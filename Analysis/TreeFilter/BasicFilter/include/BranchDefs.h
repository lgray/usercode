#ifndef BRANCHDEFS_H
#define BRANCHDEFS_H
#include "TTree.h"
#include <vector>
//This next bit of code defines whether each branch
//exists or not.  This can be used to solve the problem
//when a branch in available in some ntuples, but not others.
//If this happens, the code will not compile because the
//branch is not written in the header file.  To fix this problem
//simply surround the offending code with #ifdef EXISTS_MYVAR ... #endif
//and if the variable does not exist the preprocessor will ignore that code#define EXISTS_nConv
#define EXISTS_nLowPtJet
#define EXISTS_nJet
#define EXISTS_nPFPho
#define EXISTS_nMu
#define EXISTS_nPho
#define EXISTS_nEle
#define EXISTS_nPUInfo
#define EXISTS_nMC
#define EXISTS_nVtxBS
#define EXISTS_nVtx
#define EXISTS_nHLT
#define EXISTS_run
#define EXISTS_event
#define EXISTS_lumis
#define EXISTS_isData
#define EXISTS_HLT
#define EXISTS_HLTIndex
#define EXISTS_bspotPos
#define EXISTS_vtx
#define EXISTS_IsVtxGood
#define EXISTS_nGoodVtx
#define EXISTS_vtxbs
#define EXISTS_pdf
#define EXISTS_pthat
#define EXISTS_processID
#define EXISTS_mcPID
#define EXISTS_mcVtx
#define EXISTS_mcPt
#define EXISTS_mcMass
#define EXISTS_mcEta
#define EXISTS_mcPhi
#define EXISTS_mcE
#define EXISTS_mcEt
#define EXISTS_mcGMomPID
#define EXISTS_mcMomPID
#define EXISTS_mcMomPt
#define EXISTS_mcMomMass
#define EXISTS_mcMomEta
#define EXISTS_mcMomPhi
#define EXISTS_mcIndex
#define EXISTS_mcDecayType
#define EXISTS_mcParentage
#define EXISTS_mcStatus
#define EXISTS_genMET
#define EXISTS_genMETPhi
#define EXISTS_nPU
#define EXISTS_puBX
#define EXISTS_puTrue
#define EXISTS_pfMET
#define EXISTS_pfMETPhi
#define EXISTS_pfMETsumEt
#define EXISTS_pfMETmEtSig
#define EXISTS_pfMETSig
#define EXISTS_recoPfMET
#define EXISTS_recoPfMETPhi
#define EXISTS_recoPfMETsumEt
#define EXISTS_recoPfMETmEtSig
#define EXISTS_recoPfMETSig
#define EXISTS_trkMETxPV
#define EXISTS_trkMETyPV
#define EXISTS_trkMETPhiPV
#define EXISTS_trkMETPV
#define EXISTS_trkMETx
#define EXISTS_trkMETy
#define EXISTS_trkMETPhi
#define EXISTS_trkMET
#define EXISTS_metFilters
#define EXISTS_eleTrg
#define EXISTS_eleClass
#define EXISTS_eleIsEcalDriven
#define EXISTS_eleCharge
#define EXISTS_eleEn
#define EXISTS_eleEcalEn
#define EXISTS_eleSCRawEn
#define EXISTS_eleSCEn
#define EXISTS_eleESEn
#define EXISTS_elePt
#define EXISTS_eleEta
#define EXISTS_elePhi
#define EXISTS_eleEtaVtx
#define EXISTS_elePhiVtx
#define EXISTS_eleEtVtx
#define EXISTS_eleSCEta
#define EXISTS_eleSCPhi
#define EXISTS_eleSCEtaWidth
#define EXISTS_eleSCPhiWidth
#define EXISTS_eleVtx
#define EXISTS_eleD0
#define EXISTS_eleDz
#define EXISTS_eleD0GV
#define EXISTS_eleDzGV
#define EXISTS_eleD0Vtx
#define EXISTS_eleDzVtx
#define EXISTS_eleHoverE
#define EXISTS_eleHoverE12
#define EXISTS_eleEoverP
#define EXISTS_elePin
#define EXISTS_elePout
#define EXISTS_eleTrkMomErr
#define EXISTS_eleBrem
#define EXISTS_eledEtaAtVtx
#define EXISTS_eledPhiAtVtx
#define EXISTS_eleSigmaIEtaIEta
#define EXISTS_eleSigmaIEtaIPhi
#define EXISTS_eleSigmaIPhiIPhi
#define EXISTS_eleEmax
#define EXISTS_eleE1x5
#define EXISTS_eleE3x3
#define EXISTS_eleE5x5
#define EXISTS_eleE2x5Max
#define EXISTS_eleRegrE
#define EXISTS_eleRegrEerr
#define EXISTS_elePhoRegrE
#define EXISTS_elePhoRegrEerr
#define EXISTS_eleSeedTime
#define EXISTS_eleRecoFlag
#define EXISTS_elePos
#define EXISTS_eleGenIndex
#define EXISTS_eleGenGMomPID
#define EXISTS_eleGenMomPID
#define EXISTS_eleGenMomPt
#define EXISTS_eleIsoTrkDR03
#define EXISTS_eleIsoEcalDR03
#define EXISTS_eleIsoHcalDR03
#define EXISTS_eleIsoHcalDR0312
#define EXISTS_eleIsoTrkDR04
#define EXISTS_eleIsoEcalDR04
#define EXISTS_eleIsoHcalDR04
#define EXISTS_eleIsoHcalDR0412
#define EXISTS_eleModIsoTrk
#define EXISTS_eleModIsoEcal
#define EXISTS_eleModIsoHcal
#define EXISTS_eleMissHits
#define EXISTS_eleConvDist
#define EXISTS_eleConvDcot
#define EXISTS_eleConvVtxFit
#define EXISTS_eleIP3D
#define EXISTS_eleIP3DErr
#define EXISTS_eleIDMVANonTrig
#define EXISTS_eleIDMVATrig
#define EXISTS_eleIDMVATrigIDIso
#define EXISTS_elePFChIso03
#define EXISTS_elePFPhoIso03
#define EXISTS_elePFNeuIso03
#define EXISTS_elePFChIso04
#define EXISTS_elePFPhoIso04
#define EXISTS_elePFNeuIso04
#define EXISTS_eleESEffSigmaRR
#define EXISTS_phoTrg
#define EXISTS_phoTrgFilter
#define EXISTS_phoIsPhoton
#define EXISTS_phoSCPos
#define EXISTS_phoCaloPos
#define EXISTS_phoE
#define EXISTS_phoEt
#define EXISTS_phoEta
#define EXISTS_phoVtx
#define EXISTS_phoPhi
#define EXISTS_phoEtVtx
#define EXISTS_phoEtaVtx
#define EXISTS_phoPhiVtx
#define EXISTS_phoR9
#define EXISTS_phoTrkIsoHollowDR03
#define EXISTS_phoEcalIsoDR03
#define EXISTS_phoHcalIsoDR03
#define EXISTS_phoHcalIsoDR0312
#define EXISTS_phoTrkIsoHollowDR04
#define EXISTS_phoCiCTrkIsoDR03
#define EXISTS_phoCiCTrkIsoDR04
#define EXISTS_phoCiCdRtoTrk
#define EXISTS_phoEcalIsoDR04
#define EXISTS_phoHcalIsoDR04
#define EXISTS_phoHcalIsoDR0412
#define EXISTS_phoHoverE
#define EXISTS_phoHoverE12
#define EXISTS_phoEleVeto
#define EXISTS_phoSigmaIEtaIEta
#define EXISTS_phoSigmaIEtaIPhi
#define EXISTS_phoSigmaIPhiIPhi
#define EXISTS_phoCiCPF4phopfIso03
#define EXISTS_phoCiCPF4phopfIso04
#define EXISTS_phoCiCPF4chgpfIso02
#define EXISTS_phoCiCPF4chgpfIso03
#define EXISTS_phoCiCPF4chgpfIso04
#define EXISTS_phoEmax
#define EXISTS_phoE3x3
#define EXISTS_phoE3x1
#define EXISTS_phoE1x3
#define EXISTS_phoE5x5
#define EXISTS_phoE1x5
#define EXISTS_phoE2x2
#define EXISTS_phoE2x5Max
#define EXISTS_phoPFChIso
#define EXISTS_phoPFPhoIso
#define EXISTS_phoPFNeuIso
#define EXISTS_phoSCRChIso
#define EXISTS_phoSCRPhoIso
#define EXISTS_phoSCRNeuIso
#define EXISTS_phoRegrE
#define EXISTS_phoRegrEerr
#define EXISTS_phoSeedTime
#define EXISTS_phoSeedDetId1
#define EXISTS_phoSeedDetId2
#define EXISTS_phoLICTD
#define EXISTS_phoRecoFlag
#define EXISTS_phoPos
#define EXISTS_phoGenIndex
#define EXISTS_phoGenGMomPID
#define EXISTS_phoGenMomPID
#define EXISTS_phoGenMomPt
#define EXISTS_phoSCE
#define EXISTS_phoSCRawE
#define EXISTS_phoESEn
#define EXISTS_phoSCEt
#define EXISTS_phoSCEta
#define EXISTS_phoSCPhi
#define EXISTS_phoSCEtaWidth
#define EXISTS_phoSCPhiWidth
#define EXISTS_phoSCBrem
#define EXISTS_phoOverlap
#define EXISTS_phohasPixelSeed
#define EXISTS_pho_hasConvPf
#define EXISTS_pho_hasSLConvPf
#define EXISTS_pho_pfconvVtxZ
#define EXISTS_pho_pfconvVtxZErr
#define EXISTS_pho_nSLConv
#define EXISTS_pho_pfSLConvPos
#define EXISTS_pho_pfSLConvVtxZ
#define EXISTS_phoIsConv
#define EXISTS_phoNConv
#define EXISTS_phoConvInvMass
#define EXISTS_phoConvCotTheta
#define EXISTS_phoConvEoverP
#define EXISTS_phoConvZofPVfromTrks
#define EXISTS_phoConvMinDist
#define EXISTS_phoConvdPhiAtVtx
#define EXISTS_phoConvdPhiAtCalo
#define EXISTS_phoConvdEtaAtCalo
#define EXISTS_phoConvTrkd0
#define EXISTS_phoConvTrkPin
#define EXISTS_phoConvTrkPout
#define EXISTS_phoConvTrkdz
#define EXISTS_phoConvTrkdzErr
#define EXISTS_phoConvChi2
#define EXISTS_phoConvChi2Prob
#define EXISTS_phoConvNTrks
#define EXISTS_phoConvCharge
#define EXISTS_phoConvValidVtx
#define EXISTS_phoConvLikeLihood
#define EXISTS_phoConvP4
#define EXISTS_phoConvVtx
#define EXISTS_phoConvVtxErr
#define EXISTS_phoConvPairMomentum
#define EXISTS_phoConvRefittedMomentum
#define EXISTS_SingleLegConv
#define EXISTS_phoPFConvVtx
#define EXISTS_phoPFConvMom
#define EXISTS_phoESEffSigmaRR
#define EXISTS_muTrg
#define EXISTS_muEta
#define EXISTS_muPhi
#define EXISTS_muCharge
#define EXISTS_muPt
#define EXISTS_muPz
#define EXISTS_muVtx
#define EXISTS_muVtxGlb
#define EXISTS_muGenIndex
#define EXISTS_mucktPt
#define EXISTS_mucktPtErr
#define EXISTS_mucktEta
#define EXISTS_mucktPhi
#define EXISTS_mucktdxy
#define EXISTS_mucktdz
#define EXISTS_muIsoTrk
#define EXISTS_muIsoCalo
#define EXISTS_muIsoEcal
#define EXISTS_muIsoHcal
#define EXISTS_muChi2NDF
#define EXISTS_muInnerChi2NDF
#define EXISTS_muPFIsoR04_CH
#define EXISTS_muPFIsoR04_NH
#define EXISTS_muPFIsoR04_Pho
#define EXISTS_muPFIsoR04_PU
#define EXISTS_muPFIsoR04_CPart
#define EXISTS_muPFIsoR04_NHHT
#define EXISTS_muPFIsoR04_PhoHT
#define EXISTS_muPFIsoR03_CH
#define EXISTS_muPFIsoR03_NH
#define EXISTS_muPFIsoR03_Pho
#define EXISTS_muPFIsoR03_PU
#define EXISTS_muPFIsoR03_CPart
#define EXISTS_muPFIsoR03_NHHT
#define EXISTS_muPFIsoR03_PhoHT
#define EXISTS_muType
#define EXISTS_muD0
#define EXISTS_muDz
#define EXISTS_muD0GV
#define EXISTS_muDzGV
#define EXISTS_muD0Vtx
#define EXISTS_muDzVtx
#define EXISTS_muInnerD0
#define EXISTS_muInnerDz
#define EXISTS_muInnerD0GV
#define EXISTS_muInnerDzGV
#define EXISTS_muInnerPt
#define EXISTS_muInnerPtErr
#define EXISTS_muNumberOfValidTrkLayers
#define EXISTS_muNumberOfValidTrkHits
#define EXISTS_muNumberOfValidPixelLayers
#define EXISTS_muNumberOfValidPixelHits
#define EXISTS_muNumberOfValidMuonHits
#define EXISTS_muStations
#define EXISTS_muChambers
#define EXISTS_muIP3D
#define EXISTS_muIP3DErr
#define EXISTS_PFPhoEt
#define EXISTS_PFPhoEta
#define EXISTS_PFPhoPhi
#define EXISTS_PFPhoType
#define EXISTS_PFPhoIso
#define EXISTS_rho25
#define EXISTS_rho25_neu
#define EXISTS_rho25_muPFiso
#define EXISTS_rho25_elePFiso
#define EXISTS_rho2011
#define EXISTS_rho2012
#define EXISTS_jetTrg
#define EXISTS_jetEn
#define EXISTS_jetPt
#define EXISTS_jetEta
#define EXISTS_jetPhi
#define EXISTS_jetCharge
#define EXISTS_jetEt
#define EXISTS_jetRawPt
#define EXISTS_jetRawEn
#define EXISTS_jetArea
#define EXISTS_jetCHF
#define EXISTS_jetNHF
#define EXISTS_jetCEF
#define EXISTS_jetNEF
#define EXISTS_jetNCH
#define EXISTS_jetHFHAE
#define EXISTS_jetHFEME
#define EXISTS_jetNConstituents
#define EXISTS_jetCombinedSecondaryVtxBJetTags
#define EXISTS_jetCombinedSecondaryVtxMVABJetTags
#define EXISTS_jetJetProbabilityBJetTags
#define EXISTS_jetJetBProbabilityBJetTags
#define EXISTS_jetTrackCountingHighPurBJetTags
#define EXISTS_jetBetaStar
#define EXISTS_jetPFLooseId
#define EXISTS_jetDRMean
#define EXISTS_jetDR2Mean
#define EXISTS_jetDZ
#define EXISTS_jetFrac01
#define EXISTS_jetFrac02
#define EXISTS_jetFrac03
#define EXISTS_jetFrac04
#define EXISTS_jetFrac05
#define EXISTS_jetFrac06
#define EXISTS_jetFrac07
#define EXISTS_jetBeta
#define EXISTS_jetBetaStarCMG
#define EXISTS_jetBetaStarClassic
#define EXISTS_jetBetaExt
#define EXISTS_jetBetaStarCMGExt
#define EXISTS_jetBetaStarClassicExt
#define EXISTS_jetNNeutrals
#define EXISTS_jetNCharged
#define EXISTS_jetMVAs
#define EXISTS_jetWPLevels
#define EXISTS_jetMVAsExt
#define EXISTS_jetWPLevelsExt
#define EXISTS_jetMt
#define EXISTS_jetJECUnc
#define EXISTS_jetLeadTrackPt
#define EXISTS_jetVtxPt
#define EXISTS_jetVtxMass
#define EXISTS_jetVtx3dL
#define EXISTS_jetVtx3deL
#define EXISTS_jetSoftLeptPt
#define EXISTS_jetSoftLeptPtRel
#define EXISTS_jetSoftLeptdR
#define EXISTS_jetSoftLeptIdlooseMu
#define EXISTS_jetSoftLeptIdEle95
#define EXISTS_jetDPhiMETJet
#define EXISTS_jetPuJetIdL
#define EXISTS_jetPuJetIdM
#define EXISTS_jetPuJetIdT
#define EXISTS_jetPartonID
#define EXISTS_jetGenJetIndex
#define EXISTS_jetGenJetEn
#define EXISTS_jetGenJetPt
#define EXISTS_jetGenJetEta
#define EXISTS_jetGenJetPhi
#define EXISTS_jetGenPartonID
#define EXISTS_jetGenEn
#define EXISTS_jetGenPt
#define EXISTS_jetGenEta
#define EXISTS_jetGenPhi
#define EXISTS_jetLowPtEn
#define EXISTS_jetLowPtPt
#define EXISTS_jetLowPtEta
#define EXISTS_jetLowPtPhi
#define EXISTS_jetLowPtCharge
#define EXISTS_jetLowPtEt
#define EXISTS_jetLowPtRawPt
#define EXISTS_jetLowPtRawEn
#define EXISTS_jetLowPtArea
#define EXISTS_jetLowPtPartonID
#define EXISTS_jetLowPtGenJetEn
#define EXISTS_jetLowPtGenJetPt
#define EXISTS_jetLowPtGenJetEta
#define EXISTS_jetLowPtGenJetPhi
#define EXISTS_jetLowPtGenPartonID
#define EXISTS_jetLowPtGenEn
#define EXISTS_jetLowPtGenPt
#define EXISTS_jetLowPtGenEta
#define EXISTS_jetLowPtGenPhi
#define EXISTS_convP4
#define EXISTS_convVtx
#define EXISTS_convVtxErr
#define EXISTS_convPairMomentum
#define EXISTS_convRefittedMomentum
#define EXISTS_convNTracks
#define EXISTS_convPairInvMass
#define EXISTS_convPairCotThetaSep
#define EXISTS_convEoverP
#define EXISTS_convDistOfMinApproach
#define EXISTS_convDPhiTrksAtVtx
#define EXISTS_convDPhiTrksAtEcal
#define EXISTS_convDEtaTrksAtEcal
#define EXISTS_convDxy
#define EXISTS_convDz
#define EXISTS_convLxy
#define EXISTS_convLz
#define EXISTS_convZofPrimVtxFromTrks
#define EXISTS_convNHitsBeforeVtx
#define EXISTS_convNSharedHits
#define EXISTS_convValidVtx
#define EXISTS_convMVALikelihood
#define EXISTS_convChi2
#define EXISTS_convChi2Probability
#define EXISTS_convTk1Dz
#define EXISTS_convTk2Dz
#define EXISTS_convTk1DzErr
#define EXISTS_convTk2DzErr
#define EXISTS_convCh1Ch2
#define EXISTS_convTk1D0
#define EXISTS_convTk1Pout
#define EXISTS_convTk1Pin
#define EXISTS_convTk2D0
#define EXISTS_convTk2Pout
#define EXISTS_convTk2Pin
//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions
namespace IN {
 extern Int_t				nConv;
 extern Int_t				nLowPtJet;
 extern Int_t				nJet;
 extern Int_t				nPFPho;
 extern Int_t				nMu;
 extern Int_t				nPho;
 extern Int_t				nEle;
 extern Int_t				nPUInfo;
 extern Int_t				nMC;
 extern Int_t				nVtxBS;
 extern Int_t				nVtx;
 extern Int_t				nHLT;
 extern Int_t				run;
 extern Long64_t				event;
 extern Int_t				lumis;
 extern Bool_t				isData;
 extern Int_t				HLT[444];
 extern Int_t				HLTIndex[70];
 extern Float_t				bspotPos[3];
 extern Float_t				vtx[63][3];
 extern Int_t				IsVtxGood;
 extern Int_t				nGoodVtx;
 extern Float_t				vtxbs[63][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[69];
 extern Float_t				mcVtx[69][3];
 extern Float_t				mcPt[69];
 extern Float_t				mcMass[69];
 extern Float_t				mcEta[69];
 extern Float_t				mcPhi[69];
 extern Float_t				mcE[69];
 extern Float_t				mcEt[69];
 extern Int_t				mcGMomPID[69];
 extern Int_t				mcMomPID[69];
 extern Float_t				mcMomPt[69];
 extern Float_t				mcMomMass[69];
 extern Float_t				mcMomEta[69];
 extern Float_t				mcMomPhi[69];
 extern Int_t				mcIndex[69];
 extern Int_t				mcDecayType[69];
 extern Int_t				mcParentage[69];
 extern Int_t				mcStatus[69];
 extern Float_t				genMET;
 extern Float_t				genMETPhi;
 extern Int_t				nPU[4];
 extern Int_t				puBX[4];
 extern Float_t				puTrue[4];
 extern Float_t				pfMET;
 extern Float_t				pfMETPhi;
 extern Float_t				pfMETsumEt;
 extern Float_t				pfMETmEtSig;
 extern Float_t				pfMETSig;
 extern Float_t				recoPfMET;
 extern Float_t				recoPfMETPhi;
 extern Float_t				recoPfMETsumEt;
 extern Float_t				recoPfMETmEtSig;
 extern Float_t				recoPfMETSig;
 extern Float_t				trkMETxPV;
 extern Float_t				trkMETyPV;
 extern Float_t				trkMETPhiPV;
 extern Float_t				trkMETPV;
 extern Float_t				trkMETx[63];
 extern Float_t				trkMETy[63];
 extern Float_t				trkMETPhi[63];
 extern Float_t				trkMET[63];
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[9][16];
 extern Int_t				eleClass[9];
 extern Int_t				eleIsEcalDriven[9];
 extern Int_t				eleCharge[9];
 extern Float_t				eleEn[9];
 extern Float_t				eleEcalEn[9];
 extern Float_t				eleSCRawEn[9];
 extern Float_t				eleSCEn[9];
 extern Float_t				eleESEn[9];
 extern Float_t				elePt[9];
 extern Float_t				eleEta[9];
 extern Float_t				elePhi[9];
 extern Float_t				eleEtaVtx[9][100];
 extern Float_t				elePhiVtx[9][100];
 extern Float_t				eleEtVtx[9][100];
 extern Float_t				eleSCEta[9];
 extern Float_t				eleSCPhi[9];
 extern Float_t				eleSCEtaWidth[9];
 extern Float_t				eleSCPhiWidth[9];
 extern Float_t				eleVtx[9][3];
 extern Float_t				eleD0[9];
 extern Float_t				eleDz[9];
 extern Float_t				eleD0GV[9];
 extern Float_t				eleDzGV[9];
 extern Float_t				eleD0Vtx[9][100];
 extern Float_t				eleDzVtx[9][100];
 extern Float_t				eleHoverE[9];
 extern Float_t				eleHoverE12[9];
 extern Float_t				eleEoverP[9];
 extern Float_t				elePin[9];
 extern Float_t				elePout[9];
 extern Float_t				eleTrkMomErr[9];
 extern Float_t				eleBrem[9];
 extern Float_t				eledEtaAtVtx[9];
 extern Float_t				eledPhiAtVtx[9];
 extern Float_t				eleSigmaIEtaIEta[9];
 extern Float_t				eleSigmaIEtaIPhi[9];
 extern Float_t				eleSigmaIPhiIPhi[9];
 extern Float_t				eleEmax[9];
 extern Float_t				eleE1x5[9];
 extern Float_t				eleE3x3[9];
 extern Float_t				eleE5x5[9];
 extern Float_t				eleE2x5Max[9];
 extern Float_t				eleRegrE[9];
 extern Float_t				eleRegrEerr[9];
 extern Float_t				elePhoRegrE[9];
 extern Float_t				elePhoRegrEerr[9];
 extern Float_t				eleSeedTime[9];
 extern Int_t				eleRecoFlag[9];
 extern Int_t				elePos[9];
 extern Int_t				eleGenIndex[9];
 extern Int_t				eleGenGMomPID[9];
 extern Int_t				eleGenMomPID[9];
 extern Float_t				eleGenMomPt[9];
 extern Float_t				eleIsoTrkDR03[9];
 extern Float_t				eleIsoEcalDR03[9];
 extern Float_t				eleIsoHcalDR03[9];
 extern Float_t				eleIsoHcalDR0312[9];
 extern Float_t				eleIsoTrkDR04[9];
 extern Float_t				eleIsoEcalDR04[9];
 extern Float_t				eleIsoHcalDR04[9];
 extern Float_t				eleIsoHcalDR0412[9];
 extern Float_t				eleModIsoTrk[9];
 extern Float_t				eleModIsoEcal[9];
 extern Float_t				eleModIsoHcal[9];
 extern Int_t				eleMissHits[9];
 extern Float_t				eleConvDist[9];
 extern Float_t				eleConvDcot[9];
 extern Int_t				eleConvVtxFit[9];
 extern Float_t				eleIP3D[9];
 extern Float_t				eleIP3DErr[9];
 extern Float_t				eleIDMVANonTrig[9];
 extern Float_t				eleIDMVATrig[9];
 extern Float_t				eleIDMVATrigIDIso[9];
 extern Float_t				elePFChIso03[9];
 extern Float_t				elePFPhoIso03[9];
 extern Float_t				elePFNeuIso03[9];
 extern Float_t				elePFChIso04[9];
 extern Float_t				elePFPhoIso04[9];
 extern Float_t				elePFNeuIso04[9];
 extern Float_t				eleESEffSigmaRR[9][3];
 extern Int_t				phoTrg[15][8];
 extern Int_t				phoTrgFilter[15][50];
 extern Bool_t				phoIsPhoton[15];
 extern Float_t				phoSCPos[15][3];
 extern Float_t				phoCaloPos[15][3];
 extern Float_t				phoE[15];
 extern Float_t				phoEt[15];
 extern Float_t				phoEta[15];
 extern Float_t				phoVtx[15][3];
 extern Float_t				phoPhi[15];
 extern Float_t				phoEtVtx[15][100];
 extern Float_t				phoEtaVtx[15][100];
 extern Float_t				phoPhiVtx[15][100];
 extern Float_t				phoR9[15];
 extern Float_t				phoTrkIsoHollowDR03[15];
 extern Float_t				phoEcalIsoDR03[15];
 extern Float_t				phoHcalIsoDR03[15];
 extern Float_t				phoHcalIsoDR0312[15];
 extern Float_t				phoTrkIsoHollowDR04[15];
 extern Float_t				phoCiCTrkIsoDR03[15][100];
 extern Float_t				phoCiCTrkIsoDR04[15][100];
 extern Float_t				phoCiCdRtoTrk[15];
 extern Float_t				phoEcalIsoDR04[15];
 extern Float_t				phoHcalIsoDR04[15];
 extern Float_t				phoHcalIsoDR0412[15];
 extern Float_t				phoHoverE[15];
 extern Float_t				phoHoverE12[15];
 extern Int_t				phoEleVeto[15];
 extern Float_t				phoSigmaIEtaIEta[15];
 extern Float_t				phoSigmaIEtaIPhi[15];
 extern Float_t				phoSigmaIPhiIPhi[15];
 extern Float_t				phoCiCPF4phopfIso03[15];
 extern Float_t				phoCiCPF4phopfIso04[15];
 extern Float_t				phoCiCPF4chgpfIso02[15][100];
 extern Float_t				phoCiCPF4chgpfIso03[15][100];
 extern Float_t				phoCiCPF4chgpfIso04[15][100];
 extern Float_t				phoEmax[15];
 extern Float_t				phoE3x3[15];
 extern Float_t				phoE3x1[15];
 extern Float_t				phoE1x3[15];
 extern Float_t				phoE5x5[15];
 extern Float_t				phoE1x5[15];
 extern Float_t				phoE2x2[15];
 extern Float_t				phoE2x5Max[15];
 extern Float_t				phoPFChIso[15];
 extern Float_t				phoPFPhoIso[15];
 extern Float_t				phoPFNeuIso[15];
 extern Float_t				phoSCRChIso[15];
 extern Float_t				phoSCRPhoIso[15];
 extern Float_t				phoSCRNeuIso[15];
 extern Float_t				phoRegrE[15];
 extern Float_t				phoRegrEerr[15];
 extern Float_t				phoSeedTime[15];
 extern Int_t				phoSeedDetId1[15];
 extern Int_t				phoSeedDetId2[15];
 extern Float_t				phoLICTD[15];
 extern Int_t				phoRecoFlag[15];
 extern Int_t				phoPos[15];
 extern Int_t				phoGenIndex[15];
 extern Int_t				phoGenGMomPID[15];
 extern Int_t				phoGenMomPID[15];
 extern Float_t				phoGenMomPt[15];
 extern Float_t				phoSCE[15];
 extern Float_t				phoSCRawE[15];
 extern Float_t				phoESEn[15];
 extern Float_t				phoSCEt[15];
 extern Float_t				phoSCEta[15];
 extern Float_t				phoSCPhi[15];
 extern Float_t				phoSCEtaWidth[15];
 extern Float_t				phoSCPhiWidth[15];
 extern Float_t				phoSCBrem[15];
 extern Int_t				phoOverlap[15];
 extern Int_t				phohasPixelSeed[15];
 extern Int_t				pho_hasConvPf[15];
 extern Int_t				pho_hasSLConvPf[15];
 extern Float_t				pho_pfconvVtxZ[15];
 extern Float_t				pho_pfconvVtxZErr[15];
 extern Int_t				pho_nSLConv[15];
 extern Float_t				pho_pfSLConvPos[15][20][3];
 extern Float_t				pho_pfSLConvVtxZ[15][20];
 extern Int_t				phoIsConv[15];
 extern Int_t				phoNConv[15];
 extern Float_t				phoConvInvMass[15];
 extern Float_t				phoConvCotTheta[15];
 extern Float_t				phoConvEoverP[15];
 extern Float_t				phoConvZofPVfromTrks[15];
 extern Float_t				phoConvMinDist[15];
 extern Float_t				phoConvdPhiAtVtx[15];
 extern Float_t				phoConvdPhiAtCalo[15];
 extern Float_t				phoConvdEtaAtCalo[15];
 extern Float_t				phoConvTrkd0[15][2];
 extern Float_t				phoConvTrkPin[15][2];
 extern Float_t				phoConvTrkPout[15][2];
 extern Float_t				phoConvTrkdz[15][2];
 extern Float_t				phoConvTrkdzErr[15][2];
 extern Float_t				phoConvChi2[15];
 extern Float_t				phoConvChi2Prob[15];
 extern Int_t				phoConvNTrks[15];
 extern Float_t				phoConvCharge[15][2];
 extern Float_t				phoConvValidVtx[15];
 extern Float_t				phoConvLikeLihood[15];
 extern Float_t				phoConvP4[15][4];
 extern Float_t				phoConvVtx[15][3];
 extern Float_t				phoConvVtxErr[15][3];
 extern Float_t				phoConvPairMomentum[15][3];
 extern Float_t				phoConvRefittedMomentum[15][3];
 extern Int_t				SingleLegConv[15];
 extern Float_t				phoPFConvVtx[15][3];
 extern Float_t				phoPFConvMom[15][3];
 extern Float_t				phoESEffSigmaRR[15][3];
 extern Int_t				muTrg[9][10];
 extern Float_t				muEta[9];
 extern Float_t				muPhi[9];
 extern Int_t				muCharge[9];
 extern Float_t				muPt[9];
 extern Float_t				muPz[9];
 extern Float_t				muVtx[9][3];
 extern Float_t				muVtxGlb[9][3];
 extern Int_t				muGenIndex[9];
 extern Float_t				mucktPt[9];
 extern Float_t				mucktPtErr[9];
 extern Float_t				mucktEta[9];
 extern Float_t				mucktPhi[9];
 extern Float_t				mucktdxy[9];
 extern Float_t				mucktdz[9];
 extern Float_t				muIsoTrk[9];
 extern Float_t				muIsoCalo[9];
 extern Float_t				muIsoEcal[9];
 extern Float_t				muIsoHcal[9];
 extern Float_t				muChi2NDF[9];
 extern Float_t				muInnerChi2NDF[9];
 extern Float_t				muPFIsoR04_CH[9];
 extern Float_t				muPFIsoR04_NH[9];
 extern Float_t				muPFIsoR04_Pho[9];
 extern Float_t				muPFIsoR04_PU[9];
 extern Float_t				muPFIsoR04_CPart[9];
 extern Float_t				muPFIsoR04_NHHT[9];
 extern Float_t				muPFIsoR04_PhoHT[9];
 extern Float_t				muPFIsoR03_CH[9];
 extern Float_t				muPFIsoR03_NH[9];
 extern Float_t				muPFIsoR03_Pho[9];
 extern Float_t				muPFIsoR03_PU[9];
 extern Float_t				muPFIsoR03_CPart[9];
 extern Float_t				muPFIsoR03_NHHT[9];
 extern Float_t				muPFIsoR03_PhoHT[9];
 extern Int_t				muType[9];
 extern Float_t				muD0[9];
 extern Float_t				muDz[9];
 extern Float_t				muD0GV[9];
 extern Float_t				muDzGV[9];
 extern Float_t				muD0Vtx[9][100];
 extern Float_t				muDzVtx[9][100];
 extern Float_t				muInnerD0[9];
 extern Float_t				muInnerDz[9];
 extern Float_t				muInnerD0GV[9];
 extern Float_t				muInnerDzGV[9];
 extern Float_t				muInnerPt[9];
 extern Float_t				muInnerPtErr[9];
 extern Int_t				muNumberOfValidTrkLayers[9];
 extern Int_t				muNumberOfValidTrkHits[9];
 extern Int_t				muNumberOfValidPixelLayers[9];
 extern Int_t				muNumberOfValidPixelHits[9];
 extern Int_t				muNumberOfValidMuonHits[9];
 extern Int_t				muStations[9];
 extern Int_t				muChambers[9];
 extern Float_t				muIP3D[9];
 extern Float_t				muIP3DErr[9];
 extern Float_t				PFPhoEt[44];
 extern Float_t				PFPhoEta[44];
 extern Float_t				PFPhoPhi[44];
 extern Int_t				PFPhoType[44];
 extern Float_t				PFPhoIso[44];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[93][14];
 extern Float_t				jetEn[93];
 extern Float_t				jetPt[93];
 extern Float_t				jetEta[93];
 extern Float_t				jetPhi[93];
 extern Float_t				jetCharge[93];
 extern Float_t				jetEt[93];
 extern Float_t				jetRawPt[93];
 extern Float_t				jetRawEn[93];
 extern Float_t				jetArea[93];
 extern Float_t				jetCHF[93];
 extern Float_t				jetNHF[93];
 extern Float_t				jetCEF[93];
 extern Float_t				jetNEF[93];
 extern Int_t				jetNCH[93];
 extern Float_t				jetHFHAE[93];
 extern Float_t				jetHFEME[93];
 extern Int_t				jetNConstituents[93];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[93];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[93];
 extern Float_t				jetJetProbabilityBJetTags[93];
 extern Float_t				jetJetBProbabilityBJetTags[93];
 extern Float_t				jetTrackCountingHighPurBJetTags[93];
 extern Float_t				jetBetaStar[93][100];
 extern Bool_t				jetPFLooseId[93];
 extern Float_t				jetDRMean[93];
 extern Float_t				jetDR2Mean[93];
 extern Float_t				jetDZ[93];
 extern Float_t				jetFrac01[93];
 extern Float_t				jetFrac02[93];
 extern Float_t				jetFrac03[93];
 extern Float_t				jetFrac04[93];
 extern Float_t				jetFrac05[93];
 extern Float_t				jetFrac06[93];
 extern Float_t				jetFrac07[93];
 extern Float_t				jetBeta[93];
 extern Float_t				jetBetaStarCMG[93];
 extern Float_t				jetBetaStarClassic[93];
 extern Float_t				jetBetaExt[93][100];
 extern Float_t				jetBetaStarCMGExt[93][100];
 extern Float_t				jetBetaStarClassicExt[93][100];
 extern Float_t				jetNNeutrals[93];
 extern Float_t				jetNCharged[93];
 extern Float_t				jetMVAs[93][4];
 extern Int_t				jetWPLevels[93][4];
 extern Float_t				jetMVAsExt[93][4][100];
 extern Int_t				jetWPLevelsExt[93][4][100];
 extern Float_t				jetMt[93];
 extern Float_t				jetJECUnc[93];
 extern Float_t				jetLeadTrackPt[93];
 extern Float_t				jetVtxPt[93];
 extern Float_t				jetVtxMass[93];
 extern Float_t				jetVtx3dL[93];
 extern Float_t				jetVtx3deL[93];
 extern Float_t				jetSoftLeptPt[93];
 extern Float_t				jetSoftLeptPtRel[93];
 extern Float_t				jetSoftLeptdR[93];
 extern Float_t				jetSoftLeptIdlooseMu[93];
 extern Float_t				jetSoftLeptIdEle95[93];
 extern Float_t				jetDPhiMETJet[93];
 extern Float_t				jetPuJetIdL[93];
 extern Float_t				jetPuJetIdM[93];
 extern Float_t				jetPuJetIdT[93];
 extern Int_t				jetPartonID[93];
 extern Int_t				jetGenJetIndex[93];
 extern Float_t				jetGenJetEn[93];
 extern Float_t				jetGenJetPt[93];
 extern Float_t				jetGenJetEta[93];
 extern Float_t				jetGenJetPhi[93];
 extern Int_t				jetGenPartonID[93];
 extern Float_t				jetGenEn[93];
 extern Float_t				jetGenPt[93];
 extern Float_t				jetGenEta[93];
 extern Float_t				jetGenPhi[93];
 extern Float_t				jetLowPtEn[64];
 extern Float_t				jetLowPtPt[64];
 extern Float_t				jetLowPtEta[64];
 extern Float_t				jetLowPtPhi[64];
 extern Float_t				jetLowPtCharge[64];
 extern Float_t				jetLowPtEt[64];
 extern Float_t				jetLowPtRawPt[64];
 extern Float_t				jetLowPtRawEn[64];
 extern Float_t				jetLowPtArea[64];
 extern Int_t				jetLowPtPartonID[64];
 extern Float_t				jetLowPtGenJetEn[64];
 extern Float_t				jetLowPtGenJetPt[64];
 extern Float_t				jetLowPtGenJetEta[64];
 extern Float_t				jetLowPtGenJetPhi[64];
 extern Int_t				jetLowPtGenPartonID[64];
 extern Float_t				jetLowPtGenEn[64];
 extern Float_t				jetLowPtGenPt[64];
 extern Float_t				jetLowPtGenEta[64];
 extern Float_t				jetLowPtGenPhi[64];
 extern Float_t				convP4[113][4];
 extern Float_t				convVtx[113][3];
 extern Float_t				convVtxErr[113][3];
 extern Float_t				convPairMomentum[113][3];
 extern Float_t				convRefittedMomentum[113][3];
 extern Int_t				convNTracks[113];
 extern Float_t				convPairInvMass[113];
 extern Float_t				convPairCotThetaSep[113];
 extern Float_t				convEoverP[113];
 extern Float_t				convDistOfMinApproach[113];
 extern Float_t				convDPhiTrksAtVtx[113];
 extern Float_t				convDPhiTrksAtEcal[113];
 extern Float_t				convDEtaTrksAtEcal[113];
 extern Float_t				convDxy[113];
 extern Float_t				convDz[113];
 extern Float_t				convLxy[113];
 extern Float_t				convLz[113];
 extern Float_t				convZofPrimVtxFromTrks[113];
 extern Int_t				convNHitsBeforeVtx[113][2];
 extern Int_t				convNSharedHits[113];
 extern Int_t				convValidVtx[113];
 extern Float_t				convMVALikelihood[113];
 extern Float_t				convChi2[113];
 extern Float_t				convChi2Probability[113];
 extern Float_t				convTk1Dz[113];
 extern Float_t				convTk2Dz[113];
 extern Float_t				convTk1DzErr[113];
 extern Float_t				convTk2DzErr[113];
 extern Int_t				convCh1Ch2[113];
 extern Float_t				convTk1D0[113];
 extern Float_t				convTk1Pout[113];
 extern Float_t				convTk1Pin[113];
 extern Float_t				convTk2D0[113];
 extern Float_t				convTk2Pout[113];
 extern Float_t				convTk2Pin[113];
};
namespace OUT {
 extern Int_t				nPho;
 extern Float_t				phoE[15];
 extern Float_t				phoEt[15];
 extern Float_t				phoEta[15];
 extern Float_t				phoPhi[15];
 extern Float_t				phoSigmaIEtaIEta[15];
 extern Float_t				phoSCEta[15];
};
#endif
