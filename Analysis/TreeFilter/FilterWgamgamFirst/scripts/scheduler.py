import os
base_data='/eos/cms/store/group/phys_smp/ggNtuples/data'
base_mc='/eos/cms/store/group/phys_smp/ggNtuples/mc'
base_cmuko='/store/group/phys_egamma/cmkuo'
job_conf = [
          #(base_mc1,'job_summer12_DYJetsToLL',400),
          #(base_mc1,'job_summer12_LNuGG_FSR',15),
          #(base_mc1,'job_summer12_LNuGG_ISR',15),
          #(base_mc1,'job_summer12_WWW',4),
          #(base_mc1,'job_summer12_WWZ',4),
          #(base_mc1,'job_summer12_WZZ',4),
          #(base_mc1,'job_summer12_WZ_2l2q',50),
          #(base_mc1,'job_summer12_WZ_3lnu',30),
          #(base_mc1,'job_summer12_Wg',60),
          #(base_mc1,'job_summer12_ZZZ',4),
          #(base_mc1,'job_summer12_ZZ_2e2mu',20),
          #(base_mc1,'job_summer12_ZZ_2e2tau',10),
          #(base_mc1,'job_summer12_ZZ_2l2q',30),
          #(base_mc1,'job_summer12_ZZ_2mu2tau',10),
          #(base_mc1,'job_summer12_ZZ_4e',20),
          #(base_mc1,'job_summer12_ZZ_4mu',20),
          #(base_mc1,'job_summer12_ZZ_4tau',10),
          #(base_mc1,'job_summer12_Zg',100),
          #(base_mc1,'job_summer12_gjet_pt20to40_doubleEM',100),
          #(base_mc1,'job_summer12_gjet_pt40_doubleEM',100),
          #(base_mc1,'job_summer12_ttW',4),
          #(base_mc1,'job_summer12_ttZ',4),
          #(base_cmuko, 'job_summer12_diphoton_box_25to250' , 10),
          #(base_mc1,'job_summer12_ttjets_1l',200),
          #(base_mc1,'job_summer12_ttjets_2l',200),
          #(base_mc2, 'job_summer12_WJetsToLNu1', 300),
          #(base_mc2, 'job_summer12_WJetsToLNu2', 350),
          #(base_mc2, 'job_summer12_WW_2l2nu', 25),
          #(base_mc2, 'job_summer12_t_s', 4),
          #(base_mc2, 'job_summer12_t_t', 2),
          #(base_mc2, 'job_summer12_t_tW', 8),
          #(base_mc2, 'job_summer12_tbar_s',2),
          #(base_mc2, 'job_summer12_tbar_t', 25),
          #(base_mc2, 'job_summer12_tbar_tW', 8),

          #(base_data, 'job_muon_2012a_Jan22rereco', 50),
          #(base_data, 'job_muon_2012b_Jan22rereco', 100),
          #(base_data, 'job_muon_2012c_Jan22rereco', 200),
          #(base_data, 'job_muon_2012d_Jan22rereco', 200),
          #(base_data, 'job_electron_2012a_Jan22rereco', 100),
          #(base_data, 'job_electron_2012b_Jan22rereco', 200),
          #(base_data, 'job_electron_2012c_Jan2012rereco', 400),
          (base_data, 'job_electron_2012d_Jan22rereco', 400),


]

base_cmd = 'python scripts/filter.py  --files root://eoscms/%(base)s/%(job)s.root  --outputDir /tmp/jkunkle/%(job)s  --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfFilter.py --enableRemoveFilter --nsplit %(nsp)d --storagePath /eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesDec13/%(job)s --confFileName analysis_config_%(job)s.txt --nproc 5 ; python ../../Util/scripts/copy_histograms.py --file root://eoscms/%(base)s/%(job)s.root  --output /eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesDec13/%(job)s'

for base, name, nsp in job_conf :

    command = base_cmd %{ 'base' : base, 'job' : name, 'nsp' : nsp } 
    print command
    os.system( command )
