from core import Filter

def get_remove_filter() :

    return ['.*']

def get_keep_filter() :

    return ['pfMET.*', 'recoPfMET.*', 'nVtxBS']

def config_analysis( alg_list ) :

    alg_list.append( build_electron( do_cutflow=True, do_hists=True, evalPID='medium' ) )
    alg_list.append( build_muon( do_cutflow=True, do_hists=True) )

    ## filter out a lepton 
    #filter_evt = Filter( 'FilterEvent' )
    #filter_evt.cut_mu_n = ' > 0 '
    #alg_list.append(filter_evt)

    alg_list.append( build_photon( do_cutflow=True, do_hists=True, evalPID='medium') )
    alg_list.append( build_jet( do_cutflow=True, do_hists=True ) )

    # do this later, after PID has been applied
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

def build_electron( do_cutflow=False, do_hists=False, filtPID=None, evalPID=None ) :

    filt = Filter('BuildElectron')

    filt.do_cutflow = do_cutflow

    filt.cut_pt = ' > 25'
    filt.cut_abssceta       = ' <2.5 '
    # no crack for now
    #filt.cut_abssceta_crack = ' > 1.44 & < 1.57 '
    #filt.invert('cut_abssceta_crack')

    filt.cut_absdEtaIn_barrel_tight       = ' < 0.004 '
    filt.cut_absdPhiIn_barrel_tight       = ' < 0.03 '
    filt.cut_sigmaIEIE_barrel_tight       = ' < 0.01 '
    filt.cut_hovere_barrel_tight          = ' < 0.12 '
    filt.cut_d0_barrel_tight              = ' < 0.02 '
    filt.cut_z0_barrel_tight              = ' < 0.1 '
    filt.cut_eoverp_barrel_tight          = ' < 0.05 '
    filt.cut_pfIso30_barrel_tight         = ' < 0.1 '
    filt.cut_convfit_barrel_tight         = ' < 0.000001 '
    filt.cut_misshits_barrel_tight        = ' == 0 '

    filt.cut_absdEtaIn_barrel_medium      = ' < 0.004 '
    filt.cut_absdPhiIn_barrel_medium      = ' < 0.06 '
    filt.cut_sigmaIEIE_barrel_medium      = ' < 0.01 '
    filt.cut_hovere_barrel_medium         = ' < 0.12 '
    filt.cut_d0_barrel_medium             = ' < 0.02 '
    filt.cut_z0_barrel_medium             = ' < 0.1 '
    filt.cut_eoverp_barrel_medium         = ' < 0.05 '
    filt.cut_pfIso30_barrel_medium        = ' < 0.15 '
    filt.cut_convfit_barrel_medium        = ' < 0.000001 '
    filt.cut_misshits_barrel_medium       = ' <= 1 '

    filt.cut_absdEtaIn_barrel_loose       = ' < 0.007 '
    filt.cut_absdPhiIn_barrel_loose       = ' < 0.15 '
    filt.cut_sigmaIEIE_barrel_loose       = ' < 0.01 '
    filt.cut_hovere_barrel_loose          = ' < 0.12 '
    filt.cut_d0_barrel_loose              = ' < 0.02 '
    filt.cut_z0_barrel_loose              = ' < 0.2 '
    filt.cut_eoverp_barrel_loose          = ' < 0.05 '
    filt.cut_pfIso30_barrel_loose         = ' < 0.15 '
    filt.cut_convfit_barrel_loose         = ' < 0.000001 '
    filt.cut_misshits_barrel_loose        = ' <= 1 '

    filt.cut_absdEtaIn_barrel_veryloose   = ' < 0.007 '
    filt.cut_absdPhiIn_barrel_veryloose   = ' < 0.8 '
    filt.cut_sigmaIEIE_barrel_veryloose   = ' < 0.01 '
    filt.cut_hovere_barrel_veryloose      = ' < 0.15 '
    filt.cut_d0_barrel_veryloose          = ' < 0.04 '
    filt.cut_z0_barrel_veryloose          = ' < 0.2 '
    #filt.cut_eoverp_barrel_veryloose     = ' < 0.05 ' #no cut
    filt.cut_pfIso30_barrel_veryloose     = ' < 0.1 '
    #filt.cut_convfit_barrel_veryloose    = ' < 0.000001 ' #no cut
    #filt.cut_misshits_barrel_veryloose   = ' == 0 ' #no cut

    filt.cut_absdEtaIn_barrel_tightTrig   = ' < 0.007 '
    filt.cut_absdPhiIn_barrel_tightTrig   = ' < 0.15 '
    filt.cut_sigmaIEIE_barrel_tightTrig   = ' < 0.01 '
    filt.cut_hovere_barrel_tightTrig      = ' < 0.12 '
    filt.cut_ecalIso30_barrel_tightTrig   = ' < 0.2 '
    filt.cut_hcalIso30_barrel_tightTrig   = ' < 0.2 '
    filt.cut_trkIso30_barrel_tightTrig    = ' < 0.2 '

    filt.cut_absdEtaIn_endcap_tight       = ' < 0.005 '
    filt.cut_absdPhiIn_endcap_tight       = ' < 0.02 '
    filt.cut_sigmaIEIE_endcap_tight       = ' < 0.03 '
    filt.cut_hovere_endcap_tight          = ' < 0.1 '
    filt.cut_d0_endcap_tight              = ' < 0.02 '
    filt.cut_z0_endcap_tight              = ' < 0.1 '
    filt.cut_eoverp_endcap_tight          = ' < 0.05 '
    filt.cut_pfIso30_endcap_lowPt_tight   = ' < 0.1 '
    filt.cut_pfIso30_endcap_highPt_tight  = ' < 0.15 '
    filt.cut_convfit_endcap_tight         = ' < 0.000001 '
    filt.cut_misshits_endcap_tight        = ' == 0 '

    filt.cut_absdEtaIn_endcap_medium      = ' < 0.007 '
    filt.cut_absdPhiIn_endcap_medium      = ' < 0.03 '
    filt.cut_sigmaIEIE_endcap_medium      = ' < 0.03 '
    filt.cut_hovere_endcap_medium         = ' < 0.1 '
    filt.cut_d0_endcap_medium             = ' < 0.02 '
    filt.cut_z0_endcap_medium             = ' < 0.1 '
    filt.cut_eoverp_endcap_medium         = ' < 0.05 '
    filt.cut_pfIso30_endcap_lowPt_medium  = ' < 0.1 '
    filt.cut_pfIso30_endcap_highPt_medium = ' < 0.15 '
    filt.cut_convfit_endcap_medium        = ' < 0.000001 '
    filt.cut_misshits_endcap_medium       = ' <= 1 '

    filt.cut_absdEtaIn_endcap_loose       = ' < 0.009 '
    filt.cut_absdPhiIn_endcap_loose       = ' < 0.1 '
    filt.cut_sigmaIEIE_endcap_loose       = ' < 0.03 '
    filt.cut_hovere_endcap_loose          = ' < 0.1 '
    filt.cut_d0_endcap_loose              = ' < 0.02 '
    filt.cut_z0_endcap_loose              = ' < 0.2 '
    filt.cut_eoverp_endcap_loose          = ' < 0.05 '
    filt.cut_pfIso30_endcap_lowPt_loose   = ' < 0.10 '
    filt.cut_pfIso30_endcap_highPt_loose  = ' < 0.15 '
    filt.cut_convfit_endcap_loose         = ' < 0.000001 '
    filt.cut_misshits_endcap_loose        = ' <= 1 '

    filt.cut_absdEtaIn_endcap_veryloose   = ' < 0.01 '
    filt.cut_absdPhiIn_endcap_veryloose   = ' < 0.7 '
    filt.cut_sigmaIEIE_endcap_veryloose   = ' < 0.03 '
    #filt.cut_hovere_endcap_veryloose      = ' < 0.15 ' #no cut
    filt.cut_d0_endcap_veryloose          = ' < 0.04 '
    filt.cut_z0_endcap_veryloose          = ' < 0.2 '
    #filt.cut_eoverp_endcap_veryloose     = ' < 0.05 ' #no cut
    filt.cut_pfIso30_endcap_veryloose     = ' < 0.15 '
    #filt.cut_convfit_endcap_veryloose    = ' < 0.000001 ' #no cut
    #filt.cut_misshits_endcap_veryloose   = ' == 0 ' #no cut

    filt.cut_absdEtaIn_endcap_tightTrig   = ' < 0.009 '
    filt.cut_absdPhiIn_endcap_tightTrig   = ' < 0.10 '
    filt.cut_sigmaIEIE_endcap_tightTrig   = ' < 0.03 '
    filt.cut_hovere_endcap_tightTrig      = ' < 0.1 '
    filt.cut_ecalIso30_endcap_tightTrig   = ' < 0.2 '
    filt.cut_hcalIso30_endcap_tightTrig   = ' < 0.2 '
    filt.cut_trkIso30_endcap_tightTrig    = ' < 0.2 '

    if filtPID is not None :
        setattr(filt, 'cut_pid_%s' %filtPID, ' == True' )

    if evalPID is not None :
        filt.add_var( 'evalPID', evalPID )

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )
        filt.add_hist( 'cut_abseta_crack', 50, 0, 5 )
        filt.add_hist( 'cut_absdEtaIn_barrel_tight', 100, -0.1, 0.1 )
        filt.add_hist( 'cut_absdPhiIn_barrel_tight', 100, -0.1, 0.1 )
        filt.add_hist( 'cut_sigmaIEIE_barrel_tight', 100, 0, 0.05 )
        filt.add_hist( 'cut_hovere_barrel_tight', 100, -1, 1 )
        filt.add_hist( 'cut_d0_barrel_tight', 100, -1, 1 )
        filt.add_hist( 'cut_z0_barrel_tight', 100, -1, 1 )
        filt.add_hist( 'cut_eoverp_barrel_tight', 100, 0, 1 )
        filt.add_hist( 'cut_pfIso30_barrel_tight', 100, 0, 10 )
        filt.add_hist( 'cut_convfit_barrel_tight', 2, 0, 2 )
        filt.add_hist( 'cut_misshits_barrel_tight', 10, 0, 10 )

    return filt

def build_photon( do_cutflow=False, do_hists=False, filtPID=None, evalPID=None ) :

    filt = Filter('BuildPhoton')

    filt.do_cutflow = do_cutflow

    filt.cut_pt           = ' > 15 '
    filt.cut_abseta       = ' < 2.5'
    filt.cut_abseta_crack = ' > 1.479 & < 1.566 '
    filt.invert('cut_abseta_crack')

    filt.cut_emfrac       = ' < 0.05'
    filt.cut_eveto        = ' == False'

    filt.cut_sigmaIEIE_barrel_loose  = ' < 0.012 '
    filt.cut_chIsoCorr_barrel_loose  = ' < 2.6 '
    filt.cut_neuIsoCorr_barrel_loose = ' < 3.5 '
    filt.cut_phoIsoCorr_barrel_loose = ' < 1.3 '

    filt.cut_sigmaIEIE_endcap_loose  = ' < 0.034 '
    filt.cut_chIsoCorr_endcap_loose  = ' < 2.3 '
    filt.cut_neuIsoCorr_endcap_loose = ' < 2.9 '
    # no cut for loose
    #filt.cut_phoIsoCorr_endcap_loose = ' < 1.0 '

    filt.cut_sigmaIEIE_barrel_medium  = ' < 0.011 '
    filt.cut_chIsoCorr_barrel_medium  = ' < 1.5 '
    filt.cut_neuIsoCorr_barrel_medium = ' < 1.0 '
    filt.cut_phoIsoCorr_barrel_medium = ' < 0.7 '

    filt.cut_sigmaIEIE_endcap_medium  = ' < 0.033 '
    filt.cut_chIsoCorr_endcap_medium  = ' < 1.2 '
    filt.cut_neuIsoCorr_endcap_medium = ' < 1.5 '
    filt.cut_phoIsoCorr_endcap_medium = ' < 1.0 '

    filt.cut_sigmaIEIE_barrel_tight  = ' < 0.011 '
    filt.cut_chIsoCorr_barrel_tight  = ' < 0.7 '
    filt.cut_neuIsoCorr_barrel_tight = ' < 0.4 '
    filt.cut_phoIsoCorr_barrel_tight = ' < 0.5 '

    filt.cut_sigmaIEIE_endcap_tight  = ' < 0.031 '
    filt.cut_chIsoCorr_endcap_tight  = ' < 0.5 '
    filt.cut_neuIsoCorr_endcap_tight = ' < 1.5 '
    filt.cut_phoIsoCorr_endcap_tight = ' < 1.0 '

    if filtPID is not None :
        setattr(filt, 'cut_pid_%s' %filtPID, ' == True' )

    if evalPID is not None :
        filt.add_var( 'evalPID', evalPID )

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )
        filt.add_hist( 'cut_abseta_crack', 50, 0, 5 )
        filt.add_hist( 'cut_emfrac', 50, 0, 0.1 )
        filt.add_hist( 'cut_eveto', 2, 0, 2 )
        filt.add_hist( 'cut_sigmaIEIE_barrel_medium', 50, 0, 0.05 )
        filt.add_hist( 'cut_chIsoCorr_barrel_medium', 50, 0, 5 )
        filt.add_hist( 'cut_neuIsoCorr_barrel_medium', 50, 0, 5 )
        filt.add_hist( 'cut_phoIsoCorr_barrel_medium', 50, 0, 5 )
        filt.add_hist( 'cut_sigmaIEIE_endcap_medium', 50, 0, 0.05 )
        filt.add_hist( 'cut_chIsoCorr_endcap_medium', 50, 0, 5 )
        filt.add_hist( 'cut_neuIsoCorr_endcap_medium', 50, 0, 5 )
        filt.add_hist( 'cut_phoIsoCorr_endcap_medium', 50, 0, 5 )

    return filt

def build_jet( do_cutflow=False, do_hists=False ) :

    filt = Filter('BuildJet')
    filt.do_cutflow = do_cutflow

    filt.cut_pt = ' > 30 '
    filt.cut_abseta = ' < 4.5 '

    if do_hists :
        filt.add_hist( 'cut_pt', 100, 0, 500 )
        filt.add_hist( 'cut_abseta', 50, 0, 5 )

    return filt
