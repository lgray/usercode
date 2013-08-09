import os
import re
import sys
import imp
from argparse import ArgumentParser
def ParseArgs() :

    parser = ArgumentParser(description='')
    
    parser.add_argument('--files', dest='files', default=None, help='list of input files (comma separated).  If not provided, --filesDir must be provided')
    
    parser.add_argument('--filesDir', dest='filesDir', default=None, help='Directory to search for files.  If not provided, --files must be provided')
    
    parser.add_argument('--outputDir', dest='outputDir', default=None, help='<Required> Output sample path.  If nproc is set to > 1 a job directory is appended')
    
    parser.add_argument('--outputFile', dest='outputFile', default=None, help='Name of output file.  If none given it will assume the name of one if the input files')
    
    parser.add_argument('--treeName', dest='treeName', default=None, help='<Required> name of tree to process')
    
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
    for top, dirs, files in os.walk(filesDir) :
        for f in files :
            if f.count(filekey) != -1 :
                input_files.append(top+'/'+f)

    return input_files

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

