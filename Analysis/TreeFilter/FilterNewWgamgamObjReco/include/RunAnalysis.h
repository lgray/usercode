#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>
#include <vector>


#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"

// The RunModule inherits from RunModuleBase (an Abstract Base Class )
// defined in the Core package so that all
// RunModules present a common interface in a Run function
// This allows the code defined in this package
// to be run from the Core package to minimize
// code duplication in each module
class RunModule : public virtual RunModuleBase {

    public :

        RunModule() {}

        // The run function must exist and be defined exactly as this
        // because it is defined in RunModuleBase 
        // in src/RunModule.cxx all the analysis is defind in this RunModule function
        void initialize(TChain * chain, TTree *outtree, TFile *outfile, const CmdOptions & options, std::vector<ModuleConfig> & configs);
        bool execute( std::vector<ModuleConfig> & config ) ;
        void finalize( ) {};

        // The ApplyModule function calls any other module defined below
        // in src/RunModule.cxx.  This funciton is not strictly required
        // but its a consistent way to apply modules
        bool ApplyModule         ( ModuleConfig & config ) const;


        // Define modules below.
        // There is no restriction on the naming
        // return values, or inputs to these functions, but
        // you must of course handle them in the source file
        // Examples :
        void BuildElectron       ( ModuleConfig & config ) const;
        void BuildMediumElectron ( ModuleConfig & config ) const;
        void BuildMuon           ( ModuleConfig & config ) const;
        void BuildPhoton         ( ModuleConfig & config ) const;
        void BuildJet            ( ModuleConfig & config ) const;
        void BuildEvent          ( ModuleConfig & config ) const;
        bool FilterElec          ( ModuleConfig & config ) const;
        bool FilterMuon          ( ModuleConfig & config ) const;
        bool FilterEvent         ( ModuleConfig & config ) const;
        bool FilterTauEvent      ( ModuleConfig & config ) const;
        bool FilterBasicEvent    ( ModuleConfig & config ) const;

        bool HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR ) const;
        bool HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR, float &minDR ) const;
        bool HasTruthMatch( const TLorentzVector & objlv, const std::vector<int> & matchPID, float maxDR, float &minDR, TLorentzVector &matchLV ) const;
        void calc_corr_iso( float chIso, float phoIso, float neuIso, float rho, float eta, float &chisoCorr, float &phoIsoCorr, float &neuIsoCorr ) const;

     private :

        bool eval_el_tight    ;
        bool eval_el_medium   ;
        bool eval_el_loose    ;
        bool eval_el_veryloose;
        bool eval_el_tightTrig;

        bool eval_ph_tight    ;
        bool eval_ph_medium   ;
        bool eval_ph_loose    ;
};

// Ouput namespace 
// Declare any output variables that you'll fill here
namespace OUT {

    Int_t              el_n;
    Int_t              mu_n;
    Int_t              ph_n;
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
    std::vector<Bool_t> *el_truthMatch_el;
    std::vector<float>  *el_truthMatchPt_el;
    std::vector<float>  *el_truthMinDR_el;

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
    std::vector<Bool_t> *ph_truthMatch_el;
    std::vector<Bool_t> *ph_truthMatch_ph;
    std::vector<float>  *ph_truthMinDR_el;
    std::vector<float>  *ph_truthMinDR_ph;
    std::vector<float>  *ph_truthMatchPt_el;
    std::vector<float>  *ph_truthMatchPt_ph;
    std::vector<Bool_t> *ph_hasSLConv;

    std::vector<float>  *jet_pt;
    std::vector<float>  *jet_eta;
    std::vector<float>  *jet_phi;
    std::vector<float>  *jet_e;

    Float_t             avgPU; 
};

#endif
