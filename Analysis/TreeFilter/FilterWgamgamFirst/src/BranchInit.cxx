#include <algorithm>
#include <iostream>
#include "TTree.h"
#include "TChain.h"
#include "include/BranchInit.h"
#include "include/BranchDefs.h"

namespace IN {
 Int_t				nHLT;
 Int_t				run;
 Long64_t				event;
 Int_t				lumis;
 Bool_t				isData;
 Int_t				HLT[453];
 Int_t				HLTIndex[70];
 Float_t				bspotPos[3];
 Int_t				nVtx;
 std::vector<float>				*vtx_x;
 std::vector<float>				*vtx_y;
 std::vector<float>				*vtx_z;
 Int_t				IsVtxGood;
 Int_t				nGoodVtx;
 Int_t				nVtxBS;
 std::vector<float>				*vtxbs_x;
 std::vector<float>				*vtxbs_y;
 std::vector<float>				*vtxbs_z;
 Float_t				pfMET;
 Float_t				pfMETPhi;
 Float_t				pfMETsumEt;
 Float_t				pfMETmEtSig;
 Float_t				pfMETSig;
 Float_t				pfType01MET;
 Float_t				pfType01METPhi;
 Float_t				pfType01METsumEt;
 Float_t				pfType01METmEtSig;
 Float_t				pfType01METSig;
 Float_t				recoPfMET;
 Float_t				recoPfMETPhi;
 Float_t				recoPfMETsumEt;
 Float_t				recoPfMETmEtSig;
 Float_t				recoPfMETSig;
 Float_t				trkMETxPV;
 Float_t				trkMETyPV;
 Float_t				trkMETPhiPV;
 Float_t				trkMETPV;
 std::vector<float>				*trkMETx;
 std::vector<float>				*trkMETy;
 std::vector<float>				*trkMETPhi;
 std::vector<float>				*trkMET;
 Int_t				metFilters[10];
 Int_t				nEle;
 std::vector<unsigned long>				*eleTrg;
 std::vector<int>				*eleClass;
 std::vector<int>				*eleIsEcalDriven;
 std::vector<int>				*eleCharge;
 std::vector<int>				*eleChargeConsistent;
 std::vector<float>				*eleEn;
 std::vector<float>				*eleEcalEn;
 std::vector<float>				*eleSCRawEn;
 std::vector<float>				*eleSCEn;
 std::vector<float>				*eleESEn;
 std::vector<float>				*elePt;
 std::vector<float>				*eleEta;
 std::vector<float>				*elePhi;
 std::vector<float>				*eleR9;
 std::vector<std::vector<float> >				*eleEtaVtx;
 std::vector<std::vector<float> >				*elePhiVtx;
 std::vector<std::vector<float> >				*eleEtVtx;
 std::vector<float>				*eleSCEta;
 std::vector<float>				*eleSCPhi;
 std::vector<float>				*eleSCEtaWidth;
 std::vector<float>				*eleSCPhiWidth;
 std::vector<float>				*eleVtx_x;
 std::vector<float>				*eleVtx_y;
 std::vector<float>				*eleVtx_z;
 std::vector<float>				*eleD0;
 std::vector<float>				*eleDz;
 std::vector<float>				*eleD0GV;
 std::vector<float>				*eleDzGV;
 std::vector<std::vector<float> >				*eleD0Vtx;
 std::vector<std::vector<float> >				*eleDzVtx;
 std::vector<float>				*eleHoverE;
 std::vector<float>				*eleHoverE12;
 std::vector<float>				*eleEoverP;
 std::vector<float>				*elePin;
 std::vector<float>				*elePout;
 std::vector<float>				*eleTrkMomErr;
 std::vector<float>				*eleBrem;
 std::vector<float>				*eledEtaAtVtx;
 std::vector<float>				*eledPhiAtVtx;
 std::vector<float>				*eleSigmaIEtaIEta;
 std::vector<float>				*eleSigmaIEtaIPhi;
 std::vector<float>				*eleSigmaIPhiIPhi;
 std::vector<float>				*eleEmax;
 std::vector<float>				*eleE2ndMax;
 std::vector<float>				*eleETop;
 std::vector<float>				*eleEBottom;
 std::vector<float>				*eleELeft;
 std::vector<float>				*eleERight;
 std::vector<float>				*eleE1x5;
 std::vector<float>				*eleE3x3;
 std::vector<float>				*eleE5x5;
 std::vector<float>				*eleE2x5Max;
 std::vector<float>				*eleE2x5Top;
 std::vector<float>				*eleE2x5Bottom;
 std::vector<float>				*eleE2x5Left;
 std::vector<float>				*eleE2x5Right;
 std::vector<float>				*eleSeedEta;
 std::vector<float>				*eleSeedE;
 std::vector<float>				*eleSeedPhi;
 std::vector<float>				*eleCrysEta;
 std::vector<float>				*eleCrysPhi;
 std::vector<int>				*eleCrysIEta;
 std::vector<int>				*eleCrysIPhi;
 std::vector<float>				*eleRegrE;
 std::vector<float>				*eleRegrEerr;
 std::vector<float>				*elePhoRegrE;
 std::vector<float>				*elePhoRegrEerr;
 std::vector<float>				*eleSeedTime;
 std::vector<int>				*eleRecoFlag;
 std::vector<int>				*elePos;
 std::vector<float>				*eleIsoTrkDR03;
 std::vector<float>				*eleIsoEcalDR03;
 std::vector<float>				*eleIsoHcalDR03;
 std::vector<float>				*eleIsoHcalDR0312;
 std::vector<float>				*eleIsoTrkDR04;
 std::vector<float>				*eleIsoEcalDR04;
 std::vector<float>				*eleIsoHcalDR04;
 std::vector<float>				*eleIsoHcalDR0412;
 std::vector<float>				*eleModIsoTrk;
 std::vector<float>				*eleModIsoEcal;
 std::vector<float>				*eleModIsoHcal;
 std::vector<int>				*eleMissHits;
 std::vector<float>				*eleConvDist;
 std::vector<float>				*eleConvDcot;
 std::vector<int>				*eleConvVtxFit;
 std::vector<float>				*eleIP3D;
 std::vector<float>				*eleIP3DErr;
 std::vector<float>				*eleIDMVANonTrig;
 std::vector<float>				*eleIDMVATrig;
 std::vector<float>				*elePFChIso03;
 std::vector<float>				*elePFPhoIso03;
 std::vector<float>				*elePFNeuIso03;
 std::vector<float>				*elePFChIso04;
 std::vector<float>				*elePFPhoIso04;
 std::vector<float>				*elePFNeuIso04;
 std::vector<float>				*eleESEffSigmaRR_x;
 std::vector<float>				*eleESEffSigmaRR_y;
 std::vector<float>				*eleESEffSigmaRR_z;
 Int_t				nPho;
 std::vector<unsigned long>				*phoTrg;
 std::vector<unsigned long>				*phoTrgFilter;
 std::vector<bool>				*phoIsPhoton;
 std::vector<float>				*phoSCPos_x;
 std::vector<float>				*phoSCPos_y;
 std::vector<float>				*phoSCPos_z;
 std::vector<float>				*phoCaloPos_x;
 std::vector<float>				*phoCaloPos_y;
 std::vector<float>				*phoCaloPos_z;
 std::vector<float>				*phoE;
 std::vector<float>				*phoEt;
 std::vector<float>				*phoEta;
 std::vector<float>				*phoVtx_x;
 std::vector<float>				*phoVtx_y;
 std::vector<float>				*phoVtx_z;
 std::vector<float>				*phoPhi;
 std::vector<std::vector<float> >				*phoEtVtx;
 std::vector<std::vector<float> >				*phoEtaVtx;
 std::vector<std::vector<float> >				*phoPhiVtx;
 std::vector<float>				*phoR9;
 std::vector<int>				*phoNClus;
 std::vector<float>				*phoTrkIsoHollowDR03;
 std::vector<float>				*phoEcalIsoDR03;
 std::vector<float>				*phoHcalIsoDR03;
 std::vector<float>				*phoHcalIsoDR0312;
 std::vector<float>				*phoTrkIsoHollowDR04;
 std::vector<float>				*phoCiCdRtoTrk;
 std::vector<float>				*phoEcalIsoDR04;
 std::vector<float>				*phoHcalIsoDR04;
 std::vector<float>				*phoHcalIsoDR0412;
 std::vector<float>				*phoHoverE;
 std::vector<float>				*phoHoverE12;
 std::vector<int>				*phoEleVeto;
 std::vector<float>				*phoSigmaIEtaIEta;
 std::vector<float>				*phoSigmaIEtaIPhi;
 std::vector<float>				*phoSigmaIPhiIPhi;
 std::vector<float>				*phoCiCPF4phopfIso03;
 std::vector<float>				*phoCiCPF4phopfIso04;
 std::vector<std::vector<float> >				*phoCiCPF4chgpfIso02;
 std::vector<std::vector<float> >				*phoCiCPF4chgpfIso03;
 std::vector<std::vector<float> >				*phoCiCPF4chgpfIso04;
 std::vector<float>				*phoEmax;
 std::vector<float>				*phoETop;
 std::vector<float>				*phoEBottom;
 std::vector<float>				*phoELeft;
 std::vector<float>				*phoERight;
 std::vector<float>				*phoE2ndMax;
 std::vector<float>				*phoE3x3;
 std::vector<float>				*phoE3x1;
 std::vector<float>				*phoE1x3;
 std::vector<float>				*phoE5x5;
 std::vector<float>				*phoE1x5;
 std::vector<float>				*phoE2x2;
 std::vector<float>				*phoE2x5Max;
 std::vector<float>				*phoE2x5Top;
 std::vector<float>				*phoE2x5Bottom;
 std::vector<float>				*phoE2x5Left;
 std::vector<float>				*phoE2x5Right;
 std::vector<float>				*phoSeedE;
 std::vector<float>				*phoSeedEta;
 std::vector<float>				*phoSeedPhi;
 std::vector<float>				*phoCrysEta;
 std::vector<float>				*phoCrysPhi;
 std::vector<int>				*phoCrysIEta;
 std::vector<int>				*phoCrysIPhi;
 std::vector<float>				*phoPFChIso;
 std::vector<float>				*phoPFPhoIso;
 std::vector<float>				*phoPFNeuIso;
 std::vector<float>				*phoSCRChIso;
 std::vector<float>				*phoSCRPhoIso;
 std::vector<float>				*phoSCRNeuIso;
 std::vector<float>				*phoSCRChIso04;
 std::vector<float>				*phoSCRPhoIso04;
 std::vector<float>				*phoSCRNeuIso04;
 std::vector<float>				*phoRandConeChIso;
 std::vector<float>				*phoRandConePhoIso;
 std::vector<float>				*phoRandConeNeuIso;
 std::vector<float>				*phoRandConeChIso04;
 std::vector<float>				*phoRandConePhoIso04;
 std::vector<float>				*phoRandConeNeuIso04;
 std::vector<float>				*phoRegrE;
 std::vector<float>				*phoRegrEerr;
 std::vector<float>				*phoSeedTime;
 std::vector<int>				*phoSeedDetId1;
 std::vector<int>				*phoSeedDetId2;
 std::vector<float>				*phoLICTD;
 std::vector<int>				*phoRecoFlag;
 std::vector<int>				*phoPos;
 std::vector<float>				*phoSCE;
 std::vector<float>				*phoSCRawE;
 std::vector<float>				*phoESEn;
 std::vector<float>				*phoSCEt;
 std::vector<float>				*phoSCEta;
 std::vector<float>				*phoSCPhi;
 std::vector<float>				*phoSCEtaWidth;
 std::vector<float>				*phoSCPhiWidth;
 std::vector<float>				*phoSCBrem;
 std::vector<int>				*phoOverlap;
 std::vector<int>				*phohasPixelSeed;
 std::vector<int>				*pho_hasConvPf;
 std::vector<int>				*pho_hasSLConvPf;
 std::vector<float>				*pho_pfconvVtxZ;
 std::vector<float>				*pho_pfconvVtxZErr;
 std::vector<int>				*pho_nSLConv;
 std::vector<std::vector<float> >				*pho_pfSLConvPos_x;
 std::vector<std::vector<float> >				*pho_pfSLConvPos_y;
 std::vector<std::vector<float> >				*pho_pfSLConvPos_z;
 std::vector<std::vector<float> >				*pho_pfSLConvVtxZ;
 std::vector<int>				*phoIsConv;
 std::vector<int>				*phoNConv;
 std::vector<float>				*phoConvInvMass;
 std::vector<float>				*phoConvCotTheta;
 std::vector<float>				*phoConvEoverP;
 std::vector<float>				*phoConvZofPVfromTrks;
 std::vector<float>				*phoConvMinDist;
 std::vector<float>				*phoConvdPhiAtVtx;
 std::vector<float>				*phoConvdPhiAtCalo;
 std::vector<float>				*phoConvdEtaAtCalo;
 std::vector<float>				*phoConvTrkd0_x;
 std::vector<float>				*phoConvTrkd0_y;
 std::vector<float>				*phoConvTrkPin_x;
 std::vector<float>				*phoConvTrkPin_y;
 std::vector<float>				*phoConvTrkPout_x;
 std::vector<float>				*phoConvTrkPout_y;
 std::vector<float>				*phoConvTrkdz_x;
 std::vector<float>				*phoConvTrkdz_y;
 std::vector<float>				*phoConvTrkdzErr_x;
 std::vector<float>				*phoConvTrkdzErr_y;
 std::vector<float>				*phoConvChi2;
 std::vector<float>				*phoConvChi2Prob;
 std::vector<int>				*phoConvNTrks;
 std::vector<float>				*phoConvCharge1;
 std::vector<float>				*phoConvCharge2;
 std::vector<int>				*phoConvValidVtx;
 std::vector<float>				*phoConvLikeLihood;
 std::vector<float>				*phoConvP4_0;
 std::vector<float>				*phoConvP4_1;
 std::vector<float>				*phoConvP4_2;
 std::vector<float>				*phoConvP4_3;
 std::vector<float>				*phoConvVtx_x;
 std::vector<float>				*phoConvVtx_y;
 std::vector<float>				*phoConvVtx_z;
 std::vector<float>				*phoConvVtxErr_x;
 std::vector<float>				*phoConvVtxErr_y;
 std::vector<float>				*phoConvVtxErr_z;
 std::vector<float>				*phoConvPairMomentum_x;
 std::vector<float>				*phoConvPairMomentum_y;
 std::vector<float>				*phoConvPairMomentum_z;
 std::vector<float>				*phoConvRefittedMomentum_x;
 std::vector<float>				*phoConvRefittedMomentum_y;
 std::vector<float>				*phoConvRefittedMomentum_z;
 std::vector<int>				*SingleLegConv;
 std::vector<std::vector<float> >				*phoPFConvVtx_x;
 std::vector<std::vector<float> >				*phoPFConvVtx_y;
 std::vector<std::vector<float> >				*phoPFConvVtx_z;
 std::vector<std::vector<float> >				*phoPFConvMom_x;
 std::vector<std::vector<float> >				*phoPFConvMom_y;
 std::vector<std::vector<float> >				*phoPFConvMom_z;
 std::vector<float>				*phoESEffSigmaRR_x;
 std::vector<float>				*phoESEffSigmaRR_y;
 std::vector<float>				*phoESEffSigmaRR_z;
 Int_t				nMu;
 std::vector<unsigned long>				*muTrg;
 std::vector<float>				*muEta;
 std::vector<float>				*muPhi;
 std::vector<int>				*muCharge;
 std::vector<float>				*muPt;
 std::vector<float>				*muPz;
 std::vector<float>				*muVtx_x;
 std::vector<float>				*muVtx_y;
 std::vector<float>				*muVtx_z;
 std::vector<float>				*muVtxGlb_x;
 std::vector<float>				*muVtxGlb_y;
 std::vector<float>				*muVtxGlb_z;
 std::vector<float>				*mucktPt;
 std::vector<float>				*mucktPtErr;
 std::vector<float>				*mucktEta;
 std::vector<float>				*mucktPhi;
 std::vector<float>				*mucktdxy;
 std::vector<float>				*mucktdz;
 std::vector<float>				*muIsoTrk;
 std::vector<float>				*muIsoCalo;
 std::vector<float>				*muIsoEcal;
 std::vector<float>				*muIsoHcal;
 std::vector<float>				*muChi2NDF;
 std::vector<float>				*muInnerChi2NDF;
 std::vector<float>				*muPFIsoR04_CH;
 std::vector<float>				*muPFIsoR04_NH;
 std::vector<float>				*muPFIsoR04_Pho;
 std::vector<float>				*muPFIsoR04_PU;
 std::vector<float>				*muPFIsoR04_CPart;
 std::vector<float>				*muPFIsoR04_NHHT;
 std::vector<float>				*muPFIsoR04_PhoHT;
 std::vector<float>				*muPFIsoR03_CH;
 std::vector<float>				*muPFIsoR03_NH;
 std::vector<float>				*muPFIsoR03_Pho;
 std::vector<float>				*muPFIsoR03_PU;
 std::vector<float>				*muPFIsoR03_CPart;
 std::vector<float>				*muPFIsoR03_NHHT;
 std::vector<float>				*muPFIsoR03_PhoHT;
 std::vector<int>				*muType;
 std::vector<float>				*muD0;
 std::vector<float>				*muDz;
 std::vector<float>				*muD0GV;
 std::vector<float>				*muDzGV;
 std::vector<std::vector<float> >				*muD0Vtx;
 std::vector<std::vector<float> >				*muDzVtx;
 std::vector<float>				*muInnerD0;
 std::vector<float>				*muInnerDz;
 std::vector<float>				*muInnerD0GV;
 std::vector<float>				*muInnerDzGV;
 std::vector<float>				*muInnerPt;
 std::vector<float>				*muInnerPtErr;
 std::vector<int>				*muNumberOfValidTrkLayers;
 std::vector<int>				*muNumberOfValidTrkHits;
 std::vector<int>				*muNumberOfValidPixelLayers;
 std::vector<int>				*muNumberOfValidPixelHits;
 std::vector<int>				*muNumberOfValidMuonHits;
 std::vector<int>				*muStations;
 std::vector<int>				*muChambers;
 std::vector<float>				*muIP3D;
 std::vector<float>				*muIP3DErr;
 Int_t				nTau;
 std::vector<bool>				*tauDecayModeFinding;
 std::vector<bool>				*tauAgainstElectronLooseMVA3;
 std::vector<bool>				*tauAgainstElectronMediumMVA3;
 std::vector<bool>				*tauAgainstElectronTightMVA3;
 std::vector<bool>				*tauAgainstElectronVTightMVA3;
 std::vector<bool>				*tauAgainstElectronDeadECAL;
 std::vector<bool>				*tauAgainstMuonLoose2;
 std::vector<bool>				*tauAgainstMuonMedium2;
 std::vector<bool>				*tauAgainstMuonTight2;
 std::vector<bool>				*tauCombinedIsolationDeltaBetaCorrRaw3Hits;
 std::vector<bool>				*tauLooseCombinedIsolationDeltaBetaCorr3Hits;
 std::vector<bool>				*tauMediumCombinedIsolationDeltaBetaCorr3Hits;
 std::vector<bool>				*tauTightCombinedIsolationDeltaBetaCorr3Hits;
 std::vector<float>				*tauEta;
 std::vector<float>				*tauPhi;
 std::vector<float>				*tauPt;
 std::vector<float>				*tauEt;
 std::vector<float>				*tauCharge;
 std::vector<int>				*tauDecayMode;
 std::vector<float>				*tauEMFraction;
 std::vector<float>				*tauHCAL3x3OverPLead;
 std::vector<float>				*tauHCALMaxOverPLead;
 std::vector<float>				*tauHCALTotOverPLead;
 std::vector<float>				*tauIsolationPFChargedHadrCandsPtSum;
 std::vector<float>				*tauIsolationPFGammaCandsEtSum;
 std::vector<float>				*tauLeadPFChargedHadrCandsignedSipt;
 std::vector<bool>				*tauLeadChargedHadronExists;
 std::vector<float>				*tauLeadChargedHadronEta;
 std::vector<float>				*tauLeadChargedHadronPhi;
 std::vector<float>				*tauLeadChargedHadronPt;
 Float_t				rho25;
 Float_t				rho25_neu;
 Float_t				rho25_muPFiso;
 Float_t				rho25_elePFiso;
 Float_t				rho2011;
 Float_t				rho2012;
 Float_t				QGTag_MLP;
 Float_t				QGTag_likelihood;
 Int_t				nCA8Jet;
 std::vector<float>				*CA8JetPt;
 std::vector<float>				*CA8JetEta;
 std::vector<float>				*CA8JetPhi;
 std::vector<float>				*CA8JetMass;
 std::vector<float>				*CA8JetArea;
 std::vector<float>				*CA8Jet_tau1;
 std::vector<float>				*CA8Jet_tau2;
 std::vector<float>				*CA8Jet_tau3;
 std::vector<float>				*CA8JetCHF;
 std::vector<float>				*CA8JetNHF;
 std::vector<float>				*CA8JetCEF;
 std::vector<float>				*CA8JetNEF;
 std::vector<int>				*CA8JetNCH;
 std::vector<int>				*CA8Jetnconstituents;
 std::vector<float>				*CA8prunedJetMass;
 std::vector<int>				*CA8prunedJet_nSubJets;
 std::vector<std::vector<float> >				*CA8prunedJet_SubjetPt;
 std::vector<std::vector<float> >				*CA8prunedJet_SubjetEta;
 std::vector<std::vector<float> >				*CA8prunedJet_SubjetPhi;
 std::vector<std::vector<float> >				*CA8prunedJet_SubjetMass;
 Int_t				nJet;
 std::vector<unsigned long>				*jetTrg;
 std::vector<float>				*jetEn;
 std::vector<float>				*jetPt;
 std::vector<float>				*jetEta;
 std::vector<float>				*jetPhi;
 std::vector<float>				*jetCharge;
 std::vector<float>				*jetEt;
 std::vector<float>				*jetRawPt;
 std::vector<float>				*jetRawEn;
 std::vector<float>				*jetArea;
 std::vector<float>				*jetCHF;
 std::vector<float>				*jetNHF;
 std::vector<float>				*jetCEF;
 std::vector<float>				*jetNEF;
 std::vector<int>				*jetNCH;
 std::vector<float>				*jetHFHAE;
 std::vector<float>				*jetHFEME;
 std::vector<int>				*jetNConstituents;
 std::vector<float>				*jetCombinedSecondaryVtxBJetTags;
 std::vector<float>				*jetCombinedSecondaryVtxMVABJetTags;
 std::vector<float>				*jetJetProbabilityBJetTags;
 std::vector<float>				*jetJetBProbabilityBJetTags;
 std::vector<std::vector<float> >				*jetBetaStar;
 std::vector<bool>				*jetPFLooseId;
 std::vector<float>				*jetDRMean;
 std::vector<float>				*jetDR2Mean;
 std::vector<float>				*jetDZ;
 std::vector<float>				*jetFrac01;
 std::vector<float>				*jetFrac02;
 std::vector<float>				*jetFrac03;
 std::vector<float>				*jetFrac04;
 std::vector<float>				*jetFrac05;
 std::vector<float>				*jetFrac06;
 std::vector<float>				*jetFrac07;
 std::vector<float>				*jetBeta;
 std::vector<float>				*jetBetaStarCMG;
 std::vector<float>				*jetBetaStarClassic;
 std::vector<std::vector<float> >				*jetBetaExt;
 std::vector<std::vector<float> >				*jetBetaStarCMGExt;
 std::vector<std::vector<float> >				*jetBetaStarClassicExt;
 std::vector<float>				*jetNNeutrals;
 std::vector<float>				*jetNCharged;
 std::vector<std::vector<float> >				*jetMVAs;
 std::vector<std::vector<int> >				*jetWPLevels;
 std::vector<std::vector<float> >				*jetMVAsExt_simple;
 std::vector<std::vector<int> >				*jetWPLevelsExt_simple;
 std::vector<std::vector<float> >				*jetMVAsExt_full;
 std::vector<std::vector<int> >				*jetWPLevelsExt_full;
 std::vector<std::vector<float> >				*jetMVAsExt_cutBased;
 std::vector<std::vector<int> >				*jetWPLevelsExt_cutBased;
 std::vector<std::vector<float> >				*jetMVAsExt_philv1;
 std::vector<std::vector<int> >				*jetWPLevelsExt_philv1;
 std::vector<float>				*jetMt;
 std::vector<float>				*jetJECUnc;
 std::vector<float>				*jetLeadTrackPt;
 std::vector<float>				*jetVtxPt;
 std::vector<float>				*jetVtxMass;
 std::vector<float>				*jetVtx3dL;
 std::vector<float>				*jetVtx3deL;
 std::vector<float>				*jetSoftLeptPt;
 std::vector<float>				*jetSoftLeptPtRel;
 std::vector<float>				*jetSoftLeptdR;
 std::vector<float>				*jetSoftLeptIdlooseMu;
 std::vector<float>				*jetSoftLeptIdEle95;
 std::vector<float>				*jetDPhiMETJet;
 std::vector<float>				*jetPuJetIdL;
 std::vector<float>				*jetPuJetIdM;
 std::vector<float>				*jetPuJetIdT;
 Int_t				nConv;
 std::vector<float>				*convP4_x;
 std::vector<float>				*convP4_y;
 std::vector<float>				*convP4_z;
 std::vector<float>				*convP4_E;
 std::vector<float>				*convVtx_x;
 std::vector<float>				*convVtx_y;
 std::vector<float>				*convVtx_z;
 std::vector<float>				*convVtxErr_x;
 std::vector<float>				*convVtxErr_y;
 std::vector<float>				*convVtxErr_z;
 std::vector<float>				*convPairMomentum_x;
 std::vector<float>				*convPairMomentum_y;
 std::vector<float>				*convPairMomentum_z;
 std::vector<float>				*convRefittedMomentum_x;
 std::vector<float>				*convRefittedMomentum_y;
 std::vector<float>				*convRefittedMomentum_z;
 std::vector<int>				*convNTracks;
 std::vector<float>				*convPairInvMass;
 std::vector<float>				*convPairCotThetaSep;
 std::vector<float>				*convEoverP;
 std::vector<float>				*convDistOfMinApproach;
 std::vector<float>				*convDPhiTrksAtVtx;
 std::vector<float>				*convDPhiTrksAtEcal;
 std::vector<float>				*convDEtaTrksAtEcal;
 std::vector<float>				*convDxy;
 std::vector<float>				*convDz;
 std::vector<float>				*convLxy;
 std::vector<float>				*convLz;
 std::vector<float>				*convZofPrimVtxFromTrks;
 std::vector<int>				*convNHitsBeforeVtx_0;
 std::vector<int>				*convNHitsBeforeVtx_1;
 std::vector<int>				*convNSharedHits;
 std::vector<int>				*convValidVtx;
 std::vector<float>				*convMVALikelihood;
 std::vector<float>				*convChi2;
 std::vector<float>				*convChi2Probability;
 std::vector<float>				*convTk1Dz;
 std::vector<float>				*convTk2Dz;
 std::vector<float>				*convTk1DzErr;
 std::vector<float>				*convTk2DzErr;
 std::vector<int>				*convCh1Ch2;
 std::vector<float>				*convTk1D0;
 std::vector<float>				*convTk1Pout;
 std::vector<float>				*convTk1Pin;
 std::vector<float>				*convTk2D0;
 std::vector<float>				*convTk2Pout;
 std::vector<float>				*convTk2Pin;
};
namespace OUT {
 Int_t				nHLT;
 Int_t				run;
 Long64_t				event;
 Int_t				lumis;
 Bool_t				isData;
 Int_t				HLT[453];
 Int_t				HLTIndex[70];
 Float_t				bspotPos[3];
 Int_t				nVtx;
 std::vector<float>				*vtx_x;
 std::vector<float>				*vtx_y;
 std::vector<float>				*vtx_z;
 Int_t				IsVtxGood;
 Int_t				nGoodVtx;
 Int_t				nVtxBS;
 std::vector<float>				*vtxbs_x;
 std::vector<float>				*vtxbs_y;
 std::vector<float>				*vtxbs_z;
 Float_t				pfMET;
 Float_t				pfMETPhi;
 Float_t				pfMETsumEt;
 Float_t				pfMETmEtSig;
 Float_t				pfMETSig;
 Float_t				pfType01MET;
 Float_t				pfType01METPhi;
 Float_t				pfType01METsumEt;
 Float_t				pfType01METmEtSig;
 Float_t				pfType01METSig;
 Float_t				recoPfMET;
 Float_t				recoPfMETPhi;
 Float_t				recoPfMETsumEt;
 Float_t				recoPfMETmEtSig;
 Float_t				recoPfMETSig;
 Float_t				trkMETxPV;
 Float_t				trkMETyPV;
 Float_t				trkMETPhiPV;
 Float_t				trkMETPV;
 std::vector<float>				*trkMETx;
 std::vector<float>				*trkMETy;
 std::vector<float>				*trkMETPhi;
 std::vector<float>				*trkMET;
 Int_t				metFilters[10];
 Int_t				nEle;
 std::vector<unsigned long>				*eleTrg;
 std::vector<int>				*eleClass;
 std::vector<int>				*eleIsEcalDriven;
 std::vector<int>				*eleCharge;
 std::vector<int>				*eleChargeConsistent;
 std::vector<float>				*eleEn;
 std::vector<float>				*eleEcalEn;
 std::vector<float>				*eleSCRawEn;
 std::vector<float>				*eleSCEn;
 std::vector<float>				*eleESEn;
 std::vector<float>				*elePt;
 std::vector<float>				*eleEta;
 std::vector<float>				*elePhi;
 std::vector<float>				*eleR9;
 std::vector<std::vector<float> >				*eleEtaVtx;
 std::vector<std::vector<float> >				*elePhiVtx;
 std::vector<std::vector<float> >				*eleEtVtx;
 std::vector<float>				*eleSCEta;
 std::vector<float>				*eleSCPhi;
 std::vector<float>				*eleSCEtaWidth;
 std::vector<float>				*eleSCPhiWidth;
 std::vector<float>				*eleVtx_x;
 std::vector<float>				*eleVtx_y;
 std::vector<float>				*eleVtx_z;
 std::vector<float>				*eleD0;
 std::vector<float>				*eleDz;
 std::vector<float>				*eleD0GV;
 std::vector<float>				*eleDzGV;
 std::vector<std::vector<float> >				*eleD0Vtx;
 std::vector<std::vector<float> >				*eleDzVtx;
 std::vector<float>				*eleHoverE;
 std::vector<float>				*eleHoverE12;
 std::vector<float>				*eleEoverP;
 std::vector<float>				*elePin;
 std::vector<float>				*elePout;
 std::vector<float>				*eleTrkMomErr;
 std::vector<float>				*eleBrem;
 std::vector<float>				*eledEtaAtVtx;
 std::vector<float>				*eledPhiAtVtx;
 std::vector<float>				*eleSigmaIEtaIEta;
 std::vector<float>				*eleSigmaIEtaIPhi;
 std::vector<float>				*eleSigmaIPhiIPhi;
 std::vector<float>				*eleEmax;
 std::vector<float>				*eleE2ndMax;
 std::vector<float>				*eleETop;
 std::vector<float>				*eleEBottom;
 std::vector<float>				*eleELeft;
 std::vector<float>				*eleERight;
 std::vector<float>				*eleE1x5;
 std::vector<float>				*eleE3x3;
 std::vector<float>				*eleE5x5;
 std::vector<float>				*eleE2x5Max;
 std::vector<float>				*eleE2x5Top;
 std::vector<float>				*eleE2x5Bottom;
 std::vector<float>				*eleE2x5Left;
 std::vector<float>				*eleE2x5Right;
 std::vector<float>				*eleSeedEta;
 std::vector<float>				*eleSeedE;
 std::vector<float>				*eleSeedPhi;
 std::vector<float>				*eleCrysEta;
 std::vector<float>				*eleCrysPhi;
 std::vector<int>				*eleCrysIEta;
 std::vector<int>				*eleCrysIPhi;
 std::vector<float>				*eleRegrE;
 std::vector<float>				*eleRegrEerr;
 std::vector<float>				*elePhoRegrE;
 std::vector<float>				*elePhoRegrEerr;
 std::vector<float>				*eleSeedTime;
 std::vector<int>				*eleRecoFlag;
 std::vector<int>				*elePos;
 std::vector<float>				*eleIsoTrkDR03;
 std::vector<float>				*eleIsoEcalDR03;
 std::vector<float>				*eleIsoHcalDR03;
 std::vector<float>				*eleIsoHcalDR0312;
 std::vector<float>				*eleIsoTrkDR04;
 std::vector<float>				*eleIsoEcalDR04;
 std::vector<float>				*eleIsoHcalDR04;
 std::vector<float>				*eleIsoHcalDR0412;
 std::vector<float>				*eleModIsoTrk;
 std::vector<float>				*eleModIsoEcal;
 std::vector<float>				*eleModIsoHcal;
 std::vector<int>				*eleMissHits;
 std::vector<float>				*eleConvDist;
 std::vector<float>				*eleConvDcot;
 std::vector<int>				*eleConvVtxFit;
 std::vector<float>				*eleIP3D;
 std::vector<float>				*eleIP3DErr;
 std::vector<float>				*eleIDMVANonTrig;
 std::vector<float>				*eleIDMVATrig;
 std::vector<float>				*elePFChIso03;
 std::vector<float>				*elePFPhoIso03;
 std::vector<float>				*elePFNeuIso03;
 std::vector<float>				*elePFChIso04;
 std::vector<float>				*elePFPhoIso04;
 std::vector<float>				*elePFNeuIso04;
 std::vector<float>				*eleESEffSigmaRR_x;
 std::vector<float>				*eleESEffSigmaRR_y;
 std::vector<float>				*eleESEffSigmaRR_z;
 Int_t				nPho;
 std::vector<unsigned long>				*phoTrg;
 std::vector<unsigned long>				*phoTrgFilter;
 std::vector<bool>				*phoIsPhoton;
 std::vector<float>				*phoSCPos_x;
 std::vector<float>				*phoSCPos_y;
 std::vector<float>				*phoSCPos_z;
 std::vector<float>				*phoCaloPos_x;
 std::vector<float>				*phoCaloPos_y;
 std::vector<float>				*phoCaloPos_z;
 std::vector<float>				*phoE;
 std::vector<float>				*phoEt;
 std::vector<float>				*phoEta;
 std::vector<float>				*phoVtx_x;
 std::vector<float>				*phoVtx_y;
 std::vector<float>				*phoVtx_z;
 std::vector<float>				*phoPhi;
 std::vector<std::vector<float> >				*phoEtVtx;
 std::vector<std::vector<float> >				*phoEtaVtx;
 std::vector<std::vector<float> >				*phoPhiVtx;
 std::vector<float>				*phoR9;
 std::vector<int>				*phoNClus;
 std::vector<float>				*phoTrkIsoHollowDR03;
 std::vector<float>				*phoEcalIsoDR03;
 std::vector<float>				*phoHcalIsoDR03;
 std::vector<float>				*phoHcalIsoDR0312;
 std::vector<float>				*phoTrkIsoHollowDR04;
 std::vector<float>				*phoCiCdRtoTrk;
 std::vector<float>				*phoEcalIsoDR04;
 std::vector<float>				*phoHcalIsoDR04;
 std::vector<float>				*phoHcalIsoDR0412;
 std::vector<float>				*phoHoverE;
 std::vector<float>				*phoHoverE12;
 std::vector<int>				*phoEleVeto;
 std::vector<float>				*phoSigmaIEtaIEta;
 std::vector<float>				*phoSigmaIEtaIPhi;
 std::vector<float>				*phoSigmaIPhiIPhi;
 std::vector<float>				*phoCiCPF4phopfIso03;
 std::vector<float>				*phoCiCPF4phopfIso04;
 std::vector<float>				*phoEmax;
 std::vector<float>				*phoETop;
 std::vector<float>				*phoEBottom;
 std::vector<float>				*phoELeft;
 std::vector<float>				*phoERight;
 std::vector<float>				*phoE2ndMax;
 std::vector<float>				*phoE3x3;
 std::vector<float>				*phoE3x1;
 std::vector<float>				*phoE1x3;
 std::vector<float>				*phoE5x5;
 std::vector<float>				*phoE1x5;
 std::vector<float>				*phoE2x2;
 std::vector<float>				*phoE2x5Max;
 std::vector<float>				*phoE2x5Top;
 std::vector<float>				*phoE2x5Bottom;
 std::vector<float>				*phoE2x5Left;
 std::vector<float>				*phoE2x5Right;
 std::vector<float>				*phoSeedE;
 std::vector<float>				*phoSeedEta;
 std::vector<float>				*phoSeedPhi;
 std::vector<float>				*phoCrysEta;
 std::vector<float>				*phoCrysPhi;
 std::vector<int>				*phoCrysIEta;
 std::vector<int>				*phoCrysIPhi;
 std::vector<float>				*phoPFChIso;
 std::vector<float>				*phoPFPhoIso;
 std::vector<float>				*phoPFNeuIso;
 std::vector<float>				*phoSCRChIso;
 std::vector<float>				*phoSCRPhoIso;
 std::vector<float>				*phoSCRNeuIso;
 std::vector<float>				*phoSCRChIso04;
 std::vector<float>				*phoSCRPhoIso04;
 std::vector<float>				*phoSCRNeuIso04;
 std::vector<float>				*phoRandConeChIso;
 std::vector<float>				*phoRandConePhoIso;
 std::vector<float>				*phoRandConeNeuIso;
 std::vector<float>				*phoRandConeChIso04;
 std::vector<float>				*phoRandConePhoIso04;
 std::vector<float>				*phoRandConeNeuIso04;
 std::vector<float>				*phoRegrE;
 std::vector<float>				*phoRegrEerr;
 std::vector<float>				*phoSeedTime;
 std::vector<int>				*phoSeedDetId1;
 std::vector<int>				*phoSeedDetId2;
 std::vector<float>				*phoLICTD;
 std::vector<int>				*phoRecoFlag;
 std::vector<int>				*phoPos;
 std::vector<float>				*phoSCE;
 std::vector<float>				*phoSCRawE;
 std::vector<float>				*phoESEn;
 std::vector<float>				*phoSCEt;
 std::vector<float>				*phoSCEta;
 std::vector<float>				*phoSCPhi;
 std::vector<float>				*phoSCEtaWidth;
 std::vector<float>				*phoSCPhiWidth;
 std::vector<float>				*phoSCBrem;
 std::vector<int>				*phoOverlap;
 std::vector<int>				*phohasPixelSeed;
 std::vector<int>				*pho_hasConvPf;
 std::vector<int>				*pho_hasSLConvPf;
 std::vector<float>				*pho_pfconvVtxZ;
 std::vector<float>				*pho_pfconvVtxZErr;
 std::vector<int>				*pho_nSLConv;
 std::vector<std::vector<float> >				*pho_pfSLConvPos_x;
 std::vector<std::vector<float> >				*pho_pfSLConvPos_y;
 std::vector<std::vector<float> >				*pho_pfSLConvPos_z;
 std::vector<std::vector<float> >				*pho_pfSLConvVtxZ;
 std::vector<int>				*phoIsConv;
 std::vector<int>				*phoNConv;
 std::vector<float>				*phoConvInvMass;
 std::vector<float>				*phoConvCotTheta;
 std::vector<float>				*phoConvEoverP;
 std::vector<float>				*phoConvZofPVfromTrks;
 std::vector<float>				*phoConvMinDist;
 std::vector<float>				*phoConvdPhiAtVtx;
 std::vector<float>				*phoConvdPhiAtCalo;
 std::vector<float>				*phoConvdEtaAtCalo;
 std::vector<float>				*phoConvTrkd0_x;
 std::vector<float>				*phoConvTrkd0_y;
 std::vector<float>				*phoConvTrkPin_x;
 std::vector<float>				*phoConvTrkPin_y;
 std::vector<float>				*phoConvTrkPout_x;
 std::vector<float>				*phoConvTrkPout_y;
 std::vector<float>				*phoConvTrkdz_x;
 std::vector<float>				*phoConvTrkdz_y;
 std::vector<float>				*phoConvTrkdzErr_x;
 std::vector<float>				*phoConvTrkdzErr_y;
 std::vector<float>				*phoConvChi2;
 std::vector<float>				*phoConvChi2Prob;
 std::vector<int>				*phoConvNTrks;
 std::vector<float>				*phoConvCharge1;
 std::vector<float>				*phoConvCharge2;
 std::vector<int>				*phoConvValidVtx;
 std::vector<float>				*phoConvLikeLihood;
 std::vector<float>				*phoConvP4_0;
 std::vector<float>				*phoConvP4_1;
 std::vector<float>				*phoConvP4_2;
 std::vector<float>				*phoConvP4_3;
 std::vector<float>				*phoConvVtx_x;
 std::vector<float>				*phoConvVtx_y;
 std::vector<float>				*phoConvVtx_z;
 std::vector<float>				*phoConvVtxErr_x;
 std::vector<float>				*phoConvVtxErr_y;
 std::vector<float>				*phoConvVtxErr_z;
 std::vector<float>				*phoConvPairMomentum_x;
 std::vector<float>				*phoConvPairMomentum_y;
 std::vector<float>				*phoConvPairMomentum_z;
 std::vector<float>				*phoConvRefittedMomentum_x;
 std::vector<float>				*phoConvRefittedMomentum_y;
 std::vector<float>				*phoConvRefittedMomentum_z;
 std::vector<int>				*SingleLegConv;
 std::vector<std::vector<float> >				*phoPFConvVtx_x;
 std::vector<std::vector<float> >				*phoPFConvVtx_y;
 std::vector<std::vector<float> >				*phoPFConvVtx_z;
 std::vector<std::vector<float> >				*phoPFConvMom_x;
 std::vector<std::vector<float> >				*phoPFConvMom_y;
 std::vector<std::vector<float> >				*phoPFConvMom_z;
 std::vector<float>				*phoESEffSigmaRR_x;
 std::vector<float>				*phoESEffSigmaRR_y;
 std::vector<float>				*phoESEffSigmaRR_z;
 Int_t				nMu;
 std::vector<unsigned long>				*muTrg;
 std::vector<float>				*muEta;
 std::vector<float>				*muPhi;
 std::vector<int>				*muCharge;
 std::vector<float>				*muPt;
 std::vector<float>				*muPz;
 std::vector<float>				*muVtx_x;
 std::vector<float>				*muVtx_y;
 std::vector<float>				*muVtx_z;
 std::vector<float>				*muVtxGlb_x;
 std::vector<float>				*muVtxGlb_y;
 std::vector<float>				*muVtxGlb_z;
 std::vector<float>				*mucktPt;
 std::vector<float>				*mucktPtErr;
 std::vector<float>				*mucktEta;
 std::vector<float>				*mucktPhi;
 std::vector<float>				*mucktdxy;
 std::vector<float>				*mucktdz;
 std::vector<float>				*muIsoTrk;
 std::vector<float>				*muIsoCalo;
 std::vector<float>				*muIsoEcal;
 std::vector<float>				*muIsoHcal;
 std::vector<float>				*muChi2NDF;
 std::vector<float>				*muInnerChi2NDF;
 std::vector<float>				*muPFIsoR04_CH;
 std::vector<float>				*muPFIsoR04_NH;
 std::vector<float>				*muPFIsoR04_Pho;
 std::vector<float>				*muPFIsoR04_PU;
 std::vector<float>				*muPFIsoR04_CPart;
 std::vector<float>				*muPFIsoR04_NHHT;
 std::vector<float>				*muPFIsoR04_PhoHT;
 std::vector<float>				*muPFIsoR03_CH;
 std::vector<float>				*muPFIsoR03_NH;
 std::vector<float>				*muPFIsoR03_Pho;
 std::vector<float>				*muPFIsoR03_PU;
 std::vector<float>				*muPFIsoR03_CPart;
 std::vector<float>				*muPFIsoR03_NHHT;
 std::vector<float>				*muPFIsoR03_PhoHT;
 std::vector<int>				*muType;
 std::vector<float>				*muD0;
 std::vector<float>				*muDz;
 std::vector<float>				*muD0GV;
 std::vector<float>				*muDzGV;
 std::vector<std::vector<float> >				*muD0Vtx;
 std::vector<std::vector<float> >				*muDzVtx;
 std::vector<float>				*muInnerD0;
 std::vector<float>				*muInnerDz;
 std::vector<float>				*muInnerD0GV;
 std::vector<float>				*muInnerDzGV;
 std::vector<float>				*muInnerPt;
 std::vector<float>				*muInnerPtErr;
 std::vector<int>				*muNumberOfValidTrkLayers;
 std::vector<int>				*muNumberOfValidTrkHits;
 std::vector<int>				*muNumberOfValidPixelLayers;
 std::vector<int>				*muNumberOfValidPixelHits;
 std::vector<int>				*muNumberOfValidMuonHits;
 std::vector<int>				*muStations;
 std::vector<int>				*muChambers;
 std::vector<float>				*muIP3D;
 std::vector<float>				*muIP3DErr;
 Int_t				nTau;
 std::vector<bool>				*tauDecayModeFinding;
 std::vector<bool>				*tauAgainstElectronLooseMVA3;
 std::vector<bool>				*tauAgainstElectronMediumMVA3;
 std::vector<bool>				*tauAgainstElectronTightMVA3;
 std::vector<bool>				*tauAgainstElectronVTightMVA3;
 std::vector<bool>				*tauAgainstElectronDeadECAL;
 std::vector<bool>				*tauAgainstMuonLoose2;
 std::vector<bool>				*tauAgainstMuonMedium2;
 std::vector<bool>				*tauAgainstMuonTight2;
 std::vector<bool>				*tauCombinedIsolationDeltaBetaCorrRaw3Hits;
 std::vector<bool>				*tauLooseCombinedIsolationDeltaBetaCorr3Hits;
 std::vector<bool>				*tauMediumCombinedIsolationDeltaBetaCorr3Hits;
 std::vector<bool>				*tauTightCombinedIsolationDeltaBetaCorr3Hits;
 std::vector<float>				*tauEta;
 std::vector<float>				*tauPhi;
 std::vector<float>				*tauPt;
 std::vector<float>				*tauEt;
 std::vector<float>				*tauCharge;
 std::vector<int>				*tauDecayMode;
 std::vector<float>				*tauEMFraction;
 std::vector<float>				*tauHCAL3x3OverPLead;
 std::vector<float>				*tauHCALMaxOverPLead;
 std::vector<float>				*tauHCALTotOverPLead;
 std::vector<float>				*tauIsolationPFChargedHadrCandsPtSum;
 std::vector<float>				*tauIsolationPFGammaCandsEtSum;
 std::vector<float>				*tauLeadPFChargedHadrCandsignedSipt;
 std::vector<bool>				*tauLeadChargedHadronExists;
 std::vector<float>				*tauLeadChargedHadronEta;
 std::vector<float>				*tauLeadChargedHadronPhi;
 std::vector<float>				*tauLeadChargedHadronPt;
 Float_t				rho25;
 Float_t				rho25_neu;
 Float_t				rho25_muPFiso;
 Float_t				rho25_elePFiso;
 Float_t				rho2011;
 Float_t				rho2012;
 Float_t				QGTag_MLP;
 Float_t				QGTag_likelihood;
 Int_t				nCA8Jet;
 Int_t				nJet;
 std::vector<unsigned long>				*jetTrg;
 std::vector<float>				*jetEn;
 std::vector<float>				*jetPt;
 std::vector<float>				*jetEta;
 std::vector<float>				*jetPhi;
 std::vector<float>				*jetCharge;
 std::vector<float>				*jetEt;
 std::vector<float>				*jetRawPt;
 std::vector<float>				*jetRawEn;
 std::vector<float>				*jetArea;
 std::vector<float>				*jetCHF;
 std::vector<float>				*jetNHF;
 std::vector<float>				*jetCEF;
 std::vector<float>				*jetNEF;
 std::vector<int>				*jetNCH;
 std::vector<float>				*jetHFHAE;
 std::vector<float>				*jetHFEME;
 std::vector<int>				*jetNConstituents;
 std::vector<float>				*jetCombinedSecondaryVtxBJetTags;
 std::vector<float>				*jetCombinedSecondaryVtxMVABJetTags;
 std::vector<float>				*jetJetProbabilityBJetTags;
 std::vector<float>				*jetJetBProbabilityBJetTags;
 std::vector<bool>				*jetPFLooseId;
 std::vector<float>				*jetDRMean;
 std::vector<float>				*jetDR2Mean;
 std::vector<float>				*jetDZ;
 std::vector<float>				*jetFrac01;
 std::vector<float>				*jetFrac02;
 std::vector<float>				*jetFrac03;
 std::vector<float>				*jetFrac04;
 std::vector<float>				*jetFrac05;
 std::vector<float>				*jetFrac06;
 std::vector<float>				*jetFrac07;
 std::vector<float>				*jetBeta;
 std::vector<float>				*jetBetaStarCMG;
 std::vector<float>				*jetBetaStarClassic;
 std::vector<float>				*jetNNeutrals;
 std::vector<float>				*jetNCharged;
 std::vector<std::vector<int> >				*jetWPLevels;
 std::vector<std::vector<float> >				*jetMVAsExt_cutBased;
 std::vector<std::vector<float> >				*jetMVAsExt_philv1;
 std::vector<std::vector<int> >				*jetWPLevelsExt_philv1;
 std::vector<float>				*jetMt;
 std::vector<float>				*jetJECUnc;
 std::vector<float>				*jetLeadTrackPt;
 std::vector<float>				*jetVtxPt;
 std::vector<float>				*jetVtxMass;
 std::vector<float>				*jetVtx3dL;
 std::vector<float>				*jetVtx3deL;
 std::vector<float>				*jetSoftLeptPt;
 std::vector<float>				*jetSoftLeptPtRel;
 std::vector<float>				*jetSoftLeptdR;
 std::vector<float>				*jetSoftLeptIdlooseMu;
 std::vector<float>				*jetSoftLeptIdEle95;
 std::vector<float>				*jetDPhiMETJet;
 std::vector<float>				*jetPuJetIdL;
 std::vector<float>				*jetPuJetIdM;
 std::vector<float>				*jetPuJetIdT;
 Int_t				nConv;
 std::vector<float>				*convP4_x;
 std::vector<float>				*convP4_y;
 std::vector<float>				*convP4_z;
 std::vector<float>				*convP4_E;
 std::vector<float>				*convVtx_x;
 std::vector<float>				*convVtx_y;
 std::vector<float>				*convVtx_z;
 std::vector<float>				*convVtxErr_x;
 std::vector<float>				*convVtxErr_y;
 std::vector<float>				*convVtxErr_z;
 std::vector<float>				*convPairMomentum_x;
 std::vector<float>				*convPairMomentum_y;
 std::vector<float>				*convPairMomentum_z;
 std::vector<float>				*convRefittedMomentum_x;
 std::vector<float>				*convRefittedMomentum_y;
 std::vector<float>				*convRefittedMomentum_z;
 std::vector<int>				*convNTracks;
 std::vector<float>				*convPairInvMass;
 std::vector<float>				*convPairCotThetaSep;
 std::vector<float>				*convEoverP;
 std::vector<float>				*convDistOfMinApproach;
 std::vector<float>				*convDPhiTrksAtVtx;
 std::vector<float>				*convDPhiTrksAtEcal;
 std::vector<float>				*convDEtaTrksAtEcal;
 std::vector<float>				*convDxy;
 std::vector<float>				*convDz;
 std::vector<float>				*convLxy;
 std::vector<float>				*convLz;
 std::vector<float>				*convZofPrimVtxFromTrks;
 std::vector<int>				*convNHitsBeforeVtx_0;
 std::vector<int>				*convNHitsBeforeVtx_1;
 std::vector<int>				*convNSharedHits;
 std::vector<int>				*convValidVtx;
 std::vector<float>				*convMVALikelihood;
 std::vector<float>				*convChi2;
 std::vector<float>				*convChi2Probability;
 std::vector<float>				*convTk1Dz;
 std::vector<float>				*convTk2Dz;
 std::vector<float>				*convTk1DzErr;
 std::vector<float>				*convTk2DzErr;
 std::vector<int>				*convCh1Ch2;
 std::vector<float>				*convTk1D0;
 std::vector<float>				*convTk1Pout;
 std::vector<float>				*convTk1Pin;
 std::vector<float>				*convTk2D0;
 std::vector<float>				*convTk2Pout;
 std::vector<float>				*convTk2Pin;
};
void InitINTree( TChain * tree) {

  tree->SetBranchAddress("nHLT", &IN::nHLT);
  tree->SetBranchAddress("run", &IN::run);
  tree->SetBranchAddress("event", &IN::event);
  tree->SetBranchAddress("lumis", &IN::lumis);
  tree->SetBranchAddress("isData", &IN::isData);
  tree->SetBranchAddress("HLT", &IN::HLT);
  tree->SetBranchAddress("HLTIndex", &IN::HLTIndex);
  tree->SetBranchAddress("bspotPos", &IN::bspotPos);
  tree->SetBranchAddress("nVtx", &IN::nVtx);
  tree->SetBranchAddress("vtx_x", &IN::vtx_x);
  tree->SetBranchAddress("vtx_y", &IN::vtx_y);
  tree->SetBranchAddress("vtx_z", &IN::vtx_z);
  tree->SetBranchAddress("IsVtxGood", &IN::IsVtxGood);
  tree->SetBranchAddress("nGoodVtx", &IN::nGoodVtx);
  tree->SetBranchAddress("nVtxBS", &IN::nVtxBS);
  tree->SetBranchAddress("vtxbs_x", &IN::vtxbs_x);
  tree->SetBranchAddress("vtxbs_y", &IN::vtxbs_y);
  tree->SetBranchAddress("vtxbs_z", &IN::vtxbs_z);
  tree->SetBranchAddress("pfMET", &IN::pfMET);
  tree->SetBranchAddress("pfMETPhi", &IN::pfMETPhi);
  tree->SetBranchAddress("pfMETsumEt", &IN::pfMETsumEt);
  tree->SetBranchAddress("pfMETmEtSig", &IN::pfMETmEtSig);
  tree->SetBranchAddress("pfMETSig", &IN::pfMETSig);
  tree->SetBranchAddress("pfType01MET", &IN::pfType01MET);
  tree->SetBranchAddress("pfType01METPhi", &IN::pfType01METPhi);
  tree->SetBranchAddress("pfType01METsumEt", &IN::pfType01METsumEt);
  tree->SetBranchAddress("pfType01METmEtSig", &IN::pfType01METmEtSig);
  tree->SetBranchAddress("pfType01METSig", &IN::pfType01METSig);
  tree->SetBranchAddress("recoPfMET", &IN::recoPfMET);
  tree->SetBranchAddress("recoPfMETPhi", &IN::recoPfMETPhi);
  tree->SetBranchAddress("recoPfMETsumEt", &IN::recoPfMETsumEt);
  tree->SetBranchAddress("recoPfMETmEtSig", &IN::recoPfMETmEtSig);
  tree->SetBranchAddress("recoPfMETSig", &IN::recoPfMETSig);
  tree->SetBranchAddress("trkMETxPV", &IN::trkMETxPV);
  tree->SetBranchAddress("trkMETyPV", &IN::trkMETyPV);
  tree->SetBranchAddress("trkMETPhiPV", &IN::trkMETPhiPV);
  tree->SetBranchAddress("trkMETPV", &IN::trkMETPV);
  tree->SetBranchAddress("trkMETx", &IN::trkMETx);
  tree->SetBranchAddress("trkMETy", &IN::trkMETy);
  tree->SetBranchAddress("trkMETPhi", &IN::trkMETPhi);
  tree->SetBranchAddress("trkMET", &IN::trkMET);
  tree->SetBranchAddress("metFilters", &IN::metFilters);
  tree->SetBranchAddress("nEle", &IN::nEle);
  tree->SetBranchAddress("eleTrg", &IN::eleTrg);
  tree->SetBranchAddress("eleClass", &IN::eleClass);
  tree->SetBranchAddress("eleIsEcalDriven", &IN::eleIsEcalDriven);
  tree->SetBranchAddress("eleCharge", &IN::eleCharge);
  tree->SetBranchAddress("eleChargeConsistent", &IN::eleChargeConsistent);
  tree->SetBranchAddress("eleEn", &IN::eleEn);
  tree->SetBranchAddress("eleEcalEn", &IN::eleEcalEn);
  tree->SetBranchAddress("eleSCRawEn", &IN::eleSCRawEn);
  tree->SetBranchAddress("eleSCEn", &IN::eleSCEn);
  tree->SetBranchAddress("eleESEn", &IN::eleESEn);
  tree->SetBranchAddress("elePt", &IN::elePt);
  tree->SetBranchAddress("eleEta", &IN::eleEta);
  tree->SetBranchAddress("elePhi", &IN::elePhi);
  tree->SetBranchAddress("eleR9", &IN::eleR9);
  tree->SetBranchAddress("eleEtaVtx", &IN::eleEtaVtx);
  tree->SetBranchAddress("elePhiVtx", &IN::elePhiVtx);
  tree->SetBranchAddress("eleEtVtx", &IN::eleEtVtx);
  tree->SetBranchAddress("eleSCEta", &IN::eleSCEta);
  tree->SetBranchAddress("eleSCPhi", &IN::eleSCPhi);
  tree->SetBranchAddress("eleSCEtaWidth", &IN::eleSCEtaWidth);
  tree->SetBranchAddress("eleSCPhiWidth", &IN::eleSCPhiWidth);
  tree->SetBranchAddress("eleVtx_x", &IN::eleVtx_x);
  tree->SetBranchAddress("eleVtx_y", &IN::eleVtx_y);
  tree->SetBranchAddress("eleVtx_z", &IN::eleVtx_z);
  tree->SetBranchAddress("eleD0", &IN::eleD0);
  tree->SetBranchAddress("eleDz", &IN::eleDz);
  tree->SetBranchAddress("eleD0GV", &IN::eleD0GV);
  tree->SetBranchAddress("eleDzGV", &IN::eleDzGV);
  tree->SetBranchAddress("eleD0Vtx", &IN::eleD0Vtx);
  tree->SetBranchAddress("eleDzVtx", &IN::eleDzVtx);
  tree->SetBranchAddress("eleHoverE", &IN::eleHoverE);
  tree->SetBranchAddress("eleHoverE12", &IN::eleHoverE12);
  tree->SetBranchAddress("eleEoverP", &IN::eleEoverP);
  tree->SetBranchAddress("elePin", &IN::elePin);
  tree->SetBranchAddress("elePout", &IN::elePout);
  tree->SetBranchAddress("eleTrkMomErr", &IN::eleTrkMomErr);
  tree->SetBranchAddress("eleBrem", &IN::eleBrem);
  tree->SetBranchAddress("eledEtaAtVtx", &IN::eledEtaAtVtx);
  tree->SetBranchAddress("eledPhiAtVtx", &IN::eledPhiAtVtx);
  tree->SetBranchAddress("eleSigmaIEtaIEta", &IN::eleSigmaIEtaIEta);
  tree->SetBranchAddress("eleSigmaIEtaIPhi", &IN::eleSigmaIEtaIPhi);
  tree->SetBranchAddress("eleSigmaIPhiIPhi", &IN::eleSigmaIPhiIPhi);
  tree->SetBranchAddress("eleEmax", &IN::eleEmax);
  tree->SetBranchAddress("eleE2ndMax", &IN::eleE2ndMax);
  tree->SetBranchAddress("eleETop", &IN::eleETop);
  tree->SetBranchAddress("eleEBottom", &IN::eleEBottom);
  tree->SetBranchAddress("eleELeft", &IN::eleELeft);
  tree->SetBranchAddress("eleERight", &IN::eleERight);
  tree->SetBranchAddress("eleE1x5", &IN::eleE1x5);
  tree->SetBranchAddress("eleE3x3", &IN::eleE3x3);
  tree->SetBranchAddress("eleE5x5", &IN::eleE5x5);
  tree->SetBranchAddress("eleE2x5Max", &IN::eleE2x5Max);
  tree->SetBranchAddress("eleE2x5Top", &IN::eleE2x5Top);
  tree->SetBranchAddress("eleE2x5Bottom", &IN::eleE2x5Bottom);
  tree->SetBranchAddress("eleE2x5Left", &IN::eleE2x5Left);
  tree->SetBranchAddress("eleE2x5Right", &IN::eleE2x5Right);
  tree->SetBranchAddress("eleSeedEta", &IN::eleSeedEta);
  tree->SetBranchAddress("eleSeedE", &IN::eleSeedE);
  tree->SetBranchAddress("eleSeedPhi", &IN::eleSeedPhi);
  tree->SetBranchAddress("eleCrysEta", &IN::eleCrysEta);
  tree->SetBranchAddress("eleCrysPhi", &IN::eleCrysPhi);
  tree->SetBranchAddress("eleCrysIEta", &IN::eleCrysIEta);
  tree->SetBranchAddress("eleCrysIPhi", &IN::eleCrysIPhi);
  tree->SetBranchAddress("eleRegrE", &IN::eleRegrE);
  tree->SetBranchAddress("eleRegrEerr", &IN::eleRegrEerr);
  tree->SetBranchAddress("elePhoRegrE", &IN::elePhoRegrE);
  tree->SetBranchAddress("elePhoRegrEerr", &IN::elePhoRegrEerr);
  tree->SetBranchAddress("eleSeedTime", &IN::eleSeedTime);
  tree->SetBranchAddress("eleRecoFlag", &IN::eleRecoFlag);
  tree->SetBranchAddress("elePos", &IN::elePos);
  tree->SetBranchAddress("eleIsoTrkDR03", &IN::eleIsoTrkDR03);
  tree->SetBranchAddress("eleIsoEcalDR03", &IN::eleIsoEcalDR03);
  tree->SetBranchAddress("eleIsoHcalDR03", &IN::eleIsoHcalDR03);
  tree->SetBranchAddress("eleIsoHcalDR0312", &IN::eleIsoHcalDR0312);
  tree->SetBranchAddress("eleIsoTrkDR04", &IN::eleIsoTrkDR04);
  tree->SetBranchAddress("eleIsoEcalDR04", &IN::eleIsoEcalDR04);
  tree->SetBranchAddress("eleIsoHcalDR04", &IN::eleIsoHcalDR04);
  tree->SetBranchAddress("eleIsoHcalDR0412", &IN::eleIsoHcalDR0412);
  tree->SetBranchAddress("eleModIsoTrk", &IN::eleModIsoTrk);
  tree->SetBranchAddress("eleModIsoEcal", &IN::eleModIsoEcal);
  tree->SetBranchAddress("eleModIsoHcal", &IN::eleModIsoHcal);
  tree->SetBranchAddress("eleMissHits", &IN::eleMissHits);
  tree->SetBranchAddress("eleConvDist", &IN::eleConvDist);
  tree->SetBranchAddress("eleConvDcot", &IN::eleConvDcot);
  tree->SetBranchAddress("eleConvVtxFit", &IN::eleConvVtxFit);
  tree->SetBranchAddress("eleIP3D", &IN::eleIP3D);
  tree->SetBranchAddress("eleIP3DErr", &IN::eleIP3DErr);
  tree->SetBranchAddress("eleIDMVANonTrig", &IN::eleIDMVANonTrig);
  tree->SetBranchAddress("eleIDMVATrig", &IN::eleIDMVATrig);
  tree->SetBranchAddress("elePFChIso03", &IN::elePFChIso03);
  tree->SetBranchAddress("elePFPhoIso03", &IN::elePFPhoIso03);
  tree->SetBranchAddress("elePFNeuIso03", &IN::elePFNeuIso03);
  tree->SetBranchAddress("elePFChIso04", &IN::elePFChIso04);
  tree->SetBranchAddress("elePFPhoIso04", &IN::elePFPhoIso04);
  tree->SetBranchAddress("elePFNeuIso04", &IN::elePFNeuIso04);
  tree->SetBranchAddress("eleESEffSigmaRR_x", &IN::eleESEffSigmaRR_x);
  tree->SetBranchAddress("eleESEffSigmaRR_y", &IN::eleESEffSigmaRR_y);
  tree->SetBranchAddress("eleESEffSigmaRR_z", &IN::eleESEffSigmaRR_z);
  tree->SetBranchAddress("nPho", &IN::nPho);
  tree->SetBranchAddress("phoTrg", &IN::phoTrg);
  tree->SetBranchAddress("phoTrgFilter", &IN::phoTrgFilter);
  tree->SetBranchAddress("phoIsPhoton", &IN::phoIsPhoton);
  tree->SetBranchAddress("phoSCPos_x", &IN::phoSCPos_x);
  tree->SetBranchAddress("phoSCPos_y", &IN::phoSCPos_y);
  tree->SetBranchAddress("phoSCPos_z", &IN::phoSCPos_z);
  tree->SetBranchAddress("phoCaloPos_x", &IN::phoCaloPos_x);
  tree->SetBranchAddress("phoCaloPos_y", &IN::phoCaloPos_y);
  tree->SetBranchAddress("phoCaloPos_z", &IN::phoCaloPos_z);
  tree->SetBranchAddress("phoE", &IN::phoE);
  tree->SetBranchAddress("phoEt", &IN::phoEt);
  tree->SetBranchAddress("phoEta", &IN::phoEta);
  tree->SetBranchAddress("phoVtx_x", &IN::phoVtx_x);
  tree->SetBranchAddress("phoVtx_y", &IN::phoVtx_y);
  tree->SetBranchAddress("phoVtx_z", &IN::phoVtx_z);
  tree->SetBranchAddress("phoPhi", &IN::phoPhi);
  tree->SetBranchAddress("phoEtVtx", &IN::phoEtVtx);
  tree->SetBranchAddress("phoEtaVtx", &IN::phoEtaVtx);
  tree->SetBranchAddress("phoPhiVtx", &IN::phoPhiVtx);
  tree->SetBranchAddress("phoR9", &IN::phoR9);
  tree->SetBranchAddress("phoNClus", &IN::phoNClus);
  tree->SetBranchAddress("phoTrkIsoHollowDR03", &IN::phoTrkIsoHollowDR03);
  tree->SetBranchAddress("phoEcalIsoDR03", &IN::phoEcalIsoDR03);
  tree->SetBranchAddress("phoHcalIsoDR03", &IN::phoHcalIsoDR03);
  tree->SetBranchAddress("phoHcalIsoDR0312", &IN::phoHcalIsoDR0312);
  tree->SetBranchAddress("phoTrkIsoHollowDR04", &IN::phoTrkIsoHollowDR04);
  tree->SetBranchAddress("phoCiCdRtoTrk", &IN::phoCiCdRtoTrk);
  tree->SetBranchAddress("phoEcalIsoDR04", &IN::phoEcalIsoDR04);
  tree->SetBranchAddress("phoHcalIsoDR04", &IN::phoHcalIsoDR04);
  tree->SetBranchAddress("phoHcalIsoDR0412", &IN::phoHcalIsoDR0412);
  tree->SetBranchAddress("phoHoverE", &IN::phoHoverE);
  tree->SetBranchAddress("phoHoverE12", &IN::phoHoverE12);
  tree->SetBranchAddress("phoEleVeto", &IN::phoEleVeto);
  tree->SetBranchAddress("phoSigmaIEtaIEta", &IN::phoSigmaIEtaIEta);
  tree->SetBranchAddress("phoSigmaIEtaIPhi", &IN::phoSigmaIEtaIPhi);
  tree->SetBranchAddress("phoSigmaIPhiIPhi", &IN::phoSigmaIPhiIPhi);
  tree->SetBranchAddress("phoCiCPF4phopfIso03", &IN::phoCiCPF4phopfIso03);
  tree->SetBranchAddress("phoCiCPF4phopfIso04", &IN::phoCiCPF4phopfIso04);
  tree->SetBranchAddress("phoCiCPF4chgpfIso02", &IN::phoCiCPF4chgpfIso02);
  tree->SetBranchAddress("phoCiCPF4chgpfIso03", &IN::phoCiCPF4chgpfIso03);
  tree->SetBranchAddress("phoCiCPF4chgpfIso04", &IN::phoCiCPF4chgpfIso04);
  tree->SetBranchAddress("phoEmax", &IN::phoEmax);
  tree->SetBranchAddress("phoETop", &IN::phoETop);
  tree->SetBranchAddress("phoEBottom", &IN::phoEBottom);
  tree->SetBranchAddress("phoELeft", &IN::phoELeft);
  tree->SetBranchAddress("phoERight", &IN::phoERight);
  tree->SetBranchAddress("phoE2ndMax", &IN::phoE2ndMax);
  tree->SetBranchAddress("phoE3x3", &IN::phoE3x3);
  tree->SetBranchAddress("phoE3x1", &IN::phoE3x1);
  tree->SetBranchAddress("phoE1x3", &IN::phoE1x3);
  tree->SetBranchAddress("phoE5x5", &IN::phoE5x5);
  tree->SetBranchAddress("phoE1x5", &IN::phoE1x5);
  tree->SetBranchAddress("phoE2x2", &IN::phoE2x2);
  tree->SetBranchAddress("phoE2x5Max", &IN::phoE2x5Max);
  tree->SetBranchAddress("phoE2x5Top", &IN::phoE2x5Top);
  tree->SetBranchAddress("phoE2x5Bottom", &IN::phoE2x5Bottom);
  tree->SetBranchAddress("phoE2x5Left", &IN::phoE2x5Left);
  tree->SetBranchAddress("phoE2x5Right", &IN::phoE2x5Right);
  tree->SetBranchAddress("phoSeedE", &IN::phoSeedE);
  tree->SetBranchAddress("phoSeedEta", &IN::phoSeedEta);
  tree->SetBranchAddress("phoSeedPhi", &IN::phoSeedPhi);
  tree->SetBranchAddress("phoCrysEta", &IN::phoCrysEta);
  tree->SetBranchAddress("phoCrysPhi", &IN::phoCrysPhi);
  tree->SetBranchAddress("phoCrysIEta", &IN::phoCrysIEta);
  tree->SetBranchAddress("phoCrysIPhi", &IN::phoCrysIPhi);
  tree->SetBranchAddress("phoPFChIso", &IN::phoPFChIso);
  tree->SetBranchAddress("phoPFPhoIso", &IN::phoPFPhoIso);
  tree->SetBranchAddress("phoPFNeuIso", &IN::phoPFNeuIso);
  tree->SetBranchAddress("phoSCRChIso", &IN::phoSCRChIso);
  tree->SetBranchAddress("phoSCRPhoIso", &IN::phoSCRPhoIso);
  tree->SetBranchAddress("phoSCRNeuIso", &IN::phoSCRNeuIso);
  tree->SetBranchAddress("phoSCRChIso04", &IN::phoSCRChIso04);
  tree->SetBranchAddress("phoSCRPhoIso04", &IN::phoSCRPhoIso04);
  tree->SetBranchAddress("phoSCRNeuIso04", &IN::phoSCRNeuIso04);
  tree->SetBranchAddress("phoRandConeChIso", &IN::phoRandConeChIso);
  tree->SetBranchAddress("phoRandConePhoIso", &IN::phoRandConePhoIso);
  tree->SetBranchAddress("phoRandConeNeuIso", &IN::phoRandConeNeuIso);
  tree->SetBranchAddress("phoRandConeChIso04", &IN::phoRandConeChIso04);
  tree->SetBranchAddress("phoRandConePhoIso04", &IN::phoRandConePhoIso04);
  tree->SetBranchAddress("phoRandConeNeuIso04", &IN::phoRandConeNeuIso04);
  tree->SetBranchAddress("phoRegrE", &IN::phoRegrE);
  tree->SetBranchAddress("phoRegrEerr", &IN::phoRegrEerr);
  tree->SetBranchAddress("phoSeedTime", &IN::phoSeedTime);
  tree->SetBranchAddress("phoSeedDetId1", &IN::phoSeedDetId1);
  tree->SetBranchAddress("phoSeedDetId2", &IN::phoSeedDetId2);
  tree->SetBranchAddress("phoLICTD", &IN::phoLICTD);
  tree->SetBranchAddress("phoRecoFlag", &IN::phoRecoFlag);
  tree->SetBranchAddress("phoPos", &IN::phoPos);
  tree->SetBranchAddress("phoSCE", &IN::phoSCE);
  tree->SetBranchAddress("phoSCRawE", &IN::phoSCRawE);
  tree->SetBranchAddress("phoESEn", &IN::phoESEn);
  tree->SetBranchAddress("phoSCEt", &IN::phoSCEt);
  tree->SetBranchAddress("phoSCEta", &IN::phoSCEta);
  tree->SetBranchAddress("phoSCPhi", &IN::phoSCPhi);
  tree->SetBranchAddress("phoSCEtaWidth", &IN::phoSCEtaWidth);
  tree->SetBranchAddress("phoSCPhiWidth", &IN::phoSCPhiWidth);
  tree->SetBranchAddress("phoSCBrem", &IN::phoSCBrem);
  tree->SetBranchAddress("phoOverlap", &IN::phoOverlap);
  tree->SetBranchAddress("phohasPixelSeed", &IN::phohasPixelSeed);
  tree->SetBranchAddress("pho_hasConvPf", &IN::pho_hasConvPf);
  tree->SetBranchAddress("pho_hasSLConvPf", &IN::pho_hasSLConvPf);
  tree->SetBranchAddress("pho_pfconvVtxZ", &IN::pho_pfconvVtxZ);
  tree->SetBranchAddress("pho_pfconvVtxZErr", &IN::pho_pfconvVtxZErr);
  tree->SetBranchAddress("pho_nSLConv", &IN::pho_nSLConv);
  tree->SetBranchAddress("pho_pfSLConvPos_x", &IN::pho_pfSLConvPos_x);
  tree->SetBranchAddress("pho_pfSLConvPos_y", &IN::pho_pfSLConvPos_y);
  tree->SetBranchAddress("pho_pfSLConvPos_z", &IN::pho_pfSLConvPos_z);
  tree->SetBranchAddress("pho_pfSLConvVtxZ", &IN::pho_pfSLConvVtxZ);
  tree->SetBranchAddress("phoIsConv", &IN::phoIsConv);
  tree->SetBranchAddress("phoNConv", &IN::phoNConv);
  tree->SetBranchAddress("phoConvInvMass", &IN::phoConvInvMass);
  tree->SetBranchAddress("phoConvCotTheta", &IN::phoConvCotTheta);
  tree->SetBranchAddress("phoConvEoverP", &IN::phoConvEoverP);
  tree->SetBranchAddress("phoConvZofPVfromTrks", &IN::phoConvZofPVfromTrks);
  tree->SetBranchAddress("phoConvMinDist", &IN::phoConvMinDist);
  tree->SetBranchAddress("phoConvdPhiAtVtx", &IN::phoConvdPhiAtVtx);
  tree->SetBranchAddress("phoConvdPhiAtCalo", &IN::phoConvdPhiAtCalo);
  tree->SetBranchAddress("phoConvdEtaAtCalo", &IN::phoConvdEtaAtCalo);
  tree->SetBranchAddress("phoConvTrkd0_x", &IN::phoConvTrkd0_x);
  tree->SetBranchAddress("phoConvTrkd0_y", &IN::phoConvTrkd0_y);
  tree->SetBranchAddress("phoConvTrkPin_x", &IN::phoConvTrkPin_x);
  tree->SetBranchAddress("phoConvTrkPin_y", &IN::phoConvTrkPin_y);
  tree->SetBranchAddress("phoConvTrkPout_x", &IN::phoConvTrkPout_x);
  tree->SetBranchAddress("phoConvTrkPout_y", &IN::phoConvTrkPout_y);
  tree->SetBranchAddress("phoConvTrkdz_x", &IN::phoConvTrkdz_x);
  tree->SetBranchAddress("phoConvTrkdz_y", &IN::phoConvTrkdz_y);
  tree->SetBranchAddress("phoConvTrkdzErr_x", &IN::phoConvTrkdzErr_x);
  tree->SetBranchAddress("phoConvTrkdzErr_y", &IN::phoConvTrkdzErr_y);
  tree->SetBranchAddress("phoConvChi2", &IN::phoConvChi2);
  tree->SetBranchAddress("phoConvChi2Prob", &IN::phoConvChi2Prob);
  tree->SetBranchAddress("phoConvNTrks", &IN::phoConvNTrks);
  tree->SetBranchAddress("phoConvCharge1", &IN::phoConvCharge1);
  tree->SetBranchAddress("phoConvCharge2", &IN::phoConvCharge2);
  tree->SetBranchAddress("phoConvValidVtx", &IN::phoConvValidVtx);
  tree->SetBranchAddress("phoConvLikeLihood", &IN::phoConvLikeLihood);
  tree->SetBranchAddress("phoConvP4_0", &IN::phoConvP4_0);
  tree->SetBranchAddress("phoConvP4_1", &IN::phoConvP4_1);
  tree->SetBranchAddress("phoConvP4_2", &IN::phoConvP4_2);
  tree->SetBranchAddress("phoConvP4_3", &IN::phoConvP4_3);
  tree->SetBranchAddress("phoConvVtx_x", &IN::phoConvVtx_x);
  tree->SetBranchAddress("phoConvVtx_y", &IN::phoConvVtx_y);
  tree->SetBranchAddress("phoConvVtx_z", &IN::phoConvVtx_z);
  tree->SetBranchAddress("phoConvVtxErr_x", &IN::phoConvVtxErr_x);
  tree->SetBranchAddress("phoConvVtxErr_y", &IN::phoConvVtxErr_y);
  tree->SetBranchAddress("phoConvVtxErr_z", &IN::phoConvVtxErr_z);
  tree->SetBranchAddress("phoConvPairMomentum_x", &IN::phoConvPairMomentum_x);
  tree->SetBranchAddress("phoConvPairMomentum_y", &IN::phoConvPairMomentum_y);
  tree->SetBranchAddress("phoConvPairMomentum_z", &IN::phoConvPairMomentum_z);
  tree->SetBranchAddress("phoConvRefittedMomentum_x", &IN::phoConvRefittedMomentum_x);
  tree->SetBranchAddress("phoConvRefittedMomentum_y", &IN::phoConvRefittedMomentum_y);
  tree->SetBranchAddress("phoConvRefittedMomentum_z", &IN::phoConvRefittedMomentum_z);
  tree->SetBranchAddress("SingleLegConv", &IN::SingleLegConv);
  tree->SetBranchAddress("phoPFConvVtx_x", &IN::phoPFConvVtx_x);
  tree->SetBranchAddress("phoPFConvVtx_y", &IN::phoPFConvVtx_y);
  tree->SetBranchAddress("phoPFConvVtx_z", &IN::phoPFConvVtx_z);
  tree->SetBranchAddress("phoPFConvMom_x", &IN::phoPFConvMom_x);
  tree->SetBranchAddress("phoPFConvMom_y", &IN::phoPFConvMom_y);
  tree->SetBranchAddress("phoPFConvMom_z", &IN::phoPFConvMom_z);
  tree->SetBranchAddress("phoESEffSigmaRR_x", &IN::phoESEffSigmaRR_x);
  tree->SetBranchAddress("phoESEffSigmaRR_y", &IN::phoESEffSigmaRR_y);
  tree->SetBranchAddress("phoESEffSigmaRR_z", &IN::phoESEffSigmaRR_z);
  tree->SetBranchAddress("nMu", &IN::nMu);
  tree->SetBranchAddress("muTrg", &IN::muTrg);
  tree->SetBranchAddress("muEta", &IN::muEta);
  tree->SetBranchAddress("muPhi", &IN::muPhi);
  tree->SetBranchAddress("muCharge", &IN::muCharge);
  tree->SetBranchAddress("muPt", &IN::muPt);
  tree->SetBranchAddress("muPz", &IN::muPz);
  tree->SetBranchAddress("muVtx_x", &IN::muVtx_x);
  tree->SetBranchAddress("muVtx_y", &IN::muVtx_y);
  tree->SetBranchAddress("muVtx_z", &IN::muVtx_z);
  tree->SetBranchAddress("muVtxGlb_x", &IN::muVtxGlb_x);
  tree->SetBranchAddress("muVtxGlb_y", &IN::muVtxGlb_y);
  tree->SetBranchAddress("muVtxGlb_z", &IN::muVtxGlb_z);
  tree->SetBranchAddress("mucktPt", &IN::mucktPt);
  tree->SetBranchAddress("mucktPtErr", &IN::mucktPtErr);
  tree->SetBranchAddress("mucktEta", &IN::mucktEta);
  tree->SetBranchAddress("mucktPhi", &IN::mucktPhi);
  tree->SetBranchAddress("mucktdxy", &IN::mucktdxy);
  tree->SetBranchAddress("mucktdz", &IN::mucktdz);
  tree->SetBranchAddress("muIsoTrk", &IN::muIsoTrk);
  tree->SetBranchAddress("muIsoCalo", &IN::muIsoCalo);
  tree->SetBranchAddress("muIsoEcal", &IN::muIsoEcal);
  tree->SetBranchAddress("muIsoHcal", &IN::muIsoHcal);
  tree->SetBranchAddress("muChi2NDF", &IN::muChi2NDF);
  tree->SetBranchAddress("muInnerChi2NDF", &IN::muInnerChi2NDF);
  tree->SetBranchAddress("muPFIsoR04_CH", &IN::muPFIsoR04_CH);
  tree->SetBranchAddress("muPFIsoR04_NH", &IN::muPFIsoR04_NH);
  tree->SetBranchAddress("muPFIsoR04_Pho", &IN::muPFIsoR04_Pho);
  tree->SetBranchAddress("muPFIsoR04_PU", &IN::muPFIsoR04_PU);
  tree->SetBranchAddress("muPFIsoR04_CPart", &IN::muPFIsoR04_CPart);
  tree->SetBranchAddress("muPFIsoR04_NHHT", &IN::muPFIsoR04_NHHT);
  tree->SetBranchAddress("muPFIsoR04_PhoHT", &IN::muPFIsoR04_PhoHT);
  tree->SetBranchAddress("muPFIsoR03_CH", &IN::muPFIsoR03_CH);
  tree->SetBranchAddress("muPFIsoR03_NH", &IN::muPFIsoR03_NH);
  tree->SetBranchAddress("muPFIsoR03_Pho", &IN::muPFIsoR03_Pho);
  tree->SetBranchAddress("muPFIsoR03_PU", &IN::muPFIsoR03_PU);
  tree->SetBranchAddress("muPFIsoR03_CPart", &IN::muPFIsoR03_CPart);
  tree->SetBranchAddress("muPFIsoR03_NHHT", &IN::muPFIsoR03_NHHT);
  tree->SetBranchAddress("muPFIsoR03_PhoHT", &IN::muPFIsoR03_PhoHT);
  tree->SetBranchAddress("muType", &IN::muType);
  tree->SetBranchAddress("muD0", &IN::muD0);
  tree->SetBranchAddress("muDz", &IN::muDz);
  tree->SetBranchAddress("muD0GV", &IN::muD0GV);
  tree->SetBranchAddress("muDzGV", &IN::muDzGV);
  tree->SetBranchAddress("muD0Vtx", &IN::muD0Vtx);
  tree->SetBranchAddress("muDzVtx", &IN::muDzVtx);
  tree->SetBranchAddress("muInnerD0", &IN::muInnerD0);
  tree->SetBranchAddress("muInnerDz", &IN::muInnerDz);
  tree->SetBranchAddress("muInnerD0GV", &IN::muInnerD0GV);
  tree->SetBranchAddress("muInnerDzGV", &IN::muInnerDzGV);
  tree->SetBranchAddress("muInnerPt", &IN::muInnerPt);
  tree->SetBranchAddress("muInnerPtErr", &IN::muInnerPtErr);
  tree->SetBranchAddress("muNumberOfValidTrkLayers", &IN::muNumberOfValidTrkLayers);
  tree->SetBranchAddress("muNumberOfValidTrkHits", &IN::muNumberOfValidTrkHits);
  tree->SetBranchAddress("muNumberOfValidPixelLayers", &IN::muNumberOfValidPixelLayers);
  tree->SetBranchAddress("muNumberOfValidPixelHits", &IN::muNumberOfValidPixelHits);
  tree->SetBranchAddress("muNumberOfValidMuonHits", &IN::muNumberOfValidMuonHits);
  tree->SetBranchAddress("muStations", &IN::muStations);
  tree->SetBranchAddress("muChambers", &IN::muChambers);
  tree->SetBranchAddress("muIP3D", &IN::muIP3D);
  tree->SetBranchAddress("muIP3DErr", &IN::muIP3DErr);
  tree->SetBranchAddress("nTau", &IN::nTau);
  tree->SetBranchAddress("tauDecayModeFinding", &IN::tauDecayModeFinding);
  tree->SetBranchAddress("tauAgainstElectronLooseMVA3", &IN::tauAgainstElectronLooseMVA3);
  tree->SetBranchAddress("tauAgainstElectronMediumMVA3", &IN::tauAgainstElectronMediumMVA3);
  tree->SetBranchAddress("tauAgainstElectronTightMVA3", &IN::tauAgainstElectronTightMVA3);
  tree->SetBranchAddress("tauAgainstElectronVTightMVA3", &IN::tauAgainstElectronVTightMVA3);
  tree->SetBranchAddress("tauAgainstElectronDeadECAL", &IN::tauAgainstElectronDeadECAL);
  tree->SetBranchAddress("tauAgainstMuonLoose2", &IN::tauAgainstMuonLoose2);
  tree->SetBranchAddress("tauAgainstMuonMedium2", &IN::tauAgainstMuonMedium2);
  tree->SetBranchAddress("tauAgainstMuonTight2", &IN::tauAgainstMuonTight2);
  tree->SetBranchAddress("tauCombinedIsolationDeltaBetaCorrRaw3Hits", &IN::tauCombinedIsolationDeltaBetaCorrRaw3Hits);
  tree->SetBranchAddress("tauLooseCombinedIsolationDeltaBetaCorr3Hits", &IN::tauLooseCombinedIsolationDeltaBetaCorr3Hits);
  tree->SetBranchAddress("tauMediumCombinedIsolationDeltaBetaCorr3Hits", &IN::tauMediumCombinedIsolationDeltaBetaCorr3Hits);
  tree->SetBranchAddress("tauTightCombinedIsolationDeltaBetaCorr3Hits", &IN::tauTightCombinedIsolationDeltaBetaCorr3Hits);
  tree->SetBranchAddress("tauEta", &IN::tauEta);
  tree->SetBranchAddress("tauPhi", &IN::tauPhi);
  tree->SetBranchAddress("tauPt", &IN::tauPt);
  tree->SetBranchAddress("tauEt", &IN::tauEt);
  tree->SetBranchAddress("tauCharge", &IN::tauCharge);
  tree->SetBranchAddress("tauDecayMode", &IN::tauDecayMode);
  tree->SetBranchAddress("tauEMFraction", &IN::tauEMFraction);
  tree->SetBranchAddress("tauHCAL3x3OverPLead", &IN::tauHCAL3x3OverPLead);
  tree->SetBranchAddress("tauHCALMaxOverPLead", &IN::tauHCALMaxOverPLead);
  tree->SetBranchAddress("tauHCALTotOverPLead", &IN::tauHCALTotOverPLead);
  tree->SetBranchAddress("tauIsolationPFChargedHadrCandsPtSum", &IN::tauIsolationPFChargedHadrCandsPtSum);
  tree->SetBranchAddress("tauIsolationPFGammaCandsEtSum", &IN::tauIsolationPFGammaCandsEtSum);
  tree->SetBranchAddress("tauLeadPFChargedHadrCandsignedSipt", &IN::tauLeadPFChargedHadrCandsignedSipt);
  tree->SetBranchAddress("tauLeadChargedHadronExists", &IN::tauLeadChargedHadronExists);
  tree->SetBranchAddress("tauLeadChargedHadronEta", &IN::tauLeadChargedHadronEta);
  tree->SetBranchAddress("tauLeadChargedHadronPhi", &IN::tauLeadChargedHadronPhi);
  tree->SetBranchAddress("tauLeadChargedHadronPt", &IN::tauLeadChargedHadronPt);
  tree->SetBranchAddress("rho25", &IN::rho25);
  tree->SetBranchAddress("rho25_neu", &IN::rho25_neu);
  tree->SetBranchAddress("rho25_muPFiso", &IN::rho25_muPFiso);
  tree->SetBranchAddress("rho25_elePFiso", &IN::rho25_elePFiso);
  tree->SetBranchAddress("rho2011", &IN::rho2011);
  tree->SetBranchAddress("rho2012", &IN::rho2012);
  tree->SetBranchAddress("QGTag_MLP", &IN::QGTag_MLP);
  tree->SetBranchAddress("QGTag_likelihood", &IN::QGTag_likelihood);
  tree->SetBranchAddress("nCA8Jet", &IN::nCA8Jet);
  tree->SetBranchAddress("CA8JetPt", &IN::CA8JetPt);
  tree->SetBranchAddress("CA8JetEta", &IN::CA8JetEta);
  tree->SetBranchAddress("CA8JetPhi", &IN::CA8JetPhi);
  tree->SetBranchAddress("CA8JetMass", &IN::CA8JetMass);
  tree->SetBranchAddress("CA8JetArea", &IN::CA8JetArea);
  tree->SetBranchAddress("CA8Jet_tau1", &IN::CA8Jet_tau1);
  tree->SetBranchAddress("CA8Jet_tau2", &IN::CA8Jet_tau2);
  tree->SetBranchAddress("CA8Jet_tau3", &IN::CA8Jet_tau3);
  tree->SetBranchAddress("CA8JetCHF", &IN::CA8JetCHF);
  tree->SetBranchAddress("CA8JetNHF", &IN::CA8JetNHF);
  tree->SetBranchAddress("CA8JetCEF", &IN::CA8JetCEF);
  tree->SetBranchAddress("CA8JetNEF", &IN::CA8JetNEF);
  tree->SetBranchAddress("CA8JetNCH", &IN::CA8JetNCH);
  tree->SetBranchAddress("CA8Jetnconstituents", &IN::CA8Jetnconstituents);
  tree->SetBranchAddress("CA8prunedJetMass", &IN::CA8prunedJetMass);
  tree->SetBranchAddress("CA8prunedJet_nSubJets", &IN::CA8prunedJet_nSubJets);
  tree->SetBranchAddress("CA8prunedJet_SubjetPt", &IN::CA8prunedJet_SubjetPt);
  tree->SetBranchAddress("CA8prunedJet_SubjetEta", &IN::CA8prunedJet_SubjetEta);
  tree->SetBranchAddress("CA8prunedJet_SubjetPhi", &IN::CA8prunedJet_SubjetPhi);
  tree->SetBranchAddress("CA8prunedJet_SubjetMass", &IN::CA8prunedJet_SubjetMass);
  tree->SetBranchAddress("nJet", &IN::nJet);
  tree->SetBranchAddress("jetTrg", &IN::jetTrg);
  tree->SetBranchAddress("jetEn", &IN::jetEn);
  tree->SetBranchAddress("jetPt", &IN::jetPt);
  tree->SetBranchAddress("jetEta", &IN::jetEta);
  tree->SetBranchAddress("jetPhi", &IN::jetPhi);
  tree->SetBranchAddress("jetCharge", &IN::jetCharge);
  tree->SetBranchAddress("jetEt", &IN::jetEt);
  tree->SetBranchAddress("jetRawPt", &IN::jetRawPt);
  tree->SetBranchAddress("jetRawEn", &IN::jetRawEn);
  tree->SetBranchAddress("jetArea", &IN::jetArea);
  tree->SetBranchAddress("jetCHF", &IN::jetCHF);
  tree->SetBranchAddress("jetNHF", &IN::jetNHF);
  tree->SetBranchAddress("jetCEF", &IN::jetCEF);
  tree->SetBranchAddress("jetNEF", &IN::jetNEF);
  tree->SetBranchAddress("jetNCH", &IN::jetNCH);
  tree->SetBranchAddress("jetHFHAE", &IN::jetHFHAE);
  tree->SetBranchAddress("jetHFEME", &IN::jetHFEME);
  tree->SetBranchAddress("jetNConstituents", &IN::jetNConstituents);
  tree->SetBranchAddress("jetCombinedSecondaryVtxBJetTags", &IN::jetCombinedSecondaryVtxBJetTags);
  tree->SetBranchAddress("jetCombinedSecondaryVtxMVABJetTags", &IN::jetCombinedSecondaryVtxMVABJetTags);
  tree->SetBranchAddress("jetJetProbabilityBJetTags", &IN::jetJetProbabilityBJetTags);
  tree->SetBranchAddress("jetJetBProbabilityBJetTags", &IN::jetJetBProbabilityBJetTags);
  tree->SetBranchAddress("jetBetaStar", &IN::jetBetaStar);
  tree->SetBranchAddress("jetPFLooseId", &IN::jetPFLooseId);
  tree->SetBranchAddress("jetDRMean", &IN::jetDRMean);
  tree->SetBranchAddress("jetDR2Mean", &IN::jetDR2Mean);
  tree->SetBranchAddress("jetDZ", &IN::jetDZ);
  tree->SetBranchAddress("jetFrac01", &IN::jetFrac01);
  tree->SetBranchAddress("jetFrac02", &IN::jetFrac02);
  tree->SetBranchAddress("jetFrac03", &IN::jetFrac03);
  tree->SetBranchAddress("jetFrac04", &IN::jetFrac04);
  tree->SetBranchAddress("jetFrac05", &IN::jetFrac05);
  tree->SetBranchAddress("jetFrac06", &IN::jetFrac06);
  tree->SetBranchAddress("jetFrac07", &IN::jetFrac07);
  tree->SetBranchAddress("jetBeta", &IN::jetBeta);
  tree->SetBranchAddress("jetBetaStarCMG", &IN::jetBetaStarCMG);
  tree->SetBranchAddress("jetBetaStarClassic", &IN::jetBetaStarClassic);
  tree->SetBranchAddress("jetBetaExt", &IN::jetBetaExt);
  tree->SetBranchAddress("jetBetaStarCMGExt", &IN::jetBetaStarCMGExt);
  tree->SetBranchAddress("jetBetaStarClassicExt", &IN::jetBetaStarClassicExt);
  tree->SetBranchAddress("jetNNeutrals", &IN::jetNNeutrals);
  tree->SetBranchAddress("jetNCharged", &IN::jetNCharged);
  tree->SetBranchAddress("jetMVAs", &IN::jetMVAs);
  tree->SetBranchAddress("jetWPLevels", &IN::jetWPLevels);
  tree->SetBranchAddress("jetMVAsExt_simple", &IN::jetMVAsExt_simple);
  tree->SetBranchAddress("jetWPLevelsExt_simple", &IN::jetWPLevelsExt_simple);
  tree->SetBranchAddress("jetMVAsExt_full", &IN::jetMVAsExt_full);
  tree->SetBranchAddress("jetWPLevelsExt_full", &IN::jetWPLevelsExt_full);
  tree->SetBranchAddress("jetMVAsExt_cutBased", &IN::jetMVAsExt_cutBased);
  tree->SetBranchAddress("jetWPLevelsExt_cutBased", &IN::jetWPLevelsExt_cutBased);
  tree->SetBranchAddress("jetMVAsExt_philv1", &IN::jetMVAsExt_philv1);
  tree->SetBranchAddress("jetWPLevelsExt_philv1", &IN::jetWPLevelsExt_philv1);
  tree->SetBranchAddress("jetMt", &IN::jetMt);
  tree->SetBranchAddress("jetJECUnc", &IN::jetJECUnc);
  tree->SetBranchAddress("jetLeadTrackPt", &IN::jetLeadTrackPt);
  tree->SetBranchAddress("jetVtxPt", &IN::jetVtxPt);
  tree->SetBranchAddress("jetVtxMass", &IN::jetVtxMass);
  tree->SetBranchAddress("jetVtx3dL", &IN::jetVtx3dL);
  tree->SetBranchAddress("jetVtx3deL", &IN::jetVtx3deL);
  tree->SetBranchAddress("jetSoftLeptPt", &IN::jetSoftLeptPt);
  tree->SetBranchAddress("jetSoftLeptPtRel", &IN::jetSoftLeptPtRel);
  tree->SetBranchAddress("jetSoftLeptdR", &IN::jetSoftLeptdR);
  tree->SetBranchAddress("jetSoftLeptIdlooseMu", &IN::jetSoftLeptIdlooseMu);
  tree->SetBranchAddress("jetSoftLeptIdEle95", &IN::jetSoftLeptIdEle95);
  tree->SetBranchAddress("jetDPhiMETJet", &IN::jetDPhiMETJet);
  tree->SetBranchAddress("jetPuJetIdL", &IN::jetPuJetIdL);
  tree->SetBranchAddress("jetPuJetIdM", &IN::jetPuJetIdM);
  tree->SetBranchAddress("jetPuJetIdT", &IN::jetPuJetIdT);
  tree->SetBranchAddress("nConv", &IN::nConv);
  tree->SetBranchAddress("convP4_x", &IN::convP4_x);
  tree->SetBranchAddress("convP4_y", &IN::convP4_y);
  tree->SetBranchAddress("convP4_z", &IN::convP4_z);
  tree->SetBranchAddress("convP4_E", &IN::convP4_E);
  tree->SetBranchAddress("convVtx_x", &IN::convVtx_x);
  tree->SetBranchAddress("convVtx_y", &IN::convVtx_y);
  tree->SetBranchAddress("convVtx_z", &IN::convVtx_z);
  tree->SetBranchAddress("convVtxErr_x", &IN::convVtxErr_x);
  tree->SetBranchAddress("convVtxErr_y", &IN::convVtxErr_y);
  tree->SetBranchAddress("convVtxErr_z", &IN::convVtxErr_z);
  tree->SetBranchAddress("convPairMomentum_x", &IN::convPairMomentum_x);
  tree->SetBranchAddress("convPairMomentum_y", &IN::convPairMomentum_y);
  tree->SetBranchAddress("convPairMomentum_z", &IN::convPairMomentum_z);
  tree->SetBranchAddress("convRefittedMomentum_x", &IN::convRefittedMomentum_x);
  tree->SetBranchAddress("convRefittedMomentum_y", &IN::convRefittedMomentum_y);
  tree->SetBranchAddress("convRefittedMomentum_z", &IN::convRefittedMomentum_z);
  tree->SetBranchAddress("convNTracks", &IN::convNTracks);
  tree->SetBranchAddress("convPairInvMass", &IN::convPairInvMass);
  tree->SetBranchAddress("convPairCotThetaSep", &IN::convPairCotThetaSep);
  tree->SetBranchAddress("convEoverP", &IN::convEoverP);
  tree->SetBranchAddress("convDistOfMinApproach", &IN::convDistOfMinApproach);
  tree->SetBranchAddress("convDPhiTrksAtVtx", &IN::convDPhiTrksAtVtx);
  tree->SetBranchAddress("convDPhiTrksAtEcal", &IN::convDPhiTrksAtEcal);
  tree->SetBranchAddress("convDEtaTrksAtEcal", &IN::convDEtaTrksAtEcal);
  tree->SetBranchAddress("convDxy", &IN::convDxy);
  tree->SetBranchAddress("convDz", &IN::convDz);
  tree->SetBranchAddress("convLxy", &IN::convLxy);
  tree->SetBranchAddress("convLz", &IN::convLz);
  tree->SetBranchAddress("convZofPrimVtxFromTrks", &IN::convZofPrimVtxFromTrks);
  tree->SetBranchAddress("convNHitsBeforeVtx_0", &IN::convNHitsBeforeVtx_0);
  tree->SetBranchAddress("convNHitsBeforeVtx_1", &IN::convNHitsBeforeVtx_1);
  tree->SetBranchAddress("convNSharedHits", &IN::convNSharedHits);
  tree->SetBranchAddress("convValidVtx", &IN::convValidVtx);
  tree->SetBranchAddress("convMVALikelihood", &IN::convMVALikelihood);
  tree->SetBranchAddress("convChi2", &IN::convChi2);
  tree->SetBranchAddress("convChi2Probability", &IN::convChi2Probability);
  tree->SetBranchAddress("convTk1Dz", &IN::convTk1Dz);
  tree->SetBranchAddress("convTk2Dz", &IN::convTk2Dz);
  tree->SetBranchAddress("convTk1DzErr", &IN::convTk1DzErr);
  tree->SetBranchAddress("convTk2DzErr", &IN::convTk2DzErr);
  tree->SetBranchAddress("convCh1Ch2", &IN::convCh1Ch2);
  tree->SetBranchAddress("convTk1D0", &IN::convTk1D0);
  tree->SetBranchAddress("convTk1Pout", &IN::convTk1Pout);
  tree->SetBranchAddress("convTk1Pin", &IN::convTk1Pin);
  tree->SetBranchAddress("convTk2D0", &IN::convTk2D0);
  tree->SetBranchAddress("convTk2Pout", &IN::convTk2Pout);
  tree->SetBranchAddress("convTk2Pin", &IN::convTk2Pin);
};

void InitOUTTree( TTree * tree ) {
  tree->Branch("nHLT", &OUT::nHLT, "nHLT/I");
  tree->Branch("run", &OUT::run, "run/I");
  tree->Branch("event", &OUT::event, "event/L");
  tree->Branch("lumis", &OUT::lumis, "lumis/I");
  tree->Branch("isData", &OUT::isData, "isData/O");
  tree->Branch("HLT", &OUT::HLT, "HLT[nHLT]/I");
  tree->Branch("HLTIndex", &OUT::HLTIndex, "HLTIndex[70]/I");
  tree->Branch("bspotPos", &OUT::bspotPos, "bspotPos[3]/F");
  tree->Branch("nVtx", &OUT::nVtx, "nVtx/I");
  tree->Branch("vtx_x", &OUT::vtx_x);
  tree->Branch("vtx_y", &OUT::vtx_y);
  tree->Branch("vtx_z", &OUT::vtx_z);
  tree->Branch("IsVtxGood", &OUT::IsVtxGood, "IsVtxGood/I");
  tree->Branch("nGoodVtx", &OUT::nGoodVtx, "nGoodVtx/I");
  tree->Branch("nVtxBS", &OUT::nVtxBS, "nVtxBS/I");
  tree->Branch("vtxbs_x", &OUT::vtxbs_x);
  tree->Branch("vtxbs_y", &OUT::vtxbs_y);
  tree->Branch("vtxbs_z", &OUT::vtxbs_z);
  tree->Branch("pfMET", &OUT::pfMET, "pfMET/F");
  tree->Branch("pfMETPhi", &OUT::pfMETPhi, "pfMETPhi/F");
  tree->Branch("pfMETsumEt", &OUT::pfMETsumEt, "pfMETsumEt/F");
  tree->Branch("pfMETmEtSig", &OUT::pfMETmEtSig, "pfMETmEtSig/F");
  tree->Branch("pfMETSig", &OUT::pfMETSig, "pfMETSig/F");
  tree->Branch("pfType01MET", &OUT::pfType01MET, "pfType01MET/F");
  tree->Branch("pfType01METPhi", &OUT::pfType01METPhi, "pfType01METPhi/F");
  tree->Branch("pfType01METsumEt", &OUT::pfType01METsumEt, "pfType01METsumEt/F");
  tree->Branch("pfType01METmEtSig", &OUT::pfType01METmEtSig, "pfType01METmEtSig/F");
  tree->Branch("pfType01METSig", &OUT::pfType01METSig, "pfType01METSig/F");
  tree->Branch("recoPfMET", &OUT::recoPfMET, "recoPfMET/F");
  tree->Branch("recoPfMETPhi", &OUT::recoPfMETPhi, "recoPfMETPhi/F");
  tree->Branch("recoPfMETsumEt", &OUT::recoPfMETsumEt, "recoPfMETsumEt/F");
  tree->Branch("recoPfMETmEtSig", &OUT::recoPfMETmEtSig, "recoPfMETmEtSig/F");
  tree->Branch("recoPfMETSig", &OUT::recoPfMETSig, "recoPfMETSig/F");
  tree->Branch("trkMETxPV", &OUT::trkMETxPV, "trkMETxPV/F");
  tree->Branch("trkMETyPV", &OUT::trkMETyPV, "trkMETyPV/F");
  tree->Branch("trkMETPhiPV", &OUT::trkMETPhiPV, "trkMETPhiPV/F");
  tree->Branch("trkMETPV", &OUT::trkMETPV, "trkMETPV/F");
  tree->Branch("trkMETx", &OUT::trkMETx);
  tree->Branch("trkMETy", &OUT::trkMETy);
  tree->Branch("trkMETPhi", &OUT::trkMETPhi);
  tree->Branch("trkMET", &OUT::trkMET);
  tree->Branch("metFilters", &OUT::metFilters, "metFilters[10]/I");
  tree->Branch("nEle", &OUT::nEle, "nEle/I");
  tree->Branch("eleTrg", &OUT::eleTrg);
  tree->Branch("eleClass", &OUT::eleClass);
  tree->Branch("eleIsEcalDriven", &OUT::eleIsEcalDriven);
  tree->Branch("eleCharge", &OUT::eleCharge);
  tree->Branch("eleChargeConsistent", &OUT::eleChargeConsistent);
  tree->Branch("eleEn", &OUT::eleEn);
  tree->Branch("eleEcalEn", &OUT::eleEcalEn);
  tree->Branch("eleSCRawEn", &OUT::eleSCRawEn);
  tree->Branch("eleSCEn", &OUT::eleSCEn);
  tree->Branch("eleESEn", &OUT::eleESEn);
  tree->Branch("elePt", &OUT::elePt);
  tree->Branch("eleEta", &OUT::eleEta);
  tree->Branch("elePhi", &OUT::elePhi);
  tree->Branch("eleR9", &OUT::eleR9);
  tree->Branch("eleEtaVtx", &OUT::eleEtaVtx);
  tree->Branch("elePhiVtx", &OUT::elePhiVtx);
  tree->Branch("eleEtVtx", &OUT::eleEtVtx);
  tree->Branch("eleSCEta", &OUT::eleSCEta);
  tree->Branch("eleSCPhi", &OUT::eleSCPhi);
  tree->Branch("eleSCEtaWidth", &OUT::eleSCEtaWidth);
  tree->Branch("eleSCPhiWidth", &OUT::eleSCPhiWidth);
  tree->Branch("eleVtx_x", &OUT::eleVtx_x);
  tree->Branch("eleVtx_y", &OUT::eleVtx_y);
  tree->Branch("eleVtx_z", &OUT::eleVtx_z);
  tree->Branch("eleD0", &OUT::eleD0);
  tree->Branch("eleDz", &OUT::eleDz);
  tree->Branch("eleD0GV", &OUT::eleD0GV);
  tree->Branch("eleDzGV", &OUT::eleDzGV);
  tree->Branch("eleD0Vtx", &OUT::eleD0Vtx);
  tree->Branch("eleDzVtx", &OUT::eleDzVtx);
  tree->Branch("eleHoverE", &OUT::eleHoverE);
  tree->Branch("eleHoverE12", &OUT::eleHoverE12);
  tree->Branch("eleEoverP", &OUT::eleEoverP);
  tree->Branch("elePin", &OUT::elePin);
  tree->Branch("elePout", &OUT::elePout);
  tree->Branch("eleTrkMomErr", &OUT::eleTrkMomErr);
  tree->Branch("eleBrem", &OUT::eleBrem);
  tree->Branch("eledEtaAtVtx", &OUT::eledEtaAtVtx);
  tree->Branch("eledPhiAtVtx", &OUT::eledPhiAtVtx);
  tree->Branch("eleSigmaIEtaIEta", &OUT::eleSigmaIEtaIEta);
  tree->Branch("eleSigmaIEtaIPhi", &OUT::eleSigmaIEtaIPhi);
  tree->Branch("eleSigmaIPhiIPhi", &OUT::eleSigmaIPhiIPhi);
  tree->Branch("eleEmax", &OUT::eleEmax);
  tree->Branch("eleE2ndMax", &OUT::eleE2ndMax);
  tree->Branch("eleETop", &OUT::eleETop);
  tree->Branch("eleEBottom", &OUT::eleEBottom);
  tree->Branch("eleELeft", &OUT::eleELeft);
  tree->Branch("eleERight", &OUT::eleERight);
  tree->Branch("eleE1x5", &OUT::eleE1x5);
  tree->Branch("eleE3x3", &OUT::eleE3x3);
  tree->Branch("eleE5x5", &OUT::eleE5x5);
  tree->Branch("eleE2x5Max", &OUT::eleE2x5Max);
  tree->Branch("eleE2x5Top", &OUT::eleE2x5Top);
  tree->Branch("eleE2x5Bottom", &OUT::eleE2x5Bottom);
  tree->Branch("eleE2x5Left", &OUT::eleE2x5Left);
  tree->Branch("eleE2x5Right", &OUT::eleE2x5Right);
  tree->Branch("eleSeedEta", &OUT::eleSeedEta);
  tree->Branch("eleSeedE", &OUT::eleSeedE);
  tree->Branch("eleSeedPhi", &OUT::eleSeedPhi);
  tree->Branch("eleCrysEta", &OUT::eleCrysEta);
  tree->Branch("eleCrysPhi", &OUT::eleCrysPhi);
  tree->Branch("eleCrysIEta", &OUT::eleCrysIEta);
  tree->Branch("eleCrysIPhi", &OUT::eleCrysIPhi);
  tree->Branch("eleRegrE", &OUT::eleRegrE);
  tree->Branch("eleRegrEerr", &OUT::eleRegrEerr);
  tree->Branch("elePhoRegrE", &OUT::elePhoRegrE);
  tree->Branch("elePhoRegrEerr", &OUT::elePhoRegrEerr);
  tree->Branch("eleSeedTime", &OUT::eleSeedTime);
  tree->Branch("eleRecoFlag", &OUT::eleRecoFlag);
  tree->Branch("elePos", &OUT::elePos);
  tree->Branch("eleIsoTrkDR03", &OUT::eleIsoTrkDR03);
  tree->Branch("eleIsoEcalDR03", &OUT::eleIsoEcalDR03);
  tree->Branch("eleIsoHcalDR03", &OUT::eleIsoHcalDR03);
  tree->Branch("eleIsoHcalDR0312", &OUT::eleIsoHcalDR0312);
  tree->Branch("eleIsoTrkDR04", &OUT::eleIsoTrkDR04);
  tree->Branch("eleIsoEcalDR04", &OUT::eleIsoEcalDR04);
  tree->Branch("eleIsoHcalDR04", &OUT::eleIsoHcalDR04);
  tree->Branch("eleIsoHcalDR0412", &OUT::eleIsoHcalDR0412);
  tree->Branch("eleModIsoTrk", &OUT::eleModIsoTrk);
  tree->Branch("eleModIsoEcal", &OUT::eleModIsoEcal);
  tree->Branch("eleModIsoHcal", &OUT::eleModIsoHcal);
  tree->Branch("eleMissHits", &OUT::eleMissHits);
  tree->Branch("eleConvDist", &OUT::eleConvDist);
  tree->Branch("eleConvDcot", &OUT::eleConvDcot);
  tree->Branch("eleConvVtxFit", &OUT::eleConvVtxFit);
  tree->Branch("eleIP3D", &OUT::eleIP3D);
  tree->Branch("eleIP3DErr", &OUT::eleIP3DErr);
  tree->Branch("eleIDMVANonTrig", &OUT::eleIDMVANonTrig);
  tree->Branch("eleIDMVATrig", &OUT::eleIDMVATrig);
  tree->Branch("elePFChIso03", &OUT::elePFChIso03);
  tree->Branch("elePFPhoIso03", &OUT::elePFPhoIso03);
  tree->Branch("elePFNeuIso03", &OUT::elePFNeuIso03);
  tree->Branch("elePFChIso04", &OUT::elePFChIso04);
  tree->Branch("elePFPhoIso04", &OUT::elePFPhoIso04);
  tree->Branch("elePFNeuIso04", &OUT::elePFNeuIso04);
  tree->Branch("eleESEffSigmaRR_x", &OUT::eleESEffSigmaRR_x);
  tree->Branch("eleESEffSigmaRR_y", &OUT::eleESEffSigmaRR_y);
  tree->Branch("eleESEffSigmaRR_z", &OUT::eleESEffSigmaRR_z);
  tree->Branch("nPho", &OUT::nPho, "nPho/I");
  tree->Branch("phoTrg", &OUT::phoTrg);
  tree->Branch("phoTrgFilter", &OUT::phoTrgFilter);
  tree->Branch("phoIsPhoton", &OUT::phoIsPhoton);
  tree->Branch("phoSCPos_x", &OUT::phoSCPos_x);
  tree->Branch("phoSCPos_y", &OUT::phoSCPos_y);
  tree->Branch("phoSCPos_z", &OUT::phoSCPos_z);
  tree->Branch("phoCaloPos_x", &OUT::phoCaloPos_x);
  tree->Branch("phoCaloPos_y", &OUT::phoCaloPos_y);
  tree->Branch("phoCaloPos_z", &OUT::phoCaloPos_z);
  tree->Branch("phoE", &OUT::phoE);
  tree->Branch("phoEt", &OUT::phoEt);
  tree->Branch("phoEta", &OUT::phoEta);
  tree->Branch("phoVtx_x", &OUT::phoVtx_x);
  tree->Branch("phoVtx_y", &OUT::phoVtx_y);
  tree->Branch("phoVtx_z", &OUT::phoVtx_z);
  tree->Branch("phoPhi", &OUT::phoPhi);
  tree->Branch("phoEtVtx", &OUT::phoEtVtx);
  tree->Branch("phoEtaVtx", &OUT::phoEtaVtx);
  tree->Branch("phoPhiVtx", &OUT::phoPhiVtx);
  tree->Branch("phoR9", &OUT::phoR9);
  tree->Branch("phoNClus", &OUT::phoNClus);
  tree->Branch("phoTrkIsoHollowDR03", &OUT::phoTrkIsoHollowDR03);
  tree->Branch("phoEcalIsoDR03", &OUT::phoEcalIsoDR03);
  tree->Branch("phoHcalIsoDR03", &OUT::phoHcalIsoDR03);
  tree->Branch("phoHcalIsoDR0312", &OUT::phoHcalIsoDR0312);
  tree->Branch("phoTrkIsoHollowDR04", &OUT::phoTrkIsoHollowDR04);
  tree->Branch("phoCiCdRtoTrk", &OUT::phoCiCdRtoTrk);
  tree->Branch("phoEcalIsoDR04", &OUT::phoEcalIsoDR04);
  tree->Branch("phoHcalIsoDR04", &OUT::phoHcalIsoDR04);
  tree->Branch("phoHcalIsoDR0412", &OUT::phoHcalIsoDR0412);
  tree->Branch("phoHoverE", &OUT::phoHoverE);
  tree->Branch("phoHoverE12", &OUT::phoHoverE12);
  tree->Branch("phoEleVeto", &OUT::phoEleVeto);
  tree->Branch("phoSigmaIEtaIEta", &OUT::phoSigmaIEtaIEta);
  tree->Branch("phoSigmaIEtaIPhi", &OUT::phoSigmaIEtaIPhi);
  tree->Branch("phoSigmaIPhiIPhi", &OUT::phoSigmaIPhiIPhi);
  tree->Branch("phoCiCPF4phopfIso03", &OUT::phoCiCPF4phopfIso03);
  tree->Branch("phoCiCPF4phopfIso04", &OUT::phoCiCPF4phopfIso04);
  tree->Branch("phoEmax", &OUT::phoEmax);
  tree->Branch("phoETop", &OUT::phoETop);
  tree->Branch("phoEBottom", &OUT::phoEBottom);
  tree->Branch("phoELeft", &OUT::phoELeft);
  tree->Branch("phoERight", &OUT::phoERight);
  tree->Branch("phoE2ndMax", &OUT::phoE2ndMax);
  tree->Branch("phoE3x3", &OUT::phoE3x3);
  tree->Branch("phoE3x1", &OUT::phoE3x1);
  tree->Branch("phoE1x3", &OUT::phoE1x3);
  tree->Branch("phoE5x5", &OUT::phoE5x5);
  tree->Branch("phoE1x5", &OUT::phoE1x5);
  tree->Branch("phoE2x2", &OUT::phoE2x2);
  tree->Branch("phoE2x5Max", &OUT::phoE2x5Max);
  tree->Branch("phoE2x5Top", &OUT::phoE2x5Top);
  tree->Branch("phoE2x5Bottom", &OUT::phoE2x5Bottom);
  tree->Branch("phoE2x5Left", &OUT::phoE2x5Left);
  tree->Branch("phoE2x5Right", &OUT::phoE2x5Right);
  tree->Branch("phoSeedE", &OUT::phoSeedE);
  tree->Branch("phoSeedEta", &OUT::phoSeedEta);
  tree->Branch("phoSeedPhi", &OUT::phoSeedPhi);
  tree->Branch("phoCrysEta", &OUT::phoCrysEta);
  tree->Branch("phoCrysPhi", &OUT::phoCrysPhi);
  tree->Branch("phoCrysIEta", &OUT::phoCrysIEta);
  tree->Branch("phoCrysIPhi", &OUT::phoCrysIPhi);
  tree->Branch("phoPFChIso", &OUT::phoPFChIso);
  tree->Branch("phoPFPhoIso", &OUT::phoPFPhoIso);
  tree->Branch("phoPFNeuIso", &OUT::phoPFNeuIso);
  tree->Branch("phoSCRChIso", &OUT::phoSCRChIso);
  tree->Branch("phoSCRPhoIso", &OUT::phoSCRPhoIso);
  tree->Branch("phoSCRNeuIso", &OUT::phoSCRNeuIso);
  tree->Branch("phoSCRChIso04", &OUT::phoSCRChIso04);
  tree->Branch("phoSCRPhoIso04", &OUT::phoSCRPhoIso04);
  tree->Branch("phoSCRNeuIso04", &OUT::phoSCRNeuIso04);
  tree->Branch("phoRandConeChIso", &OUT::phoRandConeChIso);
  tree->Branch("phoRandConePhoIso", &OUT::phoRandConePhoIso);
  tree->Branch("phoRandConeNeuIso", &OUT::phoRandConeNeuIso);
  tree->Branch("phoRandConeChIso04", &OUT::phoRandConeChIso04);
  tree->Branch("phoRandConePhoIso04", &OUT::phoRandConePhoIso04);
  tree->Branch("phoRandConeNeuIso04", &OUT::phoRandConeNeuIso04);
  tree->Branch("phoRegrE", &OUT::phoRegrE);
  tree->Branch("phoRegrEerr", &OUT::phoRegrEerr);
  tree->Branch("phoSeedTime", &OUT::phoSeedTime);
  tree->Branch("phoSeedDetId1", &OUT::phoSeedDetId1);
  tree->Branch("phoSeedDetId2", &OUT::phoSeedDetId2);
  tree->Branch("phoLICTD", &OUT::phoLICTD);
  tree->Branch("phoRecoFlag", &OUT::phoRecoFlag);
  tree->Branch("phoPos", &OUT::phoPos);
  tree->Branch("phoSCE", &OUT::phoSCE);
  tree->Branch("phoSCRawE", &OUT::phoSCRawE);
  tree->Branch("phoESEn", &OUT::phoESEn);
  tree->Branch("phoSCEt", &OUT::phoSCEt);
  tree->Branch("phoSCEta", &OUT::phoSCEta);
  tree->Branch("phoSCPhi", &OUT::phoSCPhi);
  tree->Branch("phoSCEtaWidth", &OUT::phoSCEtaWidth);
  tree->Branch("phoSCPhiWidth", &OUT::phoSCPhiWidth);
  tree->Branch("phoSCBrem", &OUT::phoSCBrem);
  tree->Branch("phoOverlap", &OUT::phoOverlap);
  tree->Branch("phohasPixelSeed", &OUT::phohasPixelSeed);
  tree->Branch("pho_hasConvPf", &OUT::pho_hasConvPf);
  tree->Branch("pho_hasSLConvPf", &OUT::pho_hasSLConvPf);
  tree->Branch("pho_pfconvVtxZ", &OUT::pho_pfconvVtxZ);
  tree->Branch("pho_pfconvVtxZErr", &OUT::pho_pfconvVtxZErr);
  tree->Branch("pho_nSLConv", &OUT::pho_nSLConv);
  tree->Branch("pho_pfSLConvPos_x", &OUT::pho_pfSLConvPos_x);
  tree->Branch("pho_pfSLConvPos_y", &OUT::pho_pfSLConvPos_y);
  tree->Branch("pho_pfSLConvPos_z", &OUT::pho_pfSLConvPos_z);
  tree->Branch("pho_pfSLConvVtxZ", &OUT::pho_pfSLConvVtxZ);
  tree->Branch("phoIsConv", &OUT::phoIsConv);
  tree->Branch("phoNConv", &OUT::phoNConv);
  tree->Branch("phoConvInvMass", &OUT::phoConvInvMass);
  tree->Branch("phoConvCotTheta", &OUT::phoConvCotTheta);
  tree->Branch("phoConvEoverP", &OUT::phoConvEoverP);
  tree->Branch("phoConvZofPVfromTrks", &OUT::phoConvZofPVfromTrks);
  tree->Branch("phoConvMinDist", &OUT::phoConvMinDist);
  tree->Branch("phoConvdPhiAtVtx", &OUT::phoConvdPhiAtVtx);
  tree->Branch("phoConvdPhiAtCalo", &OUT::phoConvdPhiAtCalo);
  tree->Branch("phoConvdEtaAtCalo", &OUT::phoConvdEtaAtCalo);
  tree->Branch("phoConvTrkd0_x", &OUT::phoConvTrkd0_x);
  tree->Branch("phoConvTrkd0_y", &OUT::phoConvTrkd0_y);
  tree->Branch("phoConvTrkPin_x", &OUT::phoConvTrkPin_x);
  tree->Branch("phoConvTrkPin_y", &OUT::phoConvTrkPin_y);
  tree->Branch("phoConvTrkPout_x", &OUT::phoConvTrkPout_x);
  tree->Branch("phoConvTrkPout_y", &OUT::phoConvTrkPout_y);
  tree->Branch("phoConvTrkdz_x", &OUT::phoConvTrkdz_x);
  tree->Branch("phoConvTrkdz_y", &OUT::phoConvTrkdz_y);
  tree->Branch("phoConvTrkdzErr_x", &OUT::phoConvTrkdzErr_x);
  tree->Branch("phoConvTrkdzErr_y", &OUT::phoConvTrkdzErr_y);
  tree->Branch("phoConvChi2", &OUT::phoConvChi2);
  tree->Branch("phoConvChi2Prob", &OUT::phoConvChi2Prob);
  tree->Branch("phoConvNTrks", &OUT::phoConvNTrks);
  tree->Branch("phoConvCharge1", &OUT::phoConvCharge1);
  tree->Branch("phoConvCharge2", &OUT::phoConvCharge2);
  tree->Branch("phoConvValidVtx", &OUT::phoConvValidVtx);
  tree->Branch("phoConvLikeLihood", &OUT::phoConvLikeLihood);
  tree->Branch("phoConvP4_0", &OUT::phoConvP4_0);
  tree->Branch("phoConvP4_1", &OUT::phoConvP4_1);
  tree->Branch("phoConvP4_2", &OUT::phoConvP4_2);
  tree->Branch("phoConvP4_3", &OUT::phoConvP4_3);
  tree->Branch("phoConvVtx_x", &OUT::phoConvVtx_x);
  tree->Branch("phoConvVtx_y", &OUT::phoConvVtx_y);
  tree->Branch("phoConvVtx_z", &OUT::phoConvVtx_z);
  tree->Branch("phoConvVtxErr_x", &OUT::phoConvVtxErr_x);
  tree->Branch("phoConvVtxErr_y", &OUT::phoConvVtxErr_y);
  tree->Branch("phoConvVtxErr_z", &OUT::phoConvVtxErr_z);
  tree->Branch("phoConvPairMomentum_x", &OUT::phoConvPairMomentum_x);
  tree->Branch("phoConvPairMomentum_y", &OUT::phoConvPairMomentum_y);
  tree->Branch("phoConvPairMomentum_z", &OUT::phoConvPairMomentum_z);
  tree->Branch("phoConvRefittedMomentum_x", &OUT::phoConvRefittedMomentum_x);
  tree->Branch("phoConvRefittedMomentum_y", &OUT::phoConvRefittedMomentum_y);
  tree->Branch("phoConvRefittedMomentum_z", &OUT::phoConvRefittedMomentum_z);
  tree->Branch("SingleLegConv", &OUT::SingleLegConv);
  tree->Branch("phoPFConvVtx_x", &OUT::phoPFConvVtx_x);
  tree->Branch("phoPFConvVtx_y", &OUT::phoPFConvVtx_y);
  tree->Branch("phoPFConvVtx_z", &OUT::phoPFConvVtx_z);
  tree->Branch("phoPFConvMom_x", &OUT::phoPFConvMom_x);
  tree->Branch("phoPFConvMom_y", &OUT::phoPFConvMom_y);
  tree->Branch("phoPFConvMom_z", &OUT::phoPFConvMom_z);
  tree->Branch("phoESEffSigmaRR_x", &OUT::phoESEffSigmaRR_x);
  tree->Branch("phoESEffSigmaRR_y", &OUT::phoESEffSigmaRR_y);
  tree->Branch("phoESEffSigmaRR_z", &OUT::phoESEffSigmaRR_z);
  tree->Branch("nMu", &OUT::nMu, "nMu/I");
  tree->Branch("muTrg", &OUT::muTrg);
  tree->Branch("muEta", &OUT::muEta);
  tree->Branch("muPhi", &OUT::muPhi);
  tree->Branch("muCharge", &OUT::muCharge);
  tree->Branch("muPt", &OUT::muPt);
  tree->Branch("muPz", &OUT::muPz);
  tree->Branch("muVtx_x", &OUT::muVtx_x);
  tree->Branch("muVtx_y", &OUT::muVtx_y);
  tree->Branch("muVtx_z", &OUT::muVtx_z);
  tree->Branch("muVtxGlb_x", &OUT::muVtxGlb_x);
  tree->Branch("muVtxGlb_y", &OUT::muVtxGlb_y);
  tree->Branch("muVtxGlb_z", &OUT::muVtxGlb_z);
  tree->Branch("mucktPt", &OUT::mucktPt);
  tree->Branch("mucktPtErr", &OUT::mucktPtErr);
  tree->Branch("mucktEta", &OUT::mucktEta);
  tree->Branch("mucktPhi", &OUT::mucktPhi);
  tree->Branch("mucktdxy", &OUT::mucktdxy);
  tree->Branch("mucktdz", &OUT::mucktdz);
  tree->Branch("muIsoTrk", &OUT::muIsoTrk);
  tree->Branch("muIsoCalo", &OUT::muIsoCalo);
  tree->Branch("muIsoEcal", &OUT::muIsoEcal);
  tree->Branch("muIsoHcal", &OUT::muIsoHcal);
  tree->Branch("muChi2NDF", &OUT::muChi2NDF);
  tree->Branch("muInnerChi2NDF", &OUT::muInnerChi2NDF);
  tree->Branch("muPFIsoR04_CH", &OUT::muPFIsoR04_CH);
  tree->Branch("muPFIsoR04_NH", &OUT::muPFIsoR04_NH);
  tree->Branch("muPFIsoR04_Pho", &OUT::muPFIsoR04_Pho);
  tree->Branch("muPFIsoR04_PU", &OUT::muPFIsoR04_PU);
  tree->Branch("muPFIsoR04_CPart", &OUT::muPFIsoR04_CPart);
  tree->Branch("muPFIsoR04_NHHT", &OUT::muPFIsoR04_NHHT);
  tree->Branch("muPFIsoR04_PhoHT", &OUT::muPFIsoR04_PhoHT);
  tree->Branch("muPFIsoR03_CH", &OUT::muPFIsoR03_CH);
  tree->Branch("muPFIsoR03_NH", &OUT::muPFIsoR03_NH);
  tree->Branch("muPFIsoR03_Pho", &OUT::muPFIsoR03_Pho);
  tree->Branch("muPFIsoR03_PU", &OUT::muPFIsoR03_PU);
  tree->Branch("muPFIsoR03_CPart", &OUT::muPFIsoR03_CPart);
  tree->Branch("muPFIsoR03_NHHT", &OUT::muPFIsoR03_NHHT);
  tree->Branch("muPFIsoR03_PhoHT", &OUT::muPFIsoR03_PhoHT);
  tree->Branch("muType", &OUT::muType);
  tree->Branch("muD0", &OUT::muD0);
  tree->Branch("muDz", &OUT::muDz);
  tree->Branch("muD0GV", &OUT::muD0GV);
  tree->Branch("muDzGV", &OUT::muDzGV);
  tree->Branch("muD0Vtx", &OUT::muD0Vtx);
  tree->Branch("muDzVtx", &OUT::muDzVtx);
  tree->Branch("muInnerD0", &OUT::muInnerD0);
  tree->Branch("muInnerDz", &OUT::muInnerDz);
  tree->Branch("muInnerD0GV", &OUT::muInnerD0GV);
  tree->Branch("muInnerDzGV", &OUT::muInnerDzGV);
  tree->Branch("muInnerPt", &OUT::muInnerPt);
  tree->Branch("muInnerPtErr", &OUT::muInnerPtErr);
  tree->Branch("muNumberOfValidTrkLayers", &OUT::muNumberOfValidTrkLayers);
  tree->Branch("muNumberOfValidTrkHits", &OUT::muNumberOfValidTrkHits);
  tree->Branch("muNumberOfValidPixelLayers", &OUT::muNumberOfValidPixelLayers);
  tree->Branch("muNumberOfValidPixelHits", &OUT::muNumberOfValidPixelHits);
  tree->Branch("muNumberOfValidMuonHits", &OUT::muNumberOfValidMuonHits);
  tree->Branch("muStations", &OUT::muStations);
  tree->Branch("muChambers", &OUT::muChambers);
  tree->Branch("muIP3D", &OUT::muIP3D);
  tree->Branch("muIP3DErr", &OUT::muIP3DErr);
  tree->Branch("nTau", &OUT::nTau, "nTau/I");
  tree->Branch("tauDecayModeFinding", &OUT::tauDecayModeFinding);
  tree->Branch("tauAgainstElectronLooseMVA3", &OUT::tauAgainstElectronLooseMVA3);
  tree->Branch("tauAgainstElectronMediumMVA3", &OUT::tauAgainstElectronMediumMVA3);
  tree->Branch("tauAgainstElectronTightMVA3", &OUT::tauAgainstElectronTightMVA3);
  tree->Branch("tauAgainstElectronVTightMVA3", &OUT::tauAgainstElectronVTightMVA3);
  tree->Branch("tauAgainstElectronDeadECAL", &OUT::tauAgainstElectronDeadECAL);
  tree->Branch("tauAgainstMuonLoose2", &OUT::tauAgainstMuonLoose2);
  tree->Branch("tauAgainstMuonMedium2", &OUT::tauAgainstMuonMedium2);
  tree->Branch("tauAgainstMuonTight2", &OUT::tauAgainstMuonTight2);
  tree->Branch("tauCombinedIsolationDeltaBetaCorrRaw3Hits", &OUT::tauCombinedIsolationDeltaBetaCorrRaw3Hits);
  tree->Branch("tauLooseCombinedIsolationDeltaBetaCorr3Hits", &OUT::tauLooseCombinedIsolationDeltaBetaCorr3Hits);
  tree->Branch("tauMediumCombinedIsolationDeltaBetaCorr3Hits", &OUT::tauMediumCombinedIsolationDeltaBetaCorr3Hits);
  tree->Branch("tauTightCombinedIsolationDeltaBetaCorr3Hits", &OUT::tauTightCombinedIsolationDeltaBetaCorr3Hits);
  tree->Branch("tauEta", &OUT::tauEta);
  tree->Branch("tauPhi", &OUT::tauPhi);
  tree->Branch("tauPt", &OUT::tauPt);
  tree->Branch("tauEt", &OUT::tauEt);
  tree->Branch("tauCharge", &OUT::tauCharge);
  tree->Branch("tauDecayMode", &OUT::tauDecayMode);
  tree->Branch("tauEMFraction", &OUT::tauEMFraction);
  tree->Branch("tauHCAL3x3OverPLead", &OUT::tauHCAL3x3OverPLead);
  tree->Branch("tauHCALMaxOverPLead", &OUT::tauHCALMaxOverPLead);
  tree->Branch("tauHCALTotOverPLead", &OUT::tauHCALTotOverPLead);
  tree->Branch("tauIsolationPFChargedHadrCandsPtSum", &OUT::tauIsolationPFChargedHadrCandsPtSum);
  tree->Branch("tauIsolationPFGammaCandsEtSum", &OUT::tauIsolationPFGammaCandsEtSum);
  tree->Branch("tauLeadPFChargedHadrCandsignedSipt", &OUT::tauLeadPFChargedHadrCandsignedSipt);
  tree->Branch("tauLeadChargedHadronExists", &OUT::tauLeadChargedHadronExists);
  tree->Branch("tauLeadChargedHadronEta", &OUT::tauLeadChargedHadronEta);
  tree->Branch("tauLeadChargedHadronPhi", &OUT::tauLeadChargedHadronPhi);
  tree->Branch("tauLeadChargedHadronPt", &OUT::tauLeadChargedHadronPt);
  tree->Branch("rho25", &OUT::rho25, "rho25/F");
  tree->Branch("rho25_neu", &OUT::rho25_neu, "rho25_neu/F");
  tree->Branch("rho25_muPFiso", &OUT::rho25_muPFiso, "rho25_muPFiso/F");
  tree->Branch("rho25_elePFiso", &OUT::rho25_elePFiso, "rho25_elePFiso/F");
  tree->Branch("rho2011", &OUT::rho2011, "rho2011/F");
  tree->Branch("rho2012", &OUT::rho2012, "rho2012/F");
  tree->Branch("QGTag_MLP", &OUT::QGTag_MLP, "QGTag_MLP/F");
  tree->Branch("QGTag_likelihood", &OUT::QGTag_likelihood, "QGTag_likelihood/F");
  tree->Branch("nCA8Jet", &OUT::nCA8Jet, "nCA8Jet/I");
  tree->Branch("nJet", &OUT::nJet, "nJet/I");
  tree->Branch("jetTrg", &OUT::jetTrg);
  tree->Branch("jetEn", &OUT::jetEn);
  tree->Branch("jetPt", &OUT::jetPt);
  tree->Branch("jetEta", &OUT::jetEta);
  tree->Branch("jetPhi", &OUT::jetPhi);
  tree->Branch("jetCharge", &OUT::jetCharge);
  tree->Branch("jetEt", &OUT::jetEt);
  tree->Branch("jetRawPt", &OUT::jetRawPt);
  tree->Branch("jetRawEn", &OUT::jetRawEn);
  tree->Branch("jetArea", &OUT::jetArea);
  tree->Branch("jetCHF", &OUT::jetCHF);
  tree->Branch("jetNHF", &OUT::jetNHF);
  tree->Branch("jetCEF", &OUT::jetCEF);
  tree->Branch("jetNEF", &OUT::jetNEF);
  tree->Branch("jetNCH", &OUT::jetNCH);
  tree->Branch("jetHFHAE", &OUT::jetHFHAE);
  tree->Branch("jetHFEME", &OUT::jetHFEME);
  tree->Branch("jetNConstituents", &OUT::jetNConstituents);
  tree->Branch("jetCombinedSecondaryVtxBJetTags", &OUT::jetCombinedSecondaryVtxBJetTags);
  tree->Branch("jetCombinedSecondaryVtxMVABJetTags", &OUT::jetCombinedSecondaryVtxMVABJetTags);
  tree->Branch("jetJetProbabilityBJetTags", &OUT::jetJetProbabilityBJetTags);
  tree->Branch("jetJetBProbabilityBJetTags", &OUT::jetJetBProbabilityBJetTags);
  tree->Branch("jetPFLooseId", &OUT::jetPFLooseId);
  tree->Branch("jetDRMean", &OUT::jetDRMean);
  tree->Branch("jetDR2Mean", &OUT::jetDR2Mean);
  tree->Branch("jetDZ", &OUT::jetDZ);
  tree->Branch("jetFrac01", &OUT::jetFrac01);
  tree->Branch("jetFrac02", &OUT::jetFrac02);
  tree->Branch("jetFrac03", &OUT::jetFrac03);
  tree->Branch("jetFrac04", &OUT::jetFrac04);
  tree->Branch("jetFrac05", &OUT::jetFrac05);
  tree->Branch("jetFrac06", &OUT::jetFrac06);
  tree->Branch("jetFrac07", &OUT::jetFrac07);
  tree->Branch("jetBeta", &OUT::jetBeta);
  tree->Branch("jetBetaStarCMG", &OUT::jetBetaStarCMG);
  tree->Branch("jetBetaStarClassic", &OUT::jetBetaStarClassic);
  tree->Branch("jetNNeutrals", &OUT::jetNNeutrals);
  tree->Branch("jetNCharged", &OUT::jetNCharged);
  tree->Branch("jetWPLevels", &OUT::jetWPLevels);
  tree->Branch("jetMVAsExt_cutBased", &OUT::jetMVAsExt_cutBased);
  tree->Branch("jetMVAsExt_philv1", &OUT::jetMVAsExt_philv1);
  tree->Branch("jetWPLevelsExt_philv1", &OUT::jetWPLevelsExt_philv1);
  tree->Branch("jetMt", &OUT::jetMt);
  tree->Branch("jetJECUnc", &OUT::jetJECUnc);
  tree->Branch("jetLeadTrackPt", &OUT::jetLeadTrackPt);
  tree->Branch("jetVtxPt", &OUT::jetVtxPt);
  tree->Branch("jetVtxMass", &OUT::jetVtxMass);
  tree->Branch("jetVtx3dL", &OUT::jetVtx3dL);
  tree->Branch("jetVtx3deL", &OUT::jetVtx3deL);
  tree->Branch("jetSoftLeptPt", &OUT::jetSoftLeptPt);
  tree->Branch("jetSoftLeptPtRel", &OUT::jetSoftLeptPtRel);
  tree->Branch("jetSoftLeptdR", &OUT::jetSoftLeptdR);
  tree->Branch("jetSoftLeptIdlooseMu", &OUT::jetSoftLeptIdlooseMu);
  tree->Branch("jetSoftLeptIdEle95", &OUT::jetSoftLeptIdEle95);
  tree->Branch("jetDPhiMETJet", &OUT::jetDPhiMETJet);
  tree->Branch("jetPuJetIdL", &OUT::jetPuJetIdL);
  tree->Branch("jetPuJetIdM", &OUT::jetPuJetIdM);
  tree->Branch("jetPuJetIdT", &OUT::jetPuJetIdT);
  tree->Branch("nConv", &OUT::nConv, "nConv/I");
  tree->Branch("convP4_x", &OUT::convP4_x);
  tree->Branch("convP4_y", &OUT::convP4_y);
  tree->Branch("convP4_z", &OUT::convP4_z);
  tree->Branch("convP4_E", &OUT::convP4_E);
  tree->Branch("convVtx_x", &OUT::convVtx_x);
  tree->Branch("convVtx_y", &OUT::convVtx_y);
  tree->Branch("convVtx_z", &OUT::convVtx_z);
  tree->Branch("convVtxErr_x", &OUT::convVtxErr_x);
  tree->Branch("convVtxErr_y", &OUT::convVtxErr_y);
  tree->Branch("convVtxErr_z", &OUT::convVtxErr_z);
  tree->Branch("convPairMomentum_x", &OUT::convPairMomentum_x);
  tree->Branch("convPairMomentum_y", &OUT::convPairMomentum_y);
  tree->Branch("convPairMomentum_z", &OUT::convPairMomentum_z);
  tree->Branch("convRefittedMomentum_x", &OUT::convRefittedMomentum_x);
  tree->Branch("convRefittedMomentum_y", &OUT::convRefittedMomentum_y);
  tree->Branch("convRefittedMomentum_z", &OUT::convRefittedMomentum_z);
  tree->Branch("convNTracks", &OUT::convNTracks);
  tree->Branch("convPairInvMass", &OUT::convPairInvMass);
  tree->Branch("convPairCotThetaSep", &OUT::convPairCotThetaSep);
  tree->Branch("convEoverP", &OUT::convEoverP);
  tree->Branch("convDistOfMinApproach", &OUT::convDistOfMinApproach);
  tree->Branch("convDPhiTrksAtVtx", &OUT::convDPhiTrksAtVtx);
  tree->Branch("convDPhiTrksAtEcal", &OUT::convDPhiTrksAtEcal);
  tree->Branch("convDEtaTrksAtEcal", &OUT::convDEtaTrksAtEcal);
  tree->Branch("convDxy", &OUT::convDxy);
  tree->Branch("convDz", &OUT::convDz);
  tree->Branch("convLxy", &OUT::convLxy);
  tree->Branch("convLz", &OUT::convLz);
  tree->Branch("convZofPrimVtxFromTrks", &OUT::convZofPrimVtxFromTrks);
  tree->Branch("convNHitsBeforeVtx_0", &OUT::convNHitsBeforeVtx_0);
  tree->Branch("convNHitsBeforeVtx_1", &OUT::convNHitsBeforeVtx_1);
  tree->Branch("convNSharedHits", &OUT::convNSharedHits);
  tree->Branch("convValidVtx", &OUT::convValidVtx);
  tree->Branch("convMVALikelihood", &OUT::convMVALikelihood);
  tree->Branch("convChi2", &OUT::convChi2);
  tree->Branch("convChi2Probability", &OUT::convChi2Probability);
  tree->Branch("convTk1Dz", &OUT::convTk1Dz);
  tree->Branch("convTk2Dz", &OUT::convTk2Dz);
  tree->Branch("convTk1DzErr", &OUT::convTk1DzErr);
  tree->Branch("convTk2DzErr", &OUT::convTk2DzErr);
  tree->Branch("convCh1Ch2", &OUT::convCh1Ch2);
  tree->Branch("convTk1D0", &OUT::convTk1D0);
  tree->Branch("convTk1Pout", &OUT::convTk1Pout);
  tree->Branch("convTk1Pin", &OUT::convTk1Pin);
  tree->Branch("convTk2D0", &OUT::convTk2D0);
  tree->Branch("convTk2Pout", &OUT::convTk2Pout);
  tree->Branch("convTk2Pin", &OUT::convTk2Pin);
}
void CopyInputVarsToOutput( std::string prefix) {
    CopynHLTInToOut( prefix ); 
    CopyrunInToOut( prefix ); 
    CopyeventInToOut( prefix ); 
    CopylumisInToOut( prefix ); 
    CopyisDataInToOut( prefix ); 
    CopyHLTInToOut( prefix ); 
    CopyHLTIndexInToOut( prefix ); 
    CopybspotPosInToOut( prefix ); 
    CopynVtxInToOut( prefix ); 
    Copyvtx_xInToOut( prefix ); 
    Copyvtx_yInToOut( prefix ); 
    Copyvtx_zInToOut( prefix ); 
    CopyIsVtxGoodInToOut( prefix ); 
    CopynGoodVtxInToOut( prefix ); 
    CopynVtxBSInToOut( prefix ); 
    Copyvtxbs_xInToOut( prefix ); 
    Copyvtxbs_yInToOut( prefix ); 
    Copyvtxbs_zInToOut( prefix ); 
    CopypfMETInToOut( prefix ); 
    CopypfMETPhiInToOut( prefix ); 
    CopypfMETsumEtInToOut( prefix ); 
    CopypfMETmEtSigInToOut( prefix ); 
    CopypfMETSigInToOut( prefix ); 
    CopypfType01METInToOut( prefix ); 
    CopypfType01METPhiInToOut( prefix ); 
    CopypfType01METsumEtInToOut( prefix ); 
    CopypfType01METmEtSigInToOut( prefix ); 
    CopypfType01METSigInToOut( prefix ); 
    CopyrecoPfMETInToOut( prefix ); 
    CopyrecoPfMETPhiInToOut( prefix ); 
    CopyrecoPfMETsumEtInToOut( prefix ); 
    CopyrecoPfMETmEtSigInToOut( prefix ); 
    CopyrecoPfMETSigInToOut( prefix ); 
    CopytrkMETxPVInToOut( prefix ); 
    CopytrkMETyPVInToOut( prefix ); 
    CopytrkMETPhiPVInToOut( prefix ); 
    CopytrkMETPVInToOut( prefix ); 
    CopytrkMETxInToOut( prefix ); 
    CopytrkMETyInToOut( prefix ); 
    CopytrkMETPhiInToOut( prefix ); 
    CopytrkMETInToOut( prefix ); 
    CopymetFiltersInToOut( prefix ); 
    CopynEleInToOut( prefix ); 
    CopyeleTrgInToOut( prefix ); 
    CopyeleClassInToOut( prefix ); 
    CopyeleIsEcalDrivenInToOut( prefix ); 
    CopyeleChargeInToOut( prefix ); 
    CopyeleChargeConsistentInToOut( prefix ); 
    CopyeleEnInToOut( prefix ); 
    CopyeleEcalEnInToOut( prefix ); 
    CopyeleSCRawEnInToOut( prefix ); 
    CopyeleSCEnInToOut( prefix ); 
    CopyeleESEnInToOut( prefix ); 
    CopyelePtInToOut( prefix ); 
    CopyeleEtaInToOut( prefix ); 
    CopyelePhiInToOut( prefix ); 
    CopyeleR9InToOut( prefix ); 
    CopyeleEtaVtxInToOut( prefix ); 
    CopyelePhiVtxInToOut( prefix ); 
    CopyeleEtVtxInToOut( prefix ); 
    CopyeleSCEtaInToOut( prefix ); 
    CopyeleSCPhiInToOut( prefix ); 
    CopyeleSCEtaWidthInToOut( prefix ); 
    CopyeleSCPhiWidthInToOut( prefix ); 
    CopyeleVtx_xInToOut( prefix ); 
    CopyeleVtx_yInToOut( prefix ); 
    CopyeleVtx_zInToOut( prefix ); 
    CopyeleD0InToOut( prefix ); 
    CopyeleDzInToOut( prefix ); 
    CopyeleD0GVInToOut( prefix ); 
    CopyeleDzGVInToOut( prefix ); 
    CopyeleD0VtxInToOut( prefix ); 
    CopyeleDzVtxInToOut( prefix ); 
    CopyeleHoverEInToOut( prefix ); 
    CopyeleHoverE12InToOut( prefix ); 
    CopyeleEoverPInToOut( prefix ); 
    CopyelePinInToOut( prefix ); 
    CopyelePoutInToOut( prefix ); 
    CopyeleTrkMomErrInToOut( prefix ); 
    CopyeleBremInToOut( prefix ); 
    CopyeledEtaAtVtxInToOut( prefix ); 
    CopyeledPhiAtVtxInToOut( prefix ); 
    CopyeleSigmaIEtaIEtaInToOut( prefix ); 
    CopyeleSigmaIEtaIPhiInToOut( prefix ); 
    CopyeleSigmaIPhiIPhiInToOut( prefix ); 
    CopyeleEmaxInToOut( prefix ); 
    CopyeleE2ndMaxInToOut( prefix ); 
    CopyeleETopInToOut( prefix ); 
    CopyeleEBottomInToOut( prefix ); 
    CopyeleELeftInToOut( prefix ); 
    CopyeleERightInToOut( prefix ); 
    CopyeleE1x5InToOut( prefix ); 
    CopyeleE3x3InToOut( prefix ); 
    CopyeleE5x5InToOut( prefix ); 
    CopyeleE2x5MaxInToOut( prefix ); 
    CopyeleE2x5TopInToOut( prefix ); 
    CopyeleE2x5BottomInToOut( prefix ); 
    CopyeleE2x5LeftInToOut( prefix ); 
    CopyeleE2x5RightInToOut( prefix ); 
    CopyeleSeedEtaInToOut( prefix ); 
    CopyeleSeedEInToOut( prefix ); 
    CopyeleSeedPhiInToOut( prefix ); 
    CopyeleCrysEtaInToOut( prefix ); 
    CopyeleCrysPhiInToOut( prefix ); 
    CopyeleCrysIEtaInToOut( prefix ); 
    CopyeleCrysIPhiInToOut( prefix ); 
    CopyeleRegrEInToOut( prefix ); 
    CopyeleRegrEerrInToOut( prefix ); 
    CopyelePhoRegrEInToOut( prefix ); 
    CopyelePhoRegrEerrInToOut( prefix ); 
    CopyeleSeedTimeInToOut( prefix ); 
    CopyeleRecoFlagInToOut( prefix ); 
    CopyelePosInToOut( prefix ); 
    CopyeleIsoTrkDR03InToOut( prefix ); 
    CopyeleIsoEcalDR03InToOut( prefix ); 
    CopyeleIsoHcalDR03InToOut( prefix ); 
    CopyeleIsoHcalDR0312InToOut( prefix ); 
    CopyeleIsoTrkDR04InToOut( prefix ); 
    CopyeleIsoEcalDR04InToOut( prefix ); 
    CopyeleIsoHcalDR04InToOut( prefix ); 
    CopyeleIsoHcalDR0412InToOut( prefix ); 
    CopyeleModIsoTrkInToOut( prefix ); 
    CopyeleModIsoEcalInToOut( prefix ); 
    CopyeleModIsoHcalInToOut( prefix ); 
    CopyeleMissHitsInToOut( prefix ); 
    CopyeleConvDistInToOut( prefix ); 
    CopyeleConvDcotInToOut( prefix ); 
    CopyeleConvVtxFitInToOut( prefix ); 
    CopyeleIP3DInToOut( prefix ); 
    CopyeleIP3DErrInToOut( prefix ); 
    CopyeleIDMVANonTrigInToOut( prefix ); 
    CopyeleIDMVATrigInToOut( prefix ); 
    CopyelePFChIso03InToOut( prefix ); 
    CopyelePFPhoIso03InToOut( prefix ); 
    CopyelePFNeuIso03InToOut( prefix ); 
    CopyelePFChIso04InToOut( prefix ); 
    CopyelePFPhoIso04InToOut( prefix ); 
    CopyelePFNeuIso04InToOut( prefix ); 
    CopyeleESEffSigmaRR_xInToOut( prefix ); 
    CopyeleESEffSigmaRR_yInToOut( prefix ); 
    CopyeleESEffSigmaRR_zInToOut( prefix ); 
    CopynPhoInToOut( prefix ); 
    CopyphoTrgInToOut( prefix ); 
    CopyphoTrgFilterInToOut( prefix ); 
    CopyphoIsPhotonInToOut( prefix ); 
    CopyphoSCPos_xInToOut( prefix ); 
    CopyphoSCPos_yInToOut( prefix ); 
    CopyphoSCPos_zInToOut( prefix ); 
    CopyphoCaloPos_xInToOut( prefix ); 
    CopyphoCaloPos_yInToOut( prefix ); 
    CopyphoCaloPos_zInToOut( prefix ); 
    CopyphoEInToOut( prefix ); 
    CopyphoEtInToOut( prefix ); 
    CopyphoEtaInToOut( prefix ); 
    CopyphoVtx_xInToOut( prefix ); 
    CopyphoVtx_yInToOut( prefix ); 
    CopyphoVtx_zInToOut( prefix ); 
    CopyphoPhiInToOut( prefix ); 
    CopyphoEtVtxInToOut( prefix ); 
    CopyphoEtaVtxInToOut( prefix ); 
    CopyphoPhiVtxInToOut( prefix ); 
    CopyphoR9InToOut( prefix ); 
    CopyphoNClusInToOut( prefix ); 
    CopyphoTrkIsoHollowDR03InToOut( prefix ); 
    CopyphoEcalIsoDR03InToOut( prefix ); 
    CopyphoHcalIsoDR03InToOut( prefix ); 
    CopyphoHcalIsoDR0312InToOut( prefix ); 
    CopyphoTrkIsoHollowDR04InToOut( prefix ); 
    CopyphoCiCdRtoTrkInToOut( prefix ); 
    CopyphoEcalIsoDR04InToOut( prefix ); 
    CopyphoHcalIsoDR04InToOut( prefix ); 
    CopyphoHcalIsoDR0412InToOut( prefix ); 
    CopyphoHoverEInToOut( prefix ); 
    CopyphoHoverE12InToOut( prefix ); 
    CopyphoEleVetoInToOut( prefix ); 
    CopyphoSigmaIEtaIEtaInToOut( prefix ); 
    CopyphoSigmaIEtaIPhiInToOut( prefix ); 
    CopyphoSigmaIPhiIPhiInToOut( prefix ); 
    CopyphoCiCPF4phopfIso03InToOut( prefix ); 
    CopyphoCiCPF4phopfIso04InToOut( prefix ); 
    CopyphoEmaxInToOut( prefix ); 
    CopyphoETopInToOut( prefix ); 
    CopyphoEBottomInToOut( prefix ); 
    CopyphoELeftInToOut( prefix ); 
    CopyphoERightInToOut( prefix ); 
    CopyphoE2ndMaxInToOut( prefix ); 
    CopyphoE3x3InToOut( prefix ); 
    CopyphoE3x1InToOut( prefix ); 
    CopyphoE1x3InToOut( prefix ); 
    CopyphoE5x5InToOut( prefix ); 
    CopyphoE1x5InToOut( prefix ); 
    CopyphoE2x2InToOut( prefix ); 
    CopyphoE2x5MaxInToOut( prefix ); 
    CopyphoE2x5TopInToOut( prefix ); 
    CopyphoE2x5BottomInToOut( prefix ); 
    CopyphoE2x5LeftInToOut( prefix ); 
    CopyphoE2x5RightInToOut( prefix ); 
    CopyphoSeedEInToOut( prefix ); 
    CopyphoSeedEtaInToOut( prefix ); 
    CopyphoSeedPhiInToOut( prefix ); 
    CopyphoCrysEtaInToOut( prefix ); 
    CopyphoCrysPhiInToOut( prefix ); 
    CopyphoCrysIEtaInToOut( prefix ); 
    CopyphoCrysIPhiInToOut( prefix ); 
    CopyphoPFChIsoInToOut( prefix ); 
    CopyphoPFPhoIsoInToOut( prefix ); 
    CopyphoPFNeuIsoInToOut( prefix ); 
    CopyphoSCRChIsoInToOut( prefix ); 
    CopyphoSCRPhoIsoInToOut( prefix ); 
    CopyphoSCRNeuIsoInToOut( prefix ); 
    CopyphoSCRChIso04InToOut( prefix ); 
    CopyphoSCRPhoIso04InToOut( prefix ); 
    CopyphoSCRNeuIso04InToOut( prefix ); 
    CopyphoRandConeChIsoInToOut( prefix ); 
    CopyphoRandConePhoIsoInToOut( prefix ); 
    CopyphoRandConeNeuIsoInToOut( prefix ); 
    CopyphoRandConeChIso04InToOut( prefix ); 
    CopyphoRandConePhoIso04InToOut( prefix ); 
    CopyphoRandConeNeuIso04InToOut( prefix ); 
    CopyphoRegrEInToOut( prefix ); 
    CopyphoRegrEerrInToOut( prefix ); 
    CopyphoSeedTimeInToOut( prefix ); 
    CopyphoSeedDetId1InToOut( prefix ); 
    CopyphoSeedDetId2InToOut( prefix ); 
    CopyphoLICTDInToOut( prefix ); 
    CopyphoRecoFlagInToOut( prefix ); 
    CopyphoPosInToOut( prefix ); 
    CopyphoSCEInToOut( prefix ); 
    CopyphoSCRawEInToOut( prefix ); 
    CopyphoESEnInToOut( prefix ); 
    CopyphoSCEtInToOut( prefix ); 
    CopyphoSCEtaInToOut( prefix ); 
    CopyphoSCPhiInToOut( prefix ); 
    CopyphoSCEtaWidthInToOut( prefix ); 
    CopyphoSCPhiWidthInToOut( prefix ); 
    CopyphoSCBremInToOut( prefix ); 
    CopyphoOverlapInToOut( prefix ); 
    CopyphohasPixelSeedInToOut( prefix ); 
    Copypho_hasConvPfInToOut( prefix ); 
    Copypho_hasSLConvPfInToOut( prefix ); 
    Copypho_pfconvVtxZInToOut( prefix ); 
    Copypho_pfconvVtxZErrInToOut( prefix ); 
    Copypho_nSLConvInToOut( prefix ); 
    Copypho_pfSLConvPos_xInToOut( prefix ); 
    Copypho_pfSLConvPos_yInToOut( prefix ); 
    Copypho_pfSLConvPos_zInToOut( prefix ); 
    Copypho_pfSLConvVtxZInToOut( prefix ); 
    CopyphoIsConvInToOut( prefix ); 
    CopyphoNConvInToOut( prefix ); 
    CopyphoConvInvMassInToOut( prefix ); 
    CopyphoConvCotThetaInToOut( prefix ); 
    CopyphoConvEoverPInToOut( prefix ); 
    CopyphoConvZofPVfromTrksInToOut( prefix ); 
    CopyphoConvMinDistInToOut( prefix ); 
    CopyphoConvdPhiAtVtxInToOut( prefix ); 
    CopyphoConvdPhiAtCaloInToOut( prefix ); 
    CopyphoConvdEtaAtCaloInToOut( prefix ); 
    CopyphoConvTrkd0_xInToOut( prefix ); 
    CopyphoConvTrkd0_yInToOut( prefix ); 
    CopyphoConvTrkPin_xInToOut( prefix ); 
    CopyphoConvTrkPin_yInToOut( prefix ); 
    CopyphoConvTrkPout_xInToOut( prefix ); 
    CopyphoConvTrkPout_yInToOut( prefix ); 
    CopyphoConvTrkdz_xInToOut( prefix ); 
    CopyphoConvTrkdz_yInToOut( prefix ); 
    CopyphoConvTrkdzErr_xInToOut( prefix ); 
    CopyphoConvTrkdzErr_yInToOut( prefix ); 
    CopyphoConvChi2InToOut( prefix ); 
    CopyphoConvChi2ProbInToOut( prefix ); 
    CopyphoConvNTrksInToOut( prefix ); 
    CopyphoConvCharge1InToOut( prefix ); 
    CopyphoConvCharge2InToOut( prefix ); 
    CopyphoConvValidVtxInToOut( prefix ); 
    CopyphoConvLikeLihoodInToOut( prefix ); 
    CopyphoConvP4_0InToOut( prefix ); 
    CopyphoConvP4_1InToOut( prefix ); 
    CopyphoConvP4_2InToOut( prefix ); 
    CopyphoConvP4_3InToOut( prefix ); 
    CopyphoConvVtx_xInToOut( prefix ); 
    CopyphoConvVtx_yInToOut( prefix ); 
    CopyphoConvVtx_zInToOut( prefix ); 
    CopyphoConvVtxErr_xInToOut( prefix ); 
    CopyphoConvVtxErr_yInToOut( prefix ); 
    CopyphoConvVtxErr_zInToOut( prefix ); 
    CopyphoConvPairMomentum_xInToOut( prefix ); 
    CopyphoConvPairMomentum_yInToOut( prefix ); 
    CopyphoConvPairMomentum_zInToOut( prefix ); 
    CopyphoConvRefittedMomentum_xInToOut( prefix ); 
    CopyphoConvRefittedMomentum_yInToOut( prefix ); 
    CopyphoConvRefittedMomentum_zInToOut( prefix ); 
    CopySingleLegConvInToOut( prefix ); 
    CopyphoPFConvVtx_xInToOut( prefix ); 
    CopyphoPFConvVtx_yInToOut( prefix ); 
    CopyphoPFConvVtx_zInToOut( prefix ); 
    CopyphoPFConvMom_xInToOut( prefix ); 
    CopyphoPFConvMom_yInToOut( prefix ); 
    CopyphoPFConvMom_zInToOut( prefix ); 
    CopyphoESEffSigmaRR_xInToOut( prefix ); 
    CopyphoESEffSigmaRR_yInToOut( prefix ); 
    CopyphoESEffSigmaRR_zInToOut( prefix ); 
    CopynMuInToOut( prefix ); 
    CopymuTrgInToOut( prefix ); 
    CopymuEtaInToOut( prefix ); 
    CopymuPhiInToOut( prefix ); 
    CopymuChargeInToOut( prefix ); 
    CopymuPtInToOut( prefix ); 
    CopymuPzInToOut( prefix ); 
    CopymuVtx_xInToOut( prefix ); 
    CopymuVtx_yInToOut( prefix ); 
    CopymuVtx_zInToOut( prefix ); 
    CopymuVtxGlb_xInToOut( prefix ); 
    CopymuVtxGlb_yInToOut( prefix ); 
    CopymuVtxGlb_zInToOut( prefix ); 
    CopymucktPtInToOut( prefix ); 
    CopymucktPtErrInToOut( prefix ); 
    CopymucktEtaInToOut( prefix ); 
    CopymucktPhiInToOut( prefix ); 
    CopymucktdxyInToOut( prefix ); 
    CopymucktdzInToOut( prefix ); 
    CopymuIsoTrkInToOut( prefix ); 
    CopymuIsoCaloInToOut( prefix ); 
    CopymuIsoEcalInToOut( prefix ); 
    CopymuIsoHcalInToOut( prefix ); 
    CopymuChi2NDFInToOut( prefix ); 
    CopymuInnerChi2NDFInToOut( prefix ); 
    CopymuPFIsoR04_CHInToOut( prefix ); 
    CopymuPFIsoR04_NHInToOut( prefix ); 
    CopymuPFIsoR04_PhoInToOut( prefix ); 
    CopymuPFIsoR04_PUInToOut( prefix ); 
    CopymuPFIsoR04_CPartInToOut( prefix ); 
    CopymuPFIsoR04_NHHTInToOut( prefix ); 
    CopymuPFIsoR04_PhoHTInToOut( prefix ); 
    CopymuPFIsoR03_CHInToOut( prefix ); 
    CopymuPFIsoR03_NHInToOut( prefix ); 
    CopymuPFIsoR03_PhoInToOut( prefix ); 
    CopymuPFIsoR03_PUInToOut( prefix ); 
    CopymuPFIsoR03_CPartInToOut( prefix ); 
    CopymuPFIsoR03_NHHTInToOut( prefix ); 
    CopymuPFIsoR03_PhoHTInToOut( prefix ); 
    CopymuTypeInToOut( prefix ); 
    CopymuD0InToOut( prefix ); 
    CopymuDzInToOut( prefix ); 
    CopymuD0GVInToOut( prefix ); 
    CopymuDzGVInToOut( prefix ); 
    CopymuD0VtxInToOut( prefix ); 
    CopymuDzVtxInToOut( prefix ); 
    CopymuInnerD0InToOut( prefix ); 
    CopymuInnerDzInToOut( prefix ); 
    CopymuInnerD0GVInToOut( prefix ); 
    CopymuInnerDzGVInToOut( prefix ); 
    CopymuInnerPtInToOut( prefix ); 
    CopymuInnerPtErrInToOut( prefix ); 
    CopymuNumberOfValidTrkLayersInToOut( prefix ); 
    CopymuNumberOfValidTrkHitsInToOut( prefix ); 
    CopymuNumberOfValidPixelLayersInToOut( prefix ); 
    CopymuNumberOfValidPixelHitsInToOut( prefix ); 
    CopymuNumberOfValidMuonHitsInToOut( prefix ); 
    CopymuStationsInToOut( prefix ); 
    CopymuChambersInToOut( prefix ); 
    CopymuIP3DInToOut( prefix ); 
    CopymuIP3DErrInToOut( prefix ); 
    CopynTauInToOut( prefix ); 
    CopytauDecayModeFindingInToOut( prefix ); 
    CopytauAgainstElectronLooseMVA3InToOut( prefix ); 
    CopytauAgainstElectronMediumMVA3InToOut( prefix ); 
    CopytauAgainstElectronTightMVA3InToOut( prefix ); 
    CopytauAgainstElectronVTightMVA3InToOut( prefix ); 
    CopytauAgainstElectronDeadECALInToOut( prefix ); 
    CopytauAgainstMuonLoose2InToOut( prefix ); 
    CopytauAgainstMuonMedium2InToOut( prefix ); 
    CopytauAgainstMuonTight2InToOut( prefix ); 
    CopytauCombinedIsolationDeltaBetaCorrRaw3HitsInToOut( prefix ); 
    CopytauLooseCombinedIsolationDeltaBetaCorr3HitsInToOut( prefix ); 
    CopytauMediumCombinedIsolationDeltaBetaCorr3HitsInToOut( prefix ); 
    CopytauTightCombinedIsolationDeltaBetaCorr3HitsInToOut( prefix ); 
    CopytauEtaInToOut( prefix ); 
    CopytauPhiInToOut( prefix ); 
    CopytauPtInToOut( prefix ); 
    CopytauEtInToOut( prefix ); 
    CopytauChargeInToOut( prefix ); 
    CopytauDecayModeInToOut( prefix ); 
    CopytauEMFractionInToOut( prefix ); 
    CopytauHCAL3x3OverPLeadInToOut( prefix ); 
    CopytauHCALMaxOverPLeadInToOut( prefix ); 
    CopytauHCALTotOverPLeadInToOut( prefix ); 
    CopytauIsolationPFChargedHadrCandsPtSumInToOut( prefix ); 
    CopytauIsolationPFGammaCandsEtSumInToOut( prefix ); 
    CopytauLeadPFChargedHadrCandsignedSiptInToOut( prefix ); 
    CopytauLeadChargedHadronExistsInToOut( prefix ); 
    CopytauLeadChargedHadronEtaInToOut( prefix ); 
    CopytauLeadChargedHadronPhiInToOut( prefix ); 
    CopytauLeadChargedHadronPtInToOut( prefix ); 
    Copyrho25InToOut( prefix ); 
    Copyrho25_neuInToOut( prefix ); 
    Copyrho25_muPFisoInToOut( prefix ); 
    Copyrho25_elePFisoInToOut( prefix ); 
    Copyrho2011InToOut( prefix ); 
    Copyrho2012InToOut( prefix ); 
    CopyQGTag_MLPInToOut( prefix ); 
    CopyQGTag_likelihoodInToOut( prefix ); 
    CopynCA8JetInToOut( prefix ); 
    CopynJetInToOut( prefix ); 
    CopyjetTrgInToOut( prefix ); 
    CopyjetEnInToOut( prefix ); 
    CopyjetPtInToOut( prefix ); 
    CopyjetEtaInToOut( prefix ); 
    CopyjetPhiInToOut( prefix ); 
    CopyjetChargeInToOut( prefix ); 
    CopyjetEtInToOut( prefix ); 
    CopyjetRawPtInToOut( prefix ); 
    CopyjetRawEnInToOut( prefix ); 
    CopyjetAreaInToOut( prefix ); 
    CopyjetCHFInToOut( prefix ); 
    CopyjetNHFInToOut( prefix ); 
    CopyjetCEFInToOut( prefix ); 
    CopyjetNEFInToOut( prefix ); 
    CopyjetNCHInToOut( prefix ); 
    CopyjetHFHAEInToOut( prefix ); 
    CopyjetHFEMEInToOut( prefix ); 
    CopyjetNConstituentsInToOut( prefix ); 
    CopyjetCombinedSecondaryVtxBJetTagsInToOut( prefix ); 
    CopyjetCombinedSecondaryVtxMVABJetTagsInToOut( prefix ); 
    CopyjetJetProbabilityBJetTagsInToOut( prefix ); 
    CopyjetJetBProbabilityBJetTagsInToOut( prefix ); 
    CopyjetPFLooseIdInToOut( prefix ); 
    CopyjetDRMeanInToOut( prefix ); 
    CopyjetDR2MeanInToOut( prefix ); 
    CopyjetDZInToOut( prefix ); 
    CopyjetFrac01InToOut( prefix ); 
    CopyjetFrac02InToOut( prefix ); 
    CopyjetFrac03InToOut( prefix ); 
    CopyjetFrac04InToOut( prefix ); 
    CopyjetFrac05InToOut( prefix ); 
    CopyjetFrac06InToOut( prefix ); 
    CopyjetFrac07InToOut( prefix ); 
    CopyjetBetaInToOut( prefix ); 
    CopyjetBetaStarCMGInToOut( prefix ); 
    CopyjetBetaStarClassicInToOut( prefix ); 
    CopyjetNNeutralsInToOut( prefix ); 
    CopyjetNChargedInToOut( prefix ); 
    CopyjetWPLevelsInToOut( prefix ); 
    CopyjetMVAsExt_cutBasedInToOut( prefix ); 
    CopyjetMVAsExt_philv1InToOut( prefix ); 
    CopyjetWPLevelsExt_philv1InToOut( prefix ); 
    CopyjetMtInToOut( prefix ); 
    CopyjetJECUncInToOut( prefix ); 
    CopyjetLeadTrackPtInToOut( prefix ); 
    CopyjetVtxPtInToOut( prefix ); 
    CopyjetVtxMassInToOut( prefix ); 
    CopyjetVtx3dLInToOut( prefix ); 
    CopyjetVtx3deLInToOut( prefix ); 
    CopyjetSoftLeptPtInToOut( prefix ); 
    CopyjetSoftLeptPtRelInToOut( prefix ); 
    CopyjetSoftLeptdRInToOut( prefix ); 
    CopyjetSoftLeptIdlooseMuInToOut( prefix ); 
    CopyjetSoftLeptIdEle95InToOut( prefix ); 
    CopyjetDPhiMETJetInToOut( prefix ); 
    CopyjetPuJetIdLInToOut( prefix ); 
    CopyjetPuJetIdMInToOut( prefix ); 
    CopyjetPuJetIdTInToOut( prefix ); 
    CopynConvInToOut( prefix ); 
    CopyconvP4_xInToOut( prefix ); 
    CopyconvP4_yInToOut( prefix ); 
    CopyconvP4_zInToOut( prefix ); 
    CopyconvP4_EInToOut( prefix ); 
    CopyconvVtx_xInToOut( prefix ); 
    CopyconvVtx_yInToOut( prefix ); 
    CopyconvVtx_zInToOut( prefix ); 
    CopyconvVtxErr_xInToOut( prefix ); 
    CopyconvVtxErr_yInToOut( prefix ); 
    CopyconvVtxErr_zInToOut( prefix ); 
    CopyconvPairMomentum_xInToOut( prefix ); 
    CopyconvPairMomentum_yInToOut( prefix ); 
    CopyconvPairMomentum_zInToOut( prefix ); 
    CopyconvRefittedMomentum_xInToOut( prefix ); 
    CopyconvRefittedMomentum_yInToOut( prefix ); 
    CopyconvRefittedMomentum_zInToOut( prefix ); 
    CopyconvNTracksInToOut( prefix ); 
    CopyconvPairInvMassInToOut( prefix ); 
    CopyconvPairCotThetaSepInToOut( prefix ); 
    CopyconvEoverPInToOut( prefix ); 
    CopyconvDistOfMinApproachInToOut( prefix ); 
    CopyconvDPhiTrksAtVtxInToOut( prefix ); 
    CopyconvDPhiTrksAtEcalInToOut( prefix ); 
    CopyconvDEtaTrksAtEcalInToOut( prefix ); 
    CopyconvDxyInToOut( prefix ); 
    CopyconvDzInToOut( prefix ); 
    CopyconvLxyInToOut( prefix ); 
    CopyconvLzInToOut( prefix ); 
    CopyconvZofPrimVtxFromTrksInToOut( prefix ); 
    CopyconvNHitsBeforeVtx_0InToOut( prefix ); 
    CopyconvNHitsBeforeVtx_1InToOut( prefix ); 
    CopyconvNSharedHitsInToOut( prefix ); 
    CopyconvValidVtxInToOut( prefix ); 
    CopyconvMVALikelihoodInToOut( prefix ); 
    CopyconvChi2InToOut( prefix ); 
    CopyconvChi2ProbabilityInToOut( prefix ); 
    CopyconvTk1DzInToOut( prefix ); 
    CopyconvTk2DzInToOut( prefix ); 
    CopyconvTk1DzErrInToOut( prefix ); 
    CopyconvTk2DzErrInToOut( prefix ); 
    CopyconvCh1Ch2InToOut( prefix ); 
    CopyconvTk1D0InToOut( prefix ); 
    CopyconvTk1PoutInToOut( prefix ); 
    CopyconvTk1PinInToOut( prefix ); 
    CopyconvTk2D0InToOut( prefix ); 
    CopyconvTk2PoutInToOut( prefix ); 
    CopyconvTk2PinInToOut( prefix ); 
}

// The next set of functions allows one to copy 
// input variables to the outputs based on a key
// A copy function is generated for each pair of variables
// The copy function holds the name of the function to compare
// to the input key.  If the variables are vectors, a second function
// is generated that allows one to copy all variables matching a given key
// at a certain index and pushes that back on the output variable

void CopyPrefixBranchesInToOut( const std::string & prefix ) {
// Just call each copy function with the prefix 

    CopynHLTInToOut( prefix );
    CopyrunInToOut( prefix );
    CopyeventInToOut( prefix );
    CopylumisInToOut( prefix );
    CopyisDataInToOut( prefix );
    CopyHLTInToOut( prefix );
    CopyHLTIndexInToOut( prefix );
    CopybspotPosInToOut( prefix );
    CopynVtxInToOut( prefix );
    Copyvtx_xInToOut( prefix );
    Copyvtx_yInToOut( prefix );
    Copyvtx_zInToOut( prefix );
    CopyIsVtxGoodInToOut( prefix );
    CopynGoodVtxInToOut( prefix );
    CopynVtxBSInToOut( prefix );
    Copyvtxbs_xInToOut( prefix );
    Copyvtxbs_yInToOut( prefix );
    Copyvtxbs_zInToOut( prefix );
    CopypfMETInToOut( prefix );
    CopypfMETPhiInToOut( prefix );
    CopypfMETsumEtInToOut( prefix );
    CopypfMETmEtSigInToOut( prefix );
    CopypfMETSigInToOut( prefix );
    CopypfType01METInToOut( prefix );
    CopypfType01METPhiInToOut( prefix );
    CopypfType01METsumEtInToOut( prefix );
    CopypfType01METmEtSigInToOut( prefix );
    CopypfType01METSigInToOut( prefix );
    CopyrecoPfMETInToOut( prefix );
    CopyrecoPfMETPhiInToOut( prefix );
    CopyrecoPfMETsumEtInToOut( prefix );
    CopyrecoPfMETmEtSigInToOut( prefix );
    CopyrecoPfMETSigInToOut( prefix );
    CopytrkMETxPVInToOut( prefix );
    CopytrkMETyPVInToOut( prefix );
    CopytrkMETPhiPVInToOut( prefix );
    CopytrkMETPVInToOut( prefix );
    CopytrkMETxInToOut( prefix );
    CopytrkMETyInToOut( prefix );
    CopytrkMETPhiInToOut( prefix );
    CopytrkMETInToOut( prefix );
    CopymetFiltersInToOut( prefix );
    CopynEleInToOut( prefix );
    CopyeleTrgInToOut( prefix );
    CopyeleClassInToOut( prefix );
    CopyeleIsEcalDrivenInToOut( prefix );
    CopyeleChargeInToOut( prefix );
    CopyeleChargeConsistentInToOut( prefix );
    CopyeleEnInToOut( prefix );
    CopyeleEcalEnInToOut( prefix );
    CopyeleSCRawEnInToOut( prefix );
    CopyeleSCEnInToOut( prefix );
    CopyeleESEnInToOut( prefix );
    CopyelePtInToOut( prefix );
    CopyeleEtaInToOut( prefix );
    CopyelePhiInToOut( prefix );
    CopyeleR9InToOut( prefix );
    CopyeleEtaVtxInToOut( prefix );
    CopyelePhiVtxInToOut( prefix );
    CopyeleEtVtxInToOut( prefix );
    CopyeleSCEtaInToOut( prefix );
    CopyeleSCPhiInToOut( prefix );
    CopyeleSCEtaWidthInToOut( prefix );
    CopyeleSCPhiWidthInToOut( prefix );
    CopyeleVtx_xInToOut( prefix );
    CopyeleVtx_yInToOut( prefix );
    CopyeleVtx_zInToOut( prefix );
    CopyeleD0InToOut( prefix );
    CopyeleDzInToOut( prefix );
    CopyeleD0GVInToOut( prefix );
    CopyeleDzGVInToOut( prefix );
    CopyeleD0VtxInToOut( prefix );
    CopyeleDzVtxInToOut( prefix );
    CopyeleHoverEInToOut( prefix );
    CopyeleHoverE12InToOut( prefix );
    CopyeleEoverPInToOut( prefix );
    CopyelePinInToOut( prefix );
    CopyelePoutInToOut( prefix );
    CopyeleTrkMomErrInToOut( prefix );
    CopyeleBremInToOut( prefix );
    CopyeledEtaAtVtxInToOut( prefix );
    CopyeledPhiAtVtxInToOut( prefix );
    CopyeleSigmaIEtaIEtaInToOut( prefix );
    CopyeleSigmaIEtaIPhiInToOut( prefix );
    CopyeleSigmaIPhiIPhiInToOut( prefix );
    CopyeleEmaxInToOut( prefix );
    CopyeleE2ndMaxInToOut( prefix );
    CopyeleETopInToOut( prefix );
    CopyeleEBottomInToOut( prefix );
    CopyeleELeftInToOut( prefix );
    CopyeleERightInToOut( prefix );
    CopyeleE1x5InToOut( prefix );
    CopyeleE3x3InToOut( prefix );
    CopyeleE5x5InToOut( prefix );
    CopyeleE2x5MaxInToOut( prefix );
    CopyeleE2x5TopInToOut( prefix );
    CopyeleE2x5BottomInToOut( prefix );
    CopyeleE2x5LeftInToOut( prefix );
    CopyeleE2x5RightInToOut( prefix );
    CopyeleSeedEtaInToOut( prefix );
    CopyeleSeedEInToOut( prefix );
    CopyeleSeedPhiInToOut( prefix );
    CopyeleCrysEtaInToOut( prefix );
    CopyeleCrysPhiInToOut( prefix );
    CopyeleCrysIEtaInToOut( prefix );
    CopyeleCrysIPhiInToOut( prefix );
    CopyeleRegrEInToOut( prefix );
    CopyeleRegrEerrInToOut( prefix );
    CopyelePhoRegrEInToOut( prefix );
    CopyelePhoRegrEerrInToOut( prefix );
    CopyeleSeedTimeInToOut( prefix );
    CopyeleRecoFlagInToOut( prefix );
    CopyelePosInToOut( prefix );
    CopyeleIsoTrkDR03InToOut( prefix );
    CopyeleIsoEcalDR03InToOut( prefix );
    CopyeleIsoHcalDR03InToOut( prefix );
    CopyeleIsoHcalDR0312InToOut( prefix );
    CopyeleIsoTrkDR04InToOut( prefix );
    CopyeleIsoEcalDR04InToOut( prefix );
    CopyeleIsoHcalDR04InToOut( prefix );
    CopyeleIsoHcalDR0412InToOut( prefix );
    CopyeleModIsoTrkInToOut( prefix );
    CopyeleModIsoEcalInToOut( prefix );
    CopyeleModIsoHcalInToOut( prefix );
    CopyeleMissHitsInToOut( prefix );
    CopyeleConvDistInToOut( prefix );
    CopyeleConvDcotInToOut( prefix );
    CopyeleConvVtxFitInToOut( prefix );
    CopyeleIP3DInToOut( prefix );
    CopyeleIP3DErrInToOut( prefix );
    CopyeleIDMVANonTrigInToOut( prefix );
    CopyeleIDMVATrigInToOut( prefix );
    CopyelePFChIso03InToOut( prefix );
    CopyelePFPhoIso03InToOut( prefix );
    CopyelePFNeuIso03InToOut( prefix );
    CopyelePFChIso04InToOut( prefix );
    CopyelePFPhoIso04InToOut( prefix );
    CopyelePFNeuIso04InToOut( prefix );
    CopyeleESEffSigmaRR_xInToOut( prefix );
    CopyeleESEffSigmaRR_yInToOut( prefix );
    CopyeleESEffSigmaRR_zInToOut( prefix );
    CopynPhoInToOut( prefix );
    CopyphoTrgInToOut( prefix );
    CopyphoTrgFilterInToOut( prefix );
    CopyphoIsPhotonInToOut( prefix );
    CopyphoSCPos_xInToOut( prefix );
    CopyphoSCPos_yInToOut( prefix );
    CopyphoSCPos_zInToOut( prefix );
    CopyphoCaloPos_xInToOut( prefix );
    CopyphoCaloPos_yInToOut( prefix );
    CopyphoCaloPos_zInToOut( prefix );
    CopyphoEInToOut( prefix );
    CopyphoEtInToOut( prefix );
    CopyphoEtaInToOut( prefix );
    CopyphoVtx_xInToOut( prefix );
    CopyphoVtx_yInToOut( prefix );
    CopyphoVtx_zInToOut( prefix );
    CopyphoPhiInToOut( prefix );
    CopyphoEtVtxInToOut( prefix );
    CopyphoEtaVtxInToOut( prefix );
    CopyphoPhiVtxInToOut( prefix );
    CopyphoR9InToOut( prefix );
    CopyphoNClusInToOut( prefix );
    CopyphoTrkIsoHollowDR03InToOut( prefix );
    CopyphoEcalIsoDR03InToOut( prefix );
    CopyphoHcalIsoDR03InToOut( prefix );
    CopyphoHcalIsoDR0312InToOut( prefix );
    CopyphoTrkIsoHollowDR04InToOut( prefix );
    CopyphoCiCdRtoTrkInToOut( prefix );
    CopyphoEcalIsoDR04InToOut( prefix );
    CopyphoHcalIsoDR04InToOut( prefix );
    CopyphoHcalIsoDR0412InToOut( prefix );
    CopyphoHoverEInToOut( prefix );
    CopyphoHoverE12InToOut( prefix );
    CopyphoEleVetoInToOut( prefix );
    CopyphoSigmaIEtaIEtaInToOut( prefix );
    CopyphoSigmaIEtaIPhiInToOut( prefix );
    CopyphoSigmaIPhiIPhiInToOut( prefix );
    CopyphoCiCPF4phopfIso03InToOut( prefix );
    CopyphoCiCPF4phopfIso04InToOut( prefix );
    CopyphoEmaxInToOut( prefix );
    CopyphoETopInToOut( prefix );
    CopyphoEBottomInToOut( prefix );
    CopyphoELeftInToOut( prefix );
    CopyphoERightInToOut( prefix );
    CopyphoE2ndMaxInToOut( prefix );
    CopyphoE3x3InToOut( prefix );
    CopyphoE3x1InToOut( prefix );
    CopyphoE1x3InToOut( prefix );
    CopyphoE5x5InToOut( prefix );
    CopyphoE1x5InToOut( prefix );
    CopyphoE2x2InToOut( prefix );
    CopyphoE2x5MaxInToOut( prefix );
    CopyphoE2x5TopInToOut( prefix );
    CopyphoE2x5BottomInToOut( prefix );
    CopyphoE2x5LeftInToOut( prefix );
    CopyphoE2x5RightInToOut( prefix );
    CopyphoSeedEInToOut( prefix );
    CopyphoSeedEtaInToOut( prefix );
    CopyphoSeedPhiInToOut( prefix );
    CopyphoCrysEtaInToOut( prefix );
    CopyphoCrysPhiInToOut( prefix );
    CopyphoCrysIEtaInToOut( prefix );
    CopyphoCrysIPhiInToOut( prefix );
    CopyphoPFChIsoInToOut( prefix );
    CopyphoPFPhoIsoInToOut( prefix );
    CopyphoPFNeuIsoInToOut( prefix );
    CopyphoSCRChIsoInToOut( prefix );
    CopyphoSCRPhoIsoInToOut( prefix );
    CopyphoSCRNeuIsoInToOut( prefix );
    CopyphoSCRChIso04InToOut( prefix );
    CopyphoSCRPhoIso04InToOut( prefix );
    CopyphoSCRNeuIso04InToOut( prefix );
    CopyphoRandConeChIsoInToOut( prefix );
    CopyphoRandConePhoIsoInToOut( prefix );
    CopyphoRandConeNeuIsoInToOut( prefix );
    CopyphoRandConeChIso04InToOut( prefix );
    CopyphoRandConePhoIso04InToOut( prefix );
    CopyphoRandConeNeuIso04InToOut( prefix );
    CopyphoRegrEInToOut( prefix );
    CopyphoRegrEerrInToOut( prefix );
    CopyphoSeedTimeInToOut( prefix );
    CopyphoSeedDetId1InToOut( prefix );
    CopyphoSeedDetId2InToOut( prefix );
    CopyphoLICTDInToOut( prefix );
    CopyphoRecoFlagInToOut( prefix );
    CopyphoPosInToOut( prefix );
    CopyphoSCEInToOut( prefix );
    CopyphoSCRawEInToOut( prefix );
    CopyphoESEnInToOut( prefix );
    CopyphoSCEtInToOut( prefix );
    CopyphoSCEtaInToOut( prefix );
    CopyphoSCPhiInToOut( prefix );
    CopyphoSCEtaWidthInToOut( prefix );
    CopyphoSCPhiWidthInToOut( prefix );
    CopyphoSCBremInToOut( prefix );
    CopyphoOverlapInToOut( prefix );
    CopyphohasPixelSeedInToOut( prefix );
    Copypho_hasConvPfInToOut( prefix );
    Copypho_hasSLConvPfInToOut( prefix );
    Copypho_pfconvVtxZInToOut( prefix );
    Copypho_pfconvVtxZErrInToOut( prefix );
    Copypho_nSLConvInToOut( prefix );
    Copypho_pfSLConvPos_xInToOut( prefix );
    Copypho_pfSLConvPos_yInToOut( prefix );
    Copypho_pfSLConvPos_zInToOut( prefix );
    Copypho_pfSLConvVtxZInToOut( prefix );
    CopyphoIsConvInToOut( prefix );
    CopyphoNConvInToOut( prefix );
    CopyphoConvInvMassInToOut( prefix );
    CopyphoConvCotThetaInToOut( prefix );
    CopyphoConvEoverPInToOut( prefix );
    CopyphoConvZofPVfromTrksInToOut( prefix );
    CopyphoConvMinDistInToOut( prefix );
    CopyphoConvdPhiAtVtxInToOut( prefix );
    CopyphoConvdPhiAtCaloInToOut( prefix );
    CopyphoConvdEtaAtCaloInToOut( prefix );
    CopyphoConvTrkd0_xInToOut( prefix );
    CopyphoConvTrkd0_yInToOut( prefix );
    CopyphoConvTrkPin_xInToOut( prefix );
    CopyphoConvTrkPin_yInToOut( prefix );
    CopyphoConvTrkPout_xInToOut( prefix );
    CopyphoConvTrkPout_yInToOut( prefix );
    CopyphoConvTrkdz_xInToOut( prefix );
    CopyphoConvTrkdz_yInToOut( prefix );
    CopyphoConvTrkdzErr_xInToOut( prefix );
    CopyphoConvTrkdzErr_yInToOut( prefix );
    CopyphoConvChi2InToOut( prefix );
    CopyphoConvChi2ProbInToOut( prefix );
    CopyphoConvNTrksInToOut( prefix );
    CopyphoConvCharge1InToOut( prefix );
    CopyphoConvCharge2InToOut( prefix );
    CopyphoConvValidVtxInToOut( prefix );
    CopyphoConvLikeLihoodInToOut( prefix );
    CopyphoConvP4_0InToOut( prefix );
    CopyphoConvP4_1InToOut( prefix );
    CopyphoConvP4_2InToOut( prefix );
    CopyphoConvP4_3InToOut( prefix );
    CopyphoConvVtx_xInToOut( prefix );
    CopyphoConvVtx_yInToOut( prefix );
    CopyphoConvVtx_zInToOut( prefix );
    CopyphoConvVtxErr_xInToOut( prefix );
    CopyphoConvVtxErr_yInToOut( prefix );
    CopyphoConvVtxErr_zInToOut( prefix );
    CopyphoConvPairMomentum_xInToOut( prefix );
    CopyphoConvPairMomentum_yInToOut( prefix );
    CopyphoConvPairMomentum_zInToOut( prefix );
    CopyphoConvRefittedMomentum_xInToOut( prefix );
    CopyphoConvRefittedMomentum_yInToOut( prefix );
    CopyphoConvRefittedMomentum_zInToOut( prefix );
    CopySingleLegConvInToOut( prefix );
    CopyphoPFConvVtx_xInToOut( prefix );
    CopyphoPFConvVtx_yInToOut( prefix );
    CopyphoPFConvVtx_zInToOut( prefix );
    CopyphoPFConvMom_xInToOut( prefix );
    CopyphoPFConvMom_yInToOut( prefix );
    CopyphoPFConvMom_zInToOut( prefix );
    CopyphoESEffSigmaRR_xInToOut( prefix );
    CopyphoESEffSigmaRR_yInToOut( prefix );
    CopyphoESEffSigmaRR_zInToOut( prefix );
    CopynMuInToOut( prefix );
    CopymuTrgInToOut( prefix );
    CopymuEtaInToOut( prefix );
    CopymuPhiInToOut( prefix );
    CopymuChargeInToOut( prefix );
    CopymuPtInToOut( prefix );
    CopymuPzInToOut( prefix );
    CopymuVtx_xInToOut( prefix );
    CopymuVtx_yInToOut( prefix );
    CopymuVtx_zInToOut( prefix );
    CopymuVtxGlb_xInToOut( prefix );
    CopymuVtxGlb_yInToOut( prefix );
    CopymuVtxGlb_zInToOut( prefix );
    CopymucktPtInToOut( prefix );
    CopymucktPtErrInToOut( prefix );
    CopymucktEtaInToOut( prefix );
    CopymucktPhiInToOut( prefix );
    CopymucktdxyInToOut( prefix );
    CopymucktdzInToOut( prefix );
    CopymuIsoTrkInToOut( prefix );
    CopymuIsoCaloInToOut( prefix );
    CopymuIsoEcalInToOut( prefix );
    CopymuIsoHcalInToOut( prefix );
    CopymuChi2NDFInToOut( prefix );
    CopymuInnerChi2NDFInToOut( prefix );
    CopymuPFIsoR04_CHInToOut( prefix );
    CopymuPFIsoR04_NHInToOut( prefix );
    CopymuPFIsoR04_PhoInToOut( prefix );
    CopymuPFIsoR04_PUInToOut( prefix );
    CopymuPFIsoR04_CPartInToOut( prefix );
    CopymuPFIsoR04_NHHTInToOut( prefix );
    CopymuPFIsoR04_PhoHTInToOut( prefix );
    CopymuPFIsoR03_CHInToOut( prefix );
    CopymuPFIsoR03_NHInToOut( prefix );
    CopymuPFIsoR03_PhoInToOut( prefix );
    CopymuPFIsoR03_PUInToOut( prefix );
    CopymuPFIsoR03_CPartInToOut( prefix );
    CopymuPFIsoR03_NHHTInToOut( prefix );
    CopymuPFIsoR03_PhoHTInToOut( prefix );
    CopymuTypeInToOut( prefix );
    CopymuD0InToOut( prefix );
    CopymuDzInToOut( prefix );
    CopymuD0GVInToOut( prefix );
    CopymuDzGVInToOut( prefix );
    CopymuD0VtxInToOut( prefix );
    CopymuDzVtxInToOut( prefix );
    CopymuInnerD0InToOut( prefix );
    CopymuInnerDzInToOut( prefix );
    CopymuInnerD0GVInToOut( prefix );
    CopymuInnerDzGVInToOut( prefix );
    CopymuInnerPtInToOut( prefix );
    CopymuInnerPtErrInToOut( prefix );
    CopymuNumberOfValidTrkLayersInToOut( prefix );
    CopymuNumberOfValidTrkHitsInToOut( prefix );
    CopymuNumberOfValidPixelLayersInToOut( prefix );
    CopymuNumberOfValidPixelHitsInToOut( prefix );
    CopymuNumberOfValidMuonHitsInToOut( prefix );
    CopymuStationsInToOut( prefix );
    CopymuChambersInToOut( prefix );
    CopymuIP3DInToOut( prefix );
    CopymuIP3DErrInToOut( prefix );
    CopynTauInToOut( prefix );
    CopytauDecayModeFindingInToOut( prefix );
    CopytauAgainstElectronLooseMVA3InToOut( prefix );
    CopytauAgainstElectronMediumMVA3InToOut( prefix );
    CopytauAgainstElectronTightMVA3InToOut( prefix );
    CopytauAgainstElectronVTightMVA3InToOut( prefix );
    CopytauAgainstElectronDeadECALInToOut( prefix );
    CopytauAgainstMuonLoose2InToOut( prefix );
    CopytauAgainstMuonMedium2InToOut( prefix );
    CopytauAgainstMuonTight2InToOut( prefix );
    CopytauCombinedIsolationDeltaBetaCorrRaw3HitsInToOut( prefix );
    CopytauLooseCombinedIsolationDeltaBetaCorr3HitsInToOut( prefix );
    CopytauMediumCombinedIsolationDeltaBetaCorr3HitsInToOut( prefix );
    CopytauTightCombinedIsolationDeltaBetaCorr3HitsInToOut( prefix );
    CopytauEtaInToOut( prefix );
    CopytauPhiInToOut( prefix );
    CopytauPtInToOut( prefix );
    CopytauEtInToOut( prefix );
    CopytauChargeInToOut( prefix );
    CopytauDecayModeInToOut( prefix );
    CopytauEMFractionInToOut( prefix );
    CopytauHCAL3x3OverPLeadInToOut( prefix );
    CopytauHCALMaxOverPLeadInToOut( prefix );
    CopytauHCALTotOverPLeadInToOut( prefix );
    CopytauIsolationPFChargedHadrCandsPtSumInToOut( prefix );
    CopytauIsolationPFGammaCandsEtSumInToOut( prefix );
    CopytauLeadPFChargedHadrCandsignedSiptInToOut( prefix );
    CopytauLeadChargedHadronExistsInToOut( prefix );
    CopytauLeadChargedHadronEtaInToOut( prefix );
    CopytauLeadChargedHadronPhiInToOut( prefix );
    CopytauLeadChargedHadronPtInToOut( prefix );
    Copyrho25InToOut( prefix );
    Copyrho25_neuInToOut( prefix );
    Copyrho25_muPFisoInToOut( prefix );
    Copyrho25_elePFisoInToOut( prefix );
    Copyrho2011InToOut( prefix );
    Copyrho2012InToOut( prefix );
    CopyQGTag_MLPInToOut( prefix );
    CopyQGTag_likelihoodInToOut( prefix );
    CopynCA8JetInToOut( prefix );
    CopynJetInToOut( prefix );
    CopyjetTrgInToOut( prefix );
    CopyjetEnInToOut( prefix );
    CopyjetPtInToOut( prefix );
    CopyjetEtaInToOut( prefix );
    CopyjetPhiInToOut( prefix );
    CopyjetChargeInToOut( prefix );
    CopyjetEtInToOut( prefix );
    CopyjetRawPtInToOut( prefix );
    CopyjetRawEnInToOut( prefix );
    CopyjetAreaInToOut( prefix );
    CopyjetCHFInToOut( prefix );
    CopyjetNHFInToOut( prefix );
    CopyjetCEFInToOut( prefix );
    CopyjetNEFInToOut( prefix );
    CopyjetNCHInToOut( prefix );
    CopyjetHFHAEInToOut( prefix );
    CopyjetHFEMEInToOut( prefix );
    CopyjetNConstituentsInToOut( prefix );
    CopyjetCombinedSecondaryVtxBJetTagsInToOut( prefix );
    CopyjetCombinedSecondaryVtxMVABJetTagsInToOut( prefix );
    CopyjetJetProbabilityBJetTagsInToOut( prefix );
    CopyjetJetBProbabilityBJetTagsInToOut( prefix );
    CopyjetPFLooseIdInToOut( prefix );
    CopyjetDRMeanInToOut( prefix );
    CopyjetDR2MeanInToOut( prefix );
    CopyjetDZInToOut( prefix );
    CopyjetFrac01InToOut( prefix );
    CopyjetFrac02InToOut( prefix );
    CopyjetFrac03InToOut( prefix );
    CopyjetFrac04InToOut( prefix );
    CopyjetFrac05InToOut( prefix );
    CopyjetFrac06InToOut( prefix );
    CopyjetFrac07InToOut( prefix );
    CopyjetBetaInToOut( prefix );
    CopyjetBetaStarCMGInToOut( prefix );
    CopyjetBetaStarClassicInToOut( prefix );
    CopyjetNNeutralsInToOut( prefix );
    CopyjetNChargedInToOut( prefix );
    CopyjetWPLevelsInToOut( prefix );
    CopyjetMVAsExt_cutBasedInToOut( prefix );
    CopyjetMVAsExt_philv1InToOut( prefix );
    CopyjetWPLevelsExt_philv1InToOut( prefix );
    CopyjetMtInToOut( prefix );
    CopyjetJECUncInToOut( prefix );
    CopyjetLeadTrackPtInToOut( prefix );
    CopyjetVtxPtInToOut( prefix );
    CopyjetVtxMassInToOut( prefix );
    CopyjetVtx3dLInToOut( prefix );
    CopyjetVtx3deLInToOut( prefix );
    CopyjetSoftLeptPtInToOut( prefix );
    CopyjetSoftLeptPtRelInToOut( prefix );
    CopyjetSoftLeptdRInToOut( prefix );
    CopyjetSoftLeptIdlooseMuInToOut( prefix );
    CopyjetSoftLeptIdEle95InToOut( prefix );
    CopyjetDPhiMETJetInToOut( prefix );
    CopyjetPuJetIdLInToOut( prefix );
    CopyjetPuJetIdMInToOut( prefix );
    CopyjetPuJetIdTInToOut( prefix );
    CopynConvInToOut( prefix );
    CopyconvP4_xInToOut( prefix );
    CopyconvP4_yInToOut( prefix );
    CopyconvP4_zInToOut( prefix );
    CopyconvP4_EInToOut( prefix );
    CopyconvVtx_xInToOut( prefix );
    CopyconvVtx_yInToOut( prefix );
    CopyconvVtx_zInToOut( prefix );
    CopyconvVtxErr_xInToOut( prefix );
    CopyconvVtxErr_yInToOut( prefix );
    CopyconvVtxErr_zInToOut( prefix );
    CopyconvPairMomentum_xInToOut( prefix );
    CopyconvPairMomentum_yInToOut( prefix );
    CopyconvPairMomentum_zInToOut( prefix );
    CopyconvRefittedMomentum_xInToOut( prefix );
    CopyconvRefittedMomentum_yInToOut( prefix );
    CopyconvRefittedMomentum_zInToOut( prefix );
    CopyconvNTracksInToOut( prefix );
    CopyconvPairInvMassInToOut( prefix );
    CopyconvPairCotThetaSepInToOut( prefix );
    CopyconvEoverPInToOut( prefix );
    CopyconvDistOfMinApproachInToOut( prefix );
    CopyconvDPhiTrksAtVtxInToOut( prefix );
    CopyconvDPhiTrksAtEcalInToOut( prefix );
    CopyconvDEtaTrksAtEcalInToOut( prefix );
    CopyconvDxyInToOut( prefix );
    CopyconvDzInToOut( prefix );
    CopyconvLxyInToOut( prefix );
    CopyconvLzInToOut( prefix );
    CopyconvZofPrimVtxFromTrksInToOut( prefix );
    CopyconvNHitsBeforeVtx_0InToOut( prefix );
    CopyconvNHitsBeforeVtx_1InToOut( prefix );
    CopyconvNSharedHitsInToOut( prefix );
    CopyconvValidVtxInToOut( prefix );
    CopyconvMVALikelihoodInToOut( prefix );
    CopyconvChi2InToOut( prefix );
    CopyconvChi2ProbabilityInToOut( prefix );
    CopyconvTk1DzInToOut( prefix );
    CopyconvTk2DzInToOut( prefix );
    CopyconvTk1DzErrInToOut( prefix );
    CopyconvTk2DzErrInToOut( prefix );
    CopyconvCh1Ch2InToOut( prefix );
    CopyconvTk1D0InToOut( prefix );
    CopyconvTk1PoutInToOut( prefix );
    CopyconvTk1PinInToOut( prefix );
    CopyconvTk2D0InToOut( prefix );
    CopyconvTk2PoutInToOut( prefix );
    CopyconvTk2PinInToOut( prefix );
}; 

void CopyPrefixIndexBranchesInToOut( const std::string & prefix, unsigned index ) { 

// Just call each copy function with the prefix 

    Copyvtx_xInToOutIndex( index, prefix );
    Copyvtx_yInToOutIndex( index, prefix );
    Copyvtx_zInToOutIndex( index, prefix );
    Copyvtxbs_xInToOutIndex( index, prefix );
    Copyvtxbs_yInToOutIndex( index, prefix );
    Copyvtxbs_zInToOutIndex( index, prefix );
    CopytrkMETxInToOutIndex( index, prefix );
    CopytrkMETyInToOutIndex( index, prefix );
    CopytrkMETPhiInToOutIndex( index, prefix );
    CopytrkMETInToOutIndex( index, prefix );
    CopyeleTrgInToOutIndex( index, prefix );
    CopyeleClassInToOutIndex( index, prefix );
    CopyeleIsEcalDrivenInToOutIndex( index, prefix );
    CopyeleChargeInToOutIndex( index, prefix );
    CopyeleChargeConsistentInToOutIndex( index, prefix );
    CopyeleEnInToOutIndex( index, prefix );
    CopyeleEcalEnInToOutIndex( index, prefix );
    CopyeleSCRawEnInToOutIndex( index, prefix );
    CopyeleSCEnInToOutIndex( index, prefix );
    CopyeleESEnInToOutIndex( index, prefix );
    CopyelePtInToOutIndex( index, prefix );
    CopyeleEtaInToOutIndex( index, prefix );
    CopyelePhiInToOutIndex( index, prefix );
    CopyeleR9InToOutIndex( index, prefix );
    CopyeleEtaVtxInToOutIndex( index, prefix );
    CopyelePhiVtxInToOutIndex( index, prefix );
    CopyeleEtVtxInToOutIndex( index, prefix );
    CopyeleSCEtaInToOutIndex( index, prefix );
    CopyeleSCPhiInToOutIndex( index, prefix );
    CopyeleSCEtaWidthInToOutIndex( index, prefix );
    CopyeleSCPhiWidthInToOutIndex( index, prefix );
    CopyeleVtx_xInToOutIndex( index, prefix );
    CopyeleVtx_yInToOutIndex( index, prefix );
    CopyeleVtx_zInToOutIndex( index, prefix );
    CopyeleD0InToOutIndex( index, prefix );
    CopyeleDzInToOutIndex( index, prefix );
    CopyeleD0GVInToOutIndex( index, prefix );
    CopyeleDzGVInToOutIndex( index, prefix );
    CopyeleD0VtxInToOutIndex( index, prefix );
    CopyeleDzVtxInToOutIndex( index, prefix );
    CopyeleHoverEInToOutIndex( index, prefix );
    CopyeleHoverE12InToOutIndex( index, prefix );
    CopyeleEoverPInToOutIndex( index, prefix );
    CopyelePinInToOutIndex( index, prefix );
    CopyelePoutInToOutIndex( index, prefix );
    CopyeleTrkMomErrInToOutIndex( index, prefix );
    CopyeleBremInToOutIndex( index, prefix );
    CopyeledEtaAtVtxInToOutIndex( index, prefix );
    CopyeledPhiAtVtxInToOutIndex( index, prefix );
    CopyeleSigmaIEtaIEtaInToOutIndex( index, prefix );
    CopyeleSigmaIEtaIPhiInToOutIndex( index, prefix );
    CopyeleSigmaIPhiIPhiInToOutIndex( index, prefix );
    CopyeleEmaxInToOutIndex( index, prefix );
    CopyeleE2ndMaxInToOutIndex( index, prefix );
    CopyeleETopInToOutIndex( index, prefix );
    CopyeleEBottomInToOutIndex( index, prefix );
    CopyeleELeftInToOutIndex( index, prefix );
    CopyeleERightInToOutIndex( index, prefix );
    CopyeleE1x5InToOutIndex( index, prefix );
    CopyeleE3x3InToOutIndex( index, prefix );
    CopyeleE5x5InToOutIndex( index, prefix );
    CopyeleE2x5MaxInToOutIndex( index, prefix );
    CopyeleE2x5TopInToOutIndex( index, prefix );
    CopyeleE2x5BottomInToOutIndex( index, prefix );
    CopyeleE2x5LeftInToOutIndex( index, prefix );
    CopyeleE2x5RightInToOutIndex( index, prefix );
    CopyeleSeedEtaInToOutIndex( index, prefix );
    CopyeleSeedEInToOutIndex( index, prefix );
    CopyeleSeedPhiInToOutIndex( index, prefix );
    CopyeleCrysEtaInToOutIndex( index, prefix );
    CopyeleCrysPhiInToOutIndex( index, prefix );
    CopyeleCrysIEtaInToOutIndex( index, prefix );
    CopyeleCrysIPhiInToOutIndex( index, prefix );
    CopyeleRegrEInToOutIndex( index, prefix );
    CopyeleRegrEerrInToOutIndex( index, prefix );
    CopyelePhoRegrEInToOutIndex( index, prefix );
    CopyelePhoRegrEerrInToOutIndex( index, prefix );
    CopyeleSeedTimeInToOutIndex( index, prefix );
    CopyeleRecoFlagInToOutIndex( index, prefix );
    CopyelePosInToOutIndex( index, prefix );
    CopyeleIsoTrkDR03InToOutIndex( index, prefix );
    CopyeleIsoEcalDR03InToOutIndex( index, prefix );
    CopyeleIsoHcalDR03InToOutIndex( index, prefix );
    CopyeleIsoHcalDR0312InToOutIndex( index, prefix );
    CopyeleIsoTrkDR04InToOutIndex( index, prefix );
    CopyeleIsoEcalDR04InToOutIndex( index, prefix );
    CopyeleIsoHcalDR04InToOutIndex( index, prefix );
    CopyeleIsoHcalDR0412InToOutIndex( index, prefix );
    CopyeleModIsoTrkInToOutIndex( index, prefix );
    CopyeleModIsoEcalInToOutIndex( index, prefix );
    CopyeleModIsoHcalInToOutIndex( index, prefix );
    CopyeleMissHitsInToOutIndex( index, prefix );
    CopyeleConvDistInToOutIndex( index, prefix );
    CopyeleConvDcotInToOutIndex( index, prefix );
    CopyeleConvVtxFitInToOutIndex( index, prefix );
    CopyeleIP3DInToOutIndex( index, prefix );
    CopyeleIP3DErrInToOutIndex( index, prefix );
    CopyeleIDMVANonTrigInToOutIndex( index, prefix );
    CopyeleIDMVATrigInToOutIndex( index, prefix );
    CopyelePFChIso03InToOutIndex( index, prefix );
    CopyelePFPhoIso03InToOutIndex( index, prefix );
    CopyelePFNeuIso03InToOutIndex( index, prefix );
    CopyelePFChIso04InToOutIndex( index, prefix );
    CopyelePFPhoIso04InToOutIndex( index, prefix );
    CopyelePFNeuIso04InToOutIndex( index, prefix );
    CopyeleESEffSigmaRR_xInToOutIndex( index, prefix );
    CopyeleESEffSigmaRR_yInToOutIndex( index, prefix );
    CopyeleESEffSigmaRR_zInToOutIndex( index, prefix );
    CopyphoTrgInToOutIndex( index, prefix );
    CopyphoTrgFilterInToOutIndex( index, prefix );
    CopyphoIsPhotonInToOutIndex( index, prefix );
    CopyphoSCPos_xInToOutIndex( index, prefix );
    CopyphoSCPos_yInToOutIndex( index, prefix );
    CopyphoSCPos_zInToOutIndex( index, prefix );
    CopyphoCaloPos_xInToOutIndex( index, prefix );
    CopyphoCaloPos_yInToOutIndex( index, prefix );
    CopyphoCaloPos_zInToOutIndex( index, prefix );
    CopyphoEInToOutIndex( index, prefix );
    CopyphoEtInToOutIndex( index, prefix );
    CopyphoEtaInToOutIndex( index, prefix );
    CopyphoVtx_xInToOutIndex( index, prefix );
    CopyphoVtx_yInToOutIndex( index, prefix );
    CopyphoVtx_zInToOutIndex( index, prefix );
    CopyphoPhiInToOutIndex( index, prefix );
    CopyphoEtVtxInToOutIndex( index, prefix );
    CopyphoEtaVtxInToOutIndex( index, prefix );
    CopyphoPhiVtxInToOutIndex( index, prefix );
    CopyphoR9InToOutIndex( index, prefix );
    CopyphoNClusInToOutIndex( index, prefix );
    CopyphoTrkIsoHollowDR03InToOutIndex( index, prefix );
    CopyphoEcalIsoDR03InToOutIndex( index, prefix );
    CopyphoHcalIsoDR03InToOutIndex( index, prefix );
    CopyphoHcalIsoDR0312InToOutIndex( index, prefix );
    CopyphoTrkIsoHollowDR04InToOutIndex( index, prefix );
    CopyphoCiCdRtoTrkInToOutIndex( index, prefix );
    CopyphoEcalIsoDR04InToOutIndex( index, prefix );
    CopyphoHcalIsoDR04InToOutIndex( index, prefix );
    CopyphoHcalIsoDR0412InToOutIndex( index, prefix );
    CopyphoHoverEInToOutIndex( index, prefix );
    CopyphoHoverE12InToOutIndex( index, prefix );
    CopyphoEleVetoInToOutIndex( index, prefix );
    CopyphoSigmaIEtaIEtaInToOutIndex( index, prefix );
    CopyphoSigmaIEtaIPhiInToOutIndex( index, prefix );
    CopyphoSigmaIPhiIPhiInToOutIndex( index, prefix );
    CopyphoCiCPF4phopfIso03InToOutIndex( index, prefix );
    CopyphoCiCPF4phopfIso04InToOutIndex( index, prefix );
    CopyphoEmaxInToOutIndex( index, prefix );
    CopyphoETopInToOutIndex( index, prefix );
    CopyphoEBottomInToOutIndex( index, prefix );
    CopyphoELeftInToOutIndex( index, prefix );
    CopyphoERightInToOutIndex( index, prefix );
    CopyphoE2ndMaxInToOutIndex( index, prefix );
    CopyphoE3x3InToOutIndex( index, prefix );
    CopyphoE3x1InToOutIndex( index, prefix );
    CopyphoE1x3InToOutIndex( index, prefix );
    CopyphoE5x5InToOutIndex( index, prefix );
    CopyphoE1x5InToOutIndex( index, prefix );
    CopyphoE2x2InToOutIndex( index, prefix );
    CopyphoE2x5MaxInToOutIndex( index, prefix );
    CopyphoE2x5TopInToOutIndex( index, prefix );
    CopyphoE2x5BottomInToOutIndex( index, prefix );
    CopyphoE2x5LeftInToOutIndex( index, prefix );
    CopyphoE2x5RightInToOutIndex( index, prefix );
    CopyphoSeedEInToOutIndex( index, prefix );
    CopyphoSeedEtaInToOutIndex( index, prefix );
    CopyphoSeedPhiInToOutIndex( index, prefix );
    CopyphoCrysEtaInToOutIndex( index, prefix );
    CopyphoCrysPhiInToOutIndex( index, prefix );
    CopyphoCrysIEtaInToOutIndex( index, prefix );
    CopyphoCrysIPhiInToOutIndex( index, prefix );
    CopyphoPFChIsoInToOutIndex( index, prefix );
    CopyphoPFPhoIsoInToOutIndex( index, prefix );
    CopyphoPFNeuIsoInToOutIndex( index, prefix );
    CopyphoSCRChIsoInToOutIndex( index, prefix );
    CopyphoSCRPhoIsoInToOutIndex( index, prefix );
    CopyphoSCRNeuIsoInToOutIndex( index, prefix );
    CopyphoSCRChIso04InToOutIndex( index, prefix );
    CopyphoSCRPhoIso04InToOutIndex( index, prefix );
    CopyphoSCRNeuIso04InToOutIndex( index, prefix );
    CopyphoRandConeChIsoInToOutIndex( index, prefix );
    CopyphoRandConePhoIsoInToOutIndex( index, prefix );
    CopyphoRandConeNeuIsoInToOutIndex( index, prefix );
    CopyphoRandConeChIso04InToOutIndex( index, prefix );
    CopyphoRandConePhoIso04InToOutIndex( index, prefix );
    CopyphoRandConeNeuIso04InToOutIndex( index, prefix );
    CopyphoRegrEInToOutIndex( index, prefix );
    CopyphoRegrEerrInToOutIndex( index, prefix );
    CopyphoSeedTimeInToOutIndex( index, prefix );
    CopyphoSeedDetId1InToOutIndex( index, prefix );
    CopyphoSeedDetId2InToOutIndex( index, prefix );
    CopyphoLICTDInToOutIndex( index, prefix );
    CopyphoRecoFlagInToOutIndex( index, prefix );
    CopyphoPosInToOutIndex( index, prefix );
    CopyphoSCEInToOutIndex( index, prefix );
    CopyphoSCRawEInToOutIndex( index, prefix );
    CopyphoESEnInToOutIndex( index, prefix );
    CopyphoSCEtInToOutIndex( index, prefix );
    CopyphoSCEtaInToOutIndex( index, prefix );
    CopyphoSCPhiInToOutIndex( index, prefix );
    CopyphoSCEtaWidthInToOutIndex( index, prefix );
    CopyphoSCPhiWidthInToOutIndex( index, prefix );
    CopyphoSCBremInToOutIndex( index, prefix );
    CopyphoOverlapInToOutIndex( index, prefix );
    CopyphohasPixelSeedInToOutIndex( index, prefix );
    Copypho_hasConvPfInToOutIndex( index, prefix );
    Copypho_hasSLConvPfInToOutIndex( index, prefix );
    Copypho_pfconvVtxZInToOutIndex( index, prefix );
    Copypho_pfconvVtxZErrInToOutIndex( index, prefix );
    Copypho_nSLConvInToOutIndex( index, prefix );
    Copypho_pfSLConvPos_xInToOutIndex( index, prefix );
    Copypho_pfSLConvPos_yInToOutIndex( index, prefix );
    Copypho_pfSLConvPos_zInToOutIndex( index, prefix );
    Copypho_pfSLConvVtxZInToOutIndex( index, prefix );
    CopyphoIsConvInToOutIndex( index, prefix );
    CopyphoNConvInToOutIndex( index, prefix );
    CopyphoConvInvMassInToOutIndex( index, prefix );
    CopyphoConvCotThetaInToOutIndex( index, prefix );
    CopyphoConvEoverPInToOutIndex( index, prefix );
    CopyphoConvZofPVfromTrksInToOutIndex( index, prefix );
    CopyphoConvMinDistInToOutIndex( index, prefix );
    CopyphoConvdPhiAtVtxInToOutIndex( index, prefix );
    CopyphoConvdPhiAtCaloInToOutIndex( index, prefix );
    CopyphoConvdEtaAtCaloInToOutIndex( index, prefix );
    CopyphoConvTrkd0_xInToOutIndex( index, prefix );
    CopyphoConvTrkd0_yInToOutIndex( index, prefix );
    CopyphoConvTrkPin_xInToOutIndex( index, prefix );
    CopyphoConvTrkPin_yInToOutIndex( index, prefix );
    CopyphoConvTrkPout_xInToOutIndex( index, prefix );
    CopyphoConvTrkPout_yInToOutIndex( index, prefix );
    CopyphoConvTrkdz_xInToOutIndex( index, prefix );
    CopyphoConvTrkdz_yInToOutIndex( index, prefix );
    CopyphoConvTrkdzErr_xInToOutIndex( index, prefix );
    CopyphoConvTrkdzErr_yInToOutIndex( index, prefix );
    CopyphoConvChi2InToOutIndex( index, prefix );
    CopyphoConvChi2ProbInToOutIndex( index, prefix );
    CopyphoConvNTrksInToOutIndex( index, prefix );
    CopyphoConvCharge1InToOutIndex( index, prefix );
    CopyphoConvCharge2InToOutIndex( index, prefix );
    CopyphoConvValidVtxInToOutIndex( index, prefix );
    CopyphoConvLikeLihoodInToOutIndex( index, prefix );
    CopyphoConvP4_0InToOutIndex( index, prefix );
    CopyphoConvP4_1InToOutIndex( index, prefix );
    CopyphoConvP4_2InToOutIndex( index, prefix );
    CopyphoConvP4_3InToOutIndex( index, prefix );
    CopyphoConvVtx_xInToOutIndex( index, prefix );
    CopyphoConvVtx_yInToOutIndex( index, prefix );
    CopyphoConvVtx_zInToOutIndex( index, prefix );
    CopyphoConvVtxErr_xInToOutIndex( index, prefix );
    CopyphoConvVtxErr_yInToOutIndex( index, prefix );
    CopyphoConvVtxErr_zInToOutIndex( index, prefix );
    CopyphoConvPairMomentum_xInToOutIndex( index, prefix );
    CopyphoConvPairMomentum_yInToOutIndex( index, prefix );
    CopyphoConvPairMomentum_zInToOutIndex( index, prefix );
    CopyphoConvRefittedMomentum_xInToOutIndex( index, prefix );
    CopyphoConvRefittedMomentum_yInToOutIndex( index, prefix );
    CopyphoConvRefittedMomentum_zInToOutIndex( index, prefix );
    CopySingleLegConvInToOutIndex( index, prefix );
    CopyphoPFConvVtx_xInToOutIndex( index, prefix );
    CopyphoPFConvVtx_yInToOutIndex( index, prefix );
    CopyphoPFConvVtx_zInToOutIndex( index, prefix );
    CopyphoPFConvMom_xInToOutIndex( index, prefix );
    CopyphoPFConvMom_yInToOutIndex( index, prefix );
    CopyphoPFConvMom_zInToOutIndex( index, prefix );
    CopyphoESEffSigmaRR_xInToOutIndex( index, prefix );
    CopyphoESEffSigmaRR_yInToOutIndex( index, prefix );
    CopyphoESEffSigmaRR_zInToOutIndex( index, prefix );
    CopymuTrgInToOutIndex( index, prefix );
    CopymuEtaInToOutIndex( index, prefix );
    CopymuPhiInToOutIndex( index, prefix );
    CopymuChargeInToOutIndex( index, prefix );
    CopymuPtInToOutIndex( index, prefix );
    CopymuPzInToOutIndex( index, prefix );
    CopymuVtx_xInToOutIndex( index, prefix );
    CopymuVtx_yInToOutIndex( index, prefix );
    CopymuVtx_zInToOutIndex( index, prefix );
    CopymuVtxGlb_xInToOutIndex( index, prefix );
    CopymuVtxGlb_yInToOutIndex( index, prefix );
    CopymuVtxGlb_zInToOutIndex( index, prefix );
    CopymucktPtInToOutIndex( index, prefix );
    CopymucktPtErrInToOutIndex( index, prefix );
    CopymucktEtaInToOutIndex( index, prefix );
    CopymucktPhiInToOutIndex( index, prefix );
    CopymucktdxyInToOutIndex( index, prefix );
    CopymucktdzInToOutIndex( index, prefix );
    CopymuIsoTrkInToOutIndex( index, prefix );
    CopymuIsoCaloInToOutIndex( index, prefix );
    CopymuIsoEcalInToOutIndex( index, prefix );
    CopymuIsoHcalInToOutIndex( index, prefix );
    CopymuChi2NDFInToOutIndex( index, prefix );
    CopymuInnerChi2NDFInToOutIndex( index, prefix );
    CopymuPFIsoR04_CHInToOutIndex( index, prefix );
    CopymuPFIsoR04_NHInToOutIndex( index, prefix );
    CopymuPFIsoR04_PhoInToOutIndex( index, prefix );
    CopymuPFIsoR04_PUInToOutIndex( index, prefix );
    CopymuPFIsoR04_CPartInToOutIndex( index, prefix );
    CopymuPFIsoR04_NHHTInToOutIndex( index, prefix );
    CopymuPFIsoR04_PhoHTInToOutIndex( index, prefix );
    CopymuPFIsoR03_CHInToOutIndex( index, prefix );
    CopymuPFIsoR03_NHInToOutIndex( index, prefix );
    CopymuPFIsoR03_PhoInToOutIndex( index, prefix );
    CopymuPFIsoR03_PUInToOutIndex( index, prefix );
    CopymuPFIsoR03_CPartInToOutIndex( index, prefix );
    CopymuPFIsoR03_NHHTInToOutIndex( index, prefix );
    CopymuPFIsoR03_PhoHTInToOutIndex( index, prefix );
    CopymuTypeInToOutIndex( index, prefix );
    CopymuD0InToOutIndex( index, prefix );
    CopymuDzInToOutIndex( index, prefix );
    CopymuD0GVInToOutIndex( index, prefix );
    CopymuDzGVInToOutIndex( index, prefix );
    CopymuD0VtxInToOutIndex( index, prefix );
    CopymuDzVtxInToOutIndex( index, prefix );
    CopymuInnerD0InToOutIndex( index, prefix );
    CopymuInnerDzInToOutIndex( index, prefix );
    CopymuInnerD0GVInToOutIndex( index, prefix );
    CopymuInnerDzGVInToOutIndex( index, prefix );
    CopymuInnerPtInToOutIndex( index, prefix );
    CopymuInnerPtErrInToOutIndex( index, prefix );
    CopymuNumberOfValidTrkLayersInToOutIndex( index, prefix );
    CopymuNumberOfValidTrkHitsInToOutIndex( index, prefix );
    CopymuNumberOfValidPixelLayersInToOutIndex( index, prefix );
    CopymuNumberOfValidPixelHitsInToOutIndex( index, prefix );
    CopymuNumberOfValidMuonHitsInToOutIndex( index, prefix );
    CopymuStationsInToOutIndex( index, prefix );
    CopymuChambersInToOutIndex( index, prefix );
    CopymuIP3DInToOutIndex( index, prefix );
    CopymuIP3DErrInToOutIndex( index, prefix );
    CopytauDecayModeFindingInToOutIndex( index, prefix );
    CopytauAgainstElectronLooseMVA3InToOutIndex( index, prefix );
    CopytauAgainstElectronMediumMVA3InToOutIndex( index, prefix );
    CopytauAgainstElectronTightMVA3InToOutIndex( index, prefix );
    CopytauAgainstElectronVTightMVA3InToOutIndex( index, prefix );
    CopytauAgainstElectronDeadECALInToOutIndex( index, prefix );
    CopytauAgainstMuonLoose2InToOutIndex( index, prefix );
    CopytauAgainstMuonMedium2InToOutIndex( index, prefix );
    CopytauAgainstMuonTight2InToOutIndex( index, prefix );
    CopytauCombinedIsolationDeltaBetaCorrRaw3HitsInToOutIndex( index, prefix );
    CopytauLooseCombinedIsolationDeltaBetaCorr3HitsInToOutIndex( index, prefix );
    CopytauMediumCombinedIsolationDeltaBetaCorr3HitsInToOutIndex( index, prefix );
    CopytauTightCombinedIsolationDeltaBetaCorr3HitsInToOutIndex( index, prefix );
    CopytauEtaInToOutIndex( index, prefix );
    CopytauPhiInToOutIndex( index, prefix );
    CopytauPtInToOutIndex( index, prefix );
    CopytauEtInToOutIndex( index, prefix );
    CopytauChargeInToOutIndex( index, prefix );
    CopytauDecayModeInToOutIndex( index, prefix );
    CopytauEMFractionInToOutIndex( index, prefix );
    CopytauHCAL3x3OverPLeadInToOutIndex( index, prefix );
    CopytauHCALMaxOverPLeadInToOutIndex( index, prefix );
    CopytauHCALTotOverPLeadInToOutIndex( index, prefix );
    CopytauIsolationPFChargedHadrCandsPtSumInToOutIndex( index, prefix );
    CopytauIsolationPFGammaCandsEtSumInToOutIndex( index, prefix );
    CopytauLeadPFChargedHadrCandsignedSiptInToOutIndex( index, prefix );
    CopytauLeadChargedHadronExistsInToOutIndex( index, prefix );
    CopytauLeadChargedHadronEtaInToOutIndex( index, prefix );
    CopytauLeadChargedHadronPhiInToOutIndex( index, prefix );
    CopytauLeadChargedHadronPtInToOutIndex( index, prefix );
    CopyjetTrgInToOutIndex( index, prefix );
    CopyjetEnInToOutIndex( index, prefix );
    CopyjetPtInToOutIndex( index, prefix );
    CopyjetEtaInToOutIndex( index, prefix );
    CopyjetPhiInToOutIndex( index, prefix );
    CopyjetChargeInToOutIndex( index, prefix );
    CopyjetEtInToOutIndex( index, prefix );
    CopyjetRawPtInToOutIndex( index, prefix );
    CopyjetRawEnInToOutIndex( index, prefix );
    CopyjetAreaInToOutIndex( index, prefix );
    CopyjetCHFInToOutIndex( index, prefix );
    CopyjetNHFInToOutIndex( index, prefix );
    CopyjetCEFInToOutIndex( index, prefix );
    CopyjetNEFInToOutIndex( index, prefix );
    CopyjetNCHInToOutIndex( index, prefix );
    CopyjetHFHAEInToOutIndex( index, prefix );
    CopyjetHFEMEInToOutIndex( index, prefix );
    CopyjetNConstituentsInToOutIndex( index, prefix );
    CopyjetCombinedSecondaryVtxBJetTagsInToOutIndex( index, prefix );
    CopyjetCombinedSecondaryVtxMVABJetTagsInToOutIndex( index, prefix );
    CopyjetJetProbabilityBJetTagsInToOutIndex( index, prefix );
    CopyjetJetBProbabilityBJetTagsInToOutIndex( index, prefix );
    CopyjetPFLooseIdInToOutIndex( index, prefix );
    CopyjetDRMeanInToOutIndex( index, prefix );
    CopyjetDR2MeanInToOutIndex( index, prefix );
    CopyjetDZInToOutIndex( index, prefix );
    CopyjetFrac01InToOutIndex( index, prefix );
    CopyjetFrac02InToOutIndex( index, prefix );
    CopyjetFrac03InToOutIndex( index, prefix );
    CopyjetFrac04InToOutIndex( index, prefix );
    CopyjetFrac05InToOutIndex( index, prefix );
    CopyjetFrac06InToOutIndex( index, prefix );
    CopyjetFrac07InToOutIndex( index, prefix );
    CopyjetBetaInToOutIndex( index, prefix );
    CopyjetBetaStarCMGInToOutIndex( index, prefix );
    CopyjetBetaStarClassicInToOutIndex( index, prefix );
    CopyjetNNeutralsInToOutIndex( index, prefix );
    CopyjetNChargedInToOutIndex( index, prefix );
    CopyjetWPLevelsInToOutIndex( index, prefix );
    CopyjetMVAsExt_cutBasedInToOutIndex( index, prefix );
    CopyjetMVAsExt_philv1InToOutIndex( index, prefix );
    CopyjetWPLevelsExt_philv1InToOutIndex( index, prefix );
    CopyjetMtInToOutIndex( index, prefix );
    CopyjetJECUncInToOutIndex( index, prefix );
    CopyjetLeadTrackPtInToOutIndex( index, prefix );
    CopyjetVtxPtInToOutIndex( index, prefix );
    CopyjetVtxMassInToOutIndex( index, prefix );
    CopyjetVtx3dLInToOutIndex( index, prefix );
    CopyjetVtx3deLInToOutIndex( index, prefix );
    CopyjetSoftLeptPtInToOutIndex( index, prefix );
    CopyjetSoftLeptPtRelInToOutIndex( index, prefix );
    CopyjetSoftLeptdRInToOutIndex( index, prefix );
    CopyjetSoftLeptIdlooseMuInToOutIndex( index, prefix );
    CopyjetSoftLeptIdEle95InToOutIndex( index, prefix );
    CopyjetDPhiMETJetInToOutIndex( index, prefix );
    CopyjetPuJetIdLInToOutIndex( index, prefix );
    CopyjetPuJetIdMInToOutIndex( index, prefix );
    CopyjetPuJetIdTInToOutIndex( index, prefix );
    CopyconvP4_xInToOutIndex( index, prefix );
    CopyconvP4_yInToOutIndex( index, prefix );
    CopyconvP4_zInToOutIndex( index, prefix );
    CopyconvP4_EInToOutIndex( index, prefix );
    CopyconvVtx_xInToOutIndex( index, prefix );
    CopyconvVtx_yInToOutIndex( index, prefix );
    CopyconvVtx_zInToOutIndex( index, prefix );
    CopyconvVtxErr_xInToOutIndex( index, prefix );
    CopyconvVtxErr_yInToOutIndex( index, prefix );
    CopyconvVtxErr_zInToOutIndex( index, prefix );
    CopyconvPairMomentum_xInToOutIndex( index, prefix );
    CopyconvPairMomentum_yInToOutIndex( index, prefix );
    CopyconvPairMomentum_zInToOutIndex( index, prefix );
    CopyconvRefittedMomentum_xInToOutIndex( index, prefix );
    CopyconvRefittedMomentum_yInToOutIndex( index, prefix );
    CopyconvRefittedMomentum_zInToOutIndex( index, prefix );
    CopyconvNTracksInToOutIndex( index, prefix );
    CopyconvPairInvMassInToOutIndex( index, prefix );
    CopyconvPairCotThetaSepInToOutIndex( index, prefix );
    CopyconvEoverPInToOutIndex( index, prefix );
    CopyconvDistOfMinApproachInToOutIndex( index, prefix );
    CopyconvDPhiTrksAtVtxInToOutIndex( index, prefix );
    CopyconvDPhiTrksAtEcalInToOutIndex( index, prefix );
    CopyconvDEtaTrksAtEcalInToOutIndex( index, prefix );
    CopyconvDxyInToOutIndex( index, prefix );
    CopyconvDzInToOutIndex( index, prefix );
    CopyconvLxyInToOutIndex( index, prefix );
    CopyconvLzInToOutIndex( index, prefix );
    CopyconvZofPrimVtxFromTrksInToOutIndex( index, prefix );
    CopyconvNHitsBeforeVtx_0InToOutIndex( index, prefix );
    CopyconvNHitsBeforeVtx_1InToOutIndex( index, prefix );
    CopyconvNSharedHitsInToOutIndex( index, prefix );
    CopyconvValidVtxInToOutIndex( index, prefix );
    CopyconvMVALikelihoodInToOutIndex( index, prefix );
    CopyconvChi2InToOutIndex( index, prefix );
    CopyconvChi2ProbabilityInToOutIndex( index, prefix );
    CopyconvTk1DzInToOutIndex( index, prefix );
    CopyconvTk2DzInToOutIndex( index, prefix );
    CopyconvTk1DzErrInToOutIndex( index, prefix );
    CopyconvTk2DzErrInToOutIndex( index, prefix );
    CopyconvCh1Ch2InToOutIndex( index, prefix );
    CopyconvTk1D0InToOutIndex( index, prefix );
    CopyconvTk1PoutInToOutIndex( index, prefix );
    CopyconvTk1PinInToOutIndex( index, prefix );
    CopyconvTk2D0InToOutIndex( index, prefix );
    CopyconvTk2PoutInToOutIndex( index, prefix );
    CopyconvTk2PinInToOutIndex( index, prefix );
}; 

void ClearOutputPrefix ( const std::string & prefix ) {
    ClearOutputvtx_x( prefix );
    ClearOutputvtx_y( prefix );
    ClearOutputvtx_z( prefix );
    ClearOutputvtxbs_x( prefix );
    ClearOutputvtxbs_y( prefix );
    ClearOutputvtxbs_z( prefix );
    ClearOutputtrkMETx( prefix );
    ClearOutputtrkMETy( prefix );
    ClearOutputtrkMETPhi( prefix );
    ClearOutputtrkMET( prefix );
    ClearOutputeleTrg( prefix );
    ClearOutputeleClass( prefix );
    ClearOutputeleIsEcalDriven( prefix );
    ClearOutputeleCharge( prefix );
    ClearOutputeleChargeConsistent( prefix );
    ClearOutputeleEn( prefix );
    ClearOutputeleEcalEn( prefix );
    ClearOutputeleSCRawEn( prefix );
    ClearOutputeleSCEn( prefix );
    ClearOutputeleESEn( prefix );
    ClearOutputelePt( prefix );
    ClearOutputeleEta( prefix );
    ClearOutputelePhi( prefix );
    ClearOutputeleR9( prefix );
    ClearOutputeleEtaVtx( prefix );
    ClearOutputelePhiVtx( prefix );
    ClearOutputeleEtVtx( prefix );
    ClearOutputeleSCEta( prefix );
    ClearOutputeleSCPhi( prefix );
    ClearOutputeleSCEtaWidth( prefix );
    ClearOutputeleSCPhiWidth( prefix );
    ClearOutputeleVtx_x( prefix );
    ClearOutputeleVtx_y( prefix );
    ClearOutputeleVtx_z( prefix );
    ClearOutputeleD0( prefix );
    ClearOutputeleDz( prefix );
    ClearOutputeleD0GV( prefix );
    ClearOutputeleDzGV( prefix );
    ClearOutputeleD0Vtx( prefix );
    ClearOutputeleDzVtx( prefix );
    ClearOutputeleHoverE( prefix );
    ClearOutputeleHoverE12( prefix );
    ClearOutputeleEoverP( prefix );
    ClearOutputelePin( prefix );
    ClearOutputelePout( prefix );
    ClearOutputeleTrkMomErr( prefix );
    ClearOutputeleBrem( prefix );
    ClearOutputeledEtaAtVtx( prefix );
    ClearOutputeledPhiAtVtx( prefix );
    ClearOutputeleSigmaIEtaIEta( prefix );
    ClearOutputeleSigmaIEtaIPhi( prefix );
    ClearOutputeleSigmaIPhiIPhi( prefix );
    ClearOutputeleEmax( prefix );
    ClearOutputeleE2ndMax( prefix );
    ClearOutputeleETop( prefix );
    ClearOutputeleEBottom( prefix );
    ClearOutputeleELeft( prefix );
    ClearOutputeleERight( prefix );
    ClearOutputeleE1x5( prefix );
    ClearOutputeleE3x3( prefix );
    ClearOutputeleE5x5( prefix );
    ClearOutputeleE2x5Max( prefix );
    ClearOutputeleE2x5Top( prefix );
    ClearOutputeleE2x5Bottom( prefix );
    ClearOutputeleE2x5Left( prefix );
    ClearOutputeleE2x5Right( prefix );
    ClearOutputeleSeedEta( prefix );
    ClearOutputeleSeedE( prefix );
    ClearOutputeleSeedPhi( prefix );
    ClearOutputeleCrysEta( prefix );
    ClearOutputeleCrysPhi( prefix );
    ClearOutputeleCrysIEta( prefix );
    ClearOutputeleCrysIPhi( prefix );
    ClearOutputeleRegrE( prefix );
    ClearOutputeleRegrEerr( prefix );
    ClearOutputelePhoRegrE( prefix );
    ClearOutputelePhoRegrEerr( prefix );
    ClearOutputeleSeedTime( prefix );
    ClearOutputeleRecoFlag( prefix );
    ClearOutputelePos( prefix );
    ClearOutputeleIsoTrkDR03( prefix );
    ClearOutputeleIsoEcalDR03( prefix );
    ClearOutputeleIsoHcalDR03( prefix );
    ClearOutputeleIsoHcalDR0312( prefix );
    ClearOutputeleIsoTrkDR04( prefix );
    ClearOutputeleIsoEcalDR04( prefix );
    ClearOutputeleIsoHcalDR04( prefix );
    ClearOutputeleIsoHcalDR0412( prefix );
    ClearOutputeleModIsoTrk( prefix );
    ClearOutputeleModIsoEcal( prefix );
    ClearOutputeleModIsoHcal( prefix );
    ClearOutputeleMissHits( prefix );
    ClearOutputeleConvDist( prefix );
    ClearOutputeleConvDcot( prefix );
    ClearOutputeleConvVtxFit( prefix );
    ClearOutputeleIP3D( prefix );
    ClearOutputeleIP3DErr( prefix );
    ClearOutputeleIDMVANonTrig( prefix );
    ClearOutputeleIDMVATrig( prefix );
    ClearOutputelePFChIso03( prefix );
    ClearOutputelePFPhoIso03( prefix );
    ClearOutputelePFNeuIso03( prefix );
    ClearOutputelePFChIso04( prefix );
    ClearOutputelePFPhoIso04( prefix );
    ClearOutputelePFNeuIso04( prefix );
    ClearOutputeleESEffSigmaRR_x( prefix );
    ClearOutputeleESEffSigmaRR_y( prefix );
    ClearOutputeleESEffSigmaRR_z( prefix );
    ClearOutputphoTrg( prefix );
    ClearOutputphoTrgFilter( prefix );
    ClearOutputphoIsPhoton( prefix );
    ClearOutputphoSCPos_x( prefix );
    ClearOutputphoSCPos_y( prefix );
    ClearOutputphoSCPos_z( prefix );
    ClearOutputphoCaloPos_x( prefix );
    ClearOutputphoCaloPos_y( prefix );
    ClearOutputphoCaloPos_z( prefix );
    ClearOutputphoE( prefix );
    ClearOutputphoEt( prefix );
    ClearOutputphoEta( prefix );
    ClearOutputphoVtx_x( prefix );
    ClearOutputphoVtx_y( prefix );
    ClearOutputphoVtx_z( prefix );
    ClearOutputphoPhi( prefix );
    ClearOutputphoEtVtx( prefix );
    ClearOutputphoEtaVtx( prefix );
    ClearOutputphoPhiVtx( prefix );
    ClearOutputphoR9( prefix );
    ClearOutputphoNClus( prefix );
    ClearOutputphoTrkIsoHollowDR03( prefix );
    ClearOutputphoEcalIsoDR03( prefix );
    ClearOutputphoHcalIsoDR03( prefix );
    ClearOutputphoHcalIsoDR0312( prefix );
    ClearOutputphoTrkIsoHollowDR04( prefix );
    ClearOutputphoCiCdRtoTrk( prefix );
    ClearOutputphoEcalIsoDR04( prefix );
    ClearOutputphoHcalIsoDR04( prefix );
    ClearOutputphoHcalIsoDR0412( prefix );
    ClearOutputphoHoverE( prefix );
    ClearOutputphoHoverE12( prefix );
    ClearOutputphoEleVeto( prefix );
    ClearOutputphoSigmaIEtaIEta( prefix );
    ClearOutputphoSigmaIEtaIPhi( prefix );
    ClearOutputphoSigmaIPhiIPhi( prefix );
    ClearOutputphoCiCPF4phopfIso03( prefix );
    ClearOutputphoCiCPF4phopfIso04( prefix );
    ClearOutputphoEmax( prefix );
    ClearOutputphoETop( prefix );
    ClearOutputphoEBottom( prefix );
    ClearOutputphoELeft( prefix );
    ClearOutputphoERight( prefix );
    ClearOutputphoE2ndMax( prefix );
    ClearOutputphoE3x3( prefix );
    ClearOutputphoE3x1( prefix );
    ClearOutputphoE1x3( prefix );
    ClearOutputphoE5x5( prefix );
    ClearOutputphoE1x5( prefix );
    ClearOutputphoE2x2( prefix );
    ClearOutputphoE2x5Max( prefix );
    ClearOutputphoE2x5Top( prefix );
    ClearOutputphoE2x5Bottom( prefix );
    ClearOutputphoE2x5Left( prefix );
    ClearOutputphoE2x5Right( prefix );
    ClearOutputphoSeedE( prefix );
    ClearOutputphoSeedEta( prefix );
    ClearOutputphoSeedPhi( prefix );
    ClearOutputphoCrysEta( prefix );
    ClearOutputphoCrysPhi( prefix );
    ClearOutputphoCrysIEta( prefix );
    ClearOutputphoCrysIPhi( prefix );
    ClearOutputphoPFChIso( prefix );
    ClearOutputphoPFPhoIso( prefix );
    ClearOutputphoPFNeuIso( prefix );
    ClearOutputphoSCRChIso( prefix );
    ClearOutputphoSCRPhoIso( prefix );
    ClearOutputphoSCRNeuIso( prefix );
    ClearOutputphoSCRChIso04( prefix );
    ClearOutputphoSCRPhoIso04( prefix );
    ClearOutputphoSCRNeuIso04( prefix );
    ClearOutputphoRandConeChIso( prefix );
    ClearOutputphoRandConePhoIso( prefix );
    ClearOutputphoRandConeNeuIso( prefix );
    ClearOutputphoRandConeChIso04( prefix );
    ClearOutputphoRandConePhoIso04( prefix );
    ClearOutputphoRandConeNeuIso04( prefix );
    ClearOutputphoRegrE( prefix );
    ClearOutputphoRegrEerr( prefix );
    ClearOutputphoSeedTime( prefix );
    ClearOutputphoSeedDetId1( prefix );
    ClearOutputphoSeedDetId2( prefix );
    ClearOutputphoLICTD( prefix );
    ClearOutputphoRecoFlag( prefix );
    ClearOutputphoPos( prefix );
    ClearOutputphoSCE( prefix );
    ClearOutputphoSCRawE( prefix );
    ClearOutputphoESEn( prefix );
    ClearOutputphoSCEt( prefix );
    ClearOutputphoSCEta( prefix );
    ClearOutputphoSCPhi( prefix );
    ClearOutputphoSCEtaWidth( prefix );
    ClearOutputphoSCPhiWidth( prefix );
    ClearOutputphoSCBrem( prefix );
    ClearOutputphoOverlap( prefix );
    ClearOutputphohasPixelSeed( prefix );
    ClearOutputpho_hasConvPf( prefix );
    ClearOutputpho_hasSLConvPf( prefix );
    ClearOutputpho_pfconvVtxZ( prefix );
    ClearOutputpho_pfconvVtxZErr( prefix );
    ClearOutputpho_nSLConv( prefix );
    ClearOutputpho_pfSLConvPos_x( prefix );
    ClearOutputpho_pfSLConvPos_y( prefix );
    ClearOutputpho_pfSLConvPos_z( prefix );
    ClearOutputpho_pfSLConvVtxZ( prefix );
    ClearOutputphoIsConv( prefix );
    ClearOutputphoNConv( prefix );
    ClearOutputphoConvInvMass( prefix );
    ClearOutputphoConvCotTheta( prefix );
    ClearOutputphoConvEoverP( prefix );
    ClearOutputphoConvZofPVfromTrks( prefix );
    ClearOutputphoConvMinDist( prefix );
    ClearOutputphoConvdPhiAtVtx( prefix );
    ClearOutputphoConvdPhiAtCalo( prefix );
    ClearOutputphoConvdEtaAtCalo( prefix );
    ClearOutputphoConvTrkd0_x( prefix );
    ClearOutputphoConvTrkd0_y( prefix );
    ClearOutputphoConvTrkPin_x( prefix );
    ClearOutputphoConvTrkPin_y( prefix );
    ClearOutputphoConvTrkPout_x( prefix );
    ClearOutputphoConvTrkPout_y( prefix );
    ClearOutputphoConvTrkdz_x( prefix );
    ClearOutputphoConvTrkdz_y( prefix );
    ClearOutputphoConvTrkdzErr_x( prefix );
    ClearOutputphoConvTrkdzErr_y( prefix );
    ClearOutputphoConvChi2( prefix );
    ClearOutputphoConvChi2Prob( prefix );
    ClearOutputphoConvNTrks( prefix );
    ClearOutputphoConvCharge1( prefix );
    ClearOutputphoConvCharge2( prefix );
    ClearOutputphoConvValidVtx( prefix );
    ClearOutputphoConvLikeLihood( prefix );
    ClearOutputphoConvP4_0( prefix );
    ClearOutputphoConvP4_1( prefix );
    ClearOutputphoConvP4_2( prefix );
    ClearOutputphoConvP4_3( prefix );
    ClearOutputphoConvVtx_x( prefix );
    ClearOutputphoConvVtx_y( prefix );
    ClearOutputphoConvVtx_z( prefix );
    ClearOutputphoConvVtxErr_x( prefix );
    ClearOutputphoConvVtxErr_y( prefix );
    ClearOutputphoConvVtxErr_z( prefix );
    ClearOutputphoConvPairMomentum_x( prefix );
    ClearOutputphoConvPairMomentum_y( prefix );
    ClearOutputphoConvPairMomentum_z( prefix );
    ClearOutputphoConvRefittedMomentum_x( prefix );
    ClearOutputphoConvRefittedMomentum_y( prefix );
    ClearOutputphoConvRefittedMomentum_z( prefix );
    ClearOutputSingleLegConv( prefix );
    ClearOutputphoPFConvVtx_x( prefix );
    ClearOutputphoPFConvVtx_y( prefix );
    ClearOutputphoPFConvVtx_z( prefix );
    ClearOutputphoPFConvMom_x( prefix );
    ClearOutputphoPFConvMom_y( prefix );
    ClearOutputphoPFConvMom_z( prefix );
    ClearOutputphoESEffSigmaRR_x( prefix );
    ClearOutputphoESEffSigmaRR_y( prefix );
    ClearOutputphoESEffSigmaRR_z( prefix );
    ClearOutputmuTrg( prefix );
    ClearOutputmuEta( prefix );
    ClearOutputmuPhi( prefix );
    ClearOutputmuCharge( prefix );
    ClearOutputmuPt( prefix );
    ClearOutputmuPz( prefix );
    ClearOutputmuVtx_x( prefix );
    ClearOutputmuVtx_y( prefix );
    ClearOutputmuVtx_z( prefix );
    ClearOutputmuVtxGlb_x( prefix );
    ClearOutputmuVtxGlb_y( prefix );
    ClearOutputmuVtxGlb_z( prefix );
    ClearOutputmucktPt( prefix );
    ClearOutputmucktPtErr( prefix );
    ClearOutputmucktEta( prefix );
    ClearOutputmucktPhi( prefix );
    ClearOutputmucktdxy( prefix );
    ClearOutputmucktdz( prefix );
    ClearOutputmuIsoTrk( prefix );
    ClearOutputmuIsoCalo( prefix );
    ClearOutputmuIsoEcal( prefix );
    ClearOutputmuIsoHcal( prefix );
    ClearOutputmuChi2NDF( prefix );
    ClearOutputmuInnerChi2NDF( prefix );
    ClearOutputmuPFIsoR04_CH( prefix );
    ClearOutputmuPFIsoR04_NH( prefix );
    ClearOutputmuPFIsoR04_Pho( prefix );
    ClearOutputmuPFIsoR04_PU( prefix );
    ClearOutputmuPFIsoR04_CPart( prefix );
    ClearOutputmuPFIsoR04_NHHT( prefix );
    ClearOutputmuPFIsoR04_PhoHT( prefix );
    ClearOutputmuPFIsoR03_CH( prefix );
    ClearOutputmuPFIsoR03_NH( prefix );
    ClearOutputmuPFIsoR03_Pho( prefix );
    ClearOutputmuPFIsoR03_PU( prefix );
    ClearOutputmuPFIsoR03_CPart( prefix );
    ClearOutputmuPFIsoR03_NHHT( prefix );
    ClearOutputmuPFIsoR03_PhoHT( prefix );
    ClearOutputmuType( prefix );
    ClearOutputmuD0( prefix );
    ClearOutputmuDz( prefix );
    ClearOutputmuD0GV( prefix );
    ClearOutputmuDzGV( prefix );
    ClearOutputmuD0Vtx( prefix );
    ClearOutputmuDzVtx( prefix );
    ClearOutputmuInnerD0( prefix );
    ClearOutputmuInnerDz( prefix );
    ClearOutputmuInnerD0GV( prefix );
    ClearOutputmuInnerDzGV( prefix );
    ClearOutputmuInnerPt( prefix );
    ClearOutputmuInnerPtErr( prefix );
    ClearOutputmuNumberOfValidTrkLayers( prefix );
    ClearOutputmuNumberOfValidTrkHits( prefix );
    ClearOutputmuNumberOfValidPixelLayers( prefix );
    ClearOutputmuNumberOfValidPixelHits( prefix );
    ClearOutputmuNumberOfValidMuonHits( prefix );
    ClearOutputmuStations( prefix );
    ClearOutputmuChambers( prefix );
    ClearOutputmuIP3D( prefix );
    ClearOutputmuIP3DErr( prefix );
    ClearOutputtauDecayModeFinding( prefix );
    ClearOutputtauAgainstElectronLooseMVA3( prefix );
    ClearOutputtauAgainstElectronMediumMVA3( prefix );
    ClearOutputtauAgainstElectronTightMVA3( prefix );
    ClearOutputtauAgainstElectronVTightMVA3( prefix );
    ClearOutputtauAgainstElectronDeadECAL( prefix );
    ClearOutputtauAgainstMuonLoose2( prefix );
    ClearOutputtauAgainstMuonMedium2( prefix );
    ClearOutputtauAgainstMuonTight2( prefix );
    ClearOutputtauCombinedIsolationDeltaBetaCorrRaw3Hits( prefix );
    ClearOutputtauLooseCombinedIsolationDeltaBetaCorr3Hits( prefix );
    ClearOutputtauMediumCombinedIsolationDeltaBetaCorr3Hits( prefix );
    ClearOutputtauTightCombinedIsolationDeltaBetaCorr3Hits( prefix );
    ClearOutputtauEta( prefix );
    ClearOutputtauPhi( prefix );
    ClearOutputtauPt( prefix );
    ClearOutputtauEt( prefix );
    ClearOutputtauCharge( prefix );
    ClearOutputtauDecayMode( prefix );
    ClearOutputtauEMFraction( prefix );
    ClearOutputtauHCAL3x3OverPLead( prefix );
    ClearOutputtauHCALMaxOverPLead( prefix );
    ClearOutputtauHCALTotOverPLead( prefix );
    ClearOutputtauIsolationPFChargedHadrCandsPtSum( prefix );
    ClearOutputtauIsolationPFGammaCandsEtSum( prefix );
    ClearOutputtauLeadPFChargedHadrCandsignedSipt( prefix );
    ClearOutputtauLeadChargedHadronExists( prefix );
    ClearOutputtauLeadChargedHadronEta( prefix );
    ClearOutputtauLeadChargedHadronPhi( prefix );
    ClearOutputtauLeadChargedHadronPt( prefix );
    ClearOutputjetTrg( prefix );
    ClearOutputjetEn( prefix );
    ClearOutputjetPt( prefix );
    ClearOutputjetEta( prefix );
    ClearOutputjetPhi( prefix );
    ClearOutputjetCharge( prefix );
    ClearOutputjetEt( prefix );
    ClearOutputjetRawPt( prefix );
    ClearOutputjetRawEn( prefix );
    ClearOutputjetArea( prefix );
    ClearOutputjetCHF( prefix );
    ClearOutputjetNHF( prefix );
    ClearOutputjetCEF( prefix );
    ClearOutputjetNEF( prefix );
    ClearOutputjetNCH( prefix );
    ClearOutputjetHFHAE( prefix );
    ClearOutputjetHFEME( prefix );
    ClearOutputjetNConstituents( prefix );
    ClearOutputjetCombinedSecondaryVtxBJetTags( prefix );
    ClearOutputjetCombinedSecondaryVtxMVABJetTags( prefix );
    ClearOutputjetJetProbabilityBJetTags( prefix );
    ClearOutputjetJetBProbabilityBJetTags( prefix );
    ClearOutputjetPFLooseId( prefix );
    ClearOutputjetDRMean( prefix );
    ClearOutputjetDR2Mean( prefix );
    ClearOutputjetDZ( prefix );
    ClearOutputjetFrac01( prefix );
    ClearOutputjetFrac02( prefix );
    ClearOutputjetFrac03( prefix );
    ClearOutputjetFrac04( prefix );
    ClearOutputjetFrac05( prefix );
    ClearOutputjetFrac06( prefix );
    ClearOutputjetFrac07( prefix );
    ClearOutputjetBeta( prefix );
    ClearOutputjetBetaStarCMG( prefix );
    ClearOutputjetBetaStarClassic( prefix );
    ClearOutputjetNNeutrals( prefix );
    ClearOutputjetNCharged( prefix );
    ClearOutputjetWPLevels( prefix );
    ClearOutputjetMVAsExt_cutBased( prefix );
    ClearOutputjetMVAsExt_philv1( prefix );
    ClearOutputjetWPLevelsExt_philv1( prefix );
    ClearOutputjetMt( prefix );
    ClearOutputjetJECUnc( prefix );
    ClearOutputjetLeadTrackPt( prefix );
    ClearOutputjetVtxPt( prefix );
    ClearOutputjetVtxMass( prefix );
    ClearOutputjetVtx3dL( prefix );
    ClearOutputjetVtx3deL( prefix );
    ClearOutputjetSoftLeptPt( prefix );
    ClearOutputjetSoftLeptPtRel( prefix );
    ClearOutputjetSoftLeptdR( prefix );
    ClearOutputjetSoftLeptIdlooseMu( prefix );
    ClearOutputjetSoftLeptIdEle95( prefix );
    ClearOutputjetDPhiMETJet( prefix );
    ClearOutputjetPuJetIdL( prefix );
    ClearOutputjetPuJetIdM( prefix );
    ClearOutputjetPuJetIdT( prefix );
    ClearOutputconvP4_x( prefix );
    ClearOutputconvP4_y( prefix );
    ClearOutputconvP4_z( prefix );
    ClearOutputconvP4_E( prefix );
    ClearOutputconvVtx_x( prefix );
    ClearOutputconvVtx_y( prefix );
    ClearOutputconvVtx_z( prefix );
    ClearOutputconvVtxErr_x( prefix );
    ClearOutputconvVtxErr_y( prefix );
    ClearOutputconvVtxErr_z( prefix );
    ClearOutputconvPairMomentum_x( prefix );
    ClearOutputconvPairMomentum_y( prefix );
    ClearOutputconvPairMomentum_z( prefix );
    ClearOutputconvRefittedMomentum_x( prefix );
    ClearOutputconvRefittedMomentum_y( prefix );
    ClearOutputconvRefittedMomentum_z( prefix );
    ClearOutputconvNTracks( prefix );
    ClearOutputconvPairInvMass( prefix );
    ClearOutputconvPairCotThetaSep( prefix );
    ClearOutputconvEoverP( prefix );
    ClearOutputconvDistOfMinApproach( prefix );
    ClearOutputconvDPhiTrksAtVtx( prefix );
    ClearOutputconvDPhiTrksAtEcal( prefix );
    ClearOutputconvDEtaTrksAtEcal( prefix );
    ClearOutputconvDxy( prefix );
    ClearOutputconvDz( prefix );
    ClearOutputconvLxy( prefix );
    ClearOutputconvLz( prefix );
    ClearOutputconvZofPrimVtxFromTrks( prefix );
    ClearOutputconvNHitsBeforeVtx_0( prefix );
    ClearOutputconvNHitsBeforeVtx_1( prefix );
    ClearOutputconvNSharedHits( prefix );
    ClearOutputconvValidVtx( prefix );
    ClearOutputconvMVALikelihood( prefix );
    ClearOutputconvChi2( prefix );
    ClearOutputconvChi2Probability( prefix );
    ClearOutputconvTk1Dz( prefix );
    ClearOutputconvTk2Dz( prefix );
    ClearOutputconvTk1DzErr( prefix );
    ClearOutputconvTk2DzErr( prefix );
    ClearOutputconvCh1Ch2( prefix );
    ClearOutputconvTk1D0( prefix );
    ClearOutputconvTk1Pout( prefix );
    ClearOutputconvTk1Pin( prefix );
    ClearOutputconvTk2D0( prefix );
    ClearOutputconvTk2Pout( prefix );
    ClearOutputconvTk2Pin( prefix );
}; 

void CopynHLTInToOut( std::string prefix ) { 

    std::string my_name = "nHLT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nHLT = IN::nHLT;
}; 

 void CopyrunInToOut( std::string prefix ) { 

    std::string my_name = "run";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::run = IN::run;
}; 

 void CopyeventInToOut( std::string prefix ) { 

    std::string my_name = "event";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::event = IN::event;
}; 

 void CopylumisInToOut( std::string prefix ) { 

    std::string my_name = "lumis";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::lumis = IN::lumis;
}; 

 void CopyisDataInToOut( std::string prefix ) { 

    std::string my_name = "isData";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::isData = IN::isData;
}; 

 void CopyHLTInToOut( std::string prefix ) { 

    std::string my_name = "HLT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::HLT[0] = IN::HLT[0];
   OUT::HLT[1] = IN::HLT[1];
   OUT::HLT[2] = IN::HLT[2];
   OUT::HLT[3] = IN::HLT[3];
   OUT::HLT[4] = IN::HLT[4];
   OUT::HLT[5] = IN::HLT[5];
   OUT::HLT[6] = IN::HLT[6];
   OUT::HLT[7] = IN::HLT[7];
   OUT::HLT[8] = IN::HLT[8];
   OUT::HLT[9] = IN::HLT[9];
   OUT::HLT[10] = IN::HLT[10];
   OUT::HLT[11] = IN::HLT[11];
   OUT::HLT[12] = IN::HLT[12];
   OUT::HLT[13] = IN::HLT[13];
   OUT::HLT[14] = IN::HLT[14];
   OUT::HLT[15] = IN::HLT[15];
   OUT::HLT[16] = IN::HLT[16];
   OUT::HLT[17] = IN::HLT[17];
   OUT::HLT[18] = IN::HLT[18];
   OUT::HLT[19] = IN::HLT[19];
   OUT::HLT[20] = IN::HLT[20];
   OUT::HLT[21] = IN::HLT[21];
   OUT::HLT[22] = IN::HLT[22];
   OUT::HLT[23] = IN::HLT[23];
   OUT::HLT[24] = IN::HLT[24];
   OUT::HLT[25] = IN::HLT[25];
   OUT::HLT[26] = IN::HLT[26];
   OUT::HLT[27] = IN::HLT[27];
   OUT::HLT[28] = IN::HLT[28];
   OUT::HLT[29] = IN::HLT[29];
   OUT::HLT[30] = IN::HLT[30];
   OUT::HLT[31] = IN::HLT[31];
   OUT::HLT[32] = IN::HLT[32];
   OUT::HLT[33] = IN::HLT[33];
   OUT::HLT[34] = IN::HLT[34];
   OUT::HLT[35] = IN::HLT[35];
   OUT::HLT[36] = IN::HLT[36];
   OUT::HLT[37] = IN::HLT[37];
   OUT::HLT[38] = IN::HLT[38];
   OUT::HLT[39] = IN::HLT[39];
   OUT::HLT[40] = IN::HLT[40];
   OUT::HLT[41] = IN::HLT[41];
   OUT::HLT[42] = IN::HLT[42];
   OUT::HLT[43] = IN::HLT[43];
   OUT::HLT[44] = IN::HLT[44];
   OUT::HLT[45] = IN::HLT[45];
   OUT::HLT[46] = IN::HLT[46];
   OUT::HLT[47] = IN::HLT[47];
   OUT::HLT[48] = IN::HLT[48];
   OUT::HLT[49] = IN::HLT[49];
   OUT::HLT[50] = IN::HLT[50];
   OUT::HLT[51] = IN::HLT[51];
   OUT::HLT[52] = IN::HLT[52];
   OUT::HLT[53] = IN::HLT[53];
   OUT::HLT[54] = IN::HLT[54];
   OUT::HLT[55] = IN::HLT[55];
   OUT::HLT[56] = IN::HLT[56];
   OUT::HLT[57] = IN::HLT[57];
   OUT::HLT[58] = IN::HLT[58];
   OUT::HLT[59] = IN::HLT[59];
   OUT::HLT[60] = IN::HLT[60];
   OUT::HLT[61] = IN::HLT[61];
   OUT::HLT[62] = IN::HLT[62];
   OUT::HLT[63] = IN::HLT[63];
   OUT::HLT[64] = IN::HLT[64];
   OUT::HLT[65] = IN::HLT[65];
   OUT::HLT[66] = IN::HLT[66];
   OUT::HLT[67] = IN::HLT[67];
   OUT::HLT[68] = IN::HLT[68];
   OUT::HLT[69] = IN::HLT[69];
   OUT::HLT[70] = IN::HLT[70];
   OUT::HLT[71] = IN::HLT[71];
   OUT::HLT[72] = IN::HLT[72];
   OUT::HLT[73] = IN::HLT[73];
   OUT::HLT[74] = IN::HLT[74];
   OUT::HLT[75] = IN::HLT[75];
   OUT::HLT[76] = IN::HLT[76];
   OUT::HLT[77] = IN::HLT[77];
   OUT::HLT[78] = IN::HLT[78];
   OUT::HLT[79] = IN::HLT[79];
   OUT::HLT[80] = IN::HLT[80];
   OUT::HLT[81] = IN::HLT[81];
   OUT::HLT[82] = IN::HLT[82];
   OUT::HLT[83] = IN::HLT[83];
   OUT::HLT[84] = IN::HLT[84];
   OUT::HLT[85] = IN::HLT[85];
   OUT::HLT[86] = IN::HLT[86];
   OUT::HLT[87] = IN::HLT[87];
   OUT::HLT[88] = IN::HLT[88];
   OUT::HLT[89] = IN::HLT[89];
   OUT::HLT[90] = IN::HLT[90];
   OUT::HLT[91] = IN::HLT[91];
   OUT::HLT[92] = IN::HLT[92];
   OUT::HLT[93] = IN::HLT[93];
   OUT::HLT[94] = IN::HLT[94];
   OUT::HLT[95] = IN::HLT[95];
   OUT::HLT[96] = IN::HLT[96];
   OUT::HLT[97] = IN::HLT[97];
   OUT::HLT[98] = IN::HLT[98];
   OUT::HLT[99] = IN::HLT[99];
   OUT::HLT[100] = IN::HLT[100];
   OUT::HLT[101] = IN::HLT[101];
   OUT::HLT[102] = IN::HLT[102];
   OUT::HLT[103] = IN::HLT[103];
   OUT::HLT[104] = IN::HLT[104];
   OUT::HLT[105] = IN::HLT[105];
   OUT::HLT[106] = IN::HLT[106];
   OUT::HLT[107] = IN::HLT[107];
   OUT::HLT[108] = IN::HLT[108];
   OUT::HLT[109] = IN::HLT[109];
   OUT::HLT[110] = IN::HLT[110];
   OUT::HLT[111] = IN::HLT[111];
   OUT::HLT[112] = IN::HLT[112];
   OUT::HLT[113] = IN::HLT[113];
   OUT::HLT[114] = IN::HLT[114];
   OUT::HLT[115] = IN::HLT[115];
   OUT::HLT[116] = IN::HLT[116];
   OUT::HLT[117] = IN::HLT[117];
   OUT::HLT[118] = IN::HLT[118];
   OUT::HLT[119] = IN::HLT[119];
   OUT::HLT[120] = IN::HLT[120];
   OUT::HLT[121] = IN::HLT[121];
   OUT::HLT[122] = IN::HLT[122];
   OUT::HLT[123] = IN::HLT[123];
   OUT::HLT[124] = IN::HLT[124];
   OUT::HLT[125] = IN::HLT[125];
   OUT::HLT[126] = IN::HLT[126];
   OUT::HLT[127] = IN::HLT[127];
   OUT::HLT[128] = IN::HLT[128];
   OUT::HLT[129] = IN::HLT[129];
   OUT::HLT[130] = IN::HLT[130];
   OUT::HLT[131] = IN::HLT[131];
   OUT::HLT[132] = IN::HLT[132];
   OUT::HLT[133] = IN::HLT[133];
   OUT::HLT[134] = IN::HLT[134];
   OUT::HLT[135] = IN::HLT[135];
   OUT::HLT[136] = IN::HLT[136];
   OUT::HLT[137] = IN::HLT[137];
   OUT::HLT[138] = IN::HLT[138];
   OUT::HLT[139] = IN::HLT[139];
   OUT::HLT[140] = IN::HLT[140];
   OUT::HLT[141] = IN::HLT[141];
   OUT::HLT[142] = IN::HLT[142];
   OUT::HLT[143] = IN::HLT[143];
   OUT::HLT[144] = IN::HLT[144];
   OUT::HLT[145] = IN::HLT[145];
   OUT::HLT[146] = IN::HLT[146];
   OUT::HLT[147] = IN::HLT[147];
   OUT::HLT[148] = IN::HLT[148];
   OUT::HLT[149] = IN::HLT[149];
   OUT::HLT[150] = IN::HLT[150];
   OUT::HLT[151] = IN::HLT[151];
   OUT::HLT[152] = IN::HLT[152];
   OUT::HLT[153] = IN::HLT[153];
   OUT::HLT[154] = IN::HLT[154];
   OUT::HLT[155] = IN::HLT[155];
   OUT::HLT[156] = IN::HLT[156];
   OUT::HLT[157] = IN::HLT[157];
   OUT::HLT[158] = IN::HLT[158];
   OUT::HLT[159] = IN::HLT[159];
   OUT::HLT[160] = IN::HLT[160];
   OUT::HLT[161] = IN::HLT[161];
   OUT::HLT[162] = IN::HLT[162];
   OUT::HLT[163] = IN::HLT[163];
   OUT::HLT[164] = IN::HLT[164];
   OUT::HLT[165] = IN::HLT[165];
   OUT::HLT[166] = IN::HLT[166];
   OUT::HLT[167] = IN::HLT[167];
   OUT::HLT[168] = IN::HLT[168];
   OUT::HLT[169] = IN::HLT[169];
   OUT::HLT[170] = IN::HLT[170];
   OUT::HLT[171] = IN::HLT[171];
   OUT::HLT[172] = IN::HLT[172];
   OUT::HLT[173] = IN::HLT[173];
   OUT::HLT[174] = IN::HLT[174];
   OUT::HLT[175] = IN::HLT[175];
   OUT::HLT[176] = IN::HLT[176];
   OUT::HLT[177] = IN::HLT[177];
   OUT::HLT[178] = IN::HLT[178];
   OUT::HLT[179] = IN::HLT[179];
   OUT::HLT[180] = IN::HLT[180];
   OUT::HLT[181] = IN::HLT[181];
   OUT::HLT[182] = IN::HLT[182];
   OUT::HLT[183] = IN::HLT[183];
   OUT::HLT[184] = IN::HLT[184];
   OUT::HLT[185] = IN::HLT[185];
   OUT::HLT[186] = IN::HLT[186];
   OUT::HLT[187] = IN::HLT[187];
   OUT::HLT[188] = IN::HLT[188];
   OUT::HLT[189] = IN::HLT[189];
   OUT::HLT[190] = IN::HLT[190];
   OUT::HLT[191] = IN::HLT[191];
   OUT::HLT[192] = IN::HLT[192];
   OUT::HLT[193] = IN::HLT[193];
   OUT::HLT[194] = IN::HLT[194];
   OUT::HLT[195] = IN::HLT[195];
   OUT::HLT[196] = IN::HLT[196];
   OUT::HLT[197] = IN::HLT[197];
   OUT::HLT[198] = IN::HLT[198];
   OUT::HLT[199] = IN::HLT[199];
   OUT::HLT[200] = IN::HLT[200];
   OUT::HLT[201] = IN::HLT[201];
   OUT::HLT[202] = IN::HLT[202];
   OUT::HLT[203] = IN::HLT[203];
   OUT::HLT[204] = IN::HLT[204];
   OUT::HLT[205] = IN::HLT[205];
   OUT::HLT[206] = IN::HLT[206];
   OUT::HLT[207] = IN::HLT[207];
   OUT::HLT[208] = IN::HLT[208];
   OUT::HLT[209] = IN::HLT[209];
   OUT::HLT[210] = IN::HLT[210];
   OUT::HLT[211] = IN::HLT[211];
   OUT::HLT[212] = IN::HLT[212];
   OUT::HLT[213] = IN::HLT[213];
   OUT::HLT[214] = IN::HLT[214];
   OUT::HLT[215] = IN::HLT[215];
   OUT::HLT[216] = IN::HLT[216];
   OUT::HLT[217] = IN::HLT[217];
   OUT::HLT[218] = IN::HLT[218];
   OUT::HLT[219] = IN::HLT[219];
   OUT::HLT[220] = IN::HLT[220];
   OUT::HLT[221] = IN::HLT[221];
   OUT::HLT[222] = IN::HLT[222];
   OUT::HLT[223] = IN::HLT[223];
   OUT::HLT[224] = IN::HLT[224];
   OUT::HLT[225] = IN::HLT[225];
   OUT::HLT[226] = IN::HLT[226];
   OUT::HLT[227] = IN::HLT[227];
   OUT::HLT[228] = IN::HLT[228];
   OUT::HLT[229] = IN::HLT[229];
   OUT::HLT[230] = IN::HLT[230];
   OUT::HLT[231] = IN::HLT[231];
   OUT::HLT[232] = IN::HLT[232];
   OUT::HLT[233] = IN::HLT[233];
   OUT::HLT[234] = IN::HLT[234];
   OUT::HLT[235] = IN::HLT[235];
   OUT::HLT[236] = IN::HLT[236];
   OUT::HLT[237] = IN::HLT[237];
   OUT::HLT[238] = IN::HLT[238];
   OUT::HLT[239] = IN::HLT[239];
   OUT::HLT[240] = IN::HLT[240];
   OUT::HLT[241] = IN::HLT[241];
   OUT::HLT[242] = IN::HLT[242];
   OUT::HLT[243] = IN::HLT[243];
   OUT::HLT[244] = IN::HLT[244];
   OUT::HLT[245] = IN::HLT[245];
   OUT::HLT[246] = IN::HLT[246];
   OUT::HLT[247] = IN::HLT[247];
   OUT::HLT[248] = IN::HLT[248];
   OUT::HLT[249] = IN::HLT[249];
   OUT::HLT[250] = IN::HLT[250];
   OUT::HLT[251] = IN::HLT[251];
   OUT::HLT[252] = IN::HLT[252];
   OUT::HLT[253] = IN::HLT[253];
   OUT::HLT[254] = IN::HLT[254];
   OUT::HLT[255] = IN::HLT[255];
   OUT::HLT[256] = IN::HLT[256];
   OUT::HLT[257] = IN::HLT[257];
   OUT::HLT[258] = IN::HLT[258];
   OUT::HLT[259] = IN::HLT[259];
   OUT::HLT[260] = IN::HLT[260];
   OUT::HLT[261] = IN::HLT[261];
   OUT::HLT[262] = IN::HLT[262];
   OUT::HLT[263] = IN::HLT[263];
   OUT::HLT[264] = IN::HLT[264];
   OUT::HLT[265] = IN::HLT[265];
   OUT::HLT[266] = IN::HLT[266];
   OUT::HLT[267] = IN::HLT[267];
   OUT::HLT[268] = IN::HLT[268];
   OUT::HLT[269] = IN::HLT[269];
   OUT::HLT[270] = IN::HLT[270];
   OUT::HLT[271] = IN::HLT[271];
   OUT::HLT[272] = IN::HLT[272];
   OUT::HLT[273] = IN::HLT[273];
   OUT::HLT[274] = IN::HLT[274];
   OUT::HLT[275] = IN::HLT[275];
   OUT::HLT[276] = IN::HLT[276];
   OUT::HLT[277] = IN::HLT[277];
   OUT::HLT[278] = IN::HLT[278];
   OUT::HLT[279] = IN::HLT[279];
   OUT::HLT[280] = IN::HLT[280];
   OUT::HLT[281] = IN::HLT[281];
   OUT::HLT[282] = IN::HLT[282];
   OUT::HLT[283] = IN::HLT[283];
   OUT::HLT[284] = IN::HLT[284];
   OUT::HLT[285] = IN::HLT[285];
   OUT::HLT[286] = IN::HLT[286];
   OUT::HLT[287] = IN::HLT[287];
   OUT::HLT[288] = IN::HLT[288];
   OUT::HLT[289] = IN::HLT[289];
   OUT::HLT[290] = IN::HLT[290];
   OUT::HLT[291] = IN::HLT[291];
   OUT::HLT[292] = IN::HLT[292];
   OUT::HLT[293] = IN::HLT[293];
   OUT::HLT[294] = IN::HLT[294];
   OUT::HLT[295] = IN::HLT[295];
   OUT::HLT[296] = IN::HLT[296];
   OUT::HLT[297] = IN::HLT[297];
   OUT::HLT[298] = IN::HLT[298];
   OUT::HLT[299] = IN::HLT[299];
   OUT::HLT[300] = IN::HLT[300];
   OUT::HLT[301] = IN::HLT[301];
   OUT::HLT[302] = IN::HLT[302];
   OUT::HLT[303] = IN::HLT[303];
   OUT::HLT[304] = IN::HLT[304];
   OUT::HLT[305] = IN::HLT[305];
   OUT::HLT[306] = IN::HLT[306];
   OUT::HLT[307] = IN::HLT[307];
   OUT::HLT[308] = IN::HLT[308];
   OUT::HLT[309] = IN::HLT[309];
   OUT::HLT[310] = IN::HLT[310];
   OUT::HLT[311] = IN::HLT[311];
   OUT::HLT[312] = IN::HLT[312];
   OUT::HLT[313] = IN::HLT[313];
   OUT::HLT[314] = IN::HLT[314];
   OUT::HLT[315] = IN::HLT[315];
   OUT::HLT[316] = IN::HLT[316];
   OUT::HLT[317] = IN::HLT[317];
   OUT::HLT[318] = IN::HLT[318];
   OUT::HLT[319] = IN::HLT[319];
   OUT::HLT[320] = IN::HLT[320];
   OUT::HLT[321] = IN::HLT[321];
   OUT::HLT[322] = IN::HLT[322];
   OUT::HLT[323] = IN::HLT[323];
   OUT::HLT[324] = IN::HLT[324];
   OUT::HLT[325] = IN::HLT[325];
   OUT::HLT[326] = IN::HLT[326];
   OUT::HLT[327] = IN::HLT[327];
   OUT::HLT[328] = IN::HLT[328];
   OUT::HLT[329] = IN::HLT[329];
   OUT::HLT[330] = IN::HLT[330];
   OUT::HLT[331] = IN::HLT[331];
   OUT::HLT[332] = IN::HLT[332];
   OUT::HLT[333] = IN::HLT[333];
   OUT::HLT[334] = IN::HLT[334];
   OUT::HLT[335] = IN::HLT[335];
   OUT::HLT[336] = IN::HLT[336];
   OUT::HLT[337] = IN::HLT[337];
   OUT::HLT[338] = IN::HLT[338];
   OUT::HLT[339] = IN::HLT[339];
   OUT::HLT[340] = IN::HLT[340];
   OUT::HLT[341] = IN::HLT[341];
   OUT::HLT[342] = IN::HLT[342];
   OUT::HLT[343] = IN::HLT[343];
   OUT::HLT[344] = IN::HLT[344];
   OUT::HLT[345] = IN::HLT[345];
   OUT::HLT[346] = IN::HLT[346];
   OUT::HLT[347] = IN::HLT[347];
   OUT::HLT[348] = IN::HLT[348];
   OUT::HLT[349] = IN::HLT[349];
   OUT::HLT[350] = IN::HLT[350];
   OUT::HLT[351] = IN::HLT[351];
   OUT::HLT[352] = IN::HLT[352];
   OUT::HLT[353] = IN::HLT[353];
   OUT::HLT[354] = IN::HLT[354];
   OUT::HLT[355] = IN::HLT[355];
   OUT::HLT[356] = IN::HLT[356];
   OUT::HLT[357] = IN::HLT[357];
   OUT::HLT[358] = IN::HLT[358];
   OUT::HLT[359] = IN::HLT[359];
   OUT::HLT[360] = IN::HLT[360];
   OUT::HLT[361] = IN::HLT[361];
   OUT::HLT[362] = IN::HLT[362];
   OUT::HLT[363] = IN::HLT[363];
   OUT::HLT[364] = IN::HLT[364];
   OUT::HLT[365] = IN::HLT[365];
   OUT::HLT[366] = IN::HLT[366];
   OUT::HLT[367] = IN::HLT[367];
   OUT::HLT[368] = IN::HLT[368];
   OUT::HLT[369] = IN::HLT[369];
   OUT::HLT[370] = IN::HLT[370];
   OUT::HLT[371] = IN::HLT[371];
   OUT::HLT[372] = IN::HLT[372];
   OUT::HLT[373] = IN::HLT[373];
   OUT::HLT[374] = IN::HLT[374];
   OUT::HLT[375] = IN::HLT[375];
   OUT::HLT[376] = IN::HLT[376];
   OUT::HLT[377] = IN::HLT[377];
   OUT::HLT[378] = IN::HLT[378];
   OUT::HLT[379] = IN::HLT[379];
   OUT::HLT[380] = IN::HLT[380];
   OUT::HLT[381] = IN::HLT[381];
   OUT::HLT[382] = IN::HLT[382];
   OUT::HLT[383] = IN::HLT[383];
   OUT::HLT[384] = IN::HLT[384];
   OUT::HLT[385] = IN::HLT[385];
   OUT::HLT[386] = IN::HLT[386];
   OUT::HLT[387] = IN::HLT[387];
   OUT::HLT[388] = IN::HLT[388];
   OUT::HLT[389] = IN::HLT[389];
   OUT::HLT[390] = IN::HLT[390];
   OUT::HLT[391] = IN::HLT[391];
   OUT::HLT[392] = IN::HLT[392];
   OUT::HLT[393] = IN::HLT[393];
   OUT::HLT[394] = IN::HLT[394];
   OUT::HLT[395] = IN::HLT[395];
   OUT::HLT[396] = IN::HLT[396];
   OUT::HLT[397] = IN::HLT[397];
   OUT::HLT[398] = IN::HLT[398];
   OUT::HLT[399] = IN::HLT[399];
   OUT::HLT[400] = IN::HLT[400];
   OUT::HLT[401] = IN::HLT[401];
   OUT::HLT[402] = IN::HLT[402];
   OUT::HLT[403] = IN::HLT[403];
   OUT::HLT[404] = IN::HLT[404];
   OUT::HLT[405] = IN::HLT[405];
   OUT::HLT[406] = IN::HLT[406];
   OUT::HLT[407] = IN::HLT[407];
   OUT::HLT[408] = IN::HLT[408];
   OUT::HLT[409] = IN::HLT[409];
   OUT::HLT[410] = IN::HLT[410];
   OUT::HLT[411] = IN::HLT[411];
   OUT::HLT[412] = IN::HLT[412];
   OUT::HLT[413] = IN::HLT[413];
   OUT::HLT[414] = IN::HLT[414];
   OUT::HLT[415] = IN::HLT[415];
   OUT::HLT[416] = IN::HLT[416];
   OUT::HLT[417] = IN::HLT[417];
   OUT::HLT[418] = IN::HLT[418];
   OUT::HLT[419] = IN::HLT[419];
   OUT::HLT[420] = IN::HLT[420];
   OUT::HLT[421] = IN::HLT[421];
   OUT::HLT[422] = IN::HLT[422];
   OUT::HLT[423] = IN::HLT[423];
   OUT::HLT[424] = IN::HLT[424];
   OUT::HLT[425] = IN::HLT[425];
   OUT::HLT[426] = IN::HLT[426];
   OUT::HLT[427] = IN::HLT[427];
   OUT::HLT[428] = IN::HLT[428];
   OUT::HLT[429] = IN::HLT[429];
   OUT::HLT[430] = IN::HLT[430];
   OUT::HLT[431] = IN::HLT[431];
   OUT::HLT[432] = IN::HLT[432];
   OUT::HLT[433] = IN::HLT[433];
   OUT::HLT[434] = IN::HLT[434];
   OUT::HLT[435] = IN::HLT[435];
   OUT::HLT[436] = IN::HLT[436];
   OUT::HLT[437] = IN::HLT[437];
   OUT::HLT[438] = IN::HLT[438];
   OUT::HLT[439] = IN::HLT[439];
   OUT::HLT[440] = IN::HLT[440];
   OUT::HLT[441] = IN::HLT[441];
   OUT::HLT[442] = IN::HLT[442];
   OUT::HLT[443] = IN::HLT[443];
   OUT::HLT[444] = IN::HLT[444];
   OUT::HLT[445] = IN::HLT[445];
   OUT::HLT[446] = IN::HLT[446];
   OUT::HLT[447] = IN::HLT[447];
   OUT::HLT[448] = IN::HLT[448];
   OUT::HLT[449] = IN::HLT[449];
   OUT::HLT[450] = IN::HLT[450];
   OUT::HLT[451] = IN::HLT[451];
   OUT::HLT[452] = IN::HLT[452];
 }; 

 void CopyHLTIndexInToOut( std::string prefix ) { 

    std::string my_name = "HLTIndex";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  std::copy(IN::HLTIndex, IN::HLTIndex+70, OUT::HLTIndex);
 }; 

 void CopybspotPosInToOut( std::string prefix ) { 

    std::string my_name = "bspotPos";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  std::copy(IN::bspotPos, IN::bspotPos+3, OUT::bspotPos);
 }; 

 void CopynVtxInToOut( std::string prefix ) { 

    std::string my_name = "nVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nVtx = IN::nVtx;
}; 

 void Copyvtx_xInToOut( std::string prefix ) { 

    std::string my_name = "vtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::vtx_x = std::vector<float>(*IN::vtx_x);
}; 

 void Copyvtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "vtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::vtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::vtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible vtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::vtx_x->push_back( IN::vtx_x->at(index) ); 
 }; 

 void ClearOutputvtx_x( std::string  prefix ) { 

    std::string my_name = "vtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible vtx_x, prefix = " << prefix << std::endl; 
     OUT::vtx_x->clear(); 
 }; 

 void Copyvtx_yInToOut( std::string prefix ) { 

    std::string my_name = "vtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::vtx_y = std::vector<float>(*IN::vtx_y);
}; 

 void Copyvtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "vtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::vtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::vtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible vtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::vtx_y->push_back( IN::vtx_y->at(index) ); 
 }; 

 void ClearOutputvtx_y( std::string  prefix ) { 

    std::string my_name = "vtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible vtx_y, prefix = " << prefix << std::endl; 
     OUT::vtx_y->clear(); 
 }; 

 void Copyvtx_zInToOut( std::string prefix ) { 

    std::string my_name = "vtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::vtx_z = std::vector<float>(*IN::vtx_z);
}; 

 void Copyvtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "vtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::vtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::vtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible vtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::vtx_z->push_back( IN::vtx_z->at(index) ); 
 }; 

 void ClearOutputvtx_z( std::string  prefix ) { 

    std::string my_name = "vtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible vtx_z, prefix = " << prefix << std::endl; 
     OUT::vtx_z->clear(); 
 }; 

 void CopyIsVtxGoodInToOut( std::string prefix ) { 

    std::string my_name = "IsVtxGood";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::IsVtxGood = IN::IsVtxGood;
}; 

 void CopynGoodVtxInToOut( std::string prefix ) { 

    std::string my_name = "nGoodVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nGoodVtx = IN::nGoodVtx;
}; 

 void CopynVtxBSInToOut( std::string prefix ) { 

    std::string my_name = "nVtxBS";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nVtxBS = IN::nVtxBS;
}; 

 void Copyvtxbs_xInToOut( std::string prefix ) { 

    std::string my_name = "vtxbs_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::vtxbs_x = std::vector<float>(*IN::vtxbs_x);
}; 

 void Copyvtxbs_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "vtxbs_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::vtxbs_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::vtxbs_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible vtxbs_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::vtxbs_x->push_back( IN::vtxbs_x->at(index) ); 
 }; 

 void ClearOutputvtxbs_x( std::string  prefix ) { 

    std::string my_name = "vtxbs_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible vtxbs_x, prefix = " << prefix << std::endl; 
     OUT::vtxbs_x->clear(); 
 }; 

 void Copyvtxbs_yInToOut( std::string prefix ) { 

    std::string my_name = "vtxbs_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::vtxbs_y = std::vector<float>(*IN::vtxbs_y);
}; 

 void Copyvtxbs_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "vtxbs_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::vtxbs_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::vtxbs_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible vtxbs_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::vtxbs_y->push_back( IN::vtxbs_y->at(index) ); 
 }; 

 void ClearOutputvtxbs_y( std::string  prefix ) { 

    std::string my_name = "vtxbs_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible vtxbs_y, prefix = " << prefix << std::endl; 
     OUT::vtxbs_y->clear(); 
 }; 

 void Copyvtxbs_zInToOut( std::string prefix ) { 

    std::string my_name = "vtxbs_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::vtxbs_z = std::vector<float>(*IN::vtxbs_z);
}; 

 void Copyvtxbs_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "vtxbs_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::vtxbs_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::vtxbs_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible vtxbs_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::vtxbs_z->push_back( IN::vtxbs_z->at(index) ); 
 }; 

 void ClearOutputvtxbs_z( std::string  prefix ) { 

    std::string my_name = "vtxbs_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible vtxbs_z, prefix = " << prefix << std::endl; 
     OUT::vtxbs_z->clear(); 
 }; 

 void CopypfMETInToOut( std::string prefix ) { 

    std::string my_name = "pfMET";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfMET = IN::pfMET;
}; 

 void CopypfMETPhiInToOut( std::string prefix ) { 

    std::string my_name = "pfMETPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfMETPhi = IN::pfMETPhi;
}; 

 void CopypfMETsumEtInToOut( std::string prefix ) { 

    std::string my_name = "pfMETsumEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfMETsumEt = IN::pfMETsumEt;
}; 

 void CopypfMETmEtSigInToOut( std::string prefix ) { 

    std::string my_name = "pfMETmEtSig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfMETmEtSig = IN::pfMETmEtSig;
}; 

 void CopypfMETSigInToOut( std::string prefix ) { 

    std::string my_name = "pfMETSig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfMETSig = IN::pfMETSig;
}; 

 void CopypfType01METInToOut( std::string prefix ) { 

    std::string my_name = "pfType01MET";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfType01MET = IN::pfType01MET;
}; 

 void CopypfType01METPhiInToOut( std::string prefix ) { 

    std::string my_name = "pfType01METPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfType01METPhi = IN::pfType01METPhi;
}; 

 void CopypfType01METsumEtInToOut( std::string prefix ) { 

    std::string my_name = "pfType01METsumEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfType01METsumEt = IN::pfType01METsumEt;
}; 

 void CopypfType01METmEtSigInToOut( std::string prefix ) { 

    std::string my_name = "pfType01METmEtSig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfType01METmEtSig = IN::pfType01METmEtSig;
}; 

 void CopypfType01METSigInToOut( std::string prefix ) { 

    std::string my_name = "pfType01METSig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pfType01METSig = IN::pfType01METSig;
}; 

 void CopyrecoPfMETInToOut( std::string prefix ) { 

    std::string my_name = "recoPfMET";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::recoPfMET = IN::recoPfMET;
}; 

 void CopyrecoPfMETPhiInToOut( std::string prefix ) { 

    std::string my_name = "recoPfMETPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::recoPfMETPhi = IN::recoPfMETPhi;
}; 

 void CopyrecoPfMETsumEtInToOut( std::string prefix ) { 

    std::string my_name = "recoPfMETsumEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::recoPfMETsumEt = IN::recoPfMETsumEt;
}; 

 void CopyrecoPfMETmEtSigInToOut( std::string prefix ) { 

    std::string my_name = "recoPfMETmEtSig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::recoPfMETmEtSig = IN::recoPfMETmEtSig;
}; 

 void CopyrecoPfMETSigInToOut( std::string prefix ) { 

    std::string my_name = "recoPfMETSig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::recoPfMETSig = IN::recoPfMETSig;
}; 

 void CopytrkMETxPVInToOut( std::string prefix ) { 

    std::string my_name = "trkMETxPV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::trkMETxPV = IN::trkMETxPV;
}; 

 void CopytrkMETyPVInToOut( std::string prefix ) { 

    std::string my_name = "trkMETyPV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::trkMETyPV = IN::trkMETyPV;
}; 

 void CopytrkMETPhiPVInToOut( std::string prefix ) { 

    std::string my_name = "trkMETPhiPV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::trkMETPhiPV = IN::trkMETPhiPV;
}; 

 void CopytrkMETPVInToOut( std::string prefix ) { 

    std::string my_name = "trkMETPV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::trkMETPV = IN::trkMETPV;
}; 

 void CopytrkMETxInToOut( std::string prefix ) { 

    std::string my_name = "trkMETx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::trkMETx = std::vector<float>(*IN::trkMETx);
}; 

 void CopytrkMETxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "trkMETx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::trkMETx->size() ) {
         std::cout << "Vector size exceeded for branch IN::trkMETx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible trkMETx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::trkMETx->push_back( IN::trkMETx->at(index) ); 
 }; 

 void ClearOutputtrkMETx( std::string  prefix ) { 

    std::string my_name = "trkMETx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible trkMETx, prefix = " << prefix << std::endl; 
     OUT::trkMETx->clear(); 
 }; 

 void CopytrkMETyInToOut( std::string prefix ) { 

    std::string my_name = "trkMETy";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::trkMETy = std::vector<float>(*IN::trkMETy);
}; 

 void CopytrkMETyInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "trkMETy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::trkMETy->size() ) {
         std::cout << "Vector size exceeded for branch IN::trkMETy" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible trkMETy" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::trkMETy->push_back( IN::trkMETy->at(index) ); 
 }; 

 void ClearOutputtrkMETy( std::string  prefix ) { 

    std::string my_name = "trkMETy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible trkMETy, prefix = " << prefix << std::endl; 
     OUT::trkMETy->clear(); 
 }; 

 void CopytrkMETPhiInToOut( std::string prefix ) { 

    std::string my_name = "trkMETPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::trkMETPhi = std::vector<float>(*IN::trkMETPhi);
}; 

 void CopytrkMETPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "trkMETPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::trkMETPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::trkMETPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible trkMETPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::trkMETPhi->push_back( IN::trkMETPhi->at(index) ); 
 }; 

 void ClearOutputtrkMETPhi( std::string  prefix ) { 

    std::string my_name = "trkMETPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible trkMETPhi, prefix = " << prefix << std::endl; 
     OUT::trkMETPhi->clear(); 
 }; 

 void CopytrkMETInToOut( std::string prefix ) { 

    std::string my_name = "trkMET";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::trkMET = std::vector<float>(*IN::trkMET);
}; 

 void CopytrkMETInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "trkMET";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::trkMET->size() ) {
         std::cout << "Vector size exceeded for branch IN::trkMET" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible trkMET" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::trkMET->push_back( IN::trkMET->at(index) ); 
 }; 

 void ClearOutputtrkMET( std::string  prefix ) { 

    std::string my_name = "trkMET";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible trkMET, prefix = " << prefix << std::endl; 
     OUT::trkMET->clear(); 
 }; 

 void CopymetFiltersInToOut( std::string prefix ) { 

    std::string my_name = "metFilters";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  std::copy(IN::metFilters, IN::metFilters+10, OUT::metFilters);
 }; 

 void CopynEleInToOut( std::string prefix ) { 

    std::string my_name = "nEle";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nEle = IN::nEle;
}; 

 void CopyeleTrgInToOut( std::string prefix ) { 

    std::string my_name = "eleTrg";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleTrg = std::vector<unsigned long>(*IN::eleTrg);
}; 

 void CopyeleTrgInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleTrg->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleTrg" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleTrg" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleTrg->push_back( IN::eleTrg->at(index) ); 
 }; 

 void ClearOutputeleTrg( std::string  prefix ) { 

    std::string my_name = "eleTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleTrg, prefix = " << prefix << std::endl; 
     OUT::eleTrg->clear(); 
 }; 

 void CopyeleClassInToOut( std::string prefix ) { 

    std::string my_name = "eleClass";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleClass = std::vector<int>(*IN::eleClass);
}; 

 void CopyeleClassInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleClass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleClass->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleClass" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleClass" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleClass->push_back( IN::eleClass->at(index) ); 
 }; 

 void ClearOutputeleClass( std::string  prefix ) { 

    std::string my_name = "eleClass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleClass, prefix = " << prefix << std::endl; 
     OUT::eleClass->clear(); 
 }; 

 void CopyeleIsEcalDrivenInToOut( std::string prefix ) { 

    std::string my_name = "eleIsEcalDriven";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsEcalDriven = std::vector<int>(*IN::eleIsEcalDriven);
}; 

 void CopyeleIsEcalDrivenInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsEcalDriven";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsEcalDriven->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsEcalDriven" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsEcalDriven" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsEcalDriven->push_back( IN::eleIsEcalDriven->at(index) ); 
 }; 

 void ClearOutputeleIsEcalDriven( std::string  prefix ) { 

    std::string my_name = "eleIsEcalDriven";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsEcalDriven, prefix = " << prefix << std::endl; 
     OUT::eleIsEcalDriven->clear(); 
 }; 

 void CopyeleChargeInToOut( std::string prefix ) { 

    std::string my_name = "eleCharge";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleCharge = std::vector<int>(*IN::eleCharge);
}; 

 void CopyeleChargeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleCharge->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleCharge" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleCharge" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleCharge->push_back( IN::eleCharge->at(index) ); 
 }; 

 void ClearOutputeleCharge( std::string  prefix ) { 

    std::string my_name = "eleCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleCharge, prefix = " << prefix << std::endl; 
     OUT::eleCharge->clear(); 
 }; 

 void CopyeleChargeConsistentInToOut( std::string prefix ) { 

    std::string my_name = "eleChargeConsistent";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleChargeConsistent = std::vector<int>(*IN::eleChargeConsistent);
}; 

 void CopyeleChargeConsistentInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleChargeConsistent";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleChargeConsistent->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleChargeConsistent" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleChargeConsistent" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleChargeConsistent->push_back( IN::eleChargeConsistent->at(index) ); 
 }; 

 void ClearOutputeleChargeConsistent( std::string  prefix ) { 

    std::string my_name = "eleChargeConsistent";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleChargeConsistent, prefix = " << prefix << std::endl; 
     OUT::eleChargeConsistent->clear(); 
 }; 

 void CopyeleEnInToOut( std::string prefix ) { 

    std::string my_name = "eleEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEn = std::vector<float>(*IN::eleEn);
}; 

 void CopyeleEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEn->push_back( IN::eleEn->at(index) ); 
 }; 

 void ClearOutputeleEn( std::string  prefix ) { 

    std::string my_name = "eleEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEn, prefix = " << prefix << std::endl; 
     OUT::eleEn->clear(); 
 }; 

 void CopyeleEcalEnInToOut( std::string prefix ) { 

    std::string my_name = "eleEcalEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEcalEn = std::vector<float>(*IN::eleEcalEn);
}; 

 void CopyeleEcalEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEcalEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEcalEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEcalEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEcalEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEcalEn->push_back( IN::eleEcalEn->at(index) ); 
 }; 

 void ClearOutputeleEcalEn( std::string  prefix ) { 

    std::string my_name = "eleEcalEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEcalEn, prefix = " << prefix << std::endl; 
     OUT::eleEcalEn->clear(); 
 }; 

 void CopyeleSCRawEnInToOut( std::string prefix ) { 

    std::string my_name = "eleSCRawEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSCRawEn = std::vector<float>(*IN::eleSCRawEn);
}; 

 void CopyeleSCRawEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSCRawEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSCRawEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSCRawEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSCRawEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSCRawEn->push_back( IN::eleSCRawEn->at(index) ); 
 }; 

 void ClearOutputeleSCRawEn( std::string  prefix ) { 

    std::string my_name = "eleSCRawEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSCRawEn, prefix = " << prefix << std::endl; 
     OUT::eleSCRawEn->clear(); 
 }; 

 void CopyeleSCEnInToOut( std::string prefix ) { 

    std::string my_name = "eleSCEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSCEn = std::vector<float>(*IN::eleSCEn);
}; 

 void CopyeleSCEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSCEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSCEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSCEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSCEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSCEn->push_back( IN::eleSCEn->at(index) ); 
 }; 

 void ClearOutputeleSCEn( std::string  prefix ) { 

    std::string my_name = "eleSCEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSCEn, prefix = " << prefix << std::endl; 
     OUT::eleSCEn->clear(); 
 }; 

 void CopyeleESEnInToOut( std::string prefix ) { 

    std::string my_name = "eleESEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleESEn = std::vector<float>(*IN::eleESEn);
}; 

 void CopyeleESEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleESEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleESEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleESEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleESEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleESEn->push_back( IN::eleESEn->at(index) ); 
 }; 

 void ClearOutputeleESEn( std::string  prefix ) { 

    std::string my_name = "eleESEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleESEn, prefix = " << prefix << std::endl; 
     OUT::eleESEn->clear(); 
 }; 

 void CopyelePtInToOut( std::string prefix ) { 

    std::string my_name = "elePt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePt = std::vector<float>(*IN::elePt);
}; 

 void CopyelePtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePt->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePt->push_back( IN::elePt->at(index) ); 
 }; 

 void ClearOutputelePt( std::string  prefix ) { 

    std::string my_name = "elePt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePt, prefix = " << prefix << std::endl; 
     OUT::elePt->clear(); 
 }; 

 void CopyeleEtaInToOut( std::string prefix ) { 

    std::string my_name = "eleEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEta = std::vector<float>(*IN::eleEta);
}; 

 void CopyeleEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEta->push_back( IN::eleEta->at(index) ); 
 }; 

 void ClearOutputeleEta( std::string  prefix ) { 

    std::string my_name = "eleEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEta, prefix = " << prefix << std::endl; 
     OUT::eleEta->clear(); 
 }; 

 void CopyelePhiInToOut( std::string prefix ) { 

    std::string my_name = "elePhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePhi = std::vector<float>(*IN::elePhi);
}; 

 void CopyelePhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePhi->push_back( IN::elePhi->at(index) ); 
 }; 

 void ClearOutputelePhi( std::string  prefix ) { 

    std::string my_name = "elePhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePhi, prefix = " << prefix << std::endl; 
     OUT::elePhi->clear(); 
 }; 

 void CopyeleR9InToOut( std::string prefix ) { 

    std::string my_name = "eleR9";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleR9 = std::vector<float>(*IN::eleR9);
}; 

 void CopyeleR9InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleR9";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleR9->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleR9" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleR9" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleR9->push_back( IN::eleR9->at(index) ); 
 }; 

 void ClearOutputeleR9( std::string  prefix ) { 

    std::string my_name = "eleR9";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleR9, prefix = " << prefix << std::endl; 
     OUT::eleR9->clear(); 
 }; 

 void CopyeleEtaVtxInToOut( std::string prefix ) { 

    std::string my_name = "eleEtaVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEtaVtx = std::vector<std::vector<float> >(*IN::eleEtaVtx);
}; 

 void CopyeleEtaVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEtaVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEtaVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEtaVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEtaVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEtaVtx->push_back( IN::eleEtaVtx->at(index) ); 
 }; 

 void ClearOutputeleEtaVtx( std::string  prefix ) { 

    std::string my_name = "eleEtaVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEtaVtx, prefix = " << prefix << std::endl; 
     OUT::eleEtaVtx->clear(); 
 }; 

 void CopyelePhiVtxInToOut( std::string prefix ) { 

    std::string my_name = "elePhiVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePhiVtx = std::vector<std::vector<float> >(*IN::elePhiVtx);
}; 

 void CopyelePhiVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePhiVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePhiVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePhiVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePhiVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePhiVtx->push_back( IN::elePhiVtx->at(index) ); 
 }; 

 void ClearOutputelePhiVtx( std::string  prefix ) { 

    std::string my_name = "elePhiVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePhiVtx, prefix = " << prefix << std::endl; 
     OUT::elePhiVtx->clear(); 
 }; 

 void CopyeleEtVtxInToOut( std::string prefix ) { 

    std::string my_name = "eleEtVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEtVtx = std::vector<std::vector<float> >(*IN::eleEtVtx);
}; 

 void CopyeleEtVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEtVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEtVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEtVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEtVtx->push_back( IN::eleEtVtx->at(index) ); 
 }; 

 void ClearOutputeleEtVtx( std::string  prefix ) { 

    std::string my_name = "eleEtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEtVtx, prefix = " << prefix << std::endl; 
     OUT::eleEtVtx->clear(); 
 }; 

 void CopyeleSCEtaInToOut( std::string prefix ) { 

    std::string my_name = "eleSCEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSCEta = std::vector<float>(*IN::eleSCEta);
}; 

 void CopyeleSCEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSCEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSCEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSCEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSCEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSCEta->push_back( IN::eleSCEta->at(index) ); 
 }; 

 void ClearOutputeleSCEta( std::string  prefix ) { 

    std::string my_name = "eleSCEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSCEta, prefix = " << prefix << std::endl; 
     OUT::eleSCEta->clear(); 
 }; 

 void CopyeleSCPhiInToOut( std::string prefix ) { 

    std::string my_name = "eleSCPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSCPhi = std::vector<float>(*IN::eleSCPhi);
}; 

 void CopyeleSCPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSCPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSCPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSCPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSCPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSCPhi->push_back( IN::eleSCPhi->at(index) ); 
 }; 

 void ClearOutputeleSCPhi( std::string  prefix ) { 

    std::string my_name = "eleSCPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSCPhi, prefix = " << prefix << std::endl; 
     OUT::eleSCPhi->clear(); 
 }; 

 void CopyeleSCEtaWidthInToOut( std::string prefix ) { 

    std::string my_name = "eleSCEtaWidth";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSCEtaWidth = std::vector<float>(*IN::eleSCEtaWidth);
}; 

 void CopyeleSCEtaWidthInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSCEtaWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSCEtaWidth->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSCEtaWidth" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSCEtaWidth" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSCEtaWidth->push_back( IN::eleSCEtaWidth->at(index) ); 
 }; 

 void ClearOutputeleSCEtaWidth( std::string  prefix ) { 

    std::string my_name = "eleSCEtaWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSCEtaWidth, prefix = " << prefix << std::endl; 
     OUT::eleSCEtaWidth->clear(); 
 }; 

 void CopyeleSCPhiWidthInToOut( std::string prefix ) { 

    std::string my_name = "eleSCPhiWidth";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSCPhiWidth = std::vector<float>(*IN::eleSCPhiWidth);
}; 

 void CopyeleSCPhiWidthInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSCPhiWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSCPhiWidth->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSCPhiWidth" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSCPhiWidth" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSCPhiWidth->push_back( IN::eleSCPhiWidth->at(index) ); 
 }; 

 void ClearOutputeleSCPhiWidth( std::string  prefix ) { 

    std::string my_name = "eleSCPhiWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSCPhiWidth, prefix = " << prefix << std::endl; 
     OUT::eleSCPhiWidth->clear(); 
 }; 

 void CopyeleVtx_xInToOut( std::string prefix ) { 

    std::string my_name = "eleVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleVtx_x = std::vector<float>(*IN::eleVtx_x);
}; 

 void CopyeleVtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleVtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleVtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleVtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleVtx_x->push_back( IN::eleVtx_x->at(index) ); 
 }; 

 void ClearOutputeleVtx_x( std::string  prefix ) { 

    std::string my_name = "eleVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleVtx_x, prefix = " << prefix << std::endl; 
     OUT::eleVtx_x->clear(); 
 }; 

 void CopyeleVtx_yInToOut( std::string prefix ) { 

    std::string my_name = "eleVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleVtx_y = std::vector<float>(*IN::eleVtx_y);
}; 

 void CopyeleVtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleVtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleVtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleVtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleVtx_y->push_back( IN::eleVtx_y->at(index) ); 
 }; 

 void ClearOutputeleVtx_y( std::string  prefix ) { 

    std::string my_name = "eleVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleVtx_y, prefix = " << prefix << std::endl; 
     OUT::eleVtx_y->clear(); 
 }; 

 void CopyeleVtx_zInToOut( std::string prefix ) { 

    std::string my_name = "eleVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleVtx_z = std::vector<float>(*IN::eleVtx_z);
}; 

 void CopyeleVtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleVtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleVtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleVtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleVtx_z->push_back( IN::eleVtx_z->at(index) ); 
 }; 

 void ClearOutputeleVtx_z( std::string  prefix ) { 

    std::string my_name = "eleVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleVtx_z, prefix = " << prefix << std::endl; 
     OUT::eleVtx_z->clear(); 
 }; 

 void CopyeleD0InToOut( std::string prefix ) { 

    std::string my_name = "eleD0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleD0 = std::vector<float>(*IN::eleD0);
}; 

 void CopyeleD0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleD0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleD0->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleD0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleD0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleD0->push_back( IN::eleD0->at(index) ); 
 }; 

 void ClearOutputeleD0( std::string  prefix ) { 

    std::string my_name = "eleD0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleD0, prefix = " << prefix << std::endl; 
     OUT::eleD0->clear(); 
 }; 

 void CopyeleDzInToOut( std::string prefix ) { 

    std::string my_name = "eleDz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleDz = std::vector<float>(*IN::eleDz);
}; 

 void CopyeleDzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleDz->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleDz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleDz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleDz->push_back( IN::eleDz->at(index) ); 
 }; 

 void ClearOutputeleDz( std::string  prefix ) { 

    std::string my_name = "eleDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleDz, prefix = " << prefix << std::endl; 
     OUT::eleDz->clear(); 
 }; 

 void CopyeleD0GVInToOut( std::string prefix ) { 

    std::string my_name = "eleD0GV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleD0GV = std::vector<float>(*IN::eleD0GV);
}; 

 void CopyeleD0GVInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleD0GV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleD0GV->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleD0GV" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleD0GV" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleD0GV->push_back( IN::eleD0GV->at(index) ); 
 }; 

 void ClearOutputeleD0GV( std::string  prefix ) { 

    std::string my_name = "eleD0GV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleD0GV, prefix = " << prefix << std::endl; 
     OUT::eleD0GV->clear(); 
 }; 

 void CopyeleDzGVInToOut( std::string prefix ) { 

    std::string my_name = "eleDzGV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleDzGV = std::vector<float>(*IN::eleDzGV);
}; 

 void CopyeleDzGVInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleDzGV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleDzGV->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleDzGV" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleDzGV" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleDzGV->push_back( IN::eleDzGV->at(index) ); 
 }; 

 void ClearOutputeleDzGV( std::string  prefix ) { 

    std::string my_name = "eleDzGV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleDzGV, prefix = " << prefix << std::endl; 
     OUT::eleDzGV->clear(); 
 }; 

 void CopyeleD0VtxInToOut( std::string prefix ) { 

    std::string my_name = "eleD0Vtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleD0Vtx = std::vector<std::vector<float> >(*IN::eleD0Vtx);
}; 

 void CopyeleD0VtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleD0Vtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleD0Vtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleD0Vtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleD0Vtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleD0Vtx->push_back( IN::eleD0Vtx->at(index) ); 
 }; 

 void ClearOutputeleD0Vtx( std::string  prefix ) { 

    std::string my_name = "eleD0Vtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleD0Vtx, prefix = " << prefix << std::endl; 
     OUT::eleD0Vtx->clear(); 
 }; 

 void CopyeleDzVtxInToOut( std::string prefix ) { 

    std::string my_name = "eleDzVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleDzVtx = std::vector<std::vector<float> >(*IN::eleDzVtx);
}; 

 void CopyeleDzVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleDzVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleDzVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleDzVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleDzVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleDzVtx->push_back( IN::eleDzVtx->at(index) ); 
 }; 

 void ClearOutputeleDzVtx( std::string  prefix ) { 

    std::string my_name = "eleDzVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleDzVtx, prefix = " << prefix << std::endl; 
     OUT::eleDzVtx->clear(); 
 }; 

 void CopyeleHoverEInToOut( std::string prefix ) { 

    std::string my_name = "eleHoverE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleHoverE = std::vector<float>(*IN::eleHoverE);
}; 

 void CopyeleHoverEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleHoverE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleHoverE->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleHoverE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleHoverE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleHoverE->push_back( IN::eleHoverE->at(index) ); 
 }; 

 void ClearOutputeleHoverE( std::string  prefix ) { 

    std::string my_name = "eleHoverE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleHoverE, prefix = " << prefix << std::endl; 
     OUT::eleHoverE->clear(); 
 }; 

 void CopyeleHoverE12InToOut( std::string prefix ) { 

    std::string my_name = "eleHoverE12";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleHoverE12 = std::vector<float>(*IN::eleHoverE12);
}; 

 void CopyeleHoverE12InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleHoverE12";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleHoverE12->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleHoverE12" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleHoverE12" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleHoverE12->push_back( IN::eleHoverE12->at(index) ); 
 }; 

 void ClearOutputeleHoverE12( std::string  prefix ) { 

    std::string my_name = "eleHoverE12";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleHoverE12, prefix = " << prefix << std::endl; 
     OUT::eleHoverE12->clear(); 
 }; 

 void CopyeleEoverPInToOut( std::string prefix ) { 

    std::string my_name = "eleEoverP";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEoverP = std::vector<float>(*IN::eleEoverP);
}; 

 void CopyeleEoverPInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEoverP";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEoverP->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEoverP" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEoverP" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEoverP->push_back( IN::eleEoverP->at(index) ); 
 }; 

 void ClearOutputeleEoverP( std::string  prefix ) { 

    std::string my_name = "eleEoverP";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEoverP, prefix = " << prefix << std::endl; 
     OUT::eleEoverP->clear(); 
 }; 

 void CopyelePinInToOut( std::string prefix ) { 

    std::string my_name = "elePin";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePin = std::vector<float>(*IN::elePin);
}; 

 void CopyelePinInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePin";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePin->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePin" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePin" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePin->push_back( IN::elePin->at(index) ); 
 }; 

 void ClearOutputelePin( std::string  prefix ) { 

    std::string my_name = "elePin";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePin, prefix = " << prefix << std::endl; 
     OUT::elePin->clear(); 
 }; 

 void CopyelePoutInToOut( std::string prefix ) { 

    std::string my_name = "elePout";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePout = std::vector<float>(*IN::elePout);
}; 

 void CopyelePoutInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePout";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePout->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePout" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePout" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePout->push_back( IN::elePout->at(index) ); 
 }; 

 void ClearOutputelePout( std::string  prefix ) { 

    std::string my_name = "elePout";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePout, prefix = " << prefix << std::endl; 
     OUT::elePout->clear(); 
 }; 

 void CopyeleTrkMomErrInToOut( std::string prefix ) { 

    std::string my_name = "eleTrkMomErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleTrkMomErr = std::vector<float>(*IN::eleTrkMomErr);
}; 

 void CopyeleTrkMomErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleTrkMomErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleTrkMomErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleTrkMomErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleTrkMomErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleTrkMomErr->push_back( IN::eleTrkMomErr->at(index) ); 
 }; 

 void ClearOutputeleTrkMomErr( std::string  prefix ) { 

    std::string my_name = "eleTrkMomErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleTrkMomErr, prefix = " << prefix << std::endl; 
     OUT::eleTrkMomErr->clear(); 
 }; 

 void CopyeleBremInToOut( std::string prefix ) { 

    std::string my_name = "eleBrem";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleBrem = std::vector<float>(*IN::eleBrem);
}; 

 void CopyeleBremInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleBrem";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleBrem->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleBrem" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleBrem" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleBrem->push_back( IN::eleBrem->at(index) ); 
 }; 

 void ClearOutputeleBrem( std::string  prefix ) { 

    std::string my_name = "eleBrem";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleBrem, prefix = " << prefix << std::endl; 
     OUT::eleBrem->clear(); 
 }; 

 void CopyeledEtaAtVtxInToOut( std::string prefix ) { 

    std::string my_name = "eledEtaAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eledEtaAtVtx = std::vector<float>(*IN::eledEtaAtVtx);
}; 

 void CopyeledEtaAtVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eledEtaAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eledEtaAtVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::eledEtaAtVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eledEtaAtVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eledEtaAtVtx->push_back( IN::eledEtaAtVtx->at(index) ); 
 }; 

 void ClearOutputeledEtaAtVtx( std::string  prefix ) { 

    std::string my_name = "eledEtaAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eledEtaAtVtx, prefix = " << prefix << std::endl; 
     OUT::eledEtaAtVtx->clear(); 
 }; 

 void CopyeledPhiAtVtxInToOut( std::string prefix ) { 

    std::string my_name = "eledPhiAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eledPhiAtVtx = std::vector<float>(*IN::eledPhiAtVtx);
}; 

 void CopyeledPhiAtVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eledPhiAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eledPhiAtVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::eledPhiAtVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eledPhiAtVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eledPhiAtVtx->push_back( IN::eledPhiAtVtx->at(index) ); 
 }; 

 void ClearOutputeledPhiAtVtx( std::string  prefix ) { 

    std::string my_name = "eledPhiAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eledPhiAtVtx, prefix = " << prefix << std::endl; 
     OUT::eledPhiAtVtx->clear(); 
 }; 

 void CopyeleSigmaIEtaIEtaInToOut( std::string prefix ) { 

    std::string my_name = "eleSigmaIEtaIEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSigmaIEtaIEta = std::vector<float>(*IN::eleSigmaIEtaIEta);
}; 

 void CopyeleSigmaIEtaIEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSigmaIEtaIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSigmaIEtaIEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSigmaIEtaIEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSigmaIEtaIEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSigmaIEtaIEta->push_back( IN::eleSigmaIEtaIEta->at(index) ); 
 }; 

 void ClearOutputeleSigmaIEtaIEta( std::string  prefix ) { 

    std::string my_name = "eleSigmaIEtaIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSigmaIEtaIEta, prefix = " << prefix << std::endl; 
     OUT::eleSigmaIEtaIEta->clear(); 
 }; 

 void CopyeleSigmaIEtaIPhiInToOut( std::string prefix ) { 

    std::string my_name = "eleSigmaIEtaIPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSigmaIEtaIPhi = std::vector<float>(*IN::eleSigmaIEtaIPhi);
}; 

 void CopyeleSigmaIEtaIPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSigmaIEtaIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSigmaIEtaIPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSigmaIEtaIPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSigmaIEtaIPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSigmaIEtaIPhi->push_back( IN::eleSigmaIEtaIPhi->at(index) ); 
 }; 

 void ClearOutputeleSigmaIEtaIPhi( std::string  prefix ) { 

    std::string my_name = "eleSigmaIEtaIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSigmaIEtaIPhi, prefix = " << prefix << std::endl; 
     OUT::eleSigmaIEtaIPhi->clear(); 
 }; 

 void CopyeleSigmaIPhiIPhiInToOut( std::string prefix ) { 

    std::string my_name = "eleSigmaIPhiIPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSigmaIPhiIPhi = std::vector<float>(*IN::eleSigmaIPhiIPhi);
}; 

 void CopyeleSigmaIPhiIPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSigmaIPhiIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSigmaIPhiIPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSigmaIPhiIPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSigmaIPhiIPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSigmaIPhiIPhi->push_back( IN::eleSigmaIPhiIPhi->at(index) ); 
 }; 

 void ClearOutputeleSigmaIPhiIPhi( std::string  prefix ) { 

    std::string my_name = "eleSigmaIPhiIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSigmaIPhiIPhi, prefix = " << prefix << std::endl; 
     OUT::eleSigmaIPhiIPhi->clear(); 
 }; 

 void CopyeleEmaxInToOut( std::string prefix ) { 

    std::string my_name = "eleEmax";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEmax = std::vector<float>(*IN::eleEmax);
}; 

 void CopyeleEmaxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEmax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEmax->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEmax" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEmax" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEmax->push_back( IN::eleEmax->at(index) ); 
 }; 

 void ClearOutputeleEmax( std::string  prefix ) { 

    std::string my_name = "eleEmax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEmax, prefix = " << prefix << std::endl; 
     OUT::eleEmax->clear(); 
 }; 

 void CopyeleE2ndMaxInToOut( std::string prefix ) { 

    std::string my_name = "eleE2ndMax";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE2ndMax = std::vector<float>(*IN::eleE2ndMax);
}; 

 void CopyeleE2ndMaxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE2ndMax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE2ndMax->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE2ndMax" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE2ndMax" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE2ndMax->push_back( IN::eleE2ndMax->at(index) ); 
 }; 

 void ClearOutputeleE2ndMax( std::string  prefix ) { 

    std::string my_name = "eleE2ndMax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE2ndMax, prefix = " << prefix << std::endl; 
     OUT::eleE2ndMax->clear(); 
 }; 

 void CopyeleETopInToOut( std::string prefix ) { 

    std::string my_name = "eleETop";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleETop = std::vector<float>(*IN::eleETop);
}; 

 void CopyeleETopInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleETop";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleETop->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleETop" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleETop" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleETop->push_back( IN::eleETop->at(index) ); 
 }; 

 void ClearOutputeleETop( std::string  prefix ) { 

    std::string my_name = "eleETop";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleETop, prefix = " << prefix << std::endl; 
     OUT::eleETop->clear(); 
 }; 

 void CopyeleEBottomInToOut( std::string prefix ) { 

    std::string my_name = "eleEBottom";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleEBottom = std::vector<float>(*IN::eleEBottom);
}; 

 void CopyeleEBottomInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleEBottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleEBottom->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleEBottom" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleEBottom" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleEBottom->push_back( IN::eleEBottom->at(index) ); 
 }; 

 void ClearOutputeleEBottom( std::string  prefix ) { 

    std::string my_name = "eleEBottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleEBottom, prefix = " << prefix << std::endl; 
     OUT::eleEBottom->clear(); 
 }; 

 void CopyeleELeftInToOut( std::string prefix ) { 

    std::string my_name = "eleELeft";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleELeft = std::vector<float>(*IN::eleELeft);
}; 

 void CopyeleELeftInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleELeft";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleELeft->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleELeft" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleELeft" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleELeft->push_back( IN::eleELeft->at(index) ); 
 }; 

 void ClearOutputeleELeft( std::string  prefix ) { 

    std::string my_name = "eleELeft";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleELeft, prefix = " << prefix << std::endl; 
     OUT::eleELeft->clear(); 
 }; 

 void CopyeleERightInToOut( std::string prefix ) { 

    std::string my_name = "eleERight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleERight = std::vector<float>(*IN::eleERight);
}; 

 void CopyeleERightInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleERight";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleERight->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleERight" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleERight" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleERight->push_back( IN::eleERight->at(index) ); 
 }; 

 void ClearOutputeleERight( std::string  prefix ) { 

    std::string my_name = "eleERight";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleERight, prefix = " << prefix << std::endl; 
     OUT::eleERight->clear(); 
 }; 

 void CopyeleE1x5InToOut( std::string prefix ) { 

    std::string my_name = "eleE1x5";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE1x5 = std::vector<float>(*IN::eleE1x5);
}; 

 void CopyeleE1x5InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE1x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE1x5->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE1x5" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE1x5" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE1x5->push_back( IN::eleE1x5->at(index) ); 
 }; 

 void ClearOutputeleE1x5( std::string  prefix ) { 

    std::string my_name = "eleE1x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE1x5, prefix = " << prefix << std::endl; 
     OUT::eleE1x5->clear(); 
 }; 

 void CopyeleE3x3InToOut( std::string prefix ) { 

    std::string my_name = "eleE3x3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE3x3 = std::vector<float>(*IN::eleE3x3);
}; 

 void CopyeleE3x3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE3x3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE3x3->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE3x3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE3x3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE3x3->push_back( IN::eleE3x3->at(index) ); 
 }; 

 void ClearOutputeleE3x3( std::string  prefix ) { 

    std::string my_name = "eleE3x3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE3x3, prefix = " << prefix << std::endl; 
     OUT::eleE3x3->clear(); 
 }; 

 void CopyeleE5x5InToOut( std::string prefix ) { 

    std::string my_name = "eleE5x5";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE5x5 = std::vector<float>(*IN::eleE5x5);
}; 

 void CopyeleE5x5InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE5x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE5x5->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE5x5" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE5x5" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE5x5->push_back( IN::eleE5x5->at(index) ); 
 }; 

 void ClearOutputeleE5x5( std::string  prefix ) { 

    std::string my_name = "eleE5x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE5x5, prefix = " << prefix << std::endl; 
     OUT::eleE5x5->clear(); 
 }; 

 void CopyeleE2x5MaxInToOut( std::string prefix ) { 

    std::string my_name = "eleE2x5Max";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE2x5Max = std::vector<float>(*IN::eleE2x5Max);
}; 

 void CopyeleE2x5MaxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE2x5Max";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE2x5Max->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE2x5Max" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE2x5Max" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE2x5Max->push_back( IN::eleE2x5Max->at(index) ); 
 }; 

 void ClearOutputeleE2x5Max( std::string  prefix ) { 

    std::string my_name = "eleE2x5Max";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE2x5Max, prefix = " << prefix << std::endl; 
     OUT::eleE2x5Max->clear(); 
 }; 

 void CopyeleE2x5TopInToOut( std::string prefix ) { 

    std::string my_name = "eleE2x5Top";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE2x5Top = std::vector<float>(*IN::eleE2x5Top);
}; 

 void CopyeleE2x5TopInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE2x5Top";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE2x5Top->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE2x5Top" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE2x5Top" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE2x5Top->push_back( IN::eleE2x5Top->at(index) ); 
 }; 

 void ClearOutputeleE2x5Top( std::string  prefix ) { 

    std::string my_name = "eleE2x5Top";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE2x5Top, prefix = " << prefix << std::endl; 
     OUT::eleE2x5Top->clear(); 
 }; 

 void CopyeleE2x5BottomInToOut( std::string prefix ) { 

    std::string my_name = "eleE2x5Bottom";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE2x5Bottom = std::vector<float>(*IN::eleE2x5Bottom);
}; 

 void CopyeleE2x5BottomInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE2x5Bottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE2x5Bottom->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE2x5Bottom" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE2x5Bottom" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE2x5Bottom->push_back( IN::eleE2x5Bottom->at(index) ); 
 }; 

 void ClearOutputeleE2x5Bottom( std::string  prefix ) { 

    std::string my_name = "eleE2x5Bottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE2x5Bottom, prefix = " << prefix << std::endl; 
     OUT::eleE2x5Bottom->clear(); 
 }; 

 void CopyeleE2x5LeftInToOut( std::string prefix ) { 

    std::string my_name = "eleE2x5Left";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE2x5Left = std::vector<float>(*IN::eleE2x5Left);
}; 

 void CopyeleE2x5LeftInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE2x5Left";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE2x5Left->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE2x5Left" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE2x5Left" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE2x5Left->push_back( IN::eleE2x5Left->at(index) ); 
 }; 

 void ClearOutputeleE2x5Left( std::string  prefix ) { 

    std::string my_name = "eleE2x5Left";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE2x5Left, prefix = " << prefix << std::endl; 
     OUT::eleE2x5Left->clear(); 
 }; 

 void CopyeleE2x5RightInToOut( std::string prefix ) { 

    std::string my_name = "eleE2x5Right";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleE2x5Right = std::vector<float>(*IN::eleE2x5Right);
}; 

 void CopyeleE2x5RightInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleE2x5Right";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleE2x5Right->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleE2x5Right" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleE2x5Right" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleE2x5Right->push_back( IN::eleE2x5Right->at(index) ); 
 }; 

 void ClearOutputeleE2x5Right( std::string  prefix ) { 

    std::string my_name = "eleE2x5Right";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleE2x5Right, prefix = " << prefix << std::endl; 
     OUT::eleE2x5Right->clear(); 
 }; 

 void CopyeleSeedEtaInToOut( std::string prefix ) { 

    std::string my_name = "eleSeedEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSeedEta = std::vector<float>(*IN::eleSeedEta);
}; 

 void CopyeleSeedEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSeedEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSeedEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSeedEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSeedEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSeedEta->push_back( IN::eleSeedEta->at(index) ); 
 }; 

 void ClearOutputeleSeedEta( std::string  prefix ) { 

    std::string my_name = "eleSeedEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSeedEta, prefix = " << prefix << std::endl; 
     OUT::eleSeedEta->clear(); 
 }; 

 void CopyeleSeedEInToOut( std::string prefix ) { 

    std::string my_name = "eleSeedE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSeedE = std::vector<float>(*IN::eleSeedE);
}; 

 void CopyeleSeedEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSeedE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSeedE->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSeedE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSeedE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSeedE->push_back( IN::eleSeedE->at(index) ); 
 }; 

 void ClearOutputeleSeedE( std::string  prefix ) { 

    std::string my_name = "eleSeedE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSeedE, prefix = " << prefix << std::endl; 
     OUT::eleSeedE->clear(); 
 }; 

 void CopyeleSeedPhiInToOut( std::string prefix ) { 

    std::string my_name = "eleSeedPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSeedPhi = std::vector<float>(*IN::eleSeedPhi);
}; 

 void CopyeleSeedPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSeedPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSeedPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSeedPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSeedPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSeedPhi->push_back( IN::eleSeedPhi->at(index) ); 
 }; 

 void ClearOutputeleSeedPhi( std::string  prefix ) { 

    std::string my_name = "eleSeedPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSeedPhi, prefix = " << prefix << std::endl; 
     OUT::eleSeedPhi->clear(); 
 }; 

 void CopyeleCrysEtaInToOut( std::string prefix ) { 

    std::string my_name = "eleCrysEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleCrysEta = std::vector<float>(*IN::eleCrysEta);
}; 

 void CopyeleCrysEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleCrysEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleCrysEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleCrysEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleCrysEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleCrysEta->push_back( IN::eleCrysEta->at(index) ); 
 }; 

 void ClearOutputeleCrysEta( std::string  prefix ) { 

    std::string my_name = "eleCrysEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleCrysEta, prefix = " << prefix << std::endl; 
     OUT::eleCrysEta->clear(); 
 }; 

 void CopyeleCrysPhiInToOut( std::string prefix ) { 

    std::string my_name = "eleCrysPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleCrysPhi = std::vector<float>(*IN::eleCrysPhi);
}; 

 void CopyeleCrysPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleCrysPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleCrysPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleCrysPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleCrysPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleCrysPhi->push_back( IN::eleCrysPhi->at(index) ); 
 }; 

 void ClearOutputeleCrysPhi( std::string  prefix ) { 

    std::string my_name = "eleCrysPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleCrysPhi, prefix = " << prefix << std::endl; 
     OUT::eleCrysPhi->clear(); 
 }; 

 void CopyeleCrysIEtaInToOut( std::string prefix ) { 

    std::string my_name = "eleCrysIEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleCrysIEta = std::vector<int>(*IN::eleCrysIEta);
}; 

 void CopyeleCrysIEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleCrysIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleCrysIEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleCrysIEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleCrysIEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleCrysIEta->push_back( IN::eleCrysIEta->at(index) ); 
 }; 

 void ClearOutputeleCrysIEta( std::string  prefix ) { 

    std::string my_name = "eleCrysIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleCrysIEta, prefix = " << prefix << std::endl; 
     OUT::eleCrysIEta->clear(); 
 }; 

 void CopyeleCrysIPhiInToOut( std::string prefix ) { 

    std::string my_name = "eleCrysIPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleCrysIPhi = std::vector<int>(*IN::eleCrysIPhi);
}; 

 void CopyeleCrysIPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleCrysIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleCrysIPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleCrysIPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleCrysIPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleCrysIPhi->push_back( IN::eleCrysIPhi->at(index) ); 
 }; 

 void ClearOutputeleCrysIPhi( std::string  prefix ) { 

    std::string my_name = "eleCrysIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleCrysIPhi, prefix = " << prefix << std::endl; 
     OUT::eleCrysIPhi->clear(); 
 }; 

 void CopyeleRegrEInToOut( std::string prefix ) { 

    std::string my_name = "eleRegrE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleRegrE = std::vector<float>(*IN::eleRegrE);
}; 

 void CopyeleRegrEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleRegrE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleRegrE->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleRegrE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleRegrE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleRegrE->push_back( IN::eleRegrE->at(index) ); 
 }; 

 void ClearOutputeleRegrE( std::string  prefix ) { 

    std::string my_name = "eleRegrE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleRegrE, prefix = " << prefix << std::endl; 
     OUT::eleRegrE->clear(); 
 }; 

 void CopyeleRegrEerrInToOut( std::string prefix ) { 

    std::string my_name = "eleRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleRegrEerr = std::vector<float>(*IN::eleRegrEerr);
}; 

 void CopyeleRegrEerrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleRegrEerr->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleRegrEerr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleRegrEerr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleRegrEerr->push_back( IN::eleRegrEerr->at(index) ); 
 }; 

 void ClearOutputeleRegrEerr( std::string  prefix ) { 

    std::string my_name = "eleRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleRegrEerr, prefix = " << prefix << std::endl; 
     OUT::eleRegrEerr->clear(); 
 }; 

 void CopyelePhoRegrEInToOut( std::string prefix ) { 

    std::string my_name = "elePhoRegrE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePhoRegrE = std::vector<float>(*IN::elePhoRegrE);
}; 

 void CopyelePhoRegrEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePhoRegrE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePhoRegrE->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePhoRegrE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePhoRegrE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePhoRegrE->push_back( IN::elePhoRegrE->at(index) ); 
 }; 

 void ClearOutputelePhoRegrE( std::string  prefix ) { 

    std::string my_name = "elePhoRegrE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePhoRegrE, prefix = " << prefix << std::endl; 
     OUT::elePhoRegrE->clear(); 
 }; 

 void CopyelePhoRegrEerrInToOut( std::string prefix ) { 

    std::string my_name = "elePhoRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePhoRegrEerr = std::vector<float>(*IN::elePhoRegrEerr);
}; 

 void CopyelePhoRegrEerrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePhoRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePhoRegrEerr->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePhoRegrEerr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePhoRegrEerr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePhoRegrEerr->push_back( IN::elePhoRegrEerr->at(index) ); 
 }; 

 void ClearOutputelePhoRegrEerr( std::string  prefix ) { 

    std::string my_name = "elePhoRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePhoRegrEerr, prefix = " << prefix << std::endl; 
     OUT::elePhoRegrEerr->clear(); 
 }; 

 void CopyeleSeedTimeInToOut( std::string prefix ) { 

    std::string my_name = "eleSeedTime";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleSeedTime = std::vector<float>(*IN::eleSeedTime);
}; 

 void CopyeleSeedTimeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleSeedTime";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleSeedTime->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleSeedTime" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleSeedTime" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleSeedTime->push_back( IN::eleSeedTime->at(index) ); 
 }; 

 void ClearOutputeleSeedTime( std::string  prefix ) { 

    std::string my_name = "eleSeedTime";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleSeedTime, prefix = " << prefix << std::endl; 
     OUT::eleSeedTime->clear(); 
 }; 

 void CopyeleRecoFlagInToOut( std::string prefix ) { 

    std::string my_name = "eleRecoFlag";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleRecoFlag = std::vector<int>(*IN::eleRecoFlag);
}; 

 void CopyeleRecoFlagInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleRecoFlag";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleRecoFlag->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleRecoFlag" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleRecoFlag" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleRecoFlag->push_back( IN::eleRecoFlag->at(index) ); 
 }; 

 void ClearOutputeleRecoFlag( std::string  prefix ) { 

    std::string my_name = "eleRecoFlag";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleRecoFlag, prefix = " << prefix << std::endl; 
     OUT::eleRecoFlag->clear(); 
 }; 

 void CopyelePosInToOut( std::string prefix ) { 

    std::string my_name = "elePos";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePos = std::vector<int>(*IN::elePos);
}; 

 void CopyelePosInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePos";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePos->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePos" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePos" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePos->push_back( IN::elePos->at(index) ); 
 }; 

 void ClearOutputelePos( std::string  prefix ) { 

    std::string my_name = "elePos";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePos, prefix = " << prefix << std::endl; 
     OUT::elePos->clear(); 
 }; 

 void CopyeleIsoTrkDR03InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoTrkDR03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoTrkDR03 = std::vector<float>(*IN::eleIsoTrkDR03);
}; 

 void CopyeleIsoTrkDR03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoTrkDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoTrkDR03->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoTrkDR03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoTrkDR03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoTrkDR03->push_back( IN::eleIsoTrkDR03->at(index) ); 
 }; 

 void ClearOutputeleIsoTrkDR03( std::string  prefix ) { 

    std::string my_name = "eleIsoTrkDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoTrkDR03, prefix = " << prefix << std::endl; 
     OUT::eleIsoTrkDR03->clear(); 
 }; 

 void CopyeleIsoEcalDR03InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoEcalDR03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoEcalDR03 = std::vector<float>(*IN::eleIsoEcalDR03);
}; 

 void CopyeleIsoEcalDR03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoEcalDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoEcalDR03->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoEcalDR03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoEcalDR03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoEcalDR03->push_back( IN::eleIsoEcalDR03->at(index) ); 
 }; 

 void ClearOutputeleIsoEcalDR03( std::string  prefix ) { 

    std::string my_name = "eleIsoEcalDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoEcalDR03, prefix = " << prefix << std::endl; 
     OUT::eleIsoEcalDR03->clear(); 
 }; 

 void CopyeleIsoHcalDR03InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoHcalDR03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoHcalDR03 = std::vector<float>(*IN::eleIsoHcalDR03);
}; 

 void CopyeleIsoHcalDR03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoHcalDR03->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoHcalDR03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoHcalDR03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR03->push_back( IN::eleIsoHcalDR03->at(index) ); 
 }; 

 void ClearOutputeleIsoHcalDR03( std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoHcalDR03, prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR03->clear(); 
 }; 

 void CopyeleIsoHcalDR0312InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoHcalDR0312";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoHcalDR0312 = std::vector<float>(*IN::eleIsoHcalDR0312);
}; 

 void CopyeleIsoHcalDR0312InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR0312";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoHcalDR0312->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoHcalDR0312" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoHcalDR0312" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR0312->push_back( IN::eleIsoHcalDR0312->at(index) ); 
 }; 

 void ClearOutputeleIsoHcalDR0312( std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR0312";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoHcalDR0312, prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR0312->clear(); 
 }; 

 void CopyeleIsoTrkDR04InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoTrkDR04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoTrkDR04 = std::vector<float>(*IN::eleIsoTrkDR04);
}; 

 void CopyeleIsoTrkDR04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoTrkDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoTrkDR04->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoTrkDR04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoTrkDR04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoTrkDR04->push_back( IN::eleIsoTrkDR04->at(index) ); 
 }; 

 void ClearOutputeleIsoTrkDR04( std::string  prefix ) { 

    std::string my_name = "eleIsoTrkDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoTrkDR04, prefix = " << prefix << std::endl; 
     OUT::eleIsoTrkDR04->clear(); 
 }; 

 void CopyeleIsoEcalDR04InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoEcalDR04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoEcalDR04 = std::vector<float>(*IN::eleIsoEcalDR04);
}; 

 void CopyeleIsoEcalDR04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoEcalDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoEcalDR04->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoEcalDR04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoEcalDR04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoEcalDR04->push_back( IN::eleIsoEcalDR04->at(index) ); 
 }; 

 void ClearOutputeleIsoEcalDR04( std::string  prefix ) { 

    std::string my_name = "eleIsoEcalDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoEcalDR04, prefix = " << prefix << std::endl; 
     OUT::eleIsoEcalDR04->clear(); 
 }; 

 void CopyeleIsoHcalDR04InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoHcalDR04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoHcalDR04 = std::vector<float>(*IN::eleIsoHcalDR04);
}; 

 void CopyeleIsoHcalDR04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoHcalDR04->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoHcalDR04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoHcalDR04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR04->push_back( IN::eleIsoHcalDR04->at(index) ); 
 }; 

 void ClearOutputeleIsoHcalDR04( std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoHcalDR04, prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR04->clear(); 
 }; 

 void CopyeleIsoHcalDR0412InToOut( std::string prefix ) { 

    std::string my_name = "eleIsoHcalDR0412";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIsoHcalDR0412 = std::vector<float>(*IN::eleIsoHcalDR0412);
}; 

 void CopyeleIsoHcalDR0412InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR0412";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIsoHcalDR0412->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIsoHcalDR0412" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIsoHcalDR0412" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR0412->push_back( IN::eleIsoHcalDR0412->at(index) ); 
 }; 

 void ClearOutputeleIsoHcalDR0412( std::string  prefix ) { 

    std::string my_name = "eleIsoHcalDR0412";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIsoHcalDR0412, prefix = " << prefix << std::endl; 
     OUT::eleIsoHcalDR0412->clear(); 
 }; 

 void CopyeleModIsoTrkInToOut( std::string prefix ) { 

    std::string my_name = "eleModIsoTrk";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleModIsoTrk = std::vector<float>(*IN::eleModIsoTrk);
}; 

 void CopyeleModIsoTrkInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleModIsoTrk";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleModIsoTrk->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleModIsoTrk" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleModIsoTrk" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleModIsoTrk->push_back( IN::eleModIsoTrk->at(index) ); 
 }; 

 void ClearOutputeleModIsoTrk( std::string  prefix ) { 

    std::string my_name = "eleModIsoTrk";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleModIsoTrk, prefix = " << prefix << std::endl; 
     OUT::eleModIsoTrk->clear(); 
 }; 

 void CopyeleModIsoEcalInToOut( std::string prefix ) { 

    std::string my_name = "eleModIsoEcal";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleModIsoEcal = std::vector<float>(*IN::eleModIsoEcal);
}; 

 void CopyeleModIsoEcalInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleModIsoEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleModIsoEcal->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleModIsoEcal" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleModIsoEcal" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleModIsoEcal->push_back( IN::eleModIsoEcal->at(index) ); 
 }; 

 void ClearOutputeleModIsoEcal( std::string  prefix ) { 

    std::string my_name = "eleModIsoEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleModIsoEcal, prefix = " << prefix << std::endl; 
     OUT::eleModIsoEcal->clear(); 
 }; 

 void CopyeleModIsoHcalInToOut( std::string prefix ) { 

    std::string my_name = "eleModIsoHcal";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleModIsoHcal = std::vector<float>(*IN::eleModIsoHcal);
}; 

 void CopyeleModIsoHcalInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleModIsoHcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleModIsoHcal->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleModIsoHcal" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleModIsoHcal" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleModIsoHcal->push_back( IN::eleModIsoHcal->at(index) ); 
 }; 

 void ClearOutputeleModIsoHcal( std::string  prefix ) { 

    std::string my_name = "eleModIsoHcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleModIsoHcal, prefix = " << prefix << std::endl; 
     OUT::eleModIsoHcal->clear(); 
 }; 

 void CopyeleMissHitsInToOut( std::string prefix ) { 

    std::string my_name = "eleMissHits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleMissHits = std::vector<int>(*IN::eleMissHits);
}; 

 void CopyeleMissHitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleMissHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleMissHits->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleMissHits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleMissHits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleMissHits->push_back( IN::eleMissHits->at(index) ); 
 }; 

 void ClearOutputeleMissHits( std::string  prefix ) { 

    std::string my_name = "eleMissHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleMissHits, prefix = " << prefix << std::endl; 
     OUT::eleMissHits->clear(); 
 }; 

 void CopyeleConvDistInToOut( std::string prefix ) { 

    std::string my_name = "eleConvDist";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleConvDist = std::vector<float>(*IN::eleConvDist);
}; 

 void CopyeleConvDistInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleConvDist";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleConvDist->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleConvDist" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleConvDist" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleConvDist->push_back( IN::eleConvDist->at(index) ); 
 }; 

 void ClearOutputeleConvDist( std::string  prefix ) { 

    std::string my_name = "eleConvDist";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleConvDist, prefix = " << prefix << std::endl; 
     OUT::eleConvDist->clear(); 
 }; 

 void CopyeleConvDcotInToOut( std::string prefix ) { 

    std::string my_name = "eleConvDcot";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleConvDcot = std::vector<float>(*IN::eleConvDcot);
}; 

 void CopyeleConvDcotInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleConvDcot";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleConvDcot->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleConvDcot" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleConvDcot" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleConvDcot->push_back( IN::eleConvDcot->at(index) ); 
 }; 

 void ClearOutputeleConvDcot( std::string  prefix ) { 

    std::string my_name = "eleConvDcot";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleConvDcot, prefix = " << prefix << std::endl; 
     OUT::eleConvDcot->clear(); 
 }; 

 void CopyeleConvVtxFitInToOut( std::string prefix ) { 

    std::string my_name = "eleConvVtxFit";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleConvVtxFit = std::vector<int>(*IN::eleConvVtxFit);
}; 

 void CopyeleConvVtxFitInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleConvVtxFit";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleConvVtxFit->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleConvVtxFit" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleConvVtxFit" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleConvVtxFit->push_back( IN::eleConvVtxFit->at(index) ); 
 }; 

 void ClearOutputeleConvVtxFit( std::string  prefix ) { 

    std::string my_name = "eleConvVtxFit";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleConvVtxFit, prefix = " << prefix << std::endl; 
     OUT::eleConvVtxFit->clear(); 
 }; 

 void CopyeleIP3DInToOut( std::string prefix ) { 

    std::string my_name = "eleIP3D";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIP3D = std::vector<float>(*IN::eleIP3D);
}; 

 void CopyeleIP3DInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIP3D";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIP3D->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIP3D" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIP3D" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIP3D->push_back( IN::eleIP3D->at(index) ); 
 }; 

 void ClearOutputeleIP3D( std::string  prefix ) { 

    std::string my_name = "eleIP3D";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIP3D, prefix = " << prefix << std::endl; 
     OUT::eleIP3D->clear(); 
 }; 

 void CopyeleIP3DErrInToOut( std::string prefix ) { 

    std::string my_name = "eleIP3DErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIP3DErr = std::vector<float>(*IN::eleIP3DErr);
}; 

 void CopyeleIP3DErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIP3DErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIP3DErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIP3DErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIP3DErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIP3DErr->push_back( IN::eleIP3DErr->at(index) ); 
 }; 

 void ClearOutputeleIP3DErr( std::string  prefix ) { 

    std::string my_name = "eleIP3DErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIP3DErr, prefix = " << prefix << std::endl; 
     OUT::eleIP3DErr->clear(); 
 }; 

 void CopyeleIDMVANonTrigInToOut( std::string prefix ) { 

    std::string my_name = "eleIDMVANonTrig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIDMVANonTrig = std::vector<float>(*IN::eleIDMVANonTrig);
}; 

 void CopyeleIDMVANonTrigInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIDMVANonTrig";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIDMVANonTrig->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIDMVANonTrig" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIDMVANonTrig" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIDMVANonTrig->push_back( IN::eleIDMVANonTrig->at(index) ); 
 }; 

 void ClearOutputeleIDMVANonTrig( std::string  prefix ) { 

    std::string my_name = "eleIDMVANonTrig";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIDMVANonTrig, prefix = " << prefix << std::endl; 
     OUT::eleIDMVANonTrig->clear(); 
 }; 

 void CopyeleIDMVATrigInToOut( std::string prefix ) { 

    std::string my_name = "eleIDMVATrig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleIDMVATrig = std::vector<float>(*IN::eleIDMVATrig);
}; 

 void CopyeleIDMVATrigInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleIDMVATrig";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleIDMVATrig->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleIDMVATrig" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleIDMVATrig" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleIDMVATrig->push_back( IN::eleIDMVATrig->at(index) ); 
 }; 

 void ClearOutputeleIDMVATrig( std::string  prefix ) { 

    std::string my_name = "eleIDMVATrig";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleIDMVATrig, prefix = " << prefix << std::endl; 
     OUT::eleIDMVATrig->clear(); 
 }; 

 void CopyelePFChIso03InToOut( std::string prefix ) { 

    std::string my_name = "elePFChIso03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePFChIso03 = std::vector<float>(*IN::elePFChIso03);
}; 

 void CopyelePFChIso03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePFChIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePFChIso03->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePFChIso03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePFChIso03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePFChIso03->push_back( IN::elePFChIso03->at(index) ); 
 }; 

 void ClearOutputelePFChIso03( std::string  prefix ) { 

    std::string my_name = "elePFChIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePFChIso03, prefix = " << prefix << std::endl; 
     OUT::elePFChIso03->clear(); 
 }; 

 void CopyelePFPhoIso03InToOut( std::string prefix ) { 

    std::string my_name = "elePFPhoIso03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePFPhoIso03 = std::vector<float>(*IN::elePFPhoIso03);
}; 

 void CopyelePFPhoIso03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePFPhoIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePFPhoIso03->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePFPhoIso03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePFPhoIso03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePFPhoIso03->push_back( IN::elePFPhoIso03->at(index) ); 
 }; 

 void ClearOutputelePFPhoIso03( std::string  prefix ) { 

    std::string my_name = "elePFPhoIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePFPhoIso03, prefix = " << prefix << std::endl; 
     OUT::elePFPhoIso03->clear(); 
 }; 

 void CopyelePFNeuIso03InToOut( std::string prefix ) { 

    std::string my_name = "elePFNeuIso03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePFNeuIso03 = std::vector<float>(*IN::elePFNeuIso03);
}; 

 void CopyelePFNeuIso03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePFNeuIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePFNeuIso03->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePFNeuIso03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePFNeuIso03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePFNeuIso03->push_back( IN::elePFNeuIso03->at(index) ); 
 }; 

 void ClearOutputelePFNeuIso03( std::string  prefix ) { 

    std::string my_name = "elePFNeuIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePFNeuIso03, prefix = " << prefix << std::endl; 
     OUT::elePFNeuIso03->clear(); 
 }; 

 void CopyelePFChIso04InToOut( std::string prefix ) { 

    std::string my_name = "elePFChIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePFChIso04 = std::vector<float>(*IN::elePFChIso04);
}; 

 void CopyelePFChIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePFChIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePFChIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePFChIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePFChIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePFChIso04->push_back( IN::elePFChIso04->at(index) ); 
 }; 

 void ClearOutputelePFChIso04( std::string  prefix ) { 

    std::string my_name = "elePFChIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePFChIso04, prefix = " << prefix << std::endl; 
     OUT::elePFChIso04->clear(); 
 }; 

 void CopyelePFPhoIso04InToOut( std::string prefix ) { 

    std::string my_name = "elePFPhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePFPhoIso04 = std::vector<float>(*IN::elePFPhoIso04);
}; 

 void CopyelePFPhoIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePFPhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePFPhoIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePFPhoIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePFPhoIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePFPhoIso04->push_back( IN::elePFPhoIso04->at(index) ); 
 }; 

 void ClearOutputelePFPhoIso04( std::string  prefix ) { 

    std::string my_name = "elePFPhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePFPhoIso04, prefix = " << prefix << std::endl; 
     OUT::elePFPhoIso04->clear(); 
 }; 

 void CopyelePFNeuIso04InToOut( std::string prefix ) { 

    std::string my_name = "elePFNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::elePFNeuIso04 = std::vector<float>(*IN::elePFNeuIso04);
}; 

 void CopyelePFNeuIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "elePFNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::elePFNeuIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::elePFNeuIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible elePFNeuIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::elePFNeuIso04->push_back( IN::elePFNeuIso04->at(index) ); 
 }; 

 void ClearOutputelePFNeuIso04( std::string  prefix ) { 

    std::string my_name = "elePFNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible elePFNeuIso04, prefix = " << prefix << std::endl; 
     OUT::elePFNeuIso04->clear(); 
 }; 

 void CopyeleESEffSigmaRR_xInToOut( std::string prefix ) { 

    std::string my_name = "eleESEffSigmaRR_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleESEffSigmaRR_x = std::vector<float>(*IN::eleESEffSigmaRR_x);
}; 

 void CopyeleESEffSigmaRR_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleESEffSigmaRR_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleESEffSigmaRR_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleESEffSigmaRR_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleESEffSigmaRR_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleESEffSigmaRR_x->push_back( IN::eleESEffSigmaRR_x->at(index) ); 
 }; 

 void ClearOutputeleESEffSigmaRR_x( std::string  prefix ) { 

    std::string my_name = "eleESEffSigmaRR_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleESEffSigmaRR_x, prefix = " << prefix << std::endl; 
     OUT::eleESEffSigmaRR_x->clear(); 
 }; 

 void CopyeleESEffSigmaRR_yInToOut( std::string prefix ) { 

    std::string my_name = "eleESEffSigmaRR_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleESEffSigmaRR_y = std::vector<float>(*IN::eleESEffSigmaRR_y);
}; 

 void CopyeleESEffSigmaRR_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleESEffSigmaRR_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleESEffSigmaRR_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleESEffSigmaRR_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleESEffSigmaRR_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleESEffSigmaRR_y->push_back( IN::eleESEffSigmaRR_y->at(index) ); 
 }; 

 void ClearOutputeleESEffSigmaRR_y( std::string  prefix ) { 

    std::string my_name = "eleESEffSigmaRR_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleESEffSigmaRR_y, prefix = " << prefix << std::endl; 
     OUT::eleESEffSigmaRR_y->clear(); 
 }; 

 void CopyeleESEffSigmaRR_zInToOut( std::string prefix ) { 

    std::string my_name = "eleESEffSigmaRR_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::eleESEffSigmaRR_z = std::vector<float>(*IN::eleESEffSigmaRR_z);
}; 

 void CopyeleESEffSigmaRR_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "eleESEffSigmaRR_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::eleESEffSigmaRR_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::eleESEffSigmaRR_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible eleESEffSigmaRR_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::eleESEffSigmaRR_z->push_back( IN::eleESEffSigmaRR_z->at(index) ); 
 }; 

 void ClearOutputeleESEffSigmaRR_z( std::string  prefix ) { 

    std::string my_name = "eleESEffSigmaRR_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible eleESEffSigmaRR_z, prefix = " << prefix << std::endl; 
     OUT::eleESEffSigmaRR_z->clear(); 
 }; 

 void CopynPhoInToOut( std::string prefix ) { 

    std::string my_name = "nPho";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nPho = IN::nPho;
}; 

 void CopyphoTrgInToOut( std::string prefix ) { 

    std::string my_name = "phoTrg";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoTrg = std::vector<unsigned long>(*IN::phoTrg);
}; 

 void CopyphoTrgInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoTrg->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoTrg" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoTrg" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoTrg->push_back( IN::phoTrg->at(index) ); 
 }; 

 void ClearOutputphoTrg( std::string  prefix ) { 

    std::string my_name = "phoTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoTrg, prefix = " << prefix << std::endl; 
     OUT::phoTrg->clear(); 
 }; 

 void CopyphoTrgFilterInToOut( std::string prefix ) { 

    std::string my_name = "phoTrgFilter";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoTrgFilter = std::vector<unsigned long>(*IN::phoTrgFilter);
}; 

 void CopyphoTrgFilterInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoTrgFilter";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoTrgFilter->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoTrgFilter" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoTrgFilter" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoTrgFilter->push_back( IN::phoTrgFilter->at(index) ); 
 }; 

 void ClearOutputphoTrgFilter( std::string  prefix ) { 

    std::string my_name = "phoTrgFilter";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoTrgFilter, prefix = " << prefix << std::endl; 
     OUT::phoTrgFilter->clear(); 
 }; 

 void CopyphoIsPhotonInToOut( std::string prefix ) { 

    std::string my_name = "phoIsPhoton";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoIsPhoton = std::vector<bool>(*IN::phoIsPhoton);
}; 

 void CopyphoIsPhotonInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoIsPhoton";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoIsPhoton->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoIsPhoton" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoIsPhoton" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoIsPhoton->push_back( IN::phoIsPhoton->at(index) ); 
 }; 

 void ClearOutputphoIsPhoton( std::string  prefix ) { 

    std::string my_name = "phoIsPhoton";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoIsPhoton, prefix = " << prefix << std::endl; 
     OUT::phoIsPhoton->clear(); 
 }; 

 void CopyphoSCPos_xInToOut( std::string prefix ) { 

    std::string my_name = "phoSCPos_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCPos_x = std::vector<float>(*IN::phoSCPos_x);
}; 

 void CopyphoSCPos_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCPos_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCPos_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCPos_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCPos_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCPos_x->push_back( IN::phoSCPos_x->at(index) ); 
 }; 

 void ClearOutputphoSCPos_x( std::string  prefix ) { 

    std::string my_name = "phoSCPos_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCPos_x, prefix = " << prefix << std::endl; 
     OUT::phoSCPos_x->clear(); 
 }; 

 void CopyphoSCPos_yInToOut( std::string prefix ) { 

    std::string my_name = "phoSCPos_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCPos_y = std::vector<float>(*IN::phoSCPos_y);
}; 

 void CopyphoSCPos_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCPos_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCPos_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCPos_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCPos_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCPos_y->push_back( IN::phoSCPos_y->at(index) ); 
 }; 

 void ClearOutputphoSCPos_y( std::string  prefix ) { 

    std::string my_name = "phoSCPos_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCPos_y, prefix = " << prefix << std::endl; 
     OUT::phoSCPos_y->clear(); 
 }; 

 void CopyphoSCPos_zInToOut( std::string prefix ) { 

    std::string my_name = "phoSCPos_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCPos_z = std::vector<float>(*IN::phoSCPos_z);
}; 

 void CopyphoSCPos_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCPos_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCPos_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCPos_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCPos_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCPos_z->push_back( IN::phoSCPos_z->at(index) ); 
 }; 

 void ClearOutputphoSCPos_z( std::string  prefix ) { 

    std::string my_name = "phoSCPos_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCPos_z, prefix = " << prefix << std::endl; 
     OUT::phoSCPos_z->clear(); 
 }; 

 void CopyphoCaloPos_xInToOut( std::string prefix ) { 

    std::string my_name = "phoCaloPos_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCaloPos_x = std::vector<float>(*IN::phoCaloPos_x);
}; 

 void CopyphoCaloPos_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCaloPos_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCaloPos_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCaloPos_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCaloPos_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCaloPos_x->push_back( IN::phoCaloPos_x->at(index) ); 
 }; 

 void ClearOutputphoCaloPos_x( std::string  prefix ) { 

    std::string my_name = "phoCaloPos_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCaloPos_x, prefix = " << prefix << std::endl; 
     OUT::phoCaloPos_x->clear(); 
 }; 

 void CopyphoCaloPos_yInToOut( std::string prefix ) { 

    std::string my_name = "phoCaloPos_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCaloPos_y = std::vector<float>(*IN::phoCaloPos_y);
}; 

 void CopyphoCaloPos_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCaloPos_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCaloPos_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCaloPos_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCaloPos_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCaloPos_y->push_back( IN::phoCaloPos_y->at(index) ); 
 }; 

 void ClearOutputphoCaloPos_y( std::string  prefix ) { 

    std::string my_name = "phoCaloPos_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCaloPos_y, prefix = " << prefix << std::endl; 
     OUT::phoCaloPos_y->clear(); 
 }; 

 void CopyphoCaloPos_zInToOut( std::string prefix ) { 

    std::string my_name = "phoCaloPos_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCaloPos_z = std::vector<float>(*IN::phoCaloPos_z);
}; 

 void CopyphoCaloPos_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCaloPos_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCaloPos_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCaloPos_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCaloPos_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCaloPos_z->push_back( IN::phoCaloPos_z->at(index) ); 
 }; 

 void ClearOutputphoCaloPos_z( std::string  prefix ) { 

    std::string my_name = "phoCaloPos_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCaloPos_z, prefix = " << prefix << std::endl; 
     OUT::phoCaloPos_z->clear(); 
 }; 

 void CopyphoEInToOut( std::string prefix ) { 

    std::string my_name = "phoE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE = std::vector<float>(*IN::phoE);
}; 

 void CopyphoEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE->push_back( IN::phoE->at(index) ); 
 }; 

 void ClearOutputphoE( std::string  prefix ) { 

    std::string my_name = "phoE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE, prefix = " << prefix << std::endl; 
     OUT::phoE->clear(); 
 }; 

 void CopyphoEtInToOut( std::string prefix ) { 

    std::string my_name = "phoEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEt = std::vector<float>(*IN::phoEt);
}; 

 void CopyphoEtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEt->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEt->push_back( IN::phoEt->at(index) ); 
 }; 

 void ClearOutputphoEt( std::string  prefix ) { 

    std::string my_name = "phoEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEt, prefix = " << prefix << std::endl; 
     OUT::phoEt->clear(); 
 }; 

 void CopyphoEtaInToOut( std::string prefix ) { 

    std::string my_name = "phoEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEta = std::vector<float>(*IN::phoEta);
}; 

 void CopyphoEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEta->push_back( IN::phoEta->at(index) ); 
 }; 

 void ClearOutputphoEta( std::string  prefix ) { 

    std::string my_name = "phoEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEta, prefix = " << prefix << std::endl; 
     OUT::phoEta->clear(); 
 }; 

 void CopyphoVtx_xInToOut( std::string prefix ) { 

    std::string my_name = "phoVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoVtx_x = std::vector<float>(*IN::phoVtx_x);
}; 

 void CopyphoVtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoVtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoVtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoVtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoVtx_x->push_back( IN::phoVtx_x->at(index) ); 
 }; 

 void ClearOutputphoVtx_x( std::string  prefix ) { 

    std::string my_name = "phoVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoVtx_x, prefix = " << prefix << std::endl; 
     OUT::phoVtx_x->clear(); 
 }; 

 void CopyphoVtx_yInToOut( std::string prefix ) { 

    std::string my_name = "phoVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoVtx_y = std::vector<float>(*IN::phoVtx_y);
}; 

 void CopyphoVtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoVtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoVtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoVtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoVtx_y->push_back( IN::phoVtx_y->at(index) ); 
 }; 

 void ClearOutputphoVtx_y( std::string  prefix ) { 

    std::string my_name = "phoVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoVtx_y, prefix = " << prefix << std::endl; 
     OUT::phoVtx_y->clear(); 
 }; 

 void CopyphoVtx_zInToOut( std::string prefix ) { 

    std::string my_name = "phoVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoVtx_z = std::vector<float>(*IN::phoVtx_z);
}; 

 void CopyphoVtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoVtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoVtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoVtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoVtx_z->push_back( IN::phoVtx_z->at(index) ); 
 }; 

 void ClearOutputphoVtx_z( std::string  prefix ) { 

    std::string my_name = "phoVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoVtx_z, prefix = " << prefix << std::endl; 
     OUT::phoVtx_z->clear(); 
 }; 

 void CopyphoPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPhi = std::vector<float>(*IN::phoPhi);
}; 

 void CopyphoPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPhi->push_back( IN::phoPhi->at(index) ); 
 }; 

 void ClearOutputphoPhi( std::string  prefix ) { 

    std::string my_name = "phoPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPhi, prefix = " << prefix << std::endl; 
     OUT::phoPhi->clear(); 
 }; 

 void CopyphoEtVtxInToOut( std::string prefix ) { 

    std::string my_name = "phoEtVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEtVtx = std::vector<std::vector<float> >(*IN::phoEtVtx);
}; 

 void CopyphoEtVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEtVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEtVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEtVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEtVtx->push_back( IN::phoEtVtx->at(index) ); 
 }; 

 void ClearOutputphoEtVtx( std::string  prefix ) { 

    std::string my_name = "phoEtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEtVtx, prefix = " << prefix << std::endl; 
     OUT::phoEtVtx->clear(); 
 }; 

 void CopyphoEtaVtxInToOut( std::string prefix ) { 

    std::string my_name = "phoEtaVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEtaVtx = std::vector<std::vector<float> >(*IN::phoEtaVtx);
}; 

 void CopyphoEtaVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEtaVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEtaVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEtaVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEtaVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEtaVtx->push_back( IN::phoEtaVtx->at(index) ); 
 }; 

 void ClearOutputphoEtaVtx( std::string  prefix ) { 

    std::string my_name = "phoEtaVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEtaVtx, prefix = " << prefix << std::endl; 
     OUT::phoEtaVtx->clear(); 
 }; 

 void CopyphoPhiVtxInToOut( std::string prefix ) { 

    std::string my_name = "phoPhiVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPhiVtx = std::vector<std::vector<float> >(*IN::phoPhiVtx);
}; 

 void CopyphoPhiVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPhiVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPhiVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPhiVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPhiVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPhiVtx->push_back( IN::phoPhiVtx->at(index) ); 
 }; 

 void ClearOutputphoPhiVtx( std::string  prefix ) { 

    std::string my_name = "phoPhiVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPhiVtx, prefix = " << prefix << std::endl; 
     OUT::phoPhiVtx->clear(); 
 }; 

 void CopyphoR9InToOut( std::string prefix ) { 

    std::string my_name = "phoR9";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoR9 = std::vector<float>(*IN::phoR9);
}; 

 void CopyphoR9InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoR9";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoR9->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoR9" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoR9" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoR9->push_back( IN::phoR9->at(index) ); 
 }; 

 void ClearOutputphoR9( std::string  prefix ) { 

    std::string my_name = "phoR9";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoR9, prefix = " << prefix << std::endl; 
     OUT::phoR9->clear(); 
 }; 

 void CopyphoNClusInToOut( std::string prefix ) { 

    std::string my_name = "phoNClus";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoNClus = std::vector<int>(*IN::phoNClus);
}; 

 void CopyphoNClusInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoNClus";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoNClus->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoNClus" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoNClus" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoNClus->push_back( IN::phoNClus->at(index) ); 
 }; 

 void ClearOutputphoNClus( std::string  prefix ) { 

    std::string my_name = "phoNClus";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoNClus, prefix = " << prefix << std::endl; 
     OUT::phoNClus->clear(); 
 }; 

 void CopyphoTrkIsoHollowDR03InToOut( std::string prefix ) { 

    std::string my_name = "phoTrkIsoHollowDR03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoTrkIsoHollowDR03 = std::vector<float>(*IN::phoTrkIsoHollowDR03);
}; 

 void CopyphoTrkIsoHollowDR03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoTrkIsoHollowDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoTrkIsoHollowDR03->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoTrkIsoHollowDR03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoTrkIsoHollowDR03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoTrkIsoHollowDR03->push_back( IN::phoTrkIsoHollowDR03->at(index) ); 
 }; 

 void ClearOutputphoTrkIsoHollowDR03( std::string  prefix ) { 

    std::string my_name = "phoTrkIsoHollowDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoTrkIsoHollowDR03, prefix = " << prefix << std::endl; 
     OUT::phoTrkIsoHollowDR03->clear(); 
 }; 

 void CopyphoEcalIsoDR03InToOut( std::string prefix ) { 

    std::string my_name = "phoEcalIsoDR03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEcalIsoDR03 = std::vector<float>(*IN::phoEcalIsoDR03);
}; 

 void CopyphoEcalIsoDR03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEcalIsoDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEcalIsoDR03->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEcalIsoDR03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEcalIsoDR03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEcalIsoDR03->push_back( IN::phoEcalIsoDR03->at(index) ); 
 }; 

 void ClearOutputphoEcalIsoDR03( std::string  prefix ) { 

    std::string my_name = "phoEcalIsoDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEcalIsoDR03, prefix = " << prefix << std::endl; 
     OUT::phoEcalIsoDR03->clear(); 
 }; 

 void CopyphoHcalIsoDR03InToOut( std::string prefix ) { 

    std::string my_name = "phoHcalIsoDR03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoHcalIsoDR03 = std::vector<float>(*IN::phoHcalIsoDR03);
}; 

 void CopyphoHcalIsoDR03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoHcalIsoDR03->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoHcalIsoDR03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoHcalIsoDR03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR03->push_back( IN::phoHcalIsoDR03->at(index) ); 
 }; 

 void ClearOutputphoHcalIsoDR03( std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoHcalIsoDR03, prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR03->clear(); 
 }; 

 void CopyphoHcalIsoDR0312InToOut( std::string prefix ) { 

    std::string my_name = "phoHcalIsoDR0312";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoHcalIsoDR0312 = std::vector<float>(*IN::phoHcalIsoDR0312);
}; 

 void CopyphoHcalIsoDR0312InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR0312";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoHcalIsoDR0312->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoHcalIsoDR0312" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoHcalIsoDR0312" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR0312->push_back( IN::phoHcalIsoDR0312->at(index) ); 
 }; 

 void ClearOutputphoHcalIsoDR0312( std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR0312";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoHcalIsoDR0312, prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR0312->clear(); 
 }; 

 void CopyphoTrkIsoHollowDR04InToOut( std::string prefix ) { 

    std::string my_name = "phoTrkIsoHollowDR04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoTrkIsoHollowDR04 = std::vector<float>(*IN::phoTrkIsoHollowDR04);
}; 

 void CopyphoTrkIsoHollowDR04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoTrkIsoHollowDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoTrkIsoHollowDR04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoTrkIsoHollowDR04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoTrkIsoHollowDR04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoTrkIsoHollowDR04->push_back( IN::phoTrkIsoHollowDR04->at(index) ); 
 }; 

 void ClearOutputphoTrkIsoHollowDR04( std::string  prefix ) { 

    std::string my_name = "phoTrkIsoHollowDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoTrkIsoHollowDR04, prefix = " << prefix << std::endl; 
     OUT::phoTrkIsoHollowDR04->clear(); 
 }; 

 void CopyphoCiCdRtoTrkInToOut( std::string prefix ) { 

    std::string my_name = "phoCiCdRtoTrk";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCiCdRtoTrk = std::vector<float>(*IN::phoCiCdRtoTrk);
}; 

 void CopyphoCiCdRtoTrkInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCiCdRtoTrk";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCiCdRtoTrk->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCiCdRtoTrk" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCiCdRtoTrk" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCiCdRtoTrk->push_back( IN::phoCiCdRtoTrk->at(index) ); 
 }; 

 void ClearOutputphoCiCdRtoTrk( std::string  prefix ) { 

    std::string my_name = "phoCiCdRtoTrk";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCiCdRtoTrk, prefix = " << prefix << std::endl; 
     OUT::phoCiCdRtoTrk->clear(); 
 }; 

 void CopyphoEcalIsoDR04InToOut( std::string prefix ) { 

    std::string my_name = "phoEcalIsoDR04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEcalIsoDR04 = std::vector<float>(*IN::phoEcalIsoDR04);
}; 

 void CopyphoEcalIsoDR04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEcalIsoDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEcalIsoDR04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEcalIsoDR04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEcalIsoDR04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEcalIsoDR04->push_back( IN::phoEcalIsoDR04->at(index) ); 
 }; 

 void ClearOutputphoEcalIsoDR04( std::string  prefix ) { 

    std::string my_name = "phoEcalIsoDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEcalIsoDR04, prefix = " << prefix << std::endl; 
     OUT::phoEcalIsoDR04->clear(); 
 }; 

 void CopyphoHcalIsoDR04InToOut( std::string prefix ) { 

    std::string my_name = "phoHcalIsoDR04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoHcalIsoDR04 = std::vector<float>(*IN::phoHcalIsoDR04);
}; 

 void CopyphoHcalIsoDR04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoHcalIsoDR04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoHcalIsoDR04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoHcalIsoDR04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR04->push_back( IN::phoHcalIsoDR04->at(index) ); 
 }; 

 void ClearOutputphoHcalIsoDR04( std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoHcalIsoDR04, prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR04->clear(); 
 }; 

 void CopyphoHcalIsoDR0412InToOut( std::string prefix ) { 

    std::string my_name = "phoHcalIsoDR0412";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoHcalIsoDR0412 = std::vector<float>(*IN::phoHcalIsoDR0412);
}; 

 void CopyphoHcalIsoDR0412InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR0412";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoHcalIsoDR0412->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoHcalIsoDR0412" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoHcalIsoDR0412" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR0412->push_back( IN::phoHcalIsoDR0412->at(index) ); 
 }; 

 void ClearOutputphoHcalIsoDR0412( std::string  prefix ) { 

    std::string my_name = "phoHcalIsoDR0412";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoHcalIsoDR0412, prefix = " << prefix << std::endl; 
     OUT::phoHcalIsoDR0412->clear(); 
 }; 

 void CopyphoHoverEInToOut( std::string prefix ) { 

    std::string my_name = "phoHoverE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoHoverE = std::vector<float>(*IN::phoHoverE);
}; 

 void CopyphoHoverEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoHoverE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoHoverE->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoHoverE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoHoverE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoHoverE->push_back( IN::phoHoverE->at(index) ); 
 }; 

 void ClearOutputphoHoverE( std::string  prefix ) { 

    std::string my_name = "phoHoverE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoHoverE, prefix = " << prefix << std::endl; 
     OUT::phoHoverE->clear(); 
 }; 

 void CopyphoHoverE12InToOut( std::string prefix ) { 

    std::string my_name = "phoHoverE12";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoHoverE12 = std::vector<float>(*IN::phoHoverE12);
}; 

 void CopyphoHoverE12InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoHoverE12";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoHoverE12->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoHoverE12" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoHoverE12" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoHoverE12->push_back( IN::phoHoverE12->at(index) ); 
 }; 

 void ClearOutputphoHoverE12( std::string  prefix ) { 

    std::string my_name = "phoHoverE12";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoHoverE12, prefix = " << prefix << std::endl; 
     OUT::phoHoverE12->clear(); 
 }; 

 void CopyphoEleVetoInToOut( std::string prefix ) { 

    std::string my_name = "phoEleVeto";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEleVeto = std::vector<int>(*IN::phoEleVeto);
}; 

 void CopyphoEleVetoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEleVeto";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEleVeto->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEleVeto" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEleVeto" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEleVeto->push_back( IN::phoEleVeto->at(index) ); 
 }; 

 void ClearOutputphoEleVeto( std::string  prefix ) { 

    std::string my_name = "phoEleVeto";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEleVeto, prefix = " << prefix << std::endl; 
     OUT::phoEleVeto->clear(); 
 }; 

 void CopyphoSigmaIEtaIEtaInToOut( std::string prefix ) { 

    std::string my_name = "phoSigmaIEtaIEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSigmaIEtaIEta = std::vector<float>(*IN::phoSigmaIEtaIEta);
}; 

 void CopyphoSigmaIEtaIEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSigmaIEtaIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSigmaIEtaIEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSigmaIEtaIEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSigmaIEtaIEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSigmaIEtaIEta->push_back( IN::phoSigmaIEtaIEta->at(index) ); 
 }; 

 void ClearOutputphoSigmaIEtaIEta( std::string  prefix ) { 

    std::string my_name = "phoSigmaIEtaIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSigmaIEtaIEta, prefix = " << prefix << std::endl; 
     OUT::phoSigmaIEtaIEta->clear(); 
 }; 

 void CopyphoSigmaIEtaIPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoSigmaIEtaIPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSigmaIEtaIPhi = std::vector<float>(*IN::phoSigmaIEtaIPhi);
}; 

 void CopyphoSigmaIEtaIPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSigmaIEtaIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSigmaIEtaIPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSigmaIEtaIPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSigmaIEtaIPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSigmaIEtaIPhi->push_back( IN::phoSigmaIEtaIPhi->at(index) ); 
 }; 

 void ClearOutputphoSigmaIEtaIPhi( std::string  prefix ) { 

    std::string my_name = "phoSigmaIEtaIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSigmaIEtaIPhi, prefix = " << prefix << std::endl; 
     OUT::phoSigmaIEtaIPhi->clear(); 
 }; 

 void CopyphoSigmaIPhiIPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoSigmaIPhiIPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSigmaIPhiIPhi = std::vector<float>(*IN::phoSigmaIPhiIPhi);
}; 

 void CopyphoSigmaIPhiIPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSigmaIPhiIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSigmaIPhiIPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSigmaIPhiIPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSigmaIPhiIPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSigmaIPhiIPhi->push_back( IN::phoSigmaIPhiIPhi->at(index) ); 
 }; 

 void ClearOutputphoSigmaIPhiIPhi( std::string  prefix ) { 

    std::string my_name = "phoSigmaIPhiIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSigmaIPhiIPhi, prefix = " << prefix << std::endl; 
     OUT::phoSigmaIPhiIPhi->clear(); 
 }; 

 void CopyphoCiCPF4phopfIso03InToOut( std::string prefix ) { 

    std::string my_name = "phoCiCPF4phopfIso03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCiCPF4phopfIso03 = std::vector<float>(*IN::phoCiCPF4phopfIso03);
}; 

 void CopyphoCiCPF4phopfIso03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCiCPF4phopfIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCiCPF4phopfIso03->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCiCPF4phopfIso03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCiCPF4phopfIso03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCiCPF4phopfIso03->push_back( IN::phoCiCPF4phopfIso03->at(index) ); 
 }; 

 void ClearOutputphoCiCPF4phopfIso03( std::string  prefix ) { 

    std::string my_name = "phoCiCPF4phopfIso03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCiCPF4phopfIso03, prefix = " << prefix << std::endl; 
     OUT::phoCiCPF4phopfIso03->clear(); 
 }; 

 void CopyphoCiCPF4phopfIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoCiCPF4phopfIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCiCPF4phopfIso04 = std::vector<float>(*IN::phoCiCPF4phopfIso04);
}; 

 void CopyphoCiCPF4phopfIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCiCPF4phopfIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCiCPF4phopfIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCiCPF4phopfIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCiCPF4phopfIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCiCPF4phopfIso04->push_back( IN::phoCiCPF4phopfIso04->at(index) ); 
 }; 

 void ClearOutputphoCiCPF4phopfIso04( std::string  prefix ) { 

    std::string my_name = "phoCiCPF4phopfIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCiCPF4phopfIso04, prefix = " << prefix << std::endl; 
     OUT::phoCiCPF4phopfIso04->clear(); 
 }; 

 void CopyphoEmaxInToOut( std::string prefix ) { 

    std::string my_name = "phoEmax";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEmax = std::vector<float>(*IN::phoEmax);
}; 

 void CopyphoEmaxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEmax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEmax->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEmax" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEmax" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEmax->push_back( IN::phoEmax->at(index) ); 
 }; 

 void ClearOutputphoEmax( std::string  prefix ) { 

    std::string my_name = "phoEmax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEmax, prefix = " << prefix << std::endl; 
     OUT::phoEmax->clear(); 
 }; 

 void CopyphoETopInToOut( std::string prefix ) { 

    std::string my_name = "phoETop";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoETop = std::vector<float>(*IN::phoETop);
}; 

 void CopyphoETopInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoETop";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoETop->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoETop" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoETop" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoETop->push_back( IN::phoETop->at(index) ); 
 }; 

 void ClearOutputphoETop( std::string  prefix ) { 

    std::string my_name = "phoETop";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoETop, prefix = " << prefix << std::endl; 
     OUT::phoETop->clear(); 
 }; 

 void CopyphoEBottomInToOut( std::string prefix ) { 

    std::string my_name = "phoEBottom";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoEBottom = std::vector<float>(*IN::phoEBottom);
}; 

 void CopyphoEBottomInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoEBottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoEBottom->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoEBottom" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoEBottom" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoEBottom->push_back( IN::phoEBottom->at(index) ); 
 }; 

 void ClearOutputphoEBottom( std::string  prefix ) { 

    std::string my_name = "phoEBottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoEBottom, prefix = " << prefix << std::endl; 
     OUT::phoEBottom->clear(); 
 }; 

 void CopyphoELeftInToOut( std::string prefix ) { 

    std::string my_name = "phoELeft";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoELeft = std::vector<float>(*IN::phoELeft);
}; 

 void CopyphoELeftInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoELeft";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoELeft->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoELeft" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoELeft" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoELeft->push_back( IN::phoELeft->at(index) ); 
 }; 

 void ClearOutputphoELeft( std::string  prefix ) { 

    std::string my_name = "phoELeft";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoELeft, prefix = " << prefix << std::endl; 
     OUT::phoELeft->clear(); 
 }; 

 void CopyphoERightInToOut( std::string prefix ) { 

    std::string my_name = "phoERight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoERight = std::vector<float>(*IN::phoERight);
}; 

 void CopyphoERightInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoERight";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoERight->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoERight" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoERight" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoERight->push_back( IN::phoERight->at(index) ); 
 }; 

 void ClearOutputphoERight( std::string  prefix ) { 

    std::string my_name = "phoERight";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoERight, prefix = " << prefix << std::endl; 
     OUT::phoERight->clear(); 
 }; 

 void CopyphoE2ndMaxInToOut( std::string prefix ) { 

    std::string my_name = "phoE2ndMax";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2ndMax = std::vector<float>(*IN::phoE2ndMax);
}; 

 void CopyphoE2ndMaxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2ndMax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2ndMax->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2ndMax" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2ndMax" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2ndMax->push_back( IN::phoE2ndMax->at(index) ); 
 }; 

 void ClearOutputphoE2ndMax( std::string  prefix ) { 

    std::string my_name = "phoE2ndMax";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2ndMax, prefix = " << prefix << std::endl; 
     OUT::phoE2ndMax->clear(); 
 }; 

 void CopyphoE3x3InToOut( std::string prefix ) { 

    std::string my_name = "phoE3x3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE3x3 = std::vector<float>(*IN::phoE3x3);
}; 

 void CopyphoE3x3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE3x3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE3x3->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE3x3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE3x3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE3x3->push_back( IN::phoE3x3->at(index) ); 
 }; 

 void ClearOutputphoE3x3( std::string  prefix ) { 

    std::string my_name = "phoE3x3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE3x3, prefix = " << prefix << std::endl; 
     OUT::phoE3x3->clear(); 
 }; 

 void CopyphoE3x1InToOut( std::string prefix ) { 

    std::string my_name = "phoE3x1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE3x1 = std::vector<float>(*IN::phoE3x1);
}; 

 void CopyphoE3x1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE3x1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE3x1->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE3x1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE3x1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE3x1->push_back( IN::phoE3x1->at(index) ); 
 }; 

 void ClearOutputphoE3x1( std::string  prefix ) { 

    std::string my_name = "phoE3x1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE3x1, prefix = " << prefix << std::endl; 
     OUT::phoE3x1->clear(); 
 }; 

 void CopyphoE1x3InToOut( std::string prefix ) { 

    std::string my_name = "phoE1x3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE1x3 = std::vector<float>(*IN::phoE1x3);
}; 

 void CopyphoE1x3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE1x3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE1x3->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE1x3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE1x3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE1x3->push_back( IN::phoE1x3->at(index) ); 
 }; 

 void ClearOutputphoE1x3( std::string  prefix ) { 

    std::string my_name = "phoE1x3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE1x3, prefix = " << prefix << std::endl; 
     OUT::phoE1x3->clear(); 
 }; 

 void CopyphoE5x5InToOut( std::string prefix ) { 

    std::string my_name = "phoE5x5";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE5x5 = std::vector<float>(*IN::phoE5x5);
}; 

 void CopyphoE5x5InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE5x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE5x5->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE5x5" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE5x5" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE5x5->push_back( IN::phoE5x5->at(index) ); 
 }; 

 void ClearOutputphoE5x5( std::string  prefix ) { 

    std::string my_name = "phoE5x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE5x5, prefix = " << prefix << std::endl; 
     OUT::phoE5x5->clear(); 
 }; 

 void CopyphoE1x5InToOut( std::string prefix ) { 

    std::string my_name = "phoE1x5";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE1x5 = std::vector<float>(*IN::phoE1x5);
}; 

 void CopyphoE1x5InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE1x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE1x5->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE1x5" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE1x5" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE1x5->push_back( IN::phoE1x5->at(index) ); 
 }; 

 void ClearOutputphoE1x5( std::string  prefix ) { 

    std::string my_name = "phoE1x5";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE1x5, prefix = " << prefix << std::endl; 
     OUT::phoE1x5->clear(); 
 }; 

 void CopyphoE2x2InToOut( std::string prefix ) { 

    std::string my_name = "phoE2x2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2x2 = std::vector<float>(*IN::phoE2x2);
}; 

 void CopyphoE2x2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2x2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2x2->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2x2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2x2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2x2->push_back( IN::phoE2x2->at(index) ); 
 }; 

 void ClearOutputphoE2x2( std::string  prefix ) { 

    std::string my_name = "phoE2x2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2x2, prefix = " << prefix << std::endl; 
     OUT::phoE2x2->clear(); 
 }; 

 void CopyphoE2x5MaxInToOut( std::string prefix ) { 

    std::string my_name = "phoE2x5Max";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2x5Max = std::vector<float>(*IN::phoE2x5Max);
}; 

 void CopyphoE2x5MaxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2x5Max";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2x5Max->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2x5Max" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2x5Max" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2x5Max->push_back( IN::phoE2x5Max->at(index) ); 
 }; 

 void ClearOutputphoE2x5Max( std::string  prefix ) { 

    std::string my_name = "phoE2x5Max";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2x5Max, prefix = " << prefix << std::endl; 
     OUT::phoE2x5Max->clear(); 
 }; 

 void CopyphoE2x5TopInToOut( std::string prefix ) { 

    std::string my_name = "phoE2x5Top";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2x5Top = std::vector<float>(*IN::phoE2x5Top);
}; 

 void CopyphoE2x5TopInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2x5Top";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2x5Top->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2x5Top" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2x5Top" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2x5Top->push_back( IN::phoE2x5Top->at(index) ); 
 }; 

 void ClearOutputphoE2x5Top( std::string  prefix ) { 

    std::string my_name = "phoE2x5Top";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2x5Top, prefix = " << prefix << std::endl; 
     OUT::phoE2x5Top->clear(); 
 }; 

 void CopyphoE2x5BottomInToOut( std::string prefix ) { 

    std::string my_name = "phoE2x5Bottom";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2x5Bottom = std::vector<float>(*IN::phoE2x5Bottom);
}; 

 void CopyphoE2x5BottomInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2x5Bottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2x5Bottom->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2x5Bottom" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2x5Bottom" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2x5Bottom->push_back( IN::phoE2x5Bottom->at(index) ); 
 }; 

 void ClearOutputphoE2x5Bottom( std::string  prefix ) { 

    std::string my_name = "phoE2x5Bottom";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2x5Bottom, prefix = " << prefix << std::endl; 
     OUT::phoE2x5Bottom->clear(); 
 }; 

 void CopyphoE2x5LeftInToOut( std::string prefix ) { 

    std::string my_name = "phoE2x5Left";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2x5Left = std::vector<float>(*IN::phoE2x5Left);
}; 

 void CopyphoE2x5LeftInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2x5Left";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2x5Left->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2x5Left" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2x5Left" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2x5Left->push_back( IN::phoE2x5Left->at(index) ); 
 }; 

 void ClearOutputphoE2x5Left( std::string  prefix ) { 

    std::string my_name = "phoE2x5Left";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2x5Left, prefix = " << prefix << std::endl; 
     OUT::phoE2x5Left->clear(); 
 }; 

 void CopyphoE2x5RightInToOut( std::string prefix ) { 

    std::string my_name = "phoE2x5Right";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoE2x5Right = std::vector<float>(*IN::phoE2x5Right);
}; 

 void CopyphoE2x5RightInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoE2x5Right";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoE2x5Right->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoE2x5Right" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoE2x5Right" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoE2x5Right->push_back( IN::phoE2x5Right->at(index) ); 
 }; 

 void ClearOutputphoE2x5Right( std::string  prefix ) { 

    std::string my_name = "phoE2x5Right";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoE2x5Right, prefix = " << prefix << std::endl; 
     OUT::phoE2x5Right->clear(); 
 }; 

 void CopyphoSeedEInToOut( std::string prefix ) { 

    std::string my_name = "phoSeedE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSeedE = std::vector<float>(*IN::phoSeedE);
}; 

 void CopyphoSeedEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSeedE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSeedE->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSeedE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSeedE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSeedE->push_back( IN::phoSeedE->at(index) ); 
 }; 

 void ClearOutputphoSeedE( std::string  prefix ) { 

    std::string my_name = "phoSeedE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSeedE, prefix = " << prefix << std::endl; 
     OUT::phoSeedE->clear(); 
 }; 

 void CopyphoSeedEtaInToOut( std::string prefix ) { 

    std::string my_name = "phoSeedEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSeedEta = std::vector<float>(*IN::phoSeedEta);
}; 

 void CopyphoSeedEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSeedEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSeedEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSeedEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSeedEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSeedEta->push_back( IN::phoSeedEta->at(index) ); 
 }; 

 void ClearOutputphoSeedEta( std::string  prefix ) { 

    std::string my_name = "phoSeedEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSeedEta, prefix = " << prefix << std::endl; 
     OUT::phoSeedEta->clear(); 
 }; 

 void CopyphoSeedPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoSeedPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSeedPhi = std::vector<float>(*IN::phoSeedPhi);
}; 

 void CopyphoSeedPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSeedPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSeedPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSeedPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSeedPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSeedPhi->push_back( IN::phoSeedPhi->at(index) ); 
 }; 

 void ClearOutputphoSeedPhi( std::string  prefix ) { 

    std::string my_name = "phoSeedPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSeedPhi, prefix = " << prefix << std::endl; 
     OUT::phoSeedPhi->clear(); 
 }; 

 void CopyphoCrysEtaInToOut( std::string prefix ) { 

    std::string my_name = "phoCrysEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCrysEta = std::vector<float>(*IN::phoCrysEta);
}; 

 void CopyphoCrysEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCrysEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCrysEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCrysEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCrysEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCrysEta->push_back( IN::phoCrysEta->at(index) ); 
 }; 

 void ClearOutputphoCrysEta( std::string  prefix ) { 

    std::string my_name = "phoCrysEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCrysEta, prefix = " << prefix << std::endl; 
     OUT::phoCrysEta->clear(); 
 }; 

 void CopyphoCrysPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoCrysPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCrysPhi = std::vector<float>(*IN::phoCrysPhi);
}; 

 void CopyphoCrysPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCrysPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCrysPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCrysPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCrysPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCrysPhi->push_back( IN::phoCrysPhi->at(index) ); 
 }; 

 void ClearOutputphoCrysPhi( std::string  prefix ) { 

    std::string my_name = "phoCrysPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCrysPhi, prefix = " << prefix << std::endl; 
     OUT::phoCrysPhi->clear(); 
 }; 

 void CopyphoCrysIEtaInToOut( std::string prefix ) { 

    std::string my_name = "phoCrysIEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCrysIEta = std::vector<int>(*IN::phoCrysIEta);
}; 

 void CopyphoCrysIEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCrysIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCrysIEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCrysIEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCrysIEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCrysIEta->push_back( IN::phoCrysIEta->at(index) ); 
 }; 

 void ClearOutputphoCrysIEta( std::string  prefix ) { 

    std::string my_name = "phoCrysIEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCrysIEta, prefix = " << prefix << std::endl; 
     OUT::phoCrysIEta->clear(); 
 }; 

 void CopyphoCrysIPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoCrysIPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoCrysIPhi = std::vector<int>(*IN::phoCrysIPhi);
}; 

 void CopyphoCrysIPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoCrysIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoCrysIPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoCrysIPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoCrysIPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoCrysIPhi->push_back( IN::phoCrysIPhi->at(index) ); 
 }; 

 void ClearOutputphoCrysIPhi( std::string  prefix ) { 

    std::string my_name = "phoCrysIPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoCrysIPhi, prefix = " << prefix << std::endl; 
     OUT::phoCrysIPhi->clear(); 
 }; 

 void CopyphoPFChIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoPFChIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFChIso = std::vector<float>(*IN::phoPFChIso);
}; 

 void CopyphoPFChIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFChIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFChIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFChIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFChIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFChIso->push_back( IN::phoPFChIso->at(index) ); 
 }; 

 void ClearOutputphoPFChIso( std::string  prefix ) { 

    std::string my_name = "phoPFChIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFChIso, prefix = " << prefix << std::endl; 
     OUT::phoPFChIso->clear(); 
 }; 

 void CopyphoPFPhoIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoPFPhoIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFPhoIso = std::vector<float>(*IN::phoPFPhoIso);
}; 

 void CopyphoPFPhoIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFPhoIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFPhoIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFPhoIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFPhoIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFPhoIso->push_back( IN::phoPFPhoIso->at(index) ); 
 }; 

 void ClearOutputphoPFPhoIso( std::string  prefix ) { 

    std::string my_name = "phoPFPhoIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFPhoIso, prefix = " << prefix << std::endl; 
     OUT::phoPFPhoIso->clear(); 
 }; 

 void CopyphoPFNeuIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoPFNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFNeuIso = std::vector<float>(*IN::phoPFNeuIso);
}; 

 void CopyphoPFNeuIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFNeuIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFNeuIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFNeuIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFNeuIso->push_back( IN::phoPFNeuIso->at(index) ); 
 }; 

 void ClearOutputphoPFNeuIso( std::string  prefix ) { 

    std::string my_name = "phoPFNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFNeuIso, prefix = " << prefix << std::endl; 
     OUT::phoPFNeuIso->clear(); 
 }; 

 void CopyphoSCRChIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoSCRChIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRChIso = std::vector<float>(*IN::phoSCRChIso);
}; 

 void CopyphoSCRChIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRChIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRChIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRChIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRChIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRChIso->push_back( IN::phoSCRChIso->at(index) ); 
 }; 

 void ClearOutputphoSCRChIso( std::string  prefix ) { 

    std::string my_name = "phoSCRChIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRChIso, prefix = " << prefix << std::endl; 
     OUT::phoSCRChIso->clear(); 
 }; 

 void CopyphoSCRPhoIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoSCRPhoIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRPhoIso = std::vector<float>(*IN::phoSCRPhoIso);
}; 

 void CopyphoSCRPhoIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRPhoIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRPhoIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRPhoIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRPhoIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRPhoIso->push_back( IN::phoSCRPhoIso->at(index) ); 
 }; 

 void ClearOutputphoSCRPhoIso( std::string  prefix ) { 

    std::string my_name = "phoSCRPhoIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRPhoIso, prefix = " << prefix << std::endl; 
     OUT::phoSCRPhoIso->clear(); 
 }; 

 void CopyphoSCRNeuIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoSCRNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRNeuIso = std::vector<float>(*IN::phoSCRNeuIso);
}; 

 void CopyphoSCRNeuIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRNeuIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRNeuIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRNeuIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRNeuIso->push_back( IN::phoSCRNeuIso->at(index) ); 
 }; 

 void ClearOutputphoSCRNeuIso( std::string  prefix ) { 

    std::string my_name = "phoSCRNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRNeuIso, prefix = " << prefix << std::endl; 
     OUT::phoSCRNeuIso->clear(); 
 }; 

 void CopyphoSCRChIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoSCRChIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRChIso04 = std::vector<float>(*IN::phoSCRChIso04);
}; 

 void CopyphoSCRChIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRChIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRChIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRChIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRChIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRChIso04->push_back( IN::phoSCRChIso04->at(index) ); 
 }; 

 void ClearOutputphoSCRChIso04( std::string  prefix ) { 

    std::string my_name = "phoSCRChIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRChIso04, prefix = " << prefix << std::endl; 
     OUT::phoSCRChIso04->clear(); 
 }; 

 void CopyphoSCRPhoIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoSCRPhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRPhoIso04 = std::vector<float>(*IN::phoSCRPhoIso04);
}; 

 void CopyphoSCRPhoIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRPhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRPhoIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRPhoIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRPhoIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRPhoIso04->push_back( IN::phoSCRPhoIso04->at(index) ); 
 }; 

 void ClearOutputphoSCRPhoIso04( std::string  prefix ) { 

    std::string my_name = "phoSCRPhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRPhoIso04, prefix = " << prefix << std::endl; 
     OUT::phoSCRPhoIso04->clear(); 
 }; 

 void CopyphoSCRNeuIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoSCRNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRNeuIso04 = std::vector<float>(*IN::phoSCRNeuIso04);
}; 

 void CopyphoSCRNeuIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRNeuIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRNeuIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRNeuIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRNeuIso04->push_back( IN::phoSCRNeuIso04->at(index) ); 
 }; 

 void ClearOutputphoSCRNeuIso04( std::string  prefix ) { 

    std::string my_name = "phoSCRNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRNeuIso04, prefix = " << prefix << std::endl; 
     OUT::phoSCRNeuIso04->clear(); 
 }; 

 void CopyphoRandConeChIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoRandConeChIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRandConeChIso = std::vector<float>(*IN::phoRandConeChIso);
}; 

 void CopyphoRandConeChIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRandConeChIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRandConeChIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRandConeChIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRandConeChIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRandConeChIso->push_back( IN::phoRandConeChIso->at(index) ); 
 }; 

 void ClearOutputphoRandConeChIso( std::string  prefix ) { 

    std::string my_name = "phoRandConeChIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRandConeChIso, prefix = " << prefix << std::endl; 
     OUT::phoRandConeChIso->clear(); 
 }; 

 void CopyphoRandConePhoIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoRandConePhoIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRandConePhoIso = std::vector<float>(*IN::phoRandConePhoIso);
}; 

 void CopyphoRandConePhoIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRandConePhoIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRandConePhoIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRandConePhoIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRandConePhoIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRandConePhoIso->push_back( IN::phoRandConePhoIso->at(index) ); 
 }; 

 void ClearOutputphoRandConePhoIso( std::string  prefix ) { 

    std::string my_name = "phoRandConePhoIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRandConePhoIso, prefix = " << prefix << std::endl; 
     OUT::phoRandConePhoIso->clear(); 
 }; 

 void CopyphoRandConeNeuIsoInToOut( std::string prefix ) { 

    std::string my_name = "phoRandConeNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRandConeNeuIso = std::vector<float>(*IN::phoRandConeNeuIso);
}; 

 void CopyphoRandConeNeuIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRandConeNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRandConeNeuIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRandConeNeuIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRandConeNeuIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRandConeNeuIso->push_back( IN::phoRandConeNeuIso->at(index) ); 
 }; 

 void ClearOutputphoRandConeNeuIso( std::string  prefix ) { 

    std::string my_name = "phoRandConeNeuIso";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRandConeNeuIso, prefix = " << prefix << std::endl; 
     OUT::phoRandConeNeuIso->clear(); 
 }; 

 void CopyphoRandConeChIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoRandConeChIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRandConeChIso04 = std::vector<float>(*IN::phoRandConeChIso04);
}; 

 void CopyphoRandConeChIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRandConeChIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRandConeChIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRandConeChIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRandConeChIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRandConeChIso04->push_back( IN::phoRandConeChIso04->at(index) ); 
 }; 

 void ClearOutputphoRandConeChIso04( std::string  prefix ) { 

    std::string my_name = "phoRandConeChIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRandConeChIso04, prefix = " << prefix << std::endl; 
     OUT::phoRandConeChIso04->clear(); 
 }; 

 void CopyphoRandConePhoIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoRandConePhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRandConePhoIso04 = std::vector<float>(*IN::phoRandConePhoIso04);
}; 

 void CopyphoRandConePhoIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRandConePhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRandConePhoIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRandConePhoIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRandConePhoIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRandConePhoIso04->push_back( IN::phoRandConePhoIso04->at(index) ); 
 }; 

 void ClearOutputphoRandConePhoIso04( std::string  prefix ) { 

    std::string my_name = "phoRandConePhoIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRandConePhoIso04, prefix = " << prefix << std::endl; 
     OUT::phoRandConePhoIso04->clear(); 
 }; 

 void CopyphoRandConeNeuIso04InToOut( std::string prefix ) { 

    std::string my_name = "phoRandConeNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRandConeNeuIso04 = std::vector<float>(*IN::phoRandConeNeuIso04);
}; 

 void CopyphoRandConeNeuIso04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRandConeNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRandConeNeuIso04->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRandConeNeuIso04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRandConeNeuIso04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRandConeNeuIso04->push_back( IN::phoRandConeNeuIso04->at(index) ); 
 }; 

 void ClearOutputphoRandConeNeuIso04( std::string  prefix ) { 

    std::string my_name = "phoRandConeNeuIso04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRandConeNeuIso04, prefix = " << prefix << std::endl; 
     OUT::phoRandConeNeuIso04->clear(); 
 }; 

 void CopyphoRegrEInToOut( std::string prefix ) { 

    std::string my_name = "phoRegrE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRegrE = std::vector<float>(*IN::phoRegrE);
}; 

 void CopyphoRegrEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRegrE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRegrE->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRegrE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRegrE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRegrE->push_back( IN::phoRegrE->at(index) ); 
 }; 

 void ClearOutputphoRegrE( std::string  prefix ) { 

    std::string my_name = "phoRegrE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRegrE, prefix = " << prefix << std::endl; 
     OUT::phoRegrE->clear(); 
 }; 

 void CopyphoRegrEerrInToOut( std::string prefix ) { 

    std::string my_name = "phoRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRegrEerr = std::vector<float>(*IN::phoRegrEerr);
}; 

 void CopyphoRegrEerrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRegrEerr->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRegrEerr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRegrEerr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRegrEerr->push_back( IN::phoRegrEerr->at(index) ); 
 }; 

 void ClearOutputphoRegrEerr( std::string  prefix ) { 

    std::string my_name = "phoRegrEerr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRegrEerr, prefix = " << prefix << std::endl; 
     OUT::phoRegrEerr->clear(); 
 }; 

 void CopyphoSeedTimeInToOut( std::string prefix ) { 

    std::string my_name = "phoSeedTime";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSeedTime = std::vector<float>(*IN::phoSeedTime);
}; 

 void CopyphoSeedTimeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSeedTime";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSeedTime->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSeedTime" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSeedTime" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSeedTime->push_back( IN::phoSeedTime->at(index) ); 
 }; 

 void ClearOutputphoSeedTime( std::string  prefix ) { 

    std::string my_name = "phoSeedTime";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSeedTime, prefix = " << prefix << std::endl; 
     OUT::phoSeedTime->clear(); 
 }; 

 void CopyphoSeedDetId1InToOut( std::string prefix ) { 

    std::string my_name = "phoSeedDetId1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSeedDetId1 = std::vector<int>(*IN::phoSeedDetId1);
}; 

 void CopyphoSeedDetId1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSeedDetId1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSeedDetId1->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSeedDetId1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSeedDetId1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSeedDetId1->push_back( IN::phoSeedDetId1->at(index) ); 
 }; 

 void ClearOutputphoSeedDetId1( std::string  prefix ) { 

    std::string my_name = "phoSeedDetId1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSeedDetId1, prefix = " << prefix << std::endl; 
     OUT::phoSeedDetId1->clear(); 
 }; 

 void CopyphoSeedDetId2InToOut( std::string prefix ) { 

    std::string my_name = "phoSeedDetId2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSeedDetId2 = std::vector<int>(*IN::phoSeedDetId2);
}; 

 void CopyphoSeedDetId2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSeedDetId2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSeedDetId2->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSeedDetId2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSeedDetId2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSeedDetId2->push_back( IN::phoSeedDetId2->at(index) ); 
 }; 

 void ClearOutputphoSeedDetId2( std::string  prefix ) { 

    std::string my_name = "phoSeedDetId2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSeedDetId2, prefix = " << prefix << std::endl; 
     OUT::phoSeedDetId2->clear(); 
 }; 

 void CopyphoLICTDInToOut( std::string prefix ) { 

    std::string my_name = "phoLICTD";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoLICTD = std::vector<float>(*IN::phoLICTD);
}; 

 void CopyphoLICTDInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoLICTD";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoLICTD->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoLICTD" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoLICTD" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoLICTD->push_back( IN::phoLICTD->at(index) ); 
 }; 

 void ClearOutputphoLICTD( std::string  prefix ) { 

    std::string my_name = "phoLICTD";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoLICTD, prefix = " << prefix << std::endl; 
     OUT::phoLICTD->clear(); 
 }; 

 void CopyphoRecoFlagInToOut( std::string prefix ) { 

    std::string my_name = "phoRecoFlag";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoRecoFlag = std::vector<int>(*IN::phoRecoFlag);
}; 

 void CopyphoRecoFlagInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoRecoFlag";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoRecoFlag->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoRecoFlag" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoRecoFlag" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoRecoFlag->push_back( IN::phoRecoFlag->at(index) ); 
 }; 

 void ClearOutputphoRecoFlag( std::string  prefix ) { 

    std::string my_name = "phoRecoFlag";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoRecoFlag, prefix = " << prefix << std::endl; 
     OUT::phoRecoFlag->clear(); 
 }; 

 void CopyphoPosInToOut( std::string prefix ) { 

    std::string my_name = "phoPos";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPos = std::vector<int>(*IN::phoPos);
}; 

 void CopyphoPosInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPos";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPos->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPos" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPos" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPos->push_back( IN::phoPos->at(index) ); 
 }; 

 void ClearOutputphoPos( std::string  prefix ) { 

    std::string my_name = "phoPos";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPos, prefix = " << prefix << std::endl; 
     OUT::phoPos->clear(); 
 }; 

 void CopyphoSCEInToOut( std::string prefix ) { 

    std::string my_name = "phoSCE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCE = std::vector<float>(*IN::phoSCE);
}; 

 void CopyphoSCEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCE->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCE->push_back( IN::phoSCE->at(index) ); 
 }; 

 void ClearOutputphoSCE( std::string  prefix ) { 

    std::string my_name = "phoSCE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCE, prefix = " << prefix << std::endl; 
     OUT::phoSCE->clear(); 
 }; 

 void CopyphoSCRawEInToOut( std::string prefix ) { 

    std::string my_name = "phoSCRawE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCRawE = std::vector<float>(*IN::phoSCRawE);
}; 

 void CopyphoSCRawEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCRawE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCRawE->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCRawE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCRawE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCRawE->push_back( IN::phoSCRawE->at(index) ); 
 }; 

 void ClearOutputphoSCRawE( std::string  prefix ) { 

    std::string my_name = "phoSCRawE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCRawE, prefix = " << prefix << std::endl; 
     OUT::phoSCRawE->clear(); 
 }; 

 void CopyphoESEnInToOut( std::string prefix ) { 

    std::string my_name = "phoESEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoESEn = std::vector<float>(*IN::phoESEn);
}; 

 void CopyphoESEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoESEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoESEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoESEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoESEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoESEn->push_back( IN::phoESEn->at(index) ); 
 }; 

 void ClearOutputphoESEn( std::string  prefix ) { 

    std::string my_name = "phoESEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoESEn, prefix = " << prefix << std::endl; 
     OUT::phoESEn->clear(); 
 }; 

 void CopyphoSCEtInToOut( std::string prefix ) { 

    std::string my_name = "phoSCEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCEt = std::vector<float>(*IN::phoSCEt);
}; 

 void CopyphoSCEtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCEt->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCEt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCEt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCEt->push_back( IN::phoSCEt->at(index) ); 
 }; 

 void ClearOutputphoSCEt( std::string  prefix ) { 

    std::string my_name = "phoSCEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCEt, prefix = " << prefix << std::endl; 
     OUT::phoSCEt->clear(); 
 }; 

 void CopyphoSCEtaInToOut( std::string prefix ) { 

    std::string my_name = "phoSCEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCEta = std::vector<float>(*IN::phoSCEta);
}; 

 void CopyphoSCEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCEta->push_back( IN::phoSCEta->at(index) ); 
 }; 

 void ClearOutputphoSCEta( std::string  prefix ) { 

    std::string my_name = "phoSCEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCEta, prefix = " << prefix << std::endl; 
     OUT::phoSCEta->clear(); 
 }; 

 void CopyphoSCPhiInToOut( std::string prefix ) { 

    std::string my_name = "phoSCPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCPhi = std::vector<float>(*IN::phoSCPhi);
}; 

 void CopyphoSCPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCPhi->push_back( IN::phoSCPhi->at(index) ); 
 }; 

 void ClearOutputphoSCPhi( std::string  prefix ) { 

    std::string my_name = "phoSCPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCPhi, prefix = " << prefix << std::endl; 
     OUT::phoSCPhi->clear(); 
 }; 

 void CopyphoSCEtaWidthInToOut( std::string prefix ) { 

    std::string my_name = "phoSCEtaWidth";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCEtaWidth = std::vector<float>(*IN::phoSCEtaWidth);
}; 

 void CopyphoSCEtaWidthInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCEtaWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCEtaWidth->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCEtaWidth" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCEtaWidth" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCEtaWidth->push_back( IN::phoSCEtaWidth->at(index) ); 
 }; 

 void ClearOutputphoSCEtaWidth( std::string  prefix ) { 

    std::string my_name = "phoSCEtaWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCEtaWidth, prefix = " << prefix << std::endl; 
     OUT::phoSCEtaWidth->clear(); 
 }; 

 void CopyphoSCPhiWidthInToOut( std::string prefix ) { 

    std::string my_name = "phoSCPhiWidth";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCPhiWidth = std::vector<float>(*IN::phoSCPhiWidth);
}; 

 void CopyphoSCPhiWidthInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCPhiWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCPhiWidth->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCPhiWidth" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCPhiWidth" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCPhiWidth->push_back( IN::phoSCPhiWidth->at(index) ); 
 }; 

 void ClearOutputphoSCPhiWidth( std::string  prefix ) { 

    std::string my_name = "phoSCPhiWidth";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCPhiWidth, prefix = " << prefix << std::endl; 
     OUT::phoSCPhiWidth->clear(); 
 }; 

 void CopyphoSCBremInToOut( std::string prefix ) { 

    std::string my_name = "phoSCBrem";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoSCBrem = std::vector<float>(*IN::phoSCBrem);
}; 

 void CopyphoSCBremInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoSCBrem";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoSCBrem->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoSCBrem" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoSCBrem" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoSCBrem->push_back( IN::phoSCBrem->at(index) ); 
 }; 

 void ClearOutputphoSCBrem( std::string  prefix ) { 

    std::string my_name = "phoSCBrem";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoSCBrem, prefix = " << prefix << std::endl; 
     OUT::phoSCBrem->clear(); 
 }; 

 void CopyphoOverlapInToOut( std::string prefix ) { 

    std::string my_name = "phoOverlap";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoOverlap = std::vector<int>(*IN::phoOverlap);
}; 

 void CopyphoOverlapInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoOverlap";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoOverlap->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoOverlap" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoOverlap" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoOverlap->push_back( IN::phoOverlap->at(index) ); 
 }; 

 void ClearOutputphoOverlap( std::string  prefix ) { 

    std::string my_name = "phoOverlap";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoOverlap, prefix = " << prefix << std::endl; 
     OUT::phoOverlap->clear(); 
 }; 

 void CopyphohasPixelSeedInToOut( std::string prefix ) { 

    std::string my_name = "phohasPixelSeed";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phohasPixelSeed = std::vector<int>(*IN::phohasPixelSeed);
}; 

 void CopyphohasPixelSeedInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phohasPixelSeed";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phohasPixelSeed->size() ) {
         std::cout << "Vector size exceeded for branch IN::phohasPixelSeed" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phohasPixelSeed" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phohasPixelSeed->push_back( IN::phohasPixelSeed->at(index) ); 
 }; 

 void ClearOutputphohasPixelSeed( std::string  prefix ) { 

    std::string my_name = "phohasPixelSeed";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phohasPixelSeed, prefix = " << prefix << std::endl; 
     OUT::phohasPixelSeed->clear(); 
 }; 

 void Copypho_hasConvPfInToOut( std::string prefix ) { 

    std::string my_name = "pho_hasConvPf";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_hasConvPf = std::vector<int>(*IN::pho_hasConvPf);
}; 

 void Copypho_hasConvPfInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_hasConvPf";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_hasConvPf->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_hasConvPf" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_hasConvPf" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_hasConvPf->push_back( IN::pho_hasConvPf->at(index) ); 
 }; 

 void ClearOutputpho_hasConvPf( std::string  prefix ) { 

    std::string my_name = "pho_hasConvPf";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_hasConvPf, prefix = " << prefix << std::endl; 
     OUT::pho_hasConvPf->clear(); 
 }; 

 void Copypho_hasSLConvPfInToOut( std::string prefix ) { 

    std::string my_name = "pho_hasSLConvPf";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_hasSLConvPf = std::vector<int>(*IN::pho_hasSLConvPf);
}; 

 void Copypho_hasSLConvPfInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_hasSLConvPf";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_hasSLConvPf->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_hasSLConvPf" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_hasSLConvPf" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_hasSLConvPf->push_back( IN::pho_hasSLConvPf->at(index) ); 
 }; 

 void ClearOutputpho_hasSLConvPf( std::string  prefix ) { 

    std::string my_name = "pho_hasSLConvPf";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_hasSLConvPf, prefix = " << prefix << std::endl; 
     OUT::pho_hasSLConvPf->clear(); 
 }; 

 void Copypho_pfconvVtxZInToOut( std::string prefix ) { 

    std::string my_name = "pho_pfconvVtxZ";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_pfconvVtxZ = std::vector<float>(*IN::pho_pfconvVtxZ);
}; 

 void Copypho_pfconvVtxZInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_pfconvVtxZ";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_pfconvVtxZ->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_pfconvVtxZ" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_pfconvVtxZ" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_pfconvVtxZ->push_back( IN::pho_pfconvVtxZ->at(index) ); 
 }; 

 void ClearOutputpho_pfconvVtxZ( std::string  prefix ) { 

    std::string my_name = "pho_pfconvVtxZ";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_pfconvVtxZ, prefix = " << prefix << std::endl; 
     OUT::pho_pfconvVtxZ->clear(); 
 }; 

 void Copypho_pfconvVtxZErrInToOut( std::string prefix ) { 

    std::string my_name = "pho_pfconvVtxZErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_pfconvVtxZErr = std::vector<float>(*IN::pho_pfconvVtxZErr);
}; 

 void Copypho_pfconvVtxZErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_pfconvVtxZErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_pfconvVtxZErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_pfconvVtxZErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_pfconvVtxZErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_pfconvVtxZErr->push_back( IN::pho_pfconvVtxZErr->at(index) ); 
 }; 

 void ClearOutputpho_pfconvVtxZErr( std::string  prefix ) { 

    std::string my_name = "pho_pfconvVtxZErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_pfconvVtxZErr, prefix = " << prefix << std::endl; 
     OUT::pho_pfconvVtxZErr->clear(); 
 }; 

 void Copypho_nSLConvInToOut( std::string prefix ) { 

    std::string my_name = "pho_nSLConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_nSLConv = std::vector<int>(*IN::pho_nSLConv);
}; 

 void Copypho_nSLConvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_nSLConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_nSLConv->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_nSLConv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_nSLConv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_nSLConv->push_back( IN::pho_nSLConv->at(index) ); 
 }; 

 void ClearOutputpho_nSLConv( std::string  prefix ) { 

    std::string my_name = "pho_nSLConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_nSLConv, prefix = " << prefix << std::endl; 
     OUT::pho_nSLConv->clear(); 
 }; 

 void Copypho_pfSLConvPos_xInToOut( std::string prefix ) { 

    std::string my_name = "pho_pfSLConvPos_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_pfSLConvPos_x = std::vector<std::vector<float> >(*IN::pho_pfSLConvPos_x);
}; 

 void Copypho_pfSLConvPos_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvPos_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_pfSLConvPos_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_pfSLConvPos_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_pfSLConvPos_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvPos_x->push_back( IN::pho_pfSLConvPos_x->at(index) ); 
 }; 

 void ClearOutputpho_pfSLConvPos_x( std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvPos_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_pfSLConvPos_x, prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvPos_x->clear(); 
 }; 

 void Copypho_pfSLConvPos_yInToOut( std::string prefix ) { 

    std::string my_name = "pho_pfSLConvPos_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_pfSLConvPos_y = std::vector<std::vector<float> >(*IN::pho_pfSLConvPos_y);
}; 

 void Copypho_pfSLConvPos_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvPos_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_pfSLConvPos_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_pfSLConvPos_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_pfSLConvPos_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvPos_y->push_back( IN::pho_pfSLConvPos_y->at(index) ); 
 }; 

 void ClearOutputpho_pfSLConvPos_y( std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvPos_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_pfSLConvPos_y, prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvPos_y->clear(); 
 }; 

 void Copypho_pfSLConvPos_zInToOut( std::string prefix ) { 

    std::string my_name = "pho_pfSLConvPos_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_pfSLConvPos_z = std::vector<std::vector<float> >(*IN::pho_pfSLConvPos_z);
}; 

 void Copypho_pfSLConvPos_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvPos_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_pfSLConvPos_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_pfSLConvPos_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_pfSLConvPos_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvPos_z->push_back( IN::pho_pfSLConvPos_z->at(index) ); 
 }; 

 void ClearOutputpho_pfSLConvPos_z( std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvPos_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_pfSLConvPos_z, prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvPos_z->clear(); 
 }; 

 void Copypho_pfSLConvVtxZInToOut( std::string prefix ) { 

    std::string my_name = "pho_pfSLConvVtxZ";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::pho_pfSLConvVtxZ = std::vector<std::vector<float> >(*IN::pho_pfSLConvVtxZ);
}; 

 void Copypho_pfSLConvVtxZInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvVtxZ";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::pho_pfSLConvVtxZ->size() ) {
         std::cout << "Vector size exceeded for branch IN::pho_pfSLConvVtxZ" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible pho_pfSLConvVtxZ" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvVtxZ->push_back( IN::pho_pfSLConvVtxZ->at(index) ); 
 }; 

 void ClearOutputpho_pfSLConvVtxZ( std::string  prefix ) { 

    std::string my_name = "pho_pfSLConvVtxZ";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible pho_pfSLConvVtxZ, prefix = " << prefix << std::endl; 
     OUT::pho_pfSLConvVtxZ->clear(); 
 }; 

 void CopyphoIsConvInToOut( std::string prefix ) { 

    std::string my_name = "phoIsConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoIsConv = std::vector<int>(*IN::phoIsConv);
}; 

 void CopyphoIsConvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoIsConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoIsConv->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoIsConv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoIsConv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoIsConv->push_back( IN::phoIsConv->at(index) ); 
 }; 

 void ClearOutputphoIsConv( std::string  prefix ) { 

    std::string my_name = "phoIsConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoIsConv, prefix = " << prefix << std::endl; 
     OUT::phoIsConv->clear(); 
 }; 

 void CopyphoNConvInToOut( std::string prefix ) { 

    std::string my_name = "phoNConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoNConv = std::vector<int>(*IN::phoNConv);
}; 

 void CopyphoNConvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoNConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoNConv->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoNConv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoNConv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoNConv->push_back( IN::phoNConv->at(index) ); 
 }; 

 void ClearOutputphoNConv( std::string  prefix ) { 

    std::string my_name = "phoNConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoNConv, prefix = " << prefix << std::endl; 
     OUT::phoNConv->clear(); 
 }; 

 void CopyphoConvInvMassInToOut( std::string prefix ) { 

    std::string my_name = "phoConvInvMass";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvInvMass = std::vector<float>(*IN::phoConvInvMass);
}; 

 void CopyphoConvInvMassInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvInvMass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvInvMass->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvInvMass" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvInvMass" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvInvMass->push_back( IN::phoConvInvMass->at(index) ); 
 }; 

 void ClearOutputphoConvInvMass( std::string  prefix ) { 

    std::string my_name = "phoConvInvMass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvInvMass, prefix = " << prefix << std::endl; 
     OUT::phoConvInvMass->clear(); 
 }; 

 void CopyphoConvCotThetaInToOut( std::string prefix ) { 

    std::string my_name = "phoConvCotTheta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvCotTheta = std::vector<float>(*IN::phoConvCotTheta);
}; 

 void CopyphoConvCotThetaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvCotTheta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvCotTheta->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvCotTheta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvCotTheta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvCotTheta->push_back( IN::phoConvCotTheta->at(index) ); 
 }; 

 void ClearOutputphoConvCotTheta( std::string  prefix ) { 

    std::string my_name = "phoConvCotTheta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvCotTheta, prefix = " << prefix << std::endl; 
     OUT::phoConvCotTheta->clear(); 
 }; 

 void CopyphoConvEoverPInToOut( std::string prefix ) { 

    std::string my_name = "phoConvEoverP";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvEoverP = std::vector<float>(*IN::phoConvEoverP);
}; 

 void CopyphoConvEoverPInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvEoverP";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvEoverP->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvEoverP" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvEoverP" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvEoverP->push_back( IN::phoConvEoverP->at(index) ); 
 }; 

 void ClearOutputphoConvEoverP( std::string  prefix ) { 

    std::string my_name = "phoConvEoverP";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvEoverP, prefix = " << prefix << std::endl; 
     OUT::phoConvEoverP->clear(); 
 }; 

 void CopyphoConvZofPVfromTrksInToOut( std::string prefix ) { 

    std::string my_name = "phoConvZofPVfromTrks";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvZofPVfromTrks = std::vector<float>(*IN::phoConvZofPVfromTrks);
}; 

 void CopyphoConvZofPVfromTrksInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvZofPVfromTrks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvZofPVfromTrks->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvZofPVfromTrks" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvZofPVfromTrks" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvZofPVfromTrks->push_back( IN::phoConvZofPVfromTrks->at(index) ); 
 }; 

 void ClearOutputphoConvZofPVfromTrks( std::string  prefix ) { 

    std::string my_name = "phoConvZofPVfromTrks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvZofPVfromTrks, prefix = " << prefix << std::endl; 
     OUT::phoConvZofPVfromTrks->clear(); 
 }; 

 void CopyphoConvMinDistInToOut( std::string prefix ) { 

    std::string my_name = "phoConvMinDist";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvMinDist = std::vector<float>(*IN::phoConvMinDist);
}; 

 void CopyphoConvMinDistInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvMinDist";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvMinDist->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvMinDist" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvMinDist" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvMinDist->push_back( IN::phoConvMinDist->at(index) ); 
 }; 

 void ClearOutputphoConvMinDist( std::string  prefix ) { 

    std::string my_name = "phoConvMinDist";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvMinDist, prefix = " << prefix << std::endl; 
     OUT::phoConvMinDist->clear(); 
 }; 

 void CopyphoConvdPhiAtVtxInToOut( std::string prefix ) { 

    std::string my_name = "phoConvdPhiAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvdPhiAtVtx = std::vector<float>(*IN::phoConvdPhiAtVtx);
}; 

 void CopyphoConvdPhiAtVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvdPhiAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvdPhiAtVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvdPhiAtVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvdPhiAtVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvdPhiAtVtx->push_back( IN::phoConvdPhiAtVtx->at(index) ); 
 }; 

 void ClearOutputphoConvdPhiAtVtx( std::string  prefix ) { 

    std::string my_name = "phoConvdPhiAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvdPhiAtVtx, prefix = " << prefix << std::endl; 
     OUT::phoConvdPhiAtVtx->clear(); 
 }; 

 void CopyphoConvdPhiAtCaloInToOut( std::string prefix ) { 

    std::string my_name = "phoConvdPhiAtCalo";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvdPhiAtCalo = std::vector<float>(*IN::phoConvdPhiAtCalo);
}; 

 void CopyphoConvdPhiAtCaloInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvdPhiAtCalo";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvdPhiAtCalo->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvdPhiAtCalo" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvdPhiAtCalo" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvdPhiAtCalo->push_back( IN::phoConvdPhiAtCalo->at(index) ); 
 }; 

 void ClearOutputphoConvdPhiAtCalo( std::string  prefix ) { 

    std::string my_name = "phoConvdPhiAtCalo";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvdPhiAtCalo, prefix = " << prefix << std::endl; 
     OUT::phoConvdPhiAtCalo->clear(); 
 }; 

 void CopyphoConvdEtaAtCaloInToOut( std::string prefix ) { 

    std::string my_name = "phoConvdEtaAtCalo";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvdEtaAtCalo = std::vector<float>(*IN::phoConvdEtaAtCalo);
}; 

 void CopyphoConvdEtaAtCaloInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvdEtaAtCalo";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvdEtaAtCalo->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvdEtaAtCalo" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvdEtaAtCalo" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvdEtaAtCalo->push_back( IN::phoConvdEtaAtCalo->at(index) ); 
 }; 

 void ClearOutputphoConvdEtaAtCalo( std::string  prefix ) { 

    std::string my_name = "phoConvdEtaAtCalo";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvdEtaAtCalo, prefix = " << prefix << std::endl; 
     OUT::phoConvdEtaAtCalo->clear(); 
 }; 

 void CopyphoConvTrkd0_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkd0_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkd0_x = std::vector<float>(*IN::phoConvTrkd0_x);
}; 

 void CopyphoConvTrkd0_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkd0_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkd0_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkd0_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkd0_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkd0_x->push_back( IN::phoConvTrkd0_x->at(index) ); 
 }; 

 void ClearOutputphoConvTrkd0_x( std::string  prefix ) { 

    std::string my_name = "phoConvTrkd0_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkd0_x, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkd0_x->clear(); 
 }; 

 void CopyphoConvTrkd0_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkd0_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkd0_y = std::vector<float>(*IN::phoConvTrkd0_y);
}; 

 void CopyphoConvTrkd0_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkd0_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkd0_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkd0_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkd0_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkd0_y->push_back( IN::phoConvTrkd0_y->at(index) ); 
 }; 

 void ClearOutputphoConvTrkd0_y( std::string  prefix ) { 

    std::string my_name = "phoConvTrkd0_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkd0_y, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkd0_y->clear(); 
 }; 

 void CopyphoConvTrkPin_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkPin_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkPin_x = std::vector<float>(*IN::phoConvTrkPin_x);
}; 

 void CopyphoConvTrkPin_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkPin_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkPin_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkPin_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkPin_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPin_x->push_back( IN::phoConvTrkPin_x->at(index) ); 
 }; 

 void ClearOutputphoConvTrkPin_x( std::string  prefix ) { 

    std::string my_name = "phoConvTrkPin_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkPin_x, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPin_x->clear(); 
 }; 

 void CopyphoConvTrkPin_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkPin_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkPin_y = std::vector<float>(*IN::phoConvTrkPin_y);
}; 

 void CopyphoConvTrkPin_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkPin_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkPin_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkPin_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkPin_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPin_y->push_back( IN::phoConvTrkPin_y->at(index) ); 
 }; 

 void ClearOutputphoConvTrkPin_y( std::string  prefix ) { 

    std::string my_name = "phoConvTrkPin_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkPin_y, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPin_y->clear(); 
 }; 

 void CopyphoConvTrkPout_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkPout_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkPout_x = std::vector<float>(*IN::phoConvTrkPout_x);
}; 

 void CopyphoConvTrkPout_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkPout_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkPout_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkPout_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkPout_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPout_x->push_back( IN::phoConvTrkPout_x->at(index) ); 
 }; 

 void ClearOutputphoConvTrkPout_x( std::string  prefix ) { 

    std::string my_name = "phoConvTrkPout_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkPout_x, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPout_x->clear(); 
 }; 

 void CopyphoConvTrkPout_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkPout_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkPout_y = std::vector<float>(*IN::phoConvTrkPout_y);
}; 

 void CopyphoConvTrkPout_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkPout_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkPout_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkPout_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkPout_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPout_y->push_back( IN::phoConvTrkPout_y->at(index) ); 
 }; 

 void ClearOutputphoConvTrkPout_y( std::string  prefix ) { 

    std::string my_name = "phoConvTrkPout_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkPout_y, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkPout_y->clear(); 
 }; 

 void CopyphoConvTrkdz_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkdz_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkdz_x = std::vector<float>(*IN::phoConvTrkdz_x);
}; 

 void CopyphoConvTrkdz_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkdz_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkdz_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkdz_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkdz_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdz_x->push_back( IN::phoConvTrkdz_x->at(index) ); 
 }; 

 void ClearOutputphoConvTrkdz_x( std::string  prefix ) { 

    std::string my_name = "phoConvTrkdz_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkdz_x, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdz_x->clear(); 
 }; 

 void CopyphoConvTrkdz_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkdz_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkdz_y = std::vector<float>(*IN::phoConvTrkdz_y);
}; 

 void CopyphoConvTrkdz_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkdz_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkdz_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkdz_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkdz_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdz_y->push_back( IN::phoConvTrkdz_y->at(index) ); 
 }; 

 void ClearOutputphoConvTrkdz_y( std::string  prefix ) { 

    std::string my_name = "phoConvTrkdz_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkdz_y, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdz_y->clear(); 
 }; 

 void CopyphoConvTrkdzErr_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkdzErr_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkdzErr_x = std::vector<float>(*IN::phoConvTrkdzErr_x);
}; 

 void CopyphoConvTrkdzErr_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkdzErr_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkdzErr_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkdzErr_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkdzErr_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdzErr_x->push_back( IN::phoConvTrkdzErr_x->at(index) ); 
 }; 

 void ClearOutputphoConvTrkdzErr_x( std::string  prefix ) { 

    std::string my_name = "phoConvTrkdzErr_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkdzErr_x, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdzErr_x->clear(); 
 }; 

 void CopyphoConvTrkdzErr_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvTrkdzErr_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvTrkdzErr_y = std::vector<float>(*IN::phoConvTrkdzErr_y);
}; 

 void CopyphoConvTrkdzErr_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvTrkdzErr_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvTrkdzErr_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvTrkdzErr_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvTrkdzErr_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdzErr_y->push_back( IN::phoConvTrkdzErr_y->at(index) ); 
 }; 

 void ClearOutputphoConvTrkdzErr_y( std::string  prefix ) { 

    std::string my_name = "phoConvTrkdzErr_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvTrkdzErr_y, prefix = " << prefix << std::endl; 
     OUT::phoConvTrkdzErr_y->clear(); 
 }; 

 void CopyphoConvChi2InToOut( std::string prefix ) { 

    std::string my_name = "phoConvChi2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvChi2 = std::vector<float>(*IN::phoConvChi2);
}; 

 void CopyphoConvChi2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvChi2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvChi2->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvChi2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvChi2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvChi2->push_back( IN::phoConvChi2->at(index) ); 
 }; 

 void ClearOutputphoConvChi2( std::string  prefix ) { 

    std::string my_name = "phoConvChi2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvChi2, prefix = " << prefix << std::endl; 
     OUT::phoConvChi2->clear(); 
 }; 

 void CopyphoConvChi2ProbInToOut( std::string prefix ) { 

    std::string my_name = "phoConvChi2Prob";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvChi2Prob = std::vector<float>(*IN::phoConvChi2Prob);
}; 

 void CopyphoConvChi2ProbInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvChi2Prob";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvChi2Prob->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvChi2Prob" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvChi2Prob" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvChi2Prob->push_back( IN::phoConvChi2Prob->at(index) ); 
 }; 

 void ClearOutputphoConvChi2Prob( std::string  prefix ) { 

    std::string my_name = "phoConvChi2Prob";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvChi2Prob, prefix = " << prefix << std::endl; 
     OUT::phoConvChi2Prob->clear(); 
 }; 

 void CopyphoConvNTrksInToOut( std::string prefix ) { 

    std::string my_name = "phoConvNTrks";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvNTrks = std::vector<int>(*IN::phoConvNTrks);
}; 

 void CopyphoConvNTrksInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvNTrks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvNTrks->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvNTrks" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvNTrks" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvNTrks->push_back( IN::phoConvNTrks->at(index) ); 
 }; 

 void ClearOutputphoConvNTrks( std::string  prefix ) { 

    std::string my_name = "phoConvNTrks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvNTrks, prefix = " << prefix << std::endl; 
     OUT::phoConvNTrks->clear(); 
 }; 

 void CopyphoConvCharge1InToOut( std::string prefix ) { 

    std::string my_name = "phoConvCharge1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvCharge1 = std::vector<float>(*IN::phoConvCharge1);
}; 

 void CopyphoConvCharge1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvCharge1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvCharge1->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvCharge1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvCharge1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvCharge1->push_back( IN::phoConvCharge1->at(index) ); 
 }; 

 void ClearOutputphoConvCharge1( std::string  prefix ) { 

    std::string my_name = "phoConvCharge1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvCharge1, prefix = " << prefix << std::endl; 
     OUT::phoConvCharge1->clear(); 
 }; 

 void CopyphoConvCharge2InToOut( std::string prefix ) { 

    std::string my_name = "phoConvCharge2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvCharge2 = std::vector<float>(*IN::phoConvCharge2);
}; 

 void CopyphoConvCharge2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvCharge2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvCharge2->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvCharge2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvCharge2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvCharge2->push_back( IN::phoConvCharge2->at(index) ); 
 }; 

 void ClearOutputphoConvCharge2( std::string  prefix ) { 

    std::string my_name = "phoConvCharge2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvCharge2, prefix = " << prefix << std::endl; 
     OUT::phoConvCharge2->clear(); 
 }; 

 void CopyphoConvValidVtxInToOut( std::string prefix ) { 

    std::string my_name = "phoConvValidVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvValidVtx = std::vector<int>(*IN::phoConvValidVtx);
}; 

 void CopyphoConvValidVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvValidVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvValidVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvValidVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvValidVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvValidVtx->push_back( IN::phoConvValidVtx->at(index) ); 
 }; 

 void ClearOutputphoConvValidVtx( std::string  prefix ) { 

    std::string my_name = "phoConvValidVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvValidVtx, prefix = " << prefix << std::endl; 
     OUT::phoConvValidVtx->clear(); 
 }; 

 void CopyphoConvLikeLihoodInToOut( std::string prefix ) { 

    std::string my_name = "phoConvLikeLihood";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvLikeLihood = std::vector<float>(*IN::phoConvLikeLihood);
}; 

 void CopyphoConvLikeLihoodInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvLikeLihood";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvLikeLihood->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvLikeLihood" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvLikeLihood" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvLikeLihood->push_back( IN::phoConvLikeLihood->at(index) ); 
 }; 

 void ClearOutputphoConvLikeLihood( std::string  prefix ) { 

    std::string my_name = "phoConvLikeLihood";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvLikeLihood, prefix = " << prefix << std::endl; 
     OUT::phoConvLikeLihood->clear(); 
 }; 

 void CopyphoConvP4_0InToOut( std::string prefix ) { 

    std::string my_name = "phoConvP4_0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvP4_0 = std::vector<float>(*IN::phoConvP4_0);
}; 

 void CopyphoConvP4_0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvP4_0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvP4_0->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvP4_0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvP4_0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvP4_0->push_back( IN::phoConvP4_0->at(index) ); 
 }; 

 void ClearOutputphoConvP4_0( std::string  prefix ) { 

    std::string my_name = "phoConvP4_0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvP4_0, prefix = " << prefix << std::endl; 
     OUT::phoConvP4_0->clear(); 
 }; 

 void CopyphoConvP4_1InToOut( std::string prefix ) { 

    std::string my_name = "phoConvP4_1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvP4_1 = std::vector<float>(*IN::phoConvP4_1);
}; 

 void CopyphoConvP4_1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvP4_1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvP4_1->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvP4_1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvP4_1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvP4_1->push_back( IN::phoConvP4_1->at(index) ); 
 }; 

 void ClearOutputphoConvP4_1( std::string  prefix ) { 

    std::string my_name = "phoConvP4_1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvP4_1, prefix = " << prefix << std::endl; 
     OUT::phoConvP4_1->clear(); 
 }; 

 void CopyphoConvP4_2InToOut( std::string prefix ) { 

    std::string my_name = "phoConvP4_2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvP4_2 = std::vector<float>(*IN::phoConvP4_2);
}; 

 void CopyphoConvP4_2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvP4_2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvP4_2->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvP4_2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvP4_2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvP4_2->push_back( IN::phoConvP4_2->at(index) ); 
 }; 

 void ClearOutputphoConvP4_2( std::string  prefix ) { 

    std::string my_name = "phoConvP4_2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvP4_2, prefix = " << prefix << std::endl; 
     OUT::phoConvP4_2->clear(); 
 }; 

 void CopyphoConvP4_3InToOut( std::string prefix ) { 

    std::string my_name = "phoConvP4_3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvP4_3 = std::vector<float>(*IN::phoConvP4_3);
}; 

 void CopyphoConvP4_3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvP4_3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvP4_3->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvP4_3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvP4_3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvP4_3->push_back( IN::phoConvP4_3->at(index) ); 
 }; 

 void ClearOutputphoConvP4_3( std::string  prefix ) { 

    std::string my_name = "phoConvP4_3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvP4_3, prefix = " << prefix << std::endl; 
     OUT::phoConvP4_3->clear(); 
 }; 

 void CopyphoConvVtx_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvVtx_x = std::vector<float>(*IN::phoConvVtx_x);
}; 

 void CopyphoConvVtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvVtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvVtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvVtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvVtx_x->push_back( IN::phoConvVtx_x->at(index) ); 
 }; 

 void ClearOutputphoConvVtx_x( std::string  prefix ) { 

    std::string my_name = "phoConvVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvVtx_x, prefix = " << prefix << std::endl; 
     OUT::phoConvVtx_x->clear(); 
 }; 

 void CopyphoConvVtx_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvVtx_y = std::vector<float>(*IN::phoConvVtx_y);
}; 

 void CopyphoConvVtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvVtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvVtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvVtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvVtx_y->push_back( IN::phoConvVtx_y->at(index) ); 
 }; 

 void ClearOutputphoConvVtx_y( std::string  prefix ) { 

    std::string my_name = "phoConvVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvVtx_y, prefix = " << prefix << std::endl; 
     OUT::phoConvVtx_y->clear(); 
 }; 

 void CopyphoConvVtx_zInToOut( std::string prefix ) { 

    std::string my_name = "phoConvVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvVtx_z = std::vector<float>(*IN::phoConvVtx_z);
}; 

 void CopyphoConvVtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvVtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvVtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvVtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvVtx_z->push_back( IN::phoConvVtx_z->at(index) ); 
 }; 

 void ClearOutputphoConvVtx_z( std::string  prefix ) { 

    std::string my_name = "phoConvVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvVtx_z, prefix = " << prefix << std::endl; 
     OUT::phoConvVtx_z->clear(); 
 }; 

 void CopyphoConvVtxErr_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvVtxErr_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvVtxErr_x = std::vector<float>(*IN::phoConvVtxErr_x);
}; 

 void CopyphoConvVtxErr_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvVtxErr_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvVtxErr_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvVtxErr_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvVtxErr_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvVtxErr_x->push_back( IN::phoConvVtxErr_x->at(index) ); 
 }; 

 void ClearOutputphoConvVtxErr_x( std::string  prefix ) { 

    std::string my_name = "phoConvVtxErr_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvVtxErr_x, prefix = " << prefix << std::endl; 
     OUT::phoConvVtxErr_x->clear(); 
 }; 

 void CopyphoConvVtxErr_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvVtxErr_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvVtxErr_y = std::vector<float>(*IN::phoConvVtxErr_y);
}; 

 void CopyphoConvVtxErr_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvVtxErr_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvVtxErr_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvVtxErr_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvVtxErr_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvVtxErr_y->push_back( IN::phoConvVtxErr_y->at(index) ); 
 }; 

 void ClearOutputphoConvVtxErr_y( std::string  prefix ) { 

    std::string my_name = "phoConvVtxErr_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvVtxErr_y, prefix = " << prefix << std::endl; 
     OUT::phoConvVtxErr_y->clear(); 
 }; 

 void CopyphoConvVtxErr_zInToOut( std::string prefix ) { 

    std::string my_name = "phoConvVtxErr_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvVtxErr_z = std::vector<float>(*IN::phoConvVtxErr_z);
}; 

 void CopyphoConvVtxErr_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvVtxErr_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvVtxErr_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvVtxErr_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvVtxErr_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvVtxErr_z->push_back( IN::phoConvVtxErr_z->at(index) ); 
 }; 

 void ClearOutputphoConvVtxErr_z( std::string  prefix ) { 

    std::string my_name = "phoConvVtxErr_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvVtxErr_z, prefix = " << prefix << std::endl; 
     OUT::phoConvVtxErr_z->clear(); 
 }; 

 void CopyphoConvPairMomentum_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvPairMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvPairMomentum_x = std::vector<float>(*IN::phoConvPairMomentum_x);
}; 

 void CopyphoConvPairMomentum_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvPairMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvPairMomentum_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvPairMomentum_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvPairMomentum_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvPairMomentum_x->push_back( IN::phoConvPairMomentum_x->at(index) ); 
 }; 

 void ClearOutputphoConvPairMomentum_x( std::string  prefix ) { 

    std::string my_name = "phoConvPairMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvPairMomentum_x, prefix = " << prefix << std::endl; 
     OUT::phoConvPairMomentum_x->clear(); 
 }; 

 void CopyphoConvPairMomentum_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvPairMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvPairMomentum_y = std::vector<float>(*IN::phoConvPairMomentum_y);
}; 

 void CopyphoConvPairMomentum_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvPairMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvPairMomentum_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvPairMomentum_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvPairMomentum_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvPairMomentum_y->push_back( IN::phoConvPairMomentum_y->at(index) ); 
 }; 

 void ClearOutputphoConvPairMomentum_y( std::string  prefix ) { 

    std::string my_name = "phoConvPairMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvPairMomentum_y, prefix = " << prefix << std::endl; 
     OUT::phoConvPairMomentum_y->clear(); 
 }; 

 void CopyphoConvPairMomentum_zInToOut( std::string prefix ) { 

    std::string my_name = "phoConvPairMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvPairMomentum_z = std::vector<float>(*IN::phoConvPairMomentum_z);
}; 

 void CopyphoConvPairMomentum_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvPairMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvPairMomentum_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvPairMomentum_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvPairMomentum_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvPairMomentum_z->push_back( IN::phoConvPairMomentum_z->at(index) ); 
 }; 

 void ClearOutputphoConvPairMomentum_z( std::string  prefix ) { 

    std::string my_name = "phoConvPairMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvPairMomentum_z, prefix = " << prefix << std::endl; 
     OUT::phoConvPairMomentum_z->clear(); 
 }; 

 void CopyphoConvRefittedMomentum_xInToOut( std::string prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvRefittedMomentum_x = std::vector<float>(*IN::phoConvRefittedMomentum_x);
}; 

 void CopyphoConvRefittedMomentum_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvRefittedMomentum_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvRefittedMomentum_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvRefittedMomentum_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvRefittedMomentum_x->push_back( IN::phoConvRefittedMomentum_x->at(index) ); 
 }; 

 void ClearOutputphoConvRefittedMomentum_x( std::string  prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvRefittedMomentum_x, prefix = " << prefix << std::endl; 
     OUT::phoConvRefittedMomentum_x->clear(); 
 }; 

 void CopyphoConvRefittedMomentum_yInToOut( std::string prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvRefittedMomentum_y = std::vector<float>(*IN::phoConvRefittedMomentum_y);
}; 

 void CopyphoConvRefittedMomentum_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvRefittedMomentum_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvRefittedMomentum_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvRefittedMomentum_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvRefittedMomentum_y->push_back( IN::phoConvRefittedMomentum_y->at(index) ); 
 }; 

 void ClearOutputphoConvRefittedMomentum_y( std::string  prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvRefittedMomentum_y, prefix = " << prefix << std::endl; 
     OUT::phoConvRefittedMomentum_y->clear(); 
 }; 

 void CopyphoConvRefittedMomentum_zInToOut( std::string prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoConvRefittedMomentum_z = std::vector<float>(*IN::phoConvRefittedMomentum_z);
}; 

 void CopyphoConvRefittedMomentum_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoConvRefittedMomentum_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoConvRefittedMomentum_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoConvRefittedMomentum_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoConvRefittedMomentum_z->push_back( IN::phoConvRefittedMomentum_z->at(index) ); 
 }; 

 void ClearOutputphoConvRefittedMomentum_z( std::string  prefix ) { 

    std::string my_name = "phoConvRefittedMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoConvRefittedMomentum_z, prefix = " << prefix << std::endl; 
     OUT::phoConvRefittedMomentum_z->clear(); 
 }; 

 void CopySingleLegConvInToOut( std::string prefix ) { 

    std::string my_name = "SingleLegConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::SingleLegConv = std::vector<int>(*IN::SingleLegConv);
}; 

 void CopySingleLegConvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "SingleLegConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::SingleLegConv->size() ) {
         std::cout << "Vector size exceeded for branch IN::SingleLegConv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible SingleLegConv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::SingleLegConv->push_back( IN::SingleLegConv->at(index) ); 
 }; 

 void ClearOutputSingleLegConv( std::string  prefix ) { 

    std::string my_name = "SingleLegConv";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible SingleLegConv, prefix = " << prefix << std::endl; 
     OUT::SingleLegConv->clear(); 
 }; 

 void CopyphoPFConvVtx_xInToOut( std::string prefix ) { 

    std::string my_name = "phoPFConvVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFConvVtx_x = std::vector<std::vector<float> >(*IN::phoPFConvVtx_x);
}; 

 void CopyphoPFConvVtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFConvVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFConvVtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFConvVtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFConvVtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFConvVtx_x->push_back( IN::phoPFConvVtx_x->at(index) ); 
 }; 

 void ClearOutputphoPFConvVtx_x( std::string  prefix ) { 

    std::string my_name = "phoPFConvVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFConvVtx_x, prefix = " << prefix << std::endl; 
     OUT::phoPFConvVtx_x->clear(); 
 }; 

 void CopyphoPFConvVtx_yInToOut( std::string prefix ) { 

    std::string my_name = "phoPFConvVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFConvVtx_y = std::vector<std::vector<float> >(*IN::phoPFConvVtx_y);
}; 

 void CopyphoPFConvVtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFConvVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFConvVtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFConvVtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFConvVtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFConvVtx_y->push_back( IN::phoPFConvVtx_y->at(index) ); 
 }; 

 void ClearOutputphoPFConvVtx_y( std::string  prefix ) { 

    std::string my_name = "phoPFConvVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFConvVtx_y, prefix = " << prefix << std::endl; 
     OUT::phoPFConvVtx_y->clear(); 
 }; 

 void CopyphoPFConvVtx_zInToOut( std::string prefix ) { 

    std::string my_name = "phoPFConvVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFConvVtx_z = std::vector<std::vector<float> >(*IN::phoPFConvVtx_z);
}; 

 void CopyphoPFConvVtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFConvVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFConvVtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFConvVtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFConvVtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFConvVtx_z->push_back( IN::phoPFConvVtx_z->at(index) ); 
 }; 

 void ClearOutputphoPFConvVtx_z( std::string  prefix ) { 

    std::string my_name = "phoPFConvVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFConvVtx_z, prefix = " << prefix << std::endl; 
     OUT::phoPFConvVtx_z->clear(); 
 }; 

 void CopyphoPFConvMom_xInToOut( std::string prefix ) { 

    std::string my_name = "phoPFConvMom_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFConvMom_x = std::vector<std::vector<float> >(*IN::phoPFConvMom_x);
}; 

 void CopyphoPFConvMom_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFConvMom_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFConvMom_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFConvMom_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFConvMom_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFConvMom_x->push_back( IN::phoPFConvMom_x->at(index) ); 
 }; 

 void ClearOutputphoPFConvMom_x( std::string  prefix ) { 

    std::string my_name = "phoPFConvMom_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFConvMom_x, prefix = " << prefix << std::endl; 
     OUT::phoPFConvMom_x->clear(); 
 }; 

 void CopyphoPFConvMom_yInToOut( std::string prefix ) { 

    std::string my_name = "phoPFConvMom_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFConvMom_y = std::vector<std::vector<float> >(*IN::phoPFConvMom_y);
}; 

 void CopyphoPFConvMom_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFConvMom_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFConvMom_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFConvMom_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFConvMom_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFConvMom_y->push_back( IN::phoPFConvMom_y->at(index) ); 
 }; 

 void ClearOutputphoPFConvMom_y( std::string  prefix ) { 

    std::string my_name = "phoPFConvMom_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFConvMom_y, prefix = " << prefix << std::endl; 
     OUT::phoPFConvMom_y->clear(); 
 }; 

 void CopyphoPFConvMom_zInToOut( std::string prefix ) { 

    std::string my_name = "phoPFConvMom_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoPFConvMom_z = std::vector<std::vector<float> >(*IN::phoPFConvMom_z);
}; 

 void CopyphoPFConvMom_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoPFConvMom_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoPFConvMom_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoPFConvMom_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoPFConvMom_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoPFConvMom_z->push_back( IN::phoPFConvMom_z->at(index) ); 
 }; 

 void ClearOutputphoPFConvMom_z( std::string  prefix ) { 

    std::string my_name = "phoPFConvMom_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoPFConvMom_z, prefix = " << prefix << std::endl; 
     OUT::phoPFConvMom_z->clear(); 
 }; 

 void CopyphoESEffSigmaRR_xInToOut( std::string prefix ) { 

    std::string my_name = "phoESEffSigmaRR_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoESEffSigmaRR_x = std::vector<float>(*IN::phoESEffSigmaRR_x);
}; 

 void CopyphoESEffSigmaRR_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoESEffSigmaRR_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoESEffSigmaRR_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoESEffSigmaRR_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoESEffSigmaRR_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoESEffSigmaRR_x->push_back( IN::phoESEffSigmaRR_x->at(index) ); 
 }; 

 void ClearOutputphoESEffSigmaRR_x( std::string  prefix ) { 

    std::string my_name = "phoESEffSigmaRR_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoESEffSigmaRR_x, prefix = " << prefix << std::endl; 
     OUT::phoESEffSigmaRR_x->clear(); 
 }; 

 void CopyphoESEffSigmaRR_yInToOut( std::string prefix ) { 

    std::string my_name = "phoESEffSigmaRR_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoESEffSigmaRR_y = std::vector<float>(*IN::phoESEffSigmaRR_y);
}; 

 void CopyphoESEffSigmaRR_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoESEffSigmaRR_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoESEffSigmaRR_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoESEffSigmaRR_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoESEffSigmaRR_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoESEffSigmaRR_y->push_back( IN::phoESEffSigmaRR_y->at(index) ); 
 }; 

 void ClearOutputphoESEffSigmaRR_y( std::string  prefix ) { 

    std::string my_name = "phoESEffSigmaRR_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoESEffSigmaRR_y, prefix = " << prefix << std::endl; 
     OUT::phoESEffSigmaRR_y->clear(); 
 }; 

 void CopyphoESEffSigmaRR_zInToOut( std::string prefix ) { 

    std::string my_name = "phoESEffSigmaRR_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::phoESEffSigmaRR_z = std::vector<float>(*IN::phoESEffSigmaRR_z);
}; 

 void CopyphoESEffSigmaRR_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "phoESEffSigmaRR_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::phoESEffSigmaRR_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::phoESEffSigmaRR_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible phoESEffSigmaRR_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::phoESEffSigmaRR_z->push_back( IN::phoESEffSigmaRR_z->at(index) ); 
 }; 

 void ClearOutputphoESEffSigmaRR_z( std::string  prefix ) { 

    std::string my_name = "phoESEffSigmaRR_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible phoESEffSigmaRR_z, prefix = " << prefix << std::endl; 
     OUT::phoESEffSigmaRR_z->clear(); 
 }; 

 void CopynMuInToOut( std::string prefix ) { 

    std::string my_name = "nMu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nMu = IN::nMu;
}; 

 void CopymuTrgInToOut( std::string prefix ) { 

    std::string my_name = "muTrg";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muTrg = std::vector<unsigned long>(*IN::muTrg);
}; 

 void CopymuTrgInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muTrg->size() ) {
         std::cout << "Vector size exceeded for branch IN::muTrg" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muTrg" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muTrg->push_back( IN::muTrg->at(index) ); 
 }; 

 void ClearOutputmuTrg( std::string  prefix ) { 

    std::string my_name = "muTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muTrg, prefix = " << prefix << std::endl; 
     OUT::muTrg->clear(); 
 }; 

 void CopymuEtaInToOut( std::string prefix ) { 

    std::string my_name = "muEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muEta = std::vector<float>(*IN::muEta);
}; 

 void CopymuEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::muEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muEta->push_back( IN::muEta->at(index) ); 
 }; 

 void ClearOutputmuEta( std::string  prefix ) { 

    std::string my_name = "muEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muEta, prefix = " << prefix << std::endl; 
     OUT::muEta->clear(); 
 }; 

 void CopymuPhiInToOut( std::string prefix ) { 

    std::string my_name = "muPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPhi = std::vector<float>(*IN::muPhi);
}; 

 void CopymuPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPhi->push_back( IN::muPhi->at(index) ); 
 }; 

 void ClearOutputmuPhi( std::string  prefix ) { 

    std::string my_name = "muPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPhi, prefix = " << prefix << std::endl; 
     OUT::muPhi->clear(); 
 }; 

 void CopymuChargeInToOut( std::string prefix ) { 

    std::string my_name = "muCharge";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muCharge = std::vector<int>(*IN::muCharge);
}; 

 void CopymuChargeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muCharge->size() ) {
         std::cout << "Vector size exceeded for branch IN::muCharge" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muCharge" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muCharge->push_back( IN::muCharge->at(index) ); 
 }; 

 void ClearOutputmuCharge( std::string  prefix ) { 

    std::string my_name = "muCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muCharge, prefix = " << prefix << std::endl; 
     OUT::muCharge->clear(); 
 }; 

 void CopymuPtInToOut( std::string prefix ) { 

    std::string my_name = "muPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPt = std::vector<float>(*IN::muPt);
}; 

 void CopymuPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPt->push_back( IN::muPt->at(index) ); 
 }; 

 void ClearOutputmuPt( std::string  prefix ) { 

    std::string my_name = "muPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPt, prefix = " << prefix << std::endl; 
     OUT::muPt->clear(); 
 }; 

 void CopymuPzInToOut( std::string prefix ) { 

    std::string my_name = "muPz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPz = std::vector<float>(*IN::muPz);
}; 

 void CopymuPzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPz->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPz->push_back( IN::muPz->at(index) ); 
 }; 

 void ClearOutputmuPz( std::string  prefix ) { 

    std::string my_name = "muPz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPz, prefix = " << prefix << std::endl; 
     OUT::muPz->clear(); 
 }; 

 void CopymuVtx_xInToOut( std::string prefix ) { 

    std::string my_name = "muVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muVtx_x = std::vector<float>(*IN::muVtx_x);
}; 

 void CopymuVtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muVtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::muVtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muVtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muVtx_x->push_back( IN::muVtx_x->at(index) ); 
 }; 

 void ClearOutputmuVtx_x( std::string  prefix ) { 

    std::string my_name = "muVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muVtx_x, prefix = " << prefix << std::endl; 
     OUT::muVtx_x->clear(); 
 }; 

 void CopymuVtx_yInToOut( std::string prefix ) { 

    std::string my_name = "muVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muVtx_y = std::vector<float>(*IN::muVtx_y);
}; 

 void CopymuVtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muVtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::muVtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muVtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muVtx_y->push_back( IN::muVtx_y->at(index) ); 
 }; 

 void ClearOutputmuVtx_y( std::string  prefix ) { 

    std::string my_name = "muVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muVtx_y, prefix = " << prefix << std::endl; 
     OUT::muVtx_y->clear(); 
 }; 

 void CopymuVtx_zInToOut( std::string prefix ) { 

    std::string my_name = "muVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muVtx_z = std::vector<float>(*IN::muVtx_z);
}; 

 void CopymuVtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muVtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::muVtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muVtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muVtx_z->push_back( IN::muVtx_z->at(index) ); 
 }; 

 void ClearOutputmuVtx_z( std::string  prefix ) { 

    std::string my_name = "muVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muVtx_z, prefix = " << prefix << std::endl; 
     OUT::muVtx_z->clear(); 
 }; 

 void CopymuVtxGlb_xInToOut( std::string prefix ) { 

    std::string my_name = "muVtxGlb_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muVtxGlb_x = std::vector<float>(*IN::muVtxGlb_x);
}; 

 void CopymuVtxGlb_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muVtxGlb_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muVtxGlb_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::muVtxGlb_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muVtxGlb_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muVtxGlb_x->push_back( IN::muVtxGlb_x->at(index) ); 
 }; 

 void ClearOutputmuVtxGlb_x( std::string  prefix ) { 

    std::string my_name = "muVtxGlb_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muVtxGlb_x, prefix = " << prefix << std::endl; 
     OUT::muVtxGlb_x->clear(); 
 }; 

 void CopymuVtxGlb_yInToOut( std::string prefix ) { 

    std::string my_name = "muVtxGlb_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muVtxGlb_y = std::vector<float>(*IN::muVtxGlb_y);
}; 

 void CopymuVtxGlb_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muVtxGlb_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muVtxGlb_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::muVtxGlb_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muVtxGlb_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muVtxGlb_y->push_back( IN::muVtxGlb_y->at(index) ); 
 }; 

 void ClearOutputmuVtxGlb_y( std::string  prefix ) { 

    std::string my_name = "muVtxGlb_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muVtxGlb_y, prefix = " << prefix << std::endl; 
     OUT::muVtxGlb_y->clear(); 
 }; 

 void CopymuVtxGlb_zInToOut( std::string prefix ) { 

    std::string my_name = "muVtxGlb_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muVtxGlb_z = std::vector<float>(*IN::muVtxGlb_z);
}; 

 void CopymuVtxGlb_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muVtxGlb_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muVtxGlb_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::muVtxGlb_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muVtxGlb_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muVtxGlb_z->push_back( IN::muVtxGlb_z->at(index) ); 
 }; 

 void ClearOutputmuVtxGlb_z( std::string  prefix ) { 

    std::string my_name = "muVtxGlb_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muVtxGlb_z, prefix = " << prefix << std::endl; 
     OUT::muVtxGlb_z->clear(); 
 }; 

 void CopymucktPtInToOut( std::string prefix ) { 

    std::string my_name = "mucktPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mucktPt = std::vector<float>(*IN::mucktPt);
}; 

 void CopymucktPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mucktPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mucktPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::mucktPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mucktPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mucktPt->push_back( IN::mucktPt->at(index) ); 
 }; 

 void ClearOutputmucktPt( std::string  prefix ) { 

    std::string my_name = "mucktPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mucktPt, prefix = " << prefix << std::endl; 
     OUT::mucktPt->clear(); 
 }; 

 void CopymucktPtErrInToOut( std::string prefix ) { 

    std::string my_name = "mucktPtErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mucktPtErr = std::vector<float>(*IN::mucktPtErr);
}; 

 void CopymucktPtErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mucktPtErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mucktPtErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::mucktPtErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mucktPtErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mucktPtErr->push_back( IN::mucktPtErr->at(index) ); 
 }; 

 void ClearOutputmucktPtErr( std::string  prefix ) { 

    std::string my_name = "mucktPtErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mucktPtErr, prefix = " << prefix << std::endl; 
     OUT::mucktPtErr->clear(); 
 }; 

 void CopymucktEtaInToOut( std::string prefix ) { 

    std::string my_name = "mucktEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mucktEta = std::vector<float>(*IN::mucktEta);
}; 

 void CopymucktEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mucktEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mucktEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::mucktEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mucktEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mucktEta->push_back( IN::mucktEta->at(index) ); 
 }; 

 void ClearOutputmucktEta( std::string  prefix ) { 

    std::string my_name = "mucktEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mucktEta, prefix = " << prefix << std::endl; 
     OUT::mucktEta->clear(); 
 }; 

 void CopymucktPhiInToOut( std::string prefix ) { 

    std::string my_name = "mucktPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mucktPhi = std::vector<float>(*IN::mucktPhi);
}; 

 void CopymucktPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mucktPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mucktPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::mucktPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mucktPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mucktPhi->push_back( IN::mucktPhi->at(index) ); 
 }; 

 void ClearOutputmucktPhi( std::string  prefix ) { 

    std::string my_name = "mucktPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mucktPhi, prefix = " << prefix << std::endl; 
     OUT::mucktPhi->clear(); 
 }; 

 void CopymucktdxyInToOut( std::string prefix ) { 

    std::string my_name = "mucktdxy";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mucktdxy = std::vector<float>(*IN::mucktdxy);
}; 

 void CopymucktdxyInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mucktdxy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mucktdxy->size() ) {
         std::cout << "Vector size exceeded for branch IN::mucktdxy" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mucktdxy" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mucktdxy->push_back( IN::mucktdxy->at(index) ); 
 }; 

 void ClearOutputmucktdxy( std::string  prefix ) { 

    std::string my_name = "mucktdxy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mucktdxy, prefix = " << prefix << std::endl; 
     OUT::mucktdxy->clear(); 
 }; 

 void CopymucktdzInToOut( std::string prefix ) { 

    std::string my_name = "mucktdz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mucktdz = std::vector<float>(*IN::mucktdz);
}; 

 void CopymucktdzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mucktdz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mucktdz->size() ) {
         std::cout << "Vector size exceeded for branch IN::mucktdz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mucktdz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mucktdz->push_back( IN::mucktdz->at(index) ); 
 }; 

 void ClearOutputmucktdz( std::string  prefix ) { 

    std::string my_name = "mucktdz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mucktdz, prefix = " << prefix << std::endl; 
     OUT::mucktdz->clear(); 
 }; 

 void CopymuIsoTrkInToOut( std::string prefix ) { 

    std::string my_name = "muIsoTrk";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muIsoTrk = std::vector<float>(*IN::muIsoTrk);
}; 

 void CopymuIsoTrkInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muIsoTrk";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muIsoTrk->size() ) {
         std::cout << "Vector size exceeded for branch IN::muIsoTrk" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muIsoTrk" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muIsoTrk->push_back( IN::muIsoTrk->at(index) ); 
 }; 

 void ClearOutputmuIsoTrk( std::string  prefix ) { 

    std::string my_name = "muIsoTrk";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muIsoTrk, prefix = " << prefix << std::endl; 
     OUT::muIsoTrk->clear(); 
 }; 

 void CopymuIsoCaloInToOut( std::string prefix ) { 

    std::string my_name = "muIsoCalo";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muIsoCalo = std::vector<float>(*IN::muIsoCalo);
}; 

 void CopymuIsoCaloInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muIsoCalo";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muIsoCalo->size() ) {
         std::cout << "Vector size exceeded for branch IN::muIsoCalo" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muIsoCalo" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muIsoCalo->push_back( IN::muIsoCalo->at(index) ); 
 }; 

 void ClearOutputmuIsoCalo( std::string  prefix ) { 

    std::string my_name = "muIsoCalo";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muIsoCalo, prefix = " << prefix << std::endl; 
     OUT::muIsoCalo->clear(); 
 }; 

 void CopymuIsoEcalInToOut( std::string prefix ) { 

    std::string my_name = "muIsoEcal";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muIsoEcal = std::vector<float>(*IN::muIsoEcal);
}; 

 void CopymuIsoEcalInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muIsoEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muIsoEcal->size() ) {
         std::cout << "Vector size exceeded for branch IN::muIsoEcal" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muIsoEcal" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muIsoEcal->push_back( IN::muIsoEcal->at(index) ); 
 }; 

 void ClearOutputmuIsoEcal( std::string  prefix ) { 

    std::string my_name = "muIsoEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muIsoEcal, prefix = " << prefix << std::endl; 
     OUT::muIsoEcal->clear(); 
 }; 

 void CopymuIsoHcalInToOut( std::string prefix ) { 

    std::string my_name = "muIsoHcal";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muIsoHcal = std::vector<float>(*IN::muIsoHcal);
}; 

 void CopymuIsoHcalInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muIsoHcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muIsoHcal->size() ) {
         std::cout << "Vector size exceeded for branch IN::muIsoHcal" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muIsoHcal" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muIsoHcal->push_back( IN::muIsoHcal->at(index) ); 
 }; 

 void ClearOutputmuIsoHcal( std::string  prefix ) { 

    std::string my_name = "muIsoHcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muIsoHcal, prefix = " << prefix << std::endl; 
     OUT::muIsoHcal->clear(); 
 }; 

 void CopymuChi2NDFInToOut( std::string prefix ) { 

    std::string my_name = "muChi2NDF";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muChi2NDF = std::vector<float>(*IN::muChi2NDF);
}; 

 void CopymuChi2NDFInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muChi2NDF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muChi2NDF->size() ) {
         std::cout << "Vector size exceeded for branch IN::muChi2NDF" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muChi2NDF" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muChi2NDF->push_back( IN::muChi2NDF->at(index) ); 
 }; 

 void ClearOutputmuChi2NDF( std::string  prefix ) { 

    std::string my_name = "muChi2NDF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muChi2NDF, prefix = " << prefix << std::endl; 
     OUT::muChi2NDF->clear(); 
 }; 

 void CopymuInnerChi2NDFInToOut( std::string prefix ) { 

    std::string my_name = "muInnerChi2NDF";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerChi2NDF = std::vector<float>(*IN::muInnerChi2NDF);
}; 

 void CopymuInnerChi2NDFInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerChi2NDF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerChi2NDF->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerChi2NDF" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerChi2NDF" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerChi2NDF->push_back( IN::muInnerChi2NDF->at(index) ); 
 }; 

 void ClearOutputmuInnerChi2NDF( std::string  prefix ) { 

    std::string my_name = "muInnerChi2NDF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerChi2NDF, prefix = " << prefix << std::endl; 
     OUT::muInnerChi2NDF->clear(); 
 }; 

 void CopymuPFIsoR04_CHInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_CH";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_CH = std::vector<float>(*IN::muPFIsoR04_CH);
}; 

 void CopymuPFIsoR04_CHInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_CH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_CH->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_CH" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_CH" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_CH->push_back( IN::muPFIsoR04_CH->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_CH( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_CH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_CH, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_CH->clear(); 
 }; 

 void CopymuPFIsoR04_NHInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_NH";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_NH = std::vector<float>(*IN::muPFIsoR04_NH);
}; 

 void CopymuPFIsoR04_NHInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_NH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_NH->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_NH" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_NH" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_NH->push_back( IN::muPFIsoR04_NH->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_NH( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_NH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_NH, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_NH->clear(); 
 }; 

 void CopymuPFIsoR04_PhoInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_Pho";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_Pho = std::vector<float>(*IN::muPFIsoR04_Pho);
}; 

 void CopymuPFIsoR04_PhoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_Pho";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_Pho->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_Pho" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_Pho" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_Pho->push_back( IN::muPFIsoR04_Pho->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_Pho( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_Pho";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_Pho, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_Pho->clear(); 
 }; 

 void CopymuPFIsoR04_PUInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_PU";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_PU = std::vector<float>(*IN::muPFIsoR04_PU);
}; 

 void CopymuPFIsoR04_PUInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_PU";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_PU->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_PU" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_PU" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_PU->push_back( IN::muPFIsoR04_PU->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_PU( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_PU";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_PU, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_PU->clear(); 
 }; 

 void CopymuPFIsoR04_CPartInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_CPart";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_CPart = std::vector<float>(*IN::muPFIsoR04_CPart);
}; 

 void CopymuPFIsoR04_CPartInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_CPart";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_CPart->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_CPart" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_CPart" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_CPart->push_back( IN::muPFIsoR04_CPart->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_CPart( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_CPart";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_CPart, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_CPart->clear(); 
 }; 

 void CopymuPFIsoR04_NHHTInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_NHHT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_NHHT = std::vector<float>(*IN::muPFIsoR04_NHHT);
}; 

 void CopymuPFIsoR04_NHHTInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_NHHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_NHHT->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_NHHT" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_NHHT" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_NHHT->push_back( IN::muPFIsoR04_NHHT->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_NHHT( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_NHHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_NHHT, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_NHHT->clear(); 
 }; 

 void CopymuPFIsoR04_PhoHTInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR04_PhoHT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR04_PhoHT = std::vector<float>(*IN::muPFIsoR04_PhoHT);
}; 

 void CopymuPFIsoR04_PhoHTInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_PhoHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR04_PhoHT->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR04_PhoHT" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR04_PhoHT" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_PhoHT->push_back( IN::muPFIsoR04_PhoHT->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR04_PhoHT( std::string  prefix ) { 

    std::string my_name = "muPFIsoR04_PhoHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR04_PhoHT, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR04_PhoHT->clear(); 
 }; 

 void CopymuPFIsoR03_CHInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_CH";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_CH = std::vector<float>(*IN::muPFIsoR03_CH);
}; 

 void CopymuPFIsoR03_CHInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_CH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_CH->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_CH" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_CH" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_CH->push_back( IN::muPFIsoR03_CH->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_CH( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_CH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_CH, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_CH->clear(); 
 }; 

 void CopymuPFIsoR03_NHInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_NH";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_NH = std::vector<float>(*IN::muPFIsoR03_NH);
}; 

 void CopymuPFIsoR03_NHInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_NH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_NH->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_NH" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_NH" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_NH->push_back( IN::muPFIsoR03_NH->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_NH( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_NH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_NH, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_NH->clear(); 
 }; 

 void CopymuPFIsoR03_PhoInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_Pho";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_Pho = std::vector<float>(*IN::muPFIsoR03_Pho);
}; 

 void CopymuPFIsoR03_PhoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_Pho";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_Pho->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_Pho" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_Pho" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_Pho->push_back( IN::muPFIsoR03_Pho->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_Pho( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_Pho";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_Pho, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_Pho->clear(); 
 }; 

 void CopymuPFIsoR03_PUInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_PU";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_PU = std::vector<float>(*IN::muPFIsoR03_PU);
}; 

 void CopymuPFIsoR03_PUInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_PU";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_PU->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_PU" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_PU" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_PU->push_back( IN::muPFIsoR03_PU->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_PU( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_PU";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_PU, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_PU->clear(); 
 }; 

 void CopymuPFIsoR03_CPartInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_CPart";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_CPart = std::vector<float>(*IN::muPFIsoR03_CPart);
}; 

 void CopymuPFIsoR03_CPartInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_CPart";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_CPart->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_CPart" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_CPart" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_CPart->push_back( IN::muPFIsoR03_CPart->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_CPart( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_CPart";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_CPart, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_CPart->clear(); 
 }; 

 void CopymuPFIsoR03_NHHTInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_NHHT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_NHHT = std::vector<float>(*IN::muPFIsoR03_NHHT);
}; 

 void CopymuPFIsoR03_NHHTInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_NHHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_NHHT->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_NHHT" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_NHHT" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_NHHT->push_back( IN::muPFIsoR03_NHHT->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_NHHT( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_NHHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_NHHT, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_NHHT->clear(); 
 }; 

 void CopymuPFIsoR03_PhoHTInToOut( std::string prefix ) { 

    std::string my_name = "muPFIsoR03_PhoHT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muPFIsoR03_PhoHT = std::vector<float>(*IN::muPFIsoR03_PhoHT);
}; 

 void CopymuPFIsoR03_PhoHTInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_PhoHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muPFIsoR03_PhoHT->size() ) {
         std::cout << "Vector size exceeded for branch IN::muPFIsoR03_PhoHT" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muPFIsoR03_PhoHT" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_PhoHT->push_back( IN::muPFIsoR03_PhoHT->at(index) ); 
 }; 

 void ClearOutputmuPFIsoR03_PhoHT( std::string  prefix ) { 

    std::string my_name = "muPFIsoR03_PhoHT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muPFIsoR03_PhoHT, prefix = " << prefix << std::endl; 
     OUT::muPFIsoR03_PhoHT->clear(); 
 }; 

 void CopymuTypeInToOut( std::string prefix ) { 

    std::string my_name = "muType";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muType = std::vector<int>(*IN::muType);
}; 

 void CopymuTypeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muType";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muType->size() ) {
         std::cout << "Vector size exceeded for branch IN::muType" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muType" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muType->push_back( IN::muType->at(index) ); 
 }; 

 void ClearOutputmuType( std::string  prefix ) { 

    std::string my_name = "muType";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muType, prefix = " << prefix << std::endl; 
     OUT::muType->clear(); 
 }; 

 void CopymuD0InToOut( std::string prefix ) { 

    std::string my_name = "muD0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muD0 = std::vector<float>(*IN::muD0);
}; 

 void CopymuD0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muD0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muD0->size() ) {
         std::cout << "Vector size exceeded for branch IN::muD0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muD0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muD0->push_back( IN::muD0->at(index) ); 
 }; 

 void ClearOutputmuD0( std::string  prefix ) { 

    std::string my_name = "muD0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muD0, prefix = " << prefix << std::endl; 
     OUT::muD0->clear(); 
 }; 

 void CopymuDzInToOut( std::string prefix ) { 

    std::string my_name = "muDz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muDz = std::vector<float>(*IN::muDz);
}; 

 void CopymuDzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muDz->size() ) {
         std::cout << "Vector size exceeded for branch IN::muDz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muDz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muDz->push_back( IN::muDz->at(index) ); 
 }; 

 void ClearOutputmuDz( std::string  prefix ) { 

    std::string my_name = "muDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muDz, prefix = " << prefix << std::endl; 
     OUT::muDz->clear(); 
 }; 

 void CopymuD0GVInToOut( std::string prefix ) { 

    std::string my_name = "muD0GV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muD0GV = std::vector<float>(*IN::muD0GV);
}; 

 void CopymuD0GVInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muD0GV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muD0GV->size() ) {
         std::cout << "Vector size exceeded for branch IN::muD0GV" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muD0GV" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muD0GV->push_back( IN::muD0GV->at(index) ); 
 }; 

 void ClearOutputmuD0GV( std::string  prefix ) { 

    std::string my_name = "muD0GV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muD0GV, prefix = " << prefix << std::endl; 
     OUT::muD0GV->clear(); 
 }; 

 void CopymuDzGVInToOut( std::string prefix ) { 

    std::string my_name = "muDzGV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muDzGV = std::vector<float>(*IN::muDzGV);
}; 

 void CopymuDzGVInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muDzGV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muDzGV->size() ) {
         std::cout << "Vector size exceeded for branch IN::muDzGV" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muDzGV" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muDzGV->push_back( IN::muDzGV->at(index) ); 
 }; 

 void ClearOutputmuDzGV( std::string  prefix ) { 

    std::string my_name = "muDzGV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muDzGV, prefix = " << prefix << std::endl; 
     OUT::muDzGV->clear(); 
 }; 

 void CopymuD0VtxInToOut( std::string prefix ) { 

    std::string my_name = "muD0Vtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muD0Vtx = std::vector<std::vector<float> >(*IN::muD0Vtx);
}; 

 void CopymuD0VtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muD0Vtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muD0Vtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::muD0Vtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muD0Vtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muD0Vtx->push_back( IN::muD0Vtx->at(index) ); 
 }; 

 void ClearOutputmuD0Vtx( std::string  prefix ) { 

    std::string my_name = "muD0Vtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muD0Vtx, prefix = " << prefix << std::endl; 
     OUT::muD0Vtx->clear(); 
 }; 

 void CopymuDzVtxInToOut( std::string prefix ) { 

    std::string my_name = "muDzVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muDzVtx = std::vector<std::vector<float> >(*IN::muDzVtx);
}; 

 void CopymuDzVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muDzVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muDzVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::muDzVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muDzVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muDzVtx->push_back( IN::muDzVtx->at(index) ); 
 }; 

 void ClearOutputmuDzVtx( std::string  prefix ) { 

    std::string my_name = "muDzVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muDzVtx, prefix = " << prefix << std::endl; 
     OUT::muDzVtx->clear(); 
 }; 

 void CopymuInnerD0InToOut( std::string prefix ) { 

    std::string my_name = "muInnerD0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerD0 = std::vector<float>(*IN::muInnerD0);
}; 

 void CopymuInnerD0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerD0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerD0->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerD0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerD0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerD0->push_back( IN::muInnerD0->at(index) ); 
 }; 

 void ClearOutputmuInnerD0( std::string  prefix ) { 

    std::string my_name = "muInnerD0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerD0, prefix = " << prefix << std::endl; 
     OUT::muInnerD0->clear(); 
 }; 

 void CopymuInnerDzInToOut( std::string prefix ) { 

    std::string my_name = "muInnerDz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerDz = std::vector<float>(*IN::muInnerDz);
}; 

 void CopymuInnerDzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerDz->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerDz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerDz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerDz->push_back( IN::muInnerDz->at(index) ); 
 }; 

 void ClearOutputmuInnerDz( std::string  prefix ) { 

    std::string my_name = "muInnerDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerDz, prefix = " << prefix << std::endl; 
     OUT::muInnerDz->clear(); 
 }; 

 void CopymuInnerD0GVInToOut( std::string prefix ) { 

    std::string my_name = "muInnerD0GV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerD0GV = std::vector<float>(*IN::muInnerD0GV);
}; 

 void CopymuInnerD0GVInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerD0GV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerD0GV->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerD0GV" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerD0GV" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerD0GV->push_back( IN::muInnerD0GV->at(index) ); 
 }; 

 void ClearOutputmuInnerD0GV( std::string  prefix ) { 

    std::string my_name = "muInnerD0GV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerD0GV, prefix = " << prefix << std::endl; 
     OUT::muInnerD0GV->clear(); 
 }; 

 void CopymuInnerDzGVInToOut( std::string prefix ) { 

    std::string my_name = "muInnerDzGV";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerDzGV = std::vector<float>(*IN::muInnerDzGV);
}; 

 void CopymuInnerDzGVInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerDzGV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerDzGV->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerDzGV" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerDzGV" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerDzGV->push_back( IN::muInnerDzGV->at(index) ); 
 }; 

 void ClearOutputmuInnerDzGV( std::string  prefix ) { 

    std::string my_name = "muInnerDzGV";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerDzGV, prefix = " << prefix << std::endl; 
     OUT::muInnerDzGV->clear(); 
 }; 

 void CopymuInnerPtInToOut( std::string prefix ) { 

    std::string my_name = "muInnerPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerPt = std::vector<float>(*IN::muInnerPt);
}; 

 void CopymuInnerPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerPt->push_back( IN::muInnerPt->at(index) ); 
 }; 

 void ClearOutputmuInnerPt( std::string  prefix ) { 

    std::string my_name = "muInnerPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerPt, prefix = " << prefix << std::endl; 
     OUT::muInnerPt->clear(); 
 }; 

 void CopymuInnerPtErrInToOut( std::string prefix ) { 

    std::string my_name = "muInnerPtErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muInnerPtErr = std::vector<float>(*IN::muInnerPtErr);
}; 

 void CopymuInnerPtErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muInnerPtErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muInnerPtErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::muInnerPtErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muInnerPtErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muInnerPtErr->push_back( IN::muInnerPtErr->at(index) ); 
 }; 

 void ClearOutputmuInnerPtErr( std::string  prefix ) { 

    std::string my_name = "muInnerPtErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muInnerPtErr, prefix = " << prefix << std::endl; 
     OUT::muInnerPtErr->clear(); 
 }; 

 void CopymuNumberOfValidTrkLayersInToOut( std::string prefix ) { 

    std::string my_name = "muNumberOfValidTrkLayers";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muNumberOfValidTrkLayers = std::vector<int>(*IN::muNumberOfValidTrkLayers);
}; 

 void CopymuNumberOfValidTrkLayersInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muNumberOfValidTrkLayers";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muNumberOfValidTrkLayers->size() ) {
         std::cout << "Vector size exceeded for branch IN::muNumberOfValidTrkLayers" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muNumberOfValidTrkLayers" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidTrkLayers->push_back( IN::muNumberOfValidTrkLayers->at(index) ); 
 }; 

 void ClearOutputmuNumberOfValidTrkLayers( std::string  prefix ) { 

    std::string my_name = "muNumberOfValidTrkLayers";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muNumberOfValidTrkLayers, prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidTrkLayers->clear(); 
 }; 

 void CopymuNumberOfValidTrkHitsInToOut( std::string prefix ) { 

    std::string my_name = "muNumberOfValidTrkHits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muNumberOfValidTrkHits = std::vector<int>(*IN::muNumberOfValidTrkHits);
}; 

 void CopymuNumberOfValidTrkHitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muNumberOfValidTrkHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muNumberOfValidTrkHits->size() ) {
         std::cout << "Vector size exceeded for branch IN::muNumberOfValidTrkHits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muNumberOfValidTrkHits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidTrkHits->push_back( IN::muNumberOfValidTrkHits->at(index) ); 
 }; 

 void ClearOutputmuNumberOfValidTrkHits( std::string  prefix ) { 

    std::string my_name = "muNumberOfValidTrkHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muNumberOfValidTrkHits, prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidTrkHits->clear(); 
 }; 

 void CopymuNumberOfValidPixelLayersInToOut( std::string prefix ) { 

    std::string my_name = "muNumberOfValidPixelLayers";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muNumberOfValidPixelLayers = std::vector<int>(*IN::muNumberOfValidPixelLayers);
}; 

 void CopymuNumberOfValidPixelLayersInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muNumberOfValidPixelLayers";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muNumberOfValidPixelLayers->size() ) {
         std::cout << "Vector size exceeded for branch IN::muNumberOfValidPixelLayers" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muNumberOfValidPixelLayers" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidPixelLayers->push_back( IN::muNumberOfValidPixelLayers->at(index) ); 
 }; 

 void ClearOutputmuNumberOfValidPixelLayers( std::string  prefix ) { 

    std::string my_name = "muNumberOfValidPixelLayers";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muNumberOfValidPixelLayers, prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidPixelLayers->clear(); 
 }; 

 void CopymuNumberOfValidPixelHitsInToOut( std::string prefix ) { 

    std::string my_name = "muNumberOfValidPixelHits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muNumberOfValidPixelHits = std::vector<int>(*IN::muNumberOfValidPixelHits);
}; 

 void CopymuNumberOfValidPixelHitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muNumberOfValidPixelHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muNumberOfValidPixelHits->size() ) {
         std::cout << "Vector size exceeded for branch IN::muNumberOfValidPixelHits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muNumberOfValidPixelHits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidPixelHits->push_back( IN::muNumberOfValidPixelHits->at(index) ); 
 }; 

 void ClearOutputmuNumberOfValidPixelHits( std::string  prefix ) { 

    std::string my_name = "muNumberOfValidPixelHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muNumberOfValidPixelHits, prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidPixelHits->clear(); 
 }; 

 void CopymuNumberOfValidMuonHitsInToOut( std::string prefix ) { 

    std::string my_name = "muNumberOfValidMuonHits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muNumberOfValidMuonHits = std::vector<int>(*IN::muNumberOfValidMuonHits);
}; 

 void CopymuNumberOfValidMuonHitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muNumberOfValidMuonHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muNumberOfValidMuonHits->size() ) {
         std::cout << "Vector size exceeded for branch IN::muNumberOfValidMuonHits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muNumberOfValidMuonHits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidMuonHits->push_back( IN::muNumberOfValidMuonHits->at(index) ); 
 }; 

 void ClearOutputmuNumberOfValidMuonHits( std::string  prefix ) { 

    std::string my_name = "muNumberOfValidMuonHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muNumberOfValidMuonHits, prefix = " << prefix << std::endl; 
     OUT::muNumberOfValidMuonHits->clear(); 
 }; 

 void CopymuStationsInToOut( std::string prefix ) { 

    std::string my_name = "muStations";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muStations = std::vector<int>(*IN::muStations);
}; 

 void CopymuStationsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muStations";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muStations->size() ) {
         std::cout << "Vector size exceeded for branch IN::muStations" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muStations" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muStations->push_back( IN::muStations->at(index) ); 
 }; 

 void ClearOutputmuStations( std::string  prefix ) { 

    std::string my_name = "muStations";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muStations, prefix = " << prefix << std::endl; 
     OUT::muStations->clear(); 
 }; 

 void CopymuChambersInToOut( std::string prefix ) { 

    std::string my_name = "muChambers";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muChambers = std::vector<int>(*IN::muChambers);
}; 

 void CopymuChambersInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muChambers";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muChambers->size() ) {
         std::cout << "Vector size exceeded for branch IN::muChambers" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muChambers" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muChambers->push_back( IN::muChambers->at(index) ); 
 }; 

 void ClearOutputmuChambers( std::string  prefix ) { 

    std::string my_name = "muChambers";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muChambers, prefix = " << prefix << std::endl; 
     OUT::muChambers->clear(); 
 }; 

 void CopymuIP3DInToOut( std::string prefix ) { 

    std::string my_name = "muIP3D";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muIP3D = std::vector<float>(*IN::muIP3D);
}; 

 void CopymuIP3DInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muIP3D";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muIP3D->size() ) {
         std::cout << "Vector size exceeded for branch IN::muIP3D" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muIP3D" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muIP3D->push_back( IN::muIP3D->at(index) ); 
 }; 

 void ClearOutputmuIP3D( std::string  prefix ) { 

    std::string my_name = "muIP3D";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muIP3D, prefix = " << prefix << std::endl; 
     OUT::muIP3D->clear(); 
 }; 

 void CopymuIP3DErrInToOut( std::string prefix ) { 

    std::string my_name = "muIP3DErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::muIP3DErr = std::vector<float>(*IN::muIP3DErr);
}; 

 void CopymuIP3DErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "muIP3DErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::muIP3DErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::muIP3DErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible muIP3DErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::muIP3DErr->push_back( IN::muIP3DErr->at(index) ); 
 }; 

 void ClearOutputmuIP3DErr( std::string  prefix ) { 

    std::string my_name = "muIP3DErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible muIP3DErr, prefix = " << prefix << std::endl; 
     OUT::muIP3DErr->clear(); 
 }; 

 void CopynTauInToOut( std::string prefix ) { 

    std::string my_name = "nTau";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nTau = IN::nTau;
}; 

 void CopytauDecayModeFindingInToOut( std::string prefix ) { 

    std::string my_name = "tauDecayModeFinding";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauDecayModeFinding = std::vector<bool>(*IN::tauDecayModeFinding);
}; 

 void CopytauDecayModeFindingInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauDecayModeFinding";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauDecayModeFinding->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauDecayModeFinding" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauDecayModeFinding" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauDecayModeFinding->push_back( IN::tauDecayModeFinding->at(index) ); 
 }; 

 void ClearOutputtauDecayModeFinding( std::string  prefix ) { 

    std::string my_name = "tauDecayModeFinding";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauDecayModeFinding, prefix = " << prefix << std::endl; 
     OUT::tauDecayModeFinding->clear(); 
 }; 

 void CopytauAgainstElectronLooseMVA3InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstElectronLooseMVA3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstElectronLooseMVA3 = std::vector<bool>(*IN::tauAgainstElectronLooseMVA3);
}; 

 void CopytauAgainstElectronLooseMVA3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronLooseMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstElectronLooseMVA3->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstElectronLooseMVA3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstElectronLooseMVA3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronLooseMVA3->push_back( IN::tauAgainstElectronLooseMVA3->at(index) ); 
 }; 

 void ClearOutputtauAgainstElectronLooseMVA3( std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronLooseMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstElectronLooseMVA3, prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronLooseMVA3->clear(); 
 }; 

 void CopytauAgainstElectronMediumMVA3InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstElectronMediumMVA3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstElectronMediumMVA3 = std::vector<bool>(*IN::tauAgainstElectronMediumMVA3);
}; 

 void CopytauAgainstElectronMediumMVA3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronMediumMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstElectronMediumMVA3->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstElectronMediumMVA3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstElectronMediumMVA3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronMediumMVA3->push_back( IN::tauAgainstElectronMediumMVA3->at(index) ); 
 }; 

 void ClearOutputtauAgainstElectronMediumMVA3( std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronMediumMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstElectronMediumMVA3, prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronMediumMVA3->clear(); 
 }; 

 void CopytauAgainstElectronTightMVA3InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstElectronTightMVA3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstElectronTightMVA3 = std::vector<bool>(*IN::tauAgainstElectronTightMVA3);
}; 

 void CopytauAgainstElectronTightMVA3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronTightMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstElectronTightMVA3->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstElectronTightMVA3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstElectronTightMVA3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronTightMVA3->push_back( IN::tauAgainstElectronTightMVA3->at(index) ); 
 }; 

 void ClearOutputtauAgainstElectronTightMVA3( std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronTightMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstElectronTightMVA3, prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronTightMVA3->clear(); 
 }; 

 void CopytauAgainstElectronVTightMVA3InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstElectronVTightMVA3";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstElectronVTightMVA3 = std::vector<bool>(*IN::tauAgainstElectronVTightMVA3);
}; 

 void CopytauAgainstElectronVTightMVA3InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronVTightMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstElectronVTightMVA3->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstElectronVTightMVA3" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstElectronVTightMVA3" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronVTightMVA3->push_back( IN::tauAgainstElectronVTightMVA3->at(index) ); 
 }; 

 void ClearOutputtauAgainstElectronVTightMVA3( std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronVTightMVA3";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstElectronVTightMVA3, prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronVTightMVA3->clear(); 
 }; 

 void CopytauAgainstElectronDeadECALInToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstElectronDeadECAL";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstElectronDeadECAL = std::vector<bool>(*IN::tauAgainstElectronDeadECAL);
}; 

 void CopytauAgainstElectronDeadECALInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronDeadECAL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstElectronDeadECAL->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstElectronDeadECAL" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstElectronDeadECAL" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronDeadECAL->push_back( IN::tauAgainstElectronDeadECAL->at(index) ); 
 }; 

 void ClearOutputtauAgainstElectronDeadECAL( std::string  prefix ) { 

    std::string my_name = "tauAgainstElectronDeadECAL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstElectronDeadECAL, prefix = " << prefix << std::endl; 
     OUT::tauAgainstElectronDeadECAL->clear(); 
 }; 

 void CopytauAgainstMuonLoose2InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstMuonLoose2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstMuonLoose2 = std::vector<bool>(*IN::tauAgainstMuonLoose2);
}; 

 void CopytauAgainstMuonLoose2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstMuonLoose2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstMuonLoose2->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstMuonLoose2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstMuonLoose2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstMuonLoose2->push_back( IN::tauAgainstMuonLoose2->at(index) ); 
 }; 

 void ClearOutputtauAgainstMuonLoose2( std::string  prefix ) { 

    std::string my_name = "tauAgainstMuonLoose2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstMuonLoose2, prefix = " << prefix << std::endl; 
     OUT::tauAgainstMuonLoose2->clear(); 
 }; 

 void CopytauAgainstMuonMedium2InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstMuonMedium2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstMuonMedium2 = std::vector<bool>(*IN::tauAgainstMuonMedium2);
}; 

 void CopytauAgainstMuonMedium2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstMuonMedium2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstMuonMedium2->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstMuonMedium2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstMuonMedium2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstMuonMedium2->push_back( IN::tauAgainstMuonMedium2->at(index) ); 
 }; 

 void ClearOutputtauAgainstMuonMedium2( std::string  prefix ) { 

    std::string my_name = "tauAgainstMuonMedium2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstMuonMedium2, prefix = " << prefix << std::endl; 
     OUT::tauAgainstMuonMedium2->clear(); 
 }; 

 void CopytauAgainstMuonTight2InToOut( std::string prefix ) { 

    std::string my_name = "tauAgainstMuonTight2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauAgainstMuonTight2 = std::vector<bool>(*IN::tauAgainstMuonTight2);
}; 

 void CopytauAgainstMuonTight2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauAgainstMuonTight2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauAgainstMuonTight2->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauAgainstMuonTight2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauAgainstMuonTight2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauAgainstMuonTight2->push_back( IN::tauAgainstMuonTight2->at(index) ); 
 }; 

 void ClearOutputtauAgainstMuonTight2( std::string  prefix ) { 

    std::string my_name = "tauAgainstMuonTight2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauAgainstMuonTight2, prefix = " << prefix << std::endl; 
     OUT::tauAgainstMuonTight2->clear(); 
 }; 

 void CopytauCombinedIsolationDeltaBetaCorrRaw3HitsInToOut( std::string prefix ) { 

    std::string my_name = "tauCombinedIsolationDeltaBetaCorrRaw3Hits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauCombinedIsolationDeltaBetaCorrRaw3Hits = std::vector<bool>(*IN::tauCombinedIsolationDeltaBetaCorrRaw3Hits);
}; 

 void CopytauCombinedIsolationDeltaBetaCorrRaw3HitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauCombinedIsolationDeltaBetaCorrRaw3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauCombinedIsolationDeltaBetaCorrRaw3Hits->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauCombinedIsolationDeltaBetaCorrRaw3Hits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauCombinedIsolationDeltaBetaCorrRaw3Hits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauCombinedIsolationDeltaBetaCorrRaw3Hits->push_back( IN::tauCombinedIsolationDeltaBetaCorrRaw3Hits->at(index) ); 
 }; 

 void ClearOutputtauCombinedIsolationDeltaBetaCorrRaw3Hits( std::string  prefix ) { 

    std::string my_name = "tauCombinedIsolationDeltaBetaCorrRaw3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauCombinedIsolationDeltaBetaCorrRaw3Hits, prefix = " << prefix << std::endl; 
     OUT::tauCombinedIsolationDeltaBetaCorrRaw3Hits->clear(); 
 }; 

 void CopytauLooseCombinedIsolationDeltaBetaCorr3HitsInToOut( std::string prefix ) { 

    std::string my_name = "tauLooseCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauLooseCombinedIsolationDeltaBetaCorr3Hits = std::vector<bool>(*IN::tauLooseCombinedIsolationDeltaBetaCorr3Hits);
}; 

 void CopytauLooseCombinedIsolationDeltaBetaCorr3HitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauLooseCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauLooseCombinedIsolationDeltaBetaCorr3Hits->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauLooseCombinedIsolationDeltaBetaCorr3Hits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauLooseCombinedIsolationDeltaBetaCorr3Hits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauLooseCombinedIsolationDeltaBetaCorr3Hits->push_back( IN::tauLooseCombinedIsolationDeltaBetaCorr3Hits->at(index) ); 
 }; 

 void ClearOutputtauLooseCombinedIsolationDeltaBetaCorr3Hits( std::string  prefix ) { 

    std::string my_name = "tauLooseCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauLooseCombinedIsolationDeltaBetaCorr3Hits, prefix = " << prefix << std::endl; 
     OUT::tauLooseCombinedIsolationDeltaBetaCorr3Hits->clear(); 
 }; 

 void CopytauMediumCombinedIsolationDeltaBetaCorr3HitsInToOut( std::string prefix ) { 

    std::string my_name = "tauMediumCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauMediumCombinedIsolationDeltaBetaCorr3Hits = std::vector<bool>(*IN::tauMediumCombinedIsolationDeltaBetaCorr3Hits);
}; 

 void CopytauMediumCombinedIsolationDeltaBetaCorr3HitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauMediumCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauMediumCombinedIsolationDeltaBetaCorr3Hits->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauMediumCombinedIsolationDeltaBetaCorr3Hits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauMediumCombinedIsolationDeltaBetaCorr3Hits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauMediumCombinedIsolationDeltaBetaCorr3Hits->push_back( IN::tauMediumCombinedIsolationDeltaBetaCorr3Hits->at(index) ); 
 }; 

 void ClearOutputtauMediumCombinedIsolationDeltaBetaCorr3Hits( std::string  prefix ) { 

    std::string my_name = "tauMediumCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauMediumCombinedIsolationDeltaBetaCorr3Hits, prefix = " << prefix << std::endl; 
     OUT::tauMediumCombinedIsolationDeltaBetaCorr3Hits->clear(); 
 }; 

 void CopytauTightCombinedIsolationDeltaBetaCorr3HitsInToOut( std::string prefix ) { 

    std::string my_name = "tauTightCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauTightCombinedIsolationDeltaBetaCorr3Hits = std::vector<bool>(*IN::tauTightCombinedIsolationDeltaBetaCorr3Hits);
}; 

 void CopytauTightCombinedIsolationDeltaBetaCorr3HitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauTightCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauTightCombinedIsolationDeltaBetaCorr3Hits->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauTightCombinedIsolationDeltaBetaCorr3Hits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauTightCombinedIsolationDeltaBetaCorr3Hits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauTightCombinedIsolationDeltaBetaCorr3Hits->push_back( IN::tauTightCombinedIsolationDeltaBetaCorr3Hits->at(index) ); 
 }; 

 void ClearOutputtauTightCombinedIsolationDeltaBetaCorr3Hits( std::string  prefix ) { 

    std::string my_name = "tauTightCombinedIsolationDeltaBetaCorr3Hits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauTightCombinedIsolationDeltaBetaCorr3Hits, prefix = " << prefix << std::endl; 
     OUT::tauTightCombinedIsolationDeltaBetaCorr3Hits->clear(); 
 }; 

 void CopytauEtaInToOut( std::string prefix ) { 

    std::string my_name = "tauEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauEta = std::vector<float>(*IN::tauEta);
}; 

 void CopytauEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauEta->push_back( IN::tauEta->at(index) ); 
 }; 

 void ClearOutputtauEta( std::string  prefix ) { 

    std::string my_name = "tauEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauEta, prefix = " << prefix << std::endl; 
     OUT::tauEta->clear(); 
 }; 

 void CopytauPhiInToOut( std::string prefix ) { 

    std::string my_name = "tauPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauPhi = std::vector<float>(*IN::tauPhi);
}; 

 void CopytauPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauPhi->push_back( IN::tauPhi->at(index) ); 
 }; 

 void ClearOutputtauPhi( std::string  prefix ) { 

    std::string my_name = "tauPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauPhi, prefix = " << prefix << std::endl; 
     OUT::tauPhi->clear(); 
 }; 

 void CopytauPtInToOut( std::string prefix ) { 

    std::string my_name = "tauPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauPt = std::vector<float>(*IN::tauPt);
}; 

 void CopytauPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauPt->push_back( IN::tauPt->at(index) ); 
 }; 

 void ClearOutputtauPt( std::string  prefix ) { 

    std::string my_name = "tauPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauPt, prefix = " << prefix << std::endl; 
     OUT::tauPt->clear(); 
 }; 

 void CopytauEtInToOut( std::string prefix ) { 

    std::string my_name = "tauEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauEt = std::vector<float>(*IN::tauEt);
}; 

 void CopytauEtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauEt->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauEt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauEt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauEt->push_back( IN::tauEt->at(index) ); 
 }; 

 void ClearOutputtauEt( std::string  prefix ) { 

    std::string my_name = "tauEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauEt, prefix = " << prefix << std::endl; 
     OUT::tauEt->clear(); 
 }; 

 void CopytauChargeInToOut( std::string prefix ) { 

    std::string my_name = "tauCharge";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauCharge = std::vector<float>(*IN::tauCharge);
}; 

 void CopytauChargeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauCharge->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauCharge" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauCharge" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauCharge->push_back( IN::tauCharge->at(index) ); 
 }; 

 void ClearOutputtauCharge( std::string  prefix ) { 

    std::string my_name = "tauCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauCharge, prefix = " << prefix << std::endl; 
     OUT::tauCharge->clear(); 
 }; 

 void CopytauDecayModeInToOut( std::string prefix ) { 

    std::string my_name = "tauDecayMode";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauDecayMode = std::vector<int>(*IN::tauDecayMode);
}; 

 void CopytauDecayModeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauDecayMode";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauDecayMode->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauDecayMode" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauDecayMode" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauDecayMode->push_back( IN::tauDecayMode->at(index) ); 
 }; 

 void ClearOutputtauDecayMode( std::string  prefix ) { 

    std::string my_name = "tauDecayMode";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauDecayMode, prefix = " << prefix << std::endl; 
     OUT::tauDecayMode->clear(); 
 }; 

 void CopytauEMFractionInToOut( std::string prefix ) { 

    std::string my_name = "tauEMFraction";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauEMFraction = std::vector<float>(*IN::tauEMFraction);
}; 

 void CopytauEMFractionInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauEMFraction";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauEMFraction->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauEMFraction" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauEMFraction" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauEMFraction->push_back( IN::tauEMFraction->at(index) ); 
 }; 

 void ClearOutputtauEMFraction( std::string  prefix ) { 

    std::string my_name = "tauEMFraction";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauEMFraction, prefix = " << prefix << std::endl; 
     OUT::tauEMFraction->clear(); 
 }; 

 void CopytauHCAL3x3OverPLeadInToOut( std::string prefix ) { 

    std::string my_name = "tauHCAL3x3OverPLead";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauHCAL3x3OverPLead = std::vector<float>(*IN::tauHCAL3x3OverPLead);
}; 

 void CopytauHCAL3x3OverPLeadInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauHCAL3x3OverPLead";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauHCAL3x3OverPLead->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauHCAL3x3OverPLead" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauHCAL3x3OverPLead" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauHCAL3x3OverPLead->push_back( IN::tauHCAL3x3OverPLead->at(index) ); 
 }; 

 void ClearOutputtauHCAL3x3OverPLead( std::string  prefix ) { 

    std::string my_name = "tauHCAL3x3OverPLead";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauHCAL3x3OverPLead, prefix = " << prefix << std::endl; 
     OUT::tauHCAL3x3OverPLead->clear(); 
 }; 

 void CopytauHCALMaxOverPLeadInToOut( std::string prefix ) { 

    std::string my_name = "tauHCALMaxOverPLead";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauHCALMaxOverPLead = std::vector<float>(*IN::tauHCALMaxOverPLead);
}; 

 void CopytauHCALMaxOverPLeadInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauHCALMaxOverPLead";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauHCALMaxOverPLead->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauHCALMaxOverPLead" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauHCALMaxOverPLead" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauHCALMaxOverPLead->push_back( IN::tauHCALMaxOverPLead->at(index) ); 
 }; 

 void ClearOutputtauHCALMaxOverPLead( std::string  prefix ) { 

    std::string my_name = "tauHCALMaxOverPLead";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauHCALMaxOverPLead, prefix = " << prefix << std::endl; 
     OUT::tauHCALMaxOverPLead->clear(); 
 }; 

 void CopytauHCALTotOverPLeadInToOut( std::string prefix ) { 

    std::string my_name = "tauHCALTotOverPLead";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauHCALTotOverPLead = std::vector<float>(*IN::tauHCALTotOverPLead);
}; 

 void CopytauHCALTotOverPLeadInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauHCALTotOverPLead";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauHCALTotOverPLead->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauHCALTotOverPLead" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauHCALTotOverPLead" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauHCALTotOverPLead->push_back( IN::tauHCALTotOverPLead->at(index) ); 
 }; 

 void ClearOutputtauHCALTotOverPLead( std::string  prefix ) { 

    std::string my_name = "tauHCALTotOverPLead";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauHCALTotOverPLead, prefix = " << prefix << std::endl; 
     OUT::tauHCALTotOverPLead->clear(); 
 }; 

 void CopytauIsolationPFChargedHadrCandsPtSumInToOut( std::string prefix ) { 

    std::string my_name = "tauIsolationPFChargedHadrCandsPtSum";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauIsolationPFChargedHadrCandsPtSum = std::vector<float>(*IN::tauIsolationPFChargedHadrCandsPtSum);
}; 

 void CopytauIsolationPFChargedHadrCandsPtSumInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauIsolationPFChargedHadrCandsPtSum";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauIsolationPFChargedHadrCandsPtSum->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauIsolationPFChargedHadrCandsPtSum" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauIsolationPFChargedHadrCandsPtSum" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauIsolationPFChargedHadrCandsPtSum->push_back( IN::tauIsolationPFChargedHadrCandsPtSum->at(index) ); 
 }; 

 void ClearOutputtauIsolationPFChargedHadrCandsPtSum( std::string  prefix ) { 

    std::string my_name = "tauIsolationPFChargedHadrCandsPtSum";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauIsolationPFChargedHadrCandsPtSum, prefix = " << prefix << std::endl; 
     OUT::tauIsolationPFChargedHadrCandsPtSum->clear(); 
 }; 

 void CopytauIsolationPFGammaCandsEtSumInToOut( std::string prefix ) { 

    std::string my_name = "tauIsolationPFGammaCandsEtSum";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauIsolationPFGammaCandsEtSum = std::vector<float>(*IN::tauIsolationPFGammaCandsEtSum);
}; 

 void CopytauIsolationPFGammaCandsEtSumInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauIsolationPFGammaCandsEtSum";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauIsolationPFGammaCandsEtSum->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauIsolationPFGammaCandsEtSum" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauIsolationPFGammaCandsEtSum" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauIsolationPFGammaCandsEtSum->push_back( IN::tauIsolationPFGammaCandsEtSum->at(index) ); 
 }; 

 void ClearOutputtauIsolationPFGammaCandsEtSum( std::string  prefix ) { 

    std::string my_name = "tauIsolationPFGammaCandsEtSum";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauIsolationPFGammaCandsEtSum, prefix = " << prefix << std::endl; 
     OUT::tauIsolationPFGammaCandsEtSum->clear(); 
 }; 

 void CopytauLeadPFChargedHadrCandsignedSiptInToOut( std::string prefix ) { 

    std::string my_name = "tauLeadPFChargedHadrCandsignedSipt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauLeadPFChargedHadrCandsignedSipt = std::vector<float>(*IN::tauLeadPFChargedHadrCandsignedSipt);
}; 

 void CopytauLeadPFChargedHadrCandsignedSiptInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauLeadPFChargedHadrCandsignedSipt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauLeadPFChargedHadrCandsignedSipt->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauLeadPFChargedHadrCandsignedSipt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauLeadPFChargedHadrCandsignedSipt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauLeadPFChargedHadrCandsignedSipt->push_back( IN::tauLeadPFChargedHadrCandsignedSipt->at(index) ); 
 }; 

 void ClearOutputtauLeadPFChargedHadrCandsignedSipt( std::string  prefix ) { 

    std::string my_name = "tauLeadPFChargedHadrCandsignedSipt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauLeadPFChargedHadrCandsignedSipt, prefix = " << prefix << std::endl; 
     OUT::tauLeadPFChargedHadrCandsignedSipt->clear(); 
 }; 

 void CopytauLeadChargedHadronExistsInToOut( std::string prefix ) { 

    std::string my_name = "tauLeadChargedHadronExists";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauLeadChargedHadronExists = std::vector<bool>(*IN::tauLeadChargedHadronExists);
}; 

 void CopytauLeadChargedHadronExistsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronExists";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauLeadChargedHadronExists->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauLeadChargedHadronExists" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauLeadChargedHadronExists" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronExists->push_back( IN::tauLeadChargedHadronExists->at(index) ); 
 }; 

 void ClearOutputtauLeadChargedHadronExists( std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronExists";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauLeadChargedHadronExists, prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronExists->clear(); 
 }; 

 void CopytauLeadChargedHadronEtaInToOut( std::string prefix ) { 

    std::string my_name = "tauLeadChargedHadronEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauLeadChargedHadronEta = std::vector<float>(*IN::tauLeadChargedHadronEta);
}; 

 void CopytauLeadChargedHadronEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauLeadChargedHadronEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauLeadChargedHadronEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauLeadChargedHadronEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronEta->push_back( IN::tauLeadChargedHadronEta->at(index) ); 
 }; 

 void ClearOutputtauLeadChargedHadronEta( std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauLeadChargedHadronEta, prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronEta->clear(); 
 }; 

 void CopytauLeadChargedHadronPhiInToOut( std::string prefix ) { 

    std::string my_name = "tauLeadChargedHadronPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauLeadChargedHadronPhi = std::vector<float>(*IN::tauLeadChargedHadronPhi);
}; 

 void CopytauLeadChargedHadronPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauLeadChargedHadronPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauLeadChargedHadronPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauLeadChargedHadronPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronPhi->push_back( IN::tauLeadChargedHadronPhi->at(index) ); 
 }; 

 void ClearOutputtauLeadChargedHadronPhi( std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauLeadChargedHadronPhi, prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronPhi->clear(); 
 }; 

 void CopytauLeadChargedHadronPtInToOut( std::string prefix ) { 

    std::string my_name = "tauLeadChargedHadronPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::tauLeadChargedHadronPt = std::vector<float>(*IN::tauLeadChargedHadronPt);
}; 

 void CopytauLeadChargedHadronPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::tauLeadChargedHadronPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::tauLeadChargedHadronPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible tauLeadChargedHadronPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronPt->push_back( IN::tauLeadChargedHadronPt->at(index) ); 
 }; 

 void ClearOutputtauLeadChargedHadronPt( std::string  prefix ) { 

    std::string my_name = "tauLeadChargedHadronPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible tauLeadChargedHadronPt, prefix = " << prefix << std::endl; 
     OUT::tauLeadChargedHadronPt->clear(); 
 }; 

 void Copyrho25InToOut( std::string prefix ) { 

    std::string my_name = "rho25";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::rho25 = IN::rho25;
}; 

 void Copyrho25_neuInToOut( std::string prefix ) { 

    std::string my_name = "rho25_neu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::rho25_neu = IN::rho25_neu;
}; 

 void Copyrho25_muPFisoInToOut( std::string prefix ) { 

    std::string my_name = "rho25_muPFiso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::rho25_muPFiso = IN::rho25_muPFiso;
}; 

 void Copyrho25_elePFisoInToOut( std::string prefix ) { 

    std::string my_name = "rho25_elePFiso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::rho25_elePFiso = IN::rho25_elePFiso;
}; 

 void Copyrho2011InToOut( std::string prefix ) { 

    std::string my_name = "rho2011";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::rho2011 = IN::rho2011;
}; 

 void Copyrho2012InToOut( std::string prefix ) { 

    std::string my_name = "rho2012";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::rho2012 = IN::rho2012;
}; 

 void CopyQGTag_MLPInToOut( std::string prefix ) { 

    std::string my_name = "QGTag_MLP";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::QGTag_MLP = IN::QGTag_MLP;
}; 

 void CopyQGTag_likelihoodInToOut( std::string prefix ) { 

    std::string my_name = "QGTag_likelihood";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::QGTag_likelihood = IN::QGTag_likelihood;
}; 

 void CopynCA8JetInToOut( std::string prefix ) { 

    std::string my_name = "nCA8Jet";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nCA8Jet = IN::nCA8Jet;
}; 

 void CopynJetInToOut( std::string prefix ) { 

    std::string my_name = "nJet";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nJet = IN::nJet;
}; 

 void CopyjetTrgInToOut( std::string prefix ) { 

    std::string my_name = "jetTrg";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetTrg = std::vector<unsigned long>(*IN::jetTrg);
}; 

 void CopyjetTrgInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetTrg->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetTrg" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetTrg" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetTrg->push_back( IN::jetTrg->at(index) ); 
 }; 

 void ClearOutputjetTrg( std::string  prefix ) { 

    std::string my_name = "jetTrg";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetTrg, prefix = " << prefix << std::endl; 
     OUT::jetTrg->clear(); 
 }; 

 void CopyjetEnInToOut( std::string prefix ) { 

    std::string my_name = "jetEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetEn = std::vector<float>(*IN::jetEn);
}; 

 void CopyjetEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetEn->push_back( IN::jetEn->at(index) ); 
 }; 

 void ClearOutputjetEn( std::string  prefix ) { 

    std::string my_name = "jetEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetEn, prefix = " << prefix << std::endl; 
     OUT::jetEn->clear(); 
 }; 

 void CopyjetPtInToOut( std::string prefix ) { 

    std::string my_name = "jetPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetPt = std::vector<float>(*IN::jetPt);
}; 

 void CopyjetPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetPt->push_back( IN::jetPt->at(index) ); 
 }; 

 void ClearOutputjetPt( std::string  prefix ) { 

    std::string my_name = "jetPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetPt, prefix = " << prefix << std::endl; 
     OUT::jetPt->clear(); 
 }; 

 void CopyjetEtaInToOut( std::string prefix ) { 

    std::string my_name = "jetEta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetEta = std::vector<float>(*IN::jetEta);
}; 

 void CopyjetEtaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetEta->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetEta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetEta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetEta->push_back( IN::jetEta->at(index) ); 
 }; 

 void ClearOutputjetEta( std::string  prefix ) { 

    std::string my_name = "jetEta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetEta, prefix = " << prefix << std::endl; 
     OUT::jetEta->clear(); 
 }; 

 void CopyjetPhiInToOut( std::string prefix ) { 

    std::string my_name = "jetPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetPhi = std::vector<float>(*IN::jetPhi);
}; 

 void CopyjetPhiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetPhi->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetPhi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetPhi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetPhi->push_back( IN::jetPhi->at(index) ); 
 }; 

 void ClearOutputjetPhi( std::string  prefix ) { 

    std::string my_name = "jetPhi";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetPhi, prefix = " << prefix << std::endl; 
     OUT::jetPhi->clear(); 
 }; 

 void CopyjetChargeInToOut( std::string prefix ) { 

    std::string my_name = "jetCharge";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetCharge = std::vector<float>(*IN::jetCharge);
}; 

 void CopyjetChargeInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetCharge->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetCharge" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetCharge" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetCharge->push_back( IN::jetCharge->at(index) ); 
 }; 

 void ClearOutputjetCharge( std::string  prefix ) { 

    std::string my_name = "jetCharge";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetCharge, prefix = " << prefix << std::endl; 
     OUT::jetCharge->clear(); 
 }; 

 void CopyjetEtInToOut( std::string prefix ) { 

    std::string my_name = "jetEt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetEt = std::vector<float>(*IN::jetEt);
}; 

 void CopyjetEtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetEt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetEt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetEt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetEt->push_back( IN::jetEt->at(index) ); 
 }; 

 void ClearOutputjetEt( std::string  prefix ) { 

    std::string my_name = "jetEt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetEt, prefix = " << prefix << std::endl; 
     OUT::jetEt->clear(); 
 }; 

 void CopyjetRawPtInToOut( std::string prefix ) { 

    std::string my_name = "jetRawPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetRawPt = std::vector<float>(*IN::jetRawPt);
}; 

 void CopyjetRawPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetRawPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetRawPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetRawPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetRawPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetRawPt->push_back( IN::jetRawPt->at(index) ); 
 }; 

 void ClearOutputjetRawPt( std::string  prefix ) { 

    std::string my_name = "jetRawPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetRawPt, prefix = " << prefix << std::endl; 
     OUT::jetRawPt->clear(); 
 }; 

 void CopyjetRawEnInToOut( std::string prefix ) { 

    std::string my_name = "jetRawEn";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetRawEn = std::vector<float>(*IN::jetRawEn);
}; 

 void CopyjetRawEnInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetRawEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetRawEn->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetRawEn" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetRawEn" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetRawEn->push_back( IN::jetRawEn->at(index) ); 
 }; 

 void ClearOutputjetRawEn( std::string  prefix ) { 

    std::string my_name = "jetRawEn";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetRawEn, prefix = " << prefix << std::endl; 
     OUT::jetRawEn->clear(); 
 }; 

 void CopyjetAreaInToOut( std::string prefix ) { 

    std::string my_name = "jetArea";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetArea = std::vector<float>(*IN::jetArea);
}; 

 void CopyjetAreaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetArea";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetArea->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetArea" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetArea" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetArea->push_back( IN::jetArea->at(index) ); 
 }; 

 void ClearOutputjetArea( std::string  prefix ) { 

    std::string my_name = "jetArea";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetArea, prefix = " << prefix << std::endl; 
     OUT::jetArea->clear(); 
 }; 

 void CopyjetCHFInToOut( std::string prefix ) { 

    std::string my_name = "jetCHF";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetCHF = std::vector<float>(*IN::jetCHF);
}; 

 void CopyjetCHFInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetCHF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetCHF->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetCHF" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetCHF" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetCHF->push_back( IN::jetCHF->at(index) ); 
 }; 

 void ClearOutputjetCHF( std::string  prefix ) { 

    std::string my_name = "jetCHF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetCHF, prefix = " << prefix << std::endl; 
     OUT::jetCHF->clear(); 
 }; 

 void CopyjetNHFInToOut( std::string prefix ) { 

    std::string my_name = "jetNHF";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetNHF = std::vector<float>(*IN::jetNHF);
}; 

 void CopyjetNHFInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetNHF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetNHF->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetNHF" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetNHF" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetNHF->push_back( IN::jetNHF->at(index) ); 
 }; 

 void ClearOutputjetNHF( std::string  prefix ) { 

    std::string my_name = "jetNHF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetNHF, prefix = " << prefix << std::endl; 
     OUT::jetNHF->clear(); 
 }; 

 void CopyjetCEFInToOut( std::string prefix ) { 

    std::string my_name = "jetCEF";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetCEF = std::vector<float>(*IN::jetCEF);
}; 

 void CopyjetCEFInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetCEF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetCEF->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetCEF" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetCEF" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetCEF->push_back( IN::jetCEF->at(index) ); 
 }; 

 void ClearOutputjetCEF( std::string  prefix ) { 

    std::string my_name = "jetCEF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetCEF, prefix = " << prefix << std::endl; 
     OUT::jetCEF->clear(); 
 }; 

 void CopyjetNEFInToOut( std::string prefix ) { 

    std::string my_name = "jetNEF";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetNEF = std::vector<float>(*IN::jetNEF);
}; 

 void CopyjetNEFInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetNEF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetNEF->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetNEF" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetNEF" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetNEF->push_back( IN::jetNEF->at(index) ); 
 }; 

 void ClearOutputjetNEF( std::string  prefix ) { 

    std::string my_name = "jetNEF";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetNEF, prefix = " << prefix << std::endl; 
     OUT::jetNEF->clear(); 
 }; 

 void CopyjetNCHInToOut( std::string prefix ) { 

    std::string my_name = "jetNCH";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetNCH = std::vector<int>(*IN::jetNCH);
}; 

 void CopyjetNCHInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetNCH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetNCH->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetNCH" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetNCH" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetNCH->push_back( IN::jetNCH->at(index) ); 
 }; 

 void ClearOutputjetNCH( std::string  prefix ) { 

    std::string my_name = "jetNCH";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetNCH, prefix = " << prefix << std::endl; 
     OUT::jetNCH->clear(); 
 }; 

 void CopyjetHFHAEInToOut( std::string prefix ) { 

    std::string my_name = "jetHFHAE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetHFHAE = std::vector<float>(*IN::jetHFHAE);
}; 

 void CopyjetHFHAEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetHFHAE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetHFHAE->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetHFHAE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetHFHAE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetHFHAE->push_back( IN::jetHFHAE->at(index) ); 
 }; 

 void ClearOutputjetHFHAE( std::string  prefix ) { 

    std::string my_name = "jetHFHAE";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetHFHAE, prefix = " << prefix << std::endl; 
     OUT::jetHFHAE->clear(); 
 }; 

 void CopyjetHFEMEInToOut( std::string prefix ) { 

    std::string my_name = "jetHFEME";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetHFEME = std::vector<float>(*IN::jetHFEME);
}; 

 void CopyjetHFEMEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetHFEME";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetHFEME->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetHFEME" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetHFEME" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetHFEME->push_back( IN::jetHFEME->at(index) ); 
 }; 

 void ClearOutputjetHFEME( std::string  prefix ) { 

    std::string my_name = "jetHFEME";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetHFEME, prefix = " << prefix << std::endl; 
     OUT::jetHFEME->clear(); 
 }; 

 void CopyjetNConstituentsInToOut( std::string prefix ) { 

    std::string my_name = "jetNConstituents";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetNConstituents = std::vector<int>(*IN::jetNConstituents);
}; 

 void CopyjetNConstituentsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetNConstituents";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetNConstituents->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetNConstituents" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetNConstituents" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetNConstituents->push_back( IN::jetNConstituents->at(index) ); 
 }; 

 void ClearOutputjetNConstituents( std::string  prefix ) { 

    std::string my_name = "jetNConstituents";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetNConstituents, prefix = " << prefix << std::endl; 
     OUT::jetNConstituents->clear(); 
 }; 

 void CopyjetCombinedSecondaryVtxBJetTagsInToOut( std::string prefix ) { 

    std::string my_name = "jetCombinedSecondaryVtxBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetCombinedSecondaryVtxBJetTags = std::vector<float>(*IN::jetCombinedSecondaryVtxBJetTags);
}; 

 void CopyjetCombinedSecondaryVtxBJetTagsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetCombinedSecondaryVtxBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetCombinedSecondaryVtxBJetTags->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetCombinedSecondaryVtxBJetTags" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetCombinedSecondaryVtxBJetTags" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetCombinedSecondaryVtxBJetTags->push_back( IN::jetCombinedSecondaryVtxBJetTags->at(index) ); 
 }; 

 void ClearOutputjetCombinedSecondaryVtxBJetTags( std::string  prefix ) { 

    std::string my_name = "jetCombinedSecondaryVtxBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetCombinedSecondaryVtxBJetTags, prefix = " << prefix << std::endl; 
     OUT::jetCombinedSecondaryVtxBJetTags->clear(); 
 }; 

 void CopyjetCombinedSecondaryVtxMVABJetTagsInToOut( std::string prefix ) { 

    std::string my_name = "jetCombinedSecondaryVtxMVABJetTags";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetCombinedSecondaryVtxMVABJetTags = std::vector<float>(*IN::jetCombinedSecondaryVtxMVABJetTags);
}; 

 void CopyjetCombinedSecondaryVtxMVABJetTagsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetCombinedSecondaryVtxMVABJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetCombinedSecondaryVtxMVABJetTags->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetCombinedSecondaryVtxMVABJetTags" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetCombinedSecondaryVtxMVABJetTags" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetCombinedSecondaryVtxMVABJetTags->push_back( IN::jetCombinedSecondaryVtxMVABJetTags->at(index) ); 
 }; 

 void ClearOutputjetCombinedSecondaryVtxMVABJetTags( std::string  prefix ) { 

    std::string my_name = "jetCombinedSecondaryVtxMVABJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetCombinedSecondaryVtxMVABJetTags, prefix = " << prefix << std::endl; 
     OUT::jetCombinedSecondaryVtxMVABJetTags->clear(); 
 }; 

 void CopyjetJetProbabilityBJetTagsInToOut( std::string prefix ) { 

    std::string my_name = "jetJetProbabilityBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetJetProbabilityBJetTags = std::vector<float>(*IN::jetJetProbabilityBJetTags);
}; 

 void CopyjetJetProbabilityBJetTagsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetJetProbabilityBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetJetProbabilityBJetTags->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetJetProbabilityBJetTags" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetJetProbabilityBJetTags" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetJetProbabilityBJetTags->push_back( IN::jetJetProbabilityBJetTags->at(index) ); 
 }; 

 void ClearOutputjetJetProbabilityBJetTags( std::string  prefix ) { 

    std::string my_name = "jetJetProbabilityBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetJetProbabilityBJetTags, prefix = " << prefix << std::endl; 
     OUT::jetJetProbabilityBJetTags->clear(); 
 }; 

 void CopyjetJetBProbabilityBJetTagsInToOut( std::string prefix ) { 

    std::string my_name = "jetJetBProbabilityBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetJetBProbabilityBJetTags = std::vector<float>(*IN::jetJetBProbabilityBJetTags);
}; 

 void CopyjetJetBProbabilityBJetTagsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetJetBProbabilityBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetJetBProbabilityBJetTags->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetJetBProbabilityBJetTags" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetJetBProbabilityBJetTags" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetJetBProbabilityBJetTags->push_back( IN::jetJetBProbabilityBJetTags->at(index) ); 
 }; 

 void ClearOutputjetJetBProbabilityBJetTags( std::string  prefix ) { 

    std::string my_name = "jetJetBProbabilityBJetTags";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetJetBProbabilityBJetTags, prefix = " << prefix << std::endl; 
     OUT::jetJetBProbabilityBJetTags->clear(); 
 }; 

 void CopyjetPFLooseIdInToOut( std::string prefix ) { 

    std::string my_name = "jetPFLooseId";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetPFLooseId = std::vector<bool>(*IN::jetPFLooseId);
}; 

 void CopyjetPFLooseIdInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetPFLooseId";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetPFLooseId->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetPFLooseId" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetPFLooseId" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetPFLooseId->push_back( IN::jetPFLooseId->at(index) ); 
 }; 

 void ClearOutputjetPFLooseId( std::string  prefix ) { 

    std::string my_name = "jetPFLooseId";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetPFLooseId, prefix = " << prefix << std::endl; 
     OUT::jetPFLooseId->clear(); 
 }; 

 void CopyjetDRMeanInToOut( std::string prefix ) { 

    std::string my_name = "jetDRMean";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetDRMean = std::vector<float>(*IN::jetDRMean);
}; 

 void CopyjetDRMeanInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetDRMean";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetDRMean->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetDRMean" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetDRMean" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetDRMean->push_back( IN::jetDRMean->at(index) ); 
 }; 

 void ClearOutputjetDRMean( std::string  prefix ) { 

    std::string my_name = "jetDRMean";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetDRMean, prefix = " << prefix << std::endl; 
     OUT::jetDRMean->clear(); 
 }; 

 void CopyjetDR2MeanInToOut( std::string prefix ) { 

    std::string my_name = "jetDR2Mean";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetDR2Mean = std::vector<float>(*IN::jetDR2Mean);
}; 

 void CopyjetDR2MeanInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetDR2Mean";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetDR2Mean->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetDR2Mean" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetDR2Mean" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetDR2Mean->push_back( IN::jetDR2Mean->at(index) ); 
 }; 

 void ClearOutputjetDR2Mean( std::string  prefix ) { 

    std::string my_name = "jetDR2Mean";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetDR2Mean, prefix = " << prefix << std::endl; 
     OUT::jetDR2Mean->clear(); 
 }; 

 void CopyjetDZInToOut( std::string prefix ) { 

    std::string my_name = "jetDZ";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetDZ = std::vector<float>(*IN::jetDZ);
}; 

 void CopyjetDZInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetDZ";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetDZ->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetDZ" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetDZ" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetDZ->push_back( IN::jetDZ->at(index) ); 
 }; 

 void ClearOutputjetDZ( std::string  prefix ) { 

    std::string my_name = "jetDZ";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetDZ, prefix = " << prefix << std::endl; 
     OUT::jetDZ->clear(); 
 }; 

 void CopyjetFrac01InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac01";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac01 = std::vector<float>(*IN::jetFrac01);
}; 

 void CopyjetFrac01InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac01";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac01->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac01" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac01" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac01->push_back( IN::jetFrac01->at(index) ); 
 }; 

 void ClearOutputjetFrac01( std::string  prefix ) { 

    std::string my_name = "jetFrac01";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac01, prefix = " << prefix << std::endl; 
     OUT::jetFrac01->clear(); 
 }; 

 void CopyjetFrac02InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac02";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac02 = std::vector<float>(*IN::jetFrac02);
}; 

 void CopyjetFrac02InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac02";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac02->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac02" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac02" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac02->push_back( IN::jetFrac02->at(index) ); 
 }; 

 void ClearOutputjetFrac02( std::string  prefix ) { 

    std::string my_name = "jetFrac02";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac02, prefix = " << prefix << std::endl; 
     OUT::jetFrac02->clear(); 
 }; 

 void CopyjetFrac03InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac03";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac03 = std::vector<float>(*IN::jetFrac03);
}; 

 void CopyjetFrac03InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac03->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac03" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac03" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac03->push_back( IN::jetFrac03->at(index) ); 
 }; 

 void ClearOutputjetFrac03( std::string  prefix ) { 

    std::string my_name = "jetFrac03";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac03, prefix = " << prefix << std::endl; 
     OUT::jetFrac03->clear(); 
 }; 

 void CopyjetFrac04InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac04";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac04 = std::vector<float>(*IN::jetFrac04);
}; 

 void CopyjetFrac04InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac04->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac04" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac04" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac04->push_back( IN::jetFrac04->at(index) ); 
 }; 

 void ClearOutputjetFrac04( std::string  prefix ) { 

    std::string my_name = "jetFrac04";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac04, prefix = " << prefix << std::endl; 
     OUT::jetFrac04->clear(); 
 }; 

 void CopyjetFrac05InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac05";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac05 = std::vector<float>(*IN::jetFrac05);
}; 

 void CopyjetFrac05InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac05";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac05->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac05" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac05" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac05->push_back( IN::jetFrac05->at(index) ); 
 }; 

 void ClearOutputjetFrac05( std::string  prefix ) { 

    std::string my_name = "jetFrac05";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac05, prefix = " << prefix << std::endl; 
     OUT::jetFrac05->clear(); 
 }; 

 void CopyjetFrac06InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac06";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac06 = std::vector<float>(*IN::jetFrac06);
}; 

 void CopyjetFrac06InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac06";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac06->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac06" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac06" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac06->push_back( IN::jetFrac06->at(index) ); 
 }; 

 void ClearOutputjetFrac06( std::string  prefix ) { 

    std::string my_name = "jetFrac06";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac06, prefix = " << prefix << std::endl; 
     OUT::jetFrac06->clear(); 
 }; 

 void CopyjetFrac07InToOut( std::string prefix ) { 

    std::string my_name = "jetFrac07";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetFrac07 = std::vector<float>(*IN::jetFrac07);
}; 

 void CopyjetFrac07InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetFrac07";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetFrac07->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetFrac07" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetFrac07" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetFrac07->push_back( IN::jetFrac07->at(index) ); 
 }; 

 void ClearOutputjetFrac07( std::string  prefix ) { 

    std::string my_name = "jetFrac07";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetFrac07, prefix = " << prefix << std::endl; 
     OUT::jetFrac07->clear(); 
 }; 

 void CopyjetBetaInToOut( std::string prefix ) { 

    std::string my_name = "jetBeta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetBeta = std::vector<float>(*IN::jetBeta);
}; 

 void CopyjetBetaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetBeta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetBeta->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetBeta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetBeta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetBeta->push_back( IN::jetBeta->at(index) ); 
 }; 

 void ClearOutputjetBeta( std::string  prefix ) { 

    std::string my_name = "jetBeta";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetBeta, prefix = " << prefix << std::endl; 
     OUT::jetBeta->clear(); 
 }; 

 void CopyjetBetaStarCMGInToOut( std::string prefix ) { 

    std::string my_name = "jetBetaStarCMG";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetBetaStarCMG = std::vector<float>(*IN::jetBetaStarCMG);
}; 

 void CopyjetBetaStarCMGInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetBetaStarCMG";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetBetaStarCMG->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetBetaStarCMG" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetBetaStarCMG" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetBetaStarCMG->push_back( IN::jetBetaStarCMG->at(index) ); 
 }; 

 void ClearOutputjetBetaStarCMG( std::string  prefix ) { 

    std::string my_name = "jetBetaStarCMG";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetBetaStarCMG, prefix = " << prefix << std::endl; 
     OUT::jetBetaStarCMG->clear(); 
 }; 

 void CopyjetBetaStarClassicInToOut( std::string prefix ) { 

    std::string my_name = "jetBetaStarClassic";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetBetaStarClassic = std::vector<float>(*IN::jetBetaStarClassic);
}; 

 void CopyjetBetaStarClassicInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetBetaStarClassic";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetBetaStarClassic->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetBetaStarClassic" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetBetaStarClassic" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetBetaStarClassic->push_back( IN::jetBetaStarClassic->at(index) ); 
 }; 

 void ClearOutputjetBetaStarClassic( std::string  prefix ) { 

    std::string my_name = "jetBetaStarClassic";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetBetaStarClassic, prefix = " << prefix << std::endl; 
     OUT::jetBetaStarClassic->clear(); 
 }; 

 void CopyjetNNeutralsInToOut( std::string prefix ) { 

    std::string my_name = "jetNNeutrals";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetNNeutrals = std::vector<float>(*IN::jetNNeutrals);
}; 

 void CopyjetNNeutralsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetNNeutrals";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetNNeutrals->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetNNeutrals" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetNNeutrals" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetNNeutrals->push_back( IN::jetNNeutrals->at(index) ); 
 }; 

 void ClearOutputjetNNeutrals( std::string  prefix ) { 

    std::string my_name = "jetNNeutrals";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetNNeutrals, prefix = " << prefix << std::endl; 
     OUT::jetNNeutrals->clear(); 
 }; 

 void CopyjetNChargedInToOut( std::string prefix ) { 

    std::string my_name = "jetNCharged";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetNCharged = std::vector<float>(*IN::jetNCharged);
}; 

 void CopyjetNChargedInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetNCharged";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetNCharged->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetNCharged" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetNCharged" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetNCharged->push_back( IN::jetNCharged->at(index) ); 
 }; 

 void ClearOutputjetNCharged( std::string  prefix ) { 

    std::string my_name = "jetNCharged";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetNCharged, prefix = " << prefix << std::endl; 
     OUT::jetNCharged->clear(); 
 }; 

 void CopyjetWPLevelsInToOut( std::string prefix ) { 

    std::string my_name = "jetWPLevels";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetWPLevels = std::vector<std::vector<int> >(*IN::jetWPLevels);
}; 

 void CopyjetWPLevelsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetWPLevels";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetWPLevels->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetWPLevels" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetWPLevels" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetWPLevels->push_back( IN::jetWPLevels->at(index) ); 
 }; 

 void ClearOutputjetWPLevels( std::string  prefix ) { 

    std::string my_name = "jetWPLevels";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetWPLevels, prefix = " << prefix << std::endl; 
     OUT::jetWPLevels->clear(); 
 }; 

 void CopyjetMVAsExt_cutBasedInToOut( std::string prefix ) { 

    std::string my_name = "jetMVAsExt_cutBased";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetMVAsExt_cutBased = std::vector<std::vector<float> >(*IN::jetMVAsExt_cutBased);
}; 

 void CopyjetMVAsExt_cutBasedInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetMVAsExt_cutBased";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetMVAsExt_cutBased->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetMVAsExt_cutBased" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetMVAsExt_cutBased" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetMVAsExt_cutBased->push_back( IN::jetMVAsExt_cutBased->at(index) ); 
 }; 

 void ClearOutputjetMVAsExt_cutBased( std::string  prefix ) { 

    std::string my_name = "jetMVAsExt_cutBased";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetMVAsExt_cutBased, prefix = " << prefix << std::endl; 
     OUT::jetMVAsExt_cutBased->clear(); 
 }; 

 void CopyjetMVAsExt_philv1InToOut( std::string prefix ) { 

    std::string my_name = "jetMVAsExt_philv1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetMVAsExt_philv1 = std::vector<std::vector<float> >(*IN::jetMVAsExt_philv1);
}; 

 void CopyjetMVAsExt_philv1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetMVAsExt_philv1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetMVAsExt_philv1->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetMVAsExt_philv1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetMVAsExt_philv1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetMVAsExt_philv1->push_back( IN::jetMVAsExt_philv1->at(index) ); 
 }; 

 void ClearOutputjetMVAsExt_philv1( std::string  prefix ) { 

    std::string my_name = "jetMVAsExt_philv1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetMVAsExt_philv1, prefix = " << prefix << std::endl; 
     OUT::jetMVAsExt_philv1->clear(); 
 }; 

 void CopyjetWPLevelsExt_philv1InToOut( std::string prefix ) { 

    std::string my_name = "jetWPLevelsExt_philv1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetWPLevelsExt_philv1 = std::vector<std::vector<int> >(*IN::jetWPLevelsExt_philv1);
}; 

 void CopyjetWPLevelsExt_philv1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetWPLevelsExt_philv1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetWPLevelsExt_philv1->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetWPLevelsExt_philv1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetWPLevelsExt_philv1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetWPLevelsExt_philv1->push_back( IN::jetWPLevelsExt_philv1->at(index) ); 
 }; 

 void ClearOutputjetWPLevelsExt_philv1( std::string  prefix ) { 

    std::string my_name = "jetWPLevelsExt_philv1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetWPLevelsExt_philv1, prefix = " << prefix << std::endl; 
     OUT::jetWPLevelsExt_philv1->clear(); 
 }; 

 void CopyjetMtInToOut( std::string prefix ) { 

    std::string my_name = "jetMt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetMt = std::vector<float>(*IN::jetMt);
}; 

 void CopyjetMtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetMt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetMt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetMt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetMt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetMt->push_back( IN::jetMt->at(index) ); 
 }; 

 void ClearOutputjetMt( std::string  prefix ) { 

    std::string my_name = "jetMt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetMt, prefix = " << prefix << std::endl; 
     OUT::jetMt->clear(); 
 }; 

 void CopyjetJECUncInToOut( std::string prefix ) { 

    std::string my_name = "jetJECUnc";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetJECUnc = std::vector<float>(*IN::jetJECUnc);
}; 

 void CopyjetJECUncInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetJECUnc";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetJECUnc->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetJECUnc" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetJECUnc" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetJECUnc->push_back( IN::jetJECUnc->at(index) ); 
 }; 

 void ClearOutputjetJECUnc( std::string  prefix ) { 

    std::string my_name = "jetJECUnc";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetJECUnc, prefix = " << prefix << std::endl; 
     OUT::jetJECUnc->clear(); 
 }; 

 void CopyjetLeadTrackPtInToOut( std::string prefix ) { 

    std::string my_name = "jetLeadTrackPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetLeadTrackPt = std::vector<float>(*IN::jetLeadTrackPt);
}; 

 void CopyjetLeadTrackPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetLeadTrackPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetLeadTrackPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetLeadTrackPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetLeadTrackPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetLeadTrackPt->push_back( IN::jetLeadTrackPt->at(index) ); 
 }; 

 void ClearOutputjetLeadTrackPt( std::string  prefix ) { 

    std::string my_name = "jetLeadTrackPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetLeadTrackPt, prefix = " << prefix << std::endl; 
     OUT::jetLeadTrackPt->clear(); 
 }; 

 void CopyjetVtxPtInToOut( std::string prefix ) { 

    std::string my_name = "jetVtxPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetVtxPt = std::vector<float>(*IN::jetVtxPt);
}; 

 void CopyjetVtxPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetVtxPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetVtxPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetVtxPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetVtxPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetVtxPt->push_back( IN::jetVtxPt->at(index) ); 
 }; 

 void ClearOutputjetVtxPt( std::string  prefix ) { 

    std::string my_name = "jetVtxPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetVtxPt, prefix = " << prefix << std::endl; 
     OUT::jetVtxPt->clear(); 
 }; 

 void CopyjetVtxMassInToOut( std::string prefix ) { 

    std::string my_name = "jetVtxMass";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetVtxMass = std::vector<float>(*IN::jetVtxMass);
}; 

 void CopyjetVtxMassInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetVtxMass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetVtxMass->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetVtxMass" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetVtxMass" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetVtxMass->push_back( IN::jetVtxMass->at(index) ); 
 }; 

 void ClearOutputjetVtxMass( std::string  prefix ) { 

    std::string my_name = "jetVtxMass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetVtxMass, prefix = " << prefix << std::endl; 
     OUT::jetVtxMass->clear(); 
 }; 

 void CopyjetVtx3dLInToOut( std::string prefix ) { 

    std::string my_name = "jetVtx3dL";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetVtx3dL = std::vector<float>(*IN::jetVtx3dL);
}; 

 void CopyjetVtx3dLInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetVtx3dL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetVtx3dL->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetVtx3dL" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetVtx3dL" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetVtx3dL->push_back( IN::jetVtx3dL->at(index) ); 
 }; 

 void ClearOutputjetVtx3dL( std::string  prefix ) { 

    std::string my_name = "jetVtx3dL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetVtx3dL, prefix = " << prefix << std::endl; 
     OUT::jetVtx3dL->clear(); 
 }; 

 void CopyjetVtx3deLInToOut( std::string prefix ) { 

    std::string my_name = "jetVtx3deL";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetVtx3deL = std::vector<float>(*IN::jetVtx3deL);
}; 

 void CopyjetVtx3deLInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetVtx3deL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetVtx3deL->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetVtx3deL" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetVtx3deL" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetVtx3deL->push_back( IN::jetVtx3deL->at(index) ); 
 }; 

 void ClearOutputjetVtx3deL( std::string  prefix ) { 

    std::string my_name = "jetVtx3deL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetVtx3deL, prefix = " << prefix << std::endl; 
     OUT::jetVtx3deL->clear(); 
 }; 

 void CopyjetSoftLeptPtInToOut( std::string prefix ) { 

    std::string my_name = "jetSoftLeptPt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetSoftLeptPt = std::vector<float>(*IN::jetSoftLeptPt);
}; 

 void CopyjetSoftLeptPtInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetSoftLeptPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetSoftLeptPt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetSoftLeptPt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetSoftLeptPt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptPt->push_back( IN::jetSoftLeptPt->at(index) ); 
 }; 

 void ClearOutputjetSoftLeptPt( std::string  prefix ) { 

    std::string my_name = "jetSoftLeptPt";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetSoftLeptPt, prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptPt->clear(); 
 }; 

 void CopyjetSoftLeptPtRelInToOut( std::string prefix ) { 

    std::string my_name = "jetSoftLeptPtRel";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetSoftLeptPtRel = std::vector<float>(*IN::jetSoftLeptPtRel);
}; 

 void CopyjetSoftLeptPtRelInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetSoftLeptPtRel";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetSoftLeptPtRel->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetSoftLeptPtRel" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetSoftLeptPtRel" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptPtRel->push_back( IN::jetSoftLeptPtRel->at(index) ); 
 }; 

 void ClearOutputjetSoftLeptPtRel( std::string  prefix ) { 

    std::string my_name = "jetSoftLeptPtRel";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetSoftLeptPtRel, prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptPtRel->clear(); 
 }; 

 void CopyjetSoftLeptdRInToOut( std::string prefix ) { 

    std::string my_name = "jetSoftLeptdR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetSoftLeptdR = std::vector<float>(*IN::jetSoftLeptdR);
}; 

 void CopyjetSoftLeptdRInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetSoftLeptdR";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetSoftLeptdR->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetSoftLeptdR" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetSoftLeptdR" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptdR->push_back( IN::jetSoftLeptdR->at(index) ); 
 }; 

 void ClearOutputjetSoftLeptdR( std::string  prefix ) { 

    std::string my_name = "jetSoftLeptdR";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetSoftLeptdR, prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptdR->clear(); 
 }; 

 void CopyjetSoftLeptIdlooseMuInToOut( std::string prefix ) { 

    std::string my_name = "jetSoftLeptIdlooseMu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetSoftLeptIdlooseMu = std::vector<float>(*IN::jetSoftLeptIdlooseMu);
}; 

 void CopyjetSoftLeptIdlooseMuInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetSoftLeptIdlooseMu";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetSoftLeptIdlooseMu->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetSoftLeptIdlooseMu" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetSoftLeptIdlooseMu" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptIdlooseMu->push_back( IN::jetSoftLeptIdlooseMu->at(index) ); 
 }; 

 void ClearOutputjetSoftLeptIdlooseMu( std::string  prefix ) { 

    std::string my_name = "jetSoftLeptIdlooseMu";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetSoftLeptIdlooseMu, prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptIdlooseMu->clear(); 
 }; 

 void CopyjetSoftLeptIdEle95InToOut( std::string prefix ) { 

    std::string my_name = "jetSoftLeptIdEle95";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetSoftLeptIdEle95 = std::vector<float>(*IN::jetSoftLeptIdEle95);
}; 

 void CopyjetSoftLeptIdEle95InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetSoftLeptIdEle95";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetSoftLeptIdEle95->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetSoftLeptIdEle95" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetSoftLeptIdEle95" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptIdEle95->push_back( IN::jetSoftLeptIdEle95->at(index) ); 
 }; 

 void ClearOutputjetSoftLeptIdEle95( std::string  prefix ) { 

    std::string my_name = "jetSoftLeptIdEle95";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetSoftLeptIdEle95, prefix = " << prefix << std::endl; 
     OUT::jetSoftLeptIdEle95->clear(); 
 }; 

 void CopyjetDPhiMETJetInToOut( std::string prefix ) { 

    std::string my_name = "jetDPhiMETJet";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetDPhiMETJet = std::vector<float>(*IN::jetDPhiMETJet);
}; 

 void CopyjetDPhiMETJetInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetDPhiMETJet";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetDPhiMETJet->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetDPhiMETJet" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetDPhiMETJet" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetDPhiMETJet->push_back( IN::jetDPhiMETJet->at(index) ); 
 }; 

 void ClearOutputjetDPhiMETJet( std::string  prefix ) { 

    std::string my_name = "jetDPhiMETJet";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetDPhiMETJet, prefix = " << prefix << std::endl; 
     OUT::jetDPhiMETJet->clear(); 
 }; 

 void CopyjetPuJetIdLInToOut( std::string prefix ) { 

    std::string my_name = "jetPuJetIdL";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetPuJetIdL = std::vector<float>(*IN::jetPuJetIdL);
}; 

 void CopyjetPuJetIdLInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetPuJetIdL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetPuJetIdL->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetPuJetIdL" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetPuJetIdL" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetPuJetIdL->push_back( IN::jetPuJetIdL->at(index) ); 
 }; 

 void ClearOutputjetPuJetIdL( std::string  prefix ) { 

    std::string my_name = "jetPuJetIdL";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetPuJetIdL, prefix = " << prefix << std::endl; 
     OUT::jetPuJetIdL->clear(); 
 }; 

 void CopyjetPuJetIdMInToOut( std::string prefix ) { 

    std::string my_name = "jetPuJetIdM";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetPuJetIdM = std::vector<float>(*IN::jetPuJetIdM);
}; 

 void CopyjetPuJetIdMInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetPuJetIdM";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetPuJetIdM->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetPuJetIdM" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetPuJetIdM" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetPuJetIdM->push_back( IN::jetPuJetIdM->at(index) ); 
 }; 

 void ClearOutputjetPuJetIdM( std::string  prefix ) { 

    std::string my_name = "jetPuJetIdM";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetPuJetIdM, prefix = " << prefix << std::endl; 
     OUT::jetPuJetIdM->clear(); 
 }; 

 void CopyjetPuJetIdTInToOut( std::string prefix ) { 

    std::string my_name = "jetPuJetIdT";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jetPuJetIdT = std::vector<float>(*IN::jetPuJetIdT);
}; 

 void CopyjetPuJetIdTInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jetPuJetIdT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jetPuJetIdT->size() ) {
         std::cout << "Vector size exceeded for branch IN::jetPuJetIdT" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jetPuJetIdT" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jetPuJetIdT->push_back( IN::jetPuJetIdT->at(index) ); 
 }; 

 void ClearOutputjetPuJetIdT( std::string  prefix ) { 

    std::string my_name = "jetPuJetIdT";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jetPuJetIdT, prefix = " << prefix << std::endl; 
     OUT::jetPuJetIdT->clear(); 
 }; 

 void CopynConvInToOut( std::string prefix ) { 

    std::string my_name = "nConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nConv = IN::nConv;
}; 

 void CopyconvP4_xInToOut( std::string prefix ) { 

    std::string my_name = "convP4_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convP4_x = std::vector<float>(*IN::convP4_x);
}; 

 void CopyconvP4_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convP4_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convP4_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::convP4_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convP4_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convP4_x->push_back( IN::convP4_x->at(index) ); 
 }; 

 void ClearOutputconvP4_x( std::string  prefix ) { 

    std::string my_name = "convP4_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convP4_x, prefix = " << prefix << std::endl; 
     OUT::convP4_x->clear(); 
 }; 

 void CopyconvP4_yInToOut( std::string prefix ) { 

    std::string my_name = "convP4_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convP4_y = std::vector<float>(*IN::convP4_y);
}; 

 void CopyconvP4_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convP4_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convP4_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::convP4_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convP4_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convP4_y->push_back( IN::convP4_y->at(index) ); 
 }; 

 void ClearOutputconvP4_y( std::string  prefix ) { 

    std::string my_name = "convP4_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convP4_y, prefix = " << prefix << std::endl; 
     OUT::convP4_y->clear(); 
 }; 

 void CopyconvP4_zInToOut( std::string prefix ) { 

    std::string my_name = "convP4_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convP4_z = std::vector<float>(*IN::convP4_z);
}; 

 void CopyconvP4_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convP4_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convP4_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::convP4_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convP4_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convP4_z->push_back( IN::convP4_z->at(index) ); 
 }; 

 void ClearOutputconvP4_z( std::string  prefix ) { 

    std::string my_name = "convP4_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convP4_z, prefix = " << prefix << std::endl; 
     OUT::convP4_z->clear(); 
 }; 

 void CopyconvP4_EInToOut( std::string prefix ) { 

    std::string my_name = "convP4_E";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convP4_E = std::vector<float>(*IN::convP4_E);
}; 

 void CopyconvP4_EInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convP4_E";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convP4_E->size() ) {
         std::cout << "Vector size exceeded for branch IN::convP4_E" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convP4_E" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convP4_E->push_back( IN::convP4_E->at(index) ); 
 }; 

 void ClearOutputconvP4_E( std::string  prefix ) { 

    std::string my_name = "convP4_E";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convP4_E, prefix = " << prefix << std::endl; 
     OUT::convP4_E->clear(); 
 }; 

 void CopyconvVtx_xInToOut( std::string prefix ) { 

    std::string my_name = "convVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convVtx_x = std::vector<float>(*IN::convVtx_x);
}; 

 void CopyconvVtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convVtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::convVtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convVtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convVtx_x->push_back( IN::convVtx_x->at(index) ); 
 }; 

 void ClearOutputconvVtx_x( std::string  prefix ) { 

    std::string my_name = "convVtx_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convVtx_x, prefix = " << prefix << std::endl; 
     OUT::convVtx_x->clear(); 
 }; 

 void CopyconvVtx_yInToOut( std::string prefix ) { 

    std::string my_name = "convVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convVtx_y = std::vector<float>(*IN::convVtx_y);
}; 

 void CopyconvVtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convVtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::convVtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convVtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convVtx_y->push_back( IN::convVtx_y->at(index) ); 
 }; 

 void ClearOutputconvVtx_y( std::string  prefix ) { 

    std::string my_name = "convVtx_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convVtx_y, prefix = " << prefix << std::endl; 
     OUT::convVtx_y->clear(); 
 }; 

 void CopyconvVtx_zInToOut( std::string prefix ) { 

    std::string my_name = "convVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convVtx_z = std::vector<float>(*IN::convVtx_z);
}; 

 void CopyconvVtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convVtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::convVtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convVtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convVtx_z->push_back( IN::convVtx_z->at(index) ); 
 }; 

 void ClearOutputconvVtx_z( std::string  prefix ) { 

    std::string my_name = "convVtx_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convVtx_z, prefix = " << prefix << std::endl; 
     OUT::convVtx_z->clear(); 
 }; 

 void CopyconvVtxErr_xInToOut( std::string prefix ) { 

    std::string my_name = "convVtxErr_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convVtxErr_x = std::vector<float>(*IN::convVtxErr_x);
}; 

 void CopyconvVtxErr_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convVtxErr_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convVtxErr_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::convVtxErr_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convVtxErr_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convVtxErr_x->push_back( IN::convVtxErr_x->at(index) ); 
 }; 

 void ClearOutputconvVtxErr_x( std::string  prefix ) { 

    std::string my_name = "convVtxErr_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convVtxErr_x, prefix = " << prefix << std::endl; 
     OUT::convVtxErr_x->clear(); 
 }; 

 void CopyconvVtxErr_yInToOut( std::string prefix ) { 

    std::string my_name = "convVtxErr_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convVtxErr_y = std::vector<float>(*IN::convVtxErr_y);
}; 

 void CopyconvVtxErr_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convVtxErr_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convVtxErr_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::convVtxErr_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convVtxErr_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convVtxErr_y->push_back( IN::convVtxErr_y->at(index) ); 
 }; 

 void ClearOutputconvVtxErr_y( std::string  prefix ) { 

    std::string my_name = "convVtxErr_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convVtxErr_y, prefix = " << prefix << std::endl; 
     OUT::convVtxErr_y->clear(); 
 }; 

 void CopyconvVtxErr_zInToOut( std::string prefix ) { 

    std::string my_name = "convVtxErr_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convVtxErr_z = std::vector<float>(*IN::convVtxErr_z);
}; 

 void CopyconvVtxErr_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convVtxErr_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convVtxErr_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::convVtxErr_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convVtxErr_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convVtxErr_z->push_back( IN::convVtxErr_z->at(index) ); 
 }; 

 void ClearOutputconvVtxErr_z( std::string  prefix ) { 

    std::string my_name = "convVtxErr_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convVtxErr_z, prefix = " << prefix << std::endl; 
     OUT::convVtxErr_z->clear(); 
 }; 

 void CopyconvPairMomentum_xInToOut( std::string prefix ) { 

    std::string my_name = "convPairMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convPairMomentum_x = std::vector<float>(*IN::convPairMomentum_x);
}; 

 void CopyconvPairMomentum_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convPairMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convPairMomentum_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::convPairMomentum_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convPairMomentum_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convPairMomentum_x->push_back( IN::convPairMomentum_x->at(index) ); 
 }; 

 void ClearOutputconvPairMomentum_x( std::string  prefix ) { 

    std::string my_name = "convPairMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convPairMomentum_x, prefix = " << prefix << std::endl; 
     OUT::convPairMomentum_x->clear(); 
 }; 

 void CopyconvPairMomentum_yInToOut( std::string prefix ) { 

    std::string my_name = "convPairMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convPairMomentum_y = std::vector<float>(*IN::convPairMomentum_y);
}; 

 void CopyconvPairMomentum_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convPairMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convPairMomentum_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::convPairMomentum_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convPairMomentum_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convPairMomentum_y->push_back( IN::convPairMomentum_y->at(index) ); 
 }; 

 void ClearOutputconvPairMomentum_y( std::string  prefix ) { 

    std::string my_name = "convPairMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convPairMomentum_y, prefix = " << prefix << std::endl; 
     OUT::convPairMomentum_y->clear(); 
 }; 

 void CopyconvPairMomentum_zInToOut( std::string prefix ) { 

    std::string my_name = "convPairMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convPairMomentum_z = std::vector<float>(*IN::convPairMomentum_z);
}; 

 void CopyconvPairMomentum_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convPairMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convPairMomentum_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::convPairMomentum_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convPairMomentum_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convPairMomentum_z->push_back( IN::convPairMomentum_z->at(index) ); 
 }; 

 void ClearOutputconvPairMomentum_z( std::string  prefix ) { 

    std::string my_name = "convPairMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convPairMomentum_z, prefix = " << prefix << std::endl; 
     OUT::convPairMomentum_z->clear(); 
 }; 

 void CopyconvRefittedMomentum_xInToOut( std::string prefix ) { 

    std::string my_name = "convRefittedMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convRefittedMomentum_x = std::vector<float>(*IN::convRefittedMomentum_x);
}; 

 void CopyconvRefittedMomentum_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convRefittedMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convRefittedMomentum_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::convRefittedMomentum_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convRefittedMomentum_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convRefittedMomentum_x->push_back( IN::convRefittedMomentum_x->at(index) ); 
 }; 

 void ClearOutputconvRefittedMomentum_x( std::string  prefix ) { 

    std::string my_name = "convRefittedMomentum_x";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convRefittedMomentum_x, prefix = " << prefix << std::endl; 
     OUT::convRefittedMomentum_x->clear(); 
 }; 

 void CopyconvRefittedMomentum_yInToOut( std::string prefix ) { 

    std::string my_name = "convRefittedMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convRefittedMomentum_y = std::vector<float>(*IN::convRefittedMomentum_y);
}; 

 void CopyconvRefittedMomentum_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convRefittedMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convRefittedMomentum_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::convRefittedMomentum_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convRefittedMomentum_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convRefittedMomentum_y->push_back( IN::convRefittedMomentum_y->at(index) ); 
 }; 

 void ClearOutputconvRefittedMomentum_y( std::string  prefix ) { 

    std::string my_name = "convRefittedMomentum_y";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convRefittedMomentum_y, prefix = " << prefix << std::endl; 
     OUT::convRefittedMomentum_y->clear(); 
 }; 

 void CopyconvRefittedMomentum_zInToOut( std::string prefix ) { 

    std::string my_name = "convRefittedMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convRefittedMomentum_z = std::vector<float>(*IN::convRefittedMomentum_z);
}; 

 void CopyconvRefittedMomentum_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convRefittedMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convRefittedMomentum_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::convRefittedMomentum_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convRefittedMomentum_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convRefittedMomentum_z->push_back( IN::convRefittedMomentum_z->at(index) ); 
 }; 

 void ClearOutputconvRefittedMomentum_z( std::string  prefix ) { 

    std::string my_name = "convRefittedMomentum_z";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convRefittedMomentum_z, prefix = " << prefix << std::endl; 
     OUT::convRefittedMomentum_z->clear(); 
 }; 

 void CopyconvNTracksInToOut( std::string prefix ) { 

    std::string my_name = "convNTracks";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convNTracks = std::vector<int>(*IN::convNTracks);
}; 

 void CopyconvNTracksInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convNTracks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convNTracks->size() ) {
         std::cout << "Vector size exceeded for branch IN::convNTracks" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convNTracks" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convNTracks->push_back( IN::convNTracks->at(index) ); 
 }; 

 void ClearOutputconvNTracks( std::string  prefix ) { 

    std::string my_name = "convNTracks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convNTracks, prefix = " << prefix << std::endl; 
     OUT::convNTracks->clear(); 
 }; 

 void CopyconvPairInvMassInToOut( std::string prefix ) { 

    std::string my_name = "convPairInvMass";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convPairInvMass = std::vector<float>(*IN::convPairInvMass);
}; 

 void CopyconvPairInvMassInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convPairInvMass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convPairInvMass->size() ) {
         std::cout << "Vector size exceeded for branch IN::convPairInvMass" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convPairInvMass" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convPairInvMass->push_back( IN::convPairInvMass->at(index) ); 
 }; 

 void ClearOutputconvPairInvMass( std::string  prefix ) { 

    std::string my_name = "convPairInvMass";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convPairInvMass, prefix = " << prefix << std::endl; 
     OUT::convPairInvMass->clear(); 
 }; 

 void CopyconvPairCotThetaSepInToOut( std::string prefix ) { 

    std::string my_name = "convPairCotThetaSep";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convPairCotThetaSep = std::vector<float>(*IN::convPairCotThetaSep);
}; 

 void CopyconvPairCotThetaSepInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convPairCotThetaSep";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convPairCotThetaSep->size() ) {
         std::cout << "Vector size exceeded for branch IN::convPairCotThetaSep" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convPairCotThetaSep" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convPairCotThetaSep->push_back( IN::convPairCotThetaSep->at(index) ); 
 }; 

 void ClearOutputconvPairCotThetaSep( std::string  prefix ) { 

    std::string my_name = "convPairCotThetaSep";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convPairCotThetaSep, prefix = " << prefix << std::endl; 
     OUT::convPairCotThetaSep->clear(); 
 }; 

 void CopyconvEoverPInToOut( std::string prefix ) { 

    std::string my_name = "convEoverP";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convEoverP = std::vector<float>(*IN::convEoverP);
}; 

 void CopyconvEoverPInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convEoverP";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convEoverP->size() ) {
         std::cout << "Vector size exceeded for branch IN::convEoverP" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convEoverP" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convEoverP->push_back( IN::convEoverP->at(index) ); 
 }; 

 void ClearOutputconvEoverP( std::string  prefix ) { 

    std::string my_name = "convEoverP";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convEoverP, prefix = " << prefix << std::endl; 
     OUT::convEoverP->clear(); 
 }; 

 void CopyconvDistOfMinApproachInToOut( std::string prefix ) { 

    std::string my_name = "convDistOfMinApproach";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convDistOfMinApproach = std::vector<float>(*IN::convDistOfMinApproach);
}; 

 void CopyconvDistOfMinApproachInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convDistOfMinApproach";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convDistOfMinApproach->size() ) {
         std::cout << "Vector size exceeded for branch IN::convDistOfMinApproach" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convDistOfMinApproach" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convDistOfMinApproach->push_back( IN::convDistOfMinApproach->at(index) ); 
 }; 

 void ClearOutputconvDistOfMinApproach( std::string  prefix ) { 

    std::string my_name = "convDistOfMinApproach";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convDistOfMinApproach, prefix = " << prefix << std::endl; 
     OUT::convDistOfMinApproach->clear(); 
 }; 

 void CopyconvDPhiTrksAtVtxInToOut( std::string prefix ) { 

    std::string my_name = "convDPhiTrksAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convDPhiTrksAtVtx = std::vector<float>(*IN::convDPhiTrksAtVtx);
}; 

 void CopyconvDPhiTrksAtVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convDPhiTrksAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convDPhiTrksAtVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::convDPhiTrksAtVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convDPhiTrksAtVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convDPhiTrksAtVtx->push_back( IN::convDPhiTrksAtVtx->at(index) ); 
 }; 

 void ClearOutputconvDPhiTrksAtVtx( std::string  prefix ) { 

    std::string my_name = "convDPhiTrksAtVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convDPhiTrksAtVtx, prefix = " << prefix << std::endl; 
     OUT::convDPhiTrksAtVtx->clear(); 
 }; 

 void CopyconvDPhiTrksAtEcalInToOut( std::string prefix ) { 

    std::string my_name = "convDPhiTrksAtEcal";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convDPhiTrksAtEcal = std::vector<float>(*IN::convDPhiTrksAtEcal);
}; 

 void CopyconvDPhiTrksAtEcalInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convDPhiTrksAtEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convDPhiTrksAtEcal->size() ) {
         std::cout << "Vector size exceeded for branch IN::convDPhiTrksAtEcal" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convDPhiTrksAtEcal" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convDPhiTrksAtEcal->push_back( IN::convDPhiTrksAtEcal->at(index) ); 
 }; 

 void ClearOutputconvDPhiTrksAtEcal( std::string  prefix ) { 

    std::string my_name = "convDPhiTrksAtEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convDPhiTrksAtEcal, prefix = " << prefix << std::endl; 
     OUT::convDPhiTrksAtEcal->clear(); 
 }; 

 void CopyconvDEtaTrksAtEcalInToOut( std::string prefix ) { 

    std::string my_name = "convDEtaTrksAtEcal";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convDEtaTrksAtEcal = std::vector<float>(*IN::convDEtaTrksAtEcal);
}; 

 void CopyconvDEtaTrksAtEcalInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convDEtaTrksAtEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convDEtaTrksAtEcal->size() ) {
         std::cout << "Vector size exceeded for branch IN::convDEtaTrksAtEcal" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convDEtaTrksAtEcal" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convDEtaTrksAtEcal->push_back( IN::convDEtaTrksAtEcal->at(index) ); 
 }; 

 void ClearOutputconvDEtaTrksAtEcal( std::string  prefix ) { 

    std::string my_name = "convDEtaTrksAtEcal";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convDEtaTrksAtEcal, prefix = " << prefix << std::endl; 
     OUT::convDEtaTrksAtEcal->clear(); 
 }; 

 void CopyconvDxyInToOut( std::string prefix ) { 

    std::string my_name = "convDxy";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convDxy = std::vector<float>(*IN::convDxy);
}; 

 void CopyconvDxyInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convDxy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convDxy->size() ) {
         std::cout << "Vector size exceeded for branch IN::convDxy" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convDxy" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convDxy->push_back( IN::convDxy->at(index) ); 
 }; 

 void ClearOutputconvDxy( std::string  prefix ) { 

    std::string my_name = "convDxy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convDxy, prefix = " << prefix << std::endl; 
     OUT::convDxy->clear(); 
 }; 

 void CopyconvDzInToOut( std::string prefix ) { 

    std::string my_name = "convDz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convDz = std::vector<float>(*IN::convDz);
}; 

 void CopyconvDzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convDz->size() ) {
         std::cout << "Vector size exceeded for branch IN::convDz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convDz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convDz->push_back( IN::convDz->at(index) ); 
 }; 

 void ClearOutputconvDz( std::string  prefix ) { 

    std::string my_name = "convDz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convDz, prefix = " << prefix << std::endl; 
     OUT::convDz->clear(); 
 }; 

 void CopyconvLxyInToOut( std::string prefix ) { 

    std::string my_name = "convLxy";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convLxy = std::vector<float>(*IN::convLxy);
}; 

 void CopyconvLxyInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convLxy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convLxy->size() ) {
         std::cout << "Vector size exceeded for branch IN::convLxy" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convLxy" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convLxy->push_back( IN::convLxy->at(index) ); 
 }; 

 void ClearOutputconvLxy( std::string  prefix ) { 

    std::string my_name = "convLxy";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convLxy, prefix = " << prefix << std::endl; 
     OUT::convLxy->clear(); 
 }; 

 void CopyconvLzInToOut( std::string prefix ) { 

    std::string my_name = "convLz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convLz = std::vector<float>(*IN::convLz);
}; 

 void CopyconvLzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convLz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convLz->size() ) {
         std::cout << "Vector size exceeded for branch IN::convLz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convLz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convLz->push_back( IN::convLz->at(index) ); 
 }; 

 void ClearOutputconvLz( std::string  prefix ) { 

    std::string my_name = "convLz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convLz, prefix = " << prefix << std::endl; 
     OUT::convLz->clear(); 
 }; 

 void CopyconvZofPrimVtxFromTrksInToOut( std::string prefix ) { 

    std::string my_name = "convZofPrimVtxFromTrks";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convZofPrimVtxFromTrks = std::vector<float>(*IN::convZofPrimVtxFromTrks);
}; 

 void CopyconvZofPrimVtxFromTrksInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convZofPrimVtxFromTrks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convZofPrimVtxFromTrks->size() ) {
         std::cout << "Vector size exceeded for branch IN::convZofPrimVtxFromTrks" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convZofPrimVtxFromTrks" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convZofPrimVtxFromTrks->push_back( IN::convZofPrimVtxFromTrks->at(index) ); 
 }; 

 void ClearOutputconvZofPrimVtxFromTrks( std::string  prefix ) { 

    std::string my_name = "convZofPrimVtxFromTrks";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convZofPrimVtxFromTrks, prefix = " << prefix << std::endl; 
     OUT::convZofPrimVtxFromTrks->clear(); 
 }; 

 void CopyconvNHitsBeforeVtx_0InToOut( std::string prefix ) { 

    std::string my_name = "convNHitsBeforeVtx_0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convNHitsBeforeVtx_0 = std::vector<int>(*IN::convNHitsBeforeVtx_0);
}; 

 void CopyconvNHitsBeforeVtx_0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convNHitsBeforeVtx_0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convNHitsBeforeVtx_0->size() ) {
         std::cout << "Vector size exceeded for branch IN::convNHitsBeforeVtx_0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convNHitsBeforeVtx_0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convNHitsBeforeVtx_0->push_back( IN::convNHitsBeforeVtx_0->at(index) ); 
 }; 

 void ClearOutputconvNHitsBeforeVtx_0( std::string  prefix ) { 

    std::string my_name = "convNHitsBeforeVtx_0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convNHitsBeforeVtx_0, prefix = " << prefix << std::endl; 
     OUT::convNHitsBeforeVtx_0->clear(); 
 }; 

 void CopyconvNHitsBeforeVtx_1InToOut( std::string prefix ) { 

    std::string my_name = "convNHitsBeforeVtx_1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convNHitsBeforeVtx_1 = std::vector<int>(*IN::convNHitsBeforeVtx_1);
}; 

 void CopyconvNHitsBeforeVtx_1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convNHitsBeforeVtx_1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convNHitsBeforeVtx_1->size() ) {
         std::cout << "Vector size exceeded for branch IN::convNHitsBeforeVtx_1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convNHitsBeforeVtx_1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convNHitsBeforeVtx_1->push_back( IN::convNHitsBeforeVtx_1->at(index) ); 
 }; 

 void ClearOutputconvNHitsBeforeVtx_1( std::string  prefix ) { 

    std::string my_name = "convNHitsBeforeVtx_1";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convNHitsBeforeVtx_1, prefix = " << prefix << std::endl; 
     OUT::convNHitsBeforeVtx_1->clear(); 
 }; 

 void CopyconvNSharedHitsInToOut( std::string prefix ) { 

    std::string my_name = "convNSharedHits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convNSharedHits = std::vector<int>(*IN::convNSharedHits);
}; 

 void CopyconvNSharedHitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convNSharedHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convNSharedHits->size() ) {
         std::cout << "Vector size exceeded for branch IN::convNSharedHits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convNSharedHits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convNSharedHits->push_back( IN::convNSharedHits->at(index) ); 
 }; 

 void ClearOutputconvNSharedHits( std::string  prefix ) { 

    std::string my_name = "convNSharedHits";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convNSharedHits, prefix = " << prefix << std::endl; 
     OUT::convNSharedHits->clear(); 
 }; 

 void CopyconvValidVtxInToOut( std::string prefix ) { 

    std::string my_name = "convValidVtx";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convValidVtx = std::vector<int>(*IN::convValidVtx);
}; 

 void CopyconvValidVtxInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convValidVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convValidVtx->size() ) {
         std::cout << "Vector size exceeded for branch IN::convValidVtx" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convValidVtx" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convValidVtx->push_back( IN::convValidVtx->at(index) ); 
 }; 

 void ClearOutputconvValidVtx( std::string  prefix ) { 

    std::string my_name = "convValidVtx";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convValidVtx, prefix = " << prefix << std::endl; 
     OUT::convValidVtx->clear(); 
 }; 

 void CopyconvMVALikelihoodInToOut( std::string prefix ) { 

    std::string my_name = "convMVALikelihood";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convMVALikelihood = std::vector<float>(*IN::convMVALikelihood);
}; 

 void CopyconvMVALikelihoodInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convMVALikelihood";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convMVALikelihood->size() ) {
         std::cout << "Vector size exceeded for branch IN::convMVALikelihood" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convMVALikelihood" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convMVALikelihood->push_back( IN::convMVALikelihood->at(index) ); 
 }; 

 void ClearOutputconvMVALikelihood( std::string  prefix ) { 

    std::string my_name = "convMVALikelihood";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convMVALikelihood, prefix = " << prefix << std::endl; 
     OUT::convMVALikelihood->clear(); 
 }; 

 void CopyconvChi2InToOut( std::string prefix ) { 

    std::string my_name = "convChi2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convChi2 = std::vector<float>(*IN::convChi2);
}; 

 void CopyconvChi2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convChi2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convChi2->size() ) {
         std::cout << "Vector size exceeded for branch IN::convChi2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convChi2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convChi2->push_back( IN::convChi2->at(index) ); 
 }; 

 void ClearOutputconvChi2( std::string  prefix ) { 

    std::string my_name = "convChi2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convChi2, prefix = " << prefix << std::endl; 
     OUT::convChi2->clear(); 
 }; 

 void CopyconvChi2ProbabilityInToOut( std::string prefix ) { 

    std::string my_name = "convChi2Probability";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convChi2Probability = std::vector<float>(*IN::convChi2Probability);
}; 

 void CopyconvChi2ProbabilityInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convChi2Probability";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convChi2Probability->size() ) {
         std::cout << "Vector size exceeded for branch IN::convChi2Probability" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convChi2Probability" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convChi2Probability->push_back( IN::convChi2Probability->at(index) ); 
 }; 

 void ClearOutputconvChi2Probability( std::string  prefix ) { 

    std::string my_name = "convChi2Probability";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convChi2Probability, prefix = " << prefix << std::endl; 
     OUT::convChi2Probability->clear(); 
 }; 

 void CopyconvTk1DzInToOut( std::string prefix ) { 

    std::string my_name = "convTk1Dz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk1Dz = std::vector<float>(*IN::convTk1Dz);
}; 

 void CopyconvTk1DzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk1Dz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk1Dz->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk1Dz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk1Dz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk1Dz->push_back( IN::convTk1Dz->at(index) ); 
 }; 

 void ClearOutputconvTk1Dz( std::string  prefix ) { 

    std::string my_name = "convTk1Dz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk1Dz, prefix = " << prefix << std::endl; 
     OUT::convTk1Dz->clear(); 
 }; 

 void CopyconvTk2DzInToOut( std::string prefix ) { 

    std::string my_name = "convTk2Dz";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk2Dz = std::vector<float>(*IN::convTk2Dz);
}; 

 void CopyconvTk2DzInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk2Dz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk2Dz->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk2Dz" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk2Dz" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk2Dz->push_back( IN::convTk2Dz->at(index) ); 
 }; 

 void ClearOutputconvTk2Dz( std::string  prefix ) { 

    std::string my_name = "convTk2Dz";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk2Dz, prefix = " << prefix << std::endl; 
     OUT::convTk2Dz->clear(); 
 }; 

 void CopyconvTk1DzErrInToOut( std::string prefix ) { 

    std::string my_name = "convTk1DzErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk1DzErr = std::vector<float>(*IN::convTk1DzErr);
}; 

 void CopyconvTk1DzErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk1DzErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk1DzErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk1DzErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk1DzErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk1DzErr->push_back( IN::convTk1DzErr->at(index) ); 
 }; 

 void ClearOutputconvTk1DzErr( std::string  prefix ) { 

    std::string my_name = "convTk1DzErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk1DzErr, prefix = " << prefix << std::endl; 
     OUT::convTk1DzErr->clear(); 
 }; 

 void CopyconvTk2DzErrInToOut( std::string prefix ) { 

    std::string my_name = "convTk2DzErr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk2DzErr = std::vector<float>(*IN::convTk2DzErr);
}; 

 void CopyconvTk2DzErrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk2DzErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk2DzErr->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk2DzErr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk2DzErr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk2DzErr->push_back( IN::convTk2DzErr->at(index) ); 
 }; 

 void ClearOutputconvTk2DzErr( std::string  prefix ) { 

    std::string my_name = "convTk2DzErr";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk2DzErr, prefix = " << prefix << std::endl; 
     OUT::convTk2DzErr->clear(); 
 }; 

 void CopyconvCh1Ch2InToOut( std::string prefix ) { 

    std::string my_name = "convCh1Ch2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convCh1Ch2 = std::vector<int>(*IN::convCh1Ch2);
}; 

 void CopyconvCh1Ch2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convCh1Ch2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convCh1Ch2->size() ) {
         std::cout << "Vector size exceeded for branch IN::convCh1Ch2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convCh1Ch2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convCh1Ch2->push_back( IN::convCh1Ch2->at(index) ); 
 }; 

 void ClearOutputconvCh1Ch2( std::string  prefix ) { 

    std::string my_name = "convCh1Ch2";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convCh1Ch2, prefix = " << prefix << std::endl; 
     OUT::convCh1Ch2->clear(); 
 }; 

 void CopyconvTk1D0InToOut( std::string prefix ) { 

    std::string my_name = "convTk1D0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk1D0 = std::vector<float>(*IN::convTk1D0);
}; 

 void CopyconvTk1D0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk1D0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk1D0->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk1D0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk1D0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk1D0->push_back( IN::convTk1D0->at(index) ); 
 }; 

 void ClearOutputconvTk1D0( std::string  prefix ) { 

    std::string my_name = "convTk1D0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk1D0, prefix = " << prefix << std::endl; 
     OUT::convTk1D0->clear(); 
 }; 

 void CopyconvTk1PoutInToOut( std::string prefix ) { 

    std::string my_name = "convTk1Pout";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk1Pout = std::vector<float>(*IN::convTk1Pout);
}; 

 void CopyconvTk1PoutInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk1Pout";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk1Pout->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk1Pout" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk1Pout" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk1Pout->push_back( IN::convTk1Pout->at(index) ); 
 }; 

 void ClearOutputconvTk1Pout( std::string  prefix ) { 

    std::string my_name = "convTk1Pout";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk1Pout, prefix = " << prefix << std::endl; 
     OUT::convTk1Pout->clear(); 
 }; 

 void CopyconvTk1PinInToOut( std::string prefix ) { 

    std::string my_name = "convTk1Pin";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk1Pin = std::vector<float>(*IN::convTk1Pin);
}; 

 void CopyconvTk1PinInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk1Pin";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk1Pin->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk1Pin" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk1Pin" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk1Pin->push_back( IN::convTk1Pin->at(index) ); 
 }; 

 void ClearOutputconvTk1Pin( std::string  prefix ) { 

    std::string my_name = "convTk1Pin";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk1Pin, prefix = " << prefix << std::endl; 
     OUT::convTk1Pin->clear(); 
 }; 

 void CopyconvTk2D0InToOut( std::string prefix ) { 

    std::string my_name = "convTk2D0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk2D0 = std::vector<float>(*IN::convTk2D0);
}; 

 void CopyconvTk2D0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk2D0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk2D0->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk2D0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk2D0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk2D0->push_back( IN::convTk2D0->at(index) ); 
 }; 

 void ClearOutputconvTk2D0( std::string  prefix ) { 

    std::string my_name = "convTk2D0";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk2D0, prefix = " << prefix << std::endl; 
     OUT::convTk2D0->clear(); 
 }; 

 void CopyconvTk2PoutInToOut( std::string prefix ) { 

    std::string my_name = "convTk2Pout";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk2Pout = std::vector<float>(*IN::convTk2Pout);
}; 

 void CopyconvTk2PoutInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk2Pout";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk2Pout->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk2Pout" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk2Pout" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk2Pout->push_back( IN::convTk2Pout->at(index) ); 
 }; 

 void ClearOutputconvTk2Pout( std::string  prefix ) { 

    std::string my_name = "convTk2Pout";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk2Pout, prefix = " << prefix << std::endl; 
     OUT::convTk2Pout->clear(); 
 }; 

 void CopyconvTk2PinInToOut( std::string prefix ) { 

    std::string my_name = "convTk2Pin";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::convTk2Pin = std::vector<float>(*IN::convTk2Pin);
}; 

 void CopyconvTk2PinInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "convTk2Pin";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::convTk2Pin->size() ) {
         std::cout << "Vector size exceeded for branch IN::convTk2Pin" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible convTk2Pin" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::convTk2Pin->push_back( IN::convTk2Pin->at(index) ); 
 }; 

 void ClearOutputconvTk2Pin( std::string  prefix ) { 

    std::string my_name = "convTk2Pin";
    std::size_t pos = my_name.find( prefix ); 
    std::size_t pos2 = my_name.find( "ph_sl" ); 
    if( pos2 != std::string::npos ) return; 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible convTk2Pin, prefix = " << prefix << std::endl; 
     OUT::convTk2Pin->clear(); 
 }; 

 