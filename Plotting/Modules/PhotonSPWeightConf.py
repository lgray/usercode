

def config_samples(samples) :
    import ROOT

    samples.AddSample('Data',
                      path='Data',
                      isData    = True,
                     )

    samples.AddSample('SinglePhoton',
                      path=['GammaJetBinned20','GammaJetBinned40','GammaJetBinned80','GammaJetBinned150','GammaJetBinned300',],
                      #path=['GammaJet'],
                      plotColor=ROOT.kYellow,
                      scale=1.0,

                     )

    samples.AddSample('Top',
                      path=['SingleTop','TTBar'],
                      #path=['Top'],
                      plotColor = ROOT.kGreen,
                      scale=-1.0,
                     )

    samples.AddSample('WGamma',
                      path='Wgamma',
                      plotColor = ROOT.kRed,
                      scale=-1.0,
                     )

    samples.AddSample('W+jets',
                      path=['Wenu','Wmunu', 'Wtaunu'],
                      plotColor = ROOT.kBlue,
                      scale=-1.0,
                     )

    samples.AddSample('ZGamma',
                      path=['ZnunuGammaPt20', 'ZnunuGammaPt70'],
                      plotColor = ROOT.kMagenta,
                      scale=-1.0,
                     )

    samples.AddSample('QCD',
                      path=['QCDModelInvMaj'],
                      plotColor = ROOT.kMagenta,
                      scale=-1.0,
                     )

    samples.AddSampleGroup('Numerator',
                      input_samples=[
                                     'Data',
                                     'Top',
                                     'WGamma',
                                     'W+jets',
                                     'ZGamma',
                                     'QCD',
                                    ],
                      plotColor = ROOT.kGreen,
                      scale=1.0,
                     )

    samples.AddSampleGroup('Denominator', input_samples=['SinglePhoton'], scale=1.0 )


def print_examples() :
    pass



