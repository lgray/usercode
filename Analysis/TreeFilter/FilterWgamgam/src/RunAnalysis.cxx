#include "FilterWgamgam/RunAnalysis.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


#include "FilterWgamgam/BranchDefs.h"
#include "FilterWgamgam/BranchInit.h"

#include "TFile.h"

int main(int argc, char **argv)
{


    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );

    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    int total_njobs = 0;
    for( unsigned fidx = 0; fidx < options.files.size(); ++fidx ) {
        total_njobs += options.files[fidx].jobs.size();
    }

    // loop over subjobs
    int jobidx = -1;
    for( unsigned fidx = 0; fidx < options.files.size(); ++fidx ) {
        TChain *chain = new TChain(options.treeName.c_str() );

        BOOST_FOREACH( const std::string &fname, options.files[fidx].files ) {
          std::cout << "Add file " << fname << std::endl;
          chain->Add( fname.c_str() );
        }

        // Loop over job ranges
        for( unsigned jidx = 0 ; jidx < options.files[fidx].jobs.size(); ++jidx ) {
            jobidx++;

            std::string jobstr = options.files[fidx].jobs[jidx].first;
            int minevt = options.files[fidx].jobs[jidx].second.first;
            int maxevt = options.files[fidx].jobs[jidx].second.second;

            std::string outputDir = options.outputDir;
            if( total_njobs > 1 ) {
                outputDir += "/" + jobstr;
            }

            // create the output directory
            mkdir(outputDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            std::string filepath = outputDir + "/" + options.outputFile;

            TFile * outfile  = TFile::Open(filepath.c_str(), "RECREATE");

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

            Run( chain, outtree, ana_config, options, minevt, maxevt );
            outtree->Write();
            outfile->Close();

            if( options.transferToStorage ) {
                std::string storage_dir = options.storagePath;
                std::string eos = "/afs/cern.ch/project/eos/installation/0.2.22/bin/eos.select";

                if( jobidx == 1 ) { // make the directory the first time
                    std::string mkdir_cmd = eos + " mkdir " + options.storagePath;
                    std::cout << mkdir_cmd << std::endl;
                    system( mkdir_cmd.c_str() );
                }
                if( total_njobs > 1 ) {
                    storage_dir += "/" + jobstr;
                    std::string mkdir_cmd = eos + " mkdir " + storage_dir;
                    std::cout << mkdir_cmd << std::endl;
                    system( mkdir_cmd.c_str() );
                }

                std::string copy_cmd = eos + " cp " + filepath + " " + storage_dir + "/" + options.outputFile;
                std::cout << copy_cmd << std::endl;
                system( copy_cmd.c_str() );
            }
        }
    }
    std::cout << "Finished ^.^" << std::endl;

}

void Run( TChain * chain, TTree * outtree, 
          const AnaConfig & ana_config, const CmdOptions & options,
          int minevt, int maxevt ) {

    // *************************
    // Declare output branches here
    // *************************
    

    // *************************
    // Begin loop over the input tree
    // *************************
    if( options.nevt > 0 ) {
        maxevt = options.nevt;
    }
    if( maxevt == 0 ) {
        maxevt = chain->GetEntries();
    }

    int n_saved = 0;
    std::cout << "Will analyze " << maxevt << " events between " << minevt << " and " << maxevt << std::endl;
    for( int cidx = minevt; cidx < maxevt; cidx++ ) {

        if( cidx % 1000 == 0 ) {
          //std::cout << "Processed " << cidx << " entries \xd";
          std::cout << "Processed " << cidx << " entries " << std::endl;
        }

        chain->GetEntry(cidx);

        // In BranchInit
        CopyInputVarsToOutput();


        // loop over configured modules
        bool save_event = true;
        BOOST_FOREACH( const ModuleConfig & mod_conf, ana_config.getEntries() ) {
            save_event &= ApplyModule( mod_conf );
        }

        if( save_event ) {
            outtree->Fill();
            n_saved++;
        }
    }

    std::cout << "Wrote " << n_saved << " events" << std::endl;

}

bool ApplyModule( const ModuleConfig & config ) {

    bool keep_evt = true;
    
    if( config.GetName() == "BuildElec" ) {
        BuildElec( config );
    }

    if( config.GetName() == "FilterElec" ) {
        keep_evt &= FilterElec( config );
    }
    if( config.GetName() == "FilterMuon" ) {
        keep_evt &= FilterMuon( config );
    }
    if( config.GetName() == "FilterJet" ) {
        keep_evt &= FilterJet( config );
    }
    if( config.GetName() == "FilterEvent" ) {
        keep_evt &= FilterEvent( config );
    }

    return keep_evt;

}

void BuildElec( const ModuleConfig & config ) {

    //std::cout << "EVENT " << std::endl;

    //for( int idx = 0; idx < IN::nEle; ++idx ) {
    //    std::cout << "ELE " << std::endl;
    //    for( int vidx = 0; vidx < IN::nVtx; ++vidx) {
    //        std::cout << "EleD0Vtx = " << IN::eleD0Vtx[idx][vidx] << std::endl;
    //    }
    //    std::cout << "Next vtx = " << IN::eleD0Vtx[idx][IN::nVtx] << std::endl;
    //}
    

}

bool FilterElec( const ModuleConfig & config ) {

    // NOTE this assumes that the jets are 
    // sorted in descending order

    int nElOut = 0;
    for( int idx = 0; idx < IN::nEle; ++idx ) {
        
        float elePt = IN::elePt[idx];

        if( !config.PassFloat( "cut_pt", elePt ) ) continue;

        nElOut++;
    }

    OUT::nEle = nElOut;

    return true;
}     

bool FilterJet( const ModuleConfig & config ) {

    // NOTE this assumes that the jets are 
    // sorted in descending order

    int nJetOut = 0;
    for( int idx = 0; idx < IN::nJet; ++idx ) {
        
        float jetPt = IN::jetPt[idx];

        if( !config.PassFloat( "cut_pt", jetPt ) ) continue;

        nJetOut++;
    }

    OUT::nJet = nJetOut;

    return true;
}     

bool FilterMuon( const ModuleConfig & config ) {

    // NOTE this assumes that the jets are 
    // sorted in descending order

    int nMuOut = 0;
    for( int idx = 0; idx < IN::nMu; ++idx ) {
        
        float muPt = IN::muPt[idx];

        if( !config.PassFloat( "cut_pt", muPt ) ) continue;

        nMuOut++;
    }

    OUT::nMu = nMuOut;

    return true;
}     

bool FilterEvent( const ModuleConfig & config ) {

    //int nMu = OUT::nMu;
    //int nEl = OUT::nEle;
    //int nLep = nMu + nEl;

    bool keep_evt = true;

    //if( !config.PassInt( "cut_nEl", nEl ) ) keep_evt = false;
    //if( !config.PassInt( "cut_nMu", nMu ) ) keep_evt = false;
    //if( !config.PassInt( "cut_nLep", nLep ) ) keep_evt = false;

    return keep_evt;

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

