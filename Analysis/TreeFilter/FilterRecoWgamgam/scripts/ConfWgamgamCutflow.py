from core import Filter

def get_remove_filter() :

    return ['.*']

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    alg_list.append( build_electron( do_cutflow=True, do_hists=True ) )
    alg_list.append( build_muon( do_cutflow=True, do_hists=True ) )
    alg_list.append( build_photon( do_cutflow=True, do_hists=True ) )

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

    filt.cut_isGlobal   = ' == True '
    filt.cut_isPF       = ' == True '
    filt.cut_pt         = ' > 25 '
    filt.cut_abseta     = ' < 2.5'
    filt.cut_chi2       = ' < 10'
    filt.cut_nTrkLayers = ' > 8 ' 
    filt.cut_nStations  = ' > 1'
    filt.cut_nPixelHits = ' > 0'
    filt.cut_d0         = ' < 0.2'
    filt.cut_z0         = ' < 0.5'
    #filt.cut_trkiso     = ' < 0.1 '
    filt.cut_corriso    = ' < 0.2'

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )
        filt.add_hist( 'cut_chi2', 50, 0, 50 )
        filt.add_hist( 'cut_nTrkLayers', 20, 0, 20 )
        filt.add_hist( 'cut_nStations', 5, 0, 5 )
        filt.add_hist( 'cut_nPixelHits', 20, 0, 20 )
        filt.add_hist( 'cut_d0', 100, -0.05, 0.05 )
        filt.add_hist( 'cut_z0', 100, -0.05, 0.05 )
        filt.add_hist( 'cut_trkiso', 50, 0, 0.5 )
        filt.add_hist( 'cut_corriso', 50, 0, 0.5 )

    return filt

def build_photon( do_cutflow=False, do_hists=False ) :

    filt = Filter('BuildPhoton')

    filt.do_cutflow = do_cutflow

    filt.cut_pt           = ' > 25 '
    filt.cut_abseta       = ' < 2.5'
    filt.cut_abseta_crack = ' > 1.479 & < 1.566 '
    filt.invert('cut_abseta_crack')
    filt.cut_emfrac       = ' < 0.05'
    filt.cut_eveto        = ' == True'
    filt.cut_sigmaIEIE_barrel = ' < 0.011 '
    filt.cut_chIsoCorr_barrel = ' < 1.5 '
    filt.cut_neuIsoCorr_barrel = ' < 1.0 '
    filt.cut_phoIsoCorr_barrel = ' < 0.7 '
    filt.cut_sigmaIEIE_endcap = ' < 0.033 '
    filt.cut_chIsoCorr_endcap = ' < 1.2 '
    filt.cut_neuIsoCorr_endcap = ' < 1.5 '
    filt.cut_phoIsoCorr_endcap = ' < 1.0 '

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )
        filt.add_hist( 'cut_abseta_crack', 50, 0, 5 )
        filt.add_hist( 'cut_emfrac', 50, 0, 0.1 )
        filt.add_hist( 'cut_eveto', 2, 0, 2 )
        filt.add_hist( 'cut_sigmaIEIE_barrel', 50, 0, 0.05 )
        filt.add_hist( 'cut_chIsoCorr_barrel', 50, 0, 5 )
        filt.add_hist( 'cut_neuIsoCorr_barrel', 50, 0, 5 )
        filt.add_hist( 'cut_phoIsoCorr_barrel', 50, 0, 5 )

    return filt

def build_electron( do_cutflow=False, do_hists=False ) :

    filt = Filter('BuildMediumElectron')

    filt.do_cutflow = do_cutflow

    filt.cut_pt = ' > 25'
    #filt.cut_abseta       = ' <2.5 '
    #filt.cut_abseta_crack = ' > 1.44 & < 1.57 '
    #filt.invert('cut_abseta_crack')
    filt.cut_abssceta       = ' >= 1.479 & < 2.5'

    filt.cut_dEtaIn_barrel    = ' < 0.004 '
    filt.cut_dPhiIn_barrel    = ' < 0.06 '
    filt.cut_sigmaIEIE_barrel = ' < 0.01 '
    filt.cut_hovere_barrel    = ' < 0.12 '
    filt.cut_d0_barrel        = ' < 0.02 '
    filt.cut_z0_barrel        = ' < 0.1 '
    filt.cut_eoverp_barrel    = ' < 0.05 '
    filt.cut_pfIso30_barrel   = ' < 0.15 '
    filt.cut_convfit_barrel   = ' < 0.000001 '
    filt.cut_misshits_barrel  = ' <= 1 '

    filt.cut_dEtaIn_endcap    = ' < 0.007 '
    filt.cut_dPhiIn_endcap    = ' < 0.03 '
    filt.cut_sigmaIEIE_endcap = ' < 0.03 '
    filt.cut_hovere_endcap    = ' < 0.10 '
    filt.cut_d0_endcap        = ' < 0.02 '
    filt.cut_z0_endcap        = ' < 0.1 '
    filt.cut_eoverp_endcap    = ' < 0.05 '
    filt.cut_pfIso30_endcap   = ' < 0.15 '
    filt.cut_convfit_endcap   = ' < 0.000001 '
    filt.cut_misshits_endcap  = ' <= 1 '

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )
        filt.add_hist( 'cut_abseta_crack', 50, 0, 5 )
        filt.add_hist( 'cut_abssceta', 50, 0, 5 )
        filt.add_hist( 'cut_dEtaIn_barrel', 100, -0.1, 0.1 )
        filt.add_hist( 'cut_dPhiIn_barrel', 100, -0.1, 0.1 )
        filt.add_hist( 'cut_sigmaIEIE_barrel', 100, 0, 0.05 )
        filt.add_hist( 'cut_hovere_barrel', 100, -1, 1 )
        filt.add_hist( 'cut_d0_barrel', 100, -1, 1 )
        filt.add_hist( 'cut_z0_barrel', 100, -1, 1 )
        filt.add_hist( 'cut_eoverp_barrel', 100, 0, 1 )
        filt.add_hist( 'cut_pfIso30_barrel', 100, 0, 10 )
        filt.add_hist( 'cut_convfit_barrel', 2, 0, 2 )
        filt.add_hist( 'cut_misshits_barrel', 10, 0, 10 )

    return filt
