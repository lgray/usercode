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

    samples.AddSample('Top',
                      path=['TTBar','SingleTop'],
                      plotColor = ROOT.kGreen,
                      scale=-1.0,
                     )
    samples.AddSample('WGamma',
                      path='Wgamma',
                      plotColor = ROOT.kRed+1,
                      scale=-1.0,
                     )

    samples.AddSample('W+jets',
                      path=['Wenu','Wmunu'],
                      #path=['WJets'],
                      plotColor = ROOT.kBlue,
                      scale=-1.0,
                     )


    samples.AddSampleGroup( 'DataMCSubtracted', input_samples=['Data', 'Top', 'WGamma', 'W+jets'] )

def print_examples() :
    pass
