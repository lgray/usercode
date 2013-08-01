"""
Interactive script to plot data-MC histograms out of a set of trees.
"""

# Parse command-line options
from argparse import ArgumentParser
p = ArgumentParser()
p.add_argument('--baseDir',      default=None,           dest='baseDir',         help='Path to base directory containing all ntuples')
p.add_argument('--baseDirModel',      default=None,           dest='baseDirModel', help='Path to base directory containing all ntuples for the model')
p.add_argument('--fileName',     default='ntuple.root',  dest='fileName',        help='( Default ntuple.root ) Name of files')
p.add_argument('--treeName',     default='events'     ,  dest='treeName',        help='( Default events ) Name tree in root file')
p.add_argument('--treeNameModel',     default='photons'     ,  dest='treeNameModel',help='( Default photons ) Name tree in root file')
p.add_argument('--samplesConf',  default=None,           dest='samplesConf',     help=('Use alternate sample configuration. '
                                                                                       'Must be a python file that implements the configuration '
                                                                                       'in the same manner as in the main() of this script.  If only '
                                                                                       'the file name is given it is assumed to be in the same directory '
                                                                                       'as this script, if a path is given, use that path' ) )

                                                                                       
p.add_argument('--mcweight',     default=None,  type=float ,        dest='mcweight',         help='Weight to apply to MC samples')
p.add_argument('--outputDir',     default=None,  type=str ,        dest='outputDir',         help='output directory for histograms')

options = p.parse_args()

import sys
import os
import re
import math
import uuid
import copy
import imp
import ROOT

from SampleManager import SampleManager

ROOT.gROOT.SetBatch(False)

samples = None

def main() :

    global samples
    samples = SampleManager(options.baseDir, options.mcweight, options.treeName, options.treeNameModel, options.fileName, base_path_model=options.baseDirModel)


    if options.samplesConf is not None :

        samples.ReadSamples( options.samplesConf )

    else :

        #
        # Add default samples
        #

        samples.AddSample('Data',
                          path=['Data',],
                          isData    = True,
                         )

        samples.AddSample('Z+jets',
                          path=['DrellYanZll','DrellYanZtautau'],
                          #path=['ZJets'],
                          #path=['ZJetsMerged'],
                          #scale=2.54345,
                          plotColor = ROOT.kCyan,
                          #scale = 1.07565,
                         )

        samples.AddSample('Nominal',
                          path=['DrellYanZll','DrellYanZtautau'],
                          plotColor = ROOT.kCyan,
                          disableDraw=True,

                          #scale = 1.07565,
                         )

        # for comparison
        #samples.AddSample('Single Photon Model',
        #                  path=['DrellYanZll','DrellYanZtautau'],
        #                  #path=['ZJets'],
        #                  #path=['ZJetsMerged'],
        #                  #scale=2.54345,
        #                  plotColor = ROOT.kBlue,
        #                  #scale = 1.136,
        #                 )

        samples.AddSample('Top',
                          path=['TTBar','SingleTop'],
                          plotColor = ROOT.kGreen,
                          scale=1.0,
                         )
        #samples.AddSample('WGamma',
        #                  path='WgammaFiltered',
        #                  plotColor = ROOT.kRed
        #                 )

        #samples.AddSample('ZllGamma',
        #                  path=['Zeegamma', 'Zmumugamma'],
        #                  #path=['ZllGamma'],
        #                  plotColor = ROOT.kRed+5
        #                 )

        samples.AddSample('WZ',
                          path='WZ',
                          plotColor = ROOT.kWhite,
                         )

        samples.AddSample('WW',
                          path='WW',
                          plotColor = ROOT.kRed,
                         )

        samples.AddSample('W+jets',
                          path=['Wenu','Wmunu'],
                          #path=['WJets'],
                          plotColor = ROOT.kBlue
                         )

        samples.AddSample('ZZ2l2nu',
                          #path='ZZllnunuMCAtNLO',
                          path='ZZllnunu',
                          plotColor = ROOT.kMagenta
                         )

        #samples.AddSample('Nominal Z+jets', 
        #                  path=['DrellYanZll','DrellYanZtautau', 'TTBar','SingleTop', 'WZ', 'WW', 'Wenu', 'Wmunu', 'ZZllnunuMCAtNLO'],
        #                  isSignal=True,
        #                  drawRatio=True,
        #                  plotColor=ROOT.kRed,
        #                  #scale = 1.07565,
        #                  #scale=1.27

        #                )

        #samples.AddSample('ZZ2l2nu',
        #                  path='ZZPowheg',
        #                  plotColor = ROOT.kMagenta
        #                 )

        #samples.AddSample('ZHInv125',
        #                  isSignal = True,
        #                  path='ZHInv125',
        #                  plotColor = ROOT.kRed
        #                 )

        #samples.AddModelTree('Z+jets',
        #                  path='GammaJetModel',
        #                  treename='photons',
        #                  legend_name='Z+jets (data-driven)',
        #                  #scale=0.001990889,
        #                  #scale = 1.07565,
        #                  #scale=1.05676,
        #                  plotColor = ROOT.kCyan,
        #    )
        #samples.AddModelHist('Z+jets',
        #                  path='GammaJetModel',
        #                  plotColor = ROOT.kBlue,
        #                  #scale=1.125135525,
        #                  #scale=0.87818629,
        #                  scale=1.343165222,
        #                  #scale=1.0,
        #                 )

        #samples.AddModelHist('Z+jets',
        #                  path='GammaJetModel',
        #                  plotColor = ROOT.kBlue,
        #                  scale=0.0035,
        #                  #scale=1.0,
        #                 )


        #samples.AddSample('DrellYanPythia',
        #                  path='DrellYanPythia',
        #                  plotColor = ROOT.kRed
        #                 )

    print 'Samples ready.\n'  

    print 'The draw syntax follows that of TTree.Draw.  Examples : '
    
    print 'samples.Draw(\'met_et\', \'EventWeight && passcut_ee==1\', \'(300, 0, 300)\'\n'

    print 'The first argument is a branch in the tree to draw'
    print 'The second argument is a set of cuts and/or weights to apply'
    print 'The third argument are the bin limits to use \n'

    print 'To see all available branches do ListBranches()'



#---------------------------------------
def ListBranches( key=None ) :
    """ List all available branches.  If key is provided only show those that match the key """

    global samples

    # grab list from 0th sample.  This may not work in some cases
    for br in samples.samples.values()[0].chain.GetListOfBranches() :
        if key is None :
            print br.GetName()
        else :
            if br.GetName().count(key) :
                print br.GetName()


#---------------------------------------
def SaveStack( filename, canname=None  ) :
    """ Save current plot to filename.  Must supply --outputDir  """

    global samples

    if options.outputDir is None :
        print 'No output directory provided.  Will not save.'
    else :

        if not os.path.isdir( options.outputDir ) :
            print 'Creating directory %s' %options.outputDir
            os.mkdir(options.outputDir)

        histnamepdf = options.outputDir + '/' + filename.split('.')[0]+'.pdf'
        histnameeps = options.outputDir + '/' + filename.split('.')[0]+'.eps'

        if len( samples.curr_canvases ) == 0 :
            print 'No canvases to save'
        elif len( samples.curr_canvases ) == 1  :
            samples.curr_canvases.values()[0].SaveAs(histnamepdf)
            samples.curr_canvases.values()[0].SaveAs(histnameeps)
        else :
            if canname is not None :
                if canname not in samples.curr_canvases :
                    print 'provided can name does not exist'
                else :
                    samples.curr_canvases[canname].SaveAs(histnamepdf)
                    samples.curr_canvases[canname].SaveAs(histnameeps)
                    return

            print 'Multiple canvases available.  Select which to save'
            keys = samples.curr_canvases.keys() 
            for idx, key in enumerate(keys) :
                print '%s (%d)' %(key, idx)
            selidx = int(raw_input('enter number 0 - %d' %( len(keys)-1 )))
            selkey = keys[selidx]
            samples.curr_canvases[selkey].SaveAs(histnamepdf)
            samples.curr_canvases[selkey].SaveAs(histnameeps)

#---------------------------------------
# User functions
#---------------------------------------

#---------------------------------------
def DrawFormatted(varexp, selection, histpars=None ) :
    """ Example wrapper function.   Make a stack and then add some extra goodies """

    global samples

    print 'DrawFormatted histpars ', histpars
    samples.MakeStack(varexp, selection, histpars)

    statuslabel = ROOT.TLatex(0.4, 0.8, 'Atlas Internal')
    statuslabel.SetNDC()
    luminosity = ROOT.TLatex(0.4, 0.7, ' 10.0 fb^{-1}')
    luminosity.SetNDC()
    samples.add_decoration(statuslabel)
    samples.add_decoration(luminosity)

    samples.DrawCanvas()

    statuslabel.Draw()
    luminosity.Draw()

#---------------------------------------
def DoTAndP( varexp, num_selection, den_selection, sample, histpars=None, binning=[], xlabel=None, ylabel=None, ymin=None, ymax=None, label=None ) :
    global samples

    if not isinstance(sample, list) :
        sample = [sample]

    num_hists = {}
    den_hists = {}

    for idx, samp in enumerate(sample) :
        use_stored_first = False
        if idx > 0 :
            use_stored_first = True

        samples.MakeSameCanvas([samp], varexp, num_selection, histpars, doratio=False, xlabel=xlabel, ylabel=ylabel, useStoredBinning=use_stored_first )
        num_hists[samp] = samples.samples[samp+'0'].hist.Clone('%s_TAndP_num' %samp)
        samples.MakeSameCanvas([samp], varexp, den_selection, histpars, doratio=False, xlabel=xlabel, ylabel=ylabel, useStoredBinning=True)
        den_hists[samp] = samples.samples[samp+'0'].hist.Clone('%s_TAndP_den' %samp)
        
        samples.curr_ratios[samp] = num_hists[samp].Clone('%s_ratio' %samp)
        if xlabel is not None :
            samples.curr_ratios[samp].GetXaxis().SetTitle( xlabel )
            samples.curr_ratios[samp].GetXaxis().SetTitleSize( 0.05 )
            samples.curr_ratios[samp].GetXaxis().SetTitleOffset( 1.1 )
        if ylabel is not None :
            samples.curr_ratios[samp].GetYaxis().SetTitle( ylabel )
            samples.curr_ratios[samp].GetYaxis().SetTitleSize( 0.05 )
            samples.curr_ratios[samp].GetYaxis().SetTitleOffset( 1.25 )
        samples.curr_ratios[samp].Divide(den_hists[samp])

    plot_ymax = 0.0
    plot_ymin = 100.0
    for ratio in samples.curr_ratios.values() :
        max = ratio.GetMaximum()
        min = ratio.GetMinimum()
        if max > plot_ymax :
            plot_ymax = max
        if min < plot_ymin :
            plot_ymin = min
    if ymin is not None :
        plot_ymin = ymin
    else :
        plot_ymin *= 0.9
    if ymax is not None :
        plot_ymax = ymax
    else :
        plot_ymax *= 1.1


    for ratio in samples.curr_ratios.values() :
        ratio.GetYaxis().SetRangeUser( plot_ymin, plot_ymax )

    samples.curr_canvases['ratiocan'] = ROOT.TCanvas( 'ratiocan', 'ratiocan' )
    samples.curr_canvases['ratiocan'].SetBottomMargin(0.13)
    samples.curr_canvases['ratiocan'].SetLeftMargin(0.13)

    for idx, ratio in enumerate( samples.curr_ratios.values() ) :
        drawcmd = ''
        if idx > 0 :
            drawcmd = 'same'
        ratio.Draw(drawcmd)

    leg_xmin = 0.6
    leg_xmax = 0.8
    leg_ymin = 0.68
    leg_ymax = 0.88

    if varexp.count('eta') :
        leg_xmin -= 0.2
        leg_xmax -= 0.2
        leg_ymin -= 0.1
        leg_ymax -= 0.1

    leg = ROOT.TLegend( leg_xmin, leg_ymin, leg_xmax,  leg_ymax)
    leg.SetBorderSize(0)
    leg.SetFillColor(ROOT.kWhite)

    for name in sample :
        ratio = samples.curr_ratios[name]
        leg.AddEntry( ratio, name, 'LPE' )

    samples.curr_canvases['ratiocan'].cd()
    leg.Draw()
    samples.curr_legend = leg

    if label is not None :
        lab = ROOT.TLatex()
        lab.SetNDC()

        lab.SetText( 0.2, 0.83, label )
        lab.SetTextFont(42)

        lab.Draw()

        if varexp.count('eta') :
            xsize = lab.GetXsize()
            newxmin = 0.5-( xsize/2 )
            lab.SetX(newxmin)
        samples.curr_decorations .append(lab)

def WriteCurrentHists( filename='hist.root') :
    """ write all histograms in samples to a root file """

    file = ROOT.TFile.Open( filename, 'RECREATE')

    for hist, samp in samples.samples.iteritems() :
        newhist = samp.hist.Clone(hist)
        file.cd()
        newhist.Write()

    file.Close()
        
#---------------------------------------
def MakeTAndPPlots( ) :

    if options.outputDir is None :
        print 'Must provide an output directory via --outputDir.  Will not make plots'
        return
    
    DoTAndP( 'probe_pt', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==0 && passcut_mll )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll )',  ['DataMCSubtracted', 'Z + Jets'], (60, 0, 300, 250 ), xlabel='Electron p_{T} [GeV]', ylabel='Electron to photon fake factor', ymin=0.01, ymax=0.022, label='unconverted photons' )
    SaveStack('probe_pt_electron_to_photon_ff_mcsub_0conv', 'ratiocan')

    DoTAndP( 'probe_pt', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==2 && passcut_mll )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll )',  ['DataMCSubtracted', 'Z + Jets'], (60, 0, 300, 250 ), xlabel='Electron p_{T} [GeV]', ylabel='Electron to photon fake factor', ymin=0.006, ymax=0.018, label='2 track conversion photons' )
    SaveStack('probe_pt_electron_to_photon_ff_mcsub_2conv', 'ratiocan')
    
    DoTAndP( 'probe_eta', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==0 && passcut_mll )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll )',  ['DataMCSubtracted', 'Z + Jets'], (50, -2.5, 2.5 ), xlabel='Electron #eta', ylabel='Electron to photon fake factor', ymin=0.005, ymax=0.042, label='unconverted photons' )
    SaveStack('probe_eta_electron_to_photon_ff_mcsub_0conv', 'ratiocan')

    DoTAndP( 'probe_eta', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==2 && passcut_mll )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll )',  ['DataMCSubtracted', 'Z + Jets'], (50, -2.5, 2.5 ), xlabel='Electron #eta', ylabel='Electron to photon fake factor', label='2 track conversion photons' )
    SaveStack('probe_eta_electron_to_photon_ff_mcsub_2conv', 'ratiocan')


    DoTAndP( 'probe_pt', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==0 && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50  )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll  && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50)',  ['DataMCSubtracted', 'Z + Jets'], (60, 0, 300, 250 ), xlabel='Electron p_{T} [GeV]', ylabel='Electron to photon fake factor', ymin=0.01, ymax=0.022, label='unconverted photons' )
    SaveStack('probe_pt_electron_to_photon_ff_mtcut_mcsub_0conv', 'ratiocan')

    DoTAndP( 'probe_pt', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==2 && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50 )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50 )',  ['DataMCSubtracted', 'Z + Jets'], (60, 0, 300, 250 ), xlabel='Electron p_{T} [GeV]', ylabel='Electron to photon fake factor', ymin=0.006, ymax=0.018, label='2 track conversion photons' )
    SaveStack('probe_pt_electron_to_photon_ff_mtcut_mcsub_2conv', 'ratiocan')
    
    DoTAndP( 'probe_eta', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==0 && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50 )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50 )',  ['DataMCSubtracted', 'Z + Jets'], (50, -2.5, 2.5 ), xlabel='Electron #eta', ylabel='Electron to photon fake factor', ymin=0.005, ymax=0.042, label='unconverted photons' )
    SaveStack('probe_eta_electron_to_photon_ff_mtcut_mcsub_0conv', 'ratiocan')

    DoTAndP( 'probe_eta', 'EventWeight * ( probe_passTight && probe_isPhot && probe_nConvTrk==2 && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50 )', 'EventWeight * ( tag_isElec && !probe_isPhot && passcut_mll && sqrt(2*met_et*tag_pt*( 1 - cos( met_phi-tag_phi) ) ) < 50 )',  ['DataMCSubtracted', 'Z + Jets'], (50, -2.5, 2.5 ), xlabel='Electron #eta', ylabel='Electron to photon fake factor', label='2 track conversion photons' )
    SaveStack('probe_eta_electron_to_photon_ff_mtcut_mcsub_2conv', 'ratiocan')



#---------------------------------------
def MakeZHCutFlowTables( channel='EE' ) :

    global samples

    cut_flow = ['']
    if channel == 'EE' :
        cut_base = 'EventWeight * ( passtrig_electron %s)'
        cut_flow.append('IsEE')
    if channel == 'MM' :
        cut_base = 'EventWeight * ( passtrig_muon %s)'
        cut_flow.append('IsMM')

    cut_flow += ['passcut_os', 'passcut_thirdlepveto', 'passcut_mll', 'passcut_met', 'passcut_dphill', 'passcut_ll_dphi_met', 'passcut_fracdiff', 'passcut_met_dphi_trackmet', 'passcut_jetveto']

    cut_selections = []
    for idx in range(1, len(cut_flow)+1 ) :
        cut_selections.append( cut_base%( ' && '.join(cut_flow[0:idx]) ) )

    print cut_selections
    print len(cut_selections)
    cut_labels = ['Trigger', 'DiLep', 'OS', 'ThirdLep', 'Mll', 'Met', 'DPhill', 'ZMetDphi', 'FracDiff', 'MetTrkDPhi', 'JetVeto']

    samples.MakeCutflowTable('met_et', cut_selections, cut_labels, (50, 0, 5000))
    
#---------------------------------------
def MakeQCDCRPlots() :

    global samples
    if options.outputDir is None :
        print 'Must provide an output directory via --outputDir.  Will not make plots'
        return

    #samples.Draw('ph_corriso_30/1000.0', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0  && ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 && ( !ph_pass_eratio && !ph_pass_fside && !ph_pass_deltae ) ) ', ( 64, -2, 30 ), xlabel='Calorimeter Isolation [GeV]', ylabel='Events / 0.5 GeV', noAtlasLabel=True, doratio=0, logy=True, ymax=1e12, ymin=1 )
    #SaveStack('ph_corriso_30_invertall', 'base')

    samples.Draw('ph_corriso_30/1000.0', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0  && ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 && ( !ph_pass_eratio || !ph_pass_fside || !ph_pass_deltae ) ) ', ( 64, -2, 30 ), xlabel='Calorimeter Isolation [GeV]', ylabel='Events / 0.5 GeV', noAtlasLabel=True, doratio=0, logy=True, ymax=1e13, ymin=1 )
    SaveStack('ph_corriso_30_invertany', 'base')

    samples.Draw('ph_corriso_30/1000.0', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0  && ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 && ( ( !ph_pass_eratio && !ph_pass_fside ) || ( !ph_pass_eratio && !ph_pass_deltae ) || ( !ph_pass_fside && !ph_pass_deltae ) ) )', ( 64, -2, 30 ), xlabel='Calorimeter Isolation [GeV]', ylabel='Events / 0.5 GeV', noAtlasLabel=True, doratio=0, logy=True, ymax=5e12, ymin=1 )
    SaveStack('ph_corriso_30_invertmaj', 'base')

    samples.Draw('ph_pt', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0  && ph_corriso_30 > 10000 && ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 && ( !ph_pass_eratio && !ph_pass_fside && !ph_pass_deltae ) ) ', ( 100, 0, 500, 25 ), xlabel='p_{T} [GeV]', noAtlasLabel=True, doratio=0, logy=True, ymax=1e9, ymin=0.01 )
    SaveStack('ph_pt_invertall_noniso', 'base')

    samples.Draw('ph_corriso_30/1000.0', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0 && ph_corriso_30 > 10000  && ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 && ( !ph_pass_eratio || !ph_pass_fside || !ph_pass_deltae ) ) ', ( 100, 0, 500, 25 ), xlabel='p_{T} [GeV]', noAtlasLabel=True, doratio=0, logy=True, ymax=1e9, ymin=0.01 )
    SaveStack('ph_pt_invertany_noniso', 'base')

    samples.Draw('ph_corriso_30/1000.0', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0 && ph_corriso_30 > 10000  && ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 && ( ( !ph_pass_eratio && !ph_pass_fside ) || ( !ph_pass_eratio && !ph_pass_deltae ) || ( !ph_pass_fside && !ph_pass_deltae ) ) )', ( 100, 0, 500, 25 ), xlabel='p_{T} [GeV]', noAtlasLabel=True, doratio=0, logy=True, ymax=1e9, ymin=0.01 )
    SaveStack('ph_pt_invertmaj_noniso', 'base')

    #samples.Draw('ph_corriso_30/1000.0', 'EventWeight * ( ph_n == 1 && ph_pt > 30.0 && ph_nConvTrk == 0  && ph_pass_tight ) ', ( 64, -2, 30 ), xlabel='Photon Calorimeter Isolation [GeV]', ylabel='Events / 0.5 GeV', noAtlasLabel=True, doratio=0, logy=True, ymax=1e13, ymin=100 )
    #SaveStack('ph_corriso_30_tightnoiso', 'base')


#
# The following is to get the history 
#
import atexit
historyPath = os.path.expanduser("~/.pyhistory")
try:
    import readline
except ImportError:
    print "Module readline not available."
else:
    import rlcompleter
    readline.parse_and_bind("tab: complete")
    if os.path.exists(historyPath):
        readline.read_history_file(historyPath)


# -----------------------------------------------------------------
def save_history(historyPath=historyPath):
    try:
        import readline
    except ImportError:
        print "Module readline not available."
    else:
        readline.write_history_file(historyPath)

atexit.register(save_history)

main()
