
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument( '--files', dest='files', default=None, help='list of files to combine' )
parser.add_argument( '--histName', dest='histName', default=None, help='name of histogram to combine' )


options = parser.parse_args()

import ROOT


add_bins = [3,4,5,6,7,8,9]
#add_bins = [4,6,6,7,8,9,10,11]

def main() :

    flist = options.files.split(',')

    ofiles = []
    for f in flist :
        ofiles.append( ROOT.TFile.Open( f ) )
    hists = []
    for f in ofiles:
        hists.append( f.Get( options.histName ) )

    outhist = hists[0].Clone('cuthist')

    for hist in hists[1:] :
        for bin in add_bins :
            outhist.SetBinContent( bin, hist.GetBinContent(bin) + outhist.GetBinContent( bin) );

    outhist.Draw()
    raw_input('continue')




main() 



