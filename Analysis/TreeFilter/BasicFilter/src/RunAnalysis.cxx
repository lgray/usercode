#include "include/RunAnalysis.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

#include "include/BranchDefs.h"
#include "include/BranchInit.h"

#include "TFile.h"

int main(int argc, char **argv)
{

    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^.^ Finished ^.^" << std::endl;

}

void RunModule::Run( TChain * chain, TTree * outtree, TFile * outfile,
          std::vector<ModuleConfig> & configs, const CmdOptions & options,
          int minevt, int maxevt ) const {

    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    // *************************
    // Begin loop over the input tree
    // *************************
    if( maxevt == 0 ) {
        maxevt = chain->GetEntries();
    }

    int n_saved = 0;
    std::cout << "Will analyze " << maxevt << " events " << std::endl;
    for( int cidx = minevt; cidx < maxevt; cidx++ ) {

        if( cidx % 10000 == 0 ) {
          //std::cout << "Processed " << cidx << " entries \xd";
          std::cout << "Processed " << cidx << " entries " << std::endl;
        }

        chain->GetEntry(cidx);

        // In BranchInit
        CopyInputVarsToOutput();

        outtree->Fill();
        n_saved++;
    }

    std::cout << "Wrote " << n_saved << " events" << std::endl;

}
