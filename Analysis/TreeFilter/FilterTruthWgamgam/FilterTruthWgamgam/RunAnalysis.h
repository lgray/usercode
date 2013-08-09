#ifndef RUNANALYSIS_H
#define RUNANALYSIS_H

#include "Core/AnalysisBase.h"

#include <string>
#include <vector>


#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"

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
bool ApplyModule   ( const ModuleConfig & config );
void BuildLepton     ( const ModuleConfig & config );
//void BuildMuon     ( const ModuleConfig & config );
void BuildPhoton   ( const ModuleConfig & config );
void BuildNeutrino ( const ModuleConfig & config );
void BuildEvent    ( const ModuleConfig & config );

bool FilterElec ( const ModuleConfig & config );
bool FilterMuon ( const ModuleConfig & config );
bool FilterEvent( const ModuleConfig & config );
bool FilterTauEvent( const ModuleConfig & config );
void ConfigOutFile( TFile * file, const std::string & raw_name, TTree * outtree );

float calc_mt( const TLorentzVector & obj, const TLorentzVector & nu );

AnaConfig ParseConfig( const std::string & fname, CmdOptions & options );

namespace OUT {

    Int_t              lep_n;
    Int_t              phot_n;
    Int_t              nu_n;

    std::vector<float>  *lep_pt;
    std::vector<float>  *lep_eta;
    std::vector<float>  *lep_phi;
    std::vector<float>  *lep_e;
    std::vector<int>    *lep_motherPID;
    std::vector<Bool_t> *lep_isElec;
    std::vector<Bool_t> *lep_isMuon;

    std::vector<float>  *phot_pt;
    std::vector<float>  *phot_eta;
    std::vector<float>  *phot_phi;
    std::vector<float>  *phot_e;
    std::vector<int>    *phot_motherPID;

    std::vector<float>  *nu_pt;
    std::vector<float>  *nu_eta;
    std::vector<float>  *nu_phi;
    std::vector<float>  *nu_e;
    std::vector<int>    *nu_motherPID;

    Float_t             leadPhot_pt;
    Float_t             sublPhot_pt;

    Float_t             leadPhot_lepDR;
    Float_t             sublPhot_lepDR;
    Float_t             phot_photDR;

    Float_t             mt_lepnu;
    Float_t             mt_lepphot1nu;
    Float_t             mt_lepphot2nu;
    Float_t             mt_lepphotphotnu;

    Float_t             m_lepnu;
    Float_t             m_lepphot1nu;
    Float_t             m_lepphot2nu;
    Float_t             m_lepphotphotnu;
    Float_t             m_lepphot1;
    Float_t             m_lepphot2;
    Float_t             m_lepphotphot;
    Float_t             m_photphot;

};

#endif
