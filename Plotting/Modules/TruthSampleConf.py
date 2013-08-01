

def config_samples(samples) :
    import ROOT

    samples.AddSample('105200', path='mc12_14TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter', disableDraw=True, scale=8.822477)
    samples.AddSample('105921', path='mc12_14TeV.105921.McAtNloJimmy_AUET2CT10_WpWmenuenu', disableDraw=True, scale=0.812970)
    samples.AddSample('105922', path='mc12_14TeV.105922.McAtNloJimmy_AUET2CT10_WpWmenumunu', disableDraw=True, scale=0.814242)
    samples.AddSample('105923', path='mc12_14TeV.105923.McAtNloJimmy_AUET2CT10_WpWmenutaunu', disableDraw=True, scale=0.816364)
    samples.AddSample('105924', path='mc12_14TeV.105924.McAtNloJimmy_AUET2CT10_WpWmmunuenu', disableDraw=True, scale=0.815697)
    samples.AddSample('105925', path='mc12_14TeV.105925.McAtNloJimmy_AUET2CT10_WpWmmunumunu', disableDraw=True, scale=0.815455)
    samples.AddSample('105926', path='mc12_14TeV.105926.McAtNloJimmy_AUET2CT10_WpWmmunutaunu', disableDraw=True, scale=0.815515)
    samples.AddSample('105927', path='mc12_14TeV.105927.McAtNloJimmy_AUET2CT10_WpWmtaunuenu', disableDraw=True, scale=0.815152)
    samples.AddSample('105928', path='mc12_14TeV.105928.McAtNloJimmy_AUET2CT10_WpWmtaunumunu', disableDraw=True, scale=0.815576)
    samples.AddSample('105929', path='mc12_14TeV.105929.McAtNloJimmy_AUET2CT10_WpWmtaunutaunu', disableDraw=True, scale=0.817394)
    #samples.AddSample('146906', path='mc12_14TeV.146906.Pythia8_AU2CTEQ6L1_ZZinclusive_1LepEF', disableDraw=True, scale=1.535734)
    samples.AddSample('147073', path='mc12_14TeV.147073.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0'  , disableDraw=True, scale=80.147239)
    samples.AddSample('147074', path='mc12_14TeV.147074.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1'  , disableDraw=True, scale=52.518848)
    samples.AddSample('147075', path='mc12_14TeV.147075.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2'  , disableDraw=True, scale=48.841611)
    samples.AddSample('147076', path='mc12_14TeV.147076.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3'  , disableDraw=True, scale=40.950000)
    samples.AddSample('147077', path='mc12_14TeV.147077.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4'  , disableDraw=True, scale=33.160169)
    samples.AddSample('147078', path='mc12_14TeV.147078.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5'  , disableDraw=True, scale=41.144142)
    samples.AddSample('147081', path='mc12_14TeV.147081.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0', disableDraw=True, scale=80.089888)
    samples.AddSample('147082', path='mc12_14TeV.147082.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1', disableDraw=True, scale=52.547120)
    samples.AddSample('147083', path='mc12_14TeV.147083.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2', disableDraw=True, scale=48.829530)
    samples.AddSample('147084', path='mc12_14TeV.147084.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3', disableDraw=True, scale=40.905000)
    samples.AddSample('147085', path='mc12_14TeV.147085.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4', disableDraw=True, scale=33.438462)
    samples.AddSample('147086', path='mc12_14TeV.147086.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5', disableDraw=True, scale=40.840650)
    #samples.AddSample('147090', path='mc12_14TeV.147090.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1', disableDraw=True, scale=52.534555)
    #samples.AddSample('147091', path='mc12_14TeV.147091.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2', disableDraw=True, scale=48.761074)
    #samples.AddSample('147092', path='mc12_14TeV.147092.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3', disableDraw=True, scale=40.866000)
    #samples.AddSample('147094', path='mc12_14TeV.147094.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5', disableDraw=True, scale=41.220652)
    #samples.AddSample('161155', path='mc12_14TeV.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep', disableDraw=True, scale=0.046629)
    #samples.AddSample('126566', path='mc12_14TeV.126566.MadgraphHerwigpp_UEEE3_CTEQ6L1_WpmunuZmumu', disableDraw=True, scale=0.494100)
    #samples.AddSample('126567', path='mc12_14TeV.126567.MadgraphHerwigpp_UEEE3_CTEQ6L1_ZmumuZmumu', disableDraw=True, scale=0.208873)
    samples.AddSample('146891', path='mc12_14TeV.146891.MadGraphPythia_AUET2BCTEQ6L1_lnuee_gt7', disableDraw=True, scale=0.303756)
    samples.AddSample('146893', path='mc12_14TeV.146893.MadGraphPythia_AUET2BCTEQ6L1_lnumumu_gt7', disableDraw=True, scale=0.303096)
    samples.AddSample('146895', path='mc12_14TeV.146895.MadGraphPythia_AUET2BCTEQ6L1_lnutautau_gt7', disableDraw=True, scale=0.353202)
    #samples.AddSample('147800', path='mc12_14TeV.147800.PowhegPythia8_AU2CT10_Wplusenu', disableDraw=True, scale=36480.000000)
    #samples.AddSample('147801', path='mc12_14TeV.147801.PowhegPythia8_AU2CT10_Wplusmunu', disableDraw=True, scale=36480.000000)
    #samples.AddSample('147802', path='mc12_14TeV.147802.PowhegPythia8_AU2CT10_Wplustaunu', disableDraw=True, scale=36480.000000)
    #samples.AddSample('147803', path='mc12_14TeV.147803.PowhegPythia8_AU2CT10_Wminenu', disableDraw=True, scale=26931.000000)
    #samples.AddSample('147804', path='mc12_14TeV.147804.PowhegPythia8_AU2CT10_Wminmunu', disableDraw=True, scale=26931.000000)
    #samples.AddSample('147806', path='mc12_14TeV.147806.PowhegPythia8_AU2CT10_Zee', disableDraw=True, scale=205.720000)
    #samples.AddSample('147807', path='mc12_14TeV.147807.PowhegPythia8_AU2CT10_Zmumu', disableDraw=True, scale=6174.000000)
    #samples.AddSample('147808', path='mc12_14TeV.147808.PowhegPythia8_AU2CT10_Ztautau', disableDraw=True, scale=6172.500000)
    #samples.AddSample('147811', path='mc12_14TeV.147811.Pythia8_AU2CTEQ6L1_Wmunu', disableDraw=True, scale=52233.000000)
    #samples.AddSample('147816', path='mc12_14TeV.147816.Pythia8_AU2CTEQ6L1_Zee', disableDraw=True, scale=5096.400000)
    #samples.AddSample('147817', path='mc12_14TeV.147817.Pythia8_AU2CTEQ6L1_Zmumu', disableDraw=True, scale=5080.500000)
    #samples.AddSample('147818', path='mc12_14TeV.147818.Pythia8_AU2CTEQ6L1_Ztautau', disableDraw=True, scale=1015.020000)
    samples.AddSample('157735', path='mc12_14TeV.157735.Sherpa_CT10_llnunu_leptFilt', disableDraw=True, scale=0.266706)
    #samples.AddSample('157953', path='mc12_14TeV.157953.Sherpa_CT10_WZlep_MET50', disableDraw=True, scale=0.010832)
    #samples.AddSample('160305', path='mc12_14TeV.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep', disableDraw=True, scale=0.000611)
    samples.AddSample('146411', path='user.hokawa.mc12_14TeV.146441.PowHegHerwigpp.ZH125_inv', disableDraw=True, scale=1.0)



    samples.AddSampleGroup('Zll+Jets',
                           legend_name='Z+jets',
                         input_samples=[
                                        '147073',
                                        '147074',
                                        '147075',
                                        '147076',
                                        '147077',
                                        '147078',
                                        '147081',
                                        '147082',
                                        '147083',
                                        '147084',
                                        '147085',
                                        '147086',

                           ],
                      plotColor=ROOT.kCyan,
                      scale=1.0,

                     )
    samples.AddSampleGroup('Top',
                      input_samples=[
                                     '105200',
                                    ],
                      plotColor = ROOT.kGreen,
                      scale=1.0,
                     )

    samples.AddSampleGroup('WZ',
                      input_samples=[
                                     '146891',
                                     '146893',
                                     '146895',
                                    ],
                      scale=1.0,
                      plotColor = ROOT.kRed,
                     )

    samples.AddSampleGroup('WW',
                      input_samples=[
                                     '105921',
                                     '105922',
                                     '105923',
                                     '105924',
                                     '105925',
                                     '105926',
                                     '105927',
                                     '105928',
                                     '105929',
                                    ],
                      plotColor = ROOT.kBlue,
                      scale=1.0,
                     )

    samples.AddSampleGroup('ZZ',
                      input_samples=[
                                     '157735',
                                    ],
                      plotColor = ROOT.kMagenta,
                      scale=1.0,
                     )

    samples.AddSampleGroup('ZHInv',
                      input_samples=[
                                     '146411',
                                    ],
                      plotColor = ROOT.kRed,
                      isSignal=True,
                      scale=1.0,
                     )


def print_examples() :
    pass
