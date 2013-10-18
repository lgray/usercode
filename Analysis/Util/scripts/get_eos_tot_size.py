
import eos_utilities as eosutil


def main() :
    from argparse import ArgumentParser
    parser = ArgumentParser()
    parser.add_argument('--dir', dest='dir', default=None, required=True, help='Base directory for which the total size is computed' )
    options = parser.parse_args()

    tot_size = get_eos_tot_size( options.dir )

    conv_size = tot_size/(1024*1024*1024.0)
    print 'Size for %s is %f Gb' %( options.dir, conv_size )

def get_eos_tot_size( dir ) :

    tot_size = 0
    for top, dirs, files, sizes in eosutil.walk_eos( dir ) :
        for size in sizes :
            tot_size += size

    return tot_size
    

if __name__ == '__main__' :
    main()
