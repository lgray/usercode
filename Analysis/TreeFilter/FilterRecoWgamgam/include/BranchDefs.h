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
#define EXISTS_genMET
#define EXISTS_genMETPhi
#define EXISTS_nPU
#define EXISTS_puBX
#define EXISTS_puTrue
#define EXISTS_MET
#define EXISTS_METPhi
#define EXISTS_METsumEt
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
#define EXISTS_eleE2x5Right
#define EXISTS_eleE2x5Left
#define EXISTS_eleE2x5Top
#define EXISTS_eleE2x5Bottom
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
#define EXISTS_phoEtop
#define EXISTS_phoEbottom
#define EXISTS_phoEleft
#define EXISTS_phoEright
#define EXISTS_phoE3x3
#define EXISTS_phoE3x1
#define EXISTS_phoE1x3
#define EXISTS_phoE5x5
#define EXISTS_phoE1x5
#define EXISTS_phoE2x2
#define EXISTS_phoE2x5Max
#define EXISTS_phoE2x5Right
#define EXISTS_phoE2x5Left
#define EXISTS_phoE2x5Top
#define EXISTS_phoE2x5Bottom
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
#define EXISTS_muID
#define EXISTS_muD0
#define EXISTS_muDz
#define EXISTS_muD0GV
#define EXISTS_muDzGV
#define EXISTS_muInnerD0
#define EXISTS_muInnerDz
#define EXISTS_muInnerD0GV
#define EXISTS_muInnerDzGV
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
 extern Float_t				vtx[61][3];
 extern Int_t				IsVtxGood;
 extern Float_t				vtxbs[61][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[11];
 extern Float_t				mcPt[11];
 extern Float_t				mcEta[11];
 extern Float_t				mcPhi[11];
 extern Float_t				mcE[11];
 extern Int_t				mcGMomPID[11];
 extern Int_t				mcMomPID[11];
 extern Float_t				mcMomPt[11];
 extern Float_t				mcMomMass[11];
 extern Float_t				mcMomEta[11];
 extern Float_t				mcMomPhi[11];
 extern Int_t				mcIndex[11];
 extern Int_t				mcDecayType[11];
 extern Float_t				genMET;
 extern Float_t				genMETPhi;
 extern Int_t				nPU[4];
 extern Int_t				puBX[4];
 extern Float_t				puTrue[4];
 extern Float_t				MET;
 extern Float_t				METPhi;
 extern Float_t				METsumEt;
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
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[6][16];
 extern Int_t				eleClass[6];
 extern Int_t				eleIsEcalDriven[6];
 extern Int_t				eleCharge[6];
 extern Float_t				eleEn[6];
 extern Float_t				eleEcalEn[6];
 extern Float_t				eleSCRawEn[6];
 extern Float_t				eleSCEn[6];
 extern Float_t				eleESEn[6];
 extern Float_t				elePt[6];
 extern Float_t				eleEta[6];
 extern Float_t				elePhi[6];
 extern Float_t				eleSCEta[6];
 extern Float_t				eleSCPhi[6];
 extern Float_t				eleSCEtaWidth[6];
 extern Float_t				eleSCPhiWidth[6];
 extern Float_t				eleVtx[6][3];
 extern Float_t				eleD0[6];
 extern Float_t				eleDz[6];
 extern Float_t				eleD0GV[6];
 extern Float_t				eleDzGV[6];
 extern Float_t				eleHoverE[6];
 extern Float_t				eleHoverE12[6];
 extern Float_t				eleEoverP[6];
 extern Float_t				elePin[6];
 extern Float_t				elePout[6];
 extern Float_t				eleTrkMomErr[6];
 extern Float_t				eleBrem[6];
 extern Float_t				eledEtaAtVtx[6];
 extern Float_t				eledPhiAtVtx[6];
 extern Float_t				eleSigmaIEtaIEta[6];
 extern Float_t				eleSigmaIEtaIPhi[6];
 extern Float_t				eleSigmaIPhiIPhi[6];
 extern Float_t				eleEmax[6];
 extern Float_t				eleE1x5[6];
 extern Float_t				eleE3x3[6];
 extern Float_t				eleE5x5[6];
 extern Float_t				eleE2x5Right[6];
 extern Float_t				eleE2x5Left[6];
 extern Float_t				eleE2x5Top[6];
 extern Float_t				eleE2x5Bottom[6];
 extern Float_t				eleRegrE[6];
 extern Float_t				eleRegrEerr[6];
 extern Float_t				elePhoRegrE[6];
 extern Float_t				elePhoRegrEerr[6];
 extern Float_t				eleSeedTime[6];
 extern Int_t				eleRecoFlag[6];
 extern Int_t				elePos[6];
 extern Int_t				eleGenIndex[6];
 extern Int_t				eleGenGMomPID[6];
 extern Int_t				eleGenMomPID[6];
 extern Float_t				eleGenMomPt[6];
 extern Float_t				eleIsoTrkDR03[6];
 extern Float_t				eleIsoEcalDR03[6];
 extern Float_t				eleIsoHcalDR03[6];
 extern Float_t				eleIsoHcalDR0312[6];
 extern Float_t				eleIsoTrkDR04[6];
 extern Float_t				eleIsoEcalDR04[6];
 extern Float_t				eleIsoHcalDR04[6];
 extern Float_t				eleIsoHcalDR0412[6];
 extern Int_t				eleMissHits[6];
 extern Float_t				eleConvDist[6];
 extern Float_t				eleConvDcot[6];
 extern Int_t				eleConvVtxFit[6];
 extern Float_t				eleIP3D[6];
 extern Float_t				eleIP3DErr[6];
 extern Float_t				eleIDMVANonTrig[6];
 extern Float_t				eleIDMVATrig[6];
 extern Float_t				eleIDMVATrigIDIso[6];
 extern Float_t				elePFChIso03[6];
 extern Float_t				elePFPhoIso03[6];
 extern Float_t				elePFNeuIso03[6];
 extern Float_t				elePFChIso04[6];
 extern Float_t				elePFPhoIso04[6];
 extern Float_t				elePFNeuIso04[6];
 extern Float_t				eleESEffSigmaRR[6][3];
 extern Int_t				phoTrg[13][8];
 extern Int_t				phoTrgFilter[13][50];
 extern Bool_t				phoIsPhoton[13];
 extern Float_t				phoSCPos[13][3];
 extern Float_t				phoCaloPos[13][3];
 extern Float_t				phoE[13];
 extern Float_t				phoEt[13];
 extern Float_t				phoEta[13];
 extern Float_t				phoVtx[13][3];
 extern Float_t				phoPhi[13];
 extern Float_t				phoR9[13];
 extern Float_t				phoTrkIsoHollowDR03[13];
 extern Float_t				phoEcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR0312[13];
 extern Float_t				phoTrkIsoHollowDR04[13];
 extern Float_t				phoCiCdRtoTrk[13];
 extern Float_t				phoEcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR0412[13];
 extern Float_t				phoHoverE[13];
 extern Float_t				phoHoverE12[13];
 extern Int_t				phoEleVeto[13];
 extern Float_t				phoSigmaIEtaIEta[13];
 extern Float_t				phoSigmaIEtaIPhi[13];
 extern Float_t				phoSigmaIPhiIPhi[13];
 extern Float_t				phoCiCPF4phopfIso03[13];
 extern Float_t				phoCiCPF4phopfIso04[13];
 extern Float_t				phoEmax[13];
 extern Float_t				phoEtop[13];
 extern Float_t				phoEbottom[13];
 extern Float_t				phoEleft[13];
 extern Float_t				phoEright[13];
 extern Float_t				phoE3x3[13];
 extern Float_t				phoE3x1[13];
 extern Float_t				phoE1x3[13];
 extern Float_t				phoE5x5[13];
 extern Float_t				phoE1x5[13];
 extern Float_t				phoE2x2[13];
 extern Float_t				phoE2x5Max[13];
 extern Float_t				phoE2x5Right[13];
 extern Float_t				phoE2x5Left[13];
 extern Float_t				phoE2x5Top[13];
 extern Float_t				phoE2x5Bottom[13];
 extern Float_t				phoPFChIso[13];
 extern Float_t				phoPFPhoIso[13];
 extern Float_t				phoPFNeuIso[13];
 extern Float_t				phoSCRChIso[13];
 extern Float_t				phoSCRPhoIso[13];
 extern Float_t				phoSCRNeuIso[13];
 extern Float_t				phoRegrE[13];
 extern Float_t				phoRegrEerr[13];
 extern Float_t				phoSeedTime[13];
 extern Int_t				phoSeedDetId1[13];
 extern Int_t				phoSeedDetId2[13];
 extern Int_t				phoRecoFlag[13];
 extern Int_t				phoPos[13];
 extern Int_t				phoGenIndex[13];
 extern Int_t				phoGenGMomPID[13];
 extern Int_t				phoGenMomPID[13];
 extern Float_t				phoGenMomPt[13];
 extern Float_t				phoSCE[13];
 extern Float_t				phoSCRawE[13];
 extern Float_t				phoESEn[13];
 extern Float_t				phoSCEt[13];
 extern Float_t				phoSCEta[13];
 extern Float_t				phoSCPhi[13];
 extern Float_t				phoSCEtaWidth[13];
 extern Float_t				phoSCPhiWidth[13];
 extern Float_t				phoSCBrem[13];
 extern Int_t				phoOverlap[13];
 extern Int_t				phohasPixelSeed[13];
 extern Int_t				pho_hasConvPf[13];
 extern Int_t				pho_hasSLConvPf[13];
 extern Float_t				pho_pfconvVtxZ[13];
 extern Float_t				pho_pfconvVtxZErr[13];
 extern Int_t				pho_nSLConv[13];
 extern Float_t				pho_pfSLConvPos[13][20][3];
 extern Float_t				pho_pfSLConvVtxZ[13][20];
 extern Int_t				phoIsConv[13];
 extern Int_t				phoNConv[13];
 extern Float_t				phoConvInvMass[13];
 extern Float_t				phoConvCotTheta[13];
 extern Float_t				phoConvEoverP[13];
 extern Float_t				phoConvZofPVfromTrks[13];
 extern Float_t				phoConvMinDist[13];
 extern Float_t				phoConvdPhiAtVtx[13];
 extern Float_t				phoConvdPhiAtCalo[13];
 extern Float_t				phoConvdEtaAtCalo[13];
 extern Float_t				phoConvTrkd0[13][2];
 extern Float_t				phoConvTrkPin[13][2];
 extern Float_t				phoConvTrkPout[13][2];
 extern Float_t				phoConvTrkdz[13][2];
 extern Float_t				phoConvTrkdzErr[13][2];
 extern Float_t				phoConvChi2[13];
 extern Float_t				phoConvChi2Prob[13];
 extern Int_t				phoConvNTrks[13];
 extern Float_t				phoConvCharge[13][2];
 extern Float_t				phoConvValidVtx[13];
 extern Float_t				phoConvLikeLihood[13];
 extern Float_t				phoConvP4[13][4];
 extern Float_t				phoConvVtx[13][3];
 extern Float_t				phoConvVtxErr[13][3];
 extern Float_t				phoConvPairMomentum[13][3];
 extern Float_t				phoConvRefittedMomentum[13][3];
 extern Int_t				SingleLegConv[13];
 extern Float_t				phoPFConvVtx[13][3];
 extern Float_t				phoPFConvMom[13][3];
 extern Float_t				phoESEffSigmaRR[13][3];
 extern Int_t				muTrg[12][10];
 extern Float_t				muEta[12];
 extern Float_t				muPhi[12];
 extern Int_t				muCharge[12];
 extern Float_t				muPt[12];
 extern Float_t				muPz[12];
 extern Float_t				muVtx[12][3];
 extern Float_t				muVtxGlb[12][3];
 extern Int_t				muGenIndex[12];
 extern Float_t				mucktPt[12];
 extern Float_t				mucktPtErr[12];
 extern Float_t				mucktdxy[12];
 extern Float_t				mucktdz[12];
 extern Float_t				muIsoTrk[12];
 extern Float_t				muIsoCalo[12];
 extern Float_t				muIsoEcal[12];
 extern Float_t				muIsoHcal[12];
 extern Float_t				muChi2NDF[12];
 extern Float_t				muInnerChi2NDF[12];
 extern Float_t				muPFIsoR04_CH[12];
 extern Float_t				muPFIsoR04_NH[12];
 extern Float_t				muPFIsoR04_Pho[12];
 extern Float_t				muPFIsoR04_PU[12];
 extern Float_t				muPFIsoR04_CPart[12];
 extern Float_t				muPFIsoR04_NHHT[12];
 extern Float_t				muPFIsoR04_PhoHT[12];
 extern Float_t				muPFIsoR03_CH[12];
 extern Float_t				muPFIsoR03_NH[12];
 extern Float_t				muPFIsoR03_Pho[12];
 extern Float_t				muPFIsoR03_PU[12];
 extern Float_t				muPFIsoR03_CPart[12];
 extern Float_t				muPFIsoR03_NHHT[12];
 extern Float_t				muPFIsoR03_PhoHT[12];
 extern Int_t				muType[12];
 extern Bool_t				muID[12][6];
 extern Float_t				muD0[12];
 extern Float_t				muDz[12];
 extern Float_t				muD0GV[12];
 extern Float_t				muDzGV[12];
 extern Float_t				muInnerD0[12];
 extern Float_t				muInnerDz[12];
 extern Float_t				muInnerD0GV[12];
 extern Float_t				muInnerDzGV[12];
 extern Int_t				muNumberOfValidTrkLayers[12];
 extern Int_t				muNumberOfValidTrkHits[12];
 extern Int_t				muNumberOfValidPixelLayers[12];
 extern Int_t				muNumberOfValidPixelHits[12];
 extern Int_t				muNumberOfValidMuonHits[12];
 extern Int_t				muStations[12];
 extern Int_t				muChambers[12];
 extern Float_t				muIP3D[12];
 extern Float_t				muIP3DErr[12];
 extern Float_t				PFPhoEt[52];
 extern Float_t				PFPhoEta[52];
 extern Float_t				PFPhoPhi[52];
 extern Int_t				PFPhoType[52];
 extern Float_t				PFPhoIso[52];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[21][14];
 extern Float_t				jetEn[21];
 extern Float_t				jetPt[21];
 extern Float_t				jetEta[21];
 extern Float_t				jetPhi[21];
 extern Float_t				jetCharge[21];
 extern Float_t				jetEt[21];
 extern Float_t				jetRawPt[21];
 extern Float_t				jetRawEn[21];
 extern Float_t				jetArea[21];
 extern Float_t				jetCHF[21];
 extern Float_t				jetNHF[21];
 extern Float_t				jetCEF[21];
 extern Float_t				jetNEF[21];
 extern Int_t				jetNCH[21];
 extern Float_t				jetHFHAE[21];
 extern Float_t				jetHFEME[21];
 extern Int_t				jetNConstituents[21];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[21];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[21];
 extern Float_t				jetJetProbabilityBJetTags[21];
 extern Float_t				jetJetBProbabilityBJetTags[21];
 extern Float_t				jetTrackCountingHighPurBJetTags[21];
 extern Float_t				jetBetaStar[21][100];
 extern Bool_t				jetPFLooseId[21];
 extern Float_t				jetDRMean[21];
 extern Float_t				jetDR2Mean[21];
 extern Float_t				jetDZ[21];
 extern Float_t				jetFrac01[21];
 extern Float_t				jetFrac02[21];
 extern Float_t				jetFrac03[21];
 extern Float_t				jetFrac04[21];
 extern Float_t				jetFrac05[21];
 extern Float_t				jetFrac06[21];
 extern Float_t				jetFrac07[21];
 extern Float_t				jetBeta[21];
 extern Float_t				jetBetaStarCMG[21];
 extern Float_t				jetBetaStarClassic[21];
 extern Float_t				jetBetaExt[21][100];
 extern Float_t				jetNNeutrals[21];
 extern Float_t				jetNCharged[21];
 extern Float_t				jetMVAs[21][4];
 extern Int_t				jetWPLevels[21][4];
 extern Int_t				jetPartonID[21];
 extern Int_t				jetGenJetIndex[21];
 extern Float_t				jetGenJetEn[21];
 extern Float_t				jetGenJetPt[21];
 extern Float_t				jetGenJetEta[21];
 extern Float_t				jetGenJetPhi[21];
 extern Int_t				jetGenPartonID[21];
 extern Float_t				jetGenEn[21];
 extern Float_t				jetGenPt[21];
 extern Float_t				jetGenEta[21];
 extern Float_t				jetGenPhi[21];
 extern Float_t				convVtx[127][3];
 extern Float_t				convVtxErr[127][3];
 extern Float_t				convPairMomentum[127][3];
 extern Float_t				convRefittedMomentum[127][3];
 extern Int_t				convNTracks[127];
 extern Float_t				convPairInvMass[127];
 extern Float_t				convPairCotThetaSep[127];
 extern Float_t				convEoverP[127];
 extern Float_t				convDistOfMinApproach[127];
 extern Float_t				convDPhiTrksAtVtx[127];
 extern Float_t				convDPhiTrksAtEcal[127];
 extern Float_t				convDEtaTrksAtEcal[127];
 extern Float_t				convDxy[127];
 extern Float_t				convDz[127];
 extern Float_t				convLxy[127];
 extern Float_t				convLz[127];
 extern Float_t				convZofPrimVtxFromTrks[127];
 extern Int_t				convNHitsBeforeVtx[127][2];
 extern Int_t				convNSharedHits[127];
 extern Int_t				convValidVtx[127];
 extern Float_t				convMVALikelihood[127];
 extern Float_t				convChi2[127];
 extern Float_t				convChi2Probability[127];
 extern Float_t				convTk1Dz[127];
 extern Float_t				convTk2Dz[127];
 extern Float_t				convTk1DzErr[127];
 extern Float_t				convTk2DzErr[127];
 extern Int_t				convCh1Ch2[127];
 extern Float_t				convTk1D0[127];
 extern Float_t				convTk1Pout[127];
 extern Float_t				convTk1Pin[127];
 extern Float_t				convTk2D0[127];
 extern Float_t				convTk2Pout[127];
 extern Float_t				convTk2Pin[127];
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
 extern Float_t				vtx[61][3];
 extern Int_t				IsVtxGood;
 extern Float_t				vtxbs[61][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[11];
 extern Float_t				mcPt[11];
 extern Float_t				mcEta[11];
 extern Float_t				mcPhi[11];
 extern Float_t				mcE[11];
 extern Int_t				mcGMomPID[11];
 extern Int_t				mcMomPID[11];
 extern Float_t				mcMomPt[11];
 extern Float_t				mcMomMass[11];
 extern Float_t				mcMomEta[11];
 extern Float_t				mcMomPhi[11];
 extern Int_t				mcIndex[11];
 extern Int_t				mcDecayType[11];
 extern Float_t				genMET;
 extern Float_t				genMETPhi;
 extern Int_t				nPU[4];
 extern Int_t				puBX[4];
 extern Float_t				puTrue[4];
 extern Float_t				MET;
 extern Float_t				METPhi;
 extern Float_t				METsumEt;
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
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[6][16];
 extern Int_t				eleClass[6];
 extern Int_t				eleIsEcalDriven[6];
 extern Int_t				eleCharge[6];
 extern Float_t				eleEn[6];
 extern Float_t				eleEcalEn[6];
 extern Float_t				eleSCRawEn[6];
 extern Float_t				eleSCEn[6];
 extern Float_t				eleESEn[6];
 extern Float_t				elePt[6];
 extern Float_t				eleEta[6];
 extern Float_t				elePhi[6];
 extern Float_t				eleSCEta[6];
 extern Float_t				eleSCPhi[6];
 extern Float_t				eleSCEtaWidth[6];
 extern Float_t				eleSCPhiWidth[6];
 extern Float_t				eleVtx[6][3];
 extern Float_t				eleD0[6];
 extern Float_t				eleDz[6];
 extern Float_t				eleD0GV[6];
 extern Float_t				eleDzGV[6];
 extern Float_t				eleHoverE[6];
 extern Float_t				eleHoverE12[6];
 extern Float_t				eleEoverP[6];
 extern Float_t				elePin[6];
 extern Float_t				elePout[6];
 extern Float_t				eleTrkMomErr[6];
 extern Float_t				eleBrem[6];
 extern Float_t				eledEtaAtVtx[6];
 extern Float_t				eledPhiAtVtx[6];
 extern Float_t				eleSigmaIEtaIEta[6];
 extern Float_t				eleSigmaIEtaIPhi[6];
 extern Float_t				eleSigmaIPhiIPhi[6];
 extern Float_t				eleEmax[6];
 extern Float_t				eleE1x5[6];
 extern Float_t				eleE3x3[6];
 extern Float_t				eleE5x5[6];
 extern Float_t				eleE2x5Right[6];
 extern Float_t				eleE2x5Left[6];
 extern Float_t				eleE2x5Top[6];
 extern Float_t				eleE2x5Bottom[6];
 extern Float_t				eleRegrE[6];
 extern Float_t				eleRegrEerr[6];
 extern Float_t				elePhoRegrE[6];
 extern Float_t				elePhoRegrEerr[6];
 extern Float_t				eleSeedTime[6];
 extern Int_t				eleRecoFlag[6];
 extern Int_t				elePos[6];
 extern Int_t				eleGenIndex[6];
 extern Int_t				eleGenGMomPID[6];
 extern Int_t				eleGenMomPID[6];
 extern Float_t				eleGenMomPt[6];
 extern Float_t				eleIsoTrkDR03[6];
 extern Float_t				eleIsoEcalDR03[6];
 extern Float_t				eleIsoHcalDR03[6];
 extern Float_t				eleIsoHcalDR0312[6];
 extern Float_t				eleIsoTrkDR04[6];
 extern Float_t				eleIsoEcalDR04[6];
 extern Float_t				eleIsoHcalDR04[6];
 extern Float_t				eleIsoHcalDR0412[6];
 extern Int_t				eleMissHits[6];
 extern Float_t				eleConvDist[6];
 extern Float_t				eleConvDcot[6];
 extern Int_t				eleConvVtxFit[6];
 extern Float_t				eleIP3D[6];
 extern Float_t				eleIP3DErr[6];
 extern Float_t				eleIDMVANonTrig[6];
 extern Float_t				eleIDMVATrig[6];
 extern Float_t				eleIDMVATrigIDIso[6];
 extern Float_t				elePFChIso03[6];
 extern Float_t				elePFPhoIso03[6];
 extern Float_t				elePFNeuIso03[6];
 extern Float_t				elePFChIso04[6];
 extern Float_t				elePFPhoIso04[6];
 extern Float_t				elePFNeuIso04[6];
 extern Float_t				eleESEffSigmaRR[6][3];
 extern Int_t				phoTrg[13][8];
 extern Int_t				phoTrgFilter[13][50];
 extern Bool_t				phoIsPhoton[13];
 extern Float_t				phoSCPos[13][3];
 extern Float_t				phoCaloPos[13][3];
 extern Float_t				phoE[13];
 extern Float_t				phoEt[13];
 extern Float_t				phoEta[13];
 extern Float_t				phoVtx[13][3];
 extern Float_t				phoPhi[13];
 extern Float_t				phoR9[13];
 extern Float_t				phoTrkIsoHollowDR03[13];
 extern Float_t				phoEcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR0312[13];
 extern Float_t				phoTrkIsoHollowDR04[13];
 extern Float_t				phoCiCdRtoTrk[13];
 extern Float_t				phoEcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR0412[13];
 extern Float_t				phoHoverE[13];
 extern Float_t				phoHoverE12[13];
 extern Int_t				phoEleVeto[13];
 extern Float_t				phoSigmaIEtaIEta[13];
 extern Float_t				phoSigmaIEtaIPhi[13];
 extern Float_t				phoSigmaIPhiIPhi[13];
 extern Float_t				phoCiCPF4phopfIso03[13];
 extern Float_t				phoCiCPF4phopfIso04[13];
 extern Float_t				phoEmax[13];
 extern Float_t				phoEtop[13];
 extern Float_t				phoEbottom[13];
 extern Float_t				phoEleft[13];
 extern Float_t				phoEright[13];
 extern Float_t				phoE3x3[13];
 extern Float_t				phoE3x1[13];
 extern Float_t				phoE1x3[13];
 extern Float_t				phoE5x5[13];
 extern Float_t				phoE1x5[13];
 extern Float_t				phoE2x2[13];
 extern Float_t				phoE2x5Max[13];
 extern Float_t				phoE2x5Right[13];
 extern Float_t				phoE2x5Left[13];
 extern Float_t				phoE2x5Top[13];
 extern Float_t				phoE2x5Bottom[13];
 extern Float_t				phoPFChIso[13];
 extern Float_t				phoPFPhoIso[13];
 extern Float_t				phoPFNeuIso[13];
 extern Float_t				phoSCRChIso[13];
 extern Float_t				phoSCRPhoIso[13];
 extern Float_t				phoSCRNeuIso[13];
 extern Float_t				phoRegrE[13];
 extern Float_t				phoRegrEerr[13];
 extern Float_t				phoSeedTime[13];
 extern Int_t				phoSeedDetId1[13];
 extern Int_t				phoSeedDetId2[13];
 extern Int_t				phoRecoFlag[13];
 extern Int_t				phoPos[13];
 extern Int_t				phoGenIndex[13];
 extern Int_t				phoGenGMomPID[13];
 extern Int_t				phoGenMomPID[13];
 extern Float_t				phoGenMomPt[13];
 extern Float_t				phoSCE[13];
 extern Float_t				phoSCRawE[13];
 extern Float_t				phoESEn[13];
 extern Float_t				phoSCEt[13];
 extern Float_t				phoSCEta[13];
 extern Float_t				phoSCPhi[13];
 extern Float_t				phoSCEtaWidth[13];
 extern Float_t				phoSCPhiWidth[13];
 extern Float_t				phoSCBrem[13];
 extern Int_t				phoOverlap[13];
 extern Int_t				phohasPixelSeed[13];
 extern Int_t				pho_hasConvPf[13];
 extern Int_t				pho_hasSLConvPf[13];
 extern Float_t				pho_pfconvVtxZ[13];
 extern Float_t				pho_pfconvVtxZErr[13];
 extern Int_t				pho_nSLConv[13];
 extern Float_t				pho_pfSLConvPos[13][20][3];
 extern Float_t				pho_pfSLConvVtxZ[13][20];
 extern Int_t				phoIsConv[13];
 extern Int_t				phoNConv[13];
 extern Float_t				phoConvInvMass[13];
 extern Float_t				phoConvCotTheta[13];
 extern Float_t				phoConvEoverP[13];
 extern Float_t				phoConvZofPVfromTrks[13];
 extern Float_t				phoConvMinDist[13];
 extern Float_t				phoConvdPhiAtVtx[13];
 extern Float_t				phoConvdPhiAtCalo[13];
 extern Float_t				phoConvdEtaAtCalo[13];
 extern Float_t				phoConvTrkd0[13][2];
 extern Float_t				phoConvTrkPin[13][2];
 extern Float_t				phoConvTrkPout[13][2];
 extern Float_t				phoConvTrkdz[13][2];
 extern Float_t				phoConvTrkdzErr[13][2];
 extern Float_t				phoConvChi2[13];
 extern Float_t				phoConvChi2Prob[13];
 extern Int_t				phoConvNTrks[13];
 extern Float_t				phoConvCharge[13][2];
 extern Float_t				phoConvValidVtx[13];
 extern Float_t				phoConvLikeLihood[13];
 extern Float_t				phoConvP4[13][4];
 extern Float_t				phoConvVtx[13][3];
 extern Float_t				phoConvVtxErr[13][3];
 extern Float_t				phoConvPairMomentum[13][3];
 extern Float_t				phoConvRefittedMomentum[13][3];
 extern Int_t				SingleLegConv[13];
 extern Float_t				phoPFConvVtx[13][3];
 extern Float_t				phoPFConvMom[13][3];
 extern Float_t				phoESEffSigmaRR[13][3];
 extern Int_t				muTrg[12][10];
 extern Float_t				muEta[12];
 extern Float_t				muPhi[12];
 extern Int_t				muCharge[12];
 extern Float_t				muPt[12];
 extern Float_t				muPz[12];
 extern Float_t				muVtx[12][3];
 extern Float_t				muVtxGlb[12][3];
 extern Int_t				muGenIndex[12];
 extern Float_t				mucktPt[12];
 extern Float_t				mucktPtErr[12];
 extern Float_t				mucktdxy[12];
 extern Float_t				mucktdz[12];
 extern Float_t				muIsoTrk[12];
 extern Float_t				muIsoCalo[12];
 extern Float_t				muIsoEcal[12];
 extern Float_t				muIsoHcal[12];
 extern Float_t				muChi2NDF[12];
 extern Float_t				muInnerChi2NDF[12];
 extern Float_t				muPFIsoR04_CH[12];
 extern Float_t				muPFIsoR04_NH[12];
 extern Float_t				muPFIsoR04_Pho[12];
 extern Float_t				muPFIsoR04_PU[12];
 extern Float_t				muPFIsoR04_CPart[12];
 extern Float_t				muPFIsoR04_NHHT[12];
 extern Float_t				muPFIsoR04_PhoHT[12];
 extern Float_t				muPFIsoR03_CH[12];
 extern Float_t				muPFIsoR03_NH[12];
 extern Float_t				muPFIsoR03_Pho[12];
 extern Float_t				muPFIsoR03_PU[12];
 extern Float_t				muPFIsoR03_CPart[12];
 extern Float_t				muPFIsoR03_NHHT[12];
 extern Float_t				muPFIsoR03_PhoHT[12];
 extern Int_t				muType[12];
 extern Bool_t				muID[12][6];
 extern Float_t				muD0[12];
 extern Float_t				muDz[12];
 extern Float_t				muD0GV[12];
 extern Float_t				muDzGV[12];
 extern Float_t				muInnerD0[12];
 extern Float_t				muInnerDz[12];
 extern Float_t				muInnerD0GV[12];
 extern Float_t				muInnerDzGV[12];
 extern Int_t				muNumberOfValidTrkLayers[12];
 extern Int_t				muNumberOfValidTrkHits[12];
 extern Int_t				muNumberOfValidPixelLayers[12];
 extern Int_t				muNumberOfValidPixelHits[12];
 extern Int_t				muNumberOfValidMuonHits[12];
 extern Int_t				muStations[12];
 extern Int_t				muChambers[12];
 extern Float_t				muIP3D[12];
 extern Float_t				muIP3DErr[12];
 extern Float_t				PFPhoEt[52];
 extern Float_t				PFPhoEta[52];
 extern Float_t				PFPhoPhi[52];
 extern Int_t				PFPhoType[52];
 extern Float_t				PFPhoIso[52];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[21][14];
 extern Float_t				jetEn[21];
 extern Float_t				jetPt[21];
 extern Float_t				jetEta[21];
 extern Float_t				jetPhi[21];
 extern Float_t				jetCharge[21];
 extern Float_t				jetEt[21];
 extern Float_t				jetRawPt[21];
 extern Float_t				jetRawEn[21];
 extern Float_t				jetArea[21];
 extern Float_t				jetCHF[21];
 extern Float_t				jetNHF[21];
 extern Float_t				jetCEF[21];
 extern Float_t				jetNEF[21];
 extern Int_t				jetNCH[21];
 extern Float_t				jetHFHAE[21];
 extern Float_t				jetHFEME[21];
 extern Int_t				jetNConstituents[21];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[21];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[21];
 extern Float_t				jetJetProbabilityBJetTags[21];
 extern Float_t				jetJetBProbabilityBJetTags[21];
 extern Float_t				jetTrackCountingHighPurBJetTags[21];
 extern Float_t				jetBetaStar[21][100];
 extern Bool_t				jetPFLooseId[21];
 extern Float_t				jetDRMean[21];
 extern Float_t				jetDR2Mean[21];
 extern Float_t				jetDZ[21];
 extern Float_t				jetFrac01[21];
 extern Float_t				jetFrac02[21];
 extern Float_t				jetFrac03[21];
 extern Float_t				jetFrac04[21];
 extern Float_t				jetFrac05[21];
 extern Float_t				jetFrac06[21];
 extern Float_t				jetFrac07[21];
 extern Float_t				jetBeta[21];
 extern Float_t				jetBetaStarCMG[21];
 extern Float_t				jetBetaStarClassic[21];
 extern Float_t				jetBetaExt[21][100];
 extern Float_t				jetNNeutrals[21];
 extern Float_t				jetNCharged[21];
 extern Float_t				jetMVAs[21][4];
 extern Int_t				jetWPLevels[21][4];
 extern Int_t				jetPartonID[21];
 extern Int_t				jetGenJetIndex[21];
 extern Float_t				jetGenJetEn[21];
 extern Float_t				jetGenJetPt[21];
 extern Float_t				jetGenJetEta[21];
 extern Float_t				jetGenJetPhi[21];
 extern Int_t				jetGenPartonID[21];
 extern Float_t				jetGenEn[21];
 extern Float_t				jetGenPt[21];
 extern Float_t				jetGenEta[21];
 extern Float_t				jetGenPhi[21];
 extern Float_t				convVtx[127][3];
 extern Float_t				convVtxErr[127][3];
 extern Float_t				convPairMomentum[127][3];
 extern Float_t				convRefittedMomentum[127][3];
 extern Int_t				convNTracks[127];
 extern Float_t				convPairInvMass[127];
 extern Float_t				convPairCotThetaSep[127];
 extern Float_t				convEoverP[127];
 extern Float_t				convDistOfMinApproach[127];
 extern Float_t				convDPhiTrksAtVtx[127];
 extern Float_t				convDPhiTrksAtEcal[127];
 extern Float_t				convDEtaTrksAtEcal[127];
 extern Float_t				convDxy[127];
 extern Float_t				convDz[127];
 extern Float_t				convLxy[127];
 extern Float_t				convLz[127];
 extern Float_t				convZofPrimVtxFromTrks[127];
 extern Int_t				convNHitsBeforeVtx[127][2];
 extern Int_t				convNSharedHits[127];
 extern Int_t				convValidVtx[127];
 extern Float_t				convMVALikelihood[127];
 extern Float_t				convChi2[127];
 extern Float_t				convChi2Probability[127];
 extern Float_t				convTk1Dz[127];
 extern Float_t				convTk2Dz[127];
 extern Float_t				convTk1DzErr[127];
 extern Float_t				convTk2DzErr[127];
 extern Int_t				convCh1Ch2[127];
 extern Float_t				convTk1D0[127];
 extern Float_t				convTk1Pout[127];
 extern Float_t				convTk1Pin[127];
 extern Float_t				convTk2D0[127];
 extern Float_t				convTk2Pout[127];
 extern Float_t				convTk2Pin[127];
};
#endif
