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

    //TH1::AddDirectory(kFALSE);
    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );
    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^_^ Finished ^_^" << std::endl;


}

void RunModule::Run( TChain * chain, TTree * outtree, TFile *outfile,
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
    OUT::el_mva  = 0;
    OUT::el_passTight = 0;
    OUT::el_passMedium = 0;
    OUT::el_passLoose= 0;
    OUT::el_passVeryLoose = 0;
    OUT::el_truthMatch = 0;
    OUT::el_truthMinDR= 0;
    OUT::mu_pt = 0;
    OUT::mu_eta = 0;
    OUT::mu_phi = 0;
    OUT::mu_e = 0;
    OUT::mu_truthMatch = 0;
    OUT::mu_truthMinDR = 0;
    OUT::phot_pt = 0;
    OUT::phot_eta = 0;
    OUT::phot_phi = 0;
    OUT::phot_e = 0;
    
    outtree->Branch("el_n"               , &OUT::el_n  , "el_n/I"                            );
    outtree->Branch("mu_n"               , &OUT::mu_n  , "mu_n/I"                            );
    outtree->Branch("phot_n"             , &OUT::phot_n , "phot_n/I"                         );
    outtree->Branch("vtx_n"              , &OUT::vtx_n   , "vtx_n/I"                         );

    outtree->Branch("el_pt"              , &OUT::el_pt                                       );
    outtree->Branch("el_eta"             , &OUT::el_eta                                      );
    outtree->Branch("el_phi"             , &OUT::el_phi                                      );
    outtree->Branch("el_e"               , &OUT::el_e                                        );
    outtree->Branch("el_mva"             , &OUT::el_mva                                      );
    outtree->Branch("el_passTight"       , &OUT::el_passTight                                );
    outtree->Branch("el_passMedium"      , &OUT::el_passMedium                               );
    outtree->Branch("el_passLoose"       , &OUT::el_passLoose                                );
    outtree->Branch("el_passVeryLoose"   , &OUT::el_passVeryLoose                            );
    outtree->Branch("el_truthMatch"      , &OUT::el_truthMatch                               );
    outtree->Branch("el_truthMinDR"      , &OUT::el_truthMinDR                               );
    
    outtree->Branch("mu_pt"              , &OUT::mu_pt                                       );
    outtree->Branch("mu_eta"             , &OUT::mu_eta                                      );
    outtree->Branch("mu_phi"             , &OUT::mu_phi                                      );
    outtree->Branch("mu_e"               , &OUT::mu_e                                        );
    outtree->Branch("mu_truthMatch"      , &OUT::mu_truthMatch                               );
    outtree->Branch("mu_truthMinDR"      , &OUT::mu_truthMinDR                               );
    
    outtree->Branch("phot_pt"            , &OUT::phot_pt                                     );
    outtree->Branch("phot_eta"           , &OUT::phot_eta                                    );
    outtree->Branch("phot_phi"           , &OUT::phot_phi                                    );
    outtree->Branch("phot_e"             , &OUT::phot_e                                      );
    
    outtree->Branch("avgPU"              , &OUT::avgPU, "avgPU/F"                            );

    outtree->Branch("met_et"             , &OUT::met_et , "met_et/F"                         );
    outtree->Branch("met_phi"            , &OUT::met_phi , "met_phi/F"                       );
    outtree->Branch("sumet"              , &OUT::sumet, "sumet/F"                            );
    outtree->Branch("metsig"             , &OUT::metsig, "metsig/F"                          );

    outtree->Branch("leadPhot_pt"        , &OUT::leadPhot_pt , "leadPhot_pt/F"               );
    outtree->Branch("sublPhot_pt"        , &OUT::sublPhot_pt , "sublPhot_pt/F"               );

    outtree->Branch("leadPhot_lepDR"     , &OUT::leadPhot_lepDR , "leadPhot_lepDR/F"         );
    outtree->Branch("sublPhot_lepDR"     , &OUT::sublPhot_lepDR , "sublPhot_lepDR/F"         );
    outtree->Branch("phot_photDR"        , &OUT::phot_photDR , "phot_photDR/F"               );
    outtree->Branch("photPhot_lepDR"     , &OUT::photPhot_lepDR , "photPhot_lepDR/F"         );
    outtree->Branch("leadPhot_lepDPhi"   , &OUT::leadPhot_lepDPhi , "leadPhot_lepDPhi/F"     );
    outtree->Branch("sublPhot_lepDPhi"   , &OUT::sublPhot_lepDPhi , "sublPhot_lepDPhi/F"     );
    outtree->Branch("phot_photDPhi"      , &OUT::phot_photDPhi , "phot_photDPhi/F"           );
    outtree->Branch("photPhot_lepDPhi"   , &OUT::photPhot_lepDPhi , "photPhot_lepDPhi/F"     );

    outtree->Branch("mt_lep_met"         , &OUT::mt_lep_met         , "mt_lep_met/F"         );
    outtree->Branch("mt_lepphot1_met"    , &OUT::mt_lepphot1_met    , "mt_lepphot1_met/F"    );
    outtree->Branch("mt_lepphot2_met"    , &OUT::mt_lepphot2_met    , "mt_lepphot2_met/F"    );
    outtree->Branch("mt_lepphotphot_met" , &OUT::mt_lepphotphot_met , "mt_lepphotphot_met/F" );

    outtree->Branch("m_leplep"           , &OUT::m_leplep        , "m_leplep/F"              );
    outtree->Branch("m_lepphot1"         , &OUT::m_lepphot1      , "m_lepphot1/F"            );
    outtree->Branch("m_lepphot2"         , &OUT::m_lepphot2      , "m_lepphot2/F"            );
    outtree->Branch("m_lepphotphot"      , &OUT::m_lepphotphot   , "m_lepphotphot/F"         );
    outtree->Branch("m_photphot"         , &OUT::m_photphot      , "m_photphot/F"            );

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
    OUT::mu_truthMatch-> clear();
    OUT::mu_truthMinDR-> clear();
    OUT::mu_n          = 0;

    for( int idx = 0; idx < IN::nMu; ++idx ) {
       
        float pt = IN::muPt[idx];
        float eta = IN::muEta[idx];
        float phi = IN::muPhi[idx];

        float chi2 = IN::muChi2NDF[idx];
        int   nTrkLayers = IN::muNumberOfValidTrkLayers[idx];
        int   muStations = IN::muStations[idx];
        int   nPixHit    = IN::muNumberOfValidPixelHits[idx];
        float d0         = IN::muD0GV[idx];
        float muIso      = IN::muIsoTrk[idx];

        if( !config.PassFloat( "cut_pt"         , pt         ) ) continue;
        if( !config.PassFloat( "cut_abseta"     , fabs(eta)  ) ) continue;
        if( !config.PassFloat( "cut_chi2"       , chi2       ) ) continue;
        if( !config.PassFloat( "cut_nTrkLayers" , nTrkLayers ) ) continue;
        if( !config.PassFloat( "cut_nStations"  , muStations ) ) continue;
        if( !config.PassFloat( "cut_nPixelHits" , nPixHit    ) ) continue;
        if( !config.PassFloat( "cut_d0"         , fabs(d0)   ) ) continue;
        if( !config.PassFloat( "cut_trkiso"     , muIso/pt   ) ) continue;

        OUT::mu_n++;

        TLorentzVector muon;
        muon.SetPtEtaPhiM( pt, eta, phi, 0.106 );

        OUT::mu_pt        -> push_back(pt);
        OUT::mu_eta       -> push_back(eta);
        OUT::mu_phi       -> push_back(phi);
        OUT::mu_e         -> push_back(muon.E());

        std::vector<int> matchPID;
        matchPID.push_back(13);
        matchPID.push_back(-13);
        
        float truthMinDR = 100.0;
        bool has_match = HasTruthMatch( muon, matchPID, 0.1, truthMinDR );
        OUT::mu_truthMinDR->push_back( truthMinDR );
        OUT::mu_truthMatch->push_back( has_match );
    }

}
        

void RunModule::BuildElectron( ModuleConfig & config ) const {

    OUT::el_pt            -> clear();
    OUT::el_eta           -> clear();
    OUT::el_phi           -> clear();
    OUT::el_e             -> clear();
    OUT::el_mva           -> clear();
    OUT::el_passTight     -> clear();
    OUT::el_passMedium    -> clear();
    OUT::el_passLoose     -> clear();
    OUT::el_passVeryLoose -> clear();
    OUT::el_truthMatch    -> clear();
    OUT::el_truthMinDR    -> clear();
    OUT::el_n             = 0;

    for( int idx = 0; idx < IN::nEle; ++idx ) {
        float dEtaIn    = fabs(IN::eledEtaAtVtx[idx]);
        float dPhiIn    = fabs(IN::eledPhiAtVtx[idx]);
        float sigmaIEIE = IN::eleSigmaIEtaIEta[idx];
        float d0        = fabs(IN::eleD0GV[idx]);
        float z0        = fabs(IN::eleDzGV[idx]);
        float hovere    = IN::eleHoverE[idx];
        //float eoverp    = IN::eleEoverP[idx];
        float pfiso30   = IN::elePFChIso03[idx];
        float convfit   = IN::eleConvVtxFit[idx];
        int misshits    = IN::eleMissHits[idx];

        float pt        = IN::elePt[idx];
        float eta       = IN::eleEta[idx];
        float sceta     = IN::eleSCEta[idx];
        float phi       = IN::elePhi[idx];
        float en        = IN::eleEn[idx];
        float p         = en/(IN::eleEoverP[idx]);
        float eoverp    = fabs( (1/en) - (1/p) );
        float mva       = IN::eleIDMVATrig[idx];

        if( !config.PassFloat( "cut_pt"  , pt  ) ) continue;
        if( !config.PassFloat( "cut_abseta" , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack" , fabs(eta) ) ) continue;

        if( !config.PassFloat( "cut_mva" , mva ) ) continue;

        bool pass_tight     = true;
        bool pass_medium    = true;
        bool pass_loose     = true;
        bool pass_veryloose = true;

        if( fabs(sceta) < 1.479 ) { // barrel
            
            // Tight cuts
            if( !config.PassFloat( "cut_dEtaIn_barrel_tight"    , dEtaIn       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_dPhiIn_barrel_tight"    , dPhiIn       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_tight" , sigmaIEIE    ) ) pass_tight=false;
            if( !config.PassFloat( "cut_d0_barrel_tight"        , d0           ) ) pass_tight=false;
            if( !config.PassFloat( "cut_z0_barrel_tight"        , z0           ) ) pass_tight=false;
            if( !config.PassFloat( "cut_hovere_barrel_tight"    , hovere       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_eoverp_barrel_tight"    , eoverp       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_tight"   , pfiso30/pt   ) ) pass_tight=false;
            if( !config.PassFloat( "cut_convfit_barrel_tight"   , convfit      ) ) pass_tight=false;
            if( !config.PassInt  ( "cut_misshits_barrel_tight"  , misshits     ) ) pass_tight=false;
            
            // Medium cuts
            if( !config.PassFloat( "cut_dEtaIn_barrel_medium"    , dEtaIn       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_dPhiIn_barrel_medium"    , dPhiIn       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_medium" , sigmaIEIE    ) ) pass_medium=false;
            if( !config.PassFloat( "cut_d0_barrel_medium"        , d0           ) ) pass_medium=false;
            if( !config.PassFloat( "cut_z0_barrel_medium"        , z0           ) ) pass_medium=false;
            if( !config.PassFloat( "cut_hovere_barrel_medium"    , hovere       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_eoverp_barrel_medium"    , eoverp       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_medium"   , pfiso30/pt   ) ) pass_medium=false;
            if( !config.PassFloat( "cut_convfit_barrel_medium"   , convfit      ) ) pass_medium=false;
            if( !config.PassInt  ( "cut_misshits_barrel_medium"  , misshits     ) ) pass_medium=false;
            
            // Loose cuts
            if( !config.PassFloat( "cut_dEtaIn_barrel_loose"    , dEtaIn       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_dPhiIn_barrel_loose"    , dPhiIn       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_loose" , sigmaIEIE    ) ) pass_loose=false;
            if( !config.PassFloat( "cut_d0_barrel_loose"        , d0           ) ) pass_loose=false;
            if( !config.PassFloat( "cut_z0_barrel_loose"        , z0           ) ) pass_loose=false;
            if( !config.PassFloat( "cut_hovere_barrel_loose"    , hovere       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_eoverp_barrel_loose"    , eoverp       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_loose"   , pfiso30/pt   ) ) pass_loose=false;
            if( !config.PassFloat( "cut_convfit_barrel_loose"   , convfit      ) ) pass_loose=false;
            if( !config.PassInt  ( "cut_misshits_barrel_loose"  , misshits     ) ) pass_loose=false;

            // Very Loose cuts
            if( !config.PassFloat( "cut_dEtaIn_barrel_loose"    , dEtaIn       ) ) pass_veryloose=false;
            
            if( !config.PassFloat( "cut_dEtaIn_barrel_veryloose"    , dEtaIn       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_dPhiIn_barrel_veryloose"    , dPhiIn       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_veryloose" , sigmaIEIE    ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_d0_barrel_veryloose"        , d0           ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_z0_barrel_veryloose"        , z0           ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_hovere_barrel_veryloose"    , hovere       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_eoverp_barrel_veryloose"    , eoverp       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_veryloose"   , pfiso30/pt   ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_convfit_barrel_veryloose"   , convfit      ) ) pass_veryloose=false;
            if( !config.PassInt  ( "cut_misshits_barrel_veryloose"  , misshits     ) ) pass_veryloose=false;
        }
        //if( fabs(sceta) < 2.5 && fabs(sceta) > 1.479 ) { // endcap

        //    if( !config.PassFloat( "cut_dEtaIn_endcap"    , dEtaIn       ) ) continue;
        //    if( !config.PassFloat( "cut_dPhiIn_endcap"    , dPhiIn       ) ) continue;
        //    if( !config.PassFloat( "cut_sigmaIEIE_endcap" , sigmaIEIE    ) ) continue;
        //    if( !config.PassFloat( "cut_d0_endcap"        , d0           ) ) continue;
        //    if( !config.PassFloat( "cut_z0_endcap"        , z0           ) ) continue;
        //    if( !config.PassFloat( "cut_emfrac_endcap"    , hovere       ) ) continue;
        //    if( !config.PassFloat( "cut_eoverp_endcap"    , eoverp       ) ) continue;
        //    if( !config.PassFloat( "cut_pfIso30_endcap"   , pfiso30/pt   ) ) continue;
        //    if( !config.PassFloat( "cut_convfit_endcap"   , convfit      ) ) continue;
        //    if( !config.PassInt  ( "cut_misshits_endcap"  , misshits     ) ) continue;
        //}

        OUT::el_n++;

        OUT::el_pt            -> push_back(pt);
        OUT::el_eta           -> push_back(eta);
        OUT::el_phi           -> push_back(phi);
        OUT::el_e             -> push_back(pt*cosh(eta));
        OUT::el_mva           -> push_back(mva);
        OUT::el_passTight     -> push_back(pass_tight);
        OUT::el_passMedium    -> push_back(pass_medium);
        OUT::el_passLoose     -> push_back(pass_loose);
        OUT::el_passVeryLoose -> push_back(pass_veryloose);

        // check truth matching
        TLorentzVector ellv;
        ellv.SetPtEtaPhiE( pt, eta, phi, en );
        std::vector<int> matchPID;
        matchPID.push_back(11);
        matchPID.push_back(-11);

        float minTruthDR = 100.0;
        bool match = HasTruthMatch( ellv, matchPID, 0.1, minTruthDR );
        OUT::el_truthMatch->push_back( match  );
        OUT::el_truthMinDR->push_back( minTruthDR );
        
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

    for( int idx = 0; idx < IN::nPho; ++idx ) {
        float pt        = IN::phoEt[idx];
        float eta       = IN::phoEta[idx];
        float sceta     = IN::phoSCEta[idx];
        float phi       = IN::phoPhi[idx];
        float en        = IN::phoE[idx];
        int   isConv    = IN::phoIsConv[idx];


        int   eleVeto   = IN::phoEleVeto[idx];
        float hovere    = IN::phoHoverE[idx];
        float sigmaIEIE = IN::phoSigmaIEtaIEta[idx];
        int   pixseed   = IN::phohasPixelSeed[idx];

        float isohollow40 = IN::phoTrkIsoHollowDR04[idx];
        float ecaliso40   = IN::phoEcalIsoDR04[idx];
        float hcaliso40   = IN::phoHcalIsoDR04[idx];

        float pfChIso     = IN::phoPFChIso[idx];
        float pfNeuIso    = IN::phoPFNeuIso[idx];
        float pfPhoIso    = IN::phoPFPhoIso[idx];

        if( !config.PassFloat( "cut_pt"    , pt       ) ) continue;
        if( !config.PassFloat( "cut_abseta"    , fabs(eta)       ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack"    , fabs(eta)       ) ) continue;
        if( !config.PassFloat( "cut_emfrac"    , hovere ) ) continue;
        if( fabs(sceta) < 1.479 ) { // barrel

            if( !config.PassFloat( "cut_sigmaIEIE_barrel"    , sigmaIEIE) ) continue;
            if( !config.PassFloat( "cut_trkiso40_barrel"    , isohollow40) ) continue;
            if( !config.PassFloat( "cut_ecaliso40_barrel"    , ecaliso40) ) continue;
            if( !config.PassFloat( "cut_hcaliso40_barrel"    , hcaliso40) ) continue;

        }

        OUT::phot_n++;

        OUT::phot_pt        -> push_back(pt);
        OUT::phot_eta       -> push_back(eta);
        OUT::phot_phi       -> push_back(phi);
        OUT::phot_e         -> push_back(pt*cosh(eta));
    }
            
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

bool RunModule::HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR ) const {
    
    float minDR = 100.0;
    return HasTruthMatch( objlv, matchPID, maxDR, minDR );

}

bool RunModule::HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR, float & minDR ) const {
   
    minDR = 100.0;
    bool match=false;
    for( int mcidx = 0; mcidx < IN::nMC; mcidx++ ) {
        
        if( std::find( matchPID.begin(), matchPID.end(), IN::mcPID[mcidx] ) == matchPID.end() ) continue;

        if( IN::mcStatus[mcidx] != 1 ) continue;

        TLorentzVector mclv;
        mclv.SetPtEtaPhiE( IN::mcPt[mcidx], IN::mcEta[mcidx], IN::mcPhi[mcidx], IN::mcE[mcidx] );
        float dr = mclv.DeltaR( objlv );
        if( dr < maxDR) {
            match = true;
        }
        // store the minimum delta R
        if( dr < minDR ) {
            minDR = dr;
        }
    }

    return match;

}
