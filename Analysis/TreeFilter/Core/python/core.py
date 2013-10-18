import os
import re
import sys
import imp
import math
import ROOT
import array
import copy
import inspect
import subprocess
import multiprocessing
import logging
from argparse import ArgumentParser
import eos_utilities as eosutil

def ParseArgs() :

    parser = ArgumentParser(description='')
    
    parser.add_argument('--files', dest='files', default=None, help='list of input files (comma separated).  If not provided, --filesDir must be provided')
    
    parser.add_argument('--filesDir', dest='filesDir', default=None, help='Directory to search for files.  If not provided, --files must be provided')
    
    parser.add_argument('--outputDir', dest='outputDir', default=None, help='<Required> Output sample path.  If nproc is set to > 1 a job directory is appended')
    
    parser.add_argument('--outputFile', dest='outputFile', default=None, help='Name of output file.  If none given it will assume the name of one if the input files')
    
    parser.add_argument('--treeName', dest='treeName', default=None, help='<Required> name of tree to process')

    parser.add_argument('--fileKey', dest='fileKey', default='.root', help='key to match root files')
    
    parser.add_argument('--module', dest='module', default=None, help='<Required> name of the module to import')
    
    parser.add_argument('--confFileName', dest='confFileName', default='analysis_config.txt', help='Name of the configuration file.  Default : analysis_config.txt')
    
    parser.add_argument('--nproc', dest='nproc', type=int, default=1, help='Number of processors to use.  If set to > 1, use multiprocessing')
    
    parser.add_argument('--nsplit', dest='nsplit', type=int, default=0, help='Split into nsplit subjobs.  If --nFilesPerJob is set instead, nsplit will be computed.  Jobs are first split by the number of input files.  If there are fewer input files than jobs requested the input files are further split.  Also set nproc > 1 to use multiprocessing.  However multiprocessing is only used by file')

    parser.add_argument('--nJobs', dest='nJobs', type=int, default=0, help='Equivalent to --nsplit')
    
    parser.add_argument('--nFilesPerJob', dest='nFilesPerJob', type=int, default=0, help='Number of files to run in each job.  If --nsplit is defined, then this is ignored')
    
    parser.add_argument('--noRun', dest='noRun', default=False, action='store_true', help='Just generate and compile, do not run the merging')
    
    parser.add_argument('--noCompile', dest='noCompile', default=False, action='store_true', help='Just run the merging.  Do not recompile')
    
    parser.add_argument('--storagePath', dest='storagePath', default='None', help='After the output file is written, transfer it to storage.  Use --outputDir to give the local output from where the file is transferred')
    
    parser.add_argument('--enableRemoveFilter', dest='enableRemoveFilter', default=False, action='store_true', help='Do not write out branches in the remove filter in the analysis module')
    
    parser.add_argument('--enableKeepFilter', dest='enableKeepFilter', default=False, action='store_true', help='Only write out branches in the remove filter in the analysis module.  Can specify branches to remove within the keep filter by enabling the remove filter')
    
    parser.add_argument('--debugCode', dest='debugCode', default=False, action='store_true', help='Place debugging statements in the written code')
    
    parser.add_argument('--loglevel', dest='loglevel', default='INFO', help='Log level, DEBUG, INFO, WARNING, ERROR, CRITICAL. Default is INFO')
    
    return parser.parse_args()

def config_and_run( options, package_name ) :

    assert options.files is not None or options.filesDir is not None , 'Must provide a file list via --files or a search directory via --filesDir'
    assert options.outputDir is not None, 'Must provide an output directory via --outputDir'
    assert options.treeName is not None, 'Must provide a tree name via --treeName'

    if options.loglevel.upper() not in ['DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL'] :
        print 'Loglevel must be one of DEBUG, INFO, WARNING, ERROR, CRITICAL.  Default to INFO'
        options.loglevel = 'INFO'

    #initialize the logger 
    logging.basicConfig(format='%(levelname)s:\t%(message)s', level=getattr(logging, options.loglevel.upper(), None) )

    workarea = os.getenv('WorkArea')
    assert workarea is not None, 'Did not locate WorkArea environment variable.  Please set it to the root of the package.'

    input_files = []
    if options.files is not None :
        input_files = options.files.split(',')
    elif options.filesDir is not None :
        input_files = collect_input_files( options.filesDir, options.fileKey )

    # remove any blank entries
    while '' in input_files :
        input_files.remove('')

    # if output file name is not given grab the name from one of the input files
    if options.outputFile is None :
        options.outputFile = input_files[0].split('/')[-1]

    branches = get_branch_mapping(input_files, options.treeName )

    ImportedModule = import_module( options.module )

    branches_to_keep = get_keep_branches( ImportedModule, branches, 
                                               options.enableKeepFilter, 
                                               options.enableRemoveFilter )

    if options.enableKeepFilter :
        print 'Will keep %d branches from output file : ' %len(branches_to_keep)
        print '\n'.join(branches_to_keep)
    elif options.enableRemoveFilter :
        print 'Will remove %d branches from output file : ' %( len(branches) - len(branches_to_keep))
        print '\n'.join( list( set( [ br['name'] for br in branches ] ) - set( branches_to_keep ) ) )

    if not options.noCompile :

        def_file_name = '%s/TreeFilter/%s/include/BranchDefs.h' %( workarea, package_name )
        header_file_name = '%s/TreeFilter/%s/include/BranchInit.h' %( workarea, package_name )
        source_file_name = '%s/TreeFilter/%s/src/BranchInit.cxx' %(workarea, package_name )

        # Write the c++ files having the branch definitions and 
        # SetBranchAddress calls
        write_branchdef_file(def_file_name, branches, branches_to_keep )

        write_source_file(source_file_name, header_file_name, branches, branches_to_keep )

        # compile
        logging.info('********************************')
        logging.info('  Begin Complilation ' )
        logging.info('********************************')
        proc = subprocess.Popen(['make', 'clean'])
        proc.wait()
        proc = subprocess.Popen(['make'])
        retcode = proc.wait()
        
        # abort if non-zero return code
        if retcode :
            logging.error( 'Compilation failed.  Will not run' )
            return
        logging.info('********************************')
        logging.info('  Complilation Finished ')
        logging.info('********************************')

    # Stop here if not running
    if options.noRun :
        return

    # Get the path of the executable.  First try the
    # WorkArea environment variable which will give
    # an absolute path.  If that doesn't exist, try
    # Using the path of this script to get an
    # absolute path
    exe_path = '%s/TreeFilter/%s/RunAnalysis' %(workarea, package_name)

    run_commands = []

    alg_list = []
    ImportedModule.config_analysis(alg_list)

    # --------------------------
    # Handle file splitting.
    # Be default nsplit = 1.  In this case the default 
    # behavior is only one job running over all
    # events
    # --------------------------
    if options.nJobs > 0 and options.nsplit == 0 :
        options.nsplit = options.nJobs

    file_evt_list = get_file_evt_map( input_files, options.nsplit, options.nFilesPerJob, options.treeName )

    if options.nproc > 1 and options.nproc > len(file_evt_list) :
        options.nproc = len(file_evt_list)

    logging.info('********************************')
    logging.info('Will run a total of %d processes, %d at a time' %(len(file_evt_list), options.nproc) )
    logging.info('********************************')


    if options.nproc > 1 : #multiprocessing!

        commands = generate_multiprocessing_commands( file_evt_list, alg_list, exe_path, options )

        pool = multiprocessing.Pool(options.nproc)
        logging.info('********************************')
        for cmd in commands :
            logging.info( 'Executing ' + cmd )
        logging.info('********************************')
        pool.map( os.system, commands)

    else :

        output_file = '%s/%s' %(options.outputDir, options.outputFile )
        if not os.path.isdir( options.outputDir ) and options.outputDir.count('root://') != -1 :
            os.makedirs( options.outputDir )
        write_config( alg_list, options.confFileName, options.treeName, options.outputDir, options.outputFile, file_evt_list, options.storagePath ) 
        command = make_exe_command( exe_path, options.confFileName )

        logging.info('********************************')
        logging.info( 'Executing ' + command )
        logging.info('********************************')
        os.system(command)


def collect_input_files( filesDir, filekey='.root' ) :
    input_files = []
    if filesDir.count('root://') > 0 :
        input_files = collect_input_files_eos( filesDir, filekey )
    else :
        input_files = collect_input_files_local( filesDir, filekey )

    return input_files

def collect_input_files_local( filesDir, filekey='.root' ) :
    input_files = []
    for top, dirs, files in os.walk(filesDir) :
        for f in files :
            if f.count(filekey) > 0 :
                input_files.append(top+'/'+f)

    return input_files

def collect_input_files_eos( filesDir, filekey='.root' ) :
    
    logging.info('Getting list of input files from eos')
    input_files = []
    for top, dirs, files, sizes in eosutil.walk_eos(filesDir) :
        for f in files :
            if f.count(filekey) > 0 :
                input_files.append(top+'/'+f)

    return input_files


#-----------------------------------------------------------
def get_branch_mapping( files, treename ) :
    """ get all branches with their types and size """

    if not isinstance(files, list) :
        files = [files]

    files_all_branches = []

    for filename in files :
        file = ROOT.TFile.Open( filename )
        tree = file.Get( treename )

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
            check = re.match('\w+((?:\[\w+\])*)\s*/(\w)', title) 
            size_leaf = None
            bracketEntry = None
            varId = None
            leafEntry = None
            arrayStr = ''
            size_entries = []
            totSize = lf.GetNdata()  # keep the total size for later
            if check is None :
                leafEntry = title
            else :
                bracketEntry = check.group(1)

                if len(check.groups()) > 1 :
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
                            size_entries.append(size)
                        else :
                            size_entries.append(int(eb))

                    # This should be the format of the array in the declaration
                    arrayStr = '[' + ']['.join([str(x) for x in size_entries]) + ']'

            if varId is not None :
                leafEntry += '/%s' %varId

            prop_dic = {'name' : name, 'type' : type, 'totSize' : totSize, 'arrayStr' : arrayStr, 'leafEntry' : leafEntry, 'sizeEntries' : size_entries }

            if is_range :
                # any variable that is a range variable needs to come first
                all_branches.insert(0, prop_dic) 
            else :
                all_branches.append(prop_dic)

        files_all_branches.append(all_branches)

    # now collect the maximum values from all files

    all_branches_max = []
    if len(files_all_branches) == 1 :
        all_branches_max = files_all_branches[0]
    else :

        # start by grabbing the first entry
        all_branches_max = files_all_branches[0]
        # now for the branches associated to each file, loop
        # over the branch names and check if the branch
        # size in this file is larger than the current max branch
        # size.  If larger, update.
        # this might be slow, but it runs only once per job
        for file_branches in files_all_branches[1:] :
            for brinfo in file_branches :
                for idx, brinfomax in enumerate(list(all_branches_max)) :

                    # get branches of the same name
                    if brinfo['name'] != brinfomax['name'] :
                        continue

                    #print 'Original size ',brinfomax['totSize']
                    #print 'New size ',brinfo['totSize']
                    if brinfo['totSize'] > brinfomax['totSize'] :
                        #print 'Update the size of branch %s ' %(brinfo['name'])
                        #print all_branches_max[idx]
                        #print brinfo
                        all_branches_max[idx] = brinfo

                    # if we've matched names we can move on to the next file
                    break

    return all_branches_max


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

    if not hasattr(ImportedModule, 'config_analysis') :
        print 'ERROR - module does not implement a function called config_analysis'
        sys.exit(-1)

    return ImportedModule

def get_keep_branches( module, branches, enable_keep_filter, enable_remove_filter ) :

    remove_filter = []
    keep_filter = []
    if hasattr(module, 'get_remove_filter') :
        remove_filter = module.get_remove_filter()
    if hasattr(module, 'get_keep_filter') :
        keep_filter = module.get_keep_filter()

    # by default keep all branches
    all_branches = [ br['name'] for br in branches ]
    branches_to_keep =  list(all_branches)
    if enable_keep_filter :
        #only keep these branches.  Reset the keep list
        branches_to_keep = []
        for kregex in keep_filter :
            matches = [ re.match( kregex, br['name'] ) for br in branches ]
            successful_matches = filter( lambda x : x is not None, matches )
            branches_to_keep += [ x.group(0) for x in successful_matches]

    if enable_remove_filter :
        for rregex in remove_filter :
            matches = [ re.match( rregex, br['name'] ) for br in branches ]
            successful_matches = filter( lambda x : x is not None, matches )
            branches_to_remove = [ x.group(0) for x in successful_matches]
            branches_to_keep = list( set(branches_to_keep) - set(branches_to_remove) )
            
    return branches_to_keep

def make_exe_command( exe_path, conf_file ) :

    command = [exe_path,
               ' --conf_file %s' %conf_file,
              ]

    return ' '.join(command)

def generate_multiprocessing_commands( file_evt_list, alg_list, exe_path, options ) :

    commands = []
    for idx, file_split in enumerate(file_evt_list) :
        jobid = 'Job_%04d' %idx
        outputDir = options.outputDir
        conf_file = '%s/%s_%s.%s' %(outputDir, options.confFileName.split('.')[0], jobid, '.'.join(options.confFileName.split('.')[1:]))
        if not os.path.isdir( outputDir ) :
            os.makedirs( outputDir )
        
        write_config(alg_list, conf_file, options.treeName, outputDir, options.outputFile, [file_split], options.storagePath, idx )
        commands.append( make_exe_command( exe_path, conf_file ) )

    return commands


def get_file_evt_map( input_files, nsplit, nFilesPerJob, treeName ) :

    nFilesPerSplit = 0
    if nFilesPerJob > 0 and nsplit == 0 :
        nFilesPerSplit = nFilesPerJob
    elif nFilesPerJob == 0 and nsplit > 0 :
        # split by the number of files
        nFilesPerSplit = int(math.ceil(float(len(input_files))/nsplit))
    if nFilesPerSplit == 0 :
        nFilesPerSplit = 1
    # split into sub-lists based on the number of jobs.  last job may have fewer files

    split_files = [input_files[i:i+nFilesPerSplit] for i in range(0, len(input_files), nFilesPerSplit)]
    if nsplit > 0 and nFilesPerJob > 0 :
        print 'Both --nsplit and --nFilesPerJob were provided.  This could result in only a part of the sample being analyzed'
        split_files = split_files[0:nsplit]

    # now split by events.  If no further splitting is requested
    # then each file runs over the full set of events
    files_evtsplit = []

    # determine how many times to split each file.  Do this by 
    # adding a split to each file until the number
    # of splits is achieved
    files_nsplit = [ 1 ]*len(split_files)
    n_addtl_split = nsplit - len(split_files) 
    files_idx = 0
    for sp in range(0, n_addtl_split ) :
        files_nsplit[files_idx] += 1

        # increment the index
        # if we're at the end of the list go back to the beginning
        files_idx += 1
        if files_idx >= len(files_nsplit) :
            files_idx = 0

    #get the total number of events for each file
    files_nevt = [0]*len(split_files)
    for idx, files in enumerate(split_files) :
        for file in files :
            tmp = ROOT.TFile.Open(file)
            tree = tmp.Get(treeName)
            files_nevt[idx] += tree.GetEntries()
            tmp.Close()

    # for each file get the range to use
    for files, nsplit, totevt in zip(split_files, files_nsplit, files_nevt) :

        splitlist = []
        split_base = int(totevt)/int(nsplit)
        prev_val = 0
        for splitidx in range(0, nsplit) :
            # at the last entry the upper limit is the number of events
            # this prevents any missed events
            if splitidx == nsplit-1 :
                splitlist.append( (prev_val, totevt) )
            else :
                splitlist.append( (prev_val, prev_val+split_base) )

            prev_val = prev_val + split_base

        files_evtsplit.append(splitlist)

    assert len(files_evtsplit) == len(split_files), 'ERROR - size mismatch.  This should not happen!'

    split_files_evt_match = []
    for flist, evtsplit in zip(split_files, files_evtsplit) :
        split_files_evt_match.append( (flist, evtsplit ))

    return split_files_evt_match

def write_config( alg_list, filename, treeName, outputDir, outputFile, files_list, storage_path, start_idx=0 ) :

    cfile = open( filename, 'w')

    # first write header information
    jobid = start_idx
    file_line = ''
    for flist, evtlist in files_list :
        file_line += flist.__str__().replace('\'','').replace(' ', '')
        file_line += '['
        for min, max in evtlist :
            file_line += '%d:(%d-%d),' %( jobid, min, max )
            jobid += 1
        file_line.rstrip(',')
        file_line += '];'

    cfile.write( 'files : %s\n' %file_line )
    cfile.write( 'treeName : %s\n' %( treeName ) )
    cfile.write( 'outputDir : %s\n' %( outputDir ) )
    cfile.write( 'outputFile : %s\n' %( outputFile ) )
    if storage_path != 'None' :
        cfile.write( 'storagePath : %s\n' %storage_path )

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

        if alg.do_cutflow :
            conf_string += 'do_cutflow [] ; '

        if alg.hists :
        
            for hist in alg.hists :
                conf_string+='hist [%s,%d,%f,%f];' %(hist['name'], hist['nbin'], hist['xmin'], hist['xmax'])

        cfile.write(conf_string + '\n')

    cfile.close()

def write_branchdef_file( name, branches, keep_branches=[] ) :

    branch_header = open(name, 'w')
    branch_header.write('#ifndef BRANCHDEFS_H\n')
    branch_header.write('#define BRANCHDEFS_H\n')
    branch_header.write('#include "TTree.h"\n')
    branch_header.write('#include <vector>\n')

    branch_header.write('//This next bit of code defines whether each branch\n'
                        '//exists or not.  This can be used to solve the problem\n'
                        '//when a branch in available in some ntuples, but not others.\n'
                        '//If this happens, the code will not compile because the\n'
                        '//branch is not written in the header file.  To fix this problem\n'
                        '//simply surround the offending code with #ifdef EXISTS_MYVAR ... #endif\n'
                        '//and if the variable does not exist the preprocessor will ignore that code')

    for conf in branches :
        name = conf['name']
        branch_header.write('#define EXISTS_%s\n'%name)
    
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


def write_source_file(source_file_name, header_file_name, branches, keep_branches=[], debugCode=False) :

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
    branch_setting.write('#include "include/BranchInit.h"\n' )
    branch_setting.write('#include "include/BranchDefs.h"\n\n' )

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
                if conf['totSize'] < 200 :
                    set_line = '  std::copy(IN::%s, IN::%s+%d, OUT::%s);\n ' %(name, name, conf['totSize'], name)
                    if debugCode :
                        set_line = ' std::cout << "Attempt to copy variable %s" << std::endl;\n ' %name + set_line
                else :
                    sizes = conf['sizeEntries']
                    set_line = ''
                    for array_val in generate_array_loop( sizes ) :
                        set_line += '  OUT::%s%s = IN::%s%s;\n ' %(name, array_val, name, array_val)


                    # code crashes when copying large arrays the only solution I've found is to do it manually

                branch_setting.write(set_line)
            else :
                set_line = '  OUT::%s = IN::%s;\n' %(name, name)
                branch_setting.write(set_line)


    branch_setting.write('}\n')

    branch_setting.close()


def generate_array_loop( array_sizes ) :

    def _increment( array_val, array_sizes, depth ) :

        if depth == -1 :
            return array_val
        if array_val[depth] == ( array_sizes[depth] - 1 ) : #at the last value, reset to 0 and increment the previous
            array_val[depth] = 0
            _increment( array_val, array_sizes, depth-1)
        else :
            array_val[depth] += 1

        return array_val


    n_depth = len(array_sizes)
    array_val = [0]*n_depth

    total_size = reduce(lambda x, y: x*y, array_sizes)
    for idx in range(0, total_size) :
        yield '[' + ']['.join([str(x) for x in array_val]) + ']'

        _increment( array_val, array_sizes, n_depth-1 );



class Filter :

    def __init__(self, name) :
        self.invert_list = []
        self.name = name
        self.do_cutflow = False
        self.hists = []

    def invert(self, name) :
        self.invert_list.append(name)

    def is_inverted(self, name) :
        return name in self.invert_list

    def add_hist(self, name, nbin, xmin, xmax ) :
        self.hists.append( {'name':name, 'nbin':nbin, 'xmin':xmin, 'xmax':xmax } )


# for python only code

class AnalysisConfig :

    def __init__(self) :
        self.modules = []
        self.files = []
        self.keep_branches = []

    def add_module(self, module) :
        self.modules.append(module)

    def get_modules(self) :
        return self.modules

    def Run( self, runmod, options ) :

        if not hasattr(runmod, 'Run') :
            print 'AnalysisConfig.Run - ERROR : Run module does not implement a function called Run'

        runmod.in_tree = ROOT.TChain( options.treeName, options.treeName )
        for file in self.files :
            runmod.in_tree.Add( file )

        runmod.outfile = ROOT.TFile.Open( '%s/%s' %(options.outputDir, options.outputFile ), 'RECREATE' )
        runmod.outfile.cd()

        # make the output tree
        # if the input tree is within a directory, put the output tree
        # in a directory of the same name
        name_split = runmod.in_tree.GetName().split('/')
        dir_path = ''
        if len(name_split) > 1 :
            for dir in name_split[:-1] :
                dir_path = dir_path + dir + '/'
                print 'TFile.mkdir %s' %dir_path
                runmod.outfile.mkdir( dir_path )

            runmod.outfile.cd( dir_path )

            tree_name = name_split[-1]

            runmod.out_tree = ROOT.TTree( tree_name, tree_name )
        else :
            runmod.out_tree = ROOT.TTRee( runmod.in_tree.GetName(), runmod.in_tree.GetName() )
            runmod.out_tree.SetDirectory( runmod.outfile )

        self.init_out_tree( runmod )

        print 'OUT branches'
        for br in runmod.out_tree.GetListOfBranches() :
            print br.GetName()

        runmod.Run( self.get_modules(), options, 0, 0 )

        runmod.outfile.Write()
        runmod.outfile.Close()

    def init_out_tree( self, module ) :

        all_branches = get_branch_mapping( module.in_tree )

        for br in all_branches :
            brname = br['name']

            if brname not in self.keep_branches :
                continue

            if br['type'].count('vector') :
                print 'FIX ME'
                setattr(module.out_tree, brname, std.vector(int)())
                out_tree.Branch(brname, getattr(module.out_tree, brname))
            else :
                array_type = ''
                br_type = br['type']
                if br_type == 'int' or br_type == 'Int_t' :
                    array_type = 'i'
                elif br_type == 'float' or br_type == 'Float_t' :
                    array_type = 'f'
                elif br_type == 'double' or br_type == 'Double_t' :
                    array_type = 'd'
                elif br_type == 'Long64_t' :
                    array_type = 'L'
                elif br_type == 'Bool_t' :
                    array_type = 'B'
                else :
                    print 'No conversion for type %s' %br_type
                    continue
               
                    #    root2PythonDictionary = { 
                    #            #root:python 
                    #            'C':'c',#char 
                    #            'B':'b',#signed char 
                    #            'b':'B',#unsigned char 
                    #            'S':'h',#signed short 
                    #            's':'H',#unsigned short 
                    #            'I':'i',#signed int 
                    #            'i':'I',#unsigned int 
                    #            'L':'l',#signed long 
                    #            'l':'L',#unsigned long 
                    #            'F':'f',#float 
                    #            'D':'d'#double 
                    #    } 
                setattr(module, brname, array.array(array_type, br['totSize']*[0]) )
                print brname
                print getattr(module, brname)
                print br['leafEntry']
                module.out_tree.Branch(brname, getattr(module, brname), br['leafEntry'])

class ModuleConfig : 
    
    def __init__( self, alg ) :

        self.name = alg.name

        self.cuts = {}

        for member in alg.__dict__ : 
            if not member.count('cut_') :
                continue

            self.cuts[member] = getattr(alg, member)

            
    def pass_cut( self, cut, val ) :

        # if cut hasn't been configured, then pass it
        if cut not in self.cuts :
            return True

        return eval( 'val' + self.cuts[cut] )

    def Print( self ) :
        print 'Module name is %s' %self.name
        print 'Cuts are : '
        for name, val in self.cuts.iteritems() :
            print '%s %s' %(name, val)

def ConfigureAnalysis( runmod, options ) :

    # read input files
    assert options.files is not None or options.filesDir is not None, 'Must provide a list of files via --files or a directory containing files via --filesDir'

    ana_config = AnalysisConfig()
    if options.files is not None :
        ana_config.files = options.files.split(',')
    elif options.filesDir is not None :
        ana_config.files = collect_input_files( options.filesDir )
        
    if not ana_config.files :
        print 'No files were found'
        return 

    # get the configuration
    ImportedModule = import_module( options.module )

    alg_list = []
    ImportedModule.config_analysis( alg_list )

    for alg in alg_list :
        ana_config.add_module(ModuleConfig(alg))

    keep_filter   = []
    remove_filter = []

    branches = get_branch_mapping( ana_config.files, options.treeName )

    ana_config.keep_branches = get_keep_branches( ImportedModule, branches, options.enableKeepFilter, options.enableRemoveFilter )

    return ana_config
    
def copy_event( module ) :

    for br in module.out_tree.GetListOfBranches() :
        brname = br.GetName()

        #module.nEle[0] = module.in_tree.nEle
        print brname
        print module.out_tree.GetBranch(brname).GetTitle()
        brtitle = module.out_tree.GetBranch(brname).GetTitle()
        is_array = brtitle.count('[') and brtitle.count(']')
        #print getattr(module, brname)
        #varlen = len(getattr(module, brname))
        varlen = module.in_tree.GetBranch(brname).GetLeaf(brname).GetNdata()
        print varlen
        #print 'leaf type', module.in_tree.GetBranch(brname).GetLeaf(brname).GetTypeName()
        #print getattr(module, brname)
        
        if is_array :
            #setattr(module, brname, getattr(module.in_tree, brname) )
            for idx in xrange(0, len(getattr(module.in_tree, brname ))) :
                exec('module.%s[%d] = module.in_tree.%s[%d]' %(brname, idx, brname, idx) )
        else :
            exec('module.%s[0] = module.in_tree.%s' %(brname, brname ) )

        #if varlen == 1 :
        #    exec('module.%s[0] = module.in_tree.%s' %(brname, brname ) )
        #else :
        #    setattr(module, brname, getattr(module.in_tree, brname) )
        #    #for idx in xrange(0, len(getattr(module.in_tree, brname ))) :
        #    #    exec('module.%s[%d] = copy.copymodule.in_tree.%s[%d]' %(brname, idx, brname, idx) )
        ##setattr(module, brname+'[0]', getattr(module.in_tree, brname) )
