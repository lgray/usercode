import os
from check_dataset_completion import check_dataset_completion

#base_data     ='root://eoscms//eos/cms/store/group/phys_egamma/ymaravin/ggNtuples/V05-03-07-06'
base_data     ='/eos/cms/store/group/phys_smp/ggNtuples/data'
#base_data = '/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesJan14/'
#base_alberto = '/eos/cms/store/user/abelloni/Wgamgam/FilteredSamplesJan14/'
base_mc     ='/eos/cms/store/group/phys_smp/ggNtuples/mc'
#base_filtered ='/eos/cms/store/user/abelloni/Wgamgam/FilteredSamplesJan14'
base_filtered ='/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesJan14'
#base_filtered = '/eos/cms/store/user/jkunkle/Wgamgam/RecoOutput_2014_01_16/'
#base_all = '/eos/cms/store/user/jkunkle/Wgamgam/FilteredSamplesJan14/'
base_all = '/eos/cms/store/group/phys_egamma/cmkuo/'



job_conf = [
            #(base_all, 'job_summer12_DYJetsToLL'),
            #(base_all, 'job_summer12_WAA_ISR'),
            #(base_all, 'job_summer12_WH_ZH_125'),
            #(base_all, 'job_summer12_WWW'),
            #(base_all, 'job_summer12_WWZ'),
            #(base_all, 'job_summer12_WW_2l2nu'),
            #(base_all, 'job_summer12_WWg'),
            #(base_all, 'job_summer12_WZZ'),
            #(base_all, 'job_summer12_WZ_2l2q'),
            #(base_all, 'job_summer12_WZ_3lnu'),
            #(base_all, 'job_summer12_Wg'),
            #(base_all, 'job_summer12_Wgg_FSR'),
            #(base_all, 'job_summer12_ZZZ'),
            #(base_all, 'job_summer12_ZZ_2e2mu'),
            #(base_all, 'job_summer12_ZZ_2e2tau'),
            #(base_all, 'job_summer12_ZZ_2l2nu'),
            #(base_all, 'job_summer12_ZZ_2l2q'),
            #(base_all, 'job_summer12_ZZ_2mu2tau'),
            #(base_all, 'job_summer12_ZZ_2q2nu'),
            #(base_all, 'job_summer12_ZZ_4e'),
            #(base_all, 'job_summer12_ZZ_4mu'),
            #(base_all, 'job_summer12_ZZ_4tau'),
            (base_all, 'job_summer12_Zg'),
            #(base_all, 'job_summer12_diphoton_box_10to25'),
            #(base_all, 'job_summer12_diphoton_box_250toInf'),
            #(base_all, 'job_summer12_diphoton_box_25to250'),
            #(base_all, 'job_summer12_ggH_125'),
            #(base_all, 'job_summer12_ggZZ_2l2l'),
            #(base_all, 'job_summer12_ggZZ_4l'),
            #(base_all, 'job_summer12_t_s'),
            #(base_all, 'job_summer12_t_t'),
            #(base_all, 'job_summer12_t_tW'),
            #(base_all, 'job_summer12_tbar_s'),
            #(base_all, 'job_summer12_tbar_t'),
            #(base_all, 'job_summer12_tbar_tW'),
            (base_all, 'job_summer12_ttW'),
            (base_all, 'job_summer12_ttZ'),
            #(base_all, 'job_summer12_ttg'),
            #(base_all, 'job_summer12_ttjets_1l'),
            #(base_all, 'job_summer12_ttjets_2l'),


            #(base_data, 'job_muon_2012a_Jan22rereco'),
            #(base_data, 'job_muon_2012b_Jan22rereco'),
            #(base_data, 'job_muon_2012c_Jan22rereco'),
            #(base_data, 'job_muon_2012d_Jan22rereco'),
            #(base_alberto, 'job_electron_2012a_Jan22rereco'),
            #(base_alberto, 'job_electron_2012b_Jan22rereco'),
            #(base_alberto, 'job_electron_2012c_Jan2012rereco'),
            #(base_alberto, 'job_electron_2012d_Jan22rereco'),


]


for base, ds in job_conf :

    print "FIXME"
    orig_nevt_tree, orig_nevt_hist, filt_nevt_tree, filt_nevt_hist = check_dataset_completion( originalDS=base, filteredDS=base_filtered+'/'+ds, treeNameOrig='ggNtuplizer/EventTree', treeNameFilt='ggNtuplizer/EventTree',histNameFilt='ggNtuplizer/filter', fileKeyOrig=ds+'.root', fileKeyFilt='tree.root' )

    print '%s : Orignal = %d events, filtered = %d events.  Difference = %d' %( ds, orig_nevt_tree, filt_nevt_hist, orig_nevt_tree-filt_nevt_hist)
