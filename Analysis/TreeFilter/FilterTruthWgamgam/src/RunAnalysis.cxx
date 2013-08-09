#include "FilterTruthWgamgam/RunAnalysis.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <math.h>

#include "FilterTruthWgamgam/BranchDefs.h"
#include "FilterTruthWgamgam/BranchInit.h"

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
    // Declare added output variables
    // *************************
    OUT::lep_pt = 0;
    OUT::lep_eta = 0;
    OUT::lep_phi = 0;
    OUT::lep_e = 0;
    OUT::lep_motherPID = 0;
    OUT::lep_isElec = 0;
    OUT::lep_isMuon = 0;
    OUT::phot_pt = 0;
    OUT::phot_eta = 0;
    OUT::phot_phi = 0;
    OUT::phot_e = 0;
    OUT::phot_motherPID = 0;
    OUT::nu_pt = 0;
    OUT::nu_eta = 0;
    OUT::nu_phi = 0;
    OUT::nu_e = 0;
    OUT::nu_motherPID = 0;
    
    outtree->Branch("lep_n" , &OUT::lep_n  , "lep_n/I"   );
    outtree->Branch("phot_n", &OUT::phot_n , "phot_n/I" );
    outtree->Branch("nu_n"  , &OUT::nu_n   , "nu_n/I"   );

    outtree->Branch("lep_pt"        , &OUT::lep_pt        );
    outtree->Branch("lep_eta"       , &OUT::lep_eta       );
    outtree->Branch("lep_phi"       , &OUT::lep_phi       );
    outtree->Branch("lep_e"         , &OUT::lep_e         );
    outtree->Branch("lep_motherPID" , &OUT::lep_motherPID );
    outtree->Branch("lep_isElec"    , &OUT::lep_isElec    );
    outtree->Branch("lep_isMuon"    , &OUT::lep_isMuon    );
    
    outtree->Branch("phot_pt"        , &OUT::phot_pt  );
    outtree->Branch("phot_eta"       , &OUT::phot_eta );
    outtree->Branch("phot_phi"       , &OUT::phot_phi );
    outtree->Branch("phot_e"         , &OUT::phot_e   );
    outtree->Branch("phot_motherPID" , &OUT::phot_motherPID );
    
    outtree->Branch("nu_pt"        , &OUT::nu_pt      );
    outtree->Branch("nu_eta"       , &OUT::nu_eta     );
    outtree->Branch("nu_phi"       , &OUT::nu_phi     );
    outtree->Branch("nu_e"         , &OUT::nu_e       );
    outtree->Branch("nu_motherPID" , &OUT::nu_motherPID );

    outtree->Branch("leadPhot_pt" , &OUT::leadPhot_pt , "leadPhot_pt/F" );
    outtree->Branch("sublPhot_pt" , &OUT::sublPhot_pt , "sublPhot_pt/F" );

    outtree->Branch("leadPhot_lepDR" , &OUT::leadPhot_lepDR , "leadPhot_lepDR/F" );
    outtree->Branch("sublPhot_lepDR" , &OUT::sublPhot_lepDR , "sublPhot_lepDR/F" );
    outtree->Branch("phot_photDR"    , &OUT::phot_photDR , "phot_photDR/F" );

    outtree->Branch("mt_lepnu"         , &OUT::mt_lepnu         , "mt_lepnu/F"          );
    outtree->Branch("mt_lepphot1nu"    , &OUT::mt_lepphot1nu    , "mt_lepphot1nu/F"     );
    outtree->Branch("mt_lepphot2nu"    , &OUT::mt_lepphot2nu    , "mt_lepphot2nu/F"     );
    outtree->Branch("mt_lepphotphotnu" , &OUT::mt_lepphotphotnu , "mt_lepphotphotnu/F"  );

    outtree->Branch("m_lepnu"         , &OUT::m_lepnu         , "m_lepnu/F"         );
    outtree->Branch("m_lepphot1nu"    , &OUT::m_lepphot1nu    , "m_lepphot1nu/F"    );
    outtree->Branch("m_lepphot2nu"    , &OUT::m_lepphot2nu    , "m_lepphot2nu/F"    );
    outtree->Branch("m_lepphotphotnu" , &OUT::m_lepphotphotnu , "m_lepphotphotnu/F" );
    outtree->Branch("m_lepphot1"      , &OUT::m_lepphot1      , "m_lepphot1/F"      );
    outtree->Branch("m_lepphot2"      , &OUT::m_lepphot2      , "m_lepphot2/F"      );
    outtree->Branch("m_lepphotphot"   , &OUT::m_lepphotphot   , "m_lepphotphot/F"   );
    outtree->Branch("m_photphot"      , &OUT::m_photphot      , "m_photphot/F"      );

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

        if( cidx % 10000 == 0 ) {
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
    
    if( config.GetName() == "BuildLepton" ) {
        BuildLepton( config );
    }
    if( config.GetName() == "BuildPhoton" ) {
        BuildPhoton( config );
    }
    if( config.GetName() == "BuildNeutrino" ) {
        BuildNeutrino( config );
    }
    if( config.GetName() == "BuildEvent" ) {
        BuildEvent( config );
    }

    if( config.GetName() == "FilterElec" ) {
        keep_evt &= FilterElec( config );
    }
    if( config.GetName() == "FilterMuon" ) {
        keep_evt &= FilterMuon( config );
    }
    if( config.GetName() == "FilterEvent" ) {
        keep_evt &= FilterEvent( config );
    }
    if( config.GetName() == "FilterTauEvent" ) {
        keep_evt &= FilterTauEvent( config );
    }

    return keep_evt;

}

void BuildLepton( const ModuleConfig & config ) {

    OUT::lep_pt        -> clear();
    OUT::lep_eta       -> clear();
    OUT::lep_phi       -> clear();
    OUT::lep_e         -> clear();
    OUT::lep_motherPID -> clear();
    OUT::lep_isElec    -> clear();
    OUT::lep_isMuon    -> clear();
    OUT::lep_n          = 0;

    std::vector<int> accept_pid;
    std::vector<int> accept_mother;

    accept_pid.push_back(11);
    accept_pid.push_back(13);

    // don't use for now...must also require that taus have status==3 not 1
    if( config.PassBool("cut_incTau", true ) ) {
        accept_pid.push_back(15);
    }

    accept_mother.push_back(24);
    if( config.PassBool("cut_incTauMother", true ) ) {
        accept_mother.push_back(15);
    }

    for( int idx = 0; idx < IN::nMC; ++idx ) {
        if( IN::mcStatus[idx] != 1 ) continue;

        if( std::find(accept_mother.begin(), 
                      accept_mother.end(), abs(IN::mcMomPID[idx])) == accept_mother.end() ) continue;
        if( std::find(accept_pid.begin(), 
                      accept_pid.end(), abs(IN::mcPID[idx]) ) == accept_pid.end() ) continue;

        if( !config.PassFloat( "cut_pt", IN::mcPt[idx] ) ) continue;
        if( !config.PassFloat( "cut_abseta", fabs(IN::mcEta[idx]) ) ) continue;

        OUT::lep_pt        -> push_back(IN::mcPt[idx]     );
        OUT::lep_eta       -> push_back(IN::mcEta[idx]    );
        OUT::lep_phi       -> push_back(IN::mcPhi[idx]    );
        OUT::lep_e         -> push_back(IN::mcE[idx]      );
        OUT::lep_motherPID -> push_back(IN::mcMomPID[idx] );

        if( abs(IN::mcPID[idx]) == 11 ) {
            OUT::lep_isElec->push_back(true);
        }
        else {                           
            OUT::lep_isElec->push_back(false);
        }

        if( abs(IN::mcPID[idx]) == 13 ) {
            OUT::lep_isMuon->push_back(true);
        }
        else {                           
            OUT::lep_isMuon->push_back(false);
        }

        OUT::lep_n++;
    }
            
}        

//void BuildTau( const ModuleConfig & /*config*/ ) {
//
//    OUT::mu_pt        -> clear();
//    OUT::mu_eta       -> clear();
//    OUT::mu_phi       -> clear();
//    OUT::mu_e         -> clear();
//    OUT::mu_motherPID -> clear();
//    OUT::mu_n          = 0;
//
//    for( int idx = 0; idx < IN::nMC; ++idx ) {
//        if( abs(IN::mcPID[idx]) == 13  && IN::mcStatus[idx] == 1 && abs(IN::mcMomPID[idx]) == 24 ) {
//            OUT::mu_pt        -> push_back(IN::mcPt[idx]     );
//            OUT::mu_eta       -> push_back(IN::mcEta[idx]    );
//            OUT::mu_phi       -> push_back(IN::mcPhi[idx]    );
//            OUT::mu_e         -> push_back(IN::mcE[idx]      );
//            OUT::mu_motherPID -> push_back(IN::mcMomPID[idx] );
//            OUT::mu_n++;
//        }
//    }
//            
//}        

void BuildNeutrino( const ModuleConfig & /*config*/ ) {

    OUT::nu_pt        -> clear();
    OUT::nu_eta       -> clear();
    OUT::nu_phi       -> clear();
    OUT::nu_e         -> clear();
    OUT::nu_motherPID -> clear();
    OUT::nu_n          = 0;

    for( int idx = 0; idx < IN::nMC; ++idx ) {
        if( ( abs(IN::mcPID[idx]) == 12 || 
              abs(IN::mcPID[idx]) == 14 ||  
              abs(IN::mcPID[idx]) == 16  ) && IN::mcStatus[idx] == 1 && abs(IN::mcMomPID[idx]) == 24  ) {
            OUT::nu_pt        -> push_back(IN::mcPt[idx]     );
            OUT::nu_eta       -> push_back(IN::mcEta[idx]    );
            OUT::nu_phi       -> push_back(IN::mcPhi[idx]    );
            OUT::nu_e         -> push_back(IN::mcE[idx]      );
            OUT::nu_motherPID -> push_back(IN::mcMomPID[idx] );
            OUT::nu_n++;
        }
    }
            
}        

void BuildPhoton( const ModuleConfig & config ) {

    OUT::phot_pt        -> clear();
    OUT::phot_eta       -> clear();
    OUT::phot_phi       -> clear();
    OUT::phot_e         -> clear();
    OUT::phot_motherPID -> clear();
    OUT::phot_n          = 0;

    for( int idx = 0; idx < IN::nMC; ++idx  ) {
        if( IN::mcPID[idx] == 22 && IN::mcStatus[idx] == 1 ) {

            if( !config.PassFloat( "cut_pt", IN::mcPt[idx] ) ) continue;
            if( !config.PassFloat( "cut_abseta", fabs(IN::mcEta[idx]) ) ) continue;

            OUT::phot_pt        -> push_back(IN::mcPt[idx]     );
            OUT::phot_eta       -> push_back(IN::mcEta[idx]    );
            OUT::phot_phi       -> push_back(IN::mcPhi[idx]    );
            OUT::phot_e         -> push_back(IN::mcE[idx]      );
            OUT::phot_motherPID -> push_back(IN::mcMomPID[idx] );
            OUT::phot_n++;
        }
    }
            
}        

void BuildEvent( const ModuleConfig & /*config*/ ) {

    std::vector<TLorentzVector> leptons;
    std::vector<TLorentzVector> neutrinos;
    std::vector<TLorentzVector> photons;

    for( int idx = 0; idx < OUT::lep_n; ++idx ) {
        TLorentzVector lep;
        lep.SetPtEtaPhiE( OUT::lep_pt->at(idx), 
                          OUT::lep_eta->at(idx),
                          OUT::lep_phi->at(idx),
                          OUT::lep_e->at(idx)
                        );
        leptons.push_back(lep);
    }
    for( int idx = 0; idx < OUT::nu_n; ++idx ) {
        TLorentzVector nu;
        nu.SetPtEtaPhiE(  OUT::nu_pt->at(idx), 
                          OUT::nu_eta->at(idx),
                          OUT::nu_phi->at(idx),
                          OUT::nu_e->at(idx)
                        );
        neutrinos.push_back(nu);
    }

    std::vector<std::pair<float, int> > sorted_photons;
    for( int idx = 0; idx < OUT::phot_n; ++idx ) {
        TLorentzVector phot;
        phot.SetPtEtaPhiE(  OUT::phot_pt->at(idx), 
                            OUT::phot_eta->at(idx),
                            OUT::phot_phi->at(idx),
                            OUT::phot_e->at(idx)
                        );
        photons.push_back(phot);
        sorted_photons.push_back(std::make_pair( phot.Pt(), idx ));
    }


    // sort the list of photon momenta in descending order
    std::sort(sorted_photons.rbegin(), sorted_photons.rend());

    if( photons.size() > 1 ) { 
        OUT::leadPhot_pt = sorted_photons[0].first;
        OUT::sublPhot_pt = sorted_photons[1].first;

        int leadidx = sorted_photons[0].second;
        int sublidx = sorted_photons[1].second;
        OUT::m_photphot = ( photons[leadidx] + photons[sublidx] ).M();
    }
    else if ( photons.size() == 1 ) {
        OUT::leadPhot_pt = sorted_photons[0].first;
        OUT::sublPhot_pt = 0;
    }

    if( leptons.size() == 1 && neutrinos.size() == 1 ) {
       
        OUT::m_lepnu = ( leptons[0] + neutrinos[0] ).M();
        OUT::mt_lepnu = calc_mt( leptons[0], neutrinos[0] );

        if( photons.size() > 1 ) { 

            int leadidx = sorted_photons[0].second;
            int sublidx = sorted_photons[1].second;

            OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);
            OUT::sublPhot_lepDR = photons[sublidx].DeltaR(leptons[0]);
            OUT::phot_photDR    = photons[leadidx].DeltaR(photons[sublidx]);
            
            OUT::m_lepphot1nu = ( leptons[0] + photons[leadidx] + neutrinos[0] ).M();
            OUT::m_lepphot2nu = ( leptons[0] + photons[sublidx] + neutrinos[0] ).M();
            OUT::mt_lepphot1nu = calc_mt( leptons[0] + photons[leadidx], neutrinos[0] );
            OUT::mt_lepphot2nu = calc_mt( leptons[0] + photons[sublidx], neutrinos[0] );

            OUT::m_lepphotphotnu = ( leptons[0] + photons[leadidx] + photons[sublidx] + neutrinos[0] ).M();
            OUT::mt_lepphotphotnu = calc_mt( leptons[0] + photons[leadidx] + photons[sublidx], neutrinos[0] );

            OUT::m_lepphot1 = ( leptons[0] + photons[leadidx] ).M();
            OUT::m_lepphot2 = ( leptons[0] + photons[sublidx] ).M();
            OUT::m_lepphotphot = ( leptons[0] + photons[leadidx] + photons[sublidx] ).M();
        }
        else if( photons.size() == 1 ) {

            int leadidx = sorted_photons[0].second;
            OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);

            OUT::m_lepphot1nu = ( leptons[0] + photons[leadidx] + neutrinos[0] ).M();
            OUT::mt_lepphot1nu = calc_mt( leptons[0] + photons[leadidx], neutrinos[0] );

            OUT::m_lepphot1 = ( leptons[0] + photons[leadidx] ).M();

        }
            
            
    }

}

float calc_mt( const TLorentzVector & obj, const TLorentzVector & nu ) {

    return sqrt( 2*obj.Pt()*nu.Pt() * ( 1 - cos( obj.DeltaPhi(nu) ) ) );

}
    

bool FilterElec( const ModuleConfig & config ) {

    //int nElOut = 0;
    //for( int idx = 0; idx < IN::nEle; ++idx ) {
    //    
    //    float elePt = IN::elePt[idx];

    //    if( !config.PassFloat( "cut_pt", elePt ) ) continue;

    //    nElOut++;
    //}

    //OUT::nEle = nElOut;

    return true;
}     

bool FilterMuon( const ModuleConfig & config ) {

    //int nMuOut = 0;
    //for( int idx = 0; idx < IN::nMu; ++idx ) {
    //    
    //    float muPt = IN::muPt[idx];

    //    if( !config.PassFloat( "cut_pt", muPt ) ) continue;

    //    nMuOut++;
    //    OUT::muPt[idx] = muPt;
    //}

    //OUT::nMu = nMuOut;

    return true;
}     

bool FilterEvent( const ModuleConfig & config ) {

    bool keep_event = true;
    if( !config.PassInt("cut_nLep", OUT::lep_n ) ) keep_event = false;

    return keep_event;

    
}
bool FilterTauEvent( const ModuleConfig & config ) {

    bool keep_evt = true;

    int ntau=0;
    for( int idx = 0; idx < IN::nMC; ++idx ) {
        if( fabs(IN::mcPID[idx]) != 15 ) continue;
        if( fabs(IN::mcMomPID[idx]) != 24 ) continue;

        if( !config.PassInt( "cut_tauStatus", IN::mcStatus[idx] ) ) continue;

        ntau++;

    }

    if( !config.PassInt( "cut_nTau", ntau ) ) keep_evt = false;

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
