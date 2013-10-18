import os
from get_eos_tot_size import get_eos_tot_size

base_mc1='/eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-11'
base_mc2='/eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-05'
base_data='/eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-06'
base_filtered = '/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamples'
job_conf = [
          (base_mc1,'job_summer12_DYJetsToLL'),
          (base_mc1,'job_summer12_LNuGG_FSR'),
          (base_mc1,'job_summer12_LNuGG_ISR'),
          (base_mc1,'job_summer12_WWW'),
          (base_mc1,'job_summer12_WWZ'),
          (base_mc1,'job_summer12_WZZ'),
          (base_mc1,'job_summer12_WZ_2l2q'),
          (base_mc1,'job_summer12_WZ_3lnu'),
          (base_mc1,'job_summer12_Wg'),
          (base_mc1,'job_summer12_ZZZ'),
          (base_mc1,'job_summer12_ZZ_2e2mu'),
          (base_mc1,'job_summer12_ZZ_2e2tau'),
          (base_mc1,'job_summer12_ZZ_2l2q'),
          (base_mc1,'job_summer12_ZZ_2mu2tau'),
          (base_mc1,'job_summer12_ZZ_4e'),
          (base_mc1,'job_summer12_ZZ_4mu'),
          (base_mc1,'job_summer12_ZZ_4tau'),
          (base_mc1,'job_summer12_Zg'),
          (base_mc1,'job_summer12_gjet_pt20to40_doubleEM'),
          (base_mc1,'job_summer12_gjet_pt40_doubleEM'),
          (base_mc1,'job_summer12_ttW'),
          (base_mc1,'job_summer12_ttZ'),
          (base_mc1,'job_summer12_ttjets_1l'),
          (base_mc1,'job_summer12_ttjets_2l'),
          (base_mc2, 'job_summer12_WJetsToLNu1'),
          (base_mc2, 'job_summer12_WJetsToLNu2'),
          (base_mc2, 'job_summer12_WW_2l2nu'),
          (base_mc2, 'job_summer12_t_s'),
          (base_mc2, 'job_summer12_t_t'),
          (base_mc2, 'job_summer12_t_tW'),
          (base_mc2, 'job_summer12_tbar_s'),
          (base_mc2, 'job_summer12_tbar_t'),
          (base_mc2, 'job_summer12_tbar_tW'),
          (base_data, 'job_1electron_2012b_Jul13rereco_run1'),
          (base_data, 'job_1electron_2012b_Jul13rereco_run2'),
          (base_data, 'job_1electron_2012c_Aug24rereco'),
          (base_data, 'job_1electron_2012c_Dec11rereco'),
          (base_data, 'job_1electron_2012c_PRv2_part1'),
          (base_data, 'job_1electron_2012c_PRv2_part2'),
          (base_data, 'job_1electron_2012c_PRv2_part3'),
          (base_data, 'job_1electron_2012d_PRv1_part1'),
          (base_data, 'job_1electron_2012d_PRv1_part2'),
          (base_data, 'job_electron_2012a_Aug6rereco'),
          (base_data, 'job_electron_2012a_Jul13rereco'),
          #(base_data, 'job_muon_2012a_Aug6rereco'),
          #(base_data, 'job_muon_2012a_Jul13rereco'),
          #(base_data, 'job_muon_2012b_Jul13rereco'),
          #(base_data, 'job_muon_2012c_Aug24rereco'),
          #(base_data, 'job_muon_2012c_Dec11rereco'),
          #(base_data, 'job_muon_2012c_PRv2'),
          #(base_data, 'job_muon_2012c_PRv21'),
          #(base_data, 'job_muon_2012d_PRv1'),
          #(base_data, 'job_muon_2012d_PRv11'),


]

for base, file in job_conf :

    size_orig = get_eos_tot_size( '%s/%s.root' %( base, file ) )
    size_filt = get_eos_tot_size( '%s/%s' %( base_filtered, file ) )

    print 'Filter efficiency for %s is %f.  The filtered size is %f Gb' %( file, float(size_filt)/size_orig, float(size_filt)/(1024*1024*1024) ) 


