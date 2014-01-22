from core import Filter

def get_remove_filter() :
    """ Define list of regex strings to filter input branches to remove from the output.
        Defining a non-empty list does not apply the filter, 
        you must also supply --enableRemoveFilter on the command line.
        If both filters are used, all branches in keep_filter are used
        except for those in remove_filter """

    return []

def get_keep_filter() :
    """ Define list of regex strings to filter input branches to retain in the output.  
        Defining a non-empty list does not apply the filter, 
        you must also supply --enableKeepFilter on the command line
        If both filters are used, all branches in keep_filter are used
        except for those in remove_filter """

    return ['el_n', 'mu_n', 'ph_n', 'jet_n', 'el_pt', 'el_eta', 'el_phi', 'el_e', 'mu_pt', 'mu_eta', 'mu_phi', 'mu_e', 'ph_pt', 'ph_eta', 'ph_phi', 'ph_e']

def config_analysis( alg_list, args ) :
    """ Configure analysis modules. Order is preserved """

    # lepton and photon filters must be run 
    # before the jet filter
    alg_list.append( get_muon_filter( ) )
    alg_list.append( get_electron_filter( 'medium' ) )
    #alg_list.append( get_electron_filter( 'tightTrig' ) )
    alg_list.append( get_photon_filter( 'medium' ) )
    alg_list.append( get_jet_filter(do_hists=False) )
    
    filter_event = Filter('FilterEvent')
    for cut, val in args.iteritems() :
        setattr(filter_event, cut, val)

    alg_list.append( filter_event )

    alg_list.append( Filter( 'CalcEventVars' ) )
    

def get_jet_filter( do_hists = False ) :

    filt = Filter ( 'FilterJet' ) 

    # redo overlap rm with photons and muons
    filt.cut_jet_ele_dr = ' > 0.4 '
    filt.cut_jet_ph_dr = ' > 0.4 '
    filt.cut_jet_mu_dr = ' > 0.4 '

    filt.do_cutflow = False

    if do_hists :
        filt.add_hist('cut_jet_ele_dr', 50, 0, 5)
        filt.add_hist('cut_jet_ph_dr', 50, 0, 5)
        filt.add_hist('cut_jet_mu_dr', 50, 0, 5)

    return filt

def get_electron_filter ( id ) :

    filt = Filter( 'FilterElectron' )
    filt.cut_el_pt = ' > 25' 
    setattr( filt, 'cut_el_%s' %id, 'True' )

    return filt

def get_photon_filter ( id ) :

    filt = Filter( 'FilterPhoton' )
    filt.cut_ph_pt = ' > 15 '
    #filt.cut_ph_eleVeto = ' == False'
    filt.cut_el_ph_dr = ' > 0.2 '
    #setattr( filt, 'cut_ph_%s' %id, 'True' )

    return filt


def get_muon_filter( ) :

    filt = Filter( 'FilterMuon' )
    filt.cut_mu_pt = ' > 25 '
    
    return filt
