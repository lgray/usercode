#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>


#include "TTree.h"
#include "TChain.h"

struct CmdOptions {

  CmdOptions();

  std::string config_file;
  std::string treeName;
  std::string output;
  std::vector<std::string> files;
  int nevt;

};

CmdOptions ParseOptions(int, char**);

void Run( TChain * chain, TTree *outtree, const AnaConfig & config, const CmdOptions & options);
void ConfigOutFile( TFile * file, const std::string & raw_name, TTree * outtree );

AnaConfig ParseConfig( const std::string & fname, CmdOptions & options );

#endif
