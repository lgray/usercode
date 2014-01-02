

def config_samples(samples) :

    import ROOT

    samples.AddSample('DYJetsToLL'              , path='job_summer12_DYJetsToLL'              , filekey='tree.root', disableDraw=True, scale=1.0 );

    samples.AddSample('DYJetsToLLFFNoMassCut', path='job_summer12_DYJetsToLLFFNoMassCut', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)
    samples.AddSample('DYJetsToLLFFNoMassCut0Conv', path='job_summer12_DYJetsToLLFFNoMassCut0Conv', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)
    samples.AddSample('DYJetsToLLFFNoMassCut2Conv', path='job_summer12_DYJetsToLLFFNoMassCut2Conv', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)
    samples.AddSample('DYJetsToLLFFPtNoMassCut', path='job_summer12_DYJetsToLLFFPtNoMassCut', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)
    samples.AddSample('DYJetsToLLFFEtaNoMassCut', path='job_summer12_DYJetsToLLFFEtaNoMassCut', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)
    samples.AddSample('DYJetsToLLFFPtEta1DNoMassCut', path='job_summer12_DYJetsToLLFFPtEta1DNoMassCut', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)
    samples.AddSample('DYJetsToLLFFPtEta2DNoMassCut', path='job_summer12_DYJetsToLLFFPtEta2DNoMassCut', filekey='tree.root', scale=1.0, plotColor=ROOT.kCyan, disableDraw=True)



def print_examples() :
    pass
