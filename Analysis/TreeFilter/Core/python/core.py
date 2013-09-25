import os
import re
import sys
import imp
import math
import ROOT
import inspect
import subprocess
from argparse import ArgumentParser

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
    
    parser.add_argument('--nsplit', dest='nsplit', type=int, default=1, help='Split into nsplit subjobs.  Jobs are first split by the number of input files.  If there are fewer input files than jobs requested the input files are further split.  Also set nproc > 1 to use multiprocessing.  However multiprocessing is only used by file')
    
    parser.add_argument('--noRun', dest='noRun', default=False, action='store_true', help='Just generate and compile, do not run the merging')
    
    parser.add_argument('--noCompile', dest='noCompile', default=False, action='store_true', help='Just run the merging.  Do not recompile')
    
    parser.add_argument('--storagePath', dest='storagePath', default='None', help='After the output file is written, transfer it to storage.  Use --outputDir to give the local output from where the file is transferred')
    
    parser.add_argument('--enableRemoveFilter', dest='enableRemoveFilter', default=False, action='store_true', help='Do not write out branches in the remove filter in the analysis module')
    
    parser.add_argument('--enableKeepFilter', dest='enableKeepFilter', default=False, action='store_true', help='Only write out branches in the remove filter in the analysis module.  Can specify branches to remove within the keep filter by enabling the remove filter')
    
    parser.add_argument('--debugCode', dest='debugCode', default=False, action='store_true', help='Place debugging statements in the written code')
    
    return parser.parse_args()

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
    
    print 'Getting list of input files from eos'
    input_files = []
    for top, dirs, files in walk_eos(filesDir) :
        for f in files :
            if f.count(filekey) > 0 :
                input_files.append(top+'/'+f)

    return input_files

#---------------------------------------------------------
def walk_eos(path) :

    dirs, files = parse_eos_dir(path)
    yield path, dirs, files
    if len(dirs) > 0 :
        for dir in dirs :
            for new_path, new_dirs, new_files in walk_eos('%s/%s/' %(path, dir)) :
                yield new_path, new_dirs, new_files

#---------------------------------------------------------
def parse_eos_dir(path, DEBUG=False) :

    # remove leading xrootd for using xrd dirlist
    #res = re.match('/xrootd/(.*)', path)
    #if res is not None :
    #    path = res.group(1)

    directories = []
    files = [] 

    #print "xrd hn.at3f dirlist "+path
    #lines = os.popen("xrd hn.at3f dirlist "+path).readlines()
    #output = str("").join(lines)

    eos = '/afs/cern.ch/project/eos/installation/0.2.22/bin/eos.select'

    # get directory contents
    cmd = [eos, 'ls -l', path+'/']
    #cmd = '%s ls -l %s' %(eos, path)
    result = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0]

    result_lines = result.rstrip('\n').split('\n')

    if len(result_lines) == 0 :
        return directories, files
    for line in result_lines :

        if DEBUG :
            print "Line is"
            print line

        splitline = line.split()

        if len(splitline) != 9 :
            print 'Cannot parse line :'
            print line
            print 'Here is the path'
            print path 
            print 'Here is the full entry'
            print result
            continue

        obj = splitline[8]
        isdir = (splitline[0][0] == 'd')

        if isdir :
            directories.append(obj)
        else :
            files.append(obj)
        
    return directories, files


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
        check = re.match('\w+((?:\[\w+\])*)\s*/(\w)', title) 
        size_leaf = None
        bracketEntry = None
        varId = None
        leafEntry = None
        arrayStr = ''
        size_entries = []
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

        leafEntry += '/%s' %varId

        prop_dic = {'name' : name, 'type' : type, 'totSize' : totSize, 'arrayStr' : arrayStr, 'leafEntry' : leafEntry, 'sizeEntries' : size_entries }

        if is_range :
            # any variable that is a range variable needs to come first
            all_branches.insert(0, prop_dic) 
        else :
            all_branches.append(prop_dic)

    return all_branches


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
        outputDir = options.outputDir + '/' + jobid
        conf_file = '%s/%s_%s.%s' %(outputDir, options.confFileName.split('.')[0], jobid, '.'.join(options.confFileName.split('.')[1:]))
        if not os.path.isdir( outputDir ) :
            os.makedirs( outputDir )
        
        write_config(alg_list, conf_file, options.treeName, outputDir, options.outputFile, [file_split], options.storagePath )
        commands.append( make_exe_command( exe_path, conf_file ) )

    return commands


def get_file_evt_map( input_files, nsplit, treeName ) :

    # first split by the number of files
    nFilesPerSplit = int(math.ceil(float(len(input_files))/nsplit))
    if nFilesPerSplit == 0 :
        nFilesPerSplit = 1
    # split into sub-lists based on the number of jobs.  last job may have fewer files

    split_files = [input_files[i:i+nFilesPerSplit] for i in range(0, len(input_files), nFilesPerSplit)]

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

def write_config( alg_list, filename, treeName, outputDir, outputFile, files_list, storage_path ) :

    cfile = open( filename, 'w')

    # first write header information
    jobid = 0
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

    header_loc = '/'.join(header_file_name.split('/')[0:-1])
    branch_setting = open(source_file_name, 'w')
    branch_setting.write('#include <algorithm>\n')
    branch_setting.write('#include <iostream>\n')
    branch_setting.write('#include "TTree.h"\n')
    branch_setting.write('#include "TChain.h"\n')
    branch_setting.write('#include "%s/BranchInit.h"\n' %header_loc)
    branch_setting.write('#include "%s/BranchDefs.h"\n\n' %header_loc)

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


