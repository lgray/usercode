from filter import Filter

def get_remove_filter() :

    return ['mc.*', 'jet.*', 'ele\w+Vtx', 'phoTrgFilter', 'pho\w+Vtx', 'phoCi.*', 'mu\w+Vtx', 'eleTrg', 'muTrg']

def get_keep_filter() :

    return []

def config_analysis( alg_list ) :

    elBuild = Filter('BuildElec')
    alg_list.append(elBuild)

    elFilt = Filter('FilterElec')
    elFilt.cut_pt = "> 50"
    #elecFilt.cut_eta = "> -2.5,< 2.5"
    #elecFilt.invert('cut_eta')
    #elecFilt.cut_isTight = "True"
    muFilt = Filter('FilterMuon')
    muFilt.cut_pt = "> 50"

    evFilt = Filter('FilterEvent')
    evFilt.cut_nEl = "> 0"
    evFilt.cut_nMu = "> 0"
    #evFilt.cut_nLep = "> 0"

    alg_list.append(elFilt)
    alg_list.append(muFilt)
    alg_list.append(evFilt)
