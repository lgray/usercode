

def config_samples(samples) :

    import ROOT

    samples.AddSample('WggISR', path='ISR', plotColor=ROOT.kBlue )
    samples.AddSample('WggFSR', path='FSR', plotColor=ROOT.kRed  )

def print_examples() :
    pass
