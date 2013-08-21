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

        void Run( TChain * chain, TTree *outtree, std::vector<ModuleConfig> & config, const CmdOptions & options, int minevt=0, int maxevt=0) const;

        bool ApplyModule      ( ModuleConfig & config ) const;
        void BuildElectron    ( ModuleConfig & config ) const;
        void BuildMuon      ( ModuleConfig & config ) const;
        void BuildPhoton      ( ModuleConfig & config ) const;
        void BuildEvent       ( ModuleConfig & config ) const;
        bool FilterElec       ( ModuleConfig & config ) const;
        bool FilterMuon       ( ModuleConfig & config ) const;
        bool FilterEvent      ( ModuleConfig & config ) const;
        bool FilterTauEvent   ( ModuleConfig & config ) const;
        bool FilterBasicEvent ( ModuleConfig & config ) const;

};


namespace OUT {

    Int_t              el_n;
    Int_t              mu_n;
    Int_t              phot_n;
    Int_t              vtx_n;

    std::vector<float>  *el_pt;
    std::vector<float>  *el_eta;
    std::vector<float>  *el_phi;
    std::vector<float>  *el_e;
    std::vector<float>  *el_mva;
    std::vector<Bool_t> *el_passTight;
    std::vector<Bool_t> *el_passMedium;
    std::vector<Bool_t> *el_passLoose;
    std::vector<Bool_t> *el_passVeryLoose;

    std::vector<float>  *mu_pt;
    std::vector<float>  *mu_eta;
    std::vector<float>  *mu_phi;
    std::vector<float>  *mu_e;

    std::vector<float>  *phot_pt;
    std::vector<float>  *phot_eta;
    std::vector<float>  *phot_phi;
    std::vector<float>  *phot_e;

    Float_t             avgPU; 

    Float_t             met_et;
    Float_t             met_phi;
    Float_t             sumet;
    Float_t             metsig;

    Float_t             leadPhot_pt;
    Float_t             sublPhot_pt;

    Float_t             leadPhot_lepDR;
    Float_t             sublPhot_lepDR;
    Float_t             phot_photDR;
    Float_t             photPhot_lepDR;
    Float_t             leadPhot_lepDPhi;
    Float_t             sublPhot_lepDPhi;
    Float_t             phot_photDPhi;
    Float_t             photPhot_lepDPhi;

    Float_t             mt_lep_met;
    Float_t             mt_lepphot1_met;
    Float_t             mt_lepphot2_met;
    Float_t             mt_lepphotphot_met;

    Float_t             m_leplep;
    Float_t             m_lepphot1;
    Float_t             m_lepphot2;
    Float_t             m_lepphotphot;
    Float_t             m_photphot;

};

#endif
