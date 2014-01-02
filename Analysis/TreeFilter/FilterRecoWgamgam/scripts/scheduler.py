import os

base_mc = '/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamples/'
base_ele = '/eos/cms/store/user/abelloni/Wgamgam/FilteredSamples/'
base_muon = '/eos/cms/store/user/abelloni/Wgamgam/FilteredSamples/'

jobs = [
        #(base_muon, 'job_muon_2012a_Aug6rereco'),
        #(base_muon, 'job_muon_2012a_Jul13rereco'),
        #(base_muon, 'job_muon_2012b_Jul13rereco'),
        #(base_muon, 'job_muon_2012c_Aug24rereco'),
        #(base_muon, 'job_muon_2012c_Dec11rereco'),
        #(base_muon, 'job_muon_2012c_PRv2'),
        #(base_muon, 'job_muon_2012c_PRv21'),
        #(base_muon, 'job_muon_2012d_PRv1'),
        #(base_muon, 'job_muon_2012d_PRv11'),
        #(base_ele, 'job_1electron_2012b_Jul13rereco_run1'),
        #(base_ele, 'job_1electron_2012b_Jul13rereco_run2'),
        #(base_ele, 'job_1electron_2012c_Aug24rereco'),
        #(base_ele, 'job_1electron_2012c_Dec11rereco'),
        #(base_ele, 'job_1electron_2012c_PRv2_part1'),
        #(base_ele, 'job_1electron_2012c_PRv2_part2'),
        #(base_ele, 'job_1electron_2012c_PRv2_part3'),
        #(base_ele, 'job_1electron_2012d_PRv1_part1'),
        #(base_ele, 'job_1electron_2012d_PRv1_part2'),
        #(base_ele, 'job_electron_2012a_Aug6rereco'),
        #(base_ele, 'job_electron_2012a_Jul13rereco'),
        (base_mc, 'job_summer12_DYJetsToLL'),
        #(base_mc, 'job_summer12_LNuGG_FSR'),
        #(base_mc, 'job_summer12_LNuGG_ISR'),
        #(base_mc, 'job_summer12_WJetsToLNu1'),
        #(base_mc, 'job_summer12_WJetsToLNu2'),
        #(base_mc, 'job_summer12_WWW'),
        #(base_mc, 'job_summer12_WWZ'),
        #(base_mc, 'job_summer12_WW_2l2nu'),
        #(base_mc, 'job_summer12_WZZ'),
        #(base_mc, 'job_summer12_WZ_2l2q'),
        #(base_mc, 'job_summer12_WZ_3lnu'),
        #(base_mc, 'job_summer12_Wg'),
        #(base_mc, 'job_summer12_ZZZ'),
        #(base_mc, 'job_summer12_ZZ_2e2mu'),
        #(base_mc, 'job_summer12_ZZ_2e2tau'),
        #(base_mc, 'job_summer12_ZZ_2l2q'),
        #(base_mc, 'job_summer12_ZZ_2mu2tau'),
        #(base_mc, 'job_summer12_ZZ_4e'),
        #(base_mc, 'job_summer12_ZZ_4mu'),
        #(base_mc, 'job_summer12_ZZ_4tau'),
        #(base_mc, 'job_summer12_Zg'),
        #(base_mc, 'job_summer12_gjet_pt20to40_doubleEM'),
        #(base_mc, 'job_summer12_gjet_pt40_doubleEM'),
        #(base_mc, 'job_summer12_t_s'),
        #(base_mc, 'job_summer12_t_t'),
        #(base_mc, 'job_summer12_t_tW'),
        #(base_mc, 'job_summer12_tbar_s'),
        #(base_mc, 'job_summer12_tbar_t'),
        #(base_mc, 'job_summer12_tbar_tW'),
        #(base_mc, 'job_summer12_ttW'),
        #(base_mc, 'job_summer12_ttZ'),
        #(base_mc, 'job_summer12_ttg'),
        #(base_mc, 'job_summer12_ttjets_1l'),
        #(base_mc, 'job_summer12_ttjets_2l'),

]

for base, job in jobs :
    command = 'python scripts/filter.py  --filesDir root://eoscms/%s/%s/ --fileKey tree.root --outputDir /tmp/jkunkle/RecoOutputOld_2013_12_26/%s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfWgamgamReco.py --enableKeepFilter --nFilesPerJob 5 --storagePath /eos/cms/store/user/jkunkle/Wgamgam/RecoOutputOld_2013_12_26/%s --nproc 8 --confFileName %s ' %( base, job, job, job, job ) 
    print command
    os.system(command)
