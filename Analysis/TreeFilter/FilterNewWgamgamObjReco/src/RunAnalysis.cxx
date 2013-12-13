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

    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );
    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^_^ Finished ^_^" << std::endl;


}

void RunModule::initialize( TChain * chain, TTree * outtree, TFile *outfile,
                            const CmdOptions & options ) {

    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    // *************************
    // Set defaults for added output variables
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
    OUT::ph_truthMatch     = 0;
    OUT::ph_truthMinDR     = 0;
    OUT::ph_hasSLConv      = 0;

    OUT::jet_pt             = 0;
    OUT::jet_eta            = 0;
    OUT::jet_phi            = 0;
    OUT::jet_e              = 0;

    // *************************
    // Declare Branches
    // *************************
    outtree->Branch("el_n"               , &OUT::el_n  , "el_n/I"                        );
    outtree->Branch("mu_n"               , &OUT::mu_n  , "mu_n/I"                        );
    outtree->Branch("ph_n"               , &OUT::ph_n , "ph_n/I"                         );
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
    outtree->Branch("ph_truthMatch"    , &OUT::ph_truthMatch                             );
    outtree->Branch("ph_truthMinDR"    , &OUT::ph_truthMinDR                             );
    outtree->Branch("ph_hasSLConv"     , &OUT::ph_hasSLConv                              );
    
    outtree->Branch("jet_pt"            , &OUT::jet_pt                                   );
    outtree->Branch("jet_eta"           , &OUT::jet_eta                                  );
    outtree->Branch("jet_phi"           , &OUT::jet_phi                                  );
    outtree->Branch("jet_e"             , &OUT::jet_e                                    );

    //outtree->Branch("avgPU"              , &OUT::avgPU, "avgPU/F"                        );

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
    if( config.GetName() == "BuildJet" ) {
        BuildJet( config );
    }

    // If the module applies a filter the filter decision
    // is passed back to here.  There is no requirement
    // that a function returns a bool, but
    // if you want the filter to work you need to do this
    //
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
       
        float pt = IN::muPt->at(idx);
        float eta = IN::muEta->at(idx);
        float phi = IN::muPhi->at(idx);
        unsigned int GlobalMuon = 1<<1;
        unsigned int PFMuon =  1<<5;
        bool is_global_muon = IN::muType->at(idx) & GlobalMuon;
        bool is_pf_muon = IN::muType->at(idx) & GlobalMuon;

        float chi2       = IN::muChi2NDF->at(idx);
        int   nHits      = IN::muNumberOfValidMuonHits->at(idx);
        int   nTrkLayers = IN::muNumberOfValidTrkLayers->at(idx);
        int   muStations = IN::muStations->at(idx);
        int   nPixHit    = IN::muNumberOfValidPixelHits->at(idx);
        float d0         = IN::muD0GV->at(idx);
        float z0         = IN::muDzGV->at(idx);
        float tkIso      = IN::muIsoTrk->at(idx);
        float muPFIsoCH  = IN::muPFIsoR04_CH->at(idx);
        float muPFIsoNH  = IN::muPFIsoR04_NH->at(idx);
        float muPFIsoPho = IN::muPFIsoR04_Pho->at(idx);
        float muPFIsoPU  = IN::muPFIsoR04_PU->at(idx);

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
        float dEtaIn    = fabs(IN::eledEtaAtVtx->at(idx));
        float dPhiIn    = fabs(IN::eledPhiAtVtx->at(idx));
        float sigmaIEIE = IN::eleSigmaIEtaIEta->at(idx);
        float d0        = fabs(IN::eleD0GV->at(idx));
        float z0        = fabs(IN::eleDzGV->at(idx));
        float hovere    = IN::eleHoverE->at(idx);
        //float eoverp    = IN::eleEoverP->at(idx);
        float pfiso30   = IN::elePFChIso03->at(idx);
        float convfit   = IN::eleConvVtxFit->at(idx);
        int misshits    = IN::eleMissHits->at(idx);

        float pt        = IN::elePt->at(idx);
        float eta       = IN::eleEta->at(idx);
        float sceta     = IN::eleSCEta->at(idx);
        float phi       = IN::elePhi->at(idx);
        float en        = IN::eleEn->at(idx);
        float p         = en/(IN::eleEoverP->at(idx));
        float eoverp    = fabs( (1/en) - (1/p) );
        float mva       = IN::eleIDMVATrig->at(idx);

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

        float dEtaIn    = fabs(IN::eledEtaAtVtx->at(idx));
        float dPhiIn    = fabs(IN::eledPhiAtVtx->at(idx));
        float sigmaIEIE = IN::eleSigmaIEtaIEta->at(idx);
        float d0        = fabs(IN::eleD0GV->at(idx));
        float z0        = fabs(IN::eleDzGV->at(idx));
        float hovere    = IN::eleHoverE->at(idx);
        //float eoverp    = IN::eleEoverP->at(idx);
        float pfiso30   = IN::elePFChIso03->at(idx);
        float convfit   = IN::eleConvVtxFit->at(idx);
        int misshits    = IN::eleMissHits->at(idx);

        float pt        = IN::elePt->at(idx);
        float eta       = IN::eleEta->at(idx);
        float sceta     = IN::eleSCEta->at(idx);
        float phi       = IN::elePhi->at(idx);
        float en        = IN::eleEn->at(idx);
        float p         = en/(IN::eleEoverP->at(idx));
        float eoverp    = fabs( (1/en) - (1/p) );
        float mva       = IN::eleIDMVATrig->at(idx);
        float ecalIso30 = IN::eleIsoEcalDR03->at(idx);
        float hcalIso30 = IN::eleIsoHcalDR03->at(idx);
        float trkIso30  = IN::eleIsoTrkDR03->at(idx);

        if( !config.PassFloat( "cut_pt"  , pt  ) ) continue;

        if( !config.PassFloat( "cut_abseta"         , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abseta_crack"   , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abssceta"       , fabs(eta) ) ) continue;
        if( !config.PassFloat( "cut_abssceta_crack" , fabs(eta) ) ) continue;

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

    for( int idx = 0; idx < IN::nJet; ++idx ) {
        
        float pt  = IN::jetPt->at(idx);
        float eta = IN::jetEta->at(idx);
        float phi = IN::jetPhi->at(idx);
        float en  = IN::jetEn->at(idx);

        if( !config.PassFloat( "cut_pt", pt ) ) continue;
        if( !config.PassFloat( "cut_abseta", eta ) ) continue;

        OUT::jet_pt        -> push_back(pt);
        OUT::jet_eta       -> push_back(eta);
        OUT::jet_phi       -> push_back(phi);
        OUT::jet_e         -> push_back(en);
        OUT::jet_n++;
    }
            
}        

void RunModule::BuildPIDPhoton( ModuleConfig & config ) const {

    OUT::ph_pt         -> clear();
    OUT::ph_eta        -> clear();
    OUT::ph_phi        -> clear();
    OUT::ph_e          -> clear();
    OUT::ph_HoverE     -> clear();
    OUT::ph_sigmaIEIE  -> clear();
    OUT::ph_chIsoCorr  -> clear();
    OUT::ph_neuIsoCorr -> clear();
    OUT::ph_phoIsoCorr -> clear();
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
    OUT::ph_truthMatch -> clear();
    OUT::ph_truthMinDR -> clear();
    OUT::ph_n          = 0;

    for( int idx = 0; idx < IN::nPho; ++idx ) {
        float pt        = IN::phoEt->at(idx);
        float eta       = IN::phoEta->at(idx);
        float sceta     = IN::phoSCEta->at(idx);
        float phi       = IN::phoPhi->at(idx);
        float en        = IN::phoE->at(idx);
        int   isConv    = IN::phoIsConv->at(idx);

        float rho = IN::rho2012;

        int   eleVeto   = IN::phoEleVeto->at(idx);
        float hovere    = IN::phoHoverE->at(idx);
        float sigmaIEIE = IN::phoSigmaIEtaIEta->at(idx);
        int   pixseed   = IN::phohasPixelSeed->at(idx);

        float isohollow40 = IN::phoTrkIsoHollowDR04->at(idx);
        float ecaliso40   = IN::phoEcalIsoDR04->at(idx);
        float hcaliso40   = IN::phoHcalIsoDR04->at(idx);

        float pfChIso     = IN::phoPFChIso->at(idx);
        float pfNeuIso    = IN::phoPFNeuIso->at(idx);
        float pfPhoIso    = IN::phoPFPhoIso->at(idx);

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

        bool pass = true;

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

        // fill conversion info
        // the ntuples fill default values when the
        // photon is not converted, so just keep that

        OUT::ph_isConv     -> push_back(IN::phoIsConv->at(idx));
        OUT::ph_conv_nTrk  -> push_back(IN::phoConvNTrks->at(idx));
        OUT::ph_conv_vtx_x -> push_back(IN::phoConvVtx_x->at(idx));
        OUT::ph_conv_vtx_y -> push_back(IN::phoConvVtx_y->at(idx));
        OUT::ph_conv_vtx_z -> push_back(IN::phoConvVtx_z->at(idx));
        // get the individual track pt
        // i'm not sure if its pt sorted, so lets
        // do that now to be sure
        float ptin_idx0 = IN::phoConvTrkPin_x->at(idx);
        float ptin_idx1 = IN::phoConvTrkPin_y->at(idx);
        float ptout_idx0 = IN::phoConvTrkPout_x->at(idx);
        float ptout_idx1 = IN::phoConvTrkPout_y->at(idx);
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
    OUT::ph_truthMatch -> clear();
    OUT::ph_truthMinDR -> clear();
    OUT::ph_hasSLConv  -> clear();
    OUT::ph_n          = 0;

    for( int idx = 0; idx < IN::nPho; ++idx ) {
        float pt        = IN::phoEt->at(idx);
        float eta       = IN::phoEta->at(idx);
        float sceta     = IN::phoSCEta->at(idx);
        float phi       = IN::phoPhi->at(idx);
        float en        = IN::phoE->at(idx);
        int   isConv    = IN::phoIsConv->at(idx);

        float rho = IN::rho2012;

        int   eleVeto   = IN::phoEleVeto->at(idx);
        float hovere    = IN::phoHoverE->at(idx);
        float sigmaIEIE = IN::phoSigmaIEtaIEta->at(idx);
        int   pixseed   = IN::phohasPixelSeed->at(idx);

        float isohollow40 = IN::phoTrkIsoHollowDR04->at(idx);
        float ecaliso40   = IN::phoEcalIsoDR04->at(idx);
        float hcaliso40   = IN::phoHcalIsoDR04->at(idx);

        float pfChIso     = IN::phoPFChIso->at(idx);
        float pfNeuIso    = IN::phoPFNeuIso->at(idx);
        float pfPhoIso    = IN::phoPFPhoIso->at(idx);

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

        // fill conversion info
        // the ntuples fill default values when the
        // photon is not converted, so just keep that

        OUT::ph_isConv     -> push_back(IN::phoIsConv->at(idx));
        OUT::ph_conv_nTrk  -> push_back(IN::phoConvNTrks->at(idx));
        OUT::ph_conv_vtx_x -> push_back(IN::phoConvVtx_x->at(idx));
        OUT::ph_conv_vtx_y -> push_back(IN::phoConvVtx_y->at(idx));
        OUT::ph_conv_vtx_z -> push_back(IN::phoConvVtx_z->at(idx));
        OUT::ph_hasSLConv  -> push_back(IN::pho_hasSLConvPf->at(idx));
        // get the individual track pt
        // i'm not sure if its pt sorted, so lets
        // do that now to be sure
        float ptin_idx0 = IN::phoConvTrkPin_x->at(idx);
        float ptin_idx1 = IN::phoConvTrkPin_y->at(idx);
        float ptout_idx0 = IN::phoConvTrkPout_x->at(idx);
        float ptout_idx1 = IN::phoConvTrkPout_y->at(idx);
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

        TLorentzVector phlv;
        phlv.SetPtEtaPhiE( pt, eta, phi, en );
        std::vector<int> matchPID;
        matchPID.push_back(22);

        float minTruthDR = 100.0;
        bool match = HasTruthMatch( phlv, matchPID, 0.1, minTruthDR );
        OUT::ph_truthMatch->push_back( match  );
        OUT::ph_truthMinDR->push_back( minTruthDR );
    }
            
}        

bool RunModule::FilterEvent( ModuleConfig & config ) const {

    bool keep_event = true;
    if( !config.PassInt("cut_el_n", OUT::el_n ) ) keep_event = false;
    if( !config.PassInt("cut_mu_n", OUT::mu_n ) ) keep_event = false;

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
        
        if( std::find( matchPID.begin(), matchPID.end(), IN::mcPID->at(mcidx) ) == matchPID.end() ) continue;

        #ifdef EXISTS_mcStatus
        if( IN::mcStatus->at(mcidx) != 1 ) continue;
        #endif

        TLorentzVector mclv;
        mclv.SetPtEtaPhiE( IN::mcPt->at(mcidx), IN::mcEta->at(mcidx), IN::mcPhi->at(mcidx), IN::mcE->at(mcidx) );
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
//
// ***********************************
// This is an example of a module that applies an
// event filter.  Note that it returns a bool instead
// of a void.  In principle the modules can return any
// type of variable, you just have to handle it
// in the ApplyModule function
// ***********************************


