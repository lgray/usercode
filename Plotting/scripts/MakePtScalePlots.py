"""
Make ratios of histograms
"""

# Parse command-line options
from argparse import ArgumentParser
parser = ArgumentParser()

parser.add_argument('--dil-path', dest='dil_path', default=None, help='Path to dilepton ntuple')
parser.add_argument('--gj-path', dest='gj_path', default=None, help='Path to gammajet ntuple')
parser.add_argument('--outputDir', dest='outputDir', default='PtWeights', help='Name of output directory')
parser.add_argument('--gj-conf',  default=None,           dest='gj_conf',     help=('Input single photon sample configuration. '
                                                                                    'If only '
                                                                                    'the file name is given it is assumed to be in the same directory '
                                                                                    'as this script, if a path is given, use that path' ) )

parser.add_argument('--dil-conf',  default=None,           dest='dil_conf',     help=('Input single dilepton sample configuration. '
                                                                                    'If only '
                                                                                    'the file name is given it is assumed to be in the same directory '
                                                                                    'as this script, if a path is given, use that path' ) )

parser.add_argument('--distribution', default='pt', dest='distribution', help='distribution for which the reweighting is derived' )

parser.add_argument('--normalize', default=False, action='store_true', dest='normalize', help='normalize distributions so that average weight is 1' )

options = parser.parse_args()

import sys
import os
import re
import math
import imp
import ROOT

from SampleManager import SampleManager

#ROOT.gROOT.SetBatch(True)
ROOT.gROOT.SetBatch(False)

def main() :

    if options.dil_conf is None :
        print 'Must provide a dilepton conf via --dil-conf'
        sys.exit(-1)
    if options.gj_conf is None :
        print 'Must provide a photon conf via --gj-conf'
        sys.exit(-1)


    run_tnt(options.dil_path, options.gj_path, options.dil_conf, options.gj_conf)
    #run_caf(options.dil_path, options.gj_path, options.dil_conf, options.gj_conf)
    #run_qcd( options.dil_path, options.gj_path, options.dil_conf, options.gj_conf )
    #run_sp( options.dil_path, options.gj_path, options.dil_conf, options.gj_conf )

def run_tnt(dil_path, gj_path, dil_conf, gj_conf ) :

    samples_dil = SampleManager(options.dil_path, 1.0, 'events')
    samples_gj = SampleManager(options.gj_path, 1.0, 'photons', 'ntuple.root')

    read_samples(samples_dil,options.dil_conf)
    read_samples(samples_gj, options.gj_conf)

    draw_command_dil_ee_incldphi_incljet  = 'EventWeight * ( ( passtrig_electron ) && IsEE && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 )'
    draw_command_dil_mm_incldphi_incljet  = 'EventWeight * ( ( passtrig_muon )     && IsMM && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 )'
    draw_command_dil_ee_cutdphi_incljet   = 'EventWeight * ( ( passtrig_electron ) && IsEE && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 && passcut_dphill )'
    draw_command_dil_mm_cutdphi_incljet   = 'EventWeight * ( ( passtrig_muon )     && IsMM && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 && passcut_dphill )'
    draw_command_dil_ee_incldphi_jetcut  = 'EventWeight * ( ( passtrig_electron ) && IsEE && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 && jet_eta25Pt25_n == 0 )'
    draw_command_dil_mm_incldphi_jetcut  = 'EventWeight * ( ( passtrig_muon )     && IsMM && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 && jet_eta25Pt25_n == 0 )'
    draw_command_dil_ee_cutdphi_jetcut   = 'EventWeight * ( ( passtrig_electron ) && IsEE && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 && jet_eta25Pt25_n == 0 && passcut_dphill )'
    draw_command_dil_mm_cutdphi_jetcut   = 'EventWeight * ( ( passtrig_muon )     && IsMM && passcut_os && passcut_thirdlepveto && passcut_mll && Ptll > 25.0 && jet_eta25Pt25_n == 0 && passcut_dphill )'
    
    
    if options.distribution == 'pt' :
        dil_dist = 'Ptll'
        gj_dist = 'ph_pt'
        
        draw_command_gj_ee_incldphi_incljet = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_ee_incldphi_jetcut = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'
        draw_command_gj_ee_cutdphi_incljet = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_ee_cutdphi_jetcut = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'
        draw_command_gj_mm_incldphi_incljet = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_mm_incldphi_jetcut = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'
        draw_command_gj_mm_cutdphi_incljet = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_mm_cutdphi_jetcut = 'EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'

        binning_incljet = [25, 30, 40, 50, 60, 70, 80, 100, 120, 150, 200, 1000]
        binning_jetcut = [25, 30, 40, 50, 60, 70, 80, 100, 150, 1000]
        binning_dphill_incljet = [25, 30, 35, 40, 45, 50, 55, 60, 70, 80, 100, 120, 150, 200, 1000]
        binning_dphill_jetcut = [25, 30, 35, 40, 45, 50, 55, 60, 70, 80, 100, 150, 1000]
    elif options.distribution == 'll_dphi_met' :
        dil_dist = 'LL_DPhi_Met'
        gj_dist = 'ph_dphi_met'
        
        draw_command_gj_ee_incldphi_incljet = 'EventWeight * PtWeightEE * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_ee_incldphi_jetcut = 'EventWeight * PtWeightEE0J * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'
        draw_command_gj_ee_cutdphi_incljet = 'EventWeight * PtWeightDPhillEE * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_ee_cutdphi_jetcut = 'EventWeight * PtWeightDPhillEE0J * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'
        draw_command_gj_mm_incldphi_incljet = 'EventWeight * PtWeightMM * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_mm_incldphi_jetcut = 'EventWeight * PtWeightMM0J * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'
        draw_command_gj_mm_cutdphi_incljet = 'EventWeight * PtWeightDPhillMM * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
        draw_command_gj_mm_cutdphi_jetcut = 'EventWeight * PtWeightDPhillMM0J * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_eta25Pt25_n == 0 )'

        binning_incljet = [ x*0.01 for x in range( -315, 325, 10 ) ]
        binning_jetcut = [ x*0.01 for x in range( -315, 330, 15 ) ]
        binning_dphill_incljet = [ x*0.01 for x in range( -315, 345, 30 ) ]
        binning_dphill_jetcut = [ x*0.01 for x in range( -315, 345, 30 ) ]


    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_ee_incldphi_incljet, draw_command_gj_ee_incldphi_incljet, binning_incljet, options.outputDir+'/AllJet/EE/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_mm_incldphi_incljet, draw_command_gj_mm_incldphi_incljet, binning_incljet, options.outputDir+'/AllJet/MM/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_ee_cutdphi_incljet , draw_command_gj_ee_cutdphi_incljet, binning_dphill_incljet, options.outputDir+'/DPhill_AllJet/EE/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_mm_cutdphi_incljet , draw_command_gj_mm_cutdphi_incljet, binning_dphill_incljet, options.outputDir+'/DPhill_AllJet/MM/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_ee_incldphi_jetcut, draw_command_gj_ee_incldphi_jetcut, binning_jetcut, options.outputDir+'/NJet0/EE/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_mm_incldphi_jetcut, draw_command_gj_mm_incldphi_jetcut, binning_jetcut, options.outputDir+'/NJet0/MM/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_ee_cutdphi_jetcut , draw_command_gj_ee_cutdphi_jetcut, binning_dphill_jetcut, options.outputDir+'/DPhill_NJet0/EE/hist.root')
    MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_command_dil_mm_cutdphi_jetcut , draw_command_gj_mm_cutdphi_jetcut, binning_dphill_jetcut, options.outputDir+'/DPhill_NJet0/MM/hist.root')

def run_qcd(num_path, den_path, num_conf, den_conf) :

    samples_num = SampleManager(num_path, 1.0, 'photons')
    samples_den = SampleManager(den_path, 1.0, 'photons')

    read_samples(samples_num, num_conf)
    read_samples(samples_den, den_conf)

    draw_command_num_incljet_0conv  = 'EventWeight * ( ph_n == 1 && ph_pt > 25.0 && ph_nConvTrk == 0 && ph_pass_tight && ph_corriso_30 > 10000  )'
    draw_command_num_jetcut_0conv  = 'EventWeight * ( ph_n == 1 && ph_pt > 25.0 && ph_nConvTrk == 0 && ph_pass_tight && jet_n==0 && ph_corriso_30 > 10000  )'
    draw_command_num_incljet_2conv  = 'EventWeight * ( ph_n == 1 && ph_pt > 25.0 && ph_nConvTrk == 2 && ph_pass_tight && ph_corriso_30 > 10000  )'
    draw_command_num_jetcut_2conv  = 'EventWeight * ( ph_n == 1 && ph_pt > 25.0 && ph_nConvTrk == 2 && ph_pass_tight && jet_n==0 && ph_corriso_30 > 10000  )'

    num_dist = 'ph_pt'
    den_dist = 'ph_pt'
        
    draw_command_den_InvAll_incljet_0conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && ph_corriso_30 > 10000 '
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 ' 
                                              '&& ( !ph_pass_eratio && !ph_pass_fside && !ph_pass_deltae ) )')
    draw_command_den_InvAll_jetcut_0conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && ph_corriso_30 > 10000 && jet_n==0 ' 
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                              '&& ( !ph_pass_eratio && !ph_pass_fside && !ph_pass_deltae ))')
    draw_command_den_InvAll_incljet_2conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==2 && ph_corriso_30 > 10000 ' 
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                              '&& ( !ph_pass_eratio && !ph_pass_fside && !ph_pass_deltae ))')
    draw_command_den_InvAll_jetcut_2conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==2 && ph_corriso_30 > 10000 && jet_n==0 '
                                             '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                             '&& ( !ph_pass_eratio && !ph_pass_fside && !ph_pass_deltae ))' )

    draw_command_den_InvAny_incljet_0conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && ph_corriso_30 > 10000 '
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 ' 
                                              '&& ( !ph_pass_eratio || !ph_pass_fside || !ph_pass_deltae ) )')
    draw_command_den_InvAny_jetcut_0conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && ph_corriso_30 > 10000 && jet_n==0 ' 
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                              '&& ( !ph_pass_eratio || !ph_pass_fside || !ph_pass_deltae ))')
    draw_command_den_InvAny_incljet_2conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==2 && ph_corriso_30 > 10000 ' 
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                              '&& ( !ph_pass_eratio || !ph_pass_fside || !ph_pass_deltae ))')
    draw_command_den_InvAny_jetcut_2conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==2 && ph_corriso_30 > 10000 && jet_n==0 '
                                             '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                             '&& ( !ph_pass_eratio || !ph_pass_fside || !ph_pass_deltae ))' )

    draw_command_den_InvMaj_incljet_0conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && ph_corriso_30 > 10000 '
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 ' 
                                              '&& ( (!ph_pass_eratio && !ph_pass_fside) || ( !ph_pass_eratio && !ph_pass_deltae ) || ( !ph_pass_fside && !ph_pass_deltae ) )  )')
    draw_command_den_InvMaj_jetcut_0conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && ph_corriso_30 > 10000 && jet_n==0 ' 
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                              '&& ( (!ph_pass_eratio && !ph_pass_fside) || ( !ph_pass_eratio && !ph_pass_deltae ) || ( !ph_pass_fside && !ph_pass_deltae ) )  )')
    draw_command_den_InvMaj_incljet_2conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==2 && ph_corriso_30 > 10000 ' 
                                              '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                              '&& ( (!ph_pass_eratio && !ph_pass_fside) || ( !ph_pass_eratio && !ph_pass_deltae ) || ( !ph_pass_fside && !ph_pass_deltae ) )  )')
    draw_command_den_InvMaj_jetcut_2conv  = ('EventWeight * ( ph_pt > 25.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==2 && ph_corriso_30 > 10000 && jet_n==0 '
                                             '&& ph_pass_hadleak && ph_pass_middle && ph_pass_middle && ph_pass_wstot && ph_pass_weta1 && ph_pass_ar && ph_pass_demax2 && ph_pass_f1 '
                                             '&& ( (!ph_pass_eratio && !ph_pass_fside) || ( !ph_pass_eratio && !ph_pass_deltae ) || ( !ph_pass_fside && !ph_pass_deltae ) )  )' )

    binning = [25, 35, 45, 55, 65, 75, 85, 105, 125, 150, 175, 200, 250, 300, 400, 1000]

    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_0conv, draw_command_den_InvAll_incljet_0conv, binning, options.outputDir+'/InvAll/AllJet/Conv0/hist.root')
    #MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_jetcut_0conv , draw_command_den_InvAll_jetcut_0conv, binning, options.outputDir+'/InvAll/NJet0/Conv0/hist.root')
    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_2conv, draw_command_den_InvAll_incljet_2conv, binning, options.outputDir+'/InvAll/AllJet/Conv2/hist.root')
    ##MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_jetcut_2conv , draw_command_den_InvAll_jetcut_2conv, binning, options.outputDir+'/InvAll/NJet0/Conv2/hist.root')

    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_0conv, draw_command_den_InvAny_incljet_0conv, binning, options.outputDir+'/InvAny/AllJet/Conv0/hist.root')
    #MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_jetcut_0conv , draw_command_den_InvAny_jetcut_0conv, binning, options.outputDir+'/InvAny/NJet0/Conv0/hist.root')
    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_2conv, draw_command_den_InvAny_incljet_2conv, binning, options.outputDir+'/InvAny/AllJet/Conv2/hist.root')
    #MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_jetcut_2conv , draw_command_den_InvAny_jetcut_2conv, binning, options.outputDir+'/InvAny/NJet0/Conv2/hist.root')

    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_0conv, draw_command_den_InvMaj_incljet_0conv, binning, options.outputDir+'/InvMaj/AllJet/Conv0/hist.root')
    #MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_jetcut_0conv , draw_command_den_InvMaj_jetcut_0conv, binning, options.outputDir+'/InvMaj/NJet0/Conv0/hist.root')
    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_2conv, draw_command_den_InvMaj_incljet_2conv, binning, options.outputDir+'/InvMaj/AllJet/Conv2/hist.root')
    #MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_jetcut_2conv , draw_command_den_InvMaj_jetcut_2conv, binning, options.outputDir+'/InvMaj/NJet0/Conv2/hist.root')

def run_sp(num_path, den_path, num_conf, den_conf) :

    samples_num = SampleManager(num_path, 1.0, 'photons')
    samples_den = SampleManager(den_path, 1.0, 'photons')

    read_samples(samples_num, num_conf)
    read_samples(samples_den, den_conf)

    draw_command_num_incljet_0conv  = 'EventWeight * ( ph_n == 1 && ph_pt > 25.0 && ph_nConvTrk == 0 && ph_pass_tight && ph_corriso_30 < 2000  )'
    draw_command_num_incljet_2conv  = 'EventWeight * ( ph_n == 1 && ph_pt > 25.0 && ph_nConvTrk == 2 && ph_pass_tight && ph_corriso_30 < 2000  )'

    num_dist = 'ph_pt'
    den_dist = 'ph_pt'
        
    binning = [25, 35, 45, 55, 65, 75, 85, 105, 125, 150, 175, 200, 250, 300, 400, 1000]

    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_0conv, draw_command_num_incljet_0conv, binning, options.outputDir+'/AllJet/Conv0/hist.root')
    MakeRatio(samples_num, samples_den, num_dist, den_dist, draw_command_num_incljet_2conv, draw_command_num_incljet_2conv, binning, options.outputDir+'/AllJet/Conv2/hist.root')

def run_caf(dil_path, gj_path, dil_conf, gj_conf ) :

    samples_dil_ee = SampleManager(options.dil_path, 1.0, 'HWWTree_ee')
    samples_dil_mm = SampleManager(options.dil_path, 1.0, 'HWWTree_mm')
    samples_gj = SampleManager(options.gj_path, 1.0, 'photons', filename='ntuple.root')

    read_samples(samples_dil_ee,options.dil_conf)
    read_samples(samples_dil_mm,options.dil_conf)
    read_samples(samples_gj, options.gj_conf)

    draw_command_dil_ee_incldphi_incljet  = 'mcEventWeight * ( isLowPtCand==0 && Mll > 12000 && Mll < 60000 && Ptll > 30 && (lepID0*lepID1==-121) )'
    draw_command_dil_mm_incldphi_incljet  = 'mcEventWeight * ( isLowPtCand==0 && Mll > 12000 && Mll < 60000 && Ptll > 30 &&  (lepID0*lepID1==-169) )'
    draw_command_dil_ee_incldphi_jetcut  = 'mcEventWeight * ( isLowPtCand==0 && Mll > 12000 && Mll < 60000 && Ptll > 30 &&  (lepID0*lepID1==-121) && m_jet_n>1  )'
    draw_command_dil_mm_incldphi_jetcut  = 'mcEventWeight * ( isLowPtCand==0 && Mll > 12000 && Mll < 60000 && Ptll > 30 &&  (lepID0*lepID1==-169) && m_jet_n>1  )'
    
    draw_command_gj_incljet = 'EventWeight * ( ph_pt > 30.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 )'
    draw_command_gj_jetcut = 'EventWeight * ( ph_pt > 30.0 && lep_n == 0 && ph_n==1 && ph_nConvTrk==0 && jet_n > 1 )'
    
    dil_dist = 'Ptll'
    gj_dist = 'ph_pt'
    
    binning_incljet = range(30, 80) + [80, 85, 90, 95, 100, 110, 120, 130, 150, 200, 300, 500, 1000]
    binning_jetcut = range(30, 80) + [80, 85, 90, 95, 100, 110, 120, 130, 150, 200, 300, 500, 1000]


    MakeRatio(samples_dil_ee, samples_gj, dil_dist, gj_dist, draw_command_dil_ee_incldphi_incljet, draw_command_gj_incljet, binning_incljet, options.outputDir+'/AllJet/EE/hist.root')

    MakeRatio(samples_dil_mm, samples_gj, dil_dist, gj_dist, draw_command_dil_mm_incldphi_incljet, draw_command_gj_incljet, binning_incljet, options.outputDir+'/AllJet/MM/hist.root')

    MakeRatio(samples_dil_ee, samples_gj, dil_dist, gj_dist, draw_command_dil_ee_incldphi_jetcut, draw_command_gj_jetcut, binning_jetcut, options.outputDir+'/NJet2/EE/hist.root')

    MakeRatio(samples_dil_mm, samples_gj, dil_dist, gj_dist, draw_command_dil_mm_incldphi_jetcut, draw_command_gj_jetcut, binning_jetcut, options.outputDir+'/NJet2/MM/hist.root')


def MakeRatio(samples_dil, samples_gj, dil_dist, gj_dist, draw_dil, draw_gj, binning, output) :

    
    if options.distribution == 'pt'  :
        range_min = 0
        range_max = 1000
        nbins = 1000
    elif options.distribution == 'll_dphi_met'  :
        range_min = -3.15
        range_max = 3.15
        nbins = 630

    samples_dil.CompareSelections(dil_dist, [draw_dil], ['Numerator'], (nbins,   range_min, range_max))
    samples_gj.CompareSelections(gj_dist, [draw_gj], ['Denominator'], (nbins, range_min, range_max))

    hist_dil = samples_dil.samples['Numerator'].hist
    hist_gj = samples_gj.samples['Denominator'].hist
    ratiohist = ROOT.TH1F(options.distribution, options.distribution, nbins, range_min, range_max)

    integral_num_tot = hist_dil.Integral()
    integral_den_tot = hist_gj.Integral()
    for idx, max_bin in enumerate(binning[1:]) :
        min_bin = binning[idx]

        integral_num = hist_dil.Integral( hist_dil.FindBin(min_bin), hist_dil.FindBin(max_bin) )
        integral_den = hist_gj .Integral( hist_gj .FindBin(min_bin), hist_gj .FindBin(max_bin) )
        
        if integral_den == 0 :
            print 'Denominator integral is 0 for %f, %f' %(min_bin, max_bin)
            continue
        if options.normalize :
            if integral_num_tot > 0 :
                integral_num = integral_num / integral_num_tot
            else :
                print 'Total integral is zero!'

            if integral_den_tot > 0 :
                integral_den = integral_den / integral_den_tot
            else :
                print 'Total integral is zero!'

        #print 'numerator, denominator = %f, %f' %(integral_num, integral_den)

        for bin in range(1, 1001) :
            thisbin = ratiohist.GetBinLowEdge(bin) 
            if thisbin >= min_bin and thisbin < max_bin :
                ratiohist.SetBinContent(bin, integral_num/integral_den)

    base =os.path.dirname(output) 
    if not os.path.isdir(base) :
        os.system('mkdir -p %s' %base)
    
    ofile = ROOT.TFile(output, 'RECREATE')
    ratiohist.Write()
    ofile.Close()
    print 'Write %s' %output

def read_samples(samples, conf) :

    ImportedModule=None

    ispath = ( conf.count('/') > 0 )
    module_path = None
    if ispath :
        module_path = conf
    else :
        #get path of this script
        script_path = os.path.realpath(__file__)
        module_path = os.path.dirname(script_path) + '/' + conf

    try :
        ImportedModule = imp.load_source(conf.split('.')[0], module_path)
    except IOError :
        print 'Could not import module %s' %module_path
    
    if hasattr(ImportedModule, 'config_samples') :
        ImportedModule.config_samples(samples)
    else :
        print 'ERROR - samplesConf does not implement a function called config_samples '
        sys.exit(-1)


    
main()
