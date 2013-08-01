

def config_samples(samples) :
    import ROOT

    samples.AddSample('Data',
                      path='data12/Nominal',
                      filekey='root',
                      isData    = True,
                     )

    samples.AddSample('107650', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107650', disableDraw=True, scale=2.42201 )
    samples.AddSample('107651', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107651', disableDraw=True, scale=2.35138 )
    samples.AddSample('107652', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107652', disableDraw=True, scale=2.34292 )
    samples.AddSample('107653', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107653', disableDraw=True, scale=2.49632 )
    samples.AddSample('107654', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107654', disableDraw=True, scale=2.4502 )
    samples.AddSample('107660', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107660', disableDraw=True, scale=2.49918 )
    samples.AddSample('107661', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107661', disableDraw=True, scale=2.34203 )
    samples.AddSample('107662', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107662', disableDraw=True, scale=2.34907 )
    samples.AddSample('107663', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107663', disableDraw=True, scale=2.49648 )
    samples.AddSample('107664', path='ZDY_Alpgen_1_mc12/Nominal', filekey='107664', disableDraw=True, scale=2.46542 )
    samples.AddSample('146835', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146835', disableDraw=True, scale=0.115993 )
    samples.AddSample('146845', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146845', disableDraw=True, scale=0.113543 )
    samples.AddSample('146854', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146854', disableDraw=True, scale=0.133024 )
    samples.AddSample('146855', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146855', disableDraw=True, scale=0.114627 )
    samples.AddSample('146860', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146860', disableDraw=True, scale=0.116495 )
    samples.AddSample('146861', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146861', disableDraw=True, scale=0.0961182 )
    samples.AddSample('146862', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146862', disableDraw=True, scale=0.0937268 )
    samples.AddSample('146863', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146863', disableDraw=True, scale=0.099093 )
    samples.AddSample('146864', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146864', disableDraw=True, scale=0.112035 )
    samples.AddSample('146870', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146870', disableDraw=True, scale=0.121172 )
    samples.AddSample('146871', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146871', disableDraw=True, scale=0.0995782 )
    samples.AddSample('146872', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146872', disableDraw=True, scale=0.0941413 )
    samples.AddSample('146873', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146873', disableDraw=True, scale=0.291228 )
    samples.AddSample('146874', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146874', disableDraw=True, scale=0.114116 )
    samples.AddSample('146880', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146880', disableDraw=True, scale=0.0650159 )
    samples.AddSample('146881', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146881', disableDraw=True, scale=0.0948275 )
    samples.AddSample('146882', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146882', disableDraw=True, scale=0.0599082 )
    samples.AddSample('146883', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146883', disableDraw=True, scale=0.0264196 )
    samples.AddSample('146930', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146930', disableDraw=True, scale=0.112571 )
    samples.AddSample('146931', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146931', disableDraw=True, scale=0.05857 )
    samples.AddSample('146932', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146932', disableDraw=True, scale=0.0955879 )
    samples.AddSample('146933', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146933', disableDraw=True, scale=0.0894441 )
    samples.AddSample('146934', path='ZDY_Alpgen_1_mc12/Nominal', filekey='146934', disableDraw=True, scale=0.163608 )
    samples.AddSample('147078', path='ZDY_Alpgen_1_mc12/Nominal', filekey='147078', disableDraw=True, scale=0.0770132 )
    samples.AddSample('147086', path='ZDY_Alpgen_1_mc12/Nominal', filekey='147086', disableDraw=True, scale=0.0746841 )
    samples.AddSample('147094', path='ZDY_Alpgen_1_mc12/Nominal', filekey='147094', disableDraw=True, scale=0.0736156 )

    samples.AddSample('110001', path='Top_1_mc12/Nominal', filekey='110001', disableDraw=True, scale=0.0672816 )
    samples.AddSample('108343', path='Top_1_AFII/Nominal', filekey='108343', disableDraw=True, scale=0.014847 )
    samples.AddSample('108344', path='Top_1_AFII/Nominal', filekey='108344', disableDraw=True, scale=0.0148337 )
    samples.AddSample('108345', path='Top_1_AFII/Nominal', filekey='108345', disableDraw=True, scale=0.0148304 )
    samples.AddSample('108346', path='Top_1_AFII/Nominal', filekey='108346', disableDraw=True, scale=0.105255 )
    samples.AddSample('117360', path='Top_1_AFII/Nominal', filekey='117360', disableDraw=True, scale=0.114616 )
    samples.AddSample('117361', path='Top_1_AFII/Nominal', filekey='117361', disableDraw=True, scale=0.11476 )
    samples.AddSample('117362', path='Top_1_AFII/Nominal', filekey='117362', disableDraw=True, scale=0.114523 )

    samples.AddSample('116601', path='NonWW_1_mc12/Nominal', filekey='116601', disableDraw=True, scale=0.000154053 )
    samples.AddSample('116602', path='NonWW_1_mc12/Nominal', filekey='116602', disableDraw=True, scale=0.000155043 )
    samples.AddSample('116603', path='NonWW_1_mc12/Nominal', filekey='116603', disableDraw=True, scale=0.000311172 )
    samples.AddSample('126937', path='NonWW_1_mc12/Nominal', filekey='126937', disableDraw=True, scale=0.00230088 )
    samples.AddSample('126938', path='NonWW_1_mc12/Nominal', filekey='126938', disableDraw=True, scale=0.00487659 )
    samples.AddSample('126939', path='NonWW_1_mc12/Nominal', filekey='126939', disableDraw=True, scale=0.00343433 )
    samples.AddSample('126940', path='NonWW_1_mc12/Nominal', filekey='126940', disableDraw=True, scale=0.00231294 )
    samples.AddSample('126941', path='NonWW_1_mc12/Nominal', filekey='126941', disableDraw=True, scale=0.00345938 )
    samples.AddSample('126942', path='NonWW_1_mc12/Nominal', filekey='126942', disableDraw=True, scale=0.000537618 )
    samples.AddSample('126949', path='NonWW_1_mc12/Nominal', filekey='126949', disableDraw=True, scale=0.0115797 )
    samples.AddSample('126950', path='NonWW_1_mc12/Nominal', filekey='126950', disableDraw=True, scale=0.0115885 )
    samples.AddSample('126951', path='NonWW_1_mc12/Nominal', filekey='126951', disableDraw=True, scale=0.0115885 )
    samples.AddSample('129477', path='NonWW_1_mc12/Nominal', filekey='129477', disableDraw=True, scale=0.045139 )
    samples.AddSample('129478', path='NonWW_1_mc12/Nominal', filekey='129478', disableDraw=True, scale=0.0359798 )
    samples.AddSample('129479', path='NonWW_1_mc12/Nominal', filekey='129479', disableDraw=True, scale=0.0078544 )
    samples.AddSample('129480', path='NonWW_1_mc12/Nominal', filekey='129480', disableDraw=True, scale=0.0447229 )
    samples.AddSample('129481', path='NonWW_1_mc12/Nominal', filekey='129481', disableDraw=True, scale=0.0364921 )
    samples.AddSample('129482', path='NonWW_1_mc12/Nominal', filekey='129482', disableDraw=True, scale=0.00793962 )
    samples.AddSample('129483', path='NonWW_1_mc12/Nominal', filekey='129483', disableDraw=True, scale=0.0540097 )
    samples.AddSample('129484', path='NonWW_1_mc12/Nominal', filekey='129484', disableDraw=True, scale=0.0461872 )
    samples.AddSample('129485', path='NonWW_1_mc12/Nominal', filekey='129485', disableDraw=True, scale=0.0107362 )
    samples.AddSample('129486', path='NonWW_1_mc12/Nominal', filekey='129486', disableDraw=True, scale=0.0317151 )
    samples.AddSample('129487', path='NonWW_1_mc12/Nominal', filekey='129487', disableDraw=True, scale=0.0245688 )
    samples.AddSample('129488', path='NonWW_1_mc12/Nominal', filekey='129488', disableDraw=True, scale=0.00484452 )
    samples.AddSample('129489', path='NonWW_1_mc12/Nominal', filekey='129489', disableDraw=True, scale=0.0303413 )
    samples.AddSample('129490', path='NonWW_1_mc12/Nominal', filekey='129490', disableDraw=True, scale=0.0250248 )
    samples.AddSample('129491', path='NonWW_1_mc12/Nominal', filekey='129491', disableDraw=True, scale=0.0048609 )
    samples.AddSample('129492', path='NonWW_1_mc12/Nominal', filekey='129492', disableDraw=True, scale=0.0373594 )
    samples.AddSample('129493', path='NonWW_1_mc12/Nominal', filekey='129493', disableDraw=True, scale=0.0321487 )
    samples.AddSample('129494', path='NonWW_1_mc12/Nominal', filekey='129494', disableDraw=True, scale=0.00669341 )
    samples.AddSample('146434', path='NonWW_1_mc12/Nominal', filekey='146434', disableDraw=True, scale=0.13838 )
    samples.AddSample('146435', path='NonWW_1_mc12/Nominal', filekey='146435', disableDraw=True, scale=0.184877 )
    samples.AddSample('146436', path='NonWW_1_mc12/Nominal', filekey='146436', disableDraw=True, scale=0.120057 )
    samples.AddSample('146437', path='NonWW_1_mc12/Nominal', filekey='146437', disableDraw=True, scale=0.117827 )
    samples.AddSample('146438', path='NonWW_1_mc12/Nominal', filekey='146438', disableDraw=True, scale=0.0956221 )
    samples.AddSample('146439', path='NonWW_1_mc12/Nominal', filekey='146439', disableDraw=True, scale=0.124132 )
    samples.AddSample('146890', path='NonWW_1_mc12/Nominal', filekey='146890', disableDraw=True, scale=0.583157 )
    samples.AddSample('146892', path='NonWW_1_mc12/Nominal', filekey='146892', disableDraw=True, scale=0.191288 )
    samples.AddSample('146894', path='NonWW_1_mc12/Nominal', filekey='146894', disableDraw=True, scale=0.204048 )
    samples.AddSample('161986', path='NonWW_2_mc12/Nominal', filekey='161986', disableDraw=True, scale=0.000254822 )
    samples.AddSample('161987', path='NonWW_2_mc12/Nominal', filekey='161987', disableDraw=True, scale=0.0129946 )
    samples.AddSample('161988', path='NonWW_2_mc12/Nominal', filekey='161988', disableDraw=True, scale=3.04485e-05 )

    samples.AddSample('169471', path='WW_1_mc12/Nominal', filekey='169471', disableDraw=True, scale=0.016279 )
    samples.AddSample('169472', path='WW_1_mc12/Nominal', filekey='169472', disableDraw=True, scale=0.0143476 )
    samples.AddSample('169473', path='WW_1_mc12/Nominal', filekey='169473', disableDraw=True, scale=0.0143476 )
    samples.AddSample('169474', path='WW_1_mc12/Nominal', filekey='169474', disableDraw=True, scale=0.016279 )
    samples.AddSample('169475', path='WW_1_mc12/Nominal', filekey='169475', disableDraw=True, scale=0.0143476 )
    samples.AddSample('169476', path='WW_1_mc12/Nominal', filekey='169476', disableDraw=True, scale=0.0143476 )
    samples.AddSample('169477', path='WW_1_mc12/Nominal', filekey='169477', disableDraw=True, scale=0.016279 )
    samples.AddSample('169478', path='WW_1_mc12/Nominal', filekey='169478', disableDraw=True, scale=0.0143476 )
    samples.AddSample('169479', path='WW_1_mc12/Nominal', filekey='169479', disableDraw=True, scale=0.0143476 )
    samples.AddSample('169061', path='WW_2_AFII/Nominal', filekey='169061', disableDraw=True, scale=7.2825e+07 )
    samples.AddSample('169062', path='WW_2_AFII/Nominal', filekey='169062', disableDraw=True, scale=7.28468e+07 )
    samples.AddSample('169063', path='WW_2_AFII/Nominal', filekey='169063', disableDraw=True, scale=7.28504e+07 )
    samples.AddSample('169064', path='WW_2_AFII/Nominal', filekey='169064', disableDraw=True, scale=7.28185e+07 )
    samples.AddSample('169065', path='WW_2_AFII/Nominal', filekey='169065', disableDraw=True, scale=7.28791e+07 )
    samples.AddSample('169066', path='WW_2_AFII/Nominal', filekey='169066', disableDraw=True, scale=7.28656e+07 )
    samples.AddSample('169067', path='WW_2_AFII/Nominal', filekey='169067', disableDraw=True, scale=7.29113e+07 )
    samples.AddSample('169068', path='WW_2_AFII/Nominal', filekey='169068', disableDraw=True, scale=7.28175e+07 )
    samples.AddSample('169069', path='WW_2_AFII/Nominal', filekey='169069', disableDraw=True, scale=7.28429e+07 )

    #samples.AddModelSample('PhotonData'    , path='Data'       )
    #samples.AddModelSample('SingleTop'     , path='SingleTop'  , scale=-1.0)
    #samples.AddModelSample('TTBar'         , path='TTBar'      , scale=-1.0)
    #samples.AddModelSample('Wenu'          , path='Wenu'       , scale=-1.0)
    #samples.AddModelSample('Wmunu'         , path='Wmunu'      , scale=-1.0)
    #samples.AddModelSample('Wtaunu'        , path='Wtaunu'     , scale=-1.0)
    #samples.AddModelSample('ZnunuGamma'    , path='ZnunuGamma' , scale=-1.0)
    #samples.AddModelSampleGroup('Zll+Jets' , plotColor=ROOT.kCyan,
    #                       legend_name='Z+jets (data-driven)',
    #                       input_samples=[
    #                                       'PhotonData', 
    #                                       'SingleTop',
    #                                       'TTBar',
    #                                       'Wenu', 
    #                                       'Wmunu',
    #                                       'Wtaunu',
    #                                       'ZnunuGamma',
    #                                     ],
    #)

    samples.AddSampleGroup('Zll+Jets',
                           legend_name='Z+jets (data-driven)',
                         input_samples=[
                                        '107650',
                                        '107651',
                                        '107652',
                                        '107653',
                                        '107654',
                                        '107660',
                                        '107661',
                                        '107662',
                                        '107663',
                                        '107664',
                                        '146835',
                                        '146845',
                                        '146854',
                                        '146855',
                                        '146860',
                                        '146861',
                                        '146862',
                                        '146863',
                                        '146864',
                                        '146870',
                                        '146871',
                                        '146872',
                                        '146873',
                                        '146874',
                                        '146880',
                                        '146881',
                                        '146882',
                                        '146883',
                                        '147078',
                                        '147086',
                           ],
                      plotColor=ROOT.kCyan,
                      scale=1.0,

                     )
    samples.AddSampleGroup('Ztautau+Jets',
                         input_samples=[
                                        '146930',
                                        '146931',
                                        '146932',
                                        '146933',
                                        '146934',
                                        '147094',
                           ],
                      plotColor=ROOT.kCyan+2,
                      scale=1.0,

                     )

    samples.AddSampleGroup('Top',
                      input_samples=[
                                     '110001', 
                                     '108343',
                                     '108344',
                                     '108345',
                                     '108346',
                                     '117360',
                                     '117361',
                                     '117362',
                                    ],
                      plotColor = ROOT.kGreen,
                      scale=1.0,
                     )

    samples.AddSampleGroup('NonWW',
                      input_samples=[
                                     '116601',
                                     '116602',
                                     '116603',
                                     '126937',
                                     '126938',
                                     '126939',
                                     '126940',
                                     '126941',
                                     '126942',
                                     '126949',
                                     '126950',
                                     '126951',
                                     '129477',
                                     '129478',
                                     '129479',
                                     '129480',
                                     '129481',
                                     '129482',
                                     '129483',
                                     '129484',
                                     '129485',
                                     '129486',
                                     '129487',
                                     '129488',
                                     '129489',
                                     '129490',
                                     '129491',
                                     '129492',
                                     '129493',
                                     '129494',
                                     '146434',
                                     '146435',
                                     '146436',
                                     '146437',
                                     '146438',
                                     '146439',
                                     '146890',
                                     '146892',
                                     '146894',
                                     '161986',
                                     '161987',
                                     '161988',
                                    ],
                      scale=1.0,
                      plotColor = ROOT.kRed,
                     )

    samples.AddSampleGroup('WW',
                      input_samples=[
                                     '169471',
                                     '169472',
                                     '169473',
                                     '169474',
                                     '169475',
                                     '169476',
                                     '169477',
                                     '169478',
                                     '169479',
                                     '169061',
                                     '169062',
                                     '169063',
                                     '169064',
                                     '169065',
                                     '169066',
                                     '169067',
                                     '169068',
                                     '169069',
                                     '169069',
                                    ],
                      plotColor = ROOT.kBlue,
                      scale=1.0,
                     )

    samples.AddSampleGroup('Nominal',
                           input_samples = [
                                            'Zll+Jets',
                                            'Ztautau+Jets',
                                            'Top',
                                            'NonWW',
                                            'WW',
                                            ],
                           plotColor=ROOT.kRed,
                           scale=1.0,
                           isSignal=True,
                           drawRatio=True,
                          )

def print_examples() :
    pass
