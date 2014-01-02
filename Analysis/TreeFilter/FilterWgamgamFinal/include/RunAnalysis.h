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
        void initialize( TChain * chain, TTree *outtree, TFile *outfile, const CmdOptions & options, std::vector<ModuleConfig> & configs) ;
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
        void FilterJet         ( ModuleConfig & config ) const;
        void FilterElectron    ( ModuleConfig & config ) const;
        void FilterPhoton      ( ModuleConfig & config ) const;
        void FilterMuon        ( ModuleConfig & config ) const;
        void CalcEventVars     ( ModuleConfig & config ) const;
        bool FilterEvent       ( ModuleConfig & config ) const;

};

// Ouput namespace 
// Declare any output variables that you'll fill here
namespace OUT {

    Bool_t isBlinded;
    Float_t EventWeight;

    Int_t   mu_pt25_n;
    Int_t   el_pt25_n;

    Float_t leadPhot_pt;
    Float_t sublPhot_pt;
    Float_t leadPhot_lepDR;
    Float_t sublPhot_lepDR;
    Float_t ph_phDR;
    Float_t phPhot_lepDR;
    Float_t leadPhot_lepDPhi;
    Float_t sublPhot_lepDPhi;
    Float_t ph_phDPhi;
    Float_t phPhot_lepDPhi;
    Float_t mt_lep_met;
    Float_t mt_lepph1_met;
    Float_t mt_lepph2_met;
    Float_t mt_lepphph_met;
    Float_t m_leplep;
    Float_t m_lepph1;
    Float_t m_lepph2;
    Float_t m_leplepph;
    Float_t m_lepphph;
    Float_t m_phph;
    Float_t m_leplepZ;
    Float_t m_3lep;
    Float_t m_4lep;
    Float_t pt_leplep;
    Float_t pt_lepph1;
    Float_t pt_lepph2;
    Float_t pt_lepphph;
    Float_t pt_leplepph;
    Float_t pt_secondLepton;
    Float_t pt_thirdLepton;

    Float_t m_nearestToZ;

    //Examples
};

#endif
