#include "include/RunAnalysis.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <stdlib.h>

#include "include/BranchDefs.h"
#include "include/BranchInit.h"

#include "Core/Util.h"

#include "TFile.h"

int main(int argc, char **argv)
{

    //TH1::AddDirectory(kFALSE);
    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );
    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "^_^ Finished ^_^" << std::endl;


}

void RunModule::Run( TChain * chain, TTree * outtree, TFile *outfile,
          std::vector<ModuleConfig> & configs, const CmdOptions & options,
          int minevt, int maxevt ) const {

    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );
    
    // *************************
    // Set defaults for added output variables
    // *************************
    OUT::isBlinded = 0;
    OUT::ph_medium_n = 0;
    OUT::el_medium_n = 0;

    // *************************
    // Declare Branches
    // *************************
    outtree->Branch("isBlinded", &OUT::isBlinded );
    outtree->Branch("ph_medium_n", &OUT::ph_medium_n);
    outtree->Branch("el_medium_n", &OUT::el_medium_n);

    // *************************
    // Begin loop over the input tree
    // *************************
    if( maxevt == 0 ) {
        maxevt = chain->GetEntries();
    }

    int n_saved = 0;
    std::cout << "Will analyze " << maxevt-minevt << " events between " << minevt << " and " << maxevt << std::endl;
    for( int cidx = minevt; cidx < maxevt; cidx++ ) {

        if( cidx % 10000 == 0 ) {
          std::cout << "Processed " << cidx << " entries " << std::endl;
        }

        chain->GetEntry(cidx);

        // In BranchInit
        CopyInputVarsToOutput();

        // loop over configured modules
        bool save_event = true;
        BOOST_FOREACH( ModuleConfig & mod_conf, configs ) {
            save_event &= ApplyModule( mod_conf );
        }

        if( save_event ) {
            outtree->Fill();
            n_saved++;
        }
    }

    std::cout << "Wrote " << n_saved << " events" << std::endl;

}

bool RunModule::ApplyModule( ModuleConfig & config ) const {

    // This bool is used for filtering
    // If a module implements an event filter
    // update this variable and return it
    // to apply the filter
    bool keep_evt = true;

    // This part is a bit hacked.  For each module that
    // you write below, you have to put a call to that
    // function with a matching name here.
    // The name is used to match the name used
    // in the python configuration.
    // There are fancy ways to do this, but it
    // would require the code to be much more complicated
    //
    // If the module applies a filter the filter decision
    // is passed back to here.  There is no requirement
    // that a function returns a bool, but
    // if you want the filter to work you need to do this
    //
    // Example :
    if( config.GetName() == "FilterEvent" ) {
        keep_evt &= FilterEvent( config );
    }

    return keep_evt;

}

// ***********************************
//  Define modules here
//  The modules can do basically anything
//  that you want, fill trees, fill plots, 
//  caclulate an event filter
// ***********************************
//
// Examples :

// This is an example of a module that applies an
// event filter.  Note that it returns a bool instead
// of a void.  In principle the modules can return any
// type of variable, you just have to handle it
// in the ApplyModule function

bool RunModule::FilterEvent( ModuleConfig & config ) const {

    bool keep_event = true;

    int nEl_loose  = 0;
    int nEl_medium = 0;
    int nEl_tight  = 0;
    int nMu_tight  = 0;
    int nPh_loose  = 0;
    int nPh_medium = 0;
    int nPh_tight  = 0;

    nMu_tight = IN::mu_n;

    for( int eidx = 0; eidx < IN::el_n; eidx++ ) {

        if( IN::el_passLoose->at(eidx) ) nEl_loose++;
        if( IN::el_passMedium->at(eidx) ) nEl_medium++;
        if( IN::el_passTight->at(eidx) ) nEl_tight++;

    }

    for( int pidx = 0; pidx < IN::ph_n; pidx++ ) {

        if( IN::ph_passLoose->at(pidx) ) nPh_loose++;
        if( IN::ph_passMedium->at(pidx) ) nPh_medium++;
        if( IN::ph_passTight->at(pidx) ) nPh_tight++;

    }

    OUT::ph_medium_n = nPh_medium;
    OUT::el_medium_n = nEl_medium;

    // blind bit
    if( nPh_medium > 1 ) OUT::isBlinded = true;
    else                 OUT::isBlinded = false;

    int nLep_muTight_elMed = nMu_tight + nEl_medium;
   
    if( !config.PassInt( "cut_nLep_muTight_elMed", nLep_muTight_elMed ) ) keep_event=false;
    if( !config.PassInt( "cut_nPh_medium", nPh_medium ) ) keep_event = false;

    return keep_event;
    
}

