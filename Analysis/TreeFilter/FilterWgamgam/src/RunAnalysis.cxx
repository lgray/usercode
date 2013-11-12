#include "include/RunAnalysis.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>


#include "include/BranchDefs.h"
#include "include/BranchInit.h"

#include "TFile.h"
#include "TH1.h"

int main(int argc, char **argv)
{

    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file, options );

    std::cout << "Configured " << ana_config.size() << " analysis modules " << std::endl;

    RunModule runmod;
    ana_config.Run(runmod, options);

    std::cout << "Finished ^.^" << std::endl;

}

void RunModule::Run( TChain * chain, TTree * outtree, TFile *outfile,
                     std::vector<ModuleConfig> & mod_configs, const CmdOptions & options,
                     int minevt, int maxevt ) const {
    // *************************
    // initialize trees
    // *************************
    InitINTree(chain);
    InitOUTTree( outtree );

    outfile->cd();
    TH1F * hfilter = new TH1F("filter", "filter", 2, 0, 2);
    hfilter->GetXaxis()->SetBinLabel(1, "Total");
    hfilter->GetXaxis()->SetBinLabel(2, "Filter");

    // *************************
    // Declare output branches here
    // *************************
    

    // *************************
    // Begin loop over the input tree
    // *************************
    if( options.nevt > 0 ) {
        maxevt = options.nevt;
    }
    if( maxevt == 0 ) {
        maxevt = chain->GetEntries();
    }

    int n_saved = 0;
    std::cout << "Will analyze " << maxevt-minevt << " events between " << minevt << " and " << maxevt << std::endl;
    for( int cidx = minevt; cidx < maxevt; cidx++ ) {

        if( cidx % 1000 == 0 ) {
          //std::cout << "Processed " << cidx << " entries \xd";
          std::cout << "Processed " << cidx << " entries " << std::endl;
        }

        chain->GetEntry(cidx);

        // In BranchInit
        CopyInputVarsToOutput();


        // loop over configured modules
        bool save_event = true;
        BOOST_FOREACH( ModuleConfig & mod_conf, mod_configs ) {
            save_event &= ApplyModule( mod_conf );
        }

        hfilter->Fill(0);
        if( save_event ) {
            outtree->Fill();
            hfilter->Fill(1);
            n_saved++;
        }
    }

    hfilter->Write();
    std::cout << "Wrote " << n_saved << " events" << std::endl;

}

bool RunModule::ApplyModule( ModuleConfig & config ) const {

    bool keep_evt = true;
    
    if( config.GetName() == "FilterElec" ) {
        keep_evt &= FilterElec( config );
    }
    if( config.GetName() == "FilterMuon" ) {
        keep_evt &= FilterMuon( config );
    }
    if( config.GetName() == "FilterJet" ) {
        keep_evt &= FilterJet( config );
    }
    if( config.GetName() == "FilterEvent" ) {
        keep_evt &= FilterEvent( config );
    }
    if( config.GetName() == "FilterTrigger" ) {
        keep_evt &= FilterTrigger( config );
    }

    return keep_evt;

}

bool RunModule::FilterElec( ModuleConfig & config ) const {

    // NOTE this assumes that the jets are 
    // sorted in descending order

    int nElOut = 0;
    for( int idx = 0; idx < IN::nEle; ++idx ) {
        
        float elePt = IN::elePt[idx];

        if( !config.PassFloat( "cut_pt", elePt ) ) continue;

        nElOut++;
    }

    OUT::nEle = nElOut;

    return true;
}     

bool RunModule::FilterJet( ModuleConfig & config ) const {

    // NOTE this assumes that the jets are 
    // sorted in descending order

    int nJetOut = 0;
    for( int idx = 0; idx < IN::nJet; ++idx ) {
        
        float jetPt = IN::jetPt[idx];

        if( !config.PassFloat( "cut_pt", jetPt ) ) continue;

        nJetOut++;
    }

    OUT::nJet = nJetOut;

    return true;
}     

bool RunModule::FilterMuon( ModuleConfig & config ) const {

    // NOTE this assumes that the jets are 
    // sorted in descending order

    int nMuOut = 0;
    for( int idx = 0; idx < IN::nMu; ++idx ) {
        
        float muPt = IN::muPt[idx];

        if( !config.PassFloat( "cut_pt", muPt ) ) continue;

        nMuOut++;
    }

    OUT::nMu = nMuOut;

    return true;
}     

bool RunModule::FilterEvent( ModuleConfig & config ) const {

    int nMu = OUT::nMu;
    int nEl = OUT::nEle;
    int nPho = OUT::nPho;
    int nLep = nMu + nEl;
    int nLepPho = nLep + nPho;

    bool keep_evt = true;

    if( !config.PassInt( "cut_nEl", nEl ) ) keep_evt = false;
    if( !config.PassInt( "cut_nMu", nMu ) ) keep_evt = false;
    if( !config.PassInt( "cut_nPho", nPho ) ) keep_evt = false;
    if( !config.PassInt( "cut_nLep", nLep ) ) keep_evt = false;
    if( !config.PassInt( "cut_nLepPho", nLepPho ) ) keep_evt = false;

    return keep_evt;

}     

bool RunModule::FilterTrigger( ModuleConfig & config ) const {
    
    bool keep_evt = false;
    BOOST_FOREACH( const Cut & cut, config.GetCut("cut_trigger").GetCuts() ) {
       if( IN::HLT[IN::HLTIndex[cut.val_int] ] > 0 ) keep_evt = true;
    }

    return keep_evt;
}



    

    
