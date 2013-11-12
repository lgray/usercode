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

    return []

def config_analysis( alg_list ) :
    """ Configure analysis modules. Order is preserved """

    alg_list.append( Filter('CalcEventVars') )

    alg_list.append( add_Z_event_weight() )

def add_Z_event_weight() :

    filt = Filter('AddEventWeight')

    filt.add_var( 'root_file', '/afs/cern.ch/user/j/jkunkle/usercode/Analysis/TreeFilter/UpdateFinalTree/data/EFakeGammaScaleFactorPt.root' )
    filt.add_var( 'hist_name', 'pt')
    file.add_var( 'sample_key', 'DYJetsToLL' )

    return filt
