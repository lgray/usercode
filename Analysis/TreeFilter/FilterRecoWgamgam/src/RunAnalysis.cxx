#include "FilterRecoWgamgam/RunAnalysis.h"

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

#include "FilterRecoWgamgam/BranchDefs.h"
#include "FilterRecoWgamgam/BranchInit.h"

#include "Core/Util.h"

#include "TFile.h"

int main(int argc, char **argv)
{

    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );
    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^_^ Finished ^_^" << std::endl;


}

void RunModule::Run( TChain * chain, TTree * outtree, 
          std::vector<ModuleConfig> & configs, const CmdOptions & options,
          int minevt, int maxevt ) const {

    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    // *************************
    // Declare added output variables
    // *************************
    OUT::el_pt = 0;
    OUT::el_eta = 0;
    OUT::el_phi = 0;
    OUT::el_e = 0;
    OUT::mu_pt = 0;
    OUT::mu_eta = 0;
    OUT::mu_phi = 0;
    OUT::mu_e = 0;
    OUT::phot_pt = 0;
    OUT::phot_eta = 0;
    OUT::phot_phi = 0;
    OUT::phot_e = 0;
    
    outtree->Branch("el_n" , &OUT::el_n  , "el_n/I"   );
    outtree->Branch("mu_n" , &OUT::mu_n  , "mu_n/I"   );
    outtree->Branch("phot_n", &OUT::phot_n , "phot_n/I" );
    outtree->Branch("vtx_n" , &OUT::vtx_n   , "vtx_n/I" );

    outtree->Branch("el_pt"          , &OUT::el_pt          );
    outtree->Branch("el_eta"         , &OUT::el_eta         );
    outtree->Branch("el_phi"         , &OUT::el_phi         );
    outtree->Branch("el_e"           , &OUT::el_e           );
    
    outtree->Branch("mu_pt"          , &OUT::mu_pt          );
    outtree->Branch("mu_eta"         , &OUT::mu_eta         );
    outtree->Branch("mu_phi"         , &OUT::mu_phi         );
    outtree->Branch("mu_e"           , &OUT::mu_e           );
    
    outtree->Branch("phot_pt"        , &OUT::phot_pt  );
    outtree->Branch("phot_eta"       , &OUT::phot_eta );
    outtree->Branch("phot_phi"       , &OUT::phot_phi );
    outtree->Branch("phot_e"         , &OUT::phot_e   );
    
    outtree->Branch("avgPU"  , &OUT::avgPU, "avgPU/F" );

    outtree->Branch("met_et"  , &OUT::met_et , "met_et/F" );
    outtree->Branch("met_phi" , &OUT::met_phi , "met_phi/F" );
    outtree->Branch("sumet" , &OUT::sumet, "sumet/F" );
    outtree->Branch("metsig" , &OUT::metsig, "metsig/F" );

    outtree->Branch("leadPhot_pt" , &OUT::leadPhot_pt , "leadPhot_pt/F" );
    outtree->Branch("sublPhot_pt" , &OUT::sublPhot_pt , "sublPhot_pt/F" );

    outtree->Branch("leadPhot_lepDR" , &OUT::leadPhot_lepDR , "leadPhot_lepDR/F" );
    outtree->Branch("sublPhot_lepDR" , &OUT::sublPhot_lepDR , "sublPhot_lepDR/F" );
    outtree->Branch("phot_photDR"    , &OUT::phot_photDR , "phot_photDR/F" );
    outtree->Branch("photPhot_lepDR" , &OUT::photPhot_lepDR , "photPhot_lepDR/F" );
    outtree->Branch("leadPhot_lepDPhi" , &OUT::leadPhot_lepDPhi , "leadPhot_lepDPhi/F" );
    outtree->Branch("sublPhot_lepDPhi" , &OUT::sublPhot_lepDPhi , "sublPhot_lepDPhi/F" );
    outtree->Branch("phot_photDPhi"    , &OUT::phot_photDPhi , "phot_photDPhi/F" );
    outtree->Branch("photPhot_lepDPhi"    , &OUT::photPhot_lepDPhi , "photPhot_lepDPhi/F" );

    outtree->Branch("mt_lep_met"         , &OUT::mt_lep_met         , "mt_lep_met/F"          );
    outtree->Branch("mt_lepphot1_met"    , &OUT::mt_lepphot1_met    , "mt_lepphot1_met/F"     );
    outtree->Branch("mt_lepphot2_met"    , &OUT::mt_lepphot2_met    , "mt_lepphot2_met/F"     );
    outtree->Branch("mt_lepphotphot_met" , &OUT::mt_lepphotphot_met , "mt_lepphotphot_met/F"  );

    outtree->Branch("m_leplep"        , &OUT::m_leplep        , "m_leplep/F"         );
    outtree->Branch("m_lepphot1"      , &OUT::m_lepphot1      , "m_lepphot1/F"      );
    outtree->Branch("m_lepphot2"      , &OUT::m_lepphot2      , "m_lepphot2/F"      );
    outtree->Branch("m_lepphotphot"   , &OUT::m_lepphotphot   , "m_lepphotphot/F"   );
    outtree->Branch("m_photphot"      , &OUT::m_photphot      , "m_photphot/F"      );

    // *************************
    // Begin loop over the input tree
    // *************************
    if( maxevt == 0 ) {
        maxevt = chain->GetEntries();
    }

    int n_saved = 0;
    std::cout << "Will analyze " << maxevt-minevt << " events between " << minevt << " and " << maxevt << std::endl;
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
        BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {
            save_event &= ApplyModule( mod_conf );
        }

        if( save_event ) {
            outtree->Fill();
            n_saved++;
        }
    }

    std::cout << "Wrote " << n_saved << " events" << std::endl;

}

bool RunModule::ApplyModule( ModuleConfig & config ) const {

    bool keep_evt = true;
    
    if( config.GetName() == "BuildElectron" ) {
        BuildElectron( config );
    }
    if( config.GetName() == "BuildMuon" ) {
        BuildMuon( config );
    }
    if( config.GetName() == "BuildPhoton" ) {
        BuildPhoton( config );
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

void RunModule::BuildMuon( ModuleConfig & config ) const {

    OUT::mu_pt        -> clear();
    OUT::mu_eta       -> clear();
    OUT::mu_phi       -> clear();
    OUT::mu_e         -> clear();
    OUT::mu_n          = 0;

    for( int idx = 0; idx < IN::nMu; ++idx ) {
       
        float pt = IN::muPt[idx];
        float eta = IN::muEta[idx];
        float phi = IN::muPhi[idx];


        if( !config.PassFloat( "cut_pt"  , pt  ) ) continue;
        if( !config.PassFloat( "cut_abseta"  , fabs(eta)   ) ) continue;

        OUT::mu_n++;

        TLorentzVector muon;
        muon.SetPtEtaPhiM( pt, eta, phi, 0.106 );

        OUT::mu_pt        -> push_back(pt);
        OUT::mu_eta       -> push_back(eta);
        OUT::mu_phi       -> push_back(phi);
        OUT::mu_e         -> push_back(muon.E());
        
    }

}
        

void RunModule::BuildElectron( ModuleConfig & config ) const {

    OUT::el_pt        -> clear();
    OUT::el_eta       -> clear();
    OUT::el_phi       -> clear();
    OUT::el_e         -> clear();
    OUT::el_n          = 0;

    for( int idx = 0; idx < IN::nEle; ++idx ) {
        float dEtaIn    = IN::eledEtaAtVtx[idx];
        float dPhiIn    = IN::eledPhiAtVtx[idx];
        float sigmaIEIE = IN::eleSigmaIEtaIEta[idx];
        float d0        = IN::eleD0GV[idx];
        float z0        = IN::eleD0GV[idx];
        float emfrac    = IN::eleHoverE[idx];
        //float eoverp    = IN::eleEoverP[idx];
        float ecaliso30 = IN::eleIsoEcalDR03[idx];
        float convfit   = IN::eleConvVtxFit[idx];
        float misshits  = IN::eleMissHits[idx];

        float pt        = IN::elePt[idx];
        float eta       = IN::eleEta[idx];
        float sceta     = IN::eleSCEta[idx];
        float phi       = IN::elePhi[idx];
        float en        = IN::eleEn[idx];
        float pin       = IN::elePin[idx];
        float eoverp    = fabs( (1/en) - (1/pin) );

        if( !config.PassFloat( "cut_pt"  , pt  ) ) continue;
        if( !config.PassFloat( "cut_abseta" , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack" , fabs(eta) ) ) continue;

        if( fabs(sceta) < 1.479 ) { // barrel
            
            if( !config.PassFloat( "cut_dEtaIn_barrel"    , dEtaIn       ) ) continue;
            if( !config.PassFloat( "cut_dPhiIn_barrel"    , dPhiIn       ) ) continue;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel" , sigmaIEIE    ) ) continue;
            if( !config.PassFloat( "cut_d0_barrel"        , d0           ) ) continue;
            if( !config.PassFloat( "cut_z0_barrel"        , z0           ) ) continue;
            if( !config.PassFloat( "cut_emfrac_barrel"    , emfrac       ) ) continue;
            if( !config.PassFloat( "cut_eoverp_barrel"    , eoverp       ) ) continue;
            if( !config.PassFloat( "cut_ecalIso30_barrel" , ecaliso30/pt ) ) continue;
            if( !config.PassFloat( "cut_convfit_barrel"   , convfit      ) ) continue;
            if( !config.PassInt  ( "cut_misshits_barrel"  , misshits     ) ) continue;
        }
        if( fabs(sceta) < 2.5 && fabs(sceta) > 1.479 ) { // endcap

            if( !config.PassFloat( "cut_dEtaIn_endcap"    , dEtaIn       ) ) continue;
            if( !config.PassFloat( "cut_dPhiIn_endcap"    , dPhiIn       ) ) continue;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap" , sigmaIEIE    ) ) continue;
            if( !config.PassFloat( "cut_d0_endcap"        , d0           ) ) continue;
            if( !config.PassFloat( "cut_z0_endcap"        , z0           ) ) continue;
            if( !config.PassFloat( "cut_emfrac_endcap"    , emfrac       ) ) continue;
            if( !config.PassFloat( "cut_eoverp_endcap"    , eoverp       ) ) continue;
            if( !config.PassFloat( "cut_ecalIso30_endcap" , ecaliso30/pt ) ) continue;
            if( !config.PassFloat( "cut_convfit_endcap"   , convfit      ) ) continue;
            if( !config.PassInt  ( "cut_misshits_endcap"  , misshits     ) ) continue;
        }

        OUT::el_n++;

        OUT::el_pt        -> push_back(pt);
        OUT::el_eta       -> push_back(eta);
        OUT::el_phi       -> push_back(phi);
        OUT::el_e         -> push_back(pt*cosh(eta));
        
    }

}        

//void RunModule::BuildTau( ModuleConfig & /*config*/ ) const {
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

void RunModule::BuildPhoton( ModuleConfig & config ) const {

    OUT::phot_pt        -> clear();
    OUT::phot_eta       -> clear();
    OUT::phot_phi       -> clear();
    OUT::phot_e         -> clear();
    OUT::phot_n          = 0;

    //for( int idx = 0; idx < IN::nMC; ++idx  ) {
    //    if( IN::mcPID[idx] == 22 && IN::mcStatus[idx] == 1 ) {

    //        if( !config.PassFloat( "cut_pt", IN::mcPt[idx] ) ) continue;
    //        if( !config.PassFloat( "cut_abseta", fabs(IN::mcEta[idx]) ) ) continue;

    //        OUT::phot_pt        -> push_back(IN::mcPt[idx]     );
    //        OUT::phot_eta       -> push_back(IN::mcEta[idx]    );
    //        OUT::phot_phi       -> push_back(IN::mcPhi[idx]    );
    //        OUT::phot_e         -> push_back(IN::mcE[idx]      );
    //        OUT::phot_motherPID -> push_back(IN::mcMomPID[idx] );
    //        OUT::phot_n++;
    //    }
    //}
            
}        

void RunModule::BuildEvent( ModuleConfig & /*config*/ ) const {

    std::vector<TLorentzVector> leptons;
    std::vector<TLorentzVector> photons;
    TLorentzVector metlv;
    metlv.SetPtEtaPhiM( OUT::met_et, 0.0, OUT::met_phi, 0.0 );

    for( int idx = 0; idx < OUT::el_n; ++idx ) {
        TLorentzVector lep;
        lep.SetPtEtaPhiE( OUT::el_pt->at(idx), 
                          OUT::el_eta->at(idx),
                          OUT::el_phi->at(idx),
                          OUT::el_e->at(idx)
                        );
        leptons.push_back(lep);
    }

    for( int idx = 0; idx < OUT::mu_n; ++idx ) {
        TLorentzVector lep;
        lep.SetPtEtaPhiE( OUT::mu_pt->at(idx), 
                          OUT::mu_eta->at(idx),
                          OUT::mu_phi->at(idx),
                          OUT::mu_e->at(idx)
                        );
        leptons.push_back(lep);
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

    if( leptons.size() == 2 ) {
        OUT::m_leplep = ( leptons[0] + leptons[1] ).M();
    }

    if( leptons.size() == 1 ) {
       
        OUT::mt_lep_met = calc_mt( leptons[0], metlv );

        if( photons.size() > 1 ) { 

            int leadidx = sorted_photons[0].second;
            int sublidx = sorted_photons[1].second;

            OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);
            OUT::sublPhot_lepDR = photons[sublidx].DeltaR(leptons[0]);
            OUT::phot_photDR    = photons[leadidx].DeltaR(photons[sublidx]);
            OUT::photPhot_lepDR = (photons[leadidx]+photons[sublidx]).DeltaR(photons[sublidx]);
            
            OUT::leadPhot_lepDPhi = photons[leadidx].DeltaPhi(leptons[0]);
            OUT::sublPhot_lepDPhi = photons[sublidx].DeltaPhi(leptons[0]);
            OUT::phot_photDPhi    = photons[leadidx].DeltaPhi(photons[sublidx]);
            OUT::photPhot_lepDPhi = (photons[leadidx]+photons[sublidx]).DeltaPhi(photons[sublidx]);
            
            OUT::mt_lepphot1_met = calc_mt( leptons[0] + photons[leadidx], metlv );
            OUT::mt_lepphot2_met = calc_mt( leptons[0] + photons[sublidx], metlv );

            OUT::mt_lepphotphot_met = calc_mt( leptons[0] + photons[leadidx] + photons[sublidx], metlv );

            OUT::m_lepphot1 = ( leptons[0] + photons[leadidx] ).M();
            OUT::m_lepphot2 = ( leptons[0] + photons[sublidx] ).M();
            OUT::m_lepphotphot = ( leptons[0] + photons[leadidx] + photons[sublidx] ).M();
        }
        else if( photons.size() == 1 ) {

            int leadidx = sorted_photons[0].second;
            OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);

            OUT::mt_lepphot1_met = calc_mt( leptons[0] + photons[leadidx], metlv );

            OUT::m_lepphot1 = ( leptons[0] + photons[leadidx] ).M();

        }
            
            
    }

}

    

bool RunModule::FilterElec( ModuleConfig & config ) const {

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

bool RunModule::FilterMuon( ModuleConfig & config ) const {

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

bool RunModule::FilterEvent( ModuleConfig & config ) const {

    bool keep_event = true;
    if( !config.PassInt("cut_nEl", OUT::el_n ) ) keep_event = false;

    //count number of photons that originate from a W
    int nwphot=0;

    if( !config.PassInt("cut_nWPhot", nwphot ) ) keep_event = false;

    return keep_event;

    
}
bool RunModule::FilterTauEvent( ModuleConfig & config ) const {

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
