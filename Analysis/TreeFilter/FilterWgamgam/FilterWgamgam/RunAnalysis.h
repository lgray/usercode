#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>


#include "TTree.h"
#include "TChain.h"


void Run( TChain * chain, TTree *outtree, const AnaConfig & config, const CmdOptions & options, int minevt=0, int maxevt=0);
bool ApplyModule( const ModuleConfig & config );
void BuildElec  ( const ModuleConfig & config );
bool FilterElec ( const ModuleConfig & config );
bool FilterMuon ( const ModuleConfig & config );
bool FilterJet  ( const ModuleConfig & config );
bool FilterEvent( const ModuleConfig & config );
void ConfigOutFile( TFile * file, const std::string & raw_name, TTree * outtree );


#endif
