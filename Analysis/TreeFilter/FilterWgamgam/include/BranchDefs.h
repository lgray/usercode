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
//and if the variable does not exist the preprocessor will ignore that code#define EXISTS_nHLT
#define EXISTS_nVtx
#define EXISTS_nVtxBS
#define EXISTS_nMC
#define EXISTS_nPUInfo
#define EXISTS_nEle
#define EXISTS_nPho
#define EXISTS_nMu
#define EXISTS_nPFPho
#define EXISTS_nJet
#define EXISTS_nConv
#define EXISTS_nLowPtJet
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
#define EXISTS_mcPt
#define EXISTS_mcEta
#define EXISTS_mcPhi
#define EXISTS_mcE
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
#define EXISTS_eleSCEta
#define EXISTS_eleSCPhi
#define EXISTS_eleSCEtaWidth
#define EXISTS_eleSCPhiWidth
#define EXISTS_eleVtx
#define EXISTS_eleD0
#define EXISTS_eleDz
#define EXISTS_eleD0GV
#define EXISTS_eleDzGV
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
#define EXISTS_phoR9
#define EXISTS_phoTrkIsoHollowDR03
#define EXISTS_phoEcalIsoDR03
#define EXISTS_phoHcalIsoDR03
#define EXISTS_phoHcalIsoDR0312
#define EXISTS_phoTrkIsoHollowDR04
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
#define EXISTS_jetNNeutrals
#define EXISTS_jetNCharged
#define EXISTS_jetMVAs
#define EXISTS_jetWPLevels
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
 extern Int_t				nHLT;
 extern Int_t				nVtx;
 extern Int_t				nVtxBS;
 extern Int_t				nMC;
 extern Int_t				nPUInfo;
 extern Int_t				nEle;
 extern Int_t				nPho;
 extern Int_t				nMu;
 extern Int_t				nPFPho;
 extern Int_t				nJet;
 extern Int_t				nConv;
 extern Int_t				nLowPtJet;
 extern Int_t				run;
 extern Long64_t				event;
 extern Int_t				lumis;
 extern Bool_t				isData;
 extern Int_t				HLT[444];
 extern Int_t				HLTIndex[70];
 extern Float_t				bspotPos[3];
 extern Float_t				vtx[62][3];
 extern Int_t				IsVtxGood;
 extern Int_t				nGoodVtx;
 extern Float_t				vtxbs[61][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[84];
 extern Float_t				mcPt[84];
 extern Float_t				mcEta[84];
 extern Float_t				mcPhi[84];
 extern Float_t				mcE[84];
 extern Int_t				mcGMomPID[84];
 extern Int_t				mcMomPID[84];
 extern Float_t				mcMomPt[84];
 extern Float_t				mcMomMass[84];
 extern Float_t				mcMomEta[84];
 extern Float_t				mcMomPhi[84];
 extern Int_t				mcIndex[84];
 extern Int_t				mcDecayType[84];
 extern Int_t				mcParentage[84];
 extern Int_t				mcStatus[84];
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
 extern Float_t				trkMETx[61];
 extern Float_t				trkMETy[61];
 extern Float_t				trkMETPhi[61];
 extern Float_t				trkMET[61];
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[5][16];
 extern Int_t				eleClass[5];
 extern Int_t				eleIsEcalDriven[5];
 extern Int_t				eleCharge[5];
 extern Float_t				eleEn[5];
 extern Float_t				eleEcalEn[5];
 extern Float_t				eleSCRawEn[5];
 extern Float_t				eleSCEn[5];
 extern Float_t				eleESEn[5];
 extern Float_t				elePt[5];
 extern Float_t				eleEta[5];
 extern Float_t				elePhi[5];
 extern Float_t				eleSCEta[5];
 extern Float_t				eleSCPhi[5];
 extern Float_t				eleSCEtaWidth[5];
 extern Float_t				eleSCPhiWidth[5];
 extern Float_t				eleVtx[5][3];
 extern Float_t				eleD0[5];
 extern Float_t				eleDz[5];
 extern Float_t				eleD0GV[5];
 extern Float_t				eleDzGV[5];
 extern Float_t				eleHoverE[5];
 extern Float_t				eleHoverE12[5];
 extern Float_t				eleEoverP[5];
 extern Float_t				elePin[5];
 extern Float_t				elePout[5];
 extern Float_t				eleTrkMomErr[5];
 extern Float_t				eleBrem[5];
 extern Float_t				eledEtaAtVtx[5];
 extern Float_t				eledPhiAtVtx[5];
 extern Float_t				eleSigmaIEtaIEta[5];
 extern Float_t				eleSigmaIEtaIPhi[5];
 extern Float_t				eleSigmaIPhiIPhi[5];
 extern Float_t				eleEmax[5];
 extern Float_t				eleE1x5[5];
 extern Float_t				eleE3x3[5];
 extern Float_t				eleE5x5[5];
 extern Float_t				eleE2x5Max[5];
 extern Float_t				eleRegrE[5];
 extern Float_t				eleRegrEerr[5];
 extern Float_t				elePhoRegrE[5];
 extern Float_t				elePhoRegrEerr[5];
 extern Float_t				eleSeedTime[5];
 extern Int_t				eleRecoFlag[5];
 extern Int_t				elePos[5];
 extern Int_t				eleGenIndex[5];
 extern Int_t				eleGenGMomPID[5];
 extern Int_t				eleGenMomPID[5];
 extern Float_t				eleGenMomPt[5];
 extern Float_t				eleIsoTrkDR03[5];
 extern Float_t				eleIsoEcalDR03[5];
 extern Float_t				eleIsoHcalDR03[5];
 extern Float_t				eleIsoHcalDR0312[5];
 extern Float_t				eleIsoTrkDR04[5];
 extern Float_t				eleIsoEcalDR04[5];
 extern Float_t				eleIsoHcalDR04[5];
 extern Float_t				eleIsoHcalDR0412[5];
 extern Float_t				eleModIsoTrk[5];
 extern Float_t				eleModIsoEcal[5];
 extern Float_t				eleModIsoHcal[5];
 extern Int_t				eleMissHits[5];
 extern Float_t				eleConvDist[5];
 extern Float_t				eleConvDcot[5];
 extern Int_t				eleConvVtxFit[5];
 extern Float_t				eleIP3D[5];
 extern Float_t				eleIP3DErr[5];
 extern Float_t				eleIDMVANonTrig[5];
 extern Float_t				eleIDMVATrig[5];
 extern Float_t				eleIDMVATrigIDIso[5];
 extern Float_t				elePFChIso03[5];
 extern Float_t				elePFPhoIso03[5];
 extern Float_t				elePFNeuIso03[5];
 extern Float_t				elePFChIso04[5];
 extern Float_t				elePFPhoIso04[5];
 extern Float_t				elePFNeuIso04[5];
 extern Float_t				eleESEffSigmaRR[5][3];
 extern Int_t				phoTrg[16][8];
 extern Int_t				phoTrgFilter[16][50];
 extern Bool_t				phoIsPhoton[16];
 extern Float_t				phoSCPos[16][3];
 extern Float_t				phoCaloPos[16][3];
 extern Float_t				phoE[16];
 extern Float_t				phoEt[16];
 extern Float_t				phoEta[16];
 extern Float_t				phoVtx[16][3];
 extern Float_t				phoPhi[16];
 extern Float_t				phoR9[16];
 extern Float_t				phoTrkIsoHollowDR03[16];
 extern Float_t				phoEcalIsoDR03[16];
 extern Float_t				phoHcalIsoDR03[16];
 extern Float_t				phoHcalIsoDR0312[16];
 extern Float_t				phoTrkIsoHollowDR04[16];
 extern Float_t				phoCiCdRtoTrk[16];
 extern Float_t				phoEcalIsoDR04[16];
 extern Float_t				phoHcalIsoDR04[16];
 extern Float_t				phoHcalIsoDR0412[16];
 extern Float_t				phoHoverE[16];
 extern Float_t				phoHoverE12[16];
 extern Int_t				phoEleVeto[16];
 extern Float_t				phoSigmaIEtaIEta[16];
 extern Float_t				phoSigmaIEtaIPhi[16];
 extern Float_t				phoSigmaIPhiIPhi[16];
 extern Float_t				phoCiCPF4phopfIso03[16];
 extern Float_t				phoCiCPF4phopfIso04[16];
 extern Float_t				phoEmax[16];
 extern Float_t				phoE3x3[16];
 extern Float_t				phoE3x1[16];
 extern Float_t				phoE1x3[16];
 extern Float_t				phoE5x5[16];
 extern Float_t				phoE1x5[16];
 extern Float_t				phoE2x2[16];
 extern Float_t				phoE2x5Max[16];
 extern Float_t				phoPFChIso[16];
 extern Float_t				phoPFPhoIso[16];
 extern Float_t				phoPFNeuIso[16];
 extern Float_t				phoSCRChIso[16];
 extern Float_t				phoSCRPhoIso[16];
 extern Float_t				phoSCRNeuIso[16];
 extern Float_t				phoRegrE[16];
 extern Float_t				phoRegrEerr[16];
 extern Float_t				phoSeedTime[16];
 extern Int_t				phoSeedDetId1[16];
 extern Int_t				phoSeedDetId2[16];
 extern Float_t				phoLICTD[16];
 extern Int_t				phoRecoFlag[16];
 extern Int_t				phoPos[16];
 extern Int_t				phoGenIndex[16];
 extern Int_t				phoGenGMomPID[16];
 extern Int_t				phoGenMomPID[16];
 extern Float_t				phoGenMomPt[16];
 extern Float_t				phoSCE[16];
 extern Float_t				phoSCRawE[16];
 extern Float_t				phoESEn[16];
 extern Float_t				phoSCEt[16];
 extern Float_t				phoSCEta[16];
 extern Float_t				phoSCPhi[16];
 extern Float_t				phoSCEtaWidth[16];
 extern Float_t				phoSCPhiWidth[16];
 extern Float_t				phoSCBrem[16];
 extern Int_t				phoOverlap[16];
 extern Int_t				phohasPixelSeed[16];
 extern Int_t				pho_hasConvPf[16];
 extern Int_t				pho_hasSLConvPf[16];
 extern Float_t				pho_pfconvVtxZ[16];
 extern Float_t				pho_pfconvVtxZErr[16];
 extern Int_t				pho_nSLConv[16];
 extern Float_t				pho_pfSLConvPos[16][20][3];
 extern Float_t				pho_pfSLConvVtxZ[16][20];
 extern Int_t				phoIsConv[16];
 extern Int_t				phoNConv[16];
 extern Float_t				phoConvInvMass[16];
 extern Float_t				phoConvCotTheta[16];
 extern Float_t				phoConvEoverP[16];
 extern Float_t				phoConvZofPVfromTrks[16];
 extern Float_t				phoConvMinDist[16];
 extern Float_t				phoConvdPhiAtVtx[16];
 extern Float_t				phoConvdPhiAtCalo[16];
 extern Float_t				phoConvdEtaAtCalo[16];
 extern Float_t				phoConvTrkd0[16][2];
 extern Float_t				phoConvTrkPin[16][2];
 extern Float_t				phoConvTrkPout[16][2];
 extern Float_t				phoConvTrkdz[16][2];
 extern Float_t				phoConvTrkdzErr[16][2];
 extern Float_t				phoConvChi2[16];
 extern Float_t				phoConvChi2Prob[16];
 extern Int_t				phoConvNTrks[16];
 extern Float_t				phoConvCharge[16][2];
 extern Float_t				phoConvValidVtx[16];
 extern Float_t				phoConvLikeLihood[16];
 extern Float_t				phoConvP4[16][4];
 extern Float_t				phoConvVtx[16][3];
 extern Float_t				phoConvVtxErr[16][3];
 extern Float_t				phoConvPairMomentum[16][3];
 extern Float_t				phoConvRefittedMomentum[16][3];
 extern Int_t				SingleLegConv[16];
 extern Float_t				phoPFConvVtx[16][3];
 extern Float_t				phoPFConvMom[16][3];
 extern Float_t				phoESEffSigmaRR[16][3];
 extern Int_t				muTrg[8][10];
 extern Float_t				muEta[8];
 extern Float_t				muPhi[8];
 extern Int_t				muCharge[8];
 extern Float_t				muPt[8];
 extern Float_t				muPz[8];
 extern Float_t				muVtx[8][3];
 extern Float_t				muVtxGlb[8][3];
 extern Int_t				muGenIndex[8];
 extern Float_t				mucktPt[8];
 extern Float_t				mucktPtErr[8];
 extern Float_t				mucktEta[8];
 extern Float_t				mucktPhi[8];
 extern Float_t				mucktdxy[8];
 extern Float_t				mucktdz[8];
 extern Float_t				muIsoTrk[8];
 extern Float_t				muIsoCalo[8];
 extern Float_t				muIsoEcal[8];
 extern Float_t				muIsoHcal[8];
 extern Float_t				muChi2NDF[8];
 extern Float_t				muInnerChi2NDF[8];
 extern Float_t				muPFIsoR04_CH[8];
 extern Float_t				muPFIsoR04_NH[8];
 extern Float_t				muPFIsoR04_Pho[8];
 extern Float_t				muPFIsoR04_PU[8];
 extern Float_t				muPFIsoR04_CPart[8];
 extern Float_t				muPFIsoR04_NHHT[8];
 extern Float_t				muPFIsoR04_PhoHT[8];
 extern Float_t				muPFIsoR03_CH[8];
 extern Float_t				muPFIsoR03_NH[8];
 extern Float_t				muPFIsoR03_Pho[8];
 extern Float_t				muPFIsoR03_PU[8];
 extern Float_t				muPFIsoR03_CPart[8];
 extern Float_t				muPFIsoR03_NHHT[8];
 extern Float_t				muPFIsoR03_PhoHT[8];
 extern Int_t				muType[8];
 extern Float_t				muD0[8];
 extern Float_t				muDz[8];
 extern Float_t				muD0GV[8];
 extern Float_t				muDzGV[8];
 extern Float_t				muInnerD0[8];
 extern Float_t				muInnerDz[8];
 extern Float_t				muInnerD0GV[8];
 extern Float_t				muInnerDzGV[8];
 extern Float_t				muInnerPt[8];
 extern Float_t				muInnerPtErr[8];
 extern Int_t				muNumberOfValidTrkLayers[8];
 extern Int_t				muNumberOfValidTrkHits[8];
 extern Int_t				muNumberOfValidPixelLayers[8];
 extern Int_t				muNumberOfValidPixelHits[8];
 extern Int_t				muNumberOfValidMuonHits[8];
 extern Int_t				muStations[8];
 extern Int_t				muChambers[8];
 extern Float_t				muIP3D[8];
 extern Float_t				muIP3DErr[8];
 extern Float_t				PFPhoEt[54];
 extern Float_t				PFPhoEta[54];
 extern Float_t				PFPhoPhi[54];
 extern Int_t				PFPhoType[54];
 extern Float_t				PFPhoIso[54];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[19][14];
 extern Float_t				jetEn[19];
 extern Float_t				jetPt[19];
 extern Float_t				jetEta[19];
 extern Float_t				jetPhi[19];
 extern Float_t				jetCharge[19];
 extern Float_t				jetEt[19];
 extern Float_t				jetRawPt[19];
 extern Float_t				jetRawEn[19];
 extern Float_t				jetArea[19];
 extern Float_t				jetCHF[19];
 extern Float_t				jetNHF[19];
 extern Float_t				jetCEF[19];
 extern Float_t				jetNEF[19];
 extern Int_t				jetNCH[19];
 extern Float_t				jetHFHAE[19];
 extern Float_t				jetHFEME[19];
 extern Int_t				jetNConstituents[19];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[19];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[19];
 extern Float_t				jetJetProbabilityBJetTags[19];
 extern Float_t				jetJetBProbabilityBJetTags[19];
 extern Float_t				jetTrackCountingHighPurBJetTags[19];
 extern Float_t				jetBetaStar[19][100];
 extern Bool_t				jetPFLooseId[19];
 extern Float_t				jetDRMean[19];
 extern Float_t				jetDR2Mean[19];
 extern Float_t				jetDZ[19];
 extern Float_t				jetFrac01[19];
 extern Float_t				jetFrac02[19];
 extern Float_t				jetFrac03[19];
 extern Float_t				jetFrac04[19];
 extern Float_t				jetFrac05[19];
 extern Float_t				jetFrac06[19];
 extern Float_t				jetFrac07[19];
 extern Float_t				jetBeta[19];
 extern Float_t				jetBetaStarCMG[19];
 extern Float_t				jetBetaStarClassic[19];
 extern Float_t				jetBetaExt[19][100];
 extern Float_t				jetNNeutrals[19];
 extern Float_t				jetNCharged[19];
 extern Float_t				jetMVAs[19][4];
 extern Int_t				jetWPLevels[19][4];
 extern Float_t				jetMt[19];
 extern Float_t				jetJECUnc[19];
 extern Float_t				jetLeadTrackPt[19];
 extern Float_t				jetVtxPt[19];
 extern Float_t				jetVtxMass[19];
 extern Float_t				jetVtx3dL[19];
 extern Float_t				jetVtx3deL[19];
 extern Float_t				jetSoftLeptPt[19];
 extern Float_t				jetSoftLeptPtRel[19];
 extern Float_t				jetSoftLeptdR[19];
 extern Float_t				jetSoftLeptIdlooseMu[19];
 extern Float_t				jetSoftLeptIdEle95[19];
 extern Float_t				jetDPhiMETJet[19];
 extern Float_t				jetPuJetIdL[19];
 extern Float_t				jetPuJetIdM[19];
 extern Float_t				jetPuJetIdT[19];
 extern Int_t				jetPartonID[19];
 extern Int_t				jetGenJetIndex[19];
 extern Float_t				jetGenJetEn[19];
 extern Float_t				jetGenJetPt[19];
 extern Float_t				jetGenJetEta[19];
 extern Float_t				jetGenJetPhi[19];
 extern Int_t				jetGenPartonID[19];
 extern Float_t				jetGenEn[19];
 extern Float_t				jetGenPt[19];
 extern Float_t				jetGenEta[19];
 extern Float_t				jetGenPhi[19];
 extern Float_t				convVtx[178][3];
 extern Float_t				convVtxErr[178][3];
 extern Float_t				convPairMomentum[178][3];
 extern Float_t				convRefittedMomentum[178][3];
 extern Int_t				convNTracks[178];
 extern Float_t				convPairInvMass[178];
 extern Float_t				convPairCotThetaSep[178];
 extern Float_t				convEoverP[178];
 extern Float_t				convDistOfMinApproach[178];
 extern Float_t				convDPhiTrksAtVtx[178];
 extern Float_t				convDPhiTrksAtEcal[178];
 extern Float_t				convDEtaTrksAtEcal[178];
 extern Float_t				convDxy[178];
 extern Float_t				convDz[178];
 extern Float_t				convLxy[178];
 extern Float_t				convLz[178];
 extern Float_t				convZofPrimVtxFromTrks[178];
 extern Int_t				convNHitsBeforeVtx[178][2];
 extern Int_t				convNSharedHits[178];
 extern Int_t				convValidVtx[178];
 extern Float_t				convMVALikelihood[178];
 extern Float_t				convChi2[178];
 extern Float_t				convChi2Probability[178];
 extern Float_t				convTk1Dz[178];
 extern Float_t				convTk2Dz[178];
 extern Float_t				convTk1DzErr[178];
 extern Float_t				convTk2DzErr[178];
 extern Int_t				convCh1Ch2[178];
 extern Float_t				convTk1D0[178];
 extern Float_t				convTk1Pout[178];
 extern Float_t				convTk1Pin[178];
 extern Float_t				convTk2D0[178];
 extern Float_t				convTk2Pout[178];
 extern Float_t				convTk2Pin[178];
};
namespace OUT {
 extern Int_t				nHLT;
 extern Int_t				nVtx;
 extern Int_t				nVtxBS;
 extern Int_t				nMC;
 extern Int_t				nPUInfo;
 extern Int_t				nEle;
 extern Int_t				nPho;
 extern Int_t				nMu;
 extern Int_t				nPFPho;
 extern Int_t				nJet;
 extern Int_t				nConv;
 extern Int_t				nLowPtJet;
 extern Int_t				run;
 extern Long64_t				event;
 extern Int_t				lumis;
 extern Bool_t				isData;
 extern Int_t				HLT[444];
 extern Int_t				HLTIndex[70];
 extern Float_t				bspotPos[3];
 extern Float_t				vtx[62][3];
 extern Int_t				IsVtxGood;
 extern Int_t				nGoodVtx;
 extern Float_t				vtxbs[61][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[84];
 extern Float_t				mcPt[84];
 extern Float_t				mcEta[84];
 extern Float_t				mcPhi[84];
 extern Float_t				mcE[84];
 extern Int_t				mcGMomPID[84];
 extern Int_t				mcMomPID[84];
 extern Float_t				mcMomPt[84];
 extern Float_t				mcMomMass[84];
 extern Float_t				mcMomEta[84];
 extern Float_t				mcMomPhi[84];
 extern Int_t				mcIndex[84];
 extern Int_t				mcDecayType[84];
 extern Int_t				mcParentage[84];
 extern Int_t				mcStatus[84];
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
 extern Float_t				trkMETx[61];
 extern Float_t				trkMETy[61];
 extern Float_t				trkMETPhi[61];
 extern Float_t				trkMET[61];
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[5][16];
 extern Int_t				eleClass[5];
 extern Int_t				eleIsEcalDriven[5];
 extern Int_t				eleCharge[5];
 extern Float_t				eleEn[5];
 extern Float_t				eleEcalEn[5];
 extern Float_t				eleSCRawEn[5];
 extern Float_t				eleSCEn[5];
 extern Float_t				eleESEn[5];
 extern Float_t				elePt[5];
 extern Float_t				eleEta[5];
 extern Float_t				elePhi[5];
 extern Float_t				eleSCEta[5];
 extern Float_t				eleSCPhi[5];
 extern Float_t				eleSCEtaWidth[5];
 extern Float_t				eleSCPhiWidth[5];
 extern Float_t				eleVtx[5][3];
 extern Float_t				eleD0[5];
 extern Float_t				eleDz[5];
 extern Float_t				eleD0GV[5];
 extern Float_t				eleDzGV[5];
 extern Float_t				eleHoverE[5];
 extern Float_t				eleHoverE12[5];
 extern Float_t				eleEoverP[5];
 extern Float_t				elePin[5];
 extern Float_t				elePout[5];
 extern Float_t				eleTrkMomErr[5];
 extern Float_t				eleBrem[5];
 extern Float_t				eledEtaAtVtx[5];
 extern Float_t				eledPhiAtVtx[5];
 extern Float_t				eleSigmaIEtaIEta[5];
 extern Float_t				eleSigmaIEtaIPhi[5];
 extern Float_t				eleSigmaIPhiIPhi[5];
 extern Float_t				eleEmax[5];
 extern Float_t				eleE1x5[5];
 extern Float_t				eleE3x3[5];
 extern Float_t				eleE5x5[5];
 extern Float_t				eleE2x5Max[5];
 extern Float_t				eleRegrE[5];
 extern Float_t				eleRegrEerr[5];
 extern Float_t				elePhoRegrE[5];
 extern Float_t				elePhoRegrEerr[5];
 extern Float_t				eleSeedTime[5];
 extern Int_t				eleRecoFlag[5];
 extern Int_t				elePos[5];
 extern Int_t				eleGenIndex[5];
 extern Int_t				eleGenGMomPID[5];
 extern Int_t				eleGenMomPID[5];
 extern Float_t				eleGenMomPt[5];
 extern Float_t				eleIsoTrkDR03[5];
 extern Float_t				eleIsoEcalDR03[5];
 extern Float_t				eleIsoHcalDR03[5];
 extern Float_t				eleIsoHcalDR0312[5];
 extern Float_t				eleIsoTrkDR04[5];
 extern Float_t				eleIsoEcalDR04[5];
 extern Float_t				eleIsoHcalDR04[5];
 extern Float_t				eleIsoHcalDR0412[5];
 extern Float_t				eleModIsoTrk[5];
 extern Float_t				eleModIsoEcal[5];
 extern Float_t				eleModIsoHcal[5];
 extern Int_t				eleMissHits[5];
 extern Float_t				eleConvDist[5];
 extern Float_t				eleConvDcot[5];
 extern Int_t				eleConvVtxFit[5];
 extern Float_t				eleIP3D[5];
 extern Float_t				eleIP3DErr[5];
 extern Float_t				eleIDMVANonTrig[5];
 extern Float_t				eleIDMVATrig[5];
 extern Float_t				eleIDMVATrigIDIso[5];
 extern Float_t				elePFChIso03[5];
 extern Float_t				elePFPhoIso03[5];
 extern Float_t				elePFNeuIso03[5];
 extern Float_t				elePFChIso04[5];
 extern Float_t				elePFPhoIso04[5];
 extern Float_t				elePFNeuIso04[5];
 extern Float_t				eleESEffSigmaRR[5][3];
 extern Int_t				phoTrg[16][8];
 extern Int_t				phoTrgFilter[16][50];
 extern Bool_t				phoIsPhoton[16];
 extern Float_t				phoSCPos[16][3];
 extern Float_t				phoCaloPos[16][3];
 extern Float_t				phoE[16];
 extern Float_t				phoEt[16];
 extern Float_t				phoEta[16];
 extern Float_t				phoVtx[16][3];
 extern Float_t				phoPhi[16];
 extern Float_t				phoR9[16];
 extern Float_t				phoTrkIsoHollowDR03[16];
 extern Float_t				phoEcalIsoDR03[16];
 extern Float_t				phoHcalIsoDR03[16];
 extern Float_t				phoHcalIsoDR0312[16];
 extern Float_t				phoTrkIsoHollowDR04[16];
 extern Float_t				phoCiCdRtoTrk[16];
 extern Float_t				phoEcalIsoDR04[16];
 extern Float_t				phoHcalIsoDR04[16];
 extern Float_t				phoHcalIsoDR0412[16];
 extern Float_t				phoHoverE[16];
 extern Float_t				phoHoverE12[16];
 extern Int_t				phoEleVeto[16];
 extern Float_t				phoSigmaIEtaIEta[16];
 extern Float_t				phoSigmaIEtaIPhi[16];
 extern Float_t				phoSigmaIPhiIPhi[16];
 extern Float_t				phoCiCPF4phopfIso03[16];
 extern Float_t				phoCiCPF4phopfIso04[16];
 extern Float_t				phoEmax[16];
 extern Float_t				phoE3x3[16];
 extern Float_t				phoE3x1[16];
 extern Float_t				phoE1x3[16];
 extern Float_t				phoE5x5[16];
 extern Float_t				phoE1x5[16];
 extern Float_t				phoE2x2[16];
 extern Float_t				phoE2x5Max[16];
 extern Float_t				phoPFChIso[16];
 extern Float_t				phoPFPhoIso[16];
 extern Float_t				phoPFNeuIso[16];
 extern Float_t				phoSCRChIso[16];
 extern Float_t				phoSCRPhoIso[16];
 extern Float_t				phoSCRNeuIso[16];
 extern Float_t				phoRegrE[16];
 extern Float_t				phoRegrEerr[16];
 extern Float_t				phoSeedTime[16];
 extern Int_t				phoSeedDetId1[16];
 extern Int_t				phoSeedDetId2[16];
 extern Float_t				phoLICTD[16];
 extern Int_t				phoRecoFlag[16];
 extern Int_t				phoPos[16];
 extern Int_t				phoGenIndex[16];
 extern Int_t				phoGenGMomPID[16];
 extern Int_t				phoGenMomPID[16];
 extern Float_t				phoGenMomPt[16];
 extern Float_t				phoSCE[16];
 extern Float_t				phoSCRawE[16];
 extern Float_t				phoESEn[16];
 extern Float_t				phoSCEt[16];
 extern Float_t				phoSCEta[16];
 extern Float_t				phoSCPhi[16];
 extern Float_t				phoSCEtaWidth[16];
 extern Float_t				phoSCPhiWidth[16];
 extern Float_t				phoSCBrem[16];
 extern Int_t				phoOverlap[16];
 extern Int_t				phohasPixelSeed[16];
 extern Int_t				pho_hasConvPf[16];
 extern Int_t				pho_hasSLConvPf[16];
 extern Float_t				pho_pfconvVtxZ[16];
 extern Float_t				pho_pfconvVtxZErr[16];
 extern Int_t				pho_nSLConv[16];
 extern Float_t				pho_pfSLConvPos[16][20][3];
 extern Float_t				pho_pfSLConvVtxZ[16][20];
 extern Int_t				phoIsConv[16];
 extern Int_t				phoNConv[16];
 extern Float_t				phoConvInvMass[16];
 extern Float_t				phoConvCotTheta[16];
 extern Float_t				phoConvEoverP[16];
 extern Float_t				phoConvZofPVfromTrks[16];
 extern Float_t				phoConvMinDist[16];
 extern Float_t				phoConvdPhiAtVtx[16];
 extern Float_t				phoConvdPhiAtCalo[16];
 extern Float_t				phoConvdEtaAtCalo[16];
 extern Float_t				phoConvTrkd0[16][2];
 extern Float_t				phoConvTrkPin[16][2];
 extern Float_t				phoConvTrkPout[16][2];
 extern Float_t				phoConvTrkdz[16][2];
 extern Float_t				phoConvTrkdzErr[16][2];
 extern Float_t				phoConvChi2[16];
 extern Float_t				phoConvChi2Prob[16];
 extern Int_t				phoConvNTrks[16];
 extern Float_t				phoConvCharge[16][2];
 extern Float_t				phoConvValidVtx[16];
 extern Float_t				phoConvLikeLihood[16];
 extern Float_t				phoConvP4[16][4];
 extern Float_t				phoConvVtx[16][3];
 extern Float_t				phoConvVtxErr[16][3];
 extern Float_t				phoConvPairMomentum[16][3];
 extern Float_t				phoConvRefittedMomentum[16][3];
 extern Int_t				SingleLegConv[16];
 extern Float_t				phoPFConvVtx[16][3];
 extern Float_t				phoPFConvMom[16][3];
 extern Float_t				phoESEffSigmaRR[16][3];
 extern Int_t				muTrg[8][10];
 extern Float_t				muEta[8];
 extern Float_t				muPhi[8];
 extern Int_t				muCharge[8];
 extern Float_t				muPt[8];
 extern Float_t				muPz[8];
 extern Float_t				muVtx[8][3];
 extern Float_t				muVtxGlb[8][3];
 extern Int_t				muGenIndex[8];
 extern Float_t				mucktPt[8];
 extern Float_t				mucktPtErr[8];
 extern Float_t				mucktEta[8];
 extern Float_t				mucktPhi[8];
 extern Float_t				mucktdxy[8];
 extern Float_t				mucktdz[8];
 extern Float_t				muIsoTrk[8];
 extern Float_t				muIsoCalo[8];
 extern Float_t				muIsoEcal[8];
 extern Float_t				muIsoHcal[8];
 extern Float_t				muChi2NDF[8];
 extern Float_t				muInnerChi2NDF[8];
 extern Float_t				muPFIsoR04_CH[8];
 extern Float_t				muPFIsoR04_NH[8];
 extern Float_t				muPFIsoR04_Pho[8];
 extern Float_t				muPFIsoR04_PU[8];
 extern Float_t				muPFIsoR04_CPart[8];
 extern Float_t				muPFIsoR04_NHHT[8];
 extern Float_t				muPFIsoR04_PhoHT[8];
 extern Float_t				muPFIsoR03_CH[8];
 extern Float_t				muPFIsoR03_NH[8];
 extern Float_t				muPFIsoR03_Pho[8];
 extern Float_t				muPFIsoR03_PU[8];
 extern Float_t				muPFIsoR03_CPart[8];
 extern Float_t				muPFIsoR03_NHHT[8];
 extern Float_t				muPFIsoR03_PhoHT[8];
 extern Int_t				muType[8];
 extern Float_t				muD0[8];
 extern Float_t				muDz[8];
 extern Float_t				muD0GV[8];
 extern Float_t				muDzGV[8];
 extern Float_t				muInnerD0[8];
 extern Float_t				muInnerDz[8];
 extern Float_t				muInnerD0GV[8];
 extern Float_t				muInnerDzGV[8];
 extern Float_t				muInnerPt[8];
 extern Float_t				muInnerPtErr[8];
 extern Int_t				muNumberOfValidTrkLayers[8];
 extern Int_t				muNumberOfValidTrkHits[8];
 extern Int_t				muNumberOfValidPixelLayers[8];
 extern Int_t				muNumberOfValidPixelHits[8];
 extern Int_t				muNumberOfValidMuonHits[8];
 extern Int_t				muStations[8];
 extern Int_t				muChambers[8];
 extern Float_t				muIP3D[8];
 extern Float_t				muIP3DErr[8];
 extern Float_t				PFPhoEt[54];
 extern Float_t				PFPhoEta[54];
 extern Float_t				PFPhoPhi[54];
 extern Int_t				PFPhoType[54];
 extern Float_t				PFPhoIso[54];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[19][14];
 extern Float_t				jetEn[19];
 extern Float_t				jetPt[19];
 extern Float_t				jetEta[19];
 extern Float_t				jetPhi[19];
 extern Float_t				jetCharge[19];
 extern Float_t				jetEt[19];
 extern Float_t				jetRawPt[19];
 extern Float_t				jetRawEn[19];
 extern Float_t				jetArea[19];
 extern Float_t				jetCHF[19];
 extern Float_t				jetNHF[19];
 extern Float_t				jetCEF[19];
 extern Float_t				jetNEF[19];
 extern Int_t				jetNCH[19];
 extern Float_t				jetHFHAE[19];
 extern Float_t				jetHFEME[19];
 extern Int_t				jetNConstituents[19];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[19];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[19];
 extern Float_t				jetJetProbabilityBJetTags[19];
 extern Float_t				jetJetBProbabilityBJetTags[19];
 extern Float_t				jetTrackCountingHighPurBJetTags[19];
 extern Float_t				jetBetaStar[19][100];
 extern Bool_t				jetPFLooseId[19];
 extern Float_t				jetDRMean[19];
 extern Float_t				jetDR2Mean[19];
 extern Float_t				jetDZ[19];
 extern Float_t				jetFrac01[19];
 extern Float_t				jetFrac02[19];
 extern Float_t				jetFrac03[19];
 extern Float_t				jetFrac04[19];
 extern Float_t				jetFrac05[19];
 extern Float_t				jetFrac06[19];
 extern Float_t				jetFrac07[19];
 extern Float_t				jetBeta[19];
 extern Float_t				jetBetaStarCMG[19];
 extern Float_t				jetBetaStarClassic[19];
 extern Float_t				jetBetaExt[19][100];
 extern Float_t				jetNNeutrals[19];
 extern Float_t				jetNCharged[19];
 extern Float_t				jetMVAs[19][4];
 extern Int_t				jetWPLevels[19][4];
 extern Float_t				jetMt[19];
 extern Float_t				jetJECUnc[19];
 extern Float_t				jetLeadTrackPt[19];
 extern Float_t				jetVtxPt[19];
 extern Float_t				jetVtxMass[19];
 extern Float_t				jetVtx3dL[19];
 extern Float_t				jetVtx3deL[19];
 extern Float_t				jetSoftLeptPt[19];
 extern Float_t				jetSoftLeptPtRel[19];
 extern Float_t				jetSoftLeptdR[19];
 extern Float_t				jetSoftLeptIdlooseMu[19];
 extern Float_t				jetSoftLeptIdEle95[19];
 extern Float_t				jetDPhiMETJet[19];
 extern Float_t				jetPuJetIdL[19];
 extern Float_t				jetPuJetIdM[19];
 extern Float_t				jetPuJetIdT[19];
 extern Int_t				jetPartonID[19];
 extern Int_t				jetGenJetIndex[19];
 extern Float_t				jetGenJetEn[19];
 extern Float_t				jetGenJetPt[19];
 extern Float_t				jetGenJetEta[19];
 extern Float_t				jetGenJetPhi[19];
 extern Int_t				jetGenPartonID[19];
 extern Float_t				jetGenEn[19];
 extern Float_t				jetGenPt[19];
 extern Float_t				jetGenEta[19];
 extern Float_t				jetGenPhi[19];
 extern Float_t				convVtx[178][3];
 extern Float_t				convVtxErr[178][3];
 extern Float_t				convPairMomentum[178][3];
 extern Float_t				convRefittedMomentum[178][3];
 extern Int_t				convNTracks[178];
 extern Float_t				convPairInvMass[178];
 extern Float_t				convPairCotThetaSep[178];
 extern Float_t				convEoverP[178];
 extern Float_t				convDistOfMinApproach[178];
 extern Float_t				convDPhiTrksAtVtx[178];
 extern Float_t				convDPhiTrksAtEcal[178];
 extern Float_t				convDEtaTrksAtEcal[178];
 extern Float_t				convDxy[178];
 extern Float_t				convDz[178];
 extern Float_t				convLxy[178];
 extern Float_t				convLz[178];
 extern Float_t				convZofPrimVtxFromTrks[178];
 extern Int_t				convNHitsBeforeVtx[178][2];
 extern Int_t				convNSharedHits[178];
 extern Int_t				convValidVtx[178];
 extern Float_t				convMVALikelihood[178];
 extern Float_t				convChi2[178];
 extern Float_t				convChi2Probability[178];
 extern Float_t				convTk1Dz[178];
 extern Float_t				convTk2Dz[178];
 extern Float_t				convTk1DzErr[178];
 extern Float_t				convTk2DzErr[178];
 extern Int_t				convCh1Ch2[178];
 extern Float_t				convTk1D0[178];
 extern Float_t				convTk1Pout[178];
 extern Float_t				convTk1Pin[178];
 extern Float_t				convTk2D0[178];
 extern Float_t				convTk2Pout[178];
 extern Float_t				convTk2Pin[178];
};
#endif
