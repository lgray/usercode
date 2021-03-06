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

        // Define modules below.
        // There is no restriction on the naming
        // return values, or inputs to these functions, but
        // you must of course handle them in the source file
        void MakeNtuple ( ModuleConfig & config ) const;
        bool FilterEvent( ModuleConfig & config ) const;

        TTree * outtree;

};

// Ouput namespace 
// Declare any output variables that you'll fill here
namespace OUT {

    float              tag_pt;
    float              tag_eta_sc;
    float              tag_eta;
    float              tag_phi;
    float              probe_pt;
    float              probe_eta;
    float              probe_eta_sc;
    float              probe_phi;
    Bool_t             probe_isPhoton;
    int                probe_nConvTrk;
    float              m_tagprobe;
    float              m_tagprobe_sceta;

};

#endif
