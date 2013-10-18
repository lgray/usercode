import subprocess 
import os
import sys
#---------------------------------------------------------
def walk_eos(path) :

    dirs, files, sizes = parse_eos_dir(path)
    yield path, dirs, files, sizes
    if len(dirs) > 0 :
        for dir in dirs :
            for new_path, new_dirs, new_files, new_sizes in walk_eos('%s/%s/' %(path, dir)) :
                yield new_path, new_dirs, new_files, new_sizes

#---------------------------------------------------------
def parse_eos_dir(path, DEBUG=False) :

    # remove leading xrootd for using xrd dirlist
    #res = re.match('/xrootd/(.*)', path)
    #if res is not None :
    #    path = res.group(1)

    directories = []
    files = [] 
    sizes = []

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
        size = splitline[4]

        if isdir :
            directories.append(obj)
        else :
            files.append(obj)
            sizes.append( int(size) )
        
    return directories, files, sizes

