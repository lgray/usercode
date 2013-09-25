from core import Filter

def get_remove_filter() :

    #jet_filt = ['jetLowPt.*', 'jetMVAsExt', 'jetWPLevelsExt', 'jetBeta.*', 'jetMVAs']
    jet_filt = ['jetLowPt.*', 'jetMVAsExt', 'jetWPLevelsExt', 'jetBetaStarCMGExt', 'jetBetaStarClassicExt', 'phoEtaVtx', 'phoEtVtx', 'phoPhiVtx', 'mcEt', 'mcMass', 'mcVtx', 'convP4']
    vtx_filt = ['eleD0Vtx', 'eleDzVtx', 'phoPhiVtx', 'eleEtVtx', 'muD0Vtx', 'muDzVtx', 'phoEtaVtx', 'elePhiVtx', 'phoEtVtx', 'eleEtaVtx']
    pho_filt = ['phoCiCTrkIsoDR04', 'phoCiCTrkIsoDR03', 'phoCiCPF4chgpfIso04', 'phoCiCPF4chgpfIso03', 'phoCiCPF4chgpfIso02']

    return jet_filt+vtx_filt+pho_filt

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    jet_filt = Filter('FilterJet')
    jet_filt.cut_pt = '> 15'
    alg_list.append(jet_filt)

    ele_filt = Filter('FilterElec') 
    ele_filt.cut_pt = '> 15'
    alg_list.append(ele_filt)

    mu_filt = Filter('FilterMuon') 
    mu_filt.cut_pt = '> 15'
    alg_list.append(mu_filt)

    evt_filt = Filter('FilterEvent')
    evt_filt.cut_nLep = '> 0'
    #evt_filt.cut_nPho = '> 0'

    alg_list.append(evt_filt)

    trig_filt = Filter('FilterTrigger')
    trig_filt.cut_trigger = '== 17 '
    alg_list.append(trig_filt)
