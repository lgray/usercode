from core import Filter
from ConfWgamgamReco import build_electron, build_muon, build_photon

def get_remove_filter() :

    return ['.*']

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    #alg_list.append( build_electron( do_cutflow=False, do_hists=False ) )
    #alg_list.append( build_muon( do_cutflow=True, do_hists=True) )

    alg_list.append( build_photon( do_cutflow=True, do_hists=True, filtPID='medium') )
    #alg_list.append( build_jet( do_cutflow=False, do_hists=False ) )

    # do this later, after PID has been applied
    #alg_list.append( Filter('BuildEvent'   ) )


