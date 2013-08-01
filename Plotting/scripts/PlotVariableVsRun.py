import sys
import os
import uuid

from argparse import ArgumentParser

parser = ArgumentParser()

parser.add_argument('--baseDir', dest='baseDir', default=None, help='Path to ntuples')
parser.add_argument('--sampleConf',  default=None, dest='sampleConf',     help='Input sample configuration. ')

options = parser.parse_args()

import ROOT
from SampleManager import SampleManager

def main() :


    if options.baseDir is None :
        print 'Must provide a path to files via --baseDir'
        sys.exit(-1)
    if options.sampleConf is None :
        print 'Must provide a configuration via --sampleConf'
        sys.exit(-1)


    
    run_ee_mm_ratio_vs_run()

def run_ee_mm_ratio_vs_run() :

    samples = SampleManager(options.baseDir, 1.0, 'events')
    samples.ReadSamples( options.sampleConf )

    data_chain = samples.samples['Data']
    #all_runs = collect_all_runs(data_chain)
    all_runs = [200842, 200863, 200913, 200926, 200965, 200967, 200982, 200987, 201006, 201052, 201113, 201120, 201138, 201190, 201191, 201257, 201269, 201280, 201289, 201489, 201494, 201555, 201556, 202660, 202668, 202712, 202798, 202965, 202991, 203027, 203169, 203191, 203195, 203228, 203256, 203258, 203277, 203335, 203336, 203353, 203432, 203454, 203456, 203523, 203524, 203602, 203605, 203636, 203680, 203719, 203739, 203745, 203760, 203779, 203792, 203875, 203876, 203934, 204025, 204026, 204071, 204073, 204134, 204153, 204158, 204240, 204265, 204416, 204442, 204474, 204564, 204633, 204668, 204726, 204763, 204769, 204772, 204796, 204853, 204857, 204910, 204932, 204954, 204955, 204976, 205010, 205016, 205017, 205055, 205071, 205112, 205113, 206368, 206369, 206409, 206497, 206573, 206614, 206955, 206962, 206971, 207044, 207046, 207221, 207262, 207304, 207306, 207332, 207397, 207447, 207490, 207528, 207531, 207532, 207582, 207589, 207620, 207664, 207696, 207749, 207772, 207800, 207809, 207845, 207864, 207865, 207931, 207934, 207975, 207982, 208123, 208126, 208179, 208184, 208189, 208258, 208261, 208354, 208485, 208631, 208642, 208662, 208705, 208717, 208720, 208780, 208781, 208811, 208870, 208930, 208931, 208970, 208982, 209025, 209074, 209084, 209109, 209161, 209183, 209214, 209254, 209265, 209269, 209353, 209381, 209550, 209580, 209608, 209628, 209629, 209736, 209776, 209787, 209812, 209864, 209866, 209899, 209980, 209995, 210302, 210308, 211620, 211670, 211697, 211772, 211787, 211867, 211902, 211937, 212034, 212103, 212142, 212144, 212172, 212199, 212272, 212619, 212663, 212687, 212721, 212742, 212809, 212815, 212858, 212967, 212993, 213039, 213079, 213092, 213130, 213155, 213157, 213204, 213250, 213359, 213431, 213479, 213486, 213539, 213627, 213640, 213684, 213695, 213702, 213754, 213796, 213816, 213819, 213900, 213951, 213964, 213968, 214021, 214086, 214160, 214176, 214216, 214388, 214390, 214494, 214523, 214544, 214553, 214618, 214651, 214680, 214714, 214721, 214758, 214777, 215027, 215061, 215063, 215091, 215414, 215433, 215456, 215464, 215473, 215541, 215571, 215589, 215643]

    num_hist_2d = ROOT.TH2F('num2d', 'num2d', (all_runs[-1] - all_runs[0]), all_runs[0], all_runs[-1], 1, 0, 500 )
    den_hist_2d = ROOT.TH2F('den2d', 'den2d', (all_runs[-1] - all_runs[0]), all_runs[0], all_runs[-1], 1, 0, 500 )

    ratio_hist = ROOT.TH1F( 'ratio', 'ratio', (all_runs[-1] - all_runs[0]), all_runs[0], all_runs[-1] )
    num_hist = ROOT.TH1F( 'num','num', (all_runs[-1] - all_runs[0]), all_runs[0], all_runs[-1] )
    den_hist = ROOT.TH1F( 'den','den', (all_runs[-1] - all_runs[0]), all_runs[0], all_runs[-1] )

    data_chain = samples.samples['Data']
    data_chain.chain.Draw('Mll:RunNumber>>den2d', 'passtrig_muon && IsMM && passcut_mll')
    data_chain.chain.Draw('Mll:RunNumber>>num2d', 'passtrig_electron && IsEE && passcut_mll')

    for run in all_runs :

        bin =  ratio_hist.FindBin(run)

        num = num_hist_2d.GetBinContent(num_hist.GetXaxis().FindBin(run), 1)
        den = den_hist_2d.GetBinContent(den_hist.GetXaxis().FindBin(run), 1)

        num_hist.SetBinContent( bin, num )
        den_hist.SetBinContent( bin, den )

        if den != 0 :
            ratio_hist.SetBinContent(bin, num/den )
        else :
            print 'Denominator is zero for run %d' %run

    num_hist.Draw()
    den_hist.Draw('same')

    raw_input('continue')
        
    ratio_hist.Draw()
    raw_input('continue')

def collect_all_runs(chain) :

    nevt = chain.GetEntries()

    all_runs = set()
    chain.SetBranchStatus('*', 0)
    chain.SetBranchStatus('RunNumber', 1)

    print 'Collecting list of run numbers'
    for i in xrange(0, nevt) :
        if i%10000 == 0 :
            print 'Processed %d events' %i

        chain.GetEntry(i)

        all_runs.add( chain.RunNumber )

    all_runs = list(all_runs)

    all_runs.sort()

    print 'Identified %d runs' %len(all_runs)

    chain.SetBranchStatus('*', 1)
    return all_runs





main()



