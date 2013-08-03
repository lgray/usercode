
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
from array import array
from argparse import ArgumentParser

parser = ArgumentParser(description='')

parser.add_argument('--files', dest='files', default=None, help='<Required> list of input files (comma separated)')

parser.add_argument('--output', dest='output', default=None, help='<Required> Output sample path')

parser.add_argument('--treeName', dest='treeName', default=None, help='<Required> name of tree to process')

parser.add_argument('--confFileName', dest='confFileName', default='analysis_config.txt', help='Name of the configuration file.  Default : analysis_config.txt')

parser.add_argument('--nproc', dest='nproc', type=int, default=1, help='Number of processors to use.  If set to > 1, use multiprocessing')

parser.add_argument('--noRun', dest='noRun', default=False, action='store_true', help='Just generate and compile, do not run the merging')

parser.add_argument('--noCompile', dest='noCompile', default=False, action='store_true', help='Just run the merging.  Do not recompile')

parser.add_argument('--enableFilter', dest='enableFilter', default=False, action='store_true', help='Do not write out branches in _filter_regex list')


options = parser.parse_args()

#*************************************
#Some global definitions
#*************************************

workarea = os.getenv('WorkArea')
header_file_name = workarea + '/FilterWgamgam/BranchDefs.h'
source_file_name = workarea + '/FilterWgamgam/BranchInit.icc'

_filter_regex = [ 'jet_AntiKt4TruthJets.*', 'el_*', 'mcevt_*', 'mu_staco_*']

def main(**kwargs) :

    assert options.files is not None, 'Must provide a file list via --files'
    assert options.output is not None, 'Must provide an output name via --output'
    assert options.treeName is not None, 'Must provide a tree name via --treeName'

    input_files = options.files.split(',')

    testfile = ROOT.TFile.Open( input_files[0] )
    testtree = testfile.Get( options.treeName )

    branches = get_branch_mapping(testtree)

    if not options.noCompile :
        # get list of branches to remove if requested
        branches_to_remove = []
        if options.enableFilter :
            for br in branches.keys() :
                reslist = [ re.match( filtre, br ) for filtre in _filter_regex ]
                filtlist = filter( lambda x : x is not None, reslist )
                if filtlist :
                    branches_to_remove.append(br)

        print 'Will remove %d branches from output file : ' %len(branches_to_remove)
        print '\n'.join(branches_to_remove)

        # Write the c++ files having the branch definitions and 
        # SetBranchAddress calls
        write_header_file(header_file_name, branches,branches_to_remove )

        write_source_file(source_file_name, branches,branches_to_remove )

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
    rootcore = os.getenv('WorkArea')
    if rootcore is not None :
        exe_path = '%s/../TruthNtupAnalysis/bin/process' %rootcore

    if exe_path is None :
        print ('Did not find executable through the WorkArea environment variable. '
               'Next try using the absolute path of this script' )

        script_loc = os.path.realpath(__file__)
        exe_path = '%s/../RunAnalysis' %os.path.dirname(script_loc)

    if not os.path.isfile(exe_path) :
        print ('ERROR - cannot locate path of executable file.  The path '
               'was determined from the path of this script.  Either set the '
               'TestArea environment variable to the directory where HWWAnalysisCode '
               'resides, or keep this script in the same location as the executable' )
        sys.exit(-1)

    run_commands = []

    alg_list = []
    config_analysis( alg_list )

    write_config( alg_list, options.confFileName )

    command = make_exe_command( exe_path, options.confFileName )

    print command

    os.system(command)

def config_analysis( alg_list  ) :

    elecFilt = ObjectFilter()
    elecFilt.cut_pt = "> 30"
    elecFilt.cut_eta = "> -2.5,< 2.5"
    elecFilt.invert('cut_eta')
    elecFilt.cut_isTight = "True"

    alg_list.append(elecFilt)

def write_config( alg_list, conf_file ) :

    cfile = open( conf_file, 'w')

    for alg in alg_list :
        conf_string = alg.name + ' : '
        for name, val in inspect(alg) :

            if name[0] == '_' : continue

            if name[0:3] == 'cut' :
                # check if this cut is inverted
                inv_str = ''
                if alg.is_inverted(name) :
                    inv_str = '!'
                conf_string += '%s %s[%s] ; ' %(name, inv_str, val)

        cfile.write(conf_string + '\n')

    cfile.close()

def make_exe_command( exe_path, conf_file ) :

    command = [exe_path,
               ' --conf_file %s' %conf_file,
              ]

    return ' '.join(command)

def write_header_file( name, branches, remove_branches=[] ) :

    branch_header = open(name, 'w')
    branch_header.write('#include "TTree.h"\n')
    branch_header.write('#include <vector>\n')

    branch_header.write('namespace IN {\n');

    for name, ( type, size ) in branches.iteritems() :
        if type.count('vector') :
            modtype = type.replace('vector', 'std::vector')
            file_entry = '  %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            if size > 1 :
                file_entry = '  %s\t\t\t\t%s[%d];\n' %(type, name, size)
            else :
                file_entry = '  %s\t\t\t\t%s;\n' %(type, name)

        branch_header.write(file_entry)

    branch_header.write('};\n');

    branch_header.write('namespace OUT {\n');

    for name, (type, size) in branches.iteritems() :
        if name in remove_branches :
            continue
        if type.count('vector') :
            modtype = type.replace('vector', 'std::vector')
            file_entry = '  %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            if size > 1 :
                file_entry = '  %s\t\t\t\t%s[%d];\n' %(type, name, size)
            else :
                file_entry = '  %s\t\t\t\t%s;\n' %(type, name)

        branch_header.write(file_entry)

    branch_header.write('};\n');

    branch_header.close()


def write_source_file(source_file_name, branches, remove_branches=[]) :

    branch_setting = open(source_file_name, 'w')
    branch_setting.write('#include "TTree.h"\n')

    branch_setting.write('void InitINTree( TChain * tree) {\n\n')
    counter = -1
    
    for name, (type, size) in branches.iteritems() :
        counter += 1
        if type.count('vector') :
            set_line = '  tree->SetBranchAddress("%s", &IN::%s);\n' %(name, name)
        else :
            set_line = '  tree->SetBranchAddress("%s", &IN::%s);\n' %(name, name)

        branch_setting.write(set_line)

    branch_setting.write('};\n\n')

    branch_setting.write('void InitOUTTree( TTree * tree ) {\n')

    for name, (type, size) in branches.iteritems() :
        if name in remove_branches :
            continue
        if type.count('vector') :
            set_line = '  tree->Branch("%s", &OUT::%s);\n' %(name, name)
        else :
            var_id = None
            if type == 'Float_t' :
                var_id = 'F'
            elif type == 'Double_t' :
                var_id = 'D'
            elif type == 'Int_t' :
                var_id = 'I'
            elif type == 'UInt_t' :
                var_id = 'i'
            elif type == 'Bool_t' :
                var_id = 'O'
            else :
                print 'Could not determine variable ID for %s.  Please add a var_id for this type' %type
                continue

            if size > 1 :
                set_line = '  tree->Branch("%s", &OUT::%s, "%s[%d]/%s");\n' %(name, name, name, size, var_id)
            else :
                set_line = '  tree->Branch("%s", &OUT::%s, "%s/%s");\n' %(name, name, name, var_id)

        branch_setting.write(set_line)

    branch_setting.write('}\n')

    branch_setting.write('void CopyInputVarsToOutput() {\n')

    for name, (type, size) in branches.iteritems() :
        if name in remove_branches :
            continue
        if type.count('vector') :
            set_line = '  OUT::%s = IN::%s;\n' %(name, name)
            branch_setting.write(set_line)
        else :
            if size > 1 :
                for i in range(0, size) :
                    set_line = '  OUT::%s[%d] = IN::%s[%d];\n' %(name, i, name, i)
                    branch_setting.write(set_line)
            else :
                set_line = '  OUT::%s = IN::%s;\n' %(name, name)
                branch_setting.write(set_line)


    branch_setting.write('}\n')

    branch_setting.close()



#-----------------------------------------------------------
def get_branch_mapping( tree ) :
    """ get all branches with their types and size """
    all_branches = {}
    for br in tree.GetListOfBranches() :
        leaf = br.GetListOfLeaves()[0]
        all_branches[br.GetName()] = ( leaf.GetTypeName(), leaf.GetLen() )

    return all_branches

if __name__ == '__main__' :
    main()
