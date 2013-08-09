#include <algorithm>
#include <iostream>
#include "TTree.h"
#include "TChain.h"
#include "FilterTruthWgamgam/BranchInit.h"
#include "FilterTruthWgamgam/BranchDefs.h"

namespace IN {
 Int_t				nMC;
 Int_t				mcPID[61];
 Float_t				mcVtx[61][3];
 Float_t				mcPt[61];
 Float_t				mcMass[61];
 Float_t				mcEta[61];
 Float_t				mcPhi[61];
 Float_t				mcE[61];
 Float_t				mcEt[61];
 Int_t				mcGMomPID[61];
 Int_t				mcMomPID[61];
 Float_t				mcMomPt[61];
 Float_t				mcMomMass[61];
 Float_t				mcMomEta[61];
 Float_t				mcMomPhi[61];
 Int_t				mcIndex[61];
 Int_t				mcDecayType[61];
 Int_t				mcParentage[61];
 Int_t				mcStatus[61];
 Int_t				lep_n;
 Int_t				phot_n;
 Int_t				nu_n;
 std::vector<float>				*lep_pt;
 std::vector<float>				*lep_eta;
 std::vector<float>				*lep_phi;
 std::vector<float>				*lep_e;
 std::vector<int>				*lep_motherPID;
 std::vector<bool>				*lep_isElec;
 std::vector<bool>				*lep_isMuon;
 std::vector<float>				*phot_pt;
 std::vector<float>				*phot_eta;
 std::vector<float>				*phot_phi;
 std::vector<float>				*phot_e;
 std::vector<int>				*phot_motherPID;
 std::vector<float>				*nu_pt;
 std::vector<float>				*nu_eta;
 std::vector<float>				*nu_phi;
 std::vector<float>				*nu_e;
 std::vector<int>				*nu_motherPID;
 Float_t				leadPhot_pt;
 Float_t				sublPhot_pt;
 Float_t				leadPhot_lepDR;
 Float_t				sublPhot_lepDR;
 Float_t				mt_lepnu;
 Float_t				mt_lepphot1nu;
 Float_t				mt_lepphot2nu;
 Float_t				mt_lepphotphotnu;
 Float_t				m_lepnu;
 Float_t				m_lepphot1nu;
 Float_t				m_lepphot2nu;
 Float_t				m_lepphotphotnu;
 Float_t				m_lepphot1;
 Float_t				m_lepphot2;
 Float_t				m_lepphotphot;
 Float_t				m_photphot;
};
namespace OUT {
};
void InitINTree( TChain * tree) {

  tree->SetBranchAddress("nMC", &IN::nMC);
  tree->SetBranchAddress("mcPID", &IN::mcPID);
  tree->SetBranchAddress("mcVtx", &IN::mcVtx);
  tree->SetBranchAddress("mcPt", &IN::mcPt);
  tree->SetBranchAddress("mcMass", &IN::mcMass);
  tree->SetBranchAddress("mcEta", &IN::mcEta);
  tree->SetBranchAddress("mcPhi", &IN::mcPhi);
  tree->SetBranchAddress("mcE", &IN::mcE);
  tree->SetBranchAddress("mcEt", &IN::mcEt);
  tree->SetBranchAddress("mcGMomPID", &IN::mcGMomPID);
  tree->SetBranchAddress("mcMomPID", &IN::mcMomPID);
  tree->SetBranchAddress("mcMomPt", &IN::mcMomPt);
  tree->SetBranchAddress("mcMomMass", &IN::mcMomMass);
  tree->SetBranchAddress("mcMomEta", &IN::mcMomEta);
  tree->SetBranchAddress("mcMomPhi", &IN::mcMomPhi);
  tree->SetBranchAddress("mcIndex", &IN::mcIndex);
  tree->SetBranchAddress("mcDecayType", &IN::mcDecayType);
  tree->SetBranchAddress("mcParentage", &IN::mcParentage);
  tree->SetBranchAddress("mcStatus", &IN::mcStatus);
  tree->SetBranchAddress("lep_n", &IN::lep_n);
  tree->SetBranchAddress("phot_n", &IN::phot_n);
  tree->SetBranchAddress("nu_n", &IN::nu_n);
  tree->SetBranchAddress("lep_pt", &IN::lep_pt);
  tree->SetBranchAddress("lep_eta", &IN::lep_eta);
  tree->SetBranchAddress("lep_phi", &IN::lep_phi);
  tree->SetBranchAddress("lep_e", &IN::lep_e);
  tree->SetBranchAddress("lep_motherPID", &IN::lep_motherPID);
  tree->SetBranchAddress("lep_isElec", &IN::lep_isElec);
  tree->SetBranchAddress("lep_isMuon", &IN::lep_isMuon);
  tree->SetBranchAddress("phot_pt", &IN::phot_pt);
  tree->SetBranchAddress("phot_eta", &IN::phot_eta);
  tree->SetBranchAddress("phot_phi", &IN::phot_phi);
  tree->SetBranchAddress("phot_e", &IN::phot_e);
  tree->SetBranchAddress("phot_motherPID", &IN::phot_motherPID);
  tree->SetBranchAddress("nu_pt", &IN::nu_pt);
  tree->SetBranchAddress("nu_eta", &IN::nu_eta);
  tree->SetBranchAddress("nu_phi", &IN::nu_phi);
  tree->SetBranchAddress("nu_e", &IN::nu_e);
  tree->SetBranchAddress("nu_motherPID", &IN::nu_motherPID);
  tree->SetBranchAddress("leadPhot_pt", &IN::leadPhot_pt);
  tree->SetBranchAddress("sublPhot_pt", &IN::sublPhot_pt);
  tree->SetBranchAddress("leadPhot_lepDR", &IN::leadPhot_lepDR);
  tree->SetBranchAddress("sublPhot_lepDR", &IN::sublPhot_lepDR);
  tree->SetBranchAddress("mt_lepnu", &IN::mt_lepnu);
  tree->SetBranchAddress("mt_lepphot1nu", &IN::mt_lepphot1nu);
  tree->SetBranchAddress("mt_lepphot2nu", &IN::mt_lepphot2nu);
  tree->SetBranchAddress("mt_lepphotphotnu", &IN::mt_lepphotphotnu);
  tree->SetBranchAddress("m_lepnu", &IN::m_lepnu);
  tree->SetBranchAddress("m_lepphot1nu", &IN::m_lepphot1nu);
  tree->SetBranchAddress("m_lepphot2nu", &IN::m_lepphot2nu);
  tree->SetBranchAddress("m_lepphotphotnu", &IN::m_lepphotphotnu);
  tree->SetBranchAddress("m_lepphot1", &IN::m_lepphot1);
  tree->SetBranchAddress("m_lepphot2", &IN::m_lepphot2);
  tree->SetBranchAddress("m_lepphotphot", &IN::m_lepphotphot);
  tree->SetBranchAddress("m_photphot", &IN::m_photphot);
};

void InitOUTTree( TTree * tree ) {
}
void CopyInputVarsToOutput() {
}
