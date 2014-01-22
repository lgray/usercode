import os
base_data='/eos/cms/store/group/phys_smp/ggNtuples/data'
base_mc='/eos/cms/store/group/phys_smp/ggNtuples/mc'
base_cmkuo='/eos/cms/store/group/phys_egamma/cmkuo'
job_conf = [
          #(base_mc,'job_summer12_DYJetsToLL',400),
          ##(base_cmkuo, 'job_summer12_WAA_ISR', 20),
          #(base_cmkuo, 'job_summer12_WH_ZH_125', 10),
          #(base_cmkuo, 'job_summer12_WWW', 10),
          #(base_cmkuo, 'job_summer12_WWZ', 10),
          #(base_cmkuo, 'job_summer12_WW_2l2nu', 20),
          #(base_cmkuo, 'job_summer12_WWg', 10),
          #(base_cmkuo, 'job_summer12_WZZ', 10),
          #(base_cmkuo, 'job_summer12_WZ_2l2q', 20),
          #(base_cmkuo, 'job_summer12_WZ_3lnu', 20),
          #(base_cmkuo, 'job_summer12_Wg', 100),
          #(base_cmkuo, 'job_summer12_Wgg_FSR', 20),
          #(base_cmkuo, 'job_summer12_ZZZ', 10),
          #(base_cmkuo, 'job_summer12_ZZ_2e2mu', 10),
          #(base_cmkuo, 'job_summer12_ZZ_2e2tau', 10),
          #(base_cmkuo, 'job_summer12_ZZ_2l2nu', 10),
          #(base_cmkuo, 'job_summer12_ZZ_2l2q', 10),
          #(base_cmkuo, 'job_summer12_ZZ_2mu2tau', 10),
          #(base_cmkuo, 'job_summer12_ZZ_2q2nu', 10),
          #(base_cmkuo, 'job_summer12_ZZ_4e', 10),
          #(base_cmkuo, 'job_summer12_ZZ_4mu', 10),
          #(base_cmkuo, 'job_summer12_ZZ_4tau', 10),
          #(base_cmkuo, 'job_summer12_Zg', 100),
          #(base_cmkuo, 'job_summer12_diphoton_box_10to25', 10),
          #(base_cmkuo, 'job_summer12_diphoton_box_250toInf', 10),
          #(base_cmkuo, 'job_summer12_diphoton_box_25to250', 10),
          #(base_cmkuo, 'job_summer12_ggH_125', 10),
          #(base_cmkuo, 'job_summer12_ggZZ_2l2l', 10),
          #(base_cmkuo, 'job_summer12_ggZZ_4l', 10),
          #(base_cmkuo, 'job_summer12_t_s', 10),
          #(base_cmkuo, 'job_summer12_t_t', 10),
          #(base_cmkuo, 'job_summer12_t_tW', 10),
          #(base_cmkuo, 'job_summer12_tbar_s', 10),
          #(base_cmkuo, 'job_summer12_tbar_t', 10),
          #(base_cmkuo, 'job_summer12_tbar_tW', 50),
          (base_cmkuo, 'job_summer12_ttW', 10),
          #(base_cmkuo, 'job_summer12_ttZ', 10),
          #(base_cmkuo, 'job_summer12_ttg', 50),
          #(base_cmkuo, 'job_summer12_ttinclusive', 10),
          #(base_cmkuo, 'job_summer12_Wjets', 400),
          #(base_cmkuo, 'job_summer12_ttjets_1l', 200),
          #(base_cmkuo, 'job_summer12_ttjets_2l', 200),

          #(base_data, 'job_muon_2012a_Jan22rereco', 50),
          #(base_data, 'job_muon_2012b_Jan22rereco', 100),
          #(base_data, 'job_muon_2012c_Jan22rereco', 200),
          #(base_data, 'job_muon_2012d_Jan22rereco', 200),
          #(base_data, 'job_electron_2012a_Jan22rereco', 100),
          #(base_data, 'job_electron_2012b_Jan22rereco', 200),
          #(base_data, 'job_electron_2012c_Jan2012rereco', 400),
          #(base_data, 'job_electron_2012d_Jan22rereco', 400),


]

base_cmd = 'python scripts/filter.py  --files root://eoscms/%(base)s/%(job)s.root  --outputDir /tmp/jkunkle/%(job)s  --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfFilter.py --enableRemoveFilter --nsplit %(nsp)d --storagePath /eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesJan14/%(job)s --confFileName analysis_config_%(job)s.txt --nproc 5 --exeName RunAnalysis ; python ../../Util/scripts/copy_histograms.py --file root://eoscms/%(base)s/%(job)s.root  --output /eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesJan14/%(job)s'

for base, name, nsp in job_conf :

    command = base_cmd %{ 'base' : base, 'job' : name, 'nsp' : nsp } 
    print command
    os.system( command )
