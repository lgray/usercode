def config_samples(samples) :
    import ROOT

    samples.AddSample('Data',
                      path='Data',
                      isData    = True,
                      scale=-1.0,
                     )

    samples.AddSample('Z + Jets',
                      path=['DrellYanZll', 'DrellYanZtautau'],
                      #path=['Top'],
                      plotColor = ROOT.kCyan,
                      scale=-1.0,
                     )

    samples.AddSample('SinglePhoton',
                      path=['GammaJetBinned20','GammaJetBinned40','GammaJetBinned80','GammaJetBinned150','GammaJetBinned300',],
                      #path=['GammaJet'],
                      plotColor=ROOT.kYellow,
                      scale=-1.0,

                     )

    samples.AddSample('Top',
                      path=['SingleTop','TTBar'],
                      #path=['Top'],
                      plotColor = ROOT.kGreen,
                      scale=-1.0,
                     )

    samples.AddSample('W (#bf{#font[12]{l}}#nu) + #gamma',
                      path='Wgamma',
                      plotColor = ROOT.kRed,
                      scale=-1.2,
                     )

    #samples.AddSample('W+jets',
    #                  path=['Wenu','Wmunu', 'Wtaunu'],
    #                  plotColor = ROOT.kBlue,
    #                  scale=-1.0,
    #                 )

    samples.AddSample('ZGamma',
                      path=['ZnunuGammaPt20', 'ZnunuGammaPt70'],
                      plotColor = ROOT.kMagenta,
                      scale=-1.0,
                     )

    samples.AddSample('Z (#bf{#font[12]{ll}})  + #gamma',
                      path=['ZllGamma'],
                      plotColor = ROOT.kOrange,
                      scale=-1.0,
                     )

def print_examples() :
    pass
