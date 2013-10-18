
from argparse import ArgumentParser

import eos_utilities as eosutil
import ROOT



def main() :

    parser = ArgumentParser()
    
    parser.add_argument('--originalDS', dest='originalDS', default=None, required=True,help='Path to original dataset')
    parser.add_argument('--filteredDS', dest='filteredDS', default=None, required=True,help='Path to filtered dataset')
    parser.add_argument('--treeName',   dest='treeName',   default=None, required=True, help='Name of tree (assume same in both orignal and filtered)')
    parser.add_argument('--fileKeyOrig', dest='fileKeyOrig', default=None, help='key to match orginal files' )
    parser.add_argument('--fileKeyFilt', dest='fileKeyFilt', default=None, help='key to match filtered files' )
    
    options = parser.parse_args()

    orig_nevt, filt_nevt = check_dataset_completion( options.originalDS, options.filteredDS, options.treeName, options.fileKeyOrig, options.fileKeyFilt )

    print '%s : Orignal = %d events, filtered = %d events.  Difference = %d' %( options.filteredDS, orig_nevt, filt_nevt, orig_nevt-filt_nevt)

def check_dataset_completion( originalDS, filteredDS, treeName, fileKeyOrig=None, fileKeyFilt=None ) :

    orig_nevt = 0
    filt_nevt = 0
    for top, dirs, files, sizes in eosutil.walk_eos( originalDS ) :
        for file in files :

            if fileKeyOrig is not None and not file.count(fileKeyOrig) : continue

            ofile = ROOT.TFile.Open( top+'/'+file )
            otree = ofile.Get(treeName)
            orig_nevt += otree.GetEntries()

    if not orig_nevt :
        print 'Did not get any original events.  Check the path'
        return
        

    for top, dirs, files, sizes in eosutil.walk_eos( filteredDS ) :
        for file in files :

            if fileKeyFilt is not None and not file.count(fileKeyFilt) : continue

            ofile = ROOT.TFile.Open( top+'/'+file )
            ohist = ofile.Get('filter')
            filt_nevt += ohist.GetBinContent(1)

    return orig_nevt, filt_nevt



if __name__ == '__main__' :
    main()

