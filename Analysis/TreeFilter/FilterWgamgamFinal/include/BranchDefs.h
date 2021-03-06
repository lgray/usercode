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
//and if the variable does not exist the preprocessor will ignore that code#define EXISTS_nVtxBS
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
#define EXISTS_el_n
#define EXISTS_mu_n
#define EXISTS_ph_n
#define EXISTS_vtx_n
#define EXISTS_el_pt
#define EXISTS_el_eta
#define EXISTS_el_sceta
#define EXISTS_el_phi
#define EXISTS_el_e
#define EXISTS_el_mva
#define EXISTS_el_d0pv
#define EXISTS_el_z0pv
#define EXISTS_el_hasMatchedConv
#define EXISTS_el_passTight
#define EXISTS_el_passMedium
#define EXISTS_el_passLoose
#define EXISTS_el_passVeryLoose
#define EXISTS_el_truthMatch_ph
#define EXISTS_el_truthMatch
#define EXISTS_el_truthMinDR
#define EXISTS_mu_pt
#define EXISTS_mu_eta
#define EXISTS_mu_phi
#define EXISTS_mu_e
#define EXISTS_mu_pfIso_ch
#define EXISTS_mu_pfIso_nh
#define EXISTS_mu_pfIso_pho
#define EXISTS_mu_pfIso_pu
#define EXISTS_mu_corrIso
#define EXISTS_mu_truthMatch
#define EXISTS_mu_truthMinDR
#define EXISTS_ph_pt
#define EXISTS_ph_eta
#define EXISTS_ph_phi
#define EXISTS_ph_e
#define EXISTS_ph_HoverE
#define EXISTS_ph_sigmaIEIE
#define EXISTS_ph_chIsoCorr
#define EXISTS_ph_neuIsoCorr
#define EXISTS_ph_phoIsoCorr
#define EXISTS_ph_isConv
#define EXISTS_ph_conv_nTrk
#define EXISTS_ph_conv_vtx_x
#define EXISTS_ph_conv_vtx_y
#define EXISTS_ph_conv_vtx_z
#define EXISTS_ph_conv_ptin1
#define EXISTS_ph_conv_ptin2
#define EXISTS_ph_conv_ptout1
#define EXISTS_ph_conv_ptout2
#define EXISTS_ph_passTight
#define EXISTS_ph_passMedium
#define EXISTS_ph_passLoose
#define EXISTS_avgPU
#define EXISTS_leadPhot_pt
#define EXISTS_sublPhot_pt
#define EXISTS_leadPhot_lepDR
#define EXISTS_sublPhot_lepDR
#define EXISTS_ph_phDR
#define EXISTS_phPhot_lepDR
#define EXISTS_leadPhot_lepDPhi
#define EXISTS_sublPhot_lepDPhi
#define EXISTS_ph_phDPhi
#define EXISTS_phPhot_lepDPhi
#define EXISTS_mt_lep_met
#define EXISTS_mt_lepph1_met
#define EXISTS_mt_lepph2_met
#define EXISTS_mt_lepphph_met
#define EXISTS_m_leplep
#define EXISTS_m_lepph1
#define EXISTS_m_lepph2
#define EXISTS_m_lepphph
#define EXISTS_m_phph
//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions
namespace IN {
 extern Int_t				nVtxBS;
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
 extern Int_t				el_n;
 extern Int_t				mu_n;
 extern Int_t				ph_n;
 extern Int_t				vtx_n;
 extern std::vector<float>				*el_pt;
 extern std::vector<float>				*el_eta;
 extern std::vector<float>				*el_sceta;
 extern std::vector<float>				*el_phi;
 extern std::vector<float>				*el_e;
 extern std::vector<float>				*el_mva;
 extern std::vector<float>				*el_d0pv;
 extern std::vector<float>				*el_z0pv;
 extern std::vector<bool>				*el_hasMatchedConv;
 extern std::vector<bool>				*el_passTight;
 extern std::vector<bool>				*el_passMedium;
 extern std::vector<bool>				*el_passLoose;
 extern std::vector<bool>				*el_passVeryLoose;
 extern std::vector<bool>				*el_truthMatch_ph;
 extern std::vector<bool>				*el_truthMatch;
 extern std::vector<float>				*el_truthMinDR;
 extern std::vector<float>				*mu_pt;
 extern std::vector<float>				*mu_eta;
 extern std::vector<float>				*mu_phi;
 extern std::vector<float>				*mu_e;
 extern std::vector<float>				*mu_pfIso_ch;
 extern std::vector<float>				*mu_pfIso_nh;
 extern std::vector<float>				*mu_pfIso_pho;
 extern std::vector<float>				*mu_pfIso_pu;
 extern std::vector<float>				*mu_corrIso;
 extern std::vector<bool>				*mu_truthMatch;
 extern std::vector<float>				*mu_truthMinDR;
 extern std::vector<float>				*ph_pt;
 extern std::vector<float>				*ph_eta;
 extern std::vector<float>				*ph_phi;
 extern std::vector<float>				*ph_e;
 extern std::vector<float>				*ph_HoverE;
 extern std::vector<float>				*ph_sigmaIEIE;
 extern std::vector<float>				*ph_chIsoCorr;
 extern std::vector<float>				*ph_neuIsoCorr;
 extern std::vector<float>				*ph_phoIsoCorr;
 extern std::vector<bool>				*ph_isConv;
 extern std::vector<int>				*ph_conv_nTrk;
 extern std::vector<float>				*ph_conv_vtx_x;
 extern std::vector<float>				*ph_conv_vtx_y;
 extern std::vector<float>				*ph_conv_vtx_z;
 extern std::vector<float>				*ph_conv_ptin1;
 extern std::vector<float>				*ph_conv_ptin2;
 extern std::vector<float>				*ph_conv_ptout1;
 extern std::vector<float>				*ph_conv_ptout2;
 extern std::vector<bool>				*ph_passTight;
 extern std::vector<bool>				*ph_passMedium;
 extern std::vector<bool>				*ph_passLoose;
 extern Float_t				avgPU;
 extern Float_t				leadPhot_pt;
 extern Float_t				sublPhot_pt;
 extern Float_t				leadPhot_lepDR;
 extern Float_t				sublPhot_lepDR;
 extern Float_t				ph_phDR;
 extern Float_t				phPhot_lepDR;
 extern Float_t				leadPhot_lepDPhi;
 extern Float_t				sublPhot_lepDPhi;
 extern Float_t				ph_phDPhi;
 extern Float_t				phPhot_lepDPhi;
 extern Float_t				mt_lep_met;
 extern Float_t				mt_lepph1_met;
 extern Float_t				mt_lepph2_met;
 extern Float_t				mt_lepphph_met;
 extern Float_t				m_leplep;
 extern Float_t				m_lepph1;
 extern Float_t				m_lepph2;
 extern Float_t				m_lepphph;
 extern Float_t				m_phph;
};
namespace OUT {
 extern Int_t				nVtxBS;
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
 extern Int_t				el_n;
 extern Int_t				mu_n;
 extern Int_t				ph_n;
 extern Int_t				vtx_n;
 extern std::vector<float>				*el_pt;
 extern std::vector<float>				*el_eta;
 extern std::vector<float>				*el_sceta;
 extern std::vector<float>				*el_phi;
 extern std::vector<float>				*el_e;
 extern std::vector<float>				*el_mva;
 extern std::vector<float>				*el_d0pv;
 extern std::vector<float>				*el_z0pv;
 extern std::vector<bool>				*el_hasMatchedConv;
 extern std::vector<bool>				*el_passTight;
 extern std::vector<bool>				*el_passMedium;
 extern std::vector<bool>				*el_passLoose;
 extern std::vector<bool>				*el_passVeryLoose;
 extern std::vector<bool>				*el_truthMatch_ph;
 extern std::vector<bool>				*el_truthMatch;
 extern std::vector<float>				*el_truthMinDR;
 extern std::vector<float>				*mu_pt;
 extern std::vector<float>				*mu_eta;
 extern std::vector<float>				*mu_phi;
 extern std::vector<float>				*mu_e;
 extern std::vector<float>				*mu_pfIso_ch;
 extern std::vector<float>				*mu_pfIso_nh;
 extern std::vector<float>				*mu_pfIso_pho;
 extern std::vector<float>				*mu_pfIso_pu;
 extern std::vector<float>				*mu_corrIso;
 extern std::vector<bool>				*mu_truthMatch;
 extern std::vector<float>				*mu_truthMinDR;
 extern std::vector<float>				*ph_pt;
 extern std::vector<float>				*ph_eta;
 extern std::vector<float>				*ph_phi;
 extern std::vector<float>				*ph_e;
 extern std::vector<float>				*ph_HoverE;
 extern std::vector<float>				*ph_sigmaIEIE;
 extern std::vector<float>				*ph_chIsoCorr;
 extern std::vector<float>				*ph_neuIsoCorr;
 extern std::vector<float>				*ph_phoIsoCorr;
 extern std::vector<bool>				*ph_isConv;
 extern std::vector<int>				*ph_conv_nTrk;
 extern std::vector<float>				*ph_conv_vtx_x;
 extern std::vector<float>				*ph_conv_vtx_y;
 extern std::vector<float>				*ph_conv_vtx_z;
 extern std::vector<float>				*ph_conv_ptin1;
 extern std::vector<float>				*ph_conv_ptin2;
 extern std::vector<float>				*ph_conv_ptout1;
 extern std::vector<float>				*ph_conv_ptout2;
 extern std::vector<bool>				*ph_passTight;
 extern std::vector<bool>				*ph_passMedium;
 extern std::vector<bool>				*ph_passLoose;
 extern Float_t				avgPU;
 extern Float_t				leadPhot_pt;
 extern Float_t				sublPhot_pt;
 extern Float_t				leadPhot_lepDR;
 extern Float_t				sublPhot_lepDR;
 extern Float_t				ph_phDR;
 extern Float_t				phPhot_lepDR;
 extern Float_t				leadPhot_lepDPhi;
 extern Float_t				sublPhot_lepDPhi;
 extern Float_t				ph_phDPhi;
 extern Float_t				phPhot_lepDPhi;
 extern Float_t				mt_lep_met;
 extern Float_t				mt_lepph1_met;
 extern Float_t				mt_lepph2_met;
 extern Float_t				mt_lepphph_met;
 extern Float_t				m_leplep;
 extern Float_t				m_lepph1;
 extern Float_t				m_lepph2;
 extern Float_t				m_lepphph;
 extern Float_t				m_phph;
};
#endif
