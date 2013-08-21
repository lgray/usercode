#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>


#include "TTree.h"
#include "TChain.h"

class RunModule : public virtual RunModuleBase {

    public :

        RunModule() {}

        void Run( TChain * chain, TTree *outtree, std::vector<ModuleConfig> & config, const CmdOptions & options, int minevt=0, int maxevt=0) const;

        bool ApplyModule( ModuleConfig & config ) const;
        void BuildElec  ( ModuleConfig & config ) const;
        bool FilterElec ( ModuleConfig & config ) const;
        bool FilterMuon ( ModuleConfig & config ) const;
        bool FilterJet  ( ModuleConfig & config ) const;
        bool FilterEvent( ModuleConfig & config ) const;

};

//void Run( TChain * chain, TTree *outtree, const AnaConfig & config, const CmdOptions & options, int minevt=0, int maxevt=0);

#endif
