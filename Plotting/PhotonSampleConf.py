

def config_samples(samples) :
    import ROOT

    samples.AddSample('Data',
                      path='Data',
                      isData    = True,
                      scale=1.0,
                     )

    samples.AddSample('Fail all',
                      path=['QCDModelInvAll'],
                      plotColor = ROOT.kRed+1,
                      scale=1.0,
                     )
    samples.AddSample('Fail two or more',
                      path=['QCDModelInvMaj'],
                      plotColor = ROOT.kBlue-2,
                      scale=1.0,
                     )
    samples.AddSample('Fail one or more',
                      #'DiJet',
                      path=['QCDModelInvAny'],
                      plotColor = ROOT.kGreen+3,
                      scale=1.0,
                     )

    ##samples.AddSample('JZ0W',path=['JZ0W'],disableDraw=False,scale=1.0, plotColor=ROOT.kRed)
    #samples.AddSample('JZ1',path=['JZ1'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed+1)
    #samples.AddSample('JZ2',path=['JZ2'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed+2)
    #samples.AddSample('JZ3',path=['JZ3'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed+3)
    #samples.AddSample('JZ4',path=['JZ4'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed+4)
    #samples.AddSample('JZ5',path=['JZ5'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed-1)
    #samples.AddSample('JZ6',path=['JZ6'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed-2)
    #samples.AddSample('JZ7',path=['JZ7'],disableDraw=True,scale=1.0, plotColor=ROOT.kRed-3)


    #samples.AddSampleGroup( 'QCD', input_samples = ['JZ1', 
    #                                                'JZ2', 
    #                                                'JZ3', 
    #                                                'JZ4', 
    #                                                'JZ5', 
    #                                                'JZ6', 
    #                                                'JZ7', 
    #                                                 ],
    #                                plotColor=ROOT.kRed,
    #                                scale=1.0
    #                      )
                                                      

    samples.AddSample('#gamma + jet',
                      path=['SPModelInvAny'],
                      #path=['GammaJetBinned20','GammaJetBinned40','GammaJetBinned80','GammaJetBinned150','GammaJetBinned300',],
                      plotColor=ROOT.kYellow,
                      scale=1.0,
                     )

    samples.AddSample('Top',
                      path=['SingleTop','TTBar'],
                      #path=['Top'],
                      plotColor = ROOT.kGreen,
                      scale=1.0,
                     )

    samples.AddSample('W (#bf{#font[12]{l}}#nu) + #gamma',
                      path='Wgamma',
                      plotColor = ROOT.kRed,
                      scale=1.0,
                     )

    samples.AddSample('W + jet',
                      path=['Wenu','Wmunu', 'Wtaunu'],
                      plotColor = ROOT.kBlue,
                      scale=1.0,
                     )

    samples.AddSample(
                      #'Z (#rightarrow #nu #nu ) + #gamma',
                      'Z (#nu#nu) + #gamma',
                      path=['ZnunuGammaPt20', 'ZnunuGammaPt70'],
                      plotColor = ROOT.kMagenta,
                      scale=1.0,
                     )

    samples.AddSample(
                      #'Z (#rightarrow l l ) + #gamma',
                      'Z (#bf{#font[12]{ll}})  + #gamma',
                      path=['ZllGamma'],
                      plotColor = ROOT.kOrange,
                      scale=1.0,
                     )

    #samples.AddModelSample( 'QCD', path='Data', legend_name='QCD (data-driven)', plotColor=ROOT.kRed, scale=1.0 )



def print_examples() :

    print 'Plot photon pt distribution : '
    print 'samples.Draw(\'gamma_pt\', \'EventWeight\', ( 500, 0, 500 ) )'

    print 'Plot met distribution after cutting on pt '
    print 'samples.Draw(\'met_et\', \'EventWeight * ( gamma_pt > 50.0 ) \', ( 500, 0, 500 ) )'

    print 'Plot jet multiplicity'
    print 'samples.Draw(\'njets\', \'EventWeight \', ( 20, 0, 20 ) )'
