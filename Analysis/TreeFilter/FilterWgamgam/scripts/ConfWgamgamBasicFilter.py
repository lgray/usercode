from core import Filter

def get_remove_filter() :

    jet_filt = ['jetLowPt.*', 'jetMVAsExt', 'jetWPLevelsExt', 'jetBeta.*', 'jetMVAs']
    #vtx_filt = ['eleD0Vtx', 'eleDzVtx', 'phoPhiVtx', 'eleEtVtx', 'muD0Vtx', 'muDzVtx', 'phoEtaVtx', 'elePhiVtx', 'phoEtVtx', 'eleEtaVtx']
    vtx_filt = []

    return jet_filt+vtx_filt

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    jet_filt = Filter('FilterJet')
    jet_filt.cut_pt = '> 15'

    alg_list.append(jet_filt)
    #alg_list.append( Filter('FilterElec') )
    #alg_list.append(mu_filt)
