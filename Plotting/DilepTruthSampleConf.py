

def config_samples(samples) :
    import ROOT

    #samples.AddSample('Sherpa', path='user.jkunkle.mc11_7TeV.128814.SherpaZZllnn.e950_s1310_s1300_r3043_r2993.Dec12.r17.0.6.9', plotColor=ROOT.kRed-3 )
    #samples.AddSample('PowhegBox', path='user.jkunkle.mc11_7TeV.126406.PowHegBoxZZeenn_Pythia.e995_s1372_s1370_r3043_r2993.Dec12.r17.0.6.9', plotColor=ROOT.kBlue+1)
    #samples.AddSample('MC@NLO', path='user.jkunkle.mc11_7TeV.105932.McAtNlo_JIMMY_ZZ_llnunu.e872_s1310_s1300_r3043_r2993.Dec12.r17.0.6.9', plotColor=ROOT.kBlack)
    
    samples.AddSample('ZZ', path='user.jkunkle.mc11_7TeV.128814.SherpaZZllnn.e950_s1310_s1300_r3043_r2993.Dec12.r17.0.6.9', plotColor=ROOT.kBlue+1)
    samples.AddSample('Z + jets', path='user.jkunkle.mc12_14TeV.147806.PowhegPythia8_AU2CT10_Zee.filter.NTUP_TRUTH.ProdJune.01', plotColor=ROOT.kRed-2)

def print_examples() :
    pass
