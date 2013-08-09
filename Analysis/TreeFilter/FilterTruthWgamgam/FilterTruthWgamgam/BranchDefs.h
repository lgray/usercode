#ifndef BRANCHDEFS_H
#define BRANCHDEFS_H
#include "TTree.h"
#include <vector>
//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions
namespace IN {
 extern Int_t				nMC;
 extern Int_t				mcPID[61];
 extern Float_t				mcVtx[61][3];
 extern Float_t				mcPt[61];
 extern Float_t				mcMass[61];
 extern Float_t				mcEta[61];
 extern Float_t				mcPhi[61];
 extern Float_t				mcE[61];
 extern Float_t				mcEt[61];
 extern Int_t				mcGMomPID[61];
 extern Int_t				mcMomPID[61];
 extern Float_t				mcMomPt[61];
 extern Float_t				mcMomMass[61];
 extern Float_t				mcMomEta[61];
 extern Float_t				mcMomPhi[61];
 extern Int_t				mcIndex[61];
 extern Int_t				mcDecayType[61];
 extern Int_t				mcParentage[61];
 extern Int_t				mcStatus[61];
 extern Int_t				lep_n;
 extern Int_t				phot_n;
 extern Int_t				nu_n;
 extern std::vector<float>				*lep_pt;
 extern std::vector<float>				*lep_eta;
 extern std::vector<float>				*lep_phi;
 extern std::vector<float>				*lep_e;
 extern std::vector<int>				*lep_motherPID;
 extern std::vector<bool>				*lep_isElec;
 extern std::vector<bool>				*lep_isMuon;
 extern std::vector<float>				*phot_pt;
 extern std::vector<float>				*phot_eta;
 extern std::vector<float>				*phot_phi;
 extern std::vector<float>				*phot_e;
 extern std::vector<int>				*phot_motherPID;
 extern std::vector<float>				*nu_pt;
 extern std::vector<float>				*nu_eta;
 extern std::vector<float>				*nu_phi;
 extern std::vector<float>				*nu_e;
 extern std::vector<int>				*nu_motherPID;
 extern Float_t				leadPhot_pt;
 extern Float_t				sublPhot_pt;
 extern Float_t				leadPhot_lepDR;
 extern Float_t				sublPhot_lepDR;
 extern Float_t				mt_lepnu;
 extern Float_t				mt_lepphot1nu;
 extern Float_t				mt_lepphot2nu;
 extern Float_t				mt_lepphotphotnu;
 extern Float_t				m_lepnu;
 extern Float_t				m_lepphot1nu;
 extern Float_t				m_lepphot2nu;
 extern Float_t				m_lepphotphotnu;
 extern Float_t				m_lepphot1;
 extern Float_t				m_lepphot2;
 extern Float_t				m_lepphotphot;
 extern Float_t				m_photphot;
};
namespace OUT {
};
#endif
