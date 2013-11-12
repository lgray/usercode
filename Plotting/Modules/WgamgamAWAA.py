

def config_samples(samples) :

    import ROOT

    #samples.AddSample('WggISR', path='ISR', plotColor=ROOT.kBlue )
    #samples.AddSample('WggFSR', path='FSR', plotColor=ROOT.kRed  )
    #samples.AddSample('Combined', path=['FSR', 'ISR'], plotColor=ROOT.kBlack  )

    samples.AddSample('0 W photons', path=['NPhot0ISR', 'NPhot0FSR'], plotColor=ROOT.kBlack )
    samples.AddSample('1 W photons', path=['NPhot1ISR', 'NPhot1FSR'], plotColor=ROOT.kBlue )
    samples.AddSample('2 W photons', path=['NPhot2ISR', 'NPhot2FSR'], plotColor=ROOT.kRed )

def print_examples() :
    pass
