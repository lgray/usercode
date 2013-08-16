#include <algorithm>
#include <iostream>
#include "TTree.h"
#include "TChain.h"
#include "/afs/cern.ch/user/j/jkunkle/usercode/Analysis/TreeFilter/FilterTruthWgamgam/FilterTruthWgamgam/BranchInit.h"
#include "/afs/cern.ch/user/j/jkunkle/usercode/Analysis/TreeFilter/FilterTruthWgamgam/FilterTruthWgamgam/BranchDefs.h"

namespace IN {
 Int_t				nMC;
 Int_t				mcPID[63];
 Float_t				mcVtx[63][3];
 Float_t				mcPt[63];
 Float_t				mcMass[63];
 Float_t				mcEta[63];
 Float_t				mcPhi[63];
 Float_t				mcE[63];
 Float_t				mcEt[63];
 Int_t				mcGMomPID[63];
 Int_t				mcMomPID[63];
 Float_t				mcMomPt[63];
 Float_t				mcMomMass[63];
 Float_t				mcMomEta[63];
 Float_t				mcMomPhi[63];
 Int_t				mcIndex[63];
 Int_t				mcDecayType[63];
 Int_t				mcParentage[63];
 Int_t				mcStatus[63];
};
namespace OUT {
 Int_t				nMC;
 Int_t				mcPID[63];
 Float_t				mcVtx[63][3];
 Float_t				mcPt[63];
 Float_t				mcMass[63];
 Float_t				mcEta[63];
 Float_t				mcPhi[63];
 Float_t				mcE[63];
 Float_t				mcEt[63];
 Int_t				mcGMomPID[63];
 Int_t				mcMomPID[63];
 Float_t				mcMomPt[63];
 Float_t				mcMomMass[63];
 Float_t				mcMomEta[63];
 Float_t				mcMomPhi[63];
 Int_t				mcIndex[63];
 Int_t				mcDecayType[63];
 Int_t				mcParentage[63];
 Int_t				mcStatus[63];
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
};

void InitOUTTree( TTree * tree ) {
  tree->Branch("nMC", &OUT::nMC, "nMC/I");
  tree->Branch("mcPID", &OUT::mcPID, "mcPID[nMC]/I");
  tree->Branch("mcVtx", &OUT::mcVtx, "mcVtx[nMC][3]/F");
  tree->Branch("mcPt", &OUT::mcPt, "mcPt[nMC]/F");
  tree->Branch("mcMass", &OUT::mcMass, "mcMass[nMC]/F");
  tree->Branch("mcEta", &OUT::mcEta, "mcEta[nMC]/F");
  tree->Branch("mcPhi", &OUT::mcPhi, "mcPhi[nMC]/F");
  tree->Branch("mcE", &OUT::mcE, "mcE[nMC]/F");
  tree->Branch("mcEt", &OUT::mcEt, "mcEt[nMC]/F");
  tree->Branch("mcGMomPID", &OUT::mcGMomPID, "mcGMomPID[nMC]/I");
  tree->Branch("mcMomPID", &OUT::mcMomPID, "mcMomPID[nMC]/I");
  tree->Branch("mcMomPt", &OUT::mcMomPt, "mcMomPt[nMC]/F");
  tree->Branch("mcMomMass", &OUT::mcMomMass, "mcMomMass[nMC]/F");
  tree->Branch("mcMomEta", &OUT::mcMomEta, "mcMomEta[nMC]/F");
  tree->Branch("mcMomPhi", &OUT::mcMomPhi, "mcMomPhi[nMC]/F");
  tree->Branch("mcIndex", &OUT::mcIndex, "mcIndex[nMC]/I");
  tree->Branch("mcDecayType", &OUT::mcDecayType, "mcDecayType[nMC]/I");
  tree->Branch("mcParentage", &OUT::mcParentage, "mcParentage[nMC]/I");
  tree->Branch("mcStatus", &OUT::mcStatus, "mcStatus[nMC]/I");
}
void CopyInputVarsToOutput() {
  OUT::nMC = IN::nMC;
  std::copy(IN::mcPID, IN::mcPID+63, OUT::mcPID);
   std::copy(IN::mcVtx, IN::mcVtx+189, OUT::mcVtx);
   std::copy(IN::mcPt, IN::mcPt+63, OUT::mcPt);
   std::copy(IN::mcMass, IN::mcMass+63, OUT::mcMass);
   std::copy(IN::mcEta, IN::mcEta+63, OUT::mcEta);
   std::copy(IN::mcPhi, IN::mcPhi+63, OUT::mcPhi);
   std::copy(IN::mcE, IN::mcE+63, OUT::mcE);
   std::copy(IN::mcEt, IN::mcEt+63, OUT::mcEt);
   std::copy(IN::mcGMomPID, IN::mcGMomPID+63, OUT::mcGMomPID);
   std::copy(IN::mcMomPID, IN::mcMomPID+63, OUT::mcMomPID);
   std::copy(IN::mcMomPt, IN::mcMomPt+63, OUT::mcMomPt);
   std::copy(IN::mcMomMass, IN::mcMomMass+63, OUT::mcMomMass);
   std::copy(IN::mcMomEta, IN::mcMomEta+63, OUT::mcMomEta);
   std::copy(IN::mcMomPhi, IN::mcMomPhi+63, OUT::mcMomPhi);
   std::copy(IN::mcIndex, IN::mcIndex+63, OUT::mcIndex);
   std::copy(IN::mcDecayType, IN::mcDecayType+63, OUT::mcDecayType);
   std::copy(IN::mcParentage, IN::mcParentage+63, OUT::mcParentage);
   std::copy(IN::mcStatus, IN::mcStatus+63, OUT::mcStatus);
 }
