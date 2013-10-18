#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>


#include "TTree.h"
#include "TChain.h"

class RunModule : public virtual RunModuleBase {

    public :

        RunModule() {}

        void Run( TChain * chain, TTree *outtree, TFile *outfile, std::vector<ModuleConfig> & config, const CmdOptions & options, int minevt=0, int maxevt=0) const;

};

#endif
