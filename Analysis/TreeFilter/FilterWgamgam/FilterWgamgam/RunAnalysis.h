#include "AnalysisBase.h"

#include "BranchDefs.h"
#include "BranchInit.icc"

struct CmdOptions {

  CmdOptions();

  std::string conf_file;

};

CmdOptions ParseOptions(int, char**);

void ApplyModule( const ModuleConfig & config );
void FilterElec( const ModuleConfig & config );

AnaConfig ParseConfig( const std::string & fname );

