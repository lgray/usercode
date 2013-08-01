def config_samples(samples) :
    import ROOT

    samples.AddSample('Data',
                      path=['Data',],
                      isData    = True,
                     )

    samples.AddSample('Z + Jets',
                      path=['DrellYanZll', 'DrellYanZtautau'],
                      #path=['PowhegZll'],
                      #path=['ZJets'],
                      #path=['ZJetsMerged'],
                      #scale=2.54345,
                      plotColor = ROOT.kCyan,
                      #scale = 1.07565,
                     )

    #samples.AddSample('DrellYanZtautau',
    #                  path=['DrellYanZtautau'],
    #                  #path=['PowhegZtautau'],
    #                  #path=['ZJets'],
    #                  #path=['ZJetsMerged'],
    #                  #scale=2.54345,
    #                  plotColor = ROOT.kCyan,
    #                  #scale = 1.07565,
    #                 )

    # for comparison
    #samples.AddSample('Single Photon Model',
    #                  path=['DrellYanZll','DrellYanZtautau'],
    #                  #path=['ZJets'],
    #                  #path=['ZJetsMerged'],
    #                  #scale=2.54345,
    #                  plotColor = ROOT.kBlue,
    #                  #scale = 1.136,
    #                 )

    samples.AddSample('Top',
                      path=['TTBar','SingleTop'],
                      plotColor = ROOT.kGreen,
                      scale=1.0,
                     )
    samples.AddSample('WGamma',
                      path='Wgamma',
                      plotColor = ROOT.kRed+1,
                     )

    #samples.AddSample('ZllGamma',
    #                  path=['Zeegamma', 'Zmumugamma'],
    #                  #path=['ZllGamma'],
    #                  plotColor = ROOT.kRed+5
    #                 )

    samples.AddSample('WZ',
                      path='WZ',
                      plotColor = ROOT.kWhite,
                     )

    samples.AddSample('WW',
                      path='WW',
                      plotColor = ROOT.kRed,
                     )

    samples.AddSample('W+jets',
                      path=['Wenu','Wmunu'],
                      #path=['WJets'],
                      plotColor = ROOT.kBlue
                     )

    samples.AddSample('ZZ2l2nu',
                      #path='ZZllnunuMCAtNLO',
                      path='ZZllnunu',
                      plotColor = ROOT.kMagenta,
                      scale=1.0,
                     )

    samples.AddSampleGroup('Nominal', 
                           input_samples = [
                                            'Z + Jets',
                                            'Top',
                                            'WZ',
                                            'WW',
                                            'W+jets',
                                            'ZZ2l2nu'
                                            ],
                           isSignal=True,
                           plotColor=ROOT.kRed,
                           drawRatio=True,
                          )


    #samples.AddSample('Nominal Z+jets', 
    #                  path=['DrellYanZll','DrellYanZtautau', 'TTBar','SingleTop', 'WZ', 'WW', 'Wenu', 'Wmunu', 'ZZllnunuMCAtNLO'],
    #                  isSignal=True,
    #                  drawRatio=True,
    #                  plotColor=ROOT.kRed,
    #                  #scale = 1.07565,
    #                  #scale=1.27

    #                )

    #samples.AddSample('ZZ2l2nu',
    #                  path='ZZPowheg',
    #                  plotColor = ROOT.kMagenta
    #                 )

    #samples.AddSample('ZHInv125',
    #                  isSignal = True,
    #                  path='ZHInv125',
    #                  plotColor = ROOT.kRed
    #                 )

    #samples.AddModelTree('Z+jets',
    #                  path='GammaJetModel',
    #                  treename='photons',
    #                  legend_name='Z+jets (data-driven)',
    #                  #scale=0.001990889,
    #                  #scale = 1.07565,
    #                  #scale=1.05676,
    #                  plotColor = ROOT.kCyan,
    #    )
    #samples.AddModelHist('Z+jets',
    #                  path='GammaJetModel',
    #                  plotColor = ROOT.kBlue,
    #                  #scale=1.125135525,
    #                  #scale=0.87818629,
    #                  scale=1.343165222,
    #                  #scale=1.0,
    #                 )

    #samples.AddModelHist('Z+jets',
    #                  path='GammaJetModel',
    #                  plotColor = ROOT.kBlue,
    #                  scale=0.0035,
    #                  #scale=1.0,
    #                 )


    #samples.AddSample('DrellYanPythia',
    #                  path='DrellYanPythia',
    #                  plotColor = ROOT.kRed
    #                 )

    samples.AddModelSample('PhotonData'    , path='Data'       )
    samples.AddModelSample('SingleTop'     , path='SingleTop'  , scale=-1.0)
    samples.AddModelSample('TTBar'         , path='TTBar'      , scale=-1.0)
    samples.AddModelSample('Wenu'          , path='Wenu'       , scale=-1.0)
    samples.AddModelSample('Wmunu'         , path='Wmunu'      , scale=-1.0)
    samples.AddModelSample('Wtaunu'        , path='Wtaunu'     , scale=-1.0)
    samples.AddModelSample('ZnunuGamma'    , path=['ZnunuGammaPt20', 'ZnunuGammaPt70'] , scale=-1.0)
    samples.AddModelSampleGroup('Z + Jets' , plotColor=ROOT.kCyan,
                           legend_name='Z + Jets (data-driven)',
                                #scale=0.73,
                                #scale=1.147,
                                scale = 1.043,

                           input_samples=[
                                           'PhotonData', 
                                           'SingleTop',
                                           'TTBar',
                                           'Wenu', 
                                           'Wmunu',
                                           'Wtaunu',
                                           'ZnunuGamma',
                                         ],
    )

def print_examples() :
    pass
