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
 std::vector<float>				*jet_pt;
 std::vector<float>				*jet_eta;
 std::vector<float>				*jet_phi;
 std::vector<float>				*jet_e;
 Float_t				avgPU;
 Bool_t				isBlinded;
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
};
namespace OUT {
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
  tree->SetBranchAddress("jet_pt", &IN::jet_pt);
  tree->SetBranchAddress("jet_eta", &IN::jet_eta);
  tree->SetBranchAddress("jet_phi", &IN::jet_phi);
  tree->SetBranchAddress("jet_e", &IN::jet_e);
  tree->SetBranchAddress("avgPU", &IN::avgPU);
  tree->SetBranchAddress("isBlinded", &IN::isBlinded);
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
};

void InitOUTTree( TTree * tree ) {
}
void CopyInputVarsToOutput( std::string prefix) {
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

}; 

void CopyPrefixIndexBranchesInToOut( const std::string & prefix, unsigned index ) { 

// Just call each copy function with the prefix 

}; 

void ClearOutputPrefix ( const std::string & prefix ) {
}; 

