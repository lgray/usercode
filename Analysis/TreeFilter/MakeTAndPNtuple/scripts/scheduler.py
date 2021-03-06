import os
base = '/afs/cern.ch/work/j/jkunkle/private/CMS/Wgamgam/Output/'


jobs_data = [
        #(base, 'job_1electron_2012b_Jul13rereco_run1'),
        #(base, 'job_1electron_2012b_Jul13rereco_run2'),
        #(base, 'job_1electron_2012c_Aug24rereco'),
        #(base, 'job_1electron_2012c_Dec11rereco'),
        #(base, 'job_1electron_2012c_PRv2_part1'),
        #(base, 'job_1electron_2012c_PRv2_part2'),
        #(base, 'job_1electron_2012c_PRv2_part3'),
        #(base, 'job_1electron_2012d_PRv1_part1'),
        #(base, 'job_1electron_2012d_PRv1_part2'),
        #(base, 'job_electron_2012a_Aug6rereco'),
        #(base, 'job_electron_2012a_Jul13rereco'),
        #(base, 'job_muon_2012a_Aug6rereco'),
        #(base, 'job_muon_2012a_Jul13rereco'),
        #(base, 'job_muon_2012b_Jul13rereco'),
        #(base, 'job_muon_2012c_Aug24rereco'),
        #(base, 'job_muon_2012c_Dec11rereco'),
        #(base, 'job_muon_2012c_PRv2'),
        #(base, 'job_muon_2012c_PRv21'),
        #(base, 'job_muon_2012d_PRv1'),
        #(base, 'job_muon_2012d_PRv11'),
]
jobs_mc = [
        (base, 'job_summer12_DYJetsToLL'),
        #(base, 'job_summer12_LNuGG_FSR'),
        #(base, 'job_summer12_LNuGG_ISR'),
        #(base, 'job_summer12_WJetsToLNu1'),
        #(base, 'job_summer12_WJetsToLNu2'),
        #(base, 'job_summer12_WWW'),
        #(base, 'job_summer12_WWZ'),
        #(base, 'job_summer12_WW_2l2nu'),
        #(base, 'job_summer12_WZZ'),
        #(base, 'job_summer12_WZ_2l2q'),
        #(base, 'job_summer12_WZ_3lnu'),
        #(base, 'job_summer12_Wg'),
        #(base, 'job_summer12_ZZZ'),
        #(base, 'job_summer12_ZZ_2e2mu'),
        #(base, 'job_summer12_ZZ_2e2tau'),
        #(base, 'job_summer12_ZZ_2l2q'),
        #(base, 'job_summer12_ZZ_2mu2tau'),
        #(base, 'job_summer12_ZZ_4e'),
        #(base, 'job_summer12_ZZ_4mu'),
        #(base, 'job_summer12_ZZ_4tau'),
        #(base, 'job_summer12_Zg'),
        #(base, 'job_summer12_gjet_pt20to40_doubleEM'),
        #(base, 'job_summer12_gjet_pt40_doubleEM'),
        #(base, 'job_summer12_t_s'),
        #(base, 'job_summer12_t_t'),
        #(base, 'job_summer12_t_tW'),
        #(base, 'job_summer12_tbar_s'),
        #(base, 'job_summer12_tbar_t'),
        #(base, 'job_summer12_tbar_tW'),
        #(base, 'job_summer12_ttW'),
        #(base, 'job_summer12_ttZ'),
        #(base, 'job_summer12_ttg'),
        #(base, 'job_summer12_ttjets_1l'),
        #(base, 'job_summer12_ttjets_2l'),

]

second_base = ['DiLepton_2014_01_14', 'LepGamma_2014_01_14']

#module_mc   = 'ConfLepGammaFilter.py'
#module_data = 'ConfLepGammaFilter_Data.py'
output_name = 'TAndP_2014_01_14'

for base, job in jobs_data+jobs_mc :

    input_dirs = []
    for sb in second_base :
        input_dirs.append( '%s/%s/%s' %( base, sb, job ) )
    
    command = 'python scripts/filter.py  --filesDir %s --fileKey tree.root --outputDir /afs/cern.ch/work/j/jkunkle/private/CMS/Wgamgam/Output/%s/%s --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfTAndP.py --nFilesPerJob 5 --nproc 8 --enableRemoveFilter' %( ','.join(input_dirs), output_name, job ) 
    print command
    os.system(command)
    
