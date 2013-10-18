
#************************************************************************************
#
# filter.py
#
# Author : Josh Kunkle  (jkunkle@cern.ch)
#

import sys
import os
import re
import math
import subprocess
import multiprocessing
import inspect
import ROOT

import core

options = core.ParseArgs()

#*************************************
#Some global definitions
#*************************************

workarea = os.getenv('WorkArea')
if workarea is None :
    print 'Did not locate WorkArea environment variable.  Please set it to the root of the package'
    sys.exit(-1)

def_file_name = workarea    + '/TreeFilter/FilterTruthWgamgam/FilterTruthWgamgam/BranchDefs.h'
header_file_name = workarea + '/TreeFilter/FilterTruthWgamgam/FilterTruthWgamgam/BranchInit.h'
source_file_name = workarea + '/TreeFilter/FilterTruthWgamgam/src/BranchInit.cxx'

def main(**kwargs) :

    assert options.files is not None or options.filesDir is not None , 'Must provide a file list via --files or a search directory via --filesDir'
    assert options.outputDir is not None, 'Must provide an output directory via --outputDir'
    assert options.treeName is not None, 'Must provide a tree name via --treeName'

    input_files = []
    if options.files is not None :
        input_files = options.files.split(',')
    elif options.filesDir is not None :
        input_files = core.collect_input_files( options.filesDir, options.fileKey )

    # if output file name is not given grab the name from one of the input files
    if options.outputFile is None :
        options.outputFile = input_files[0].split('/')[-1]

    testfile = ROOT.TFile.Open( input_files[0] )
    testtree = testfile.Get( options.treeName )

    branches = core.get_branch_mapping(testtree)

    ImportedModule = core.import_module( options.module )

    branches_to_keep = core.get_keep_branches( ImportedModule, branches, 
                                               options.enableKeepFilter, 
                                               options.enableRemoveFilter )

    if options.enableKeepFilter :
        print 'Will keep %d branches from output file : ' %len(branches_to_keep)
        print '\n'.join(branches_to_keep)
    elif options.enableRemoveFilter :
        print 'Will remove %d branches from output file : ' %( len(branches) - len(branches_to_keep))
        print '\n'.join( list( set( [ br['name'] for br in branches ] ) - set( branches_to_keep ) ) )

    if not options.noCompile :

        # Write the c++ files having the branch definitions and 
        # SetBranchAddress calls
        core.write_branchdef_file(def_file_name, branches, branches_to_keep )

        core.write_source_file(source_file_name, header_file_name, branches, branches_to_keep )

        # compile
        proc = subprocess.Popen(['make'])
        retcode = proc.wait()
        
        # abort if non-zero return code
        if retcode :
            print 'Compilation failed.  Will not run'
            return

    # Stop here if not running
    if options.noRun :
        return

    # Get the path of the executable.  First try the
    # WorkArea environment variable which will give
    # an absolute path.  If that doesn't exist, try
    # Using the path of this script to get an
    # absolute path
    exe_path = None

    if workarea is not None :
        exe_path = '%s/TreeFilter/FilterTruthWgamgam/RunAnalysis' %workarea

    if exe_path is None :
        print ('Did not find executable through the WorkArea environment variable. '
               'Next try using the absolute path of this script' )

        script_loc = os.path.realpath(__file__)
        exe_path = '%s/../RunAnalysis' %os.path.dirname(script_loc)

    if not os.path.isfile(exe_path) :
        print ('ERROR - cannot locate path of executable file.  The path '
               'was determined from the path of this script.  Either set the '
               'WorkArea environment variable to the directory where HWWAnalysisCode '
               'resides, or keep this script in the same location as the executable' )
        sys.exit(-1)

    run_commands = []

    alg_list = []
    ImportedModule.config_analysis(alg_list)

    # --------------------------
    # Handle file splitting.
    # Be default nsplit = 1.  In this case the default 
    # behavior is only one job running over all
    # events
    # --------------------------

    file_evt_list = core.get_file_evt_map( input_files, options.nsplit, options.treeName )

    if options.nproc > 1 : #multiprocessing!

        if options.nproc > len(file_evt_list) :
            options.nproc = len(file_evt_list)

        commands = core.generate_multiprocessing_commands( file_evt_list, alg_list, exe_path, options )

        print 'Will run a total of %d processes, %d at a time' %(len(commands), options.nproc)

        pool = multiprocessing.Pool(options.nproc)
        cmds_with_echo = ['echo "%s" ; %s' %(x,x) for x in commands ]
        pool.map( os.system, cmds_with_echo )

    else :

        output_file = '%s/%s' %(options.outputDir, options.outputFile )
        if not os.path.isdir( options.outputDir ) and options.outputDir.count('root://') != -1 :
            os.makedirs( options.outputDir )
        core.write_config( alg_list, options.confFileName, options.treeName, options.outputDir, options.outputFile, file_evt_list, options.storagePath ) 
        command = core.make_exe_command( exe_path, options.confFileName )

        print command
        os.system(command)


if __name__ == '__main__' :
    main()
