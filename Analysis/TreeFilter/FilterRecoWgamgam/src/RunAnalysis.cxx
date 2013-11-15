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
    OUT::el_pt             = 0;
    OUT::el_eta            = 0;
    OUT::el_sceta          = 0;
    OUT::el_phi            = 0;
    OUT::el_e              = 0;
    OUT::el_mva            = 0;
    OUT::el_d0pv           = 0;
    OUT::el_z0pv           = 0;
    OUT::el_hasMatchedConv = 0;
    OUT::el_passTight      = 0;
    OUT::el_passMedium     = 0;
    OUT::el_passLoose      = 0;
    OUT::el_passVeryLoose  = 0;
    OUT::el_passTightTrig  = 0;
    OUT::el_truthMatch_ph  = 0;
    OUT::el_truthMatch     = 0;
    OUT::el_truthMinDR     = 0;
    OUT::mu_pt             = 0;
    OUT::mu_eta            = 0;
    OUT::mu_phi            = 0;
    OUT::mu_e              = 0;
    OUT::mu_pfIso_ch       = 0;
    OUT::mu_pfIso_nh       = 0;
    OUT::mu_pfIso_pho      = 0;
    OUT::mu_pfIso_pu       = 0;
    OUT::mu_corrIso        = 0;
    OUT::mu_truthMatch     = 0;
    OUT::mu_truthMinDR     = 0;
    OUT::ph_pt             = 0;
    OUT::ph_eta            = 0;
    OUT::ph_phi            = 0;
    OUT::ph_e              = 0;
    OUT::ph_HoverE         = 0;
    OUT::ph_sigmaIEIE      = 0;
    OUT::ph_chIsoCorr      = 0;
    OUT::ph_neuIsoCorr     = 0;
    OUT::ph_phoIsoCorr     = 0;
    OUT::ph_eleVeto        = 0;
    OUT::ph_isConv         = 0;
    OUT::ph_conv_nTrk      = 0;
    OUT::ph_conv_vtx_x     = 0;
    OUT::ph_conv_vtx_y     = 0;
    OUT::ph_conv_vtx_z     = 0;
    OUT::ph_conv_ptin1     = 0;
    OUT::ph_conv_ptin2     = 0;
    OUT::ph_conv_ptout1    = 0;
    OUT::ph_conv_ptout2    = 0;
    OUT::ph_passTight      = 0;
    OUT::ph_passMedium     = 0;
    OUT::ph_passLoose      = 0;
    OUT::ph_truthMatch_ph  = 0;
    OUT::ph_truthMatch_el  = 0;
    OUT::ph_truthMatch_mu  = 0;
    OUT::ph_truthMatch_q   = 0;

    OUT::ph_sl_pt       = 0;
    OUT::ph_sl_eta      = 0;
    OUT::ph_sl_phi      = 0;
    OUT::ph_sl_e        = 0;
    OUT::ph_sl_d0       = 0;
    OUT::ph_sl_z0       = 0;
    OUT::ph_sl_convfit  = 0;
    OUT::ph_sl_misshits = 0;

    OUT::jet_pt             = 0;
    OUT::jet_eta            = 0;
    OUT::jet_phi            = 0;
    OUT::jet_e              = 0;
    OUT::jet_ph_minDR       = 0;
    
    outtree->Branch("el_n"               , &OUT::el_n  , "el_n/I"                        );
    outtree->Branch("mu_n"               , &OUT::mu_n  , "mu_n/I"                        );
    outtree->Branch("ph_n"               , &OUT::ph_n , "ph_n/I"                         );
    outtree->Branch("ph_sl_n"            , &OUT::ph_sl_n , "ph_sl_n/I"                         );
    outtree->Branch("jet_n"              , &OUT::jet_n , "jet_n/I"                       );
    outtree->Branch("vtx_n"              , &OUT::vtx_n   , "vtx_n/I"                     );

    outtree->Branch("el_pt"              , &OUT::el_pt                                   );
    outtree->Branch("el_eta"             , &OUT::el_eta                                  );
    outtree->Branch("el_sceta"           , &OUT::el_sceta                                );
    outtree->Branch("el_phi"             , &OUT::el_phi                                  );
    outtree->Branch("el_e"               , &OUT::el_e                                    );
    outtree->Branch("el_mva"             , &OUT::el_mva                                  );
    outtree->Branch("el_d0pv"            , &OUT::el_d0pv                                 );
    outtree->Branch("el_z0pv"            , &OUT::el_z0pv                                 );
    outtree->Branch("el_sigmaIEIE"       , &OUT::el_sigmaIEIE                            );
    outtree->Branch("el_pfiso30"         , &OUT::el_pfiso30                              );
    outtree->Branch("el_hasMatchedConv"  , &OUT::el_hasMatchedConv                       );
    outtree->Branch("el_passTight"       , &OUT::el_passTight                            );
    outtree->Branch("el_passMedium"      , &OUT::el_passMedium                           );
    outtree->Branch("el_passLoose"       , &OUT::el_passLoose                            );
    outtree->Branch("el_passVeryLoose"   , &OUT::el_passVeryLoose                        );
    outtree->Branch("el_passTightTrig"   , &OUT::el_passTightTrig                        );
    outtree->Branch("el_truthMatch_ph"   , &OUT::el_truthMatch_ph                        );
    outtree->Branch("el_truthMatch"      , &OUT::el_truthMatch                           );
    outtree->Branch("el_truthMinDR"      , &OUT::el_truthMinDR                           );
    
    outtree->Branch("mu_pt"              , &OUT::mu_pt                                   );
    outtree->Branch("mu_eta"             , &OUT::mu_eta                                  );
    outtree->Branch("mu_phi"             , &OUT::mu_phi                                  );
    outtree->Branch("mu_e"               , &OUT::mu_e                                    );
    outtree->Branch("mu_pfIso_ch"        , &OUT::mu_pfIso_ch                             );
    outtree->Branch("mu_pfIso_nh"        , &OUT::mu_pfIso_nh                             );
    outtree->Branch("mu_pfIso_pho"       , &OUT::mu_pfIso_pho                            );
    outtree->Branch("mu_pfIso_pu"        , &OUT::mu_pfIso_pu                             );
    outtree->Branch("mu_corrIso"         , &OUT::mu_corrIso                              );
    outtree->Branch("mu_truthMatch"      , &OUT::mu_truthMatch                           );
    outtree->Branch("mu_truthMinDR"      , &OUT::mu_truthMinDR                           );
    
    outtree->Branch("ph_pt"            , &OUT::ph_pt                                     );
    outtree->Branch("ph_eta"           , &OUT::ph_eta                                    );
    outtree->Branch("ph_phi"           , &OUT::ph_phi                                    );
    outtree->Branch("ph_e"             , &OUT::ph_e                                      );
    outtree->Branch("ph_HoverE"        , &OUT::ph_HoverE                                 );
    outtree->Branch("ph_sigmaIEIE"     , &OUT::ph_sigmaIEIE                              );
    outtree->Branch("ph_chIsoCorr"     , &OUT::ph_chIsoCorr                              );
    outtree->Branch("ph_neuIsoCorr"    , &OUT::ph_neuIsoCorr                             );
    outtree->Branch("ph_phoIsoCorr"    , &OUT::ph_phoIsoCorr                             );
    outtree->Branch("ph_eleVeto"       , &OUT::ph_eleVeto                                );
    outtree->Branch("ph_isConv"        , &OUT::ph_isConv                                 );
    outtree->Branch("ph_conv_nTrk"     , &OUT::ph_conv_nTrk                              );
    outtree->Branch("ph_conv_vtx_x"    , &OUT::ph_conv_vtx_x                             );
    outtree->Branch("ph_conv_vtx_y"    , &OUT::ph_conv_vtx_y                             );
    outtree->Branch("ph_conv_vtx_z"    , &OUT::ph_conv_vtx_z                             );
    outtree->Branch("ph_conv_ptin1"    , &OUT::ph_conv_ptin1                             );
    outtree->Branch("ph_conv_ptin2"    , &OUT::ph_conv_ptin2                             );
    outtree->Branch("ph_conv_ptout1"   , &OUT::ph_conv_ptout1                            );
    outtree->Branch("ph_conv_ptout2"   , &OUT::ph_conv_ptout2                            );
    outtree->Branch("ph_passTight"     , &OUT::ph_passTight                              );
    outtree->Branch("ph_passMedium"    , &OUT::ph_passMedium                             );
    outtree->Branch("ph_passLoose"     , &OUT::ph_passLoose                              );
    outtree->Branch("ph_truthMatch_ph" , &OUT::ph_truthMatch_ph                          );
    outtree->Branch("ph_truthMatch_el" , &OUT::ph_truthMatch_el                          );
    outtree->Branch("ph_truthMatch_mu" , &OUT::ph_truthMatch_mu                          );
    outtree->Branch("ph_truthMatch_q"  , &OUT::ph_truthMatch_q                           );

    outtree->Branch("ph_sl_pt"       , &OUT::ph_sl_pt                                    );
    outtree->Branch("ph_sl_eta"      , &OUT::ph_sl_eta                                   );
    outtree->Branch("ph_sl_phi"      , &OUT::ph_sl_phi                                   );
    outtree->Branch("ph_sl_e"        , &OUT::ph_sl_e                                     );
    outtree->Branch("ph_sl_d0"       , &OUT::ph_sl_d0                                    );
    outtree->Branch("ph_sl_z0"       , &OUT::ph_sl_z0                                    );
    outtree->Branch("ph_sl_convfit"  , &OUT::ph_sl_convfit                               );
    outtree->Branch("ph_sl_misshits" , &OUT::ph_sl_misshits                              );
    
    outtree->Branch("jet_pt"            , &OUT::jet_pt                                   );
    outtree->Branch("jet_eta"           , &OUT::jet_eta                                  );
    outtree->Branch("jet_phi"           , &OUT::jet_phi                                  );
    outtree->Branch("jet_e"             , &OUT::jet_e                                    );
    outtree->Branch("jet_ph_minDR"      , &OUT::jet_ph_minDR                             );

    outtree->Branch("avgPU"              , &OUT::avgPU, "avgPU/F"                        );

    // copy from input tree
    //outtree->Branch("met_et"             , &OUT::met_et , "met_et/F"                   );
    //outtree->Branch("met_phi"            , &OUT::met_phi , "met_phi/F"                 );
    //outtree->Branch("sumet"              , &OUT::sumet, "sumet/F"                      );
    //outtree->Branch("metsig"             , &OUT::metsig, "metsig/F"                    );

    //outtree->Branch("leadPhot_pt"        , &OUT::leadPhot_pt , "leadPhot_pt/F"           );
    //outtree->Branch("sublPhot_pt"        , &OUT::sublPhot_pt , "sublPhot_pt/F"           );

    //outtree->Branch("leadPhot_lepDR"     , &OUT::leadPhot_lepDR , "leadPhot_lepDR/F"     );
    //outtree->Branch("sublPhot_lepDR"     , &OUT::sublPhot_lepDR , "sublPhot_lepDR/F"     );
    //outtree->Branch("ph_phDR"        , &OUT::ph_phDR , "ph_phDR/F"                       );
    //outtree->Branch("phPhot_lepDR"     , &OUT::phPhot_lepDR , "phPhot_lepDR/F"           );
    //outtree->Branch("leadPhot_lepDPhi"   , &OUT::leadPhot_lepDPhi , "leadPhot_lepDPhi/F" );
    //outtree->Branch("sublPhot_lepDPhi"   , &OUT::sublPhot_lepDPhi , "sublPhot_lepDPhi/F" );
    //outtree->Branch("ph_phDPhi"      , &OUT::ph_phDPhi , "ph_phDPhi/F"                   );
    //outtree->Branch("phPhot_lepDPhi"   , &OUT::phPhot_lepDPhi , "phPhot_lepDPhi/F"       );

    //outtree->Branch("mt_lep_met"         , &OUT::mt_lep_met         , "mt_lep_met/F"     );
    //outtree->Branch("mt_lepph1_met"    , &OUT::mt_lepph1_met    , "mt_lepph1_met/F"      );
    //outtree->Branch("mt_lepph2_met"    , &OUT::mt_lepph2_met    , "mt_lepph2_met/F"      );
    //outtree->Branch("mt_lepphph_met" , &OUT::mt_lepphph_met , "mt_lepphph_met/F"         );

    //outtree->Branch("m_leplep"           , &OUT::m_leplep        , "m_leplep/F"          );
    //outtree->Branch("m_lepph1"         , &OUT::m_lepph1      , "m_lepph1/F"              );
    //outtree->Branch("m_lepph2"         , &OUT::m_lepph2      , "m_lepph2/F"              );
    //outtree->Branch("m_lepphph"      , &OUT::m_lepphph   , "m_lepphph/F"                 );
    //outtree->Branch("m_phph"         , &OUT::m_phph      , "m_phph/F"                    );

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
          std::cout << "Processed " << cidx << " entries " << std::endl;
        }

        chain->GetEntry(cidx);

        // In BranchInit
        CopyInputVarsToOutput();

        // loop over configured modules
        bool save_event = true;
        BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {
            save_event &= ApplyModule( mod_conf );
            // if not saving the event already, don't continue
            if( !save_event ) break;
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
    if( config.GetName() == "BuildMediumElectron" ) {
        BuildMediumElectron( config );
    }
    if( config.GetName() == "BuildMuon" ) {
        BuildMuon( config );
    }
    if( config.GetName() == "BuildPhoton" ) {
        BuildPhoton( config );
    }
    if( config.GetName() == "BuildPIDPhoton" ) {
        BuildPIDPhoton( config );
    }
    if( config.GetName() == "BuildSLPhoton" ) {
        BuildSLPhoton( config );
    }
    if( config.GetName() == "BuildJet" ) {
        BuildJet( config );
    }
    if( config.GetName() == "FilterEvent" ) {
        keep_evt &= FilterEvent( config );
    }

    return keep_evt;

}

void RunModule::BuildMuon( ModuleConfig & config ) const {

    OUT::mu_pt         -> clear();
    OUT::mu_eta        -> clear();
    OUT::mu_phi        -> clear();
    OUT::mu_e          -> clear();
    OUT::mu_pfIso_ch   -> clear();
    OUT::mu_pfIso_nh   -> clear();
    OUT::mu_pfIso_pho  -> clear();
    OUT::mu_pfIso_pu   -> clear();
    OUT::mu_corrIso    -> clear();
    OUT::mu_truthMatch -> clear();
    OUT::mu_truthMinDR -> clear();
    OUT::mu_n          = 0;

    for( int idx = 0; idx < IN::nMu; ++idx ) {
       
        float pt = IN::muPt[idx];
        float eta = IN::muEta[idx];
        float phi = IN::muPhi[idx];
        unsigned int GlobalMuon = 1<<1;
        //unsigned int PFMuon =  1<<5;
        bool is_global_muon = IN::muType[idx] & GlobalMuon;
        bool is_pf_muon = IN::muType[idx] & GlobalMuon;

        float chi2       = IN::muChi2NDF[idx];
        //int   nHits      = IN::muNumberOfValidMuonHits[idx];
        int   nTrkLayers = IN::muNumberOfValidTrkLayers[idx];
        int   muStations = IN::muStations[idx];
        int   nPixHit    = IN::muNumberOfValidPixelHits[idx];
        float d0         = IN::muD0GV[idx];
        float z0         = IN::muDzGV[idx];
        float tkIso      = IN::muIsoTrk[idx];
        float muPFIsoCH  = IN::muPFIsoR04_CH[idx];
        float muPFIsoNH  = IN::muPFIsoR04_NH[idx];
        float muPFIsoPho = IN::muPFIsoR04_Pho[idx];
        float muPFIsoPU  = IN::muPFIsoR04_PU[idx];

        // isolation calculation
        float sum_neu = muPFIsoNH + muPFIsoPho - 0.5*muPFIsoPU;
        if( sum_neu < 0 ) {
            sum_neu = 0.0;
        }
        float corriso = muPFIsoCH+sum_neu;

        if( !config.PassBool ( "cut_isGlobal"   , is_global_muon ) ) continue;
        if( !config.PassBool ( "cut_isPF"       , is_pf_muon     ) ) continue;
        if( !config.PassFloat( "cut_pt"         , pt             ) ) continue;
        if( !config.PassFloat( "cut_abseta"     , fabs(eta)      ) ) continue;
        if( !config.PassFloat( "cut_chi2"       , chi2           ) ) continue;
        if( !config.PassFloat( "cut_nTrkLayers" , nTrkLayers     ) ) continue;
        if( !config.PassFloat( "cut_nStations"  , muStations     ) ) continue;
        if( !config.PassFloat( "cut_nPixelHits" , nPixHit        ) ) continue;
        if( !config.PassFloat( "cut_d0"         , fabs(d0)       ) ) continue;
        if( !config.PassFloat( "cut_z0"         , fabs(z0)       ) ) continue;
        if( !config.PassFloat( "cut_trkiso"     , tkIso/pt       ) ) continue;
        if( !config.PassFloat( "cut_corriso"    , corriso/pt     ) ) continue;

        OUT::mu_n++;

        TLorentzVector muon;
        muon.SetPtEtaPhiM( pt, eta, phi, 0.106 );

        OUT::mu_pt        -> push_back(pt);
        OUT::mu_eta       -> push_back(eta);
        OUT::mu_phi       -> push_back(phi);
        OUT::mu_e         -> push_back(muon.E());
        OUT::mu_pfIso_ch  -> push_back(muPFIsoCH);
        OUT::mu_pfIso_nh  -> push_back(muPFIsoNH);
        OUT::mu_pfIso_pho -> push_back(muPFIsoPho);
        OUT::mu_pfIso_pu  -> push_back(muPFIsoPU);
        OUT::mu_corrIso   -> push_back(corriso);

        std::vector<int> matchPID;
        matchPID.push_back(13);
        matchPID.push_back(-13);
        
        float truthMinDR = 100.0;
        bool has_match = HasTruthMatch( muon, matchPID, 0.1, truthMinDR );
        OUT::mu_truthMinDR->push_back( truthMinDR );
        OUT::mu_truthMatch->push_back( has_match );
    }

}

void RunModule::BuildMediumElectron( ModuleConfig & config ) const {

    OUT::el_pt            -> clear();
    OUT::el_eta           -> clear();
    OUT::el_sceta         -> clear();
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
        if( !config.PassFloat( "cut_abseta"         , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack"   , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abssceta"       , fabs(sceta) ) ) continue;
        if( !config.PassFloat( "cut_abssceta_crack" , fabs(sceta) ) ) continue;

        if( fabs(sceta) < 1.479 ) { // barrel
            
            // Medium cuts
            if( !config.PassFloat( "cut_absdEtaIn_barrel"    , dEtaIn       ) ) continue;
            if( !config.PassFloat( "cut_absdPhiIn_barrel"    , dPhiIn       ) ) continue;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel" , sigmaIEIE    ) ) continue;
            if( !config.PassFloat( "cut_d0_barrel"        , d0           ) ) continue;
            if( !config.PassFloat( "cut_z0_barrel"        , z0           ) ) continue;
            if( !config.PassFloat( "cut_hovere_barrel"    , hovere       ) ) continue;
            if( !config.PassFloat( "cut_eoverp_barrel"    , eoverp       ) ) continue;
            if( !config.PassFloat( "cut_pfIso30_barrel"   , pfiso30/pt   ) ) continue;
            if( !config.PassFloat( "cut_convfit_barrel"   , convfit      ) ) continue;
            if( !config.PassInt  ( "cut_misshits_barrel"  , misshits     ) ) continue;
            
        }
        else { // endcap

            // Medium cuts
            if( !config.PassFloat( "cut_absdEtaIn_endcap"    , dEtaIn       ) ) continue;
            if( !config.PassFloat( "cut_absdPhiIn_endcap"    , dPhiIn       ) ) continue;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap" , sigmaIEIE    ) ) continue;
            if( !config.PassFloat( "cut_d0_endcap"        , d0           ) ) continue;
            if( !config.PassFloat( "cut_z0_endcap"        , z0           ) ) continue;
            if( !config.PassFloat( "cut_hovere_endcap"    , hovere       ) ) continue;
            if( !config.PassFloat( "cut_eoverp_endcap"    , eoverp       ) ) continue;
            if( !config.PassFloat( "cut_pfIso30_endcap"   , pfiso30/pt   ) ) continue;
            if( !config.PassFloat( "cut_convfit_endcap"   , convfit      ) ) continue;
            if( !config.PassInt  ( "cut_misshits_endcap"  , misshits     ) ) continue;
            
        }

        OUT::el_n++;

        OUT::el_pt            -> push_back(pt);
        OUT::el_eta           -> push_back(eta);
        OUT::el_sceta         -> push_back(sceta);
        OUT::el_phi           -> push_back(phi);
        OUT::el_e             -> push_back(pt*cosh(eta));
        OUT::el_mva           -> push_back(mva);

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
void RunModule::BuildElectron( ModuleConfig & config ) const {

    OUT::el_pt             -> clear();
    OUT::el_eta            -> clear();
    OUT::el_sceta          -> clear();
    OUT::el_phi            -> clear();
    OUT::el_e              -> clear();
    OUT::el_mva            -> clear();
    OUT::el_d0pv           -> clear();
    OUT::el_z0pv           -> clear();
    OUT::el_sigmaIEIE      -> clear();
    OUT::el_pfiso30        -> clear();
    OUT::el_hasMatchedConv -> clear();
    OUT::el_passTight      -> clear();
    OUT::el_passMedium     -> clear();
    OUT::el_passLoose      -> clear();
    OUT::el_passVeryLoose  -> clear();
    OUT::el_passTightTrig  -> clear();
    OUT::el_truthMatch_ph  -> clear();
    OUT::el_truthMatch     -> clear();
    OUT::el_truthMinDR     -> clear();
    OUT::el_n              = 0;

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
        float ecalIso30 = IN::eleIsoEcalDR03[idx];
        float hcalIso30 = IN::eleIsoHcalDR03[idx];
        float trkIso30  = IN::eleIsoTrkDR03[idx];

        if( !config.PassFloat( "cut_pt"  , pt  ) ) continue;

        if( !config.PassFloat( "cut_abseta"         , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack"   , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abssceta"       , fabs(sceta) ) ) continue;
        if( !config.PassFloat( "cut_abssceta_crack" , fabs(sceta) ) ) continue;

        if( !config.PassFloat( "cut_mva" , mva ) ) continue;

        bool pass_tight     = true;
        bool pass_medium    = true;
        bool pass_loose     = true;
        bool pass_veryloose = true;
        bool pass_tightTrig = true;

        if( fabs(sceta) < 1.479 ) { // barrel
            
            // Tight cuts
            if( !config.PassFloat( "cut_absdEtaIn_barrel_tight"    , dEtaIn       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_absdPhiIn_barrel_tight"    , dPhiIn       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_tight" , sigmaIEIE    ) ) pass_tight=false;
            if( !config.PassFloat( "cut_d0_barrel_tight"        , d0           ) ) pass_tight=false;
            if( !config.PassFloat( "cut_z0_barrel_tight"        , z0           ) ) pass_tight=false;
            if( !config.PassFloat( "cut_hovere_barrel_tight"    , hovere       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_eoverp_barrel_tight"    , eoverp       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_tight"   , pfiso30/pt   ) ) pass_tight=false;
            if( !config.PassFloat( "cut_convfit_barrel_tight"   , convfit      ) ) pass_tight=false;
            if( !config.PassInt  ( "cut_misshits_barrel_tight"  , misshits     ) ) pass_tight=false;
            
            // Medium cuts
            if( !config.PassFloat( "cut_absdEtaIn_barrel_medium"    , dEtaIn       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_absdPhiIn_barrel_medium"    , dPhiIn       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_medium" , sigmaIEIE    ) ) pass_medium=false;
            if( !config.PassFloat( "cut_d0_barrel_medium"        , d0           ) ) pass_medium=false;
            if( !config.PassFloat( "cut_z0_barrel_medium"        , z0           ) ) pass_medium=false;
            if( !config.PassFloat( "cut_hovere_barrel_medium"    , hovere       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_eoverp_barrel_medium"    , eoverp       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_medium"   , pfiso30/pt   ) ) pass_medium=false;
            if( !config.PassFloat( "cut_convfit_barrel_medium"   , convfit      ) ) pass_medium=false;
            if( !config.PassInt  ( "cut_misshits_barrel_medium"  , misshits     ) ) pass_medium=false;
            
            // Loose cuts
            if( !config.PassFloat( "cut_absdEtaIn_barrel_loose"    , dEtaIn       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_absdPhiIn_barrel_loose"    , dPhiIn       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_loose" , sigmaIEIE    ) ) pass_loose=false;
            if( !config.PassFloat( "cut_d0_barrel_loose"        , d0           ) ) pass_loose=false;
            if( !config.PassFloat( "cut_z0_barrel_loose"        , z0           ) ) pass_loose=false;
            if( !config.PassFloat( "cut_hovere_barrel_loose"    , hovere       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_eoverp_barrel_loose"    , eoverp       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_loose"   , pfiso30/pt   ) ) pass_loose=false;
            if( !config.PassFloat( "cut_convfit_barrel_loose"   , convfit      ) ) pass_loose=false;
            if( !config.PassInt  ( "cut_misshits_barrel_loose"  , misshits     ) ) pass_loose=false;

            // Very Loose cuts
            if( !config.PassFloat( "cut_absdEtaIn_barrel_veryloose"    , dEtaIn       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_absdPhiIn_barrel_veryloose"    , dPhiIn       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_veryloose" , sigmaIEIE    ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_d0_barrel_veryloose"        , d0           ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_z0_barrel_veryloose"        , z0           ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_hovere_barrel_veryloose"    , hovere       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_eoverp_barrel_veryloose"    , eoverp       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_pfIso30_barrel_veryloose"   , pfiso30/pt   ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_convfit_barrel_veryloose"   , convfit      ) ) pass_veryloose=false;
            if( !config.PassInt  ( "cut_misshits_barrel_veryloose"  , misshits     ) ) pass_veryloose=false;

            // tight trigger cuts
            if( !config.PassFloat( "cut_absdEtaIn_barrel_tightTrig"   , dEtaIn      ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_absdPhiIn_barrel_tightTrig"   , dPhiIn      ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_sigmaIEIE_barrel_tightTrig"   , sigmaIEIE   ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_hovere_barrel_tightTrig"   , hovere         ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_ecalIso30_barrel_tightTrig"   , ecalIso30/pt) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_hcalIso30_barrel_tightTrig"   , hcalIso30/pt) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_trkIso30_barrel_tightTrig"   , trkIso30/pt  ) ) pass_tightTrig=false;

        }
        else { // endcap

            // Tight cuts
            if( !config.PassFloat( "cut_absdEtaIn_endcap_tight"    , dEtaIn       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_absdPhiIn_endcap_tight"    , dPhiIn       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap_tight" , sigmaIEIE    ) ) pass_tight=false;
            if( !config.PassFloat( "cut_d0_endcap_tight"        , d0           ) ) pass_tight=false;
            if( !config.PassFloat( "cut_z0_endcap_tight"        , z0           ) ) pass_tight=false;
            if( !config.PassFloat( "cut_hovere_endcap_tight"    , hovere       ) ) pass_tight=false;
            if( !config.PassFloat( "cut_eoverp_endcap_tight"    , eoverp       ) ) pass_tight=false;
            if( pt < 20 ) {
              if( !config.PassFloat( "cut_pfIso30_endcap_lowPt_tight"   , pfiso30/pt   ) ) pass_tight=false;
            }
            else {
              if( !config.PassFloat( "cut_pfIso30_endcap_highPt_tight"   , pfiso30/pt   ) ) pass_tight=false;
            }

            if( !config.PassFloat( "cut_convfit_endcap_tight"   , convfit      ) ) pass_tight=false;
            if( !config.PassInt  ( "cut_misshits_endcap_tight"  , misshits     ) ) pass_tight=false;
            
            // Medium cuts
            if( !config.PassFloat( "cut_absdEtaIn_endcap_medium"    , dEtaIn       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_absdPhiIn_endcap_medium"    , dPhiIn       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap_medium" , sigmaIEIE    ) ) pass_medium=false;
            if( !config.PassFloat( "cut_d0_endcap_medium"        , d0           ) ) pass_medium=false;
            if( !config.PassFloat( "cut_z0_endcap_medium"        , z0           ) ) pass_medium=false;
            if( !config.PassFloat( "cut_hovere_endcap_medium"    , hovere       ) ) pass_medium=false;
            if( !config.PassFloat( "cut_eoverp_endcap_medium"    , eoverp       ) ) pass_medium=false;
            if( pt < 20 ) {
                if( !config.PassFloat( "cut_pfIso30_endcap_lowPt_medium"   , pfiso30/pt   ) ) pass_medium=false;
            }
            else {
                if( !config.PassFloat( "cut_pfIso30_endcap_highPt_medium"   , pfiso30/pt   ) ) pass_medium=false;
            }
            if( !config.PassFloat( "cut_convfit_endcap_medium"   , convfit      ) ) pass_medium=false;
            if( !config.PassInt  ( "cut_misshits_endcap_medium"  , misshits     ) ) pass_medium=false;
            
            // Loose cuts
            if( !config.PassFloat( "cut_absdEtaIn_endcap_loose"    , dEtaIn       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_absdPhiIn_endcap_loose"    , dPhiIn       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap_loose" , sigmaIEIE    ) ) pass_loose=false;
            if( !config.PassFloat( "cut_d0_endcap_loose"        , d0           ) ) pass_loose=false;
            if( !config.PassFloat( "cut_z0_endcap_loose"        , z0           ) ) pass_loose=false;
            if( !config.PassFloat( "cut_hovere_endcap_loose"    , hovere       ) ) pass_loose=false;
            if( !config.PassFloat( "cut_eoverp_endcap_loose"    , eoverp       ) ) pass_loose=false;
            if( pt < 20 ) {
                if( !config.PassFloat( "cut_pfIso30_endcap_lowPt_loose"   , pfiso30/pt   ) ) pass_loose=false;
            }
            else {
                if( !config.PassFloat( "cut_pfIso30_endcap_highPt_loose"   , pfiso30/pt   ) ) pass_loose=false;
            }
            if( !config.PassFloat( "cut_convfit_endcap_loose"   , convfit      ) ) pass_loose=false;
            if( !config.PassInt  ( "cut_misshits_endcap_loose"  , misshits     ) ) pass_loose=false;

            // Very Loose cuts
            if( !config.PassFloat( "cut_absdEtaIn_endcap_veryloose"    , dEtaIn       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_absdPhiIn_endcap_veryloose"    , dPhiIn       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap_veryloose" , sigmaIEIE    ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_d0_endcap_veryloose"        , d0           ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_z0_endcap_veryloose"        , z0           ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_hovere_endcap_veryloose"    , hovere       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_eoverp_endcap_veryloose"    , eoverp       ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_pfIso30_endcap_veryloose"   , pfiso30/pt   ) ) pass_veryloose=false;
            if( !config.PassFloat( "cut_convfit_endcap_veryloose"   , convfit      ) ) pass_veryloose=false;
            if( !config.PassInt  ( "cut_misshits_endcap_veryloose"  , misshits     ) ) pass_veryloose=false;
            // tight trigger cuts
            if( !config.PassFloat( "cut_absdEtaIn_endcap_tightTrig"   , dEtaIn      ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_absdPhiIn_endcap_tightTrig"   , dPhiIn      ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_sigmaIEIE_endcap_tightTrig"   , sigmaIEIE   ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_hovere_endcap_tightTrig"   , hovere         ) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_ecalIso30_endcap_tightTrig"   , ecalIso30/pt) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_hcalIso30_endcap_tightTrig"   , hcalIso30/pt) ) pass_tightTrig=false;
            if( !config.PassFloat( "cut_trkIso30_endcap_tightTrig"   , trkIso30/pt  ) ) pass_tightTrig=false;
        }

        if( !config.PassBool( "cut_pid_tightTrig", pass_tightTrig ) ) continue;
        if( !config.PassBool( "cut_pid_tight"    , pass_tight     ) ) continue;
        if( !config.PassBool( "cut_pid_medium"   , pass_medium    ) ) continue;
        if( !config.PassBool( "cut_pid_loose"    , pass_loose     ) ) continue;
        if( !config.PassBool( "cut_pid_veryloose", pass_veryloose ) ) continue;

        OUT::el_n++;

        OUT::el_pt            -> push_back(pt);
        OUT::el_eta           -> push_back(eta);
        OUT::el_sceta         -> push_back(sceta);
        OUT::el_phi           -> push_back(phi);
        OUT::el_e             -> push_back(pt*cosh(eta));
        OUT::el_mva           -> push_back(mva);
        OUT::el_d0pv          -> push_back( d0 );
        OUT::el_z0pv          -> push_back( z0 );
        OUT::el_sigmaIEIE     -> push_back( sigmaIEIE );
        OUT::el_pfiso30       -> push_back( pfiso30 );
        OUT::el_hasMatchedConv-> push_back( convfit );
        OUT::el_passTight     -> push_back(pass_tight);
        OUT::el_passMedium    -> push_back(pass_medium);
        OUT::el_passLoose     -> push_back(pass_loose);
        OUT::el_passVeryLoose -> push_back(pass_veryloose);
        OUT::el_passTightTrig -> push_back(pass_tightTrig);

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

        std::vector<int> matchPIDPH;
        matchPIDPH.push_back(22);
        bool matchph = HasTruthMatch( ellv, matchPIDPH, 0.2 );
        OUT::el_truthMatch_ph->push_back( matchph );
        
    }

}        

void RunModule::BuildJet( ModuleConfig & config ) const {

    OUT::jet_pt        -> clear();
    OUT::jet_eta       -> clear();
    OUT::jet_phi       -> clear();
    OUT::jet_e         -> clear();
    OUT::jet_n          = 0;
    OUT::jet_ph_minDR  -> clear();

    for( int idx = 0; idx < IN::nJet; ++idx ) {
        
        float pt  = IN::jetPt[idx];
        float eta = IN::jetEta[idx];
        float phi = IN::jetPhi[idx];
        float en  = IN::jetEn[idx];

        TLorentzVector jetlv;
        jetlv.SetPtEtaPhiE( pt, eta, phi,en );

        if( !config.PassFloat( "cut_pt", pt ) ) continue;
        if( !config.PassFloat( "cut_abseta", eta ) ) continue;

        bool keep_jet = true;
        if( config.HasCut( "cut_jet_ele_dr" ) ) {
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
        }

        // don't continue if the jet should be rejected
        if( !keep_jet ) continue;

        float min_dr = 100.0;
        //if( config.HasCut( "cut_jet_ph_dr" ) ) {
            for( int pidx = 0; pidx < OUT::ph_n; pidx++ ) {
                TLorentzVector phlv;
                phlv.SetPtEtaPhiE( OUT::ph_pt->at(pidx), 
                                   OUT::ph_eta->at(pidx),
                                   OUT::ph_phi->at(pidx),
                                   OUT::ph_e->at(pidx)
                                  );

                //delta R 
                float dr = phlv.DeltaR( jetlv );
                if( dr < min_dr ) {
                    min_dr = dr;
                }
                if( !config.PassFloat( "cut_jet_ph_dr", dr ) ) keep_jet = false;
            }
        //}
        // don't continue if the jet should be rejected
        if( !keep_jet ) continue;

        if( config.HasCut( "cut_jet_mu_dr" ) ) {
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
        }

        // don't continue if the jet should be rejected
        if( !keep_jet ) continue;

        OUT::jet_pt        -> push_back(pt);
        OUT::jet_eta       -> push_back(eta);
        OUT::jet_phi       -> push_back(phi);
        OUT::jet_e         -> push_back(en);
        OUT::jet_ph_minDR  -> push_back(min_dr);
        OUT::jet_n++;
    }
            
}        

void RunModule::BuildPIDPhoton( ModuleConfig & config ) const {

    OUT::ph_pt            -> clear();
    OUT::ph_eta           -> clear();
    OUT::ph_phi           -> clear();
    OUT::ph_e             -> clear();
    OUT::ph_HoverE        -> clear();
    OUT::ph_sigmaIEIE     -> clear();
    OUT::ph_chIsoCorr     -> clear();
    OUT::ph_neuIsoCorr    -> clear();
    OUT::ph_phoIsoCorr    -> clear();
    OUT::ph_eleVeto       -> clear();
    OUT::ph_isConv        -> clear();
    OUT::ph_conv_nTrk     -> clear();
    OUT::ph_conv_vtx_x    -> clear();
    OUT::ph_conv_vtx_y    -> clear();
    OUT::ph_conv_vtx_z    -> clear();
    OUT::ph_conv_ptin1    -> clear();
    OUT::ph_conv_ptin2    -> clear();
    OUT::ph_conv_ptout1   -> clear();
    OUT::ph_conv_ptout2   -> clear();
    OUT::ph_passLoose     -> clear();
    OUT::ph_passMedium    -> clear();
    OUT::ph_passTight     -> clear();
    OUT::ph_truthMatch_ph -> clear();
    OUT::ph_truthMatch_el -> clear();
    OUT::ph_truthMatch_mu -> clear();
    OUT::ph_truthMatch_q  -> clear();
    OUT::ph_n          = 0;

    for( int idx = 0; idx < IN::nPho; ++idx ) {
        float pt        = IN::phoEt[idx];
        float eta       = IN::phoEta[idx];
        float sceta     = IN::phoSCEta[idx];
        float phi       = IN::phoPhi[idx];
        float en        = IN::phoE[idx];

        float rho = IN::rho2012;

        int   eleVeto   = IN::phoEleVeto[idx];
        float hovere    = IN::phoHoverE[idx];
        float sigmaIEIE = IN::phoSigmaIEtaIEta[idx];
        //int   pixseed   = IN::phohasPixelSeed[idx];

        float pfChIso     = IN::phoPFChIso[idx];
        float pfNeuIso    = IN::phoPFNeuIso[idx];
        float pfPhoIso    = IN::phoPFPhoIso[idx];

        float pfChIsoRhoCorr = 0.0;
        float pfNeuIsoRhoCorr = 0.0;
        float pfPhoIsoRhoCorr = 0.0;
        calc_corr_iso( pfChIso, pfPhoIso, pfNeuIso, rho, eta, pfChIsoRhoCorr, pfPhoIsoRhoCorr, pfNeuIsoRhoCorr);

        float pfChIsoPtRhoCorr  = pfChIsoRhoCorr;
        float pfNeuIsoPtRhoCorr = pfNeuIsoRhoCorr-0.04*pt;
        float pfPhoIsoPtRhoCorr = pfPhoIsoRhoCorr-0.005*pt;

        if( !config.PassFloat( "cut_pt"    , pt       ) ) continue;
        if( !config.PassFloat( "cut_abseta"    , fabs(sceta)       ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack"    , fabs(sceta)       ) ) continue;
        if( !config.PassFloat( "cut_emfrac"    , hovere ) ) continue;
        if( !config.PassBool ( "cut_eveto"     , eleVeto) ) continue;

        if( fabs(sceta) < 1.479 ) { // barrel

            if( !config.PassFloat( "cut_sigmaIEIE_barrel"   , sigmaIEIE         ) ) continue;
            if( !config.PassFloat( "cut_chIsoCorr_barrel"   , pfChIsoPtRhoCorr  ) ) continue;
            if( !config.PassFloat( "cut_neuIsoCorr_barrel"  , pfNeuIsoPtRhoCorr ) ) continue;
            if( !config.PassFloat( "cut_phoIsoCorr_barrel"  , pfPhoIsoPtRhoCorr ) ) continue;

        }
        else {
            if( !config.PassFloat( "cut_sigmaIEIE_endcap"   , sigmaIEIE         ) ) continue;
            if( !config.PassFloat( "cut_chIsoCorr_endcap"   , pfChIsoPtRhoCorr  ) ) continue;
            if( !config.PassFloat( "cut_neuIsoCorr_endcap"  , pfNeuIsoPtRhoCorr ) ) continue;
            if( !config.PassFloat( "cut_phoIsoCorr_endcap"  , pfPhoIsoPtRhoCorr ) ) continue;

        }


        OUT::ph_n++;

        OUT::ph_pt         -> push_back(pt);
        OUT::ph_eta        -> push_back(eta);
        OUT::ph_phi        -> push_back(phi);
        OUT::ph_e          -> push_back(pt*cosh(eta));
        OUT::ph_HoverE     -> push_back(hovere);
        OUT::ph_sigmaIEIE  -> push_back(sigmaIEIE);
        OUT::ph_chIsoCorr  -> push_back(pfChIsoPtRhoCorr);
        OUT::ph_neuIsoCorr -> push_back(pfNeuIsoPtRhoCorr);
        OUT::ph_phoIsoCorr -> push_back(pfPhoIsoPtRhoCorr);
        OUT::ph_eleVeto    -> push_back(eleVeto);

        // fill conversion info
        // the ntuples fill default values when the
        // photon is not converted, so just keep that

        OUT::ph_isConv     -> push_back(IN::phoIsConv[idx]);
        OUT::ph_conv_nTrk  -> push_back(IN::phoConvNTrks[idx]);
        OUT::ph_conv_vtx_x -> push_back(IN::phoConvVtx[idx][0]);
        OUT::ph_conv_vtx_y -> push_back(IN::phoConvVtx[idx][1]);
        OUT::ph_conv_vtx_z -> push_back(IN::phoConvVtx[idx][2]);
        // get the individual track pt
        // i'm not sure if its pt sorted, so lets
        // do that now to be sure
        float ptin_idx0 = IN::phoConvTrkPin[idx][0];
        float ptin_idx1 = IN::phoConvTrkPin[idx][1];
        float ptout_idx0 = IN::phoConvTrkPout[idx][0];
        float ptout_idx1 = IN::phoConvTrkPout[idx][1];
        if( ptin_idx0 > ptin_idx1 ) {
            OUT::ph_conv_ptin1 -> push_back(ptin_idx0);
            OUT::ph_conv_ptin2 -> push_back(ptin_idx1);
        }
        else {
            OUT::ph_conv_ptin2 -> push_back(ptin_idx0);
            OUT::ph_conv_ptin1 -> push_back(ptin_idx1);
        }
        if( ptout_idx0 > ptout_idx1 ) {
            OUT::ph_conv_ptout1 -> push_back(ptout_idx0);
            OUT::ph_conv_ptout2 -> push_back(ptout_idx1);
        }
        else {
            OUT::ph_conv_ptout2 -> push_back(ptout_idx0);
            OUT::ph_conv_ptout1 -> push_back(ptout_idx1);
        }

        // truth matching
        TLorentzVector phlv;
        phlv.SetPtEtaPhiE( pt, eta, phi, en );
        RunPhotonTruthMatching( phlv );
    }

}        
void RunModule::BuildPhoton( ModuleConfig & config ) const {

    OUT::ph_pt         -> clear();
    OUT::ph_eta        -> clear();
    OUT::ph_phi        -> clear();
    OUT::ph_e          -> clear();
    OUT::ph_HoverE     -> clear();
    OUT::ph_sigmaIEIE  -> clear();
    OUT::ph_chIsoCorr  -> clear();
    OUT::ph_neuIsoCorr -> clear();
    OUT::ph_phoIsoCorr -> clear();
    OUT::ph_eleVeto    -> clear();
    OUT::ph_isConv     -> clear();
    OUT::ph_conv_nTrk  -> clear();
    OUT::ph_conv_vtx_x -> clear();
    OUT::ph_conv_vtx_y -> clear();
    OUT::ph_conv_vtx_z -> clear();
    OUT::ph_conv_ptin1 -> clear();
    OUT::ph_conv_ptin2 -> clear();
    OUT::ph_conv_ptout1-> clear();
    OUT::ph_conv_ptout2-> clear();
    OUT::ph_passLoose  -> clear();
    OUT::ph_passMedium -> clear();
    OUT::ph_passTight  -> clear();
    OUT::ph_truthMatch_ph -> clear();
    OUT::ph_truthMatch_el -> clear();
    OUT::ph_truthMatch_mu -> clear();
    OUT::ph_truthMatch_q  -> clear();
    OUT::ph_n          = 0;

    for( int idx = 0; idx < IN::nPho; ++idx ) {
        float pt        = IN::phoEt[idx];
        float eta       = IN::phoEta[idx];
        float sceta     = IN::phoSCEta[idx];
        float phi       = IN::phoPhi[idx];
        float en        = IN::phoE[idx];

        float rho = IN::rho2012;

        int   eleVeto   = IN::phoEleVeto[idx];
        float hovere    = IN::phoHoverE[idx];
        float sigmaIEIE = IN::phoSigmaIEtaIEta[idx];
        //int   pixseed   = IN::phohasPixelSeed[idx];

        float pfChIso     = IN::phoPFChIso[idx];
        float pfNeuIso    = IN::phoPFNeuIso[idx];
        float pfPhoIso    = IN::phoPFPhoIso[idx];

        float pfChIsoRhoCorr = 0.0;
        float pfNeuIsoRhoCorr = 0.0;
        float pfPhoIsoRhoCorr = 0.0;
        calc_corr_iso( pfChIso, pfPhoIso, pfNeuIso, rho, eta, pfChIsoRhoCorr, pfPhoIsoRhoCorr, pfNeuIsoRhoCorr);

        float pfChIsoPtRhoCorr  = pfChIsoRhoCorr;
        float pfNeuIsoPtRhoCorr = pfNeuIsoRhoCorr-0.04*pt;
        float pfPhoIsoPtRhoCorr = pfPhoIsoRhoCorr-0.005*pt;

        if( !config.PassFloat( "cut_pt"    , pt       ) ) continue;
        if( !config.PassFloat( "cut_abseta"    , fabs(sceta)       ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack"    , fabs(sceta)       ) ) continue;
        if( !config.PassFloat( "cut_emfrac"    , hovere ) ) continue;
        if( !config.PassBool ( "cut_eveto"     , eleVeto) ) continue;

        bool pass_loose  = true;
        bool pass_medium = true;
        bool pass_tight  = true;

        if( fabs(sceta) < 1.479 ) { // barrel

            if( !config.PassFloat( "cut_sigmaIEIE_barrel_loose"   , sigmaIEIE         ) ) pass_loose=false;
            if( !config.PassFloat( "cut_chIsoCorr_barrel_loose"   , pfChIsoPtRhoCorr  ) ) pass_loose=false;
            if( !config.PassFloat( "cut_neuIsoCorr_barrel_loose"  , pfNeuIsoPtRhoCorr ) ) pass_loose=false;
            if( !config.PassFloat( "cut_phoIsoCorr_barrel_loose"  , pfPhoIsoPtRhoCorr ) ) pass_loose=false;

            if( !config.PassFloat( "cut_sigmaIEIE_barrel_medium"  , sigmaIEIE         ) ) pass_medium=false;
            if( !config.PassFloat( "cut_chIsoCorr_barrel_medium"  , pfChIsoPtRhoCorr  ) ) pass_medium=false;
            if( !config.PassFloat( "cut_neuIsoCorr_barrel_medium" , pfNeuIsoPtRhoCorr ) ) pass_medium=false;
            if( !config.PassFloat( "cut_phoIsoCorr_barrel_medium" , pfPhoIsoPtRhoCorr ) ) pass_medium=false;

            if( !config.PassFloat( "cut_sigmaIEIE_barrel_tight"   , sigmaIEIE         ) ) pass_tight=false;
            if( !config.PassFloat( "cut_chIsoCorr_barrel_tight"   , pfChIsoPtRhoCorr  ) ) pass_tight=false;
            if( !config.PassFloat( "cut_neuIsoCorr_barrel_tight"  , pfNeuIsoPtRhoCorr ) ) pass_tight=false;
            if( !config.PassFloat( "cut_phoIsoCorr_barrel_tight"  , pfPhoIsoPtRhoCorr ) ) pass_tight=false;

        }
        else {
            if( !config.PassFloat( "cut_sigmaIEIE_endcap_loose"   , sigmaIEIE         ) ) pass_loose=false;
            if( !config.PassFloat( "cut_chIsoCorr_endcap_loose"   , pfChIsoPtRhoCorr  ) ) pass_loose=false;
            if( !config.PassFloat( "cut_neuIsoCorr_endcap_loose"  , pfNeuIsoPtRhoCorr ) ) pass_loose=false;
            if( !config.PassFloat( "cut_phoIsoCorr_endcap_loose"  , pfPhoIsoPtRhoCorr ) ) pass_loose=false;

            if( !config.PassFloat( "cut_sigmaIEIE_endcap_medium"  , sigmaIEIE         ) ) pass_medium=false;
            if( !config.PassFloat( "cut_chIsoCorr_endcap_medium"  , pfChIsoPtRhoCorr  ) ) pass_medium=false;
            if( !config.PassFloat( "cut_neuIsoCorr_endcap_medium" , pfNeuIsoPtRhoCorr ) ) pass_medium=false;
            if( !config.PassFloat( "cut_phoIsoCorr_endcap_medium" , pfPhoIsoPtRhoCorr ) ) pass_medium=false;

            if( !config.PassFloat( "cut_sigmaIEIE_endcap_tight"   , sigmaIEIE         ) ) pass_tight=false;
            if( !config.PassFloat( "cut_chIsoCorr_endcap_tight"   , pfChIsoPtRhoCorr  ) ) pass_tight=false;
            if( !config.PassFloat( "cut_neuIsoCorr_endcap_tight"  , pfNeuIsoPtRhoCorr ) ) pass_tight=false;
            if( !config.PassFloat( "cut_phoIsoCorr_endcap_tight"  , pfPhoIsoPtRhoCorr ) ) pass_tight=false;
        }

        if( !config.PassBool( "cut_pid_tight"    , pass_tight     ) ) continue;
        if( !config.PassBool( "cut_pid_medium"   , pass_medium    ) ) continue;
        if( !config.PassBool( "cut_pid_loose"    , pass_loose     ) ) continue;

        OUT::ph_n++;

        OUT::ph_pt         -> push_back(pt);
        OUT::ph_eta        -> push_back(eta);
        OUT::ph_phi        -> push_back(phi);
        OUT::ph_e          -> push_back(pt*cosh(eta));
        OUT::ph_HoverE     -> push_back(hovere);
        OUT::ph_sigmaIEIE  -> push_back(sigmaIEIE);
        OUT::ph_chIsoCorr  -> push_back(pfChIsoPtRhoCorr);
        OUT::ph_neuIsoCorr -> push_back(pfNeuIsoPtRhoCorr);
        OUT::ph_phoIsoCorr -> push_back(pfPhoIsoPtRhoCorr);
        OUT::ph_passTight  -> push_back(pass_tight);
        OUT::ph_passMedium -> push_back(pass_medium);
        OUT::ph_passLoose  -> push_back(pass_loose);
        OUT::ph_eleVeto    -> push_back(eleVeto);

        // fill conversion info
        // the ntuples fill default values when the
        // photon is not converted, so just keep that

        OUT::ph_isConv     -> push_back(IN::phoIsConv[idx]);
        OUT::ph_conv_nTrk  -> push_back(IN::phoConvNTrks[idx]);
        OUT::ph_conv_vtx_x -> push_back(IN::phoConvVtx[idx][0]);
        OUT::ph_conv_vtx_y -> push_back(IN::phoConvVtx[idx][1]);
        OUT::ph_conv_vtx_z -> push_back(IN::phoConvVtx[idx][2]);
        // get the individual track pt
        // i'm not sure if its pt sorted, so lets
        // do that now to be sure
        float ptin_idx0 = IN::phoConvTrkPin[idx][0];
        float ptin_idx1 = IN::phoConvTrkPin[idx][1];
        float ptout_idx0 = IN::phoConvTrkPout[idx][0];
        float ptout_idx1 = IN::phoConvTrkPout[idx][1];
        if( ptin_idx0 > ptin_idx1 ) {
            OUT::ph_conv_ptin1 -> push_back(ptin_idx0);
            OUT::ph_conv_ptin2 -> push_back(ptin_idx1);
        }
        else {
            OUT::ph_conv_ptin2 -> push_back(ptin_idx0);
            OUT::ph_conv_ptin1 -> push_back(ptin_idx1);
        }
        if( ptout_idx0 > ptout_idx1 ) {
            OUT::ph_conv_ptout1 -> push_back(ptout_idx0);
            OUT::ph_conv_ptout2 -> push_back(ptout_idx1);
        }
        else {
            OUT::ph_conv_ptout2 -> push_back(ptout_idx0);
            OUT::ph_conv_ptout1 -> push_back(ptout_idx1);
        }

        // truth matching
        TLorentzVector phlv;
        phlv.SetPtEtaPhiE( pt, eta, phi, en );
        RunPhotonTruthMatching( phlv );

        
    }
            
}        

void RunModule::RunPhotonTruthMatching( const TLorentzVector & phlv ) const {

    std::vector<int> matchPIDEl;
    std::vector<int> matchPIDMu;
    std::vector<int> matchPIDPh;
    std::vector<int> matchPIDQ;

    matchPIDEl.push_back(11);
    matchPIDEl.push_back(-11);
    matchPIDMu.push_back(13);
    matchPIDMu.push_back(-13);
    matchPIDPh.push_back(22);
    matchPIDQ.push_back( 111);
    matchPIDQ.push_back( 211 );

    bool has_match_el = HasTruthMatch( phlv, matchPIDEl, 0.2);
    bool has_match_mu = HasTruthMatch( phlv, matchPIDMu, 0.2);
    bool has_match_ph = HasTruthMatch( phlv, matchPIDPh, 0.2);
    bool has_match_q = HasTruthMatch( phlv, matchPIDQ, 0.2);
    OUT::ph_truthMatch_el->push_back( has_match_el );
    OUT::ph_truthMatch_mu->push_back( has_match_mu );
    OUT::ph_truthMatch_ph->push_back( has_match_ph );
    OUT::ph_truthMatch_q ->push_back( has_match_q  );

}

void RunModule::BuildSLPhoton( ModuleConfig & config ) const {

    OUT::ph_sl_n = 0;
    OUT::ph_sl_pt       -> clear();
    OUT::ph_sl_eta      -> clear();
    OUT::ph_sl_phi      -> clear();
    OUT::ph_sl_e        -> clear();
    OUT::ph_sl_d0       -> clear();
    OUT::ph_sl_z0       -> clear();
    OUT::ph_sl_convfit  -> clear();
    OUT::ph_sl_misshits -> clear();

    for( int idx = 0; idx < IN::nEle; idx++) {
        float sigmaIEIE = IN::eleSigmaIEtaIEta[idx];
        float hovere    = IN::eleHoverE[idx];
        float pfiso30   = IN::elePFChIso03[idx];

        float pt        = IN::elePt[idx];
        float eta       = IN::eleEta[idx];
        float sceta     = IN::eleSCEta[idx];
        float phi       = IN::elePhi[idx];

        if( !config.PassFloat( "cut_sl_pt"  , pt  ) ) continue;

        if( !config.PassFloat( "cut_sl_abssceta"       , fabs(sceta) ) ) continue;
        if( !config.PassFloat( "cut_sl_abssceta_crack" , fabs(sceta) ) ) continue;

        if( fabs(sceta) < 1.479 ) { // barrel
            
            // Medium cuts
            if( !config.PassFloat( "cut_sl_sigmaIEIE_barrel_medium" , sigmaIEIE    ) ) continue;
            if( !config.PassFloat( "cut_sl_hovere_barrel_medium"    , hovere       ) ) continue;
            if( !config.PassFloat( "cut_sl_pfIso30_barrel_medium"   , pfiso30/pt   ) ) continue;

        }
        else { // endcap

            // Medium cuts
            if( !config.PassFloat( "cut_sl_sigmaIEIE_endcap_medium" , sigmaIEIE    ) ) continue;
            if( !config.PassFloat( "cut_sl_hovere_endcap_medium"    , hovere       ) ) continue;
            if( pt < 20 ) {
                if( !config.PassFloat( "cut_sl_pfIso30_endcap_lowPt_medium"   , pfiso30/pt   ) ) continue;
            }
            else {
                if( !config.PassFloat( "cut_sl_pfIso30_endcap_highPt_medium"   , pfiso30/pt   ) ) continue;
            }
            
        }

        OUT::ph_sl_n++;

        OUT::ph_sl_pt         -> push_back(pt);
        OUT::ph_sl_eta        -> push_back(eta);
        OUT::ph_sl_phi        -> push_back(phi);
        OUT::ph_sl_e          -> push_back(pt*cosh(eta));
        OUT::ph_sl_d0         -> push_back( fabs(IN::eleD0GV[idx]) );
        OUT::ph_sl_z0         -> push_back( fabs(IN::eleDzGV[idx]) );
        OUT::ph_sl_convfit    -> push_back( IN::eleConvVtxFit[idx] );
        OUT::ph_sl_misshits  -> push_back( IN::eleMissHits[idx] );


    }
}

// do this later, after PID has been applied
//void RunModule::BuildEvent( ModuleConfig & /*config*/ ) const {
//
//    std::vector<TLorentzVector> leptons;
//    std::vector<TLorentzVector> photons;
//    TLorentzVector metlv;
//    metlv.SetPtEtaPhiM( OUT::pfMET, 0.0, OUT::pfMETPhi, 0.0 );
//
//    for( int idx = 0; idx < OUT::el_n; ++idx ) {
//        TLorentzVector lep;
//        lep.SetPtEtaPhiE( OUT::el_pt->at(idx), 
//                          OUT::el_eta->at(idx),
//                          OUT::el_phi->at(idx),
//                          OUT::el_e->at(idx)
//                        );
//        leptons.push_back(lep);
//    }
//
//    for( int idx = 0; idx < OUT::mu_n; ++idx ) {
//        TLorentzVector lep;
//        lep.SetPtEtaPhiE( OUT::mu_pt->at(idx), 
//                          OUT::mu_eta->at(idx),
//                          OUT::mu_phi->at(idx),
//                          OUT::mu_e->at(idx)
//                        );
//        leptons.push_back(lep);
//    }
//
//    std::vector<std::pair<float, int> > sorted_photons;
//    for( int idx = 0; idx < OUT::ph_n; ++idx ) {
//        TLorentzVector phot;
//        phot.SetPtEtaPhiE(  OUT::ph_pt->at(idx), 
//                            OUT::ph_eta->at(idx),
//                            OUT::ph_phi->at(idx),
//                            OUT::ph_e->at(idx)
//                        );
//        photons.push_back(phot);
//        sorted_photons.push_back(std::make_pair( phot.Pt(), idx ));
//    }
//
//
//    // sort the list of photon momenta in descending order
//    std::sort(sorted_photons.rbegin(), sorted_photons.rend());
//
//    if( photons.size() > 1 ) { 
//        OUT::leadPhot_pt = sorted_photons[0].first;
//        OUT::sublPhot_pt = sorted_photons[1].first;
//
//        int leadidx = sorted_photons[0].second;
//        int sublidx = sorted_photons[1].second;
//        OUT::m_phph = ( photons[leadidx] + photons[sublidx] ).M();
//    }
//    else if ( photons.size() == 1 ) {
//        OUT::leadPhot_pt = sorted_photons[0].first;
//        OUT::sublPhot_pt = 0;
//    }
//
//    if( leptons.size() == 2 ) {
//        OUT::m_leplep = ( leptons[0] + leptons[1] ).M();
//    }
//
//    if( leptons.size() == 1 ) {
//       
//        OUT::mt_lep_met = calc_mt( leptons[0], metlv );
//
//        if( photons.size() > 1 ) { 
//
//            int leadidx = sorted_photons[0].second;
//            int sublidx = sorted_photons[1].second;
//
//            OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);
//            OUT::sublPhot_lepDR = photons[sublidx].DeltaR(leptons[0]);
//            OUT::ph_phDR    = photons[leadidx].DeltaR(photons[sublidx]);
//            OUT::phPhot_lepDR = (photons[leadidx]+photons[sublidx]).DeltaR(photons[sublidx]);
//            
//            OUT::leadPhot_lepDPhi = photons[leadidx].DeltaPhi(leptons[0]);
//            OUT::sublPhot_lepDPhi = photons[sublidx].DeltaPhi(leptons[0]);
//            OUT::ph_phDPhi    = photons[leadidx].DeltaPhi(photons[sublidx]);
//            OUT::phPhot_lepDPhi = (photons[leadidx]+photons[sublidx]).DeltaPhi(photons[sublidx]);
//            
//            OUT::mt_lepph1_met = calc_mt( leptons[0] + photons[leadidx], metlv );
//            OUT::mt_lepph2_met = calc_mt( leptons[0] + photons[sublidx], metlv );
//
//            OUT::mt_lepphph_met = calc_mt( leptons[0] + photons[leadidx] + photons[sublidx], metlv );
//
//            OUT::m_lepph1 = ( leptons[0] + photons[leadidx] ).M();
//            OUT::m_lepph2 = ( leptons[0] + photons[sublidx] ).M();
//            OUT::m_lepphph = ( leptons[0] + photons[leadidx] + photons[sublidx] ).M();
//        }
//        else if( photons.size() == 1 ) {
//
//            int leadidx = sorted_photons[0].second;
//            OUT::leadPhot_lepDR = photons[leadidx].DeltaR(leptons[0]);
//
//            OUT::mt_lepph1_met = calc_mt( leptons[0] + photons[leadidx], metlv );
//
//            OUT::m_lepph1 = ( leptons[0] + photons[leadidx] ).M();
//
//        }
//            
//            
//    }
//
//}

    

bool RunModule::FilterEvent( ModuleConfig & config ) const {

    int nlep = 0;
    int nlep25 = 0;
    for( int i = 0; i < OUT::el_n; i++ ) {
        nlep++;
        if( OUT::el_pt->at(i) > 25 ) nlep25++;
    }
    for( int i = 0; i < OUT::mu_n; i++ ) {
        nlep++;
        if( OUT::mu_pt->at(i) > 25 ) nlep25++;
    }

    bool keep_event = true;
    if( !config.PassInt("cut_el_n", OUT::el_n ) ) keep_event = false;
    if( !config.PassInt("cut_mu_n", OUT::mu_n ) ) keep_event = false;
    if( !config.PassInt("cut_lep_n", nlep     ) ) keep_event = false;
    if( !config.PassInt("cut_lep25_n", nlep25 ) ) keep_event = false;

    return keep_event;

    
}

bool RunModule::HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR ) const {
    
    float minDR = 100.0;
    return HasTruthMatch( objlv, matchPID, maxDR, minDR );

}

bool RunModule::HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR, float & minDR ) const {
   
    minDR = 100.0;
    bool match=false;

    #ifdef EXISTS_nMC
    for( int mcidx = 0; mcidx < IN::nMC; mcidx++ ) {
        
        if( std::find( matchPID.begin(), matchPID.end(), IN::mcPID[mcidx] ) == matchPID.end() ) continue;

        #ifdef EXISTS_mcStatus
        if( IN::mcStatus[mcidx] != 1 ) continue;
        #endif

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
    #endif

    return match;

}

void RunModule::calc_corr_iso( float chIso, float phoIso, float neuIso, float rho, float eta, float &chIsoCorr, float &phoIsoCorr, float &neuIsoCorr )  const
{

    float ea_ch;
    float ea_pho;
    float ea_neu;

    if( fabs( eta ) < 1.0 ) {
        ea_ch = 0.012;
        ea_neu = 0.03;
        ea_pho = 0.148;
    }
    else if( fabs(eta) >= 1.0 && fabs( eta ) < 1.479 ) {
        ea_ch = 0.01;
        ea_neu = 0.057;
        ea_pho = 0.13;
    }
    else if( fabs(eta) >= 1.479 && fabs( eta ) < 2.0 ) {
        ea_ch = 0.014;
        ea_neu = 0.039;
        ea_pho = 0.112;
    }
    else if( fabs(eta) >= 2.0 && fabs( eta ) < 2.2 ) {
        ea_ch = 0.012;
        ea_neu = 0.015;
        ea_pho = 0.216;
    }
    else if( fabs(eta) >= 2.2 && fabs( eta ) < 2.3 ) {
        ea_ch = 0.016;
        ea_neu = 0.024;
        ea_pho = 0.262;
    }
    else if( fabs(eta) >= 2.3 && fabs( eta ) < 2.4 ) {
        ea_ch = 0.02;
        ea_neu = 0.039;
        ea_pho = 0.260;
    }
    else if( fabs(eta) >= 2.4 ) {
        ea_ch = 0.012;
        ea_neu = 0.072;
        ea_pho = 0.266;
    }

    chIsoCorr  = chIso  - rho*ea_ch;
    phoIsoCorr = phoIso - rho*ea_pho;
    neuIsoCorr = neuIso - rho*ea_neu;

    if( chIsoCorr < 0 ) {
        chIsoCorr = 0;
    }
    if( phoIsoCorr < 0 ) {
        phoIsoCorr = 0;
    }
    if( neuIsoCorr < 0 ) {
        neuIsoCorr = 0;
    }

}
