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

void RunModule::initialize( TChain * chain, TTree * outtree, TFile *outfile,
                            const CmdOptions & options, std::vector<ModuleConfig> &/*configs*/ ) {
    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    // *************************
    // Set defaults for added output variables
    // *************************
    OUT::isBlinded = 0;

    // *************************
    // Declare Branches
    // *************************
    outtree->Branch("isBlinded", &OUT::isBlinded );
    outtree->Branch("EventWeight", &OUT::EventWeight, "EventWeight/F" );

    outtree->Branch("mu_pt25_n"        , &OUT::mu_pt25_n        , "mu_pt25_n/I"        );
    outtree->Branch("el_pt25_n"        , &OUT::el_pt25_n        , "el_pt25_n/I"        );
    
    outtree->Branch("leadPhot_pt"      , &OUT::leadPhot_pt      , "leadPhot_pt/F"        );
    outtree->Branch("sublPhot_pt"      , &OUT::sublPhot_pt      , "sublPhot_pt/F"        );
    outtree->Branch("leadPhot_lepDR"   , &OUT::leadPhot_lepDR   , "leadPhot_lepDR/F"     );
    outtree->Branch("sublPhot_lepDR"   , &OUT::sublPhot_lepDR   , "sublPhot_lepDR/F"     );
    outtree->Branch("ph_phDR"          , &OUT::ph_phDR          , "ph_phDR/F"            );
    outtree->Branch("phPhot_lepDR"     , &OUT::phPhot_lepDR     , "phPhot_lepDR/F"       );
    outtree->Branch("leadPhot_lepDPhi" , &OUT::leadPhot_lepDPhi , "leadPhot_lepDPhi/F"   );
    outtree->Branch("sublPhot_lepDPhi" , &OUT::sublPhot_lepDPhi , "sublPhot_lepDPhi/F"   );
    outtree->Branch("ph_phDPhi"        , &OUT::ph_phDPhi        , "ph_phDPhi/F"          );
    outtree->Branch("phPhot_lepDPhi"   , &OUT::phPhot_lepDPhi   , "phPhot_lepDPhi/F"     );
    outtree->Branch("mt_lep_met"       , &OUT::mt_lep_met       , "mt_lep_met/F"         );
    outtree->Branch("mt_lepph1_met"    , &OUT::mt_lepph1_met    , "mt_lepph1_met/F"      );
    outtree->Branch("mt_lepph2_met"    , &OUT::mt_lepph2_met    , "mt_lepph2_met/F"      );
    outtree->Branch("mt_lepphph_met"   , &OUT::mt_lepphph_met   , "mt_lepphph_met/F"     );
    outtree->Branch("m_leplep"         , &OUT::m_leplep         , "m_leplep/F"           );
    outtree->Branch("m_lepph1"         , &OUT::m_lepph1         , "m_lepph1/F"           );
    outtree->Branch("m_lepph2"         , &OUT::m_lepph2         , "m_lepph2/F"           );
    outtree->Branch("m_leplepph"       , &OUT::m_leplepph       , "m_leplepph/F"         );
    outtree->Branch("m_lepphph"        , &OUT::m_lepphph        , "m_lepphph/F"          );
    outtree->Branch("m_phph"           , &OUT::m_phph           , "m_phph/F"             );
    outtree->Branch("m_leplepZ"        , &OUT::m_leplepZ        , "m_leplepZ/F"          );
    outtree->Branch("m_3lep"           , &OUT::m_3lep           , "m_3lep/F"             );
    outtree->Branch("m_4lep"           , &OUT::m_4lep           , "m_4lep/F"             );
    outtree->Branch("pt_leplep"        , &OUT::pt_leplep        , "pt_leplep/F"          );
    outtree->Branch("pt_lepph1"        , &OUT::pt_lepph1        , "pt_lepph1/F"          );
    outtree->Branch("pt_lepph2"        , &OUT::pt_lepph2        , "pt_lepph2/F"          );
    outtree->Branch("pt_lepphph"       , &OUT::pt_lepphph       , "pt_lepphph/F"         );
    outtree->Branch("pt_leplepph"      , &OUT::pt_leplepph      , "pt_leplepph/F"        );
    outtree->Branch("pt_secondLepton"  , &OUT::pt_secondLepton  , "pt_secondLepton/F"    );
    outtree->Branch("pt_thirdLepton"   , &OUT::pt_thirdLepton   , "pt_thirdLepton/F"     );

    outtree->Branch("m_nearestToZ"   , &OUT::m_nearestToZ   , "m_nearestToZ/F"     );

}

bool RunModule::execute( std::vector<ModuleConfig> & configs ) {

    // In BranchInit
    CopyInputVarsToOutput();

    // loop over configured modules
    bool save_event = true;
    BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {
        save_event &= ApplyModule( mod_conf );
    }

    return save_event;

}

bool RunModule::ApplyModule( ModuleConfig & config ) const {

    // This bool is used for filtering
    // If a module implements an event filter
    // update this variable and return it
    // to apply the filter
    bool keep_evt = true;

    // This part is a bit hacked.  For each module that
    // you write below, you have to put a call to that
    // function with a matching name here.
    // The name is used to match the name used
    // in the python configuration.
    // There are fancy ways to do this, but it
    // would require the code to be much more complicated
    //
    if( config.GetName() == "FilterElectron" ) {
        FilterElectron( config );
    }
    if( config.GetName() == "FilterMuon" ) {
        FilterMuon( config );
    }
    if( config.GetName() == "FilterPhoton" ) {
        FilterPhoton( config );
    }
    if( config.GetName() == "FilterJet" ) {
        FilterJet( config );
    }
    // If the module applies a filter the filter decision
    // is passed back to here.  There is no requirement
    // that a function returns a bool, but
    // if you want the filter to work you need to do this
    //
    // Example :
    if( config.GetName() == "CalcEventVars" ) {
        CalcEventVars( config );
    }

    if( config.GetName() == "FilterEvent" ) {
        keep_evt &= FilterEvent( config );
    }

    return keep_evt;

}

// ***********************************
//  Define modules here
//  The modules can do basically anything
//  that you want, fill trees, fill plots, 
//  caclulate an event filter
// ***********************************
//
// Examples :

// This is an example of a module that applies an
// event filter.  Note that it returns a bool instead
// of a void.  In principle the modules can return any
// type of variable, you just have to handle it
// in the ApplyModule function

void RunModule::FilterElectron( ModuleConfig & config ) const {

    OUT::el_n = 0;
    ClearOutputPrefix("el_");

    for( int idx = 0; idx < IN::el_n; idx++ ) {

        if( !config.PassFloat( "cut_el_pt", IN::el_pt->at(idx)) ) continue;
        if( !config.PassBool( "cut_el_loose", IN::el_passLoose->at(idx)) ) continue;
        if( !config.PassBool( "cut_el_medium", IN::el_passMedium->at(idx)) ) continue;
        if( !config.PassBool( "cut_el_tight", IN::el_passTight->at(idx)) ) continue;
        if( !config.PassBool( "cut_el_tightTrig", IN::el_passTightTrig->at(idx)) ) continue;

        CopyPrefixIndexBranchesInToOut( "el_", idx );
        OUT::el_n++;

    }

}

void RunModule::FilterPhoton( ModuleConfig & config ) const {

    OUT::ph_n = 0;
    ClearOutputPrefix("ph_");

    for( int idx = 0; idx < IN::ph_n; idx++ ) {

        if( !config.PassFloat( "cut_ph_pt", IN::ph_pt->at(idx)) ) continue;
        //if( !config.PassBool( "cut_ph_eleVeto", IN::ph_eleVeto->at(idx)) ) continue;
        if( !config.PassBool( "cut_ph_loose", IN::ph_passLoose->at(idx)) ) continue;
        if( !config.PassBool( "cut_ph_medium", IN::ph_passMedium->at(idx)) ) continue;
        if( !config.PassBool( "cut_ph_tight", IN::ph_passTight->at(idx)) ) continue;

        // electron overlap removal
        TLorentzVector phlv;
        phlv.SetPtEtaPhiE( IN::ph_pt->at(idx), IN::ph_eta->at(idx), IN::ph_phi->at(idx), IN::ph_e->at(idx) );
        float min_dr = 100.0;
        for( int eidx = 0; eidx < OUT::el_n; eidx++ ) {
            TLorentzVector ellv;
            ellv.SetPtEtaPhiE( IN::el_pt->at(eidx), IN::el_eta->at(eidx), IN::el_phi->at(eidx), IN::el_e->at(eidx) );
            float dr = phlv.DeltaR( ellv );
            if( dr < min_dr ) {
                min_dr = dr;
            }
        }

        if( !config.PassFloat( "cut_el_ph_dr", min_dr ) ) continue;

        CopyPrefixIndexBranchesInToOut( "ph_", idx );
        OUT::ph_n++;

    }

}

void RunModule::FilterMuon( ModuleConfig & config ) const {

    OUT::mu_n = 0;
    ClearOutputPrefix("mu_");

    for( int idx = 0; idx < IN::mu_n; idx++ ) {

        if( !config.PassFloat( "cut_mu_pt", IN::mu_pt->at(idx)) ) continue;

        CopyPrefixIndexBranchesInToOut( "mu_", idx );
        OUT::mu_n++;

    }

}

void RunModule::CalcEventVars( ModuleConfig & config ) const {

    OUT::mu_pt25_n        = 0;
    OUT::el_pt25_n        = 0;
    OUT::leadPhot_pt      = 0;
    OUT::sublPhot_pt      = 0;
    OUT::leadPhot_lepDR   = 0;
    OUT::sublPhot_lepDR   = 0;
    OUT::ph_phDR          = 0;
    OUT::phPhot_lepDR     = 0;
    OUT::leadPhot_lepDPhi = 0;
    OUT::sublPhot_lepDPhi = 0;
    OUT::ph_phDPhi        = 0;
    OUT::phPhot_lepDPhi   = 0;
    OUT::mt_lep_met       = 0;
    OUT::mt_lepph1_met    = 0;
    OUT::mt_lepph2_met    = 0;
    OUT::mt_lepphph_met   = 0;
    OUT::m_leplep         = 0;
    OUT::m_lepph1         = 0;
    OUT::m_lepph2         = 0;
    OUT::m_lepphph        = 0;
    OUT::m_leplepph       = 0;
    OUT::m_phph           = 0;
    OUT::m_leplepZ        = 0;
    OUT::m_3lep           = 0;
    OUT::m_4lep           = 0;
    OUT::pt_leplep        = 0;
    OUT::pt_lepph1        = 0;
    OUT::pt_lepph2        = 0;
    OUT::pt_lepphph       = 0;
    OUT::pt_leplepph      = 0;
    OUT::pt_secondLepton  = 0;
    OUT::pt_thirdLepton   = 0;
    OUT::m_nearestToZ     = 0;

    OUT::EventWeight = 1.0;

    //TLorentzVector metlv;
    //metlv.SetPtEtaPhiM( OUT::pfMET, 0.0, OUT::pfMETPhi, 0.0 );

    //std::vector<TLorentzVector> leptons;
    //// map pt to a bool, int pair.  The bool is 1 if electron, 0 if muon.  The int is the index
    //std::vector<std::pair<float, std::pair<bool, int > > > sorted_leptons;
    //for( int idx = 0; idx < OUT::el_n; idx++ ) {

    //    TLorentzVector lv;
    //    lv.SetPtEtaPhiE(  OUT::el_pt->at(idx),
    //                      OUT::el_eta->at(idx),
    //                      OUT::el_phi->at(idx),
    //                      OUT::el_e->at(idx)
    //                    );
    //    leptons.push_back(lv);
    //    sorted_leptons.push_back( std::make_pair( lv.Pt(), std::make_pair( 1, idx ) ) );
    //    if( lv.Pt() > 25 ) {
    //        OUT::el_pt25_n++;
    //    }
    //}

    //for( int idx = 0; idx < OUT::mu_n; idx++ ) {

    //    TLorentzVector lv;
    //    lv.SetPtEtaPhiE(  OUT::mu_pt->at(idx),
    //                      OUT::mu_eta->at(idx),
    //                      OUT::mu_phi->at(idx),
    //                      OUT::mu_e->at(idx)
    //                    );
    //    leptons.push_back(lv);
    //    sorted_leptons.push_back( std::make_pair( lv.Pt(), std::make_pair( 0, idx ) ) );
    //    if( lv.Pt() > 25 ) {
    //        OUT::mu_pt25_n++;
    //    }
    //}

    //std::vector<TLorentzVector> photons;
    //std::vector<std::pair<float, int> > sorted_photons;
    //for( int idx = 0; idx < OUT::ph_n; ++idx ) {
    //    TLorentzVector phot;
    //    phot.SetPtEtaPhiE(  OUT::ph_pt->at(idx), 
    //                        OUT::ph_eta->at(idx),
    //                        OUT::ph_phi->at(idx),
    //                        OUT::ph_e->at(idx)
    //                    );
    //    photons.push_back(phot);
    //    sorted_photons.push_back(std::make_pair( phot.Pt(), idx ));
    //}


    //// sort the list of photon momenta in descending order
    //std::sort(sorted_photons.rbegin(), sorted_photons.rend());
    //std::sort(sorted_leptons.rbegin(), sorted_leptons.rend());

    //if( photons.size() > 1 ) { 
    //    OUT::leadPhot_pt = sorted_photons[0].first;
    //    OUT::sublPhot_pt = sorted_photons[1].first;

    //    int leadidx = sorted_photons[0].second;
    //    int sublidx = sorted_photons[1].second;
    //    OUT::m_phph = ( photons[leadidx] + photons[sublidx] ).M();
    //}
    //else if ( photons.size() == 1 ) {
    //    OUT::leadPhot_pt = sorted_photons[0].first;
    //    OUT::sublPhot_pt = 0;
    //}

    //if( leptons.size() == 2 ) {
    //    OUT::pt_secondLepton = sorted_leptons[1].first;
    //}
    //if( leptons.size() == 3 ) {
    //    OUT::pt_thirdLepton = sorted_leptons[2].first;
    //}

    //if( leptons.size() > 1 ) {
    //    OUT::m_leplep = ( leptons[0] + leptons[1] ).M();
    //    OUT::pt_leplep = ( leptons[0] + leptons[1] ).Pt();

    //    if( photons.size() > 0 ) { 
    //        OUT::m_leplepph  = (leptons[0] + leptons[1] + photons[0] ).M();
    //        OUT::pt_leplepph  = (leptons[0] + leptons[1] + photons[0] ).Pt();
    //    }
    //}

    //if( leptons.size() == 1 ) {
    //   
    //    OUT::mt_lep_met = calc_mt( leptons[0], metlv );

    //    if( photons.size() > 1 ) { 

    //        int leadidx = sorted_photons[0].second;
    //        int sublidx = sorted_photons[1].second;

    //        OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);
    //        OUT::sublPhot_lepDR = photons[sublidx].DeltaR(leptons[0]);
    //        OUT::ph_phDR    = photons[leadidx].DeltaR(photons[sublidx]);
    //        OUT::phPhot_lepDR = (photons[leadidx]+photons[sublidx]).DeltaR(photons[sublidx]);
    //        
    //        OUT::leadPhot_lepDPhi = photons[leadidx].DeltaPhi(leptons[0]);
    //        OUT::sublPhot_lepDPhi = photons[sublidx].DeltaPhi(leptons[0]);
    //        OUT::ph_phDPhi    = photons[leadidx].DeltaPhi(photons[sublidx]);
    //        OUT::phPhot_lepDPhi = (photons[leadidx]+photons[sublidx]).DeltaPhi(photons[sublidx]);
    //        
    //        OUT::mt_lepph1_met = calc_mt( leptons[0] + photons[leadidx], metlv );
    //        OUT::mt_lepph2_met = calc_mt( leptons[0] + photons[sublidx], metlv );

    //        OUT::mt_lepphph_met = calc_mt( leptons[0] + photons[leadidx] + photons[sublidx], metlv );

    //        OUT::m_lepph1 = ( leptons[0] + photons[leadidx] ).M();
    //        OUT::m_lepph2 = ( leptons[0] + photons[sublidx] ).M();
    //        OUT::m_lepphph = ( leptons[0] + photons[leadidx] + photons[sublidx] ).M();

    //        OUT::pt_lepph1 = ( leptons[0] + photons[leadidx] ).Pt();
    //        OUT::pt_lepph2 = ( leptons[0] + photons[sublidx] ).Pt();
    //        OUT::pt_lepphph = ( leptons[0] + photons[leadidx] + photons[sublidx] ).Pt();
    //    }
    //    else if( photons.size() == 1 ) {

    //        int leadidx = sorted_photons[0].second;
    //        OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);

    //        OUT::mt_lepph1_met = calc_mt( leptons[0] + photons[leadidx], metlv );

    //        OUT::m_lepph1 = ( leptons[0] + photons[leadidx] ).M();
    //        OUT::pt_lepph1 = ( leptons[0] + photons[leadidx] ).Pt();

    //    }
    //        
    //        
    //}
    //if( leptons.size() > 2 ) {
    //    std::vector< std::pair<float, float> > lep_pair_masses;
    //    for( unsigned i = 0; i < leptons.size() ; i++ ) {
    //        for( unsigned j = i+1; j < leptons.size() ; j++ ) {
    //            lep_pair_masses.push_back( std::make_pair( fabs(91.1876 - (leptons[i]+leptons[j]).M() ),(leptons[i]+leptons[j]).M())  );
    //        }
    //   }
    //    //sort from smallest to greatest
    //    std::sort( lep_pair_masses.begin(), lep_pair_masses.end() );

    //    OUT::m_leplepZ = lep_pair_masses[0].second;
    //}
    //if( leptons.size() == 3 ) {
    //    OUT::m_3lep = ( leptons[0] + leptons[1] + leptons[2] ).M();
    //}

    //if( leptons.size() == 4 ) {
    //    OUT::m_4lep = ( leptons[0] + leptons[1] + leptons[2] + leptons[3] ).M();
    //}

    //std::vector<TLorentzVector> objects;
    //objects.insert(objects.begin(), leptons.begin(), leptons.end() );
    //objects.insert(objects.begin(), photons.begin(), photons.end() );

    //if( objects.size() > 2 ) {
    //    std::vector<float> masses;
    //    for( unsigned i = 0; i < objects.size(); ++i ) {
    //        for( unsigned j = i+1; j < objects.size(); ++j ) {
    //            masses.push_back( (objects[i] + objects[j]).M() );
    //        }
    //    }
    //    masses.push_back( (objects[0]+objects[1]+objects[2]).M() );

    //    std::vector<std::pair<float, int > > sorted_masses;
    //    for( unsigned i = 0; i < masses.size() ; ++i ) {
    //        sorted_masses.push_back( std::make_pair( std::fabs( 91.1876 - masses[i] ), i ) );
    //    }
    //    //sort with the smallest first
    //    std::sort(sorted_masses.begin(), sorted_masses.end());
    //    int nearestZidx = sorted_masses[0].second;
    //    OUT::m_nearestToZ = masses[nearestZidx];

    //}

}

bool RunModule::FilterEvent( ModuleConfig & config ) const {

    bool keep_event = true;

    int nPh = OUT::ph_n;
    
    // blind bit
    if( nPh > 1 ) OUT::isBlinded = true;
    else          OUT::isBlinded = false;

    int nLep = 0;
    int nLep25 = 0;

    for( int i = 0; i < OUT::mu_n; ++i ) {
        nLep++;
        if( OUT::mu_pt->at(i) > 25 ) {
            nLep25++;
        }
    }
    for( int i = 0; i < OUT::el_n; ++i ) {
        nLep++;
        if( OUT::el_pt->at(i) > 25 ) {
            nLep25++;
        }
    }

    if( !config.PassInt( "cut_nLep", nLep ) ) keep_event=false;
    if( !config.PassInt( "cut_nLep25", nLep25 ) ) keep_event=false;
    if( !config.PassInt( "cut_nPh", nPh ) )   keep_event = false;

    return keep_event;
}

void RunModule::FilterJet( ModuleConfig & config ) const {

    OUT::jet_n = 0;
    ClearOutputPrefix( "jet_" );

    for( int idx = 0; idx < IN::jet_n; idx++ ) {

        bool keep_jet = true;

        TLorentzVector jetlv;
        jetlv.SetPtEtaPhiE( IN::jet_pt->at(idx), 
                            IN::jet_eta->at(idx),
                            IN::jet_phi->at(idx),
                            IN::jet_e->at(idx)
                           );

        for( int eidx = 0; eidx < OUT::el_n; eidx++ ) {
            TLorentzVector ellv;
            ellv.SetPtEtaPhiE( OUT::el_pt->at(eidx), 
                               OUT::el_eta->at(eidx),
                               OUT::el_phi->at(eidx),
                               OUT::el_e->at(eidx)
                              );

            //delta R 
            float dr = ellv.DeltaR( jetlv );
            if( !config.PassFloat( "cut_jet_ele_dr", dr ) ) keep_jet = false;
        }

        // don't continue if the jet should be rejected
        if( !keep_jet ) continue;

        for( int pidx = 0; pidx < OUT::ph_n; pidx++ ) {

            TLorentzVector phlv;
            phlv.SetPtEtaPhiE( OUT::ph_pt->at(pidx), 
                               OUT::ph_eta->at(pidx),
                               OUT::ph_phi->at(pidx),
                               OUT::ph_e->at(pidx)
                              );

            //delta R 
            float dr = phlv.DeltaR( jetlv );
            if( !config.PassFloat( "cut_jet_ph_dr", dr ) ) keep_jet = false;
        }

        // don't continue if the jet should be rejected
        if( !keep_jet ) continue;

        for( int midx = 0; midx < OUT::mu_n; midx++ ) {
            TLorentzVector mulv;
            mulv.SetPtEtaPhiE( OUT::mu_pt->at(midx), 
                               OUT::mu_eta->at(midx),
                               OUT::mu_phi->at(midx),
                               OUT::mu_e->at(midx)
                              );

            //delta R 
            float dr = mulv.DeltaR( jetlv );
            if( !config.PassFloat( "cut_jet_mu_dr", dr ) ) keep_jet = false;
        }

        if( !keep_jet ) continue;

        OUT::jet_n++;
        CopyPrefixIndexBranchesInToOut( "jet_", idx );

    }
}

