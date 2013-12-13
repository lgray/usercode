#include <algorithm>
#include <iostream>
#include "TTree.h"
#include "TChain.h"
#include "include/BranchInit.h"
#include "include/BranchDefs.h"

namespace IN {
 Int_t				nVtxBS;
 Float_t				pfMET;
 Float_t				pfMETPhi;
 Float_t				pfMETsumEt;
 Float_t				pfMETmEtSig;
 Float_t				pfMETSig;
 Float_t				recoPfMET;
 Float_t				recoPfMETPhi;
 Float_t				recoPfMETsumEt;
 Float_t				recoPfMETmEtSig;
 Float_t				recoPfMETSig;
 Int_t				el_n;
 Int_t				mu_n;
 Int_t				ph_n;
 Int_t				ph_sl_n;
 Int_t				jet_n;
 Int_t				vtx_n;
 std::vector<float>				*el_pt;
 std::vector<float>				*el_eta;
 std::vector<float>				*el_sceta;
 std::vector<float>				*el_phi;
 std::vector<float>				*el_e;
 std::vector<float>				*el_mva;
 std::vector<float>				*el_d0pv;
 std::vector<float>				*el_z0pv;
 std::vector<float>				*el_sigmaIEIE;
 std::vector<float>				*el_pfiso30;
 std::vector<bool>				*el_hasMatchedConv;
 std::vector<bool>				*el_passTight;
 std::vector<bool>				*el_passMedium;
 std::vector<bool>				*el_passLoose;
 std::vector<bool>				*el_passVeryLoose;
 std::vector<bool>				*el_passTightTrig;
 std::vector<bool>				*el_truthMatch_ph;
 std::vector<bool>				*el_truthMatch;
 std::vector<float>				*el_truthMinDR;
 std::vector<float>				*mu_pt;
 std::vector<float>				*mu_eta;
 std::vector<float>				*mu_phi;
 std::vector<float>				*mu_e;
 std::vector<float>				*mu_pfIso_ch;
 std::vector<float>				*mu_pfIso_nh;
 std::vector<float>				*mu_pfIso_pho;
 std::vector<float>				*mu_pfIso_pu;
 std::vector<float>				*mu_corrIso;
 std::vector<bool>				*mu_truthMatch;
 std::vector<float>				*mu_truthMinDR;
 std::vector<float>				*ph_pt;
 std::vector<float>				*ph_eta;
 std::vector<float>				*ph_phi;
 std::vector<float>				*ph_e;
 std::vector<float>				*ph_HoverE;
 std::vector<float>				*ph_sigmaIEIE;
 std::vector<float>				*ph_chIsoCorr;
 std::vector<float>				*ph_neuIsoCorr;
 std::vector<float>				*ph_phoIsoCorr;
 std::vector<int>				*ph_eleVeto;
 std::vector<bool>				*ph_isConv;
 std::vector<int>				*ph_conv_nTrk;
 std::vector<float>				*ph_conv_vtx_x;
 std::vector<float>				*ph_conv_vtx_y;
 std::vector<float>				*ph_conv_vtx_z;
 std::vector<float>				*ph_conv_ptin1;
 std::vector<float>				*ph_conv_ptin2;
 std::vector<float>				*ph_conv_ptout1;
 std::vector<float>				*ph_conv_ptout2;
 std::vector<bool>				*ph_passTight;
 std::vector<bool>				*ph_passMedium;
 std::vector<bool>				*ph_passLoose;
 std::vector<bool>				*ph_truthMatch_ph;
 std::vector<bool>				*ph_truthMatch_el;
 std::vector<bool>				*ph_truthMatch_mu;
 std::vector<bool>				*ph_truthMatch_q;
 std::vector<float>				*ph_sl_pt;
 std::vector<float>				*ph_sl_eta;
 std::vector<float>				*ph_sl_phi;
 std::vector<float>				*ph_sl_e;
 std::vector<float>				*ph_sl_d0;
 std::vector<float>				*ph_sl_z0;
 std::vector<int>				*ph_sl_convfit;
 std::vector<int>				*ph_sl_misshits;
 std::vector<float>				*jet_pt;
 std::vector<float>				*jet_eta;
 std::vector<float>				*jet_phi;
 std::vector<float>				*jet_e;
 Float_t				avgPU;
 Bool_t				isBlinded;
 Int_t				mu_pt25_n;
 Int_t				el_pt25_n;
 Float_t				leadPhot_pt;
 Float_t				sublPhot_pt;
 Float_t				leadPhot_lepDR;
 Float_t				sublPhot_lepDR;
 Float_t				ph_phDR;
 Float_t				phPhot_lepDR;
 Float_t				leadPhot_lepDPhi;
 Float_t				sublPhot_lepDPhi;
 Float_t				ph_phDPhi;
 Float_t				phPhot_lepDPhi;
 Float_t				mt_lep_met;
 Float_t				mt_lepph1_met;
 Float_t				mt_lepph2_met;
 Float_t				mt_lepphph_met;
 Float_t				m_leplep;
 Float_t				m_lepph1;
 Float_t				m_lepph2;
 Float_t				m_leplepph;
 Float_t				m_lepphph;
 Float_t				m_phph;
 Float_t				m_leplepZ;
 Float_t				m_3lep;
 Float_t				m_4lep;
 Float_t				pt_leplep;
 Float_t				pt_lepph1;
 Float_t				pt_lepph2;
 Float_t				pt_lepphph;
 Float_t				pt_leplepph;
 Float_t				pt_secondLepton;
 Float_t				pt_thirdLepton;
};
namespace OUT {
 Int_t				nVtxBS;
 Float_t				pfMET;
 Float_t				pfMETPhi;
 Float_t				pfMETsumEt;
 Float_t				pfMETmEtSig;
 Float_t				pfMETSig;
 Float_t				recoPfMET;
 Float_t				recoPfMETPhi;
 Float_t				recoPfMETsumEt;
 Float_t				recoPfMETmEtSig;
 Float_t				recoPfMETSig;
 Int_t				el_n;
 Int_t				mu_n;
 Int_t				ph_n;
 Int_t				ph_sl_n;
 Int_t				jet_n;
 Int_t				vtx_n;
 std::vector<float>				*el_pt;
 std::vector<float>				*el_eta;
 std::vector<float>				*el_sceta;
 std::vector<float>				*el_phi;
 std::vector<float>				*el_e;
 std::vector<float>				*el_mva;
 std::vector<float>				*el_d0pv;
 std::vector<float>				*el_z0pv;
 std::vector<float>				*el_sigmaIEIE;
 std::vector<float>				*el_pfiso30;
 std::vector<bool>				*el_hasMatchedConv;
 std::vector<bool>				*el_passTight;
 std::vector<bool>				*el_passMedium;
 std::vector<bool>				*el_passLoose;
 std::vector<bool>				*el_passVeryLoose;
 std::vector<bool>				*el_passTightTrig;
 std::vector<bool>				*el_truthMatch_ph;
 std::vector<bool>				*el_truthMatch;
 std::vector<float>				*el_truthMinDR;
 std::vector<float>				*mu_pt;
 std::vector<float>				*mu_eta;
 std::vector<float>				*mu_phi;
 std::vector<float>				*mu_e;
 std::vector<float>				*mu_pfIso_ch;
 std::vector<float>				*mu_pfIso_nh;
 std::vector<float>				*mu_pfIso_pho;
 std::vector<float>				*mu_pfIso_pu;
 std::vector<float>				*mu_corrIso;
 std::vector<bool>				*mu_truthMatch;
 std::vector<float>				*mu_truthMinDR;
 std::vector<float>				*ph_pt;
 std::vector<float>				*ph_eta;
 std::vector<float>				*ph_phi;
 std::vector<float>				*ph_e;
 std::vector<float>				*ph_HoverE;
 std::vector<float>				*ph_sigmaIEIE;
 std::vector<float>				*ph_chIsoCorr;
 std::vector<float>				*ph_neuIsoCorr;
 std::vector<float>				*ph_phoIsoCorr;
 std::vector<int>				*ph_eleVeto;
 std::vector<bool>				*ph_isConv;
 std::vector<int>				*ph_conv_nTrk;
 std::vector<float>				*ph_conv_vtx_x;
 std::vector<float>				*ph_conv_vtx_y;
 std::vector<float>				*ph_conv_vtx_z;
 std::vector<float>				*ph_conv_ptin1;
 std::vector<float>				*ph_conv_ptin2;
 std::vector<float>				*ph_conv_ptout1;
 std::vector<float>				*ph_conv_ptout2;
 std::vector<bool>				*ph_passTight;
 std::vector<bool>				*ph_passMedium;
 std::vector<bool>				*ph_passLoose;
 std::vector<bool>				*ph_truthMatch_ph;
 std::vector<bool>				*ph_truthMatch_el;
 std::vector<bool>				*ph_truthMatch_mu;
 std::vector<bool>				*ph_truthMatch_q;
 std::vector<float>				*ph_sl_pt;
 std::vector<float>				*ph_sl_eta;
 std::vector<float>				*ph_sl_phi;
 std::vector<float>				*ph_sl_e;
 std::vector<float>				*ph_sl_d0;
 std::vector<float>				*ph_sl_z0;
 std::vector<int>				*ph_sl_convfit;
 std::vector<int>				*ph_sl_misshits;
 std::vector<float>				*jet_pt;
 std::vector<float>				*jet_eta;
 std::vector<float>				*jet_phi;
 std::vector<float>				*jet_e;
 Float_t				avgPU;
 Bool_t				isBlinded;
 Int_t				mu_pt25_n;
 Int_t				el_pt25_n;
 Float_t				leadPhot_pt;
 Float_t				sublPhot_pt;
 Float_t				leadPhot_lepDR;
 Float_t				sublPhot_lepDR;
 Float_t				ph_phDR;
 Float_t				phPhot_lepDR;
 Float_t				leadPhot_lepDPhi;
 Float_t				sublPhot_lepDPhi;
 Float_t				ph_phDPhi;
 Float_t				phPhot_lepDPhi;
 Float_t				mt_lep_met;
 Float_t				mt_lepph1_met;
 Float_t				mt_lepph2_met;
 Float_t				mt_lepphph_met;
 Float_t				m_leplep;
 Float_t				m_lepph1;
 Float_t				m_lepph2;
 Float_t				m_leplepph;
 Float_t				m_lepphph;
 Float_t				m_phph;
 Float_t				m_leplepZ;
 Float_t				m_3lep;
 Float_t				m_4lep;
 Float_t				pt_leplep;
 Float_t				pt_lepph1;
 Float_t				pt_lepph2;
 Float_t				pt_lepphph;
 Float_t				pt_leplepph;
 Float_t				pt_secondLepton;
 Float_t				pt_thirdLepton;
};
void InitINTree( TChain * tree) {

  tree->SetBranchAddress("nVtxBS", &IN::nVtxBS);
  tree->SetBranchAddress("pfMET", &IN::pfMET);
  tree->SetBranchAddress("pfMETPhi", &IN::pfMETPhi);
  tree->SetBranchAddress("pfMETsumEt", &IN::pfMETsumEt);
  tree->SetBranchAddress("pfMETmEtSig", &IN::pfMETmEtSig);
  tree->SetBranchAddress("pfMETSig", &IN::pfMETSig);
  tree->SetBranchAddress("recoPfMET", &IN::recoPfMET);
  tree->SetBranchAddress("recoPfMETPhi", &IN::recoPfMETPhi);
  tree->SetBranchAddress("recoPfMETsumEt", &IN::recoPfMETsumEt);
  tree->SetBranchAddress("recoPfMETmEtSig", &IN::recoPfMETmEtSig);
  tree->SetBranchAddress("recoPfMETSig", &IN::recoPfMETSig);
  tree->SetBranchAddress("el_n", &IN::el_n);
  tree->SetBranchAddress("mu_n", &IN::mu_n);
  tree->SetBranchAddress("ph_n", &IN::ph_n);
  tree->SetBranchAddress("ph_sl_n", &IN::ph_sl_n);
  tree->SetBranchAddress("jet_n", &IN::jet_n);
  tree->SetBranchAddress("vtx_n", &IN::vtx_n);
  tree->SetBranchAddress("el_pt", &IN::el_pt);
  tree->SetBranchAddress("el_eta", &IN::el_eta);
  tree->SetBranchAddress("el_sceta", &IN::el_sceta);
  tree->SetBranchAddress("el_phi", &IN::el_phi);
  tree->SetBranchAddress("el_e", &IN::el_e);
  tree->SetBranchAddress("el_mva", &IN::el_mva);
  tree->SetBranchAddress("el_d0pv", &IN::el_d0pv);
  tree->SetBranchAddress("el_z0pv", &IN::el_z0pv);
  tree->SetBranchAddress("el_sigmaIEIE", &IN::el_sigmaIEIE);
  tree->SetBranchAddress("el_pfiso30", &IN::el_pfiso30);
  tree->SetBranchAddress("el_hasMatchedConv", &IN::el_hasMatchedConv);
  tree->SetBranchAddress("el_passTight", &IN::el_passTight);
  tree->SetBranchAddress("el_passMedium", &IN::el_passMedium);
  tree->SetBranchAddress("el_passLoose", &IN::el_passLoose);
  tree->SetBranchAddress("el_passVeryLoose", &IN::el_passVeryLoose);
  tree->SetBranchAddress("el_passTightTrig", &IN::el_passTightTrig);
  tree->SetBranchAddress("el_truthMatch_ph", &IN::el_truthMatch_ph);
  tree->SetBranchAddress("el_truthMatch", &IN::el_truthMatch);
  tree->SetBranchAddress("el_truthMinDR", &IN::el_truthMinDR);
  tree->SetBranchAddress("mu_pt", &IN::mu_pt);
  tree->SetBranchAddress("mu_eta", &IN::mu_eta);
  tree->SetBranchAddress("mu_phi", &IN::mu_phi);
  tree->SetBranchAddress("mu_e", &IN::mu_e);
  tree->SetBranchAddress("mu_pfIso_ch", &IN::mu_pfIso_ch);
  tree->SetBranchAddress("mu_pfIso_nh", &IN::mu_pfIso_nh);
  tree->SetBranchAddress("mu_pfIso_pho", &IN::mu_pfIso_pho);
  tree->SetBranchAddress("mu_pfIso_pu", &IN::mu_pfIso_pu);
  tree->SetBranchAddress("mu_corrIso", &IN::mu_corrIso);
  tree->SetBranchAddress("mu_truthMatch", &IN::mu_truthMatch);
  tree->SetBranchAddress("mu_truthMinDR", &IN::mu_truthMinDR);
  tree->SetBranchAddress("ph_pt", &IN::ph_pt);
  tree->SetBranchAddress("ph_eta", &IN::ph_eta);
  tree->SetBranchAddress("ph_phi", &IN::ph_phi);
  tree->SetBranchAddress("ph_e", &IN::ph_e);
  tree->SetBranchAddress("ph_HoverE", &IN::ph_HoverE);
  tree->SetBranchAddress("ph_sigmaIEIE", &IN::ph_sigmaIEIE);
  tree->SetBranchAddress("ph_chIsoCorr", &IN::ph_chIsoCorr);
  tree->SetBranchAddress("ph_neuIsoCorr", &IN::ph_neuIsoCorr);
  tree->SetBranchAddress("ph_phoIsoCorr", &IN::ph_phoIsoCorr);
  tree->SetBranchAddress("ph_eleVeto", &IN::ph_eleVeto);
  tree->SetBranchAddress("ph_isConv", &IN::ph_isConv);
  tree->SetBranchAddress("ph_conv_nTrk", &IN::ph_conv_nTrk);
  tree->SetBranchAddress("ph_conv_vtx_x", &IN::ph_conv_vtx_x);
  tree->SetBranchAddress("ph_conv_vtx_y", &IN::ph_conv_vtx_y);
  tree->SetBranchAddress("ph_conv_vtx_z", &IN::ph_conv_vtx_z);
  tree->SetBranchAddress("ph_conv_ptin1", &IN::ph_conv_ptin1);
  tree->SetBranchAddress("ph_conv_ptin2", &IN::ph_conv_ptin2);
  tree->SetBranchAddress("ph_conv_ptout1", &IN::ph_conv_ptout1);
  tree->SetBranchAddress("ph_conv_ptout2", &IN::ph_conv_ptout2);
  tree->SetBranchAddress("ph_passTight", &IN::ph_passTight);
  tree->SetBranchAddress("ph_passMedium", &IN::ph_passMedium);
  tree->SetBranchAddress("ph_passLoose", &IN::ph_passLoose);
  tree->SetBranchAddress("ph_truthMatch_ph", &IN::ph_truthMatch_ph);
  tree->SetBranchAddress("ph_truthMatch_el", &IN::ph_truthMatch_el);
  tree->SetBranchAddress("ph_truthMatch_mu", &IN::ph_truthMatch_mu);
  tree->SetBranchAddress("ph_truthMatch_q", &IN::ph_truthMatch_q);
  tree->SetBranchAddress("ph_sl_pt", &IN::ph_sl_pt);
  tree->SetBranchAddress("ph_sl_eta", &IN::ph_sl_eta);
  tree->SetBranchAddress("ph_sl_phi", &IN::ph_sl_phi);
  tree->SetBranchAddress("ph_sl_e", &IN::ph_sl_e);
  tree->SetBranchAddress("ph_sl_d0", &IN::ph_sl_d0);
  tree->SetBranchAddress("ph_sl_z0", &IN::ph_sl_z0);
  tree->SetBranchAddress("ph_sl_convfit", &IN::ph_sl_convfit);
  tree->SetBranchAddress("ph_sl_misshits", &IN::ph_sl_misshits);
  tree->SetBranchAddress("jet_pt", &IN::jet_pt);
  tree->SetBranchAddress("jet_eta", &IN::jet_eta);
  tree->SetBranchAddress("jet_phi", &IN::jet_phi);
  tree->SetBranchAddress("jet_e", &IN::jet_e);
  tree->SetBranchAddress("avgPU", &IN::avgPU);
  tree->SetBranchAddress("isBlinded", &IN::isBlinded);
  tree->SetBranchAddress("mu_pt25_n", &IN::mu_pt25_n);
  tree->SetBranchAddress("el_pt25_n", &IN::el_pt25_n);
  tree->SetBranchAddress("leadPhot_pt", &IN::leadPhot_pt);
  tree->SetBranchAddress("sublPhot_pt", &IN::sublPhot_pt);
  tree->SetBranchAddress("leadPhot_lepDR", &IN::leadPhot_lepDR);
  tree->SetBranchAddress("sublPhot_lepDR", &IN::sublPhot_lepDR);
  tree->SetBranchAddress("ph_phDR", &IN::ph_phDR);
  tree->SetBranchAddress("phPhot_lepDR", &IN::phPhot_lepDR);
  tree->SetBranchAddress("leadPhot_lepDPhi", &IN::leadPhot_lepDPhi);
  tree->SetBranchAddress("sublPhot_lepDPhi", &IN::sublPhot_lepDPhi);
  tree->SetBranchAddress("ph_phDPhi", &IN::ph_phDPhi);
  tree->SetBranchAddress("phPhot_lepDPhi", &IN::phPhot_lepDPhi);
  tree->SetBranchAddress("mt_lep_met", &IN::mt_lep_met);
  tree->SetBranchAddress("mt_lepph1_met", &IN::mt_lepph1_met);
  tree->SetBranchAddress("mt_lepph2_met", &IN::mt_lepph2_met);
  tree->SetBranchAddress("mt_lepphph_met", &IN::mt_lepphph_met);
  tree->SetBranchAddress("m_leplep", &IN::m_leplep);
  tree->SetBranchAddress("m_lepph1", &IN::m_lepph1);
  tree->SetBranchAddress("m_lepph2", &IN::m_lepph2);
  tree->SetBranchAddress("m_leplepph", &IN::m_leplepph);
  tree->SetBranchAddress("m_lepphph", &IN::m_lepphph);
  tree->SetBranchAddress("m_phph", &IN::m_phph);
  tree->SetBranchAddress("m_leplepZ", &IN::m_leplepZ);
  tree->SetBranchAddress("m_3lep", &IN::m_3lep);
  tree->SetBranchAddress("m_4lep", &IN::m_4lep);
  tree->SetBranchAddress("pt_leplep", &IN::pt_leplep);
  tree->SetBranchAddress("pt_lepph1", &IN::pt_lepph1);
  tree->SetBranchAddress("pt_lepph2", &IN::pt_lepph2);
  tree->SetBranchAddress("pt_lepphph", &IN::pt_lepphph);
  tree->SetBranchAddress("pt_leplepph", &IN::pt_leplepph);
  tree->SetBranchAddress("pt_secondLepton", &IN::pt_secondLepton);
  tree->SetBranchAddress("pt_thirdLepton", &IN::pt_thirdLepton);
};

void InitOUTTree( TTree * tree ) {
  tree->Branch("nVtxBS", &OUT::nVtxBS, "nVtxBS/I");
  tree->Branch("pfMET", &OUT::pfMET, "pfMET/F");
  tree->Branch("pfMETPhi", &OUT::pfMETPhi, "pfMETPhi/F");
  tree->Branch("pfMETsumEt", &OUT::pfMETsumEt, "pfMETsumEt/F");
  tree->Branch("pfMETmEtSig", &OUT::pfMETmEtSig, "pfMETmEtSig/F");
  tree->Branch("pfMETSig", &OUT::pfMETSig, "pfMETSig/F");
  tree->Branch("recoPfMET", &OUT::recoPfMET, "recoPfMET/F");
  tree->Branch("recoPfMETPhi", &OUT::recoPfMETPhi, "recoPfMETPhi/F");
  tree->Branch("recoPfMETsumEt", &OUT::recoPfMETsumEt, "recoPfMETsumEt/F");
  tree->Branch("recoPfMETmEtSig", &OUT::recoPfMETmEtSig, "recoPfMETmEtSig/F");
  tree->Branch("recoPfMETSig", &OUT::recoPfMETSig, "recoPfMETSig/F");
  tree->Branch("el_n", &OUT::el_n, "el_n/I");
  tree->Branch("mu_n", &OUT::mu_n, "mu_n/I");
  tree->Branch("ph_n", &OUT::ph_n, "ph_n/I");
  tree->Branch("ph_sl_n", &OUT::ph_sl_n, "ph_sl_n/I");
  tree->Branch("jet_n", &OUT::jet_n, "jet_n/I");
  tree->Branch("vtx_n", &OUT::vtx_n, "vtx_n/I");
  tree->Branch("el_pt", &OUT::el_pt);
  tree->Branch("el_eta", &OUT::el_eta);
  tree->Branch("el_sceta", &OUT::el_sceta);
  tree->Branch("el_phi", &OUT::el_phi);
  tree->Branch("el_e", &OUT::el_e);
  tree->Branch("el_mva", &OUT::el_mva);
  tree->Branch("el_d0pv", &OUT::el_d0pv);
  tree->Branch("el_z0pv", &OUT::el_z0pv);
  tree->Branch("el_sigmaIEIE", &OUT::el_sigmaIEIE);
  tree->Branch("el_pfiso30", &OUT::el_pfiso30);
  tree->Branch("el_hasMatchedConv", &OUT::el_hasMatchedConv);
  tree->Branch("el_passTight", &OUT::el_passTight);
  tree->Branch("el_passMedium", &OUT::el_passMedium);
  tree->Branch("el_passLoose", &OUT::el_passLoose);
  tree->Branch("el_passVeryLoose", &OUT::el_passVeryLoose);
  tree->Branch("el_passTightTrig", &OUT::el_passTightTrig);
  tree->Branch("el_truthMatch_ph", &OUT::el_truthMatch_ph);
  tree->Branch("el_truthMatch", &OUT::el_truthMatch);
  tree->Branch("el_truthMinDR", &OUT::el_truthMinDR);
  tree->Branch("mu_pt", &OUT::mu_pt);
  tree->Branch("mu_eta", &OUT::mu_eta);
  tree->Branch("mu_phi", &OUT::mu_phi);
  tree->Branch("mu_e", &OUT::mu_e);
  tree->Branch("mu_pfIso_ch", &OUT::mu_pfIso_ch);
  tree->Branch("mu_pfIso_nh", &OUT::mu_pfIso_nh);
  tree->Branch("mu_pfIso_pho", &OUT::mu_pfIso_pho);
  tree->Branch("mu_pfIso_pu", &OUT::mu_pfIso_pu);
  tree->Branch("mu_corrIso", &OUT::mu_corrIso);
  tree->Branch("mu_truthMatch", &OUT::mu_truthMatch);
  tree->Branch("mu_truthMinDR", &OUT::mu_truthMinDR);
  tree->Branch("ph_pt", &OUT::ph_pt);
  tree->Branch("ph_eta", &OUT::ph_eta);
  tree->Branch("ph_phi", &OUT::ph_phi);
  tree->Branch("ph_e", &OUT::ph_e);
  tree->Branch("ph_HoverE", &OUT::ph_HoverE);
  tree->Branch("ph_sigmaIEIE", &OUT::ph_sigmaIEIE);
  tree->Branch("ph_chIsoCorr", &OUT::ph_chIsoCorr);
  tree->Branch("ph_neuIsoCorr", &OUT::ph_neuIsoCorr);
  tree->Branch("ph_phoIsoCorr", &OUT::ph_phoIsoCorr);
  tree->Branch("ph_eleVeto", &OUT::ph_eleVeto);
  tree->Branch("ph_isConv", &OUT::ph_isConv);
  tree->Branch("ph_conv_nTrk", &OUT::ph_conv_nTrk);
  tree->Branch("ph_conv_vtx_x", &OUT::ph_conv_vtx_x);
  tree->Branch("ph_conv_vtx_y", &OUT::ph_conv_vtx_y);
  tree->Branch("ph_conv_vtx_z", &OUT::ph_conv_vtx_z);
  tree->Branch("ph_conv_ptin1", &OUT::ph_conv_ptin1);
  tree->Branch("ph_conv_ptin2", &OUT::ph_conv_ptin2);
  tree->Branch("ph_conv_ptout1", &OUT::ph_conv_ptout1);
  tree->Branch("ph_conv_ptout2", &OUT::ph_conv_ptout2);
  tree->Branch("ph_passTight", &OUT::ph_passTight);
  tree->Branch("ph_passMedium", &OUT::ph_passMedium);
  tree->Branch("ph_passLoose", &OUT::ph_passLoose);
  tree->Branch("ph_truthMatch_ph", &OUT::ph_truthMatch_ph);
  tree->Branch("ph_truthMatch_el", &OUT::ph_truthMatch_el);
  tree->Branch("ph_truthMatch_mu", &OUT::ph_truthMatch_mu);
  tree->Branch("ph_truthMatch_q", &OUT::ph_truthMatch_q);
  tree->Branch("ph_sl_pt", &OUT::ph_sl_pt);
  tree->Branch("ph_sl_eta", &OUT::ph_sl_eta);
  tree->Branch("ph_sl_phi", &OUT::ph_sl_phi);
  tree->Branch("ph_sl_e", &OUT::ph_sl_e);
  tree->Branch("ph_sl_d0", &OUT::ph_sl_d0);
  tree->Branch("ph_sl_z0", &OUT::ph_sl_z0);
  tree->Branch("ph_sl_convfit", &OUT::ph_sl_convfit);
  tree->Branch("ph_sl_misshits", &OUT::ph_sl_misshits);
  tree->Branch("jet_pt", &OUT::jet_pt);
  tree->Branch("jet_eta", &OUT::jet_eta);
  tree->Branch("jet_phi", &OUT::jet_phi);
  tree->Branch("jet_e", &OUT::jet_e);
  tree->Branch("avgPU", &OUT::avgPU, "avgPU/F");
  tree->Branch("isBlinded", &OUT::isBlinded, "isBlinded/O");
  tree->Branch("mu_pt25_n", &OUT::mu_pt25_n, "mu_pt25_n/I");
  tree->Branch("el_pt25_n", &OUT::el_pt25_n, "el_pt25_n/I");
  tree->Branch("leadPhot_pt", &OUT::leadPhot_pt, "leadPhot_pt/F");
  tree->Branch("sublPhot_pt", &OUT::sublPhot_pt, "sublPhot_pt/F");
  tree->Branch("leadPhot_lepDR", &OUT::leadPhot_lepDR, "leadPhot_lepDR/F");
  tree->Branch("sublPhot_lepDR", &OUT::sublPhot_lepDR, "sublPhot_lepDR/F");
  tree->Branch("ph_phDR", &OUT::ph_phDR, "ph_phDR/F");
  tree->Branch("phPhot_lepDR", &OUT::phPhot_lepDR, "phPhot_lepDR/F");
  tree->Branch("leadPhot_lepDPhi", &OUT::leadPhot_lepDPhi, "leadPhot_lepDPhi/F");
  tree->Branch("sublPhot_lepDPhi", &OUT::sublPhot_lepDPhi, "sublPhot_lepDPhi/F");
  tree->Branch("ph_phDPhi", &OUT::ph_phDPhi, "ph_phDPhi/F");
  tree->Branch("phPhot_lepDPhi", &OUT::phPhot_lepDPhi, "phPhot_lepDPhi/F");
  tree->Branch("mt_lep_met", &OUT::mt_lep_met, "mt_lep_met/F");
  tree->Branch("mt_lepph1_met", &OUT::mt_lepph1_met, "mt_lepph1_met/F");
  tree->Branch("mt_lepph2_met", &OUT::mt_lepph2_met, "mt_lepph2_met/F");
  tree->Branch("mt_lepphph_met", &OUT::mt_lepphph_met, "mt_lepphph_met/F");
  tree->Branch("m_leplep", &OUT::m_leplep, "m_leplep/F");
  tree->Branch("m_lepph1", &OUT::m_lepph1, "m_lepph1/F");
  tree->Branch("m_lepph2", &OUT::m_lepph2, "m_lepph2/F");
  tree->Branch("m_leplepph", &OUT::m_leplepph, "m_leplepph/F");
  tree->Branch("m_lepphph", &OUT::m_lepphph, "m_lepphph/F");
  tree->Branch("m_phph", &OUT::m_phph, "m_phph/F");
  tree->Branch("m_leplepZ", &OUT::m_leplepZ, "m_leplepZ/F");
  tree->Branch("m_3lep", &OUT::m_3lep, "m_3lep/F");
  tree->Branch("m_4lep", &OUT::m_4lep, "m_4lep/F");
  tree->Branch("pt_leplep", &OUT::pt_leplep, "pt_leplep/F");
  tree->Branch("pt_lepph1", &OUT::pt_lepph1, "pt_lepph1/F");
  tree->Branch("pt_lepph2", &OUT::pt_lepph2, "pt_lepph2/F");
  tree->Branch("pt_lepphph", &OUT::pt_lepphph, "pt_lepphph/F");
  tree->Branch("pt_leplepph", &OUT::pt_leplepph, "pt_leplepph/F");
  tree->Branch("pt_secondLepton", &OUT::pt_secondLepton, "pt_secondLepton/F");
  tree->Branch("pt_thirdLepton", &OUT::pt_thirdLepton, "pt_thirdLepton/F");
}
void CopyInputVarsToOutput( std::string prefix) {
    CopynVtxBSInToOut( prefix ); 
    CopypfMETInToOut( prefix ); 
    CopypfMETPhiInToOut( prefix ); 
    CopypfMETsumEtInToOut( prefix ); 
    CopypfMETmEtSigInToOut( prefix ); 
    CopypfMETSigInToOut( prefix ); 
    CopyrecoPfMETInToOut( prefix ); 
    CopyrecoPfMETPhiInToOut( prefix ); 
    CopyrecoPfMETsumEtInToOut( prefix ); 
    CopyrecoPfMETmEtSigInToOut( prefix ); 
    CopyrecoPfMETSigInToOut( prefix ); 
    Copyel_nInToOut( prefix ); 
    Copymu_nInToOut( prefix ); 
    Copyph_nInToOut( prefix ); 
    Copyph_sl_nInToOut( prefix ); 
    Copyjet_nInToOut( prefix ); 
    Copyvtx_nInToOut( prefix ); 
    Copyel_ptInToOut( prefix ); 
    Copyel_etaInToOut( prefix ); 
    Copyel_scetaInToOut( prefix ); 
    Copyel_phiInToOut( prefix ); 
    Copyel_eInToOut( prefix ); 
    Copyel_mvaInToOut( prefix ); 
    Copyel_d0pvInToOut( prefix ); 
    Copyel_z0pvInToOut( prefix ); 
    Copyel_sigmaIEIEInToOut( prefix ); 
    Copyel_pfiso30InToOut( prefix ); 
    Copyel_hasMatchedConvInToOut( prefix ); 
    Copyel_passTightInToOut( prefix ); 
    Copyel_passMediumInToOut( prefix ); 
    Copyel_passLooseInToOut( prefix ); 
    Copyel_passVeryLooseInToOut( prefix ); 
    Copyel_passTightTrigInToOut( prefix ); 
    Copyel_truthMatch_phInToOut( prefix ); 
    Copyel_truthMatchInToOut( prefix ); 
    Copyel_truthMinDRInToOut( prefix ); 
    Copymu_ptInToOut( prefix ); 
    Copymu_etaInToOut( prefix ); 
    Copymu_phiInToOut( prefix ); 
    Copymu_eInToOut( prefix ); 
    Copymu_pfIso_chInToOut( prefix ); 
    Copymu_pfIso_nhInToOut( prefix ); 
    Copymu_pfIso_phoInToOut( prefix ); 
    Copymu_pfIso_puInToOut( prefix ); 
    Copymu_corrIsoInToOut( prefix ); 
    Copymu_truthMatchInToOut( prefix ); 
    Copymu_truthMinDRInToOut( prefix ); 
    Copyph_ptInToOut( prefix ); 
    Copyph_etaInToOut( prefix ); 
    Copyph_phiInToOut( prefix ); 
    Copyph_eInToOut( prefix ); 
    Copyph_HoverEInToOut( prefix ); 
    Copyph_sigmaIEIEInToOut( prefix ); 
    Copyph_chIsoCorrInToOut( prefix ); 
    Copyph_neuIsoCorrInToOut( prefix ); 
    Copyph_phoIsoCorrInToOut( prefix ); 
    Copyph_eleVetoInToOut( prefix ); 
    Copyph_isConvInToOut( prefix ); 
    Copyph_conv_nTrkInToOut( prefix ); 
    Copyph_conv_vtx_xInToOut( prefix ); 
    Copyph_conv_vtx_yInToOut( prefix ); 
    Copyph_conv_vtx_zInToOut( prefix ); 
    Copyph_conv_ptin1InToOut( prefix ); 
    Copyph_conv_ptin2InToOut( prefix ); 
    Copyph_conv_ptout1InToOut( prefix ); 
    Copyph_conv_ptout2InToOut( prefix ); 
    Copyph_passTightInToOut( prefix ); 
    Copyph_passMediumInToOut( prefix ); 
    Copyph_passLooseInToOut( prefix ); 
    Copyph_truthMatch_phInToOut( prefix ); 
    Copyph_truthMatch_elInToOut( prefix ); 
    Copyph_truthMatch_muInToOut( prefix ); 
    Copyph_truthMatch_qInToOut( prefix ); 
    Copyph_sl_ptInToOut( prefix ); 
    Copyph_sl_etaInToOut( prefix ); 
    Copyph_sl_phiInToOut( prefix ); 
    Copyph_sl_eInToOut( prefix ); 
    Copyph_sl_d0InToOut( prefix ); 
    Copyph_sl_z0InToOut( prefix ); 
    Copyph_sl_convfitInToOut( prefix ); 
    Copyph_sl_misshitsInToOut( prefix ); 
    Copyjet_ptInToOut( prefix ); 
    Copyjet_etaInToOut( prefix ); 
    Copyjet_phiInToOut( prefix ); 
    Copyjet_eInToOut( prefix ); 
    CopyavgPUInToOut( prefix ); 
    CopyisBlindedInToOut( prefix ); 
    Copymu_pt25_nInToOut( prefix ); 
    Copyel_pt25_nInToOut( prefix ); 
    CopyleadPhot_ptInToOut( prefix ); 
    CopysublPhot_ptInToOut( prefix ); 
    CopyleadPhot_lepDRInToOut( prefix ); 
    CopysublPhot_lepDRInToOut( prefix ); 
    Copyph_phDRInToOut( prefix ); 
    CopyphPhot_lepDRInToOut( prefix ); 
    CopyleadPhot_lepDPhiInToOut( prefix ); 
    CopysublPhot_lepDPhiInToOut( prefix ); 
    Copyph_phDPhiInToOut( prefix ); 
    CopyphPhot_lepDPhiInToOut( prefix ); 
    Copymt_lep_metInToOut( prefix ); 
    Copymt_lepph1_metInToOut( prefix ); 
    Copymt_lepph2_metInToOut( prefix ); 
    Copymt_lepphph_metInToOut( prefix ); 
    Copym_leplepInToOut( prefix ); 
    Copym_lepph1InToOut( prefix ); 
    Copym_lepph2InToOut( prefix ); 
    Copym_leplepphInToOut( prefix ); 
    Copym_lepphphInToOut( prefix ); 
    Copym_phphInToOut( prefix ); 
    Copym_leplepZInToOut( prefix ); 
    Copym_3lepInToOut( prefix ); 
    Copym_4lepInToOut( prefix ); 
    Copypt_leplepInToOut( prefix ); 
    Copypt_lepph1InToOut( prefix ); 
    Copypt_lepph2InToOut( prefix ); 
    Copypt_lepphphInToOut( prefix ); 
    Copypt_leplepphInToOut( prefix ); 
    Copypt_secondLeptonInToOut( prefix ); 
    Copypt_thirdLeptonInToOut( prefix ); 
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

    CopynVtxBSInToOut( prefix );
    CopypfMETInToOut( prefix );
    CopypfMETPhiInToOut( prefix );
    CopypfMETsumEtInToOut( prefix );
    CopypfMETmEtSigInToOut( prefix );
    CopypfMETSigInToOut( prefix );
    CopyrecoPfMETInToOut( prefix );
    CopyrecoPfMETPhiInToOut( prefix );
    CopyrecoPfMETsumEtInToOut( prefix );
    CopyrecoPfMETmEtSigInToOut( prefix );
    CopyrecoPfMETSigInToOut( prefix );
    Copyel_nInToOut( prefix );
    Copymu_nInToOut( prefix );
    Copyph_nInToOut( prefix );
    Copyph_sl_nInToOut( prefix );
    Copyjet_nInToOut( prefix );
    Copyvtx_nInToOut( prefix );
    Copyel_ptInToOut( prefix );
    Copyel_etaInToOut( prefix );
    Copyel_scetaInToOut( prefix );
    Copyel_phiInToOut( prefix );
    Copyel_eInToOut( prefix );
    Copyel_mvaInToOut( prefix );
    Copyel_d0pvInToOut( prefix );
    Copyel_z0pvInToOut( prefix );
    Copyel_sigmaIEIEInToOut( prefix );
    Copyel_pfiso30InToOut( prefix );
    Copyel_hasMatchedConvInToOut( prefix );
    Copyel_passTightInToOut( prefix );
    Copyel_passMediumInToOut( prefix );
    Copyel_passLooseInToOut( prefix );
    Copyel_passVeryLooseInToOut( prefix );
    Copyel_passTightTrigInToOut( prefix );
    Copyel_truthMatch_phInToOut( prefix );
    Copyel_truthMatchInToOut( prefix );
    Copyel_truthMinDRInToOut( prefix );
    Copymu_ptInToOut( prefix );
    Copymu_etaInToOut( prefix );
    Copymu_phiInToOut( prefix );
    Copymu_eInToOut( prefix );
    Copymu_pfIso_chInToOut( prefix );
    Copymu_pfIso_nhInToOut( prefix );
    Copymu_pfIso_phoInToOut( prefix );
    Copymu_pfIso_puInToOut( prefix );
    Copymu_corrIsoInToOut( prefix );
    Copymu_truthMatchInToOut( prefix );
    Copymu_truthMinDRInToOut( prefix );
    Copyph_ptInToOut( prefix );
    Copyph_etaInToOut( prefix );
    Copyph_phiInToOut( prefix );
    Copyph_eInToOut( prefix );
    Copyph_HoverEInToOut( prefix );
    Copyph_sigmaIEIEInToOut( prefix );
    Copyph_chIsoCorrInToOut( prefix );
    Copyph_neuIsoCorrInToOut( prefix );
    Copyph_phoIsoCorrInToOut( prefix );
    Copyph_eleVetoInToOut( prefix );
    Copyph_isConvInToOut( prefix );
    Copyph_conv_nTrkInToOut( prefix );
    Copyph_conv_vtx_xInToOut( prefix );
    Copyph_conv_vtx_yInToOut( prefix );
    Copyph_conv_vtx_zInToOut( prefix );
    Copyph_conv_ptin1InToOut( prefix );
    Copyph_conv_ptin2InToOut( prefix );
    Copyph_conv_ptout1InToOut( prefix );
    Copyph_conv_ptout2InToOut( prefix );
    Copyph_passTightInToOut( prefix );
    Copyph_passMediumInToOut( prefix );
    Copyph_passLooseInToOut( prefix );
    Copyph_truthMatch_phInToOut( prefix );
    Copyph_truthMatch_elInToOut( prefix );
    Copyph_truthMatch_muInToOut( prefix );
    Copyph_truthMatch_qInToOut( prefix );
    Copyph_sl_ptInToOut( prefix );
    Copyph_sl_etaInToOut( prefix );
    Copyph_sl_phiInToOut( prefix );
    Copyph_sl_eInToOut( prefix );
    Copyph_sl_d0InToOut( prefix );
    Copyph_sl_z0InToOut( prefix );
    Copyph_sl_convfitInToOut( prefix );
    Copyph_sl_misshitsInToOut( prefix );
    Copyjet_ptInToOut( prefix );
    Copyjet_etaInToOut( prefix );
    Copyjet_phiInToOut( prefix );
    Copyjet_eInToOut( prefix );
    CopyavgPUInToOut( prefix );
    CopyisBlindedInToOut( prefix );
    Copymu_pt25_nInToOut( prefix );
    Copyel_pt25_nInToOut( prefix );
    CopyleadPhot_ptInToOut( prefix );
    CopysublPhot_ptInToOut( prefix );
    CopyleadPhot_lepDRInToOut( prefix );
    CopysublPhot_lepDRInToOut( prefix );
    Copyph_phDRInToOut( prefix );
    CopyphPhot_lepDRInToOut( prefix );
    CopyleadPhot_lepDPhiInToOut( prefix );
    CopysublPhot_lepDPhiInToOut( prefix );
    Copyph_phDPhiInToOut( prefix );
    CopyphPhot_lepDPhiInToOut( prefix );
    Copymt_lep_metInToOut( prefix );
    Copymt_lepph1_metInToOut( prefix );
    Copymt_lepph2_metInToOut( prefix );
    Copymt_lepphph_metInToOut( prefix );
    Copym_leplepInToOut( prefix );
    Copym_lepph1InToOut( prefix );
    Copym_lepph2InToOut( prefix );
    Copym_leplepphInToOut( prefix );
    Copym_lepphphInToOut( prefix );
    Copym_phphInToOut( prefix );
    Copym_leplepZInToOut( prefix );
    Copym_3lepInToOut( prefix );
    Copym_4lepInToOut( prefix );
    Copypt_leplepInToOut( prefix );
    Copypt_lepph1InToOut( prefix );
    Copypt_lepph2InToOut( prefix );
    Copypt_lepphphInToOut( prefix );
    Copypt_leplepphInToOut( prefix );
    Copypt_secondLeptonInToOut( prefix );
    Copypt_thirdLeptonInToOut( prefix );
}; 

void CopyPrefixIndexBranchesInToOut( const std::string & prefix, unsigned index ) { 

// Just call each copy function with the prefix 

    Copyel_ptInToOutIndex( index, prefix );
    Copyel_etaInToOutIndex( index, prefix );
    Copyel_scetaInToOutIndex( index, prefix );
    Copyel_phiInToOutIndex( index, prefix );
    Copyel_eInToOutIndex( index, prefix );
    Copyel_mvaInToOutIndex( index, prefix );
    Copyel_d0pvInToOutIndex( index, prefix );
    Copyel_z0pvInToOutIndex( index, prefix );
    Copyel_sigmaIEIEInToOutIndex( index, prefix );
    Copyel_pfiso30InToOutIndex( index, prefix );
    Copyel_hasMatchedConvInToOutIndex( index, prefix );
    Copyel_passTightInToOutIndex( index, prefix );
    Copyel_passMediumInToOutIndex( index, prefix );
    Copyel_passLooseInToOutIndex( index, prefix );
    Copyel_passVeryLooseInToOutIndex( index, prefix );
    Copyel_passTightTrigInToOutIndex( index, prefix );
    Copyel_truthMatch_phInToOutIndex( index, prefix );
    Copyel_truthMatchInToOutIndex( index, prefix );
    Copyel_truthMinDRInToOutIndex( index, prefix );
    Copymu_ptInToOutIndex( index, prefix );
    Copymu_etaInToOutIndex( index, prefix );
    Copymu_phiInToOutIndex( index, prefix );
    Copymu_eInToOutIndex( index, prefix );
    Copymu_pfIso_chInToOutIndex( index, prefix );
    Copymu_pfIso_nhInToOutIndex( index, prefix );
    Copymu_pfIso_phoInToOutIndex( index, prefix );
    Copymu_pfIso_puInToOutIndex( index, prefix );
    Copymu_corrIsoInToOutIndex( index, prefix );
    Copymu_truthMatchInToOutIndex( index, prefix );
    Copymu_truthMinDRInToOutIndex( index, prefix );
    Copyph_ptInToOutIndex( index, prefix );
    Copyph_etaInToOutIndex( index, prefix );
    Copyph_phiInToOutIndex( index, prefix );
    Copyph_eInToOutIndex( index, prefix );
    Copyph_HoverEInToOutIndex( index, prefix );
    Copyph_sigmaIEIEInToOutIndex( index, prefix );
    Copyph_chIsoCorrInToOutIndex( index, prefix );
    Copyph_neuIsoCorrInToOutIndex( index, prefix );
    Copyph_phoIsoCorrInToOutIndex( index, prefix );
    Copyph_eleVetoInToOutIndex( index, prefix );
    Copyph_isConvInToOutIndex( index, prefix );
    Copyph_conv_nTrkInToOutIndex( index, prefix );
    Copyph_conv_vtx_xInToOutIndex( index, prefix );
    Copyph_conv_vtx_yInToOutIndex( index, prefix );
    Copyph_conv_vtx_zInToOutIndex( index, prefix );
    Copyph_conv_ptin1InToOutIndex( index, prefix );
    Copyph_conv_ptin2InToOutIndex( index, prefix );
    Copyph_conv_ptout1InToOutIndex( index, prefix );
    Copyph_conv_ptout2InToOutIndex( index, prefix );
    Copyph_passTightInToOutIndex( index, prefix );
    Copyph_passMediumInToOutIndex( index, prefix );
    Copyph_passLooseInToOutIndex( index, prefix );
    Copyph_truthMatch_phInToOutIndex( index, prefix );
    Copyph_truthMatch_elInToOutIndex( index, prefix );
    Copyph_truthMatch_muInToOutIndex( index, prefix );
    Copyph_truthMatch_qInToOutIndex( index, prefix );
    Copyph_sl_ptInToOutIndex( index, prefix );
    Copyph_sl_etaInToOutIndex( index, prefix );
    Copyph_sl_phiInToOutIndex( index, prefix );
    Copyph_sl_eInToOutIndex( index, prefix );
    Copyph_sl_d0InToOutIndex( index, prefix );
    Copyph_sl_z0InToOutIndex( index, prefix );
    Copyph_sl_convfitInToOutIndex( index, prefix );
    Copyph_sl_misshitsInToOutIndex( index, prefix );
    Copyjet_ptInToOutIndex( index, prefix );
    Copyjet_etaInToOutIndex( index, prefix );
    Copyjet_phiInToOutIndex( index, prefix );
    Copyjet_eInToOutIndex( index, prefix );
}; 

void ClearOutputPrefix ( const std::string & prefix ) {
    ClearOutputel_pt( prefix );
    ClearOutputel_eta( prefix );
    ClearOutputel_sceta( prefix );
    ClearOutputel_phi( prefix );
    ClearOutputel_e( prefix );
    ClearOutputel_mva( prefix );
    ClearOutputel_d0pv( prefix );
    ClearOutputel_z0pv( prefix );
    ClearOutputel_sigmaIEIE( prefix );
    ClearOutputel_pfiso30( prefix );
    ClearOutputel_hasMatchedConv( prefix );
    ClearOutputel_passTight( prefix );
    ClearOutputel_passMedium( prefix );
    ClearOutputel_passLoose( prefix );
    ClearOutputel_passVeryLoose( prefix );
    ClearOutputel_passTightTrig( prefix );
    ClearOutputel_truthMatch_ph( prefix );
    ClearOutputel_truthMatch( prefix );
    ClearOutputel_truthMinDR( prefix );
    ClearOutputmu_pt( prefix );
    ClearOutputmu_eta( prefix );
    ClearOutputmu_phi( prefix );
    ClearOutputmu_e( prefix );
    ClearOutputmu_pfIso_ch( prefix );
    ClearOutputmu_pfIso_nh( prefix );
    ClearOutputmu_pfIso_pho( prefix );
    ClearOutputmu_pfIso_pu( prefix );
    ClearOutputmu_corrIso( prefix );
    ClearOutputmu_truthMatch( prefix );
    ClearOutputmu_truthMinDR( prefix );
    ClearOutputph_pt( prefix );
    ClearOutputph_eta( prefix );
    ClearOutputph_phi( prefix );
    ClearOutputph_e( prefix );
    ClearOutputph_HoverE( prefix );
    ClearOutputph_sigmaIEIE( prefix );
    ClearOutputph_chIsoCorr( prefix );
    ClearOutputph_neuIsoCorr( prefix );
    ClearOutputph_phoIsoCorr( prefix );
    ClearOutputph_eleVeto( prefix );
    ClearOutputph_isConv( prefix );
    ClearOutputph_conv_nTrk( prefix );
    ClearOutputph_conv_vtx_x( prefix );
    ClearOutputph_conv_vtx_y( prefix );
    ClearOutputph_conv_vtx_z( prefix );
    ClearOutputph_conv_ptin1( prefix );
    ClearOutputph_conv_ptin2( prefix );
    ClearOutputph_conv_ptout1( prefix );
    ClearOutputph_conv_ptout2( prefix );
    ClearOutputph_passTight( prefix );
    ClearOutputph_passMedium( prefix );
    ClearOutputph_passLoose( prefix );
    ClearOutputph_truthMatch_ph( prefix );
    ClearOutputph_truthMatch_el( prefix );
    ClearOutputph_truthMatch_mu( prefix );
    ClearOutputph_truthMatch_q( prefix );
    ClearOutputph_sl_pt( prefix );
    ClearOutputph_sl_eta( prefix );
    ClearOutputph_sl_phi( prefix );
    ClearOutputph_sl_e( prefix );
    ClearOutputph_sl_d0( prefix );
    ClearOutputph_sl_z0( prefix );
    ClearOutputph_sl_convfit( prefix );
    ClearOutputph_sl_misshits( prefix );
    ClearOutputjet_pt( prefix );
    ClearOutputjet_eta( prefix );
    ClearOutputjet_phi( prefix );
    ClearOutputjet_e( prefix );
}; 

void CopynVtxBSInToOut( std::string prefix ) { 

    std::string my_name = "nVtxBS";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::nVtxBS = IN::nVtxBS;
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

 void Copyel_nInToOut( std::string prefix ) { 

    std::string my_name = "el_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::el_n = IN::el_n;
}; 

 void Copymu_nInToOut( std::string prefix ) { 

    std::string my_name = "mu_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::mu_n = IN::mu_n;
}; 

 void Copyph_nInToOut( std::string prefix ) { 

    std::string my_name = "ph_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::ph_n = IN::ph_n;
}; 

 void Copyph_sl_nInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::ph_sl_n = IN::ph_sl_n;
}; 

 void Copyjet_nInToOut( std::string prefix ) { 

    std::string my_name = "jet_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::jet_n = IN::jet_n;
}; 

 void Copyvtx_nInToOut( std::string prefix ) { 

    std::string my_name = "vtx_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::vtx_n = IN::vtx_n;
}; 

 void Copyel_ptInToOut( std::string prefix ) { 

    std::string my_name = "el_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_pt = std::vector<float>(*IN::el_pt);
}; 

 void Copyel_ptInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_pt->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_pt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_pt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_pt->push_back( IN::el_pt->at(index) ); 
 }; 

 void ClearOutputel_pt( std::string  prefix ) { 

    std::string my_name = "el_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_pt, prefix = " << prefix << std::endl; 
     OUT::el_pt->clear(); 
 }; 

 void Copyel_etaInToOut( std::string prefix ) { 

    std::string my_name = "el_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_eta = std::vector<float>(*IN::el_eta);
}; 

 void Copyel_etaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_eta->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_eta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_eta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_eta->push_back( IN::el_eta->at(index) ); 
 }; 

 void ClearOutputel_eta( std::string  prefix ) { 

    std::string my_name = "el_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_eta, prefix = " << prefix << std::endl; 
     OUT::el_eta->clear(); 
 }; 

 void Copyel_scetaInToOut( std::string prefix ) { 

    std::string my_name = "el_sceta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_sceta = std::vector<float>(*IN::el_sceta);
}; 

 void Copyel_scetaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_sceta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_sceta->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_sceta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_sceta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_sceta->push_back( IN::el_sceta->at(index) ); 
 }; 

 void ClearOutputel_sceta( std::string  prefix ) { 

    std::string my_name = "el_sceta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_sceta, prefix = " << prefix << std::endl; 
     OUT::el_sceta->clear(); 
 }; 

 void Copyel_phiInToOut( std::string prefix ) { 

    std::string my_name = "el_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_phi = std::vector<float>(*IN::el_phi);
}; 

 void Copyel_phiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_phi->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_phi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_phi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_phi->push_back( IN::el_phi->at(index) ); 
 }; 

 void ClearOutputel_phi( std::string  prefix ) { 

    std::string my_name = "el_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_phi, prefix = " << prefix << std::endl; 
     OUT::el_phi->clear(); 
 }; 

 void Copyel_eInToOut( std::string prefix ) { 

    std::string my_name = "el_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_e = std::vector<float>(*IN::el_e);
}; 

 void Copyel_eInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_e->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_e" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_e" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_e->push_back( IN::el_e->at(index) ); 
 }; 

 void ClearOutputel_e( std::string  prefix ) { 

    std::string my_name = "el_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_e, prefix = " << prefix << std::endl; 
     OUT::el_e->clear(); 
 }; 

 void Copyel_mvaInToOut( std::string prefix ) { 

    std::string my_name = "el_mva";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_mva = std::vector<float>(*IN::el_mva);
}; 

 void Copyel_mvaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_mva";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_mva->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_mva" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_mva" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_mva->push_back( IN::el_mva->at(index) ); 
 }; 

 void ClearOutputel_mva( std::string  prefix ) { 

    std::string my_name = "el_mva";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_mva, prefix = " << prefix << std::endl; 
     OUT::el_mva->clear(); 
 }; 

 void Copyel_d0pvInToOut( std::string prefix ) { 

    std::string my_name = "el_d0pv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_d0pv = std::vector<float>(*IN::el_d0pv);
}; 

 void Copyel_d0pvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_d0pv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_d0pv->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_d0pv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_d0pv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_d0pv->push_back( IN::el_d0pv->at(index) ); 
 }; 

 void ClearOutputel_d0pv( std::string  prefix ) { 

    std::string my_name = "el_d0pv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_d0pv, prefix = " << prefix << std::endl; 
     OUT::el_d0pv->clear(); 
 }; 

 void Copyel_z0pvInToOut( std::string prefix ) { 

    std::string my_name = "el_z0pv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_z0pv = std::vector<float>(*IN::el_z0pv);
}; 

 void Copyel_z0pvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_z0pv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_z0pv->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_z0pv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_z0pv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_z0pv->push_back( IN::el_z0pv->at(index) ); 
 }; 

 void ClearOutputel_z0pv( std::string  prefix ) { 

    std::string my_name = "el_z0pv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_z0pv, prefix = " << prefix << std::endl; 
     OUT::el_z0pv->clear(); 
 }; 

 void Copyel_sigmaIEIEInToOut( std::string prefix ) { 

    std::string my_name = "el_sigmaIEIE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_sigmaIEIE = std::vector<float>(*IN::el_sigmaIEIE);
}; 

 void Copyel_sigmaIEIEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_sigmaIEIE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_sigmaIEIE->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_sigmaIEIE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_sigmaIEIE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_sigmaIEIE->push_back( IN::el_sigmaIEIE->at(index) ); 
 }; 

 void ClearOutputel_sigmaIEIE( std::string  prefix ) { 

    std::string my_name = "el_sigmaIEIE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_sigmaIEIE, prefix = " << prefix << std::endl; 
     OUT::el_sigmaIEIE->clear(); 
 }; 

 void Copyel_pfiso30InToOut( std::string prefix ) { 

    std::string my_name = "el_pfiso30";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_pfiso30 = std::vector<float>(*IN::el_pfiso30);
}; 

 void Copyel_pfiso30InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_pfiso30";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_pfiso30->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_pfiso30" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_pfiso30" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_pfiso30->push_back( IN::el_pfiso30->at(index) ); 
 }; 

 void ClearOutputel_pfiso30( std::string  prefix ) { 

    std::string my_name = "el_pfiso30";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_pfiso30, prefix = " << prefix << std::endl; 
     OUT::el_pfiso30->clear(); 
 }; 

 void Copyel_hasMatchedConvInToOut( std::string prefix ) { 

    std::string my_name = "el_hasMatchedConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_hasMatchedConv = std::vector<bool>(*IN::el_hasMatchedConv);
}; 

 void Copyel_hasMatchedConvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_hasMatchedConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_hasMatchedConv->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_hasMatchedConv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_hasMatchedConv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_hasMatchedConv->push_back( IN::el_hasMatchedConv->at(index) ); 
 }; 

 void ClearOutputel_hasMatchedConv( std::string  prefix ) { 

    std::string my_name = "el_hasMatchedConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_hasMatchedConv, prefix = " << prefix << std::endl; 
     OUT::el_hasMatchedConv->clear(); 
 }; 

 void Copyel_passTightInToOut( std::string prefix ) { 

    std::string my_name = "el_passTight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_passTight = std::vector<bool>(*IN::el_passTight);
}; 

 void Copyel_passTightInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_passTight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_passTight->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_passTight" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_passTight" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_passTight->push_back( IN::el_passTight->at(index) ); 
 }; 

 void ClearOutputel_passTight( std::string  prefix ) { 

    std::string my_name = "el_passTight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_passTight, prefix = " << prefix << std::endl; 
     OUT::el_passTight->clear(); 
 }; 

 void Copyel_passMediumInToOut( std::string prefix ) { 

    std::string my_name = "el_passMedium";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_passMedium = std::vector<bool>(*IN::el_passMedium);
}; 

 void Copyel_passMediumInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_passMedium";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_passMedium->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_passMedium" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_passMedium" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_passMedium->push_back( IN::el_passMedium->at(index) ); 
 }; 

 void ClearOutputel_passMedium( std::string  prefix ) { 

    std::string my_name = "el_passMedium";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_passMedium, prefix = " << prefix << std::endl; 
     OUT::el_passMedium->clear(); 
 }; 

 void Copyel_passLooseInToOut( std::string prefix ) { 

    std::string my_name = "el_passLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_passLoose = std::vector<bool>(*IN::el_passLoose);
}; 

 void Copyel_passLooseInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_passLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_passLoose->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_passLoose" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_passLoose" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_passLoose->push_back( IN::el_passLoose->at(index) ); 
 }; 

 void ClearOutputel_passLoose( std::string  prefix ) { 

    std::string my_name = "el_passLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_passLoose, prefix = " << prefix << std::endl; 
     OUT::el_passLoose->clear(); 
 }; 

 void Copyel_passVeryLooseInToOut( std::string prefix ) { 

    std::string my_name = "el_passVeryLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_passVeryLoose = std::vector<bool>(*IN::el_passVeryLoose);
}; 

 void Copyel_passVeryLooseInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_passVeryLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_passVeryLoose->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_passVeryLoose" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_passVeryLoose" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_passVeryLoose->push_back( IN::el_passVeryLoose->at(index) ); 
 }; 

 void ClearOutputel_passVeryLoose( std::string  prefix ) { 

    std::string my_name = "el_passVeryLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_passVeryLoose, prefix = " << prefix << std::endl; 
     OUT::el_passVeryLoose->clear(); 
 }; 

 void Copyel_passTightTrigInToOut( std::string prefix ) { 

    std::string my_name = "el_passTightTrig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_passTightTrig = std::vector<bool>(*IN::el_passTightTrig);
}; 

 void Copyel_passTightTrigInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_passTightTrig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_passTightTrig->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_passTightTrig" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_passTightTrig" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_passTightTrig->push_back( IN::el_passTightTrig->at(index) ); 
 }; 

 void ClearOutputel_passTightTrig( std::string  prefix ) { 

    std::string my_name = "el_passTightTrig";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_passTightTrig, prefix = " << prefix << std::endl; 
     OUT::el_passTightTrig->clear(); 
 }; 

 void Copyel_truthMatch_phInToOut( std::string prefix ) { 

    std::string my_name = "el_truthMatch_ph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_truthMatch_ph = std::vector<bool>(*IN::el_truthMatch_ph);
}; 

 void Copyel_truthMatch_phInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_truthMatch_ph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_truthMatch_ph->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_truthMatch_ph" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_truthMatch_ph" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_truthMatch_ph->push_back( IN::el_truthMatch_ph->at(index) ); 
 }; 

 void ClearOutputel_truthMatch_ph( std::string  prefix ) { 

    std::string my_name = "el_truthMatch_ph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_truthMatch_ph, prefix = " << prefix << std::endl; 
     OUT::el_truthMatch_ph->clear(); 
 }; 

 void Copyel_truthMatchInToOut( std::string prefix ) { 

    std::string my_name = "el_truthMatch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_truthMatch = std::vector<bool>(*IN::el_truthMatch);
}; 

 void Copyel_truthMatchInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_truthMatch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_truthMatch->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_truthMatch" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_truthMatch" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_truthMatch->push_back( IN::el_truthMatch->at(index) ); 
 }; 

 void ClearOutputel_truthMatch( std::string  prefix ) { 

    std::string my_name = "el_truthMatch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_truthMatch, prefix = " << prefix << std::endl; 
     OUT::el_truthMatch->clear(); 
 }; 

 void Copyel_truthMinDRInToOut( std::string prefix ) { 

    std::string my_name = "el_truthMinDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::el_truthMinDR = std::vector<float>(*IN::el_truthMinDR);
}; 

 void Copyel_truthMinDRInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "el_truthMinDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::el_truthMinDR->size() ) {
         std::cout << "Vector size exceeded for branch IN::el_truthMinDR" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible el_truthMinDR" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::el_truthMinDR->push_back( IN::el_truthMinDR->at(index) ); 
 }; 

 void ClearOutputel_truthMinDR( std::string  prefix ) { 

    std::string my_name = "el_truthMinDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible el_truthMinDR, prefix = " << prefix << std::endl; 
     OUT::el_truthMinDR->clear(); 
 }; 

 void Copymu_ptInToOut( std::string prefix ) { 

    std::string my_name = "mu_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_pt = std::vector<float>(*IN::mu_pt);
}; 

 void Copymu_ptInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_pt->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_pt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_pt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_pt->push_back( IN::mu_pt->at(index) ); 
 }; 

 void ClearOutputmu_pt( std::string  prefix ) { 

    std::string my_name = "mu_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_pt, prefix = " << prefix << std::endl; 
     OUT::mu_pt->clear(); 
 }; 

 void Copymu_etaInToOut( std::string prefix ) { 

    std::string my_name = "mu_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_eta = std::vector<float>(*IN::mu_eta);
}; 

 void Copymu_etaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_eta->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_eta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_eta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_eta->push_back( IN::mu_eta->at(index) ); 
 }; 

 void ClearOutputmu_eta( std::string  prefix ) { 

    std::string my_name = "mu_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_eta, prefix = " << prefix << std::endl; 
     OUT::mu_eta->clear(); 
 }; 

 void Copymu_phiInToOut( std::string prefix ) { 

    std::string my_name = "mu_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_phi = std::vector<float>(*IN::mu_phi);
}; 

 void Copymu_phiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_phi->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_phi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_phi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_phi->push_back( IN::mu_phi->at(index) ); 
 }; 

 void ClearOutputmu_phi( std::string  prefix ) { 

    std::string my_name = "mu_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_phi, prefix = " << prefix << std::endl; 
     OUT::mu_phi->clear(); 
 }; 

 void Copymu_eInToOut( std::string prefix ) { 

    std::string my_name = "mu_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_e = std::vector<float>(*IN::mu_e);
}; 

 void Copymu_eInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_e->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_e" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_e" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_e->push_back( IN::mu_e->at(index) ); 
 }; 

 void ClearOutputmu_e( std::string  prefix ) { 

    std::string my_name = "mu_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_e, prefix = " << prefix << std::endl; 
     OUT::mu_e->clear(); 
 }; 

 void Copymu_pfIso_chInToOut( std::string prefix ) { 

    std::string my_name = "mu_pfIso_ch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_pfIso_ch = std::vector<float>(*IN::mu_pfIso_ch);
}; 

 void Copymu_pfIso_chInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_pfIso_ch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_pfIso_ch->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_pfIso_ch" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_pfIso_ch" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_ch->push_back( IN::mu_pfIso_ch->at(index) ); 
 }; 

 void ClearOutputmu_pfIso_ch( std::string  prefix ) { 

    std::string my_name = "mu_pfIso_ch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_pfIso_ch, prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_ch->clear(); 
 }; 

 void Copymu_pfIso_nhInToOut( std::string prefix ) { 

    std::string my_name = "mu_pfIso_nh";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_pfIso_nh = std::vector<float>(*IN::mu_pfIso_nh);
}; 

 void Copymu_pfIso_nhInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_pfIso_nh";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_pfIso_nh->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_pfIso_nh" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_pfIso_nh" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_nh->push_back( IN::mu_pfIso_nh->at(index) ); 
 }; 

 void ClearOutputmu_pfIso_nh( std::string  prefix ) { 

    std::string my_name = "mu_pfIso_nh";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_pfIso_nh, prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_nh->clear(); 
 }; 

 void Copymu_pfIso_phoInToOut( std::string prefix ) { 

    std::string my_name = "mu_pfIso_pho";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_pfIso_pho = std::vector<float>(*IN::mu_pfIso_pho);
}; 

 void Copymu_pfIso_phoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_pfIso_pho";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_pfIso_pho->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_pfIso_pho" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_pfIso_pho" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_pho->push_back( IN::mu_pfIso_pho->at(index) ); 
 }; 

 void ClearOutputmu_pfIso_pho( std::string  prefix ) { 

    std::string my_name = "mu_pfIso_pho";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_pfIso_pho, prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_pho->clear(); 
 }; 

 void Copymu_pfIso_puInToOut( std::string prefix ) { 

    std::string my_name = "mu_pfIso_pu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_pfIso_pu = std::vector<float>(*IN::mu_pfIso_pu);
}; 

 void Copymu_pfIso_puInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_pfIso_pu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_pfIso_pu->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_pfIso_pu" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_pfIso_pu" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_pu->push_back( IN::mu_pfIso_pu->at(index) ); 
 }; 

 void ClearOutputmu_pfIso_pu( std::string  prefix ) { 

    std::string my_name = "mu_pfIso_pu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_pfIso_pu, prefix = " << prefix << std::endl; 
     OUT::mu_pfIso_pu->clear(); 
 }; 

 void Copymu_corrIsoInToOut( std::string prefix ) { 

    std::string my_name = "mu_corrIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_corrIso = std::vector<float>(*IN::mu_corrIso);
}; 

 void Copymu_corrIsoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_corrIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_corrIso->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_corrIso" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_corrIso" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_corrIso->push_back( IN::mu_corrIso->at(index) ); 
 }; 

 void ClearOutputmu_corrIso( std::string  prefix ) { 

    std::string my_name = "mu_corrIso";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_corrIso, prefix = " << prefix << std::endl; 
     OUT::mu_corrIso->clear(); 
 }; 

 void Copymu_truthMatchInToOut( std::string prefix ) { 

    std::string my_name = "mu_truthMatch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_truthMatch = std::vector<bool>(*IN::mu_truthMatch);
}; 

 void Copymu_truthMatchInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_truthMatch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_truthMatch->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_truthMatch" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_truthMatch" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_truthMatch->push_back( IN::mu_truthMatch->at(index) ); 
 }; 

 void ClearOutputmu_truthMatch( std::string  prefix ) { 

    std::string my_name = "mu_truthMatch";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_truthMatch, prefix = " << prefix << std::endl; 
     OUT::mu_truthMatch->clear(); 
 }; 

 void Copymu_truthMinDRInToOut( std::string prefix ) { 

    std::string my_name = "mu_truthMinDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::mu_truthMinDR = std::vector<float>(*IN::mu_truthMinDR);
}; 

 void Copymu_truthMinDRInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "mu_truthMinDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::mu_truthMinDR->size() ) {
         std::cout << "Vector size exceeded for branch IN::mu_truthMinDR" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible mu_truthMinDR" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::mu_truthMinDR->push_back( IN::mu_truthMinDR->at(index) ); 
 }; 

 void ClearOutputmu_truthMinDR( std::string  prefix ) { 

    std::string my_name = "mu_truthMinDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible mu_truthMinDR, prefix = " << prefix << std::endl; 
     OUT::mu_truthMinDR->clear(); 
 }; 

 void Copyph_ptInToOut( std::string prefix ) { 

    std::string my_name = "ph_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_pt = std::vector<float>(*IN::ph_pt);
}; 

 void Copyph_ptInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_pt->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_pt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_pt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_pt->push_back( IN::ph_pt->at(index) ); 
 }; 

 void ClearOutputph_pt( std::string  prefix ) { 

    std::string my_name = "ph_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_pt, prefix = " << prefix << std::endl; 
     OUT::ph_pt->clear(); 
 }; 

 void Copyph_etaInToOut( std::string prefix ) { 

    std::string my_name = "ph_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_eta = std::vector<float>(*IN::ph_eta);
}; 

 void Copyph_etaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_eta->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_eta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_eta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_eta->push_back( IN::ph_eta->at(index) ); 
 }; 

 void ClearOutputph_eta( std::string  prefix ) { 

    std::string my_name = "ph_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_eta, prefix = " << prefix << std::endl; 
     OUT::ph_eta->clear(); 
 }; 

 void Copyph_phiInToOut( std::string prefix ) { 

    std::string my_name = "ph_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_phi = std::vector<float>(*IN::ph_phi);
}; 

 void Copyph_phiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_phi->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_phi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_phi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_phi->push_back( IN::ph_phi->at(index) ); 
 }; 

 void ClearOutputph_phi( std::string  prefix ) { 

    std::string my_name = "ph_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_phi, prefix = " << prefix << std::endl; 
     OUT::ph_phi->clear(); 
 }; 

 void Copyph_eInToOut( std::string prefix ) { 

    std::string my_name = "ph_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_e = std::vector<float>(*IN::ph_e);
}; 

 void Copyph_eInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_e->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_e" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_e" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_e->push_back( IN::ph_e->at(index) ); 
 }; 

 void ClearOutputph_e( std::string  prefix ) { 

    std::string my_name = "ph_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_e, prefix = " << prefix << std::endl; 
     OUT::ph_e->clear(); 
 }; 

 void Copyph_HoverEInToOut( std::string prefix ) { 

    std::string my_name = "ph_HoverE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_HoverE = std::vector<float>(*IN::ph_HoverE);
}; 

 void Copyph_HoverEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_HoverE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_HoverE->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_HoverE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_HoverE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_HoverE->push_back( IN::ph_HoverE->at(index) ); 
 }; 

 void ClearOutputph_HoverE( std::string  prefix ) { 

    std::string my_name = "ph_HoverE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_HoverE, prefix = " << prefix << std::endl; 
     OUT::ph_HoverE->clear(); 
 }; 

 void Copyph_sigmaIEIEInToOut( std::string prefix ) { 

    std::string my_name = "ph_sigmaIEIE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sigmaIEIE = std::vector<float>(*IN::ph_sigmaIEIE);
}; 

 void Copyph_sigmaIEIEInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sigmaIEIE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sigmaIEIE->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sigmaIEIE" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sigmaIEIE" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sigmaIEIE->push_back( IN::ph_sigmaIEIE->at(index) ); 
 }; 

 void ClearOutputph_sigmaIEIE( std::string  prefix ) { 

    std::string my_name = "ph_sigmaIEIE";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sigmaIEIE, prefix = " << prefix << std::endl; 
     OUT::ph_sigmaIEIE->clear(); 
 }; 

 void Copyph_chIsoCorrInToOut( std::string prefix ) { 

    std::string my_name = "ph_chIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_chIsoCorr = std::vector<float>(*IN::ph_chIsoCorr);
}; 

 void Copyph_chIsoCorrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_chIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_chIsoCorr->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_chIsoCorr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_chIsoCorr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_chIsoCorr->push_back( IN::ph_chIsoCorr->at(index) ); 
 }; 

 void ClearOutputph_chIsoCorr( std::string  prefix ) { 

    std::string my_name = "ph_chIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_chIsoCorr, prefix = " << prefix << std::endl; 
     OUT::ph_chIsoCorr->clear(); 
 }; 

 void Copyph_neuIsoCorrInToOut( std::string prefix ) { 

    std::string my_name = "ph_neuIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_neuIsoCorr = std::vector<float>(*IN::ph_neuIsoCorr);
}; 

 void Copyph_neuIsoCorrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_neuIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_neuIsoCorr->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_neuIsoCorr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_neuIsoCorr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_neuIsoCorr->push_back( IN::ph_neuIsoCorr->at(index) ); 
 }; 

 void ClearOutputph_neuIsoCorr( std::string  prefix ) { 

    std::string my_name = "ph_neuIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_neuIsoCorr, prefix = " << prefix << std::endl; 
     OUT::ph_neuIsoCorr->clear(); 
 }; 

 void Copyph_phoIsoCorrInToOut( std::string prefix ) { 

    std::string my_name = "ph_phoIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_phoIsoCorr = std::vector<float>(*IN::ph_phoIsoCorr);
}; 

 void Copyph_phoIsoCorrInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_phoIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_phoIsoCorr->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_phoIsoCorr" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_phoIsoCorr" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_phoIsoCorr->push_back( IN::ph_phoIsoCorr->at(index) ); 
 }; 

 void ClearOutputph_phoIsoCorr( std::string  prefix ) { 

    std::string my_name = "ph_phoIsoCorr";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_phoIsoCorr, prefix = " << prefix << std::endl; 
     OUT::ph_phoIsoCorr->clear(); 
 }; 

 void Copyph_eleVetoInToOut( std::string prefix ) { 

    std::string my_name = "ph_eleVeto";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_eleVeto = std::vector<int>(*IN::ph_eleVeto);
}; 

 void Copyph_eleVetoInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_eleVeto";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_eleVeto->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_eleVeto" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_eleVeto" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_eleVeto->push_back( IN::ph_eleVeto->at(index) ); 
 }; 

 void ClearOutputph_eleVeto( std::string  prefix ) { 

    std::string my_name = "ph_eleVeto";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_eleVeto, prefix = " << prefix << std::endl; 
     OUT::ph_eleVeto->clear(); 
 }; 

 void Copyph_isConvInToOut( std::string prefix ) { 

    std::string my_name = "ph_isConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_isConv = std::vector<bool>(*IN::ph_isConv);
}; 

 void Copyph_isConvInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_isConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_isConv->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_isConv" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_isConv" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_isConv->push_back( IN::ph_isConv->at(index) ); 
 }; 

 void ClearOutputph_isConv( std::string  prefix ) { 

    std::string my_name = "ph_isConv";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_isConv, prefix = " << prefix << std::endl; 
     OUT::ph_isConv->clear(); 
 }; 

 void Copyph_conv_nTrkInToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_nTrk";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_nTrk = std::vector<int>(*IN::ph_conv_nTrk);
}; 

 void Copyph_conv_nTrkInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_nTrk";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_nTrk->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_nTrk" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_nTrk" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_nTrk->push_back( IN::ph_conv_nTrk->at(index) ); 
 }; 

 void ClearOutputph_conv_nTrk( std::string  prefix ) { 

    std::string my_name = "ph_conv_nTrk";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_nTrk, prefix = " << prefix << std::endl; 
     OUT::ph_conv_nTrk->clear(); 
 }; 

 void Copyph_conv_vtx_xInToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_vtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_vtx_x = std::vector<float>(*IN::ph_conv_vtx_x);
}; 

 void Copyph_conv_vtx_xInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_vtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_vtx_x->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_vtx_x" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_vtx_x" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_vtx_x->push_back( IN::ph_conv_vtx_x->at(index) ); 
 }; 

 void ClearOutputph_conv_vtx_x( std::string  prefix ) { 

    std::string my_name = "ph_conv_vtx_x";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_vtx_x, prefix = " << prefix << std::endl; 
     OUT::ph_conv_vtx_x->clear(); 
 }; 

 void Copyph_conv_vtx_yInToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_vtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_vtx_y = std::vector<float>(*IN::ph_conv_vtx_y);
}; 

 void Copyph_conv_vtx_yInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_vtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_vtx_y->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_vtx_y" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_vtx_y" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_vtx_y->push_back( IN::ph_conv_vtx_y->at(index) ); 
 }; 

 void ClearOutputph_conv_vtx_y( std::string  prefix ) { 

    std::string my_name = "ph_conv_vtx_y";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_vtx_y, prefix = " << prefix << std::endl; 
     OUT::ph_conv_vtx_y->clear(); 
 }; 

 void Copyph_conv_vtx_zInToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_vtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_vtx_z = std::vector<float>(*IN::ph_conv_vtx_z);
}; 

 void Copyph_conv_vtx_zInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_vtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_vtx_z->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_vtx_z" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_vtx_z" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_vtx_z->push_back( IN::ph_conv_vtx_z->at(index) ); 
 }; 

 void ClearOutputph_conv_vtx_z( std::string  prefix ) { 

    std::string my_name = "ph_conv_vtx_z";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_vtx_z, prefix = " << prefix << std::endl; 
     OUT::ph_conv_vtx_z->clear(); 
 }; 

 void Copyph_conv_ptin1InToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_ptin1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_ptin1 = std::vector<float>(*IN::ph_conv_ptin1);
}; 

 void Copyph_conv_ptin1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_ptin1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_ptin1->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_ptin1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_ptin1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptin1->push_back( IN::ph_conv_ptin1->at(index) ); 
 }; 

 void ClearOutputph_conv_ptin1( std::string  prefix ) { 

    std::string my_name = "ph_conv_ptin1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_ptin1, prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptin1->clear(); 
 }; 

 void Copyph_conv_ptin2InToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_ptin2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_ptin2 = std::vector<float>(*IN::ph_conv_ptin2);
}; 

 void Copyph_conv_ptin2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_ptin2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_ptin2->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_ptin2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_ptin2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptin2->push_back( IN::ph_conv_ptin2->at(index) ); 
 }; 

 void ClearOutputph_conv_ptin2( std::string  prefix ) { 

    std::string my_name = "ph_conv_ptin2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_ptin2, prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptin2->clear(); 
 }; 

 void Copyph_conv_ptout1InToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_ptout1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_ptout1 = std::vector<float>(*IN::ph_conv_ptout1);
}; 

 void Copyph_conv_ptout1InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_ptout1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_ptout1->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_ptout1" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_ptout1" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptout1->push_back( IN::ph_conv_ptout1->at(index) ); 
 }; 

 void ClearOutputph_conv_ptout1( std::string  prefix ) { 

    std::string my_name = "ph_conv_ptout1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_ptout1, prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptout1->clear(); 
 }; 

 void Copyph_conv_ptout2InToOut( std::string prefix ) { 

    std::string my_name = "ph_conv_ptout2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_conv_ptout2 = std::vector<float>(*IN::ph_conv_ptout2);
}; 

 void Copyph_conv_ptout2InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_conv_ptout2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_conv_ptout2->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_conv_ptout2" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_conv_ptout2" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptout2->push_back( IN::ph_conv_ptout2->at(index) ); 
 }; 

 void ClearOutputph_conv_ptout2( std::string  prefix ) { 

    std::string my_name = "ph_conv_ptout2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_conv_ptout2, prefix = " << prefix << std::endl; 
     OUT::ph_conv_ptout2->clear(); 
 }; 

 void Copyph_passTightInToOut( std::string prefix ) { 

    std::string my_name = "ph_passTight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_passTight = std::vector<bool>(*IN::ph_passTight);
}; 

 void Copyph_passTightInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_passTight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_passTight->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_passTight" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_passTight" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_passTight->push_back( IN::ph_passTight->at(index) ); 
 }; 

 void ClearOutputph_passTight( std::string  prefix ) { 

    std::string my_name = "ph_passTight";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_passTight, prefix = " << prefix << std::endl; 
     OUT::ph_passTight->clear(); 
 }; 

 void Copyph_passMediumInToOut( std::string prefix ) { 

    std::string my_name = "ph_passMedium";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_passMedium = std::vector<bool>(*IN::ph_passMedium);
}; 

 void Copyph_passMediumInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_passMedium";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_passMedium->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_passMedium" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_passMedium" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_passMedium->push_back( IN::ph_passMedium->at(index) ); 
 }; 

 void ClearOutputph_passMedium( std::string  prefix ) { 

    std::string my_name = "ph_passMedium";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_passMedium, prefix = " << prefix << std::endl; 
     OUT::ph_passMedium->clear(); 
 }; 

 void Copyph_passLooseInToOut( std::string prefix ) { 

    std::string my_name = "ph_passLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_passLoose = std::vector<bool>(*IN::ph_passLoose);
}; 

 void Copyph_passLooseInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_passLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_passLoose->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_passLoose" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_passLoose" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_passLoose->push_back( IN::ph_passLoose->at(index) ); 
 }; 

 void ClearOutputph_passLoose( std::string  prefix ) { 

    std::string my_name = "ph_passLoose";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_passLoose, prefix = " << prefix << std::endl; 
     OUT::ph_passLoose->clear(); 
 }; 

 void Copyph_truthMatch_phInToOut( std::string prefix ) { 

    std::string my_name = "ph_truthMatch_ph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_truthMatch_ph = std::vector<bool>(*IN::ph_truthMatch_ph);
}; 

 void Copyph_truthMatch_phInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_ph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_truthMatch_ph->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_truthMatch_ph" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_truthMatch_ph" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_ph->push_back( IN::ph_truthMatch_ph->at(index) ); 
 }; 

 void ClearOutputph_truthMatch_ph( std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_ph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_truthMatch_ph, prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_ph->clear(); 
 }; 

 void Copyph_truthMatch_elInToOut( std::string prefix ) { 

    std::string my_name = "ph_truthMatch_el";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_truthMatch_el = std::vector<bool>(*IN::ph_truthMatch_el);
}; 

 void Copyph_truthMatch_elInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_el";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_truthMatch_el->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_truthMatch_el" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_truthMatch_el" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_el->push_back( IN::ph_truthMatch_el->at(index) ); 
 }; 

 void ClearOutputph_truthMatch_el( std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_el";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_truthMatch_el, prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_el->clear(); 
 }; 

 void Copyph_truthMatch_muInToOut( std::string prefix ) { 

    std::string my_name = "ph_truthMatch_mu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_truthMatch_mu = std::vector<bool>(*IN::ph_truthMatch_mu);
}; 

 void Copyph_truthMatch_muInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_mu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_truthMatch_mu->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_truthMatch_mu" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_truthMatch_mu" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_mu->push_back( IN::ph_truthMatch_mu->at(index) ); 
 }; 

 void ClearOutputph_truthMatch_mu( std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_mu";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_truthMatch_mu, prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_mu->clear(); 
 }; 

 void Copyph_truthMatch_qInToOut( std::string prefix ) { 

    std::string my_name = "ph_truthMatch_q";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_truthMatch_q = std::vector<bool>(*IN::ph_truthMatch_q);
}; 

 void Copyph_truthMatch_qInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_q";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_truthMatch_q->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_truthMatch_q" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_truthMatch_q" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_q->push_back( IN::ph_truthMatch_q->at(index) ); 
 }; 

 void ClearOutputph_truthMatch_q( std::string  prefix ) { 

    std::string my_name = "ph_truthMatch_q";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_truthMatch_q, prefix = " << prefix << std::endl; 
     OUT::ph_truthMatch_q->clear(); 
 }; 

 void Copyph_sl_ptInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_pt = std::vector<float>(*IN::ph_sl_pt);
}; 

 void Copyph_sl_ptInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_pt->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_pt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_pt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_pt->push_back( IN::ph_sl_pt->at(index) ); 
 }; 

 void ClearOutputph_sl_pt( std::string  prefix ) { 

    std::string my_name = "ph_sl_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_pt, prefix = " << prefix << std::endl; 
     OUT::ph_sl_pt->clear(); 
 }; 

 void Copyph_sl_etaInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_eta = std::vector<float>(*IN::ph_sl_eta);
}; 

 void Copyph_sl_etaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_eta->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_eta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_eta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_eta->push_back( IN::ph_sl_eta->at(index) ); 
 }; 

 void ClearOutputph_sl_eta( std::string  prefix ) { 

    std::string my_name = "ph_sl_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_eta, prefix = " << prefix << std::endl; 
     OUT::ph_sl_eta->clear(); 
 }; 

 void Copyph_sl_phiInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_phi = std::vector<float>(*IN::ph_sl_phi);
}; 

 void Copyph_sl_phiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_phi->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_phi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_phi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_phi->push_back( IN::ph_sl_phi->at(index) ); 
 }; 

 void ClearOutputph_sl_phi( std::string  prefix ) { 

    std::string my_name = "ph_sl_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_phi, prefix = " << prefix << std::endl; 
     OUT::ph_sl_phi->clear(); 
 }; 

 void Copyph_sl_eInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_e = std::vector<float>(*IN::ph_sl_e);
}; 

 void Copyph_sl_eInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_e->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_e" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_e" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_e->push_back( IN::ph_sl_e->at(index) ); 
 }; 

 void ClearOutputph_sl_e( std::string  prefix ) { 

    std::string my_name = "ph_sl_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_e, prefix = " << prefix << std::endl; 
     OUT::ph_sl_e->clear(); 
 }; 

 void Copyph_sl_d0InToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_d0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_d0 = std::vector<float>(*IN::ph_sl_d0);
}; 

 void Copyph_sl_d0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_d0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_d0->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_d0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_d0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_d0->push_back( IN::ph_sl_d0->at(index) ); 
 }; 

 void ClearOutputph_sl_d0( std::string  prefix ) { 

    std::string my_name = "ph_sl_d0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_d0, prefix = " << prefix << std::endl; 
     OUT::ph_sl_d0->clear(); 
 }; 

 void Copyph_sl_z0InToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_z0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_z0 = std::vector<float>(*IN::ph_sl_z0);
}; 

 void Copyph_sl_z0InToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_z0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_z0->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_z0" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_z0" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_z0->push_back( IN::ph_sl_z0->at(index) ); 
 }; 

 void ClearOutputph_sl_z0( std::string  prefix ) { 

    std::string my_name = "ph_sl_z0";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_z0, prefix = " << prefix << std::endl; 
     OUT::ph_sl_z0->clear(); 
 }; 

 void Copyph_sl_convfitInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_convfit";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_convfit = std::vector<int>(*IN::ph_sl_convfit);
}; 

 void Copyph_sl_convfitInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_convfit";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_convfit->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_convfit" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_convfit" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_convfit->push_back( IN::ph_sl_convfit->at(index) ); 
 }; 

 void ClearOutputph_sl_convfit( std::string  prefix ) { 

    std::string my_name = "ph_sl_convfit";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_convfit, prefix = " << prefix << std::endl; 
     OUT::ph_sl_convfit->clear(); 
 }; 

 void Copyph_sl_misshitsInToOut( std::string prefix ) { 

    std::string my_name = "ph_sl_misshits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::ph_sl_misshits = std::vector<int>(*IN::ph_sl_misshits);
}; 

 void Copyph_sl_misshitsInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "ph_sl_misshits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::ph_sl_misshits->size() ) {
         std::cout << "Vector size exceeded for branch IN::ph_sl_misshits" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible ph_sl_misshits" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::ph_sl_misshits->push_back( IN::ph_sl_misshits->at(index) ); 
 }; 

 void ClearOutputph_sl_misshits( std::string  prefix ) { 

    std::string my_name = "ph_sl_misshits";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible ph_sl_misshits, prefix = " << prefix << std::endl; 
     OUT::ph_sl_misshits->clear(); 
 }; 

 void Copyjet_ptInToOut( std::string prefix ) { 

    std::string my_name = "jet_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jet_pt = std::vector<float>(*IN::jet_pt);
}; 

 void Copyjet_ptInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jet_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jet_pt->size() ) {
         std::cout << "Vector size exceeded for branch IN::jet_pt" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jet_pt" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jet_pt->push_back( IN::jet_pt->at(index) ); 
 }; 

 void ClearOutputjet_pt( std::string  prefix ) { 

    std::string my_name = "jet_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jet_pt, prefix = " << prefix << std::endl; 
     OUT::jet_pt->clear(); 
 }; 

 void Copyjet_etaInToOut( std::string prefix ) { 

    std::string my_name = "jet_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jet_eta = std::vector<float>(*IN::jet_eta);
}; 

 void Copyjet_etaInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jet_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jet_eta->size() ) {
         std::cout << "Vector size exceeded for branch IN::jet_eta" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jet_eta" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jet_eta->push_back( IN::jet_eta->at(index) ); 
 }; 

 void ClearOutputjet_eta( std::string  prefix ) { 

    std::string my_name = "jet_eta";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jet_eta, prefix = " << prefix << std::endl; 
     OUT::jet_eta->clear(); 
 }; 

 void Copyjet_phiInToOut( std::string prefix ) { 

    std::string my_name = "jet_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jet_phi = std::vector<float>(*IN::jet_phi);
}; 

 void Copyjet_phiInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jet_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jet_phi->size() ) {
         std::cout << "Vector size exceeded for branch IN::jet_phi" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jet_phi" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jet_phi->push_back( IN::jet_phi->at(index) ); 
 }; 

 void ClearOutputjet_phi( std::string  prefix ) { 

    std::string my_name = "jet_phi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jet_phi, prefix = " << prefix << std::endl; 
     OUT::jet_phi->clear(); 
 }; 

 void Copyjet_eInToOut( std::string prefix ) { 

    std::string my_name = "jet_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  *OUT::jet_e = std::vector<float>(*IN::jet_e);
}; 

 void Copyjet_eInToOutIndex( unsigned index, std::string  prefix ) { 

    std::string my_name = "jet_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    if( index >= IN::jet_e->size() ) {
         std::cout << "Vector size exceeded for branch IN::jet_e" << std::endl;
         return; 
     }; 

     //std::cout << "Copy varaible jet_e" << " at index " << index << ", prefix = " << prefix << std::endl; 
     OUT::jet_e->push_back( IN::jet_e->at(index) ); 
 }; 

 void ClearOutputjet_e( std::string  prefix ) { 

    std::string my_name = "jet_e";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
    //std::cout << "Clear varaible jet_e, prefix = " << prefix << std::endl; 
     OUT::jet_e->clear(); 
 }; 

 void CopyavgPUInToOut( std::string prefix ) { 

    std::string my_name = "avgPU";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::avgPU = IN::avgPU;
}; 

 void CopyisBlindedInToOut( std::string prefix ) { 

    std::string my_name = "isBlinded";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::isBlinded = IN::isBlinded;
}; 

 void Copymu_pt25_nInToOut( std::string prefix ) { 

    std::string my_name = "mu_pt25_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::mu_pt25_n = IN::mu_pt25_n;
}; 

 void Copyel_pt25_nInToOut( std::string prefix ) { 

    std::string my_name = "el_pt25_n";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::el_pt25_n = IN::el_pt25_n;
}; 

 void CopyleadPhot_ptInToOut( std::string prefix ) { 

    std::string my_name = "leadPhot_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::leadPhot_pt = IN::leadPhot_pt;
}; 

 void CopysublPhot_ptInToOut( std::string prefix ) { 

    std::string my_name = "sublPhot_pt";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::sublPhot_pt = IN::sublPhot_pt;
}; 

 void CopyleadPhot_lepDRInToOut( std::string prefix ) { 

    std::string my_name = "leadPhot_lepDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::leadPhot_lepDR = IN::leadPhot_lepDR;
}; 

 void CopysublPhot_lepDRInToOut( std::string prefix ) { 

    std::string my_name = "sublPhot_lepDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::sublPhot_lepDR = IN::sublPhot_lepDR;
}; 

 void Copyph_phDRInToOut( std::string prefix ) { 

    std::string my_name = "ph_phDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::ph_phDR = IN::ph_phDR;
}; 

 void CopyphPhot_lepDRInToOut( std::string prefix ) { 

    std::string my_name = "phPhot_lepDR";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::phPhot_lepDR = IN::phPhot_lepDR;
}; 

 void CopyleadPhot_lepDPhiInToOut( std::string prefix ) { 

    std::string my_name = "leadPhot_lepDPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::leadPhot_lepDPhi = IN::leadPhot_lepDPhi;
}; 

 void CopysublPhot_lepDPhiInToOut( std::string prefix ) { 

    std::string my_name = "sublPhot_lepDPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::sublPhot_lepDPhi = IN::sublPhot_lepDPhi;
}; 

 void Copyph_phDPhiInToOut( std::string prefix ) { 

    std::string my_name = "ph_phDPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::ph_phDPhi = IN::ph_phDPhi;
}; 

 void CopyphPhot_lepDPhiInToOut( std::string prefix ) { 

    std::string my_name = "phPhot_lepDPhi";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::phPhot_lepDPhi = IN::phPhot_lepDPhi;
}; 

 void Copymt_lep_metInToOut( std::string prefix ) { 

    std::string my_name = "mt_lep_met";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::mt_lep_met = IN::mt_lep_met;
}; 

 void Copymt_lepph1_metInToOut( std::string prefix ) { 

    std::string my_name = "mt_lepph1_met";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::mt_lepph1_met = IN::mt_lepph1_met;
}; 

 void Copymt_lepph2_metInToOut( std::string prefix ) { 

    std::string my_name = "mt_lepph2_met";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::mt_lepph2_met = IN::mt_lepph2_met;
}; 

 void Copymt_lepphph_metInToOut( std::string prefix ) { 

    std::string my_name = "mt_lepphph_met";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::mt_lepphph_met = IN::mt_lepphph_met;
}; 

 void Copym_leplepInToOut( std::string prefix ) { 

    std::string my_name = "m_leplep";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_leplep = IN::m_leplep;
}; 

 void Copym_lepph1InToOut( std::string prefix ) { 

    std::string my_name = "m_lepph1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_lepph1 = IN::m_lepph1;
}; 

 void Copym_lepph2InToOut( std::string prefix ) { 

    std::string my_name = "m_lepph2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_lepph2 = IN::m_lepph2;
}; 

 void Copym_leplepphInToOut( std::string prefix ) { 

    std::string my_name = "m_leplepph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_leplepph = IN::m_leplepph;
}; 

 void Copym_lepphphInToOut( std::string prefix ) { 

    std::string my_name = "m_lepphph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_lepphph = IN::m_lepphph;
}; 

 void Copym_phphInToOut( std::string prefix ) { 

    std::string my_name = "m_phph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_phph = IN::m_phph;
}; 

 void Copym_leplepZInToOut( std::string prefix ) { 

    std::string my_name = "m_leplepZ";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_leplepZ = IN::m_leplepZ;
}; 

 void Copym_3lepInToOut( std::string prefix ) { 

    std::string my_name = "m_3lep";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_3lep = IN::m_3lep;
}; 

 void Copym_4lepInToOut( std::string prefix ) { 

    std::string my_name = "m_4lep";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::m_4lep = IN::m_4lep;
}; 

 void Copypt_leplepInToOut( std::string prefix ) { 

    std::string my_name = "pt_leplep";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_leplep = IN::pt_leplep;
}; 

 void Copypt_lepph1InToOut( std::string prefix ) { 

    std::string my_name = "pt_lepph1";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_lepph1 = IN::pt_lepph1;
}; 

 void Copypt_lepph2InToOut( std::string prefix ) { 

    std::string my_name = "pt_lepph2";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_lepph2 = IN::pt_lepph2;
}; 

 void Copypt_lepphphInToOut( std::string prefix ) { 

    std::string my_name = "pt_lepphph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_lepphph = IN::pt_lepphph;
}; 

 void Copypt_leplepphInToOut( std::string prefix ) { 

    std::string my_name = "pt_leplepph";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_leplepph = IN::pt_leplepph;
}; 

 void Copypt_secondLeptonInToOut( std::string prefix ) { 

    std::string my_name = "pt_secondLepton";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_secondLepton = IN::pt_secondLepton;
}; 

 void Copypt_thirdLeptonInToOut( std::string prefix ) { 

    std::string my_name = "pt_thirdLepton";
    std::size_t pos = my_name.find( prefix ); 
    // if the filter is given only continue if its matched at the beginning 
    if( prefix != "" &&  pos != 0 ) return; 
  OUT::pt_thirdLepton = IN::pt_thirdLepton;
}; 

 