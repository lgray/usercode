from core import Filter

def get_remove_filter() :

    return ['.*']

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    alg_list.append( build_electron( elepid='tight', do_cutflow=True, do_hists=True ) )
    alg_list.append( build_muon( do_cutflow=True, do_hists=True ) )

    ##build_lep.cut_pt = '> 25'
    ##build_lep.cut_abseta = '< 2.5'

    #alg_list.append( build_lep )

    #build_phot = Filter( 'BuildPhoton' )
    ##build_phot.cut_pt  = ' > 15'
    ##build_phot.cut_abseta = ' < 2.5'

    #alg_list.append( build_phot )

    #alg_list.append( Filter('BuildNeutrino') )
    #alg_list.append( Filter('BuildWboson') )

    #alg_list.append( Filter('BuildEvent'   ) )

def build_muon( do_cutflow=False, do_hists=False ) :

    filt = Filter('BuildMuon')

    filt.do_cutflow = do_cutflow

    filt.cut_pt = ' > 25 '
    filt.cut_abseta = ' < 2.5'

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )

    return filt

def build_electron( elepid, do_cutflow=False, do_hists=False ) :

    filt = Filter('BuildElectron')

    filt.do_cutflow = do_cutflow

    filt.cut_pt = ' > 25'
    filt.cut_abseta       = ' <2.5 '
    filt.cut_abseta_crack = ' > 1.44, < 1.57 '
    filt.invert('cut_abseta_crack')

    filt.cut_dEtaIn_barrel    = ' < 0.004 '
    filt.cut_dPhiIn_barrel    = ' < 0.03 '
    filt.cut_sigmaIEIE_barrel = ' < 0.01 '
    filt.cut_emfrac_barrel    = ' < 0.12 '
    filt.cut_d0_barrel        = ' < 0.02 '
    filt.cut_z0_barrel        = ' < 0.1 '
    filt.cut_eoverp_barrel    = ' < 0.1 '
    filt.cut_ecalIso30_barrel = ' < 0.1 '
    filt.cut_convfit_barrel   = ' < 0.000001 '
    filt.cut_misshits_barrel  = ' == 0 '

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )
        filt.add_hist( 'cut_dEtaIn_barrel', 100, -0.1, 0.1 )
        filt.add_hist( 'cut_dPhiIn_barrel', 100, -0.1, 0.1 )
        filt.add_hist( 'cut_sigmaIEIE_barrel', 100, 0, 0.05 )
        filt.add_hist( 'cut_emfrac_barrel', 100, -1, 1 )
        filt.add_hist( 'cut_d0_barrel', 100, -1, 1 )
        filt.add_hist( 'cut_z0_barrel', 100, -1, 1 )
        filt.add_hist( 'cut_eoverp_barrel', 100, 0, 1 )
        filt.add_hist( 'cut_ecalIso30_barrel', 100, 0, 10 )
        filt.add_hist( 'cut_convfit_barrel', 2, 0, 2 )
        filt.add_hist( 'cut_misshits_barrel', 10, 0, 10 )

    return filt
