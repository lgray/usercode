#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>


#include "TTree.h"
#include "TChain.h"

class RunModule : public virtual RunModuleBase {

    public :

        RunModule() {}

        void Run( TChain * chain, TTree *outtree, const std::vector<ModuleConfig> & config, const CmdOptions & options, int minevt=0, int maxevt=0) const;

        bool ApplyModule( const ModuleConfig & config ) const;
        void BuildElec  ( const ModuleConfig & config ) const;
        bool FilterElec ( const ModuleConfig & config ) const;
        bool FilterMuon ( const ModuleConfig & config ) const;
        bool FilterJet  ( const ModuleConfig & config ) const;
        bool FilterEvent( const ModuleConfig & config ) const;

};

//void Run( TChain * chain, TTree *outtree, const AnaConfig & config, const CmdOptions & options, int minevt=0, int maxevt=0);

#endif
