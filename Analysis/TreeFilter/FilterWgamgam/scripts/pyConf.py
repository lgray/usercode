
import RunModule

alg_list = []

jet_filt = RunModule.FilterJet()
jet_filt.cut_pt = '> 15'
alg_list.append(jet_filt)
