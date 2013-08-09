
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
import imp
import ROOT
from array import array
from argparse import ArgumentParser

parser = ArgumentParser(description='')

parser.add_argument('--files', dest='files', default=None, help='list of input files (comma separated).  If not provided, --filesDir must be provided')

parser.add_argument('--filesDir', dest='filesDir', default=None, help='Directory to search for files.  If not provided, --files must be provided')

parser.add_argument('--outputDir', dest='outputDir', default=None, help='<Required> Output sample path.  If nproc is set to > 1 a job directory is appended')

parser.add_argument('--outputFile', dest='outputFile', default=None, help='Name of output file.  If none given it will assume the name of one if the input files')

parser.add_argument('--treeName', dest='treeName', default=None, help='<Required> name of tree to process')

parser.add_argument('--module', dest='module', default=None, help='<Required> name of the module to import')

parser.add_argument('--confFileName', dest='confFileName', default='analysis_config.txt', help='Name of the configuration file.  Default : analysis_config.txt')

parser.add_argument('--nproc', dest='nproc', type=int, default=1, help='Number of processors to use.  If set to > 1, use multiprocessing')

parser.add_argument('--nsplit', dest='nsplit', type=int, default=1, help='Split into nsplit subjobs based on the number of input files.  Only used if nproc is set to > 1')

parser.add_argument('--noRun', dest='noRun', default=False, action='store_true', help='Just generate and compile, do not run the merging')

parser.add_argument('--noCompile', dest='noCompile', default=False, action='store_true', help='Just run the merging.  Do not recompile')

parser.add_argument('--enableRemoveFilter', dest='enableRemoveFilter', default=False, action='store_true', help='Do not write out branches in the remove filter in the analysis module')

parser.add_argument('--enableKeepFilter', dest='enableKeepFilter', default=False, action='store_true', help='Only write out branches in the remove filter in the analysis module.  Can specify branches to remove within the keep filter by enabling the remove filter')

parser.add_argument('--debugCode', dest='debugCode', default=False, action='store_true', help='Place debugging statements in the written code')


options = parser.parse_args()

#*************************************
#Some global definitions
#*************************************

workarea = os.getenv('WorkArea')
if workarea is None :
    print 'Did not locate WorkArea environment variable.  Please set it to the root of the package'
    sys.exit(-1)

def_file_name = workarea + '/FilterTruthWgamgam/FilterTruthWgamgam/BranchDefs.h'
header_file_name = workarea + '/FilterTruthWgamgam/FilterTruthWgamgam/BranchInit.h'
source_file_name = workarea + '/FilterTruthWgamgam/src/BranchInit.cxx'

def main(**kwargs) :

    assert options.files is not None or options.filesDir is not None , 'Must provide a file list via --files or a search directory via --filesDir'
    assert options.outputDir is not None, 'Must provide an output directory via --outputDir'
    assert options.treeName is not None, 'Must provide a tree name via --treeName'

    input_files = []
    if options.files is not None :
        input_files = options.files.split(',')
    elif options.filesDir is not None :
        for top, dirs, files in os.walk(options.filesDir) :
            for f in files :
                if f.count('.root') != -1 :
                    input_files.append(top+'/'+f)

    # if output file name is not given grab the name from one of the input files
    if options.outputFile is None :
        options.outputFile = input_files[0].split('/')[-1]

    testfile = ROOT.TFile.Open( input_files[0] )
    testtree = testfile.Get( options.treeName )

    branches = get_branch_mapping(testtree)

    ImportedModule = import_module( options.module )

    remove_filter = []
    keep_filter = []
    if hasattr(ImportedModule, 'get_remove_filter') :
        remove_filter = ImportedModule.get_remove_filter()
    if hasattr(ImportedModule, 'get_keep_filter') :
        keep_filter = ImportedModule.get_keep_filter()

    if not options.noCompile :
        # by default keep all branches
        all_branches = [ br['name'] for br in branches ]
        branches_to_keep =  list(all_branches)
        if options.enableKeepFilter :
            #only keep these branches.  Reset the keep list
            branches_to_keep = []
            for kregex in keep_filter :
                matches = [ re.match( kregex, br['name'] ) for br in branches ]
                successful_matches = filter( lambda x : x is not None, matches )
                branches_to_keep += [ x.group(0) for x in successful_matches]

        if options.enableRemoveFilter :
            for rregex in remove_filter :
                matches = [ re.match( rregex, br['name'] ) for br in branches ]
                successful_matches = filter( lambda x : x is not None, matches )
                branches_to_remove = [ x.group(0) for x in successful_matches]
                print 'rm branches'
                print branches_to_remove
                branches_to_keep = list( set(branches_to_keep) - set(branches_to_remove) )
            
        if options.enableKeepFilter :
            print 'Will keep %d branches from output file : ' %len(branches_to_keep)
            print '\n'.join(branches_to_keep)
        elif options.enableRemoveFilter :
            print 'Will remove %d branches from output file : ' %( len(branches) - len(branches_to_keep))
            print '\n'.join( list( set( all_branches ) - set( branches_to_keep ) ) )


        # Write the c++ files having the branch definitions and 
        # SetBranchAddress calls
        write_branchdef_file(def_file_name, branches, branches_to_keep )

        write_source_file(source_file_name, header_file_name, branches, branches_to_keep )

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
        exe_path = '%s/FilterTruthWgamgam/RunAnalysis' %workarea

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
    import_module( options.module ).config_analysis(alg_list)

    if options.nproc > 1 : #multiprocessing!

        # if nsplit isn't set assume that it is the same as nproc
        if options.nsplit == 1 :
            options.nsplit = options.nproc

        nFilesPerJob = int(math.ceil(float(len(input_files))/options.nsplit))
        if nFilesPerJob == 0 :
            nFilesPerJob = 1
        # split into sub-lists based on the number of jobs.  last job may have fewer files

        split_files = [input_files[i:i+nFilesPerJob] for i in range(0, len(input_files), nFilesPerJob)]

        configs = []
        commands = []
        for idx, files in enumerate(split_files) :
            jobid = 'Job_%04d' %idx
            conf_file = '%s_%s.%s' %(options.confFileName.split('.')[0], jobid, '.'.join(options.confFileName.split('.')[1:]))
            outputDir = options.outputDir + '/' + jobid
            output_file = outputDir + '/' + options.outputFile
            if not os.path.isdir( outputDir ) :
                os.makedirs( outputDir )
            
            write_config(alg_list, conf_file, options.treeName, output_file, ','.join(files) )
            commands.append( make_exe_command( exe_path, conf_file ) )

        pool = multiprocessing.Pool(options.nproc)
        pool.map( os.system, commands )

    else :

        output_file = '%s/%s' %(options.outputDir, options.outputFile )
        if not os.path.isdir( options.outputDir ) :
            os.makedirs( options.outputDir )
        write_config( alg_list, options.confFileName, options.treeName, output_file, ','.join(input_files))
        command = make_exe_command( exe_path, options.confFileName )
        print command
        os.system(command)

def write_config( alg_list, filename, treeName, output, files ) :

    cfile = open( filename, 'w')

    # first write header information
    cfile.write( 'files : %s\n' %( files ) )
    cfile.write( 'treeName : %s\n' %( treeName ) )
    cfile.write( 'output : %s\n' %( output ) )
    cfile.write( '__Modules__\n' )

    for alg in alg_list :
        conf_string = alg.name + ' : '
        for name, val in inspect.getmembers(alg) :

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

def import_module( module ) :

    ImportedModule=None

    ispath = ( module.count('/') > 0 )
    module_path = None
    if ispath :
        module_path = module
    else :
        #get path of this script
        script_path = os.path.realpath(__file__)
        module_path = os.path.dirname(script_path) + '/' + module

    try :
        ImportedModule = imp.load_source(module.split('.')[0], module_path)
    except IOError :
        print 'Could not import module %s' %module_path

    print module_path
    print module.split('.')[0]
    if not hasattr(ImportedModule, 'config_analysis') :
        print 'ERROR - module does not implement a function called config_analysis'
        sys.exit(-1)

    return ImportedModule


def write_branchdef_file( name, branches, keep_branches=[] ) :

    branch_header = open(name, 'w')
    branch_header.write('#ifndef BRANCHDEFS_H\n')
    branch_header.write('#define BRANCHDEFS_H\n')
    branch_header.write('#include "TTree.h"\n')
    branch_header.write('#include <vector>\n')

    branch_header.write('//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions\n')

    branch_header.write('namespace IN {\n');

    for conf in branches :

        name = conf['name']

        # declare the variable differently for a vector
        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' extern %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' extern %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_header.write(file_entry)

    branch_header.write('};\n');

    branch_header.write('namespace OUT {\n');

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue

        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' extern %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' extern %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_header.write(file_entry)

    branch_header.write('};\n');
    branch_header.write('#endif\n')

    branch_header.close()


def write_source_file(source_file_name, header_file_name, branches, keep_branches=[]) :

    branch_header = open(header_file_name, 'w')
    branch_header.write('#ifndef BRANCHINIT_H\n')
    branch_header.write('#define BRANCHINIT_H\n')
    branch_header.write('#include "TTree.h"\n')
    branch_header.write('#include "TChain.h"\n')
    branch_header.write('void InitINTree( TChain * tree );\n')
    branch_header.write('void InitOUTTree( TTree * tree );\n')
    branch_header.write('void CopyInputVarsToOutput();\n')
    branch_header.write('#endif\n')
    branch_header.close()

    branch_setting = open(source_file_name, 'w')
    branch_setting.write('#include <algorithm>\n')
    branch_setting.write('#include <iostream>\n')
    branch_setting.write('#include "TTree.h"\n')
    branch_setting.write('#include "TChain.h"\n')
    branch_setting.write('#include "FilterTruthWgamgam/BranchInit.h"\n')
    branch_setting.write('#include "FilterTruthWgamgam/BranchDefs.h"\n\n')

    branch_setting.write('namespace IN {\n');
    for conf in branches :

        name = conf['name']

        # declare the variable differently for a vector
        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_setting.write(file_entry)

    branch_setting.write('};\n');

    branch_setting.write('namespace OUT {\n');

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue

        if conf['type'].count('vector') :
            modtype = conf['type'].replace('vector', 'std::vector')
            file_entry = ' %s\t\t\t\t*%s;\n' %(modtype, name)
        else :
            file_entry = ' %s\t\t\t\t%s%s;\n' %(conf['type'], name, conf['arrayStr'])

        branch_setting.write(file_entry)

    branch_setting.write('};\n');

    branch_setting.write('void InitINTree( TChain * tree) {\n\n')
    counter = -1
    
    for conf in branches :

        name = conf['name']

        counter += 1
        # might need to fix this for variable length arrays
        set_line = '  tree->SetBranchAddress("%s", &IN::%s);\n' %(name, name)
        #if type.count('vector') :
        #else :
        #    set_line = '  tree->SetBranchAddress("%s", &IN::%s);\n' %(name, name)

        branch_setting.write(set_line)

    branch_setting.write('};\n\n')

    branch_setting.write('void InitOUTTree( TTree * tree ) {\n')

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue

        if conf['type'].count('vector') :
            set_line = '  tree->Branch("%s", &OUT::%s);\n' %(name, name)
        else :
            set_line = '  tree->Branch("%s", &OUT::%s, "%s");\n' %(name, name, conf['leafEntry'])

        branch_setting.write(set_line)

    branch_setting.write('}\n')

    branch_setting.write('void CopyInputVarsToOutput() {\n')

    for conf in branches :

        name = conf['name']

        if name not in keep_branches :
            continue
        if conf['type'].count('vector') :
            set_line = '  OUT::%s = IN::%s;\n' %(name, name)
            branch_setting.write(set_line)
        else :
            if conf['totSize'] > 1 :
                #set_line = '  memcpy(OUT::%s, IN::%s, %d);\n' %(name, name, conf['totSize'])
                set_line = '  std::copy(IN::%s, IN::%s+%d, OUT::%s);\n ' %(name, name, conf['totSize'], name)
                if options.debugCode :
                    set_line = ' std::cout << "Attempt to copy variable %s" << std::endl;\n ' %name + set_line
                branch_setting.write(set_line)
            else :
                set_line = '  OUT::%s = IN::%s;\n' %(name, name)
                branch_setting.write(set_line)


    branch_setting.write('}\n')

    branch_setting.close()



#-----------------------------------------------------------
def get_branch_mapping( tree ) :
    """ get all branches with their types and size """

    all_branches = []
    for br in tree.GetListOfBranches() :

        name  = br.GetName()
        title = br.GetTitle()

        #I don't know why this happens.  Just fix it
        title = title.replace(']]', '][')
 
        lf = br.GetListOfLeaves()[0]
        type  = lf.GetTypeName()
        size  = lf.GetLen()
        is_range = lf.IsRange()
        # match any number of brackets and get them.  
        # Also get the varId at the end.  
        # If there are no brackets the first group is empty
        check = re.match('\w+((?:\[\w+\])*)\s*(?:/(\w))*', title) 
        size_leaf = None
        bracketEntry = None
        varId = None
        leafEntry = None
        arrayStr = ''
        totSize = lf.GetNdata()  # keep the total size for later
        if check is None :
            print 'Fail RegEx match for leaf %s' %title
        else :
            bracketEntry = check.group(1)
            varId = check.group(2)

            # construct the leafEntry
            leafEntry = name

            # there could be any number of brackets in the variable
            # If there are no brackets the leafEntry is simpy the name
            # plus the varId.  Otherwise do some more work
            if not bracketEntry == '' :
                # get each bracket entry
                each_bracket = bracketEntry.split('][')
                each_bracket = map( lambda x : x.rstrip(']').lstrip('['), each_bracket )

                # if one or more entries is a variable length array we need
                # to get its maximum size.  Otherwise we already have the size
                output_array_entry = ''
                for  eb in each_bracket :

                    # construct the leafEntry
                    leafEntry += '[%s]' %eb.rstrip('_')

                    is_int = True
                    try :
                        test = int(eb)
                    except ValueError :
                        is_int = False

                    # If its not an int, its another branch.  Get it and find its max size
                    if not is_int :

                        size_leaf_name = eb.rstrip('_')

                        size_br = tree.GetBranch(size_leaf_name)
                        size = size_br.GetListOfLeaves()[0].GetMaximum()+1 #Add one for buffer
                        output_array_entry += '[%d]' %size
                    else :
                        output_array_entry += '[%s]' %eb

                # This should be the format of the array in the declaration
                arrayStr = output_array_entry

        leafEntry += '/%s' %varId

        prop_dic = {'name' : name, 'type' : type, 'totSize' : totSize, 'arrayStr' : arrayStr, 'leafEntry' : leafEntry }

        if is_range :
            # any variable that is a range variable needs to come first
            all_branches.insert(0, prop_dic) 
        else :
            all_branches.append(prop_dic)

    return all_branches


class Filter :

    def __init__(self, name) :
        self.invert_list = []
        self.name = name

    def invert(self, name) :
        self.invert_list.append(name)

    def is_inverted(self, name) :
        return name in self.invert_list



if __name__ == '__main__' :
    main()
