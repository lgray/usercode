#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>
#include <vector>


#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"

class RunModule : public virtual RunModuleBase {

    public :

        RunModule() {}

        void Run( TChain * chain, TTree *outtree, TFile *outfile, std::vector<ModuleConfig> & config, const CmdOptions & options, int minevt=0, int maxevt=0) const;

        bool ApplyModule         ( ModuleConfig & config ) const;
        void BuildElectron       ( ModuleConfig & config ) const;
        void BuildMediumElectron ( ModuleConfig & config ) const;
        void BuildMuon           ( ModuleConfig & config ) const;
        void BuildPhoton         ( ModuleConfig & config ) const;
        void BuildSLPhoton       ( ModuleConfig & config ) const;
        void BuildPIDPhoton      ( ModuleConfig & config ) const;
        void BuildJet            ( ModuleConfig & config ) const;
        void BuildEvent          ( ModuleConfig & config ) const;
        bool FilterEvent         ( ModuleConfig & config ) const;

        bool HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR ) const;
        bool HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR, float &minDR ) const;
        void calc_corr_iso( float chIso, float phoIso, float neuIso, float rho, float eta, float &chisoCorr, float &phoIsoCorr, float &neuIsoCorr ) const;
        void RunPhotonTruthMatching( const TLorentzVector & phlv ) const;
};


namespace OUT {

    Int_t              el_n;
    Int_t              mu_n;
    Int_t              ph_n;
    Int_t              ph_sl_n;
    Int_t              jet_n;
    Int_t              vtx_n;

    std::vector<float>  *el_pt;
    std::vector<float>  *el_eta;
    std::vector<float>  *el_sceta;
    std::vector<float>  *el_phi;
    std::vector<float>  *el_e;
    std::vector<float>  *el_mva;
    std::vector<float>  *el_d0pv;
    std::vector<float>  *el_z0pv;
    std::vector<float>  *el_sigmaIEIE;
    std::vector<float>  *el_pfiso30;
    std::vector<Bool_t> *el_hasMatchedConv;
    std::vector<Bool_t> *el_passTight;
    std::vector<Bool_t> *el_passMedium;
    std::vector<Bool_t> *el_passLoose;
    std::vector<Bool_t> *el_passVeryLoose;
    std::vector<Bool_t> *el_passTightTrig;
    std::vector<Bool_t> *el_truthMatch_ph;
    std::vector<Bool_t> *el_truthMatch;
    std::vector<float>  *el_truthMinDR;

    std::vector<float>  *mu_pt;
    std::vector<float>  *mu_eta;
    std::vector<float>  *mu_phi;
    std::vector<float>  *mu_e;
    std::vector<float>  *mu_pfIso_ch;
    std::vector<float>  *mu_pfIso_nh;
    std::vector<float>  *mu_pfIso_pho;
    std::vector<float>  *mu_pfIso_pu;
    std::vector<float>  *mu_corrIso;
    std::vector<Bool_t> *mu_truthMatch;
    std::vector<float>  *mu_truthMinDR;

    std::vector<float>  *ph_pt;
    std::vector<float>  *ph_eta;
    std::vector<float>  *ph_phi;
    std::vector<float>  *ph_e;
    std::vector<float>  *ph_HoverE;
    std::vector<float>  *ph_sigmaIEIE;
    std::vector<float>  *ph_chIsoCorr;
    std::vector<float>  *ph_neuIsoCorr;
    std::vector<float>  *ph_phoIsoCorr;
    std::vector<int>    *ph_eleVeto;
    std::vector<Bool_t> *ph_isConv;
    std::vector<int>    *ph_conv_nTrk;
    std::vector<float>  *ph_conv_vtx_x;
    std::vector<float>  *ph_conv_vtx_y;
    std::vector<float>  *ph_conv_vtx_z;
    std::vector<float>  *ph_conv_ptin1;
    std::vector<float>  *ph_conv_ptin2;
    std::vector<float>  *ph_conv_ptout1;
    std::vector<float>  *ph_conv_ptout2;
    std::vector<Bool_t> *ph_passTight;
    std::vector<Bool_t> *ph_passMedium;
    std::vector<Bool_t> *ph_passLoose;
    std::vector<Bool_t> *ph_truthMatch_ph;
    std::vector<Bool_t> *ph_truthMatch_el;
    std::vector<Bool_t> *ph_truthMatch_mu;
    std::vector<Bool_t> *ph_truthMatch_q;

    std::vector<float>  *ph_sl_pt;
    std::vector<float>  *ph_sl_eta;
    std::vector<float>  *ph_sl_phi;
    std::vector<float>  *ph_sl_e;
    std::vector<float>  *ph_sl_d0;
    std::vector<float>  *ph_sl_z0;
    std::vector<int>  *ph_sl_convfit;
    std::vector<int>  *ph_sl_misshits;


    std::vector<float>  *jet_pt;
    std::vector<float>  *jet_eta;
    std::vector<float>  *jet_phi;
    std::vector<float>  *jet_e;

    Float_t             avgPU; 

    //Float_t             met_et;
    //Float_t             met_phi;
    //Float_t             sumet;
    //Float_t             metsig;

    //Float_t             leadPhot_pt;
    //Float_t             sublPhot_pt;

    //Float_t             leadPhot_lepDR;
    //Float_t             sublPhot_lepDR;
    //Float_t             ph_phDR;
    //Float_t             phPhot_lepDR;
    //Float_t             leadPhot_lepDPhi;
    //Float_t             sublPhot_lepDPhi;
    //Float_t             ph_phDPhi;
    //Float_t             phPhot_lepDPhi;

    //Float_t             mt_lep_met;
    //Float_t             mt_lepph1_met;
    //Float_t             mt_lepph2_met;
    //Float_t             mt_lepphph_met;

    //Float_t             m_leplep;
    //Float_t             m_lepph1;
    //Float_t             m_lepph2;
    //Float_t             m_lepphph;
    //Float_t             m_phph;

};

#endif
