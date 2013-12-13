#include "include/RunAnalysis.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <stdlib.h>

#include "include/BranchDefs.h"
#include "include/BranchInit.h"

#include "Core/Util.h"

#include "TFile.h"

int main(int argc, char **argv)
{

    //TH1::AddDirectory(kFALSE);
    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );
    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^_^ Finished ^_^" << std::endl;


}

void RunModule::initialize( TChain * chain, TTree * _outtree, TFile *outfile,
                            const CmdOptions & _options ) {

    // store tree for local use
    outtree = _outtree;
    options = _options;
    rfile = 0;
    rhist = 0;
    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    outtree->Branch("EventWeight"      , &OUT::EventWeight      , "EventWeight/F" );
    outtree->Branch("HasElToPhFF"      , &OUT::HasElToPhFF      , "HasElToPhFF/O" );

}

bool RunModule::execute( std::vector<ModuleConfig> & configs ) {

    // In BranchInit
    // Don't do this here
    //CopyInputVarsToOutput();

    // loop over configured modules
    BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {

        if( mod_conf.GetName() == "AddEventWeight" ) {
            AddEventWeight( mod_conf );
        }
    }

    // always return false.  Handle the tree filling locally
    return false;

}

// ***********************************
//  Define modules here
//  The modules can do basically anything
//  that you want, fill trees, fill plots, 
//  caclulate an event filter
// ***********************************
//
bool RunModule::AddEventWeight( ModuleConfig & config) {

    OUT::EventWeight = 1.0;
    OUT::HasElToPhFF = false;

    std::map<std::string, std::string> data = config.GetData();

    std::string root_file;
    std::string hist_name;
    std::string sample_key;

    if( data.find( "root_file" ) != data.end() ) {
        root_file = data["root_file"];
    }
    else {
        std::cout << "RunModule::AddEventWeight : ERROR - No root file was provided" << std::endl;
        return true;
    }
    if( data.find( "hist_name" ) != data.end() ) {
        hist_name = data["hist_name"];
    }
    else {
        std::cout << "RunModule::AddEventWeight : ERROR - No histogram name was provided" << std::endl;
        return true;
    }
    if( data.find( "sample_key" ) != data.end() ) {
        sample_key = data["sample_key"];
    }
    else {
        return true;
    }

    if( options.sample.empty() ) return true; 
    // if the string is not empty, then try to match
        
    // if no match, then return, otherwise get the histo
    if( options.sample.find( sample_key ) == std::string::npos ) {
        return true;
    }

    // check if the file has already been opened.  If not, open it and get the histogram
    if( rfile == 0 ) {

        std::cout << "Root file : " << root_file << std::endl;
        std::cout << "Hist name : " << hist_name << std::endl;
        rfile = TFile::Open( root_file.c_str() );
        rhist = dynamic_cast<TH1F*>(rfile->Get( hist_name.c_str() ) );
        //rfile->Close();
        //rfile=0;

    }

    // Require two electrons
    if( IN::el_pt25_n != 2 ) return false;

    std::vector<float> scale_factors;
    // loop over each electron
    // for each electron, create a new event
    // treating this electron as a photon
    for( int i = 0; i < IN::el_n; ++i ) {

        // copy the event
        CopyInputVarsToOutput();

        float pt = IN::el_pt->at(i);
        float sf = rhist->GetBinContent( rhist->FindBin( pt ) );

        OUT::EventWeight *= sf;
        OUT::HasElToPhFF = true;

        // we need to erase an electron, start by clearing all electron branches
        ClearOutputPrefix( "el_" );
        OUT::el_n=0;

        // find the second electron
        for( int eli = 0; eli < IN::el_n; eli++ ) {
            if( eli == i ) continue;
            // this is the electron that we count as an electron
            // copy these inputs to the output
            CopyPrefixIndexBranchesInToOut( "el_", eli );
            OUT::el_n++;
        }

        // now push back photon variables using this electron
        // don't clear current photons because we want to preserve those
        // not all photon information will be filled
        // However we should push back default variables
        // in all photon branches so that the vector sizes are consistent
        OUT::ph_pt->push_back( IN::el_pt->at(i) );
        OUT::ph_eta->push_back( IN::el_eta->at(i) );
        OUT::ph_phi->push_back( IN::el_phi->at(i) );
        OUT::ph_e->push_back( IN::el_e->at(i) );
        OUT::ph_n++;

        // recalculate event kinematics counting the electron as a photon
        // reset all of them first
        OUT::el_pt25_n=0;
        OUT::mu_pt25_n=0;
        OUT::leadPhot_pt=0;
        OUT::sublPhot_pt=0;
        OUT::m_phph=0;
        OUT::leadPhot_pt=0;
        OUT::sublPhot_pt=0;
        OUT::pt_secondLepton=0;
        OUT::pt_thirdLepton=0;
        OUT::m_leplep=0;
        OUT::pt_leplep=0;
        OUT::m_leplepph=0;
        OUT::pt_leplepph=0;
        OUT::mt_lep_met=0;
        OUT::leadPhot_lepDR=0;
        OUT::sublPhot_lepDR=0;
        OUT::ph_phDR=0;
        OUT::phPhot_lepDR=0;
        OUT::leadPhot_lepDPhi=0;
        OUT::sublPhot_lepDPhi=0;
        OUT::ph_phDPhi=0;
        OUT::phPhot_lepDPhi=0;
        OUT::mt_lepph1_met=0;
        OUT::mt_lepph2_met=0;
        OUT::mt_lepphph_met=0;
        OUT::m_lepph1=0;
        OUT::m_lepph2=0;
        OUT::m_lepphph=0;
        OUT::pt_lepph1=0;
        OUT::pt_lepph2=0;
        OUT::pt_lepphph=0;
        OUT::leadPhot_lepDR=0;
        OUT::mt_lepph1_met=0;
        OUT::m_lepph1=0;
        OUT::pt_lepph1=0;
        OUT::m_leplepZ=0;
        OUT::m_3lep=0;
        OUT::m_4lep=0;

        std::vector<TLorentzVector> leptons;
        std::vector<std::pair<float, std::pair<bool, int > > > sorted_leptons;
        for( int idx = 0; idx < OUT::el_n; idx++ ) {

            TLorentzVector lv;
            lv.SetPtEtaPhiE(  OUT::el_pt->at(idx),
                              OUT::el_eta->at(idx),
                              OUT::el_phi->at(idx),
                              OUT::el_e->at(idx)
                            );
            leptons.push_back(lv);
            sorted_leptons.push_back( std::make_pair( lv.Pt(), std::make_pair( 0, idx ) ) );
            if( lv.Pt() > 25 ) {
                OUT::el_pt25_n++;
            }
        }

        for( int idx = 0; idx < OUT::mu_n; idx++ ) {

            TLorentzVector lv;
            lv.SetPtEtaPhiE(  OUT::mu_pt->at(idx),
                              OUT::mu_eta->at(idx),
                              OUT::mu_phi->at(idx),
                              OUT::mu_e->at(idx)
                            );
            leptons.push_back(lv);
            sorted_leptons.push_back( std::make_pair( lv.Pt(), std::make_pair( 0, idx ) ) );
            if( lv.Pt() > 25 ) {
                OUT::mu_pt25_n++;
            }
        }

        std::vector<TLorentzVector> photons;
        std::vector<std::pair<float, int> > sorted_photons;
        for( int idx = 0; idx < OUT::ph_n; ++idx ) {
            TLorentzVector phot;
            phot.SetPtEtaPhiE(  OUT::ph_pt->at(idx), 
                                OUT::ph_eta->at(idx),
                                OUT::ph_phi->at(idx),
                                OUT::ph_e->at(idx)
                            );
            photons.push_back(phot);
            sorted_photons.push_back(std::make_pair( phot.Pt(), idx ));
        }

        std::sort(sorted_photons.rbegin(), sorted_photons.rend());
        std::sort(sorted_leptons.rbegin(), sorted_leptons.rend());

        if( photons.size() > 1 ) { 
            OUT::leadPhot_pt = sorted_photons[0].first;
            OUT::sublPhot_pt = sorted_photons[1].first;

            int leadidx = sorted_photons[0].second;
            int sublidx = sorted_photons[1].second;
            OUT::m_phph = ( photons[leadidx] + photons[sublidx] ).M();
        }
        else if ( photons.size() == 1 ) {
            OUT::leadPhot_pt = sorted_photons[0].first;
            OUT::sublPhot_pt = 0;
        }

        if( leptons.size() == 2 ) {
            OUT::pt_secondLepton = sorted_leptons[1].first;
        }
        if( leptons.size() == 3 ) {
            OUT::pt_thirdLepton = sorted_leptons[2].first;
        }

        if( leptons.size() > 1 ) {
            OUT::m_leplep = ( leptons[0] + leptons[1] ).M();
            OUT::pt_leplep = ( leptons[0] + leptons[1] ).Pt();

            if( photons.size() > 0 ) { 
                OUT::m_leplepph  = (leptons[0] + leptons[1] + photons[0] ).M();
                OUT::pt_leplepph  = (leptons[0] + leptons[1] + photons[0] ).Pt();
            }
        }

        if( leptons.size() == 1 ) {
           
            TLorentzVector metlv;
            metlv.SetPtEtaPhiM( OUT::pfMET, 0.0, OUT::pfMETPhi, 0.0 );
            OUT::mt_lep_met = calc_mt( leptons[0], metlv );

            if( photons.size() > 1 ) { 

                int leadidx = sorted_photons[0].second;
                int sublidx = sorted_photons[1].second;

                OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);
                OUT::sublPhot_lepDR = photons[sublidx].DeltaR(leptons[0]);
                OUT::ph_phDR    = photons[leadidx].DeltaR(photons[sublidx]);
                OUT::phPhot_lepDR = (photons[leadidx]+photons[sublidx]).DeltaR(photons[sublidx]);
                
                OUT::leadPhot_lepDPhi = photons[leadidx].DeltaPhi(leptons[0]);
                OUT::sublPhot_lepDPhi = photons[sublidx].DeltaPhi(leptons[0]);
                OUT::ph_phDPhi    = photons[leadidx].DeltaPhi(photons[sublidx]);
                OUT::phPhot_lepDPhi = (photons[leadidx]+photons[sublidx]).DeltaPhi(photons[sublidx]);
                
                OUT::mt_lepph1_met = calc_mt( leptons[0] + photons[leadidx], metlv );
                OUT::mt_lepph2_met = calc_mt( leptons[0] + photons[sublidx], metlv );

                OUT::mt_lepphph_met = calc_mt( leptons[0] + photons[leadidx] + photons[sublidx], metlv );

                OUT::m_lepph1 = ( leptons[0] + photons[leadidx] ).M();
                OUT::m_lepph2 = ( leptons[0] + photons[sublidx] ).M();
                OUT::m_lepphph = ( leptons[0] + photons[leadidx] + photons[sublidx] ).M();

                OUT::pt_lepph1 = ( leptons[0] + photons[leadidx] ).Pt();
                OUT::pt_lepph2 = ( leptons[0] + photons[sublidx] ).Pt();
                OUT::pt_lepphph = ( leptons[0] + photons[leadidx] + photons[sublidx] ).Pt();
            }
            else if( photons.size() == 1 ) {

                int leadidx = sorted_photons[0].second;
                OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);

                OUT::mt_lepph1_met = calc_mt( leptons[0] + photons[leadidx], metlv );

                OUT::m_lepph1 = ( leptons[0] + photons[leadidx] ).M();
                OUT::pt_lepph1 = ( leptons[0] + photons[leadidx] ).Pt();

            }
                
                
        }
        if( leptons.size() > 2 ) {
            std::vector< std::pair<float, float> > lep_pair_masses;
            for( unsigned i = 0; i < leptons.size() ; i++ ) {
                for( unsigned j = i+1; j < leptons.size() ; j++ ) {
                    lep_pair_masses.push_back( std::make_pair( fabs(91.1876 - (leptons[i]+leptons[j]).M() ),(leptons[i]+leptons[j]).M())  );
                }
           }
            //sort from smallest to greatest
            std::sort( lep_pair_masses.begin(), lep_pair_masses.end() );

            OUT::m_leplepZ = lep_pair_masses[0].second;
        }
        if( leptons.size() == 3 ) {
            OUT::m_3lep = ( leptons[0] + leptons[1] + leptons[2] ).M();
        }

        if( leptons.size() == 4 ) {
            OUT::m_4lep = ( leptons[0] + leptons[1] + leptons[2] + leptons[3] ).M();
        }

        outtree->Fill();
    }

    return true;
}

