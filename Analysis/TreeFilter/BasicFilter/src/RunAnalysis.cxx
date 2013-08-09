#include "BasicFilter/RunAnalysis.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

#include "BasicFilter/BranchDefs.h"
#include "BasicFilter/BranchInit.h"

#include "TFile.h"

int main(int argc, char **argv)
{


    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );

    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    std::cout << "TreenaME" << options.treeName << "test" << std::endl;
    TChain *chain = new TChain(options.treeName.c_str() );
    BOOST_FOREACH( const std::string &fname, options.files ) {
      std::cout << "Add file " << fname << std::endl;
      chain->Add( fname.c_str() );
    }
    std::cout << options.output << std::endl;
    TFile * outfile  = new TFile(options.output.c_str(), "RECREATE");

    outfile->cd();
    TTree * outtree  = 0;
    std::vector<std::string> name_tok = Tokenize( chain->GetName(), "/" ); 

    if( name_tok.size() > 1 ) {
        std::string dir_path = "";
        for( unsigned i = 0; i < name_tok.size()-1; i++ ) {
            dir_path = dir_path + name_tok[i]+"/";
            std::cout << " mkdir " << dir_path << std::endl;
            outfile->mkdir(dir_path.c_str());
        }
        outfile->cd(dir_path.c_str());
        //TDirectory * treedir = outfile->Get(dir_path);
        //treedir->cd();

        std::cout << "Path is " << dir_path << std::endl;

        std::string name = name_tok[name_tok.size()-1];

        std::cout << "Name is " << name.c_str() << std::endl;
    
        outtree = new TTree(name.c_str(), name.c_str());
        //outtree->SetDirectory(outfile->GetDirectory( dir_path.c_str() ));
    }
    else {
        outtree = new TTree(chain->GetName(), chain->GetName());
        outtree->SetDirectory(outfile);
    }
    //ConfigOutFile( outfile, chain->GetName(), outtree );

    // In BranchInit
    InitINTree(chain);
    InitOUTTree( outtree );

    Run( chain, outtree, ana_config, options );
    outtree->Write();
    outfile->Close();
    std::cout << "Finished ^.^" << std::endl;

}

void Run( TChain * chain, TTree * outtree, 
          const AnaConfig & ana_config, const CmdOptions & options ) {

    // *************************
    // Begin loop over the input tree
    // *************************
    int minevt = 0;
    int maxevt = chain->GetEntries();

    if( options.nevt > 0 ) {
        maxevt = options.nevt;
    }

    int n_saved = 0;
    std::cout << "Will analyze " << maxevt << " events " << std::endl;
    for( int cidx = minevt; cidx < maxevt; cidx++ ) {

        if( cidx % 1000 == 0 ) {
          //std::cout << "Processed " << cidx << " entries \xd";
          std::cout << "Processed " << cidx << " entries " << std::endl;
        }

        chain->GetEntry(cidx);

        // In BranchInit
        CopyInputVarsToOutput();

        outtree->Fill();
        n_saved++;
    }

    std::cout << "Wrote " << n_saved << " events" << std::endl;

}

void ConfigOutFile( TFile * file, const std::string & raw_name, TTree * outtree ) {

    // if the tree is in a directory, recreate the directory and put the tree in it
    // otherwise just make the tree in the root directory
    std::vector<std::string> name_tok = Tokenize( raw_name, "/" ); 

    if( name_tok.size() > 1 ) {
        std::string dir_path = "";
        for( unsigned i = 0; i < name_tok.size()-1; i++ ) {
            dir_path = dir_path + name_tok[i]+"/";
            std::cout << " mkdir " << dir_path << std::endl;
            file->mkdir(dir_path.c_str());
        }
        file->cd();

        std::cout << "Path is " << dir_path << std::endl;

        std::string name = name_tok[name_tok.size()-1];

        std::cout << "Name is " << name.c_str() << std::endl;
    
        outtree = new TTree(name.c_str(), name.c_str());
        outtree->SetDirectory(file->GetDirectory( dir_path.c_str() ));
    }
    else {
        outtree = new TTree(raw_name.c_str(), raw_name.c_str());
        outtree->SetDirectory(file);
    }


}

AnaConfig ParseConfig( const std::string & fname, CmdOptions & options ) {

    AnaConfig ana_config;

    std::ifstream file(fname.c_str());
    std::string line;
    if( file.is_open() ) {
        
        bool read_modules = false;
        while( getline(file, line) ) {

            if( read_modules ) {

                // information to be collected
                std::string module_name;
                std::vector<CutConfig> module_cuts;

                // Split by : character.  The 0th entry is the
                // module name
                std::vector<std::string> module_split = Tokenize( line, ":" );
                if( module_split.size() != 2 ) {
                    std::cout << "ParseConfig - ERROR : config file entry does not contain a \":\" "
                              << "character.  Please check the config file" << std::endl;
                    continue;
                }
                module_name = module_split[0];
                boost::algorithm::trim(module_name);
                std::string module_config = module_split[1];

                // Split the module config by ';' to separate cut entries
                std::vector<std::string> cut_split = Tokenize( module_config, ";" );

                BOOST_FOREACH( const std::string & cut, cut_split ) {
                    if( cut.find_first_not_of(' ') == std::string::npos ) continue; //check if cut is only whitespace 
                    module_cuts.push_back( CutConfig( cut ) );
                }

                ana_config.AddModule( module_name, module_cuts );
            }
            else {
                // reading header information
                std::vector<std::string> header_split = Tokenize( line, ":" );
                if( header_split.size() == 2 ) {
                    std::string header_key = header_split[0];
                    if( header_key.find("files") != std::string::npos ) {// read files
                        std::vector<std::string> file_list = Tokenize(header_split[1], ",");
                        BOOST_FOREACH( const std::string & file, file_list ) {
                            options.files.push_back(file);
                        }
                    }
                    else if( header_key.find("treeName") != std::string::npos ) {
                        options.treeName = header_split[1];
                        boost::algorithm::trim(options.treeName);
                    }
                    else if( header_key.find("output") != std::string::npos ) {
                        options.output = header_split[1];
                        boost::algorithm::trim(options.output);
                    }
                    else if( header_key.find("nevt") != std::string::npos ) {
                        std::stringstream ss(header_split[1]);
                        ss >> options.nevt;
                    }
                        
                }
            }

            // __Modules__ line indicates the beginning of modules

            if( line.find("__Modules__") != std::string::npos ) {
                read_modules = true;
            }
        }
    }
    return ana_config;
}

CmdOptions::CmdOptions() : nevt(-1) 
{
}

CmdOptions ParseOptions( int argc, char **argv ) 
{

    CmdOptions options;
    const struct option longopts[] =
         {
         {"conf_file", required_argument,        0, 'c'},
         {0,0,0,0},
    };

    int iarg=0;

    //turn off getopt error message
    
    while(iarg != -1) {
      iarg = getopt_long(argc, argv, "c:", longopts, 0);
      switch (iarg) {
        case 'c' : 
          {
          options.config_file = optarg;
          break;
          }
      }
    }

    return options;
}
