from core import Filter

def get_remove_filter() :

    #jet_filt = ['jetLowPt.*', 'jetMVAsExt', 'jetWPLevelsExt', 'jetBeta.*', 'jetMVAs']
    jet_filt = ['jetLowPt.*', 'jetMVAsExt', 'jetWPLevelsExt', 'jetBetaStarCMGExt', 'jetBetaStarClassicExt', 'phoEtaVtx', 'phoEtVtx', 'phoPhiVtx', 'mcEt', 'mcMass', 'convP4']
    #vtx_filt = ['eleD0Vtx', 'eleDzVtx', 'phoPhiVtx', 'eleEtVtx', 'muD0Vtx', 'muDzVtx', 'phoEtaVtx', 'elePhiVtx', 'phoEtVtx', 'eleEtaVtx']
    vtx_filt = []

    return jet_filt+vtx_filt

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    jet_filt = Filter('FilterJet')
    jet_filt.cut_pt = '> 15'
    alg_list.append(jet_filt)

    #ele_filt = Filter('FilterElec') 
    #ele_filt.cut_pt = '> 15'
    #alg_list.append(ele_filt)

    #mu_filt = Filter('FilterMuon') 
    #mu_filt.cut_pt = '> 15'
    #alg_list.append(mu_filt)
