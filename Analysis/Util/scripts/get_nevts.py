import ROOT

base = '/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamples/'
job_conf = [
          #'job_summer12_DYJetsToLL',
          #'job_summer12_LNuGG_FSR',
          #'job_summer12_LNuGG_ISR',
          #'job_summer12_WWW',
          #'job_summer12_WWZ',
          #'job_summer12_WZZ',
          #'job_summer12_WZ_2l2q',
          #'job_summer12_WZ_3lnu',
          #'job_summer12_Wg',
          #'job_summer12_ZZZ',
          #'job_summer12_ZZ_2e2mu',
          #'job_summer12_ZZ_2e2tau',
          #'job_summer12_ZZ_2l2q',
          #'job_summer12_ZZ_2mu2tau',
          #'job_summer12_ZZ_4e',
          #'job_summer12_ZZ_4mu',
          #'job_summer12_ZZ_4tau',
          #'job_summer12_Zg',
          #'job_summer12_gjet_pt20to40_doubleEM',
          #'job_summer12_gjet_pt40_doubleEM',
          #'job_summer12_ttW',
          #'job_summer12_ttZ',
          #'job_summer12_ttjets_1l',
          #'job_summer12_ttjets_2l',
          'job_summer12_ttg',
]

for i in job_conf :

    file = ROOT.TFile.Open('root://eoscms.cern.ch/%s/%s/histograms.root' %(base, i))
    hist = file.Get('ggNtuplizer/hEvents')
    nevt = hist.GetBinContent(1)

    print '%s : %d' %( i, nevt )
