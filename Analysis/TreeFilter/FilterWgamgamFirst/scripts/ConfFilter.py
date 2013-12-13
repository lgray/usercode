from core import Filter

def get_remove_filter() :
    """ Define list of regex strings to filter input branches to remove from the output.
        Defining a non-empty list does not apply the filter, 
        you must also supply --enableRemoveFilter on the command line.
        If both filters are used, all branches in keep_filter are used
        except for those in remove_filter """

    jet_filt = [
                'jetMVAsExt_full',
                'jetBetaStarCMGExt',
                'jetBetaExt',
                'jetBetaStarClassicExt',
                'jetBetaStar',
                'jetMVAsExt_simple',
                'jetMVAs',
                'jetWPLevelsExt_simple',
                'jetWPLevelsExt_full',
                'jetWPLevelsExt_cutBased',
                'CA8.*',
               ]
    #vtx_filt = ['phoPhiVtx', 'phoEtaVtx', 'phoEtVtx', 'eleEtVtx', 'elePhiVtx', 'eleEtaVtx', 'muEtVtx', 'muPhiVtx', 'muEtaVtx']
    vtx_filt = []
    pho_filt = ['phoCiCTrkIsoDR04', 'phoCiCTrkIsoDR03', 'phoCiCPF4chgpfIso04', 'phoCiCPF4chgpfIso03', 'phoCiCPF4chgpfIso02']

    return jet_filt+vtx_filt+pho_filt

def get_keep_filter() :
    """ Define list of regex strings to filter input branches to retain in the output.  
        Defining a non-empty list does not apply the filter, 
        you must also supply --enableKeepFilter on the command line
        If both filters are used, all branches in keep_filter are used
        except for those in remove_filter """

    return []

def config_analysis( alg_list, args ) :
    """ Configure analysis modules. Order is preserved """

    jet_filt = Filter('FilterJet')
    jet_filt.cut_pt = '> 15'
    alg_list.append(jet_filt)

    #ele_filt = Filter('FilterElec') 
    #ele_filt.cut_pt = '> 10'
    #alg_list.append(ele_filt)

    #mu_filt = Filter('FilterMuon') 
    #mu_filt.cut_pt = '> 10'
    #alg_list.append(mu_filt)

    evt_filt = Filter('FilterEvent')
    evt_filt.cut_nLep = '> 0'
    ##evt_filt.cut_nPho = '> 0'

    #alg_list.append(evt_filt)

    trig_filt = Filter('FilterTrigger')
    trig_filt.cut_trigger = '==1 | ==17 | == 18 | == 19' #diphoton | electron | muon
    #trig_filt.cut_trigger = '== 18 | == 19' #muon
    #trig_filt.cut_trigger = '==17' #electron
    alg_list.append(trig_filt)
