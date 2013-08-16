#ifndef BRANCHDEFS_H
#define BRANCHDEFS_H
#include "TTree.h"
#include <vector>
//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions
namespace IN {
 extern Int_t				nMC;
 extern Int_t				mcPID[63];
 extern Float_t				mcVtx[63][3];
 extern Float_t				mcPt[63];
 extern Float_t				mcMass[63];
 extern Float_t				mcEta[63];
 extern Float_t				mcPhi[63];
 extern Float_t				mcE[63];
 extern Float_t				mcEt[63];
 extern Int_t				mcGMomPID[63];
 extern Int_t				mcMomPID[63];
 extern Float_t				mcMomPt[63];
 extern Float_t				mcMomMass[63];
 extern Float_t				mcMomEta[63];
 extern Float_t				mcMomPhi[63];
 extern Int_t				mcIndex[63];
 extern Int_t				mcDecayType[63];
 extern Int_t				mcParentage[63];
 extern Int_t				mcStatus[63];
};
namespace OUT {
 extern Int_t				nMC;
 extern Int_t				mcPID[63];
 extern Float_t				mcVtx[63][3];
 extern Float_t				mcPt[63];
 extern Float_t				mcMass[63];
 extern Float_t				mcEta[63];
 extern Float_t				mcPhi[63];
 extern Float_t				mcE[63];
 extern Float_t				mcEt[63];
 extern Int_t				mcGMomPID[63];
 extern Int_t				mcMomPID[63];
 extern Float_t				mcMomPt[63];
 extern Float_t				mcMomMass[63];
 extern Float_t				mcMomEta[63];
 extern Float_t				mcMomPhi[63];
 extern Int_t				mcIndex[63];
 extern Int_t				mcDecayType[63];
 extern Int_t				mcParentage[63];
 extern Int_t				mcStatus[63];
};
#endif
