import os
base_mc1='/eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-11'
base_mc2='/eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-05'
base_data='/eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-06'
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

          #(base_data, 'job_1electron_2012b_Jul13rereco_run1', 450),
          #(base_data, 'job_1electron_2012b_Jul13rereco_run2', 20),
          #(base_data, 'job_1electron_2012c_Aug24rereco', 50),
          #(base_data, 'job_1electron_2012c_Dec11rereco', 20),
          # RERUN SOME
          #(base_data, 'job_1electron_2012c_PRv2_part1', 250),
          # RERUN SOME
          (base_data, 'job_1electron_2012c_PRv2_part2', 450),
          (base_data, 'job_1electron_2012c_PRv2_part3', 2),
          (base_data, 'job_1electron_2012d_PRv1_part1', 300),
          (base_data, 'job_1electron_2012d_PRv1_part2', 500),
          (base_data, 'job_electron_2012a_Aug6rereco',  10),
          (base_data, 'job_electron_2012a_Jul13rereco', 100),
          #(base_data, 'job_muon_2012a_Aug6rereco', 5),
          #(base_data, 'job_muon_2012a_Jul13rereco', 40),
          #(base_data, 'job_muon_2012b_Jul13rereco', 300),
          #(base_data, 'job_muon_2012c_Aug24rereco', 30),
          #(base_data, 'job_muon_2012c_Dec11rereco', 10),
          #(base_data, 'job_muon_2012c_PRv2', 150),
          #(base_data, 'job_muon_2012c_PRv21', 250),
          #(base_data, 'job_muon_2012d_PRv1', 200),
          #(base_data, 'job_muon_2012d_PRv11', 300),


]

base_cmd = 'python scripts/filter.py  --files root://eoscms/%s/%s.root  --outputDir /tmp/jkunkle/%s  --outputFile tree.root --treeName ggNtuplizer/EventTree --module scripts/ConfWgamgamBasicFilter.py --enableRemoveFilter --nsplit %d --storagePath /eos/cms/store/user/jkunkle/Wgamgam/FilteredSamples/%s ; python ../../Util/scripts/copy_histograms.py --file root://eoscms/%s/%s.root  --output /eos/cms/store/user/jkunkle/Wgamgam/FilteredSamples/%s'

for base, name, nsp in job_conf :

    command = base_cmd %( base, name, name, nsp, name, base, name, name ) 
    os.system( command )
