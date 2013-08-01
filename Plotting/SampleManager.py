
import os
import sys
import math
import re
import imp
import ROOT
import copy
import uuid
from array import array

ROOT.gROOT.SetBatch(False)
testarea = str(os.getenv("TestArea"))
atlasstylesearch=["/afs/cern.ch/user/j/jkunkle/public/AtlasStyle.C",
                  testarea+"/atlasstyle-00-03-04/AtlasStyle.C",
                  '/home/jkunkle/Programs/python/AtlasStyle.C']
for p in atlasstylesearch:
    if os.path.exists(p):
        ROOT.gROOT.LoadMacro(p)
        break

ROOT.SetAtlasStyle()
ROOT.gStyle.SetPalette(1)

class Sample :
    """ Store information about one sample """

    def __init__ ( self, name, **kwargs ) :

        self.name = name
        self.hist = None

        # chain is the TChain for this sample.  
        # Will be created/overwritten if Addfiles is callled.  
        # Should not be filled for a sample group
        self.chain = kwargs.get('chain', None)

        # isActive determines if the sample will be drawn, default=True
        self.isActive = kwargs.get('isActive', True) 

        # if isData is true the sample will be drawn as points with an error bar, default=False
        self.isData   = kwargs.get('isData', False)

        # if isSignal is true the sample will be drawn as a line and not stacked, default=False
        self.isSignal = kwargs.get('isSignal', False)

        # color determines the histogram or line color, default=black
        self.color = kwargs.get('color', ROOT.kBlack)

        # Provide a legend name.  by default the legend name will be the sample name
        self.legendName = kwargs.get('legendName', name)
        if self.legendName is None :
            self.legendName = name

        # if drawRatio is true, the ratio between this and the stack will be
        # drawn in the ratio box, default=False
        self.drawRatio = kwargs.get('drawRatio', False)

        # scale is the weight applied to this sample, default=1.0
        self.scale = kwargs.get('scale', 1.0)

        # groupedSamples is filled if this is a grouping of other samples.
        # if a sample is grouped, it is drawn as the sum of all entries
        # in this list.  Be careful to set isActive to False for the
        # sub samples or they will be drawn as well.  Grouped samples
        # can be further grouped default=[] 
        self.groupedSamples = kwargs.get('groupedSamples', [])


    def AddFiles( self, treeName, files ) :

        if not isinstance(files, list) :
            files = [files]

        self.chain = ROOT.TChain(treeName, self.name)

        for file in files :
            self.chain.Add(file)

    def AddGroupSamples( self, samples ) :

        if not isinstance( samples, list) :
            samples = [samples]

        self.groupedSamples += samples

    def IsGroupedSample(self) :
        return ( len( self.groupedSamples ) > 0 )
    
class SampleManager :
    """ Manage input samples and drawn histograms """

    def __init__(self, base_path, mcweight, treeName, treeNameModel='events', filename='ntuple.root', base_path_model=None) :

        #
        # This plotting module assumes that root files are 
        # organized under sample directories.  The directories
        # that are read are configured through the module passed
        # to ReadSamples
        #
        # All drawn objects are kept in SampleManager in variables
        # starting with curr_ 
        #

        self.base_path       = base_path # path to sample directories
        self.mcweight        = mcweight
        self.treeName        = treeName
        self.treeNameModel   = treeNameModel
        self.fileName        = filename
        self.base_path_model = base_path_model
        if self.base_path_model is None :
            self.base_path_model = self.base_path

        self.samples               = {}
        self.modelsamples          = {}
        self.sample_conf           = {}
        self.stack_order                 = []
        self.signals          = []
        self.grouped_samples       = {}
        self.grouped_samples_model = {}
        self.curr_hists            = {}
        self.curr_ratios           = {}
        self.curr_canvases         = {}
        self.curr_stack            = None
        self.curr_legend           = None
        self.legendLimits          = None

        # Save any plot decorations such as labels here
        # This guarantees that the objects stay in memory
        self.curr_decorations      = []

        # When variable binning is used the binning is stored
        # so that it can be used in future calls
        self.binning = None

            
    #--------------------------------
    def get_samples(self) :
        return self.samples

    #--------------------------------
    def add_decoration(self, obj) :
        self.curr_decorations.append(obj)

    #--------------------------------
    def clear_all(self) :
        """ clear all objects """
        for samp in self.samples.values() :
            samp.hist=None
        for samp in self.modelsamples.values() :
            samp.hist=None
        self.curr_canvases         = {}
        self.curr_stack            = None
        self.curr_legend           = None
        self.curr_decorations      = []

    #--------------------------------
    def clear_hists(self) :
        for samp in self.samples.values() :
            samp.hist=None
        for samp in self.modelsamples.values() :
            samp.hist=None

    #--------------------------------
    def get_grouped_sample_names(self) :
        names = []
        for samp in self.samples.values() :
            if samp.IsGroupedSample() :
                names.append(samp.name)

        return names
            

    #--------------------------------
    def AddSample(self, name, path=None, filekey=None, isData=False, scale=None, isSignal=False, drawRatio=False, plotColor=ROOT.kBlack, lineColor=None, disableDraw=False) :
        """ Create an entry for this sample """

        # get all root files under this sample
        input_files = []

        # accept path as string (-> single entry list) or list
        if not isinstance(path, list) :
            path = [path]

        # collect files from each path 
        #
        # keep a list of paths that have
        # been traveresed and print a warning
        # if we're reading inconsistent paths
        subpaths_used = []
        paths_used    = []

        input_files = self.collect_input_files( self.base_path, path, paths_used, subpaths_used, filekey=filekey) 

        if input_files :
            #
            # Print a warning if we might be getting the wrong files
            #
            n_unique_pathlenghts = len( set( [ len( upath.split('/') ) for upath in paths_used ] ) )
            if n_unique_pathlenghts > 1 :
                print 'Found ntuples in parent directories, these may be duplicates'

            thisscale = 1.0
            # multiply by command line MC weight only for MC
            if self.mcweight is not None and not isData :
                thisscale *= self.mcweight

            # multply by scale provided to this function
            if scale is not None :
                thisscale *= scale

            thisSample = Sample(name, isActive=(not disableDraw), isData=isData, isSignal=isSignal, color=plotColor, drawRatio=drawRatio, scale=thisscale)
            thisSample.AddFiles( self.treeName, input_files )

            self.samples[name] = thisSample

            # keep the order that this sample was added
            if not isData and not isSignal and not disableDraw :
                self.stack_order.append(name)

        print_prefix = "Reading %s (%s) " %(name, path )
        print_prefix = print_prefix.ljust(60)
        if not input_files :
            print print_prefix + " [ \033[1;31mFailed\033[0m  ]"
        else :
            if len(set(path) & set(subpaths_used)) != len(path) :
                print print_prefix + " [ \033[1;33mPartial\033[0m ]"
            else :
                print print_prefix + " [ \033[1;32mSuccess\033[0m ]" 

    #--------------------------------
    def collect_input_files( self, base_path, path_list, paths_used, subpaths_used, filekey=None ) :

        input_files = []
        for subpath in path_list :
            fullpath = base_path + '/' + subpath
            # if files have been provided, read them directly
            if os.path.isfile(fullpath) :
                input_files.append(fullpath)
            else : #otherwise search directories for the needed files
                for top, dirs, files in os.walk( base_path +'/' + subpath ) :
                    for file in files :
                        if filekey is not None :
                            if file.count(filekey) == 0 : 
                                continue
                        elif file.count(self.fileName) == 0 :
                            continue
                        paths_used.append(top)
                        subpaths_used.append(subpath)
                        input_files.append(top+'/'+file)

        return input_files

    #--------------------------------
    def AddSampleGroup(self, name, input_samples=[], isData=False, scale=None, isSignal=False, drawRatio=False, plotColor=ROOT.kBlack, lineColor=None, legend_name=None, disableDraw=False) :
        """Make a new sample from any number of samples that have already been added via AddSample

           For example if a process is made of a number of individual samples that each have their
           own weight, first add those samples using AddSample with their own scale ( be sure
           to also give disableDraw=True or the individual samples will be drawn).  Then call
           Group Samples with the list of input samples and the new name.  
        """

        # keep the order that this sample was added
        if not isData and not isSignal and not disableDraw :
            self.stack_order.append(name)

        if isSignal :
            self.signals.append(name)

        thisscale = 1.0
        # multply by scale provided to this function (MCweight is applied to input samples)
        if scale is not None :
            thisscale *= scale
        
        print 'Grouping %s' %name
        thisSample = Sample(name, isActive=(not disableDraw), isData=isData, isSignal=isSignal, color=plotColor, drawRatio=drawRatio, scale=thisscale, legendName=legend_name)

        for samp in input_samples :
            if samp not in self.samples :
                continue 
            is_a_grouped_sample = ( name in self.get_grouped_sample_names() )

            if is_a_grouped_sample :
                group_samples = self.samples[name].groupedSamples
                thisSample.AddGroupSamples( group_samples )
            else :
                thisSample.AddGroupSamples( samp )

        self.samples[name] = thisSample
                
    def AddModelSampleGroup(self, name, input_samples=[], isData=False, scale=None, isSignal=False, drawRatio=False, plotColor=ROOT.kBlack, lineColor=None, legend_name=None, disableDraw=False) :
        """Make a new sample from any number of samples that have already been added via AddSample

           For example if a process is made of a number of individual samples that each have their
           own weight, first add those samples using AddSample with their own scale ( be sure
           to also give disableDraw=True or the individual samples will be drawn).  Then call
           Group Samples with the list of input samples and the new name.  
        """

        thisscale = 1.0
        # multply by scale provided to this function (MCweight is applied to input samples)
        if scale is not None :
            thisscale *= scale
        
        print 'Grouping %s' %name
        thisSample = Sample(name, isActive=(not disableDraw), isData=isData, isSignal=isSignal, color=plotColor, drawRatio=drawRatio, scale=thisscale, legendName=legend_name)

        for samp in input_samples :
            is_a_grouped_sample = ( name in self.get_grouped_sample_names() )

            if is_a_grouped_sample :
                group_samples = self.samples[name].groupedSamples
                thisSample.AddGroupSamples( group_samples )
            else :
                thisSample.AddGroupSamples( samp )

        self.modelsamples[name] = thisSample


    def AddModelSample(self, name, legend_name=None, path=None, scale=1.0 , filekey=None, plotColor=ROOT.kBlack) :
        input_files = []

        if not isinstance(path, list) :
            path = [path]

        # keep a list of paths that have
        # been traveresed and print a warning
        # if we're reading inconsistent paths
        subpaths_used = []
        paths_used    = []

        input_files = self.collect_input_files( self.base_path_model, path, paths_used, subpaths_used, filekey=filekey) 
        
        if input_files :
            #
            # Print a warning if we might be getting the wrong files
            #
            n_unique_pathlenghts = len( set( [ len( upath.split('/') ) for upath in paths_used ] ) )
            if n_unique_pathlenghts > 1 :
                print 'Found ntuples in parent directories, these may be duplicates'

            thisscale = 1.0
            if scale is not None :
                thisscale *= scale

            thisSample = Sample(name, color=plotColor, scale=thisscale, legend_name=legend_name)
            thisSample.AddFiles( self.treeNameModel, input_files )
            self.modelsamples[name] = thisSample

        print_prefix = "Reading %s (%s) " %(name, path )
        print_prefix = print_prefix.ljust(60)
        if not input_files :
            print print_prefix + " [ \033[1;31mFailed\033[0m  ]"
        else :
            if len(set(path) & set(subpaths_used)) != len(path) :
                print print_prefix + " [ \033[1;33mPartial\033[0m ]"
            else :
                print print_prefix + " [ \033[1;32mSuccess\033[0m ]" 


    def ReadSamples(self, conf) :
        ImportedModule=None

        ispath = ( conf.count('/') > 0 )
        module_path = None
        if ispath :
            module_path = conf
        else :
            #get path of this script
            script_path = os.path.realpath(__file__)
            module_path = os.path.dirname(script_path) + '/' + conf

        try :
            ImportedModule = imp.load_source(conf.split('.')[0], module_path)
        except IOError :
            print 'Could not import module %s' %module_path
        
        if hasattr(ImportedModule, 'config_samples') :
            ImportedModule.config_samples(self)
        else :
            print 'ERROR - samplesConf does not implement a function called config_samples '
            sys.exit(-1)

        ImportedModule.print_examples()


    def Draw(self, varexp, selection, histpars=None, doratio=False, ylabel=None, xlabel=None, rlabel=None, logy=False, ymin=None, ymax=None, rmin=None, rmax=None, showBackgroundTotal=False, backgroundLabel='AllBkg', removeFromBkg=[], addToBkg=[], useModel=False, treeHist=None, treeSelection=None, noAtlasLabel=False  ) :

        self.MakeStack(varexp, selection, histpars, doratio, showBackgroundTotal, backgroundLabel, removeFromBkg, addToBkg, useModel, treeHist, treeSelection )

        if ylabel is None :
            binwidth = (histpars[2]-histpars[1])/histpars[0]
            ylabel = 'Events / %d GeV' %binwidth
        if rlabel is None :
            rlabel = 'Data / MC'
        self.DrawCanvas(self.curr_stack, ylabel=ylabel, xlabel=xlabel, rlabel=rlabel, logy=logy, ymin=ymin, ymax=ymax, rmin=rmin, rmax=rmax, datahists=['Data'], sighists=self.signals, doratio=doratio, noAtlasLabel=noAtlasLabel )


    def DrawSamples(self, samples, varexp, selection, histpars=None, normalize=False, doratio=False, useTreeModel=False, treeHist=None, treeSelection=None ) :
        if not isinstance( samples, list ) :
            samples = [samples]

        self.MakeSameCanvas(samples, varexp, selection, histpars, doratio, useTreeModel=useTreeModel, treeHist=treeHist, treeSelection=treeSelection )
        self.DrawSameCanvas(normalize, doratio)

    def MakeStack(self, varexp, selection, histpars=None, doratio=False, showBackgroundTotal=False, backgroundLabel='AllBkg', removeFromBkg=[], addToBkg=[], useModel=False, treeHist=None, treeSelection=None ) :

        self.clear_all()
        for sample in self.samples.values() :
            self.create_hist( sample, varexp, selection, histpars )

        if useModel :
            for sample in self.modelsamples.values() :
                self.create_hist( sample, treeHist, treeSelection, histpars, isModel=True )

        # Model is created, replace the sample in self.samples with the
        # sample having the same name in self.modelsamples
        if useModel :
            for name, samp in self.modelsamples.iteritems() :
                if name in self.samples :
                    print 'Replacing %s' %name 
                    self.samples[name].hist = samp.hist
                    self.samples[name].legendName = samp.legendName

        self.variable_rebinning(histpars) 

        ## Get background total
        bkg_name = '__AllBkg__'
        bkg_sample = Sample( bkg_name )
        bkg_sample.disableDraw=True
        bkg_sample.hist = self.samples[self.stack_order[0]].hist.Clone(bkg_name)
        for name in self.stack_order[1:] :
            bkg_sample.hist.Add(self.samples[name].hist)

        self.samples[bkg_name] = bkg_sample

        #if showBackgroundTotal :
        #    self.curr_signals[backgroundLabel] = None
        #    for idx, name in enumerate(self.stack_order+addToBkg) :
        #        if name in removeFromBkg :
        #            continue
        #        print 'Add %s to bkg ' %name
        #        if self.curr_signals[backgroundLabel] is None :
        #            self.curr_signals[backgroundLabel] = self.curr_hists[name].Clone(backgroundLabel)
        #        else :
        #            self.curr_signals[backgroundLabel].Add(self.curr_hists[name])
        #    self.sample_conf[backgroundLabel] = {'isdata': False, 'isSignal' : True, 'color' : ROOT.kRed, 'scale' : 1.0, 'legend_name' : backgroundLabel, 'drawRatio' : True }

        if doratio :
            # when stacking, the ratio is made with respect to the data.  Find the sample that
            # is labeled as data.  Throw an error if one data sample is not found
            data_samples = []
            for name, samp in self.samples.iteritems() :
                if samp.isData :
                    data_samples.append(name)
            if len(data_samples) != 1 :
                print 'Found %d data samples, the ratio requires exactly 1 data sample to exist'
                return
            self.curr_ratios['ratio'] = Sample( 'ratio', isData=True )
            self.curr_ratios['ratio'].hist = self.samples[data_samples[0]].hist.Clone( self.samples[data_samples[0]].name + '_ratio')
            self.curr_ratios['ratio'].hist.Divide( self.samples['__AllBkg__'].hist )

            for name, sample in self.samples.iteritems() :
                if name in self.signals :
                    samp = self.samples[name]
                    if samp.drawRatio :
                        self.curr_ratios[name] = Sample( 'ratio', isData=True ) 
                        self.curr_ratios[name].hist = self.samples[data_samples[0]].hist.Clone( self.samples[data_samples[0]].name + '_ratio')
                        self.curr_ratios[name].hist.Divide( samp.hist )
                        self.curr_ratios[name].hist.SetLineColor( samp.color )
                        self.curr_ratios[name].hist.GetYaxis().SetNdivisions(509, True)
                        self.curr_ratios[name].isSignal = True

            #for ratio in self.curr_ratios.values() :
            #    ratio.hist.GetYaxis().SetTitleSize(0.1)
            #    ratio.hist.GetYaxis().SetLabelSize(0.1)
            #    ratio.hist.GetXaxis().SetLabelSize(0.1)
            #    ratio.hist.GetXaxis().SetTitleSize(0.1)
            #    ratio.hist.SetStats(0)
            #    ratio.hist.SetTitle('')


        #make the stack and fill
        self.curr_stack = ROOT.THStack(varexp, '')
            
        for name in reversed(self.stack_order) :  # reverse so that the stack is in the correct order
            self.samples[name].hist.SetFillColor( self.samples[name].color )
            self.samples[name].hist.SetLineColor( ROOT.kBlack )
            #self.samples[name].hist.SetLineWidth( 2 )
            #self.samples[nam].hist.SetStats(0)
            self.curr_stack.Add(self.samples[name].hist, 'HIST')

        for name in self.signals :
            hist = self.samples[name].hist

            hist.SetLineColor( self.samples[name].color )
            #hist.GetYaxis().SetLabelSize(1)
            #hist.SetLineWidth( 2 )

        # additional formatting
        if 'Data' in self.samples :
            #self.samples['Data'].hist.SetMarkerStyle(20)
            #self.samples['Data'].hist.SetMarkerSize(1.2)
            #self.samples['Data'].hist.SetLineWidth(2)
            self.samples['Data'].hist.SetLineColor(ROOT.kBlack)
            #self.samples['Data'].hist.SetStats(0)

        # make the legend
        # In placing the legend move the bottom down 0.05 for each entry
        step = len(self.stack_order)
        self.curr_legend = self.create_standard_legend(step, doratio)

        if 'Data' in self.samples :
            legend_name = self.samples['Data'].legendName
            self.curr_legend.AddEntry(self.samples['Data'].hist, legend_name, 'PE')

        for name in self.stack_order :
            legend_name = self.samples[name].legendName
            self.curr_legend.AddEntry(self.samples[name].hist, legend_name,  'F')
        for name in self.signals :
            legend_name = self.samples[name].legendName
            self.curr_legend.AddEntry(self.samples[name].hist, legend_name, 'L')


    def MakeSameCanvas(self, samples, varexp, selections, histpars=None, useStoredBinning=False, ylabel=None, xlabel=None, doratio=False, preserve_hists=False, useModel=False, treeHist=None, treeSelection=None, normalize=False, colors=[]  ) :
        if not preserve_hists :
            self.clear_all()

        if not isinstance(selections, list) :
            selections = [selections]
        if not isinstance(samples, list) :
            samples = [samples]

        assert len(selections) == len(samples), 'selections and samples must have same length'

        # set colors
        if not colors :
            colors = [ self.samples[s].color for s in samples ]

        created_hists = []
        for idx, ( sampname, sel ) in enumerate( zip(samples, selections) ) :
            sample = self.samples[sampname]
            # In this case the same sample may be drawn multiple
            # times.  to avoid any conflicts, add new samples
            # and draw into those
            newsamp = copy.copy(sample)
            newsamp.hist=None
            newname = sample.name
            if newname in created_hists :
                newname += str(idx)

            newsamp.name = newname

            if useModel :
                self.create_hist( newsamp, treeHist, treeSelection, histpars, isModel=True)
            else :
                self.create_hist( newsamp, varexp, sel, histpars)

            self.samples[newsamp.name] = newsamp
            created_hists.append(newsamp.name)

        if not created_hists :
            print 'No hists were created from samples %s' %(', '.join(samples) )
            return created_hists

        
        self.variable_rebinning(histpars, created_hists, useStoredBinning=useStoredBinning) 

        self.curr_canvases['same'] = ROOT.TCanvas('same', 'same')
        if doratio :
            self.curr_canvases['same'].SetTopMargin(0.08)
            self.curr_canvases['same'].SetBottomMargin(0.06)
        self.curr_canvases['same'].cd()

        first = True
        for sampname, color in zip(created_hists, colors) :
            drawcmd = 'same'
            if first :
                drawcmd = ''
                first = False
            if self.samples[sampname].isSignal :
                drawcmd+='hist'

            sample = self.samples[sampname]

            sample.hist.SetLineColor( color)
            #sample.hist.SetMarkerSize( 1.0 )
            #sample.hist.SetMarkerStyle( 20 )
            sample.hist.SetMarkerColor(color )
            #sample.hist.GetXaxis().SetLabelSize(0.05)
            #sample.hist.GetXaxis().SetTitleSize(0.05)
            #sample.hist.GetYaxis().SetLabelSize(0.05)
            #sample.hist.GetYaxis().SetTitleSize(0.05)
            #sample.hist.SetStats(0)
            if ylabel is not None :
                sample.hist.GetYaxis().SetTitle( ylabel )
            if not doratio and xlabel is not None :
                sample.hist.GetXaxis().SetTitle( xlabel )

            if normalize :
                sample.hist.DrawNormalized(drawcmd+'goff')
            else :
                sample.hist.Draw(drawcmd+'goff')

        if doratio :
            rname = self.samples[created_hists[0]].name + '_ratio'
            self.curr_ratios['ratio'] = Sample( rname, isData=False )
            self.curr_ratios['ratio'].hist = self.samples[created_hists[0]].hist.Clone( rname )
            self.curr_ratios['ratio'].hist.Divide(self.samples[created_hists[1]].hist )

        return created_hists

    def create_hist( self, sample, varexp, selection, histpars, isModel=False, useStoredBinning=False) :

        sampname = sample.name
        print 'Creating hist for %s' %sampname

        # check that this histogram hasn't been drawn
        if sample.hist is not None :
            print 'Histogram already drawn for %s' %sampname
            return

        histname = str(uuid.uuid4())

        full_selection = selection

        thishist = None
        if type( histpars ) is tuple :
            if varexp.count(':') : # make a 2-d histogram
                if len(histpars) != 6 :
                    print 'varable expression requests a 2-d histogram, please provide 6 hist parameters, nbinsx, xmin, xmax, nbinsy, ymin, ymax'
                    return

                thishist = ROOT.TH2F( histname, '', histpars[0], histpars[1], histpars[2], histpars[3], histpars[4], histpars[5])
                thishist.Sumw2()
            else :
                thishist = ROOT.TH1F( histname, '', histpars[0], histpars[1], histpars[2])
                thishist.Sumw2()
        elif type( histpars ) is list :
            thishist = ROOT.TH1F( histname, '', len(histpars)-1, array('f', histpars))
            thishist.Sumw2()
        else :
            print 'No histogram parameters were passed'

        # Draw the histogram.  Use histpars as the bin limits if given
        if sample.IsGroupedSample() :
            for subsamp in sample.groupedSamples :
                print 'Draw grouped hist %s' %subsamp
                if isModel :
                    if subsamp in self.modelsamples :
                        self.create_hist( self.modelsamples[subsamp], varexp, selection, histpars, isModel=isModel )
                else :
                    if subsamp in self.samples :
                        self.create_hist( self.samples[subsamp], varexp, selection, histpars, isModel=isModel )

            self.group_sample( sample, isModel=isModel )

            return 

        else :
            if sample.chain is not None :
                sample.chain.Draw(varexp + ' >> ' + histname, full_selection, 'goff' )

        # account for overflow and underflow
        nbins       = thishist.GetNbinsX()
        overflow    = thishist.GetBinContent(nbins+1)
        overflowerr = thishist.GetBinError  (nbins+1)
        underflow    = thishist.GetBinContent(0)
        underflowerr = thishist.GetBinError  (0)

        lastbincont  = thishist.GetBinContent(nbins)
        lastbinerr   = thishist.GetBinError  (nbins)
        firstbincont = thishist.GetBinContent(1)
        firstbinerr  = thishist.GetBinError  (1)

        if overflow != 0 :
            newcont = overflow + lastbincont
            if lastbincont == 0 :
                newconterr = overflowerr
            else :
                newconterr = math.sqrt( overflowerr * overflowerr + lastbinerr * lastbinerr )
            thishist.SetBinContent(nbins, newcont)
            thishist.SetBinError  (nbins, newconterr)
            thishist.SetBinContent(nbins+1, 0)
            thishist.SetBinError  (nbins+1, 0)

        if underflow != 0 :
            newcont = underflow + firstbincont
            if firstbincont == 0 :
                newconterr = firstbinerr
            else :
                newconterr = math.sqrt( underflowerr * underflowerr + firstbinerr * firstbinerr )
            thishist.SetBinContent(1, newcont)
            thishist.SetBinError  (1, newconterr)
            thishist.SetBinContent(0, 0)
            thishist.SetBinError  (0, 0)

        # get the histogram
        sample.hist = thishist.Clone()
        sample.hist.Scale(sample.scale)

    def variable_rebinning(self, histpars, samples=[], useStoredBinning=False) :

        if not samples:
            samples = self.stack_order

        # variable rebinning
        if len(histpars) == 4 : 
            threshold = histpars[3]

            if useStoredBinning :
                binning = self.binning
            else :
                all_stack_hists = []
                for samp in samples :
                    all_stack_hists.append(self.samples[samp].hist)

                binning = self.make_variable_binning( all_stack_hists, threshold)

                # store binning for future use
                self.binning = binning

            for samp in self.samples.values() :
                if samp.hist is not None :
                    samp.hist = self.do_variable_rebinning(samp, binning)

    def group_sample(self, sample, isModel=False) :

        if not sample.IsGroupedSample() :
            print 'Trying to group a sample that is not a grouped sample'
            return
        
        subsamps = sample.groupedSamples
        print 'RUN GROUPING FOR %s' %sample.name
        print subsamps

        if isModel :
            sample.hist = self.modelsamples[subsamps[0]].hist.Clone()
            for samp in subsamps[1:] :
                sample.hist.Add( self.modelsamples[samp].hist )
                sample.hist.Draw()
            sample.hist.Scale(sample.scale)
            self.modelsamples[sample.name] = sample
        else :
            sample.hist = self.samples[subsamps[0]].hist.Clone()
            for samp in subsamps[1:] :
                sample.hist.Add( self.samples[samp].hist )
                sample.hist.Draw()
            sample.hist.Scale(sample.scale)
            self.samples[sample.name] = sample



    def DrawCanvas(self, topcan, ylabel=None, xlabel=None, rlabel=None, logy=False, ymin=None, ymax=None, rmin=None, rmax=None, datahists=[], sighists=[], doratio=False, noAtlasLabel=False ) :

        xsize = 650 
        ysize = 500
        if doratio :
            ysize = 620

        self.curr_canvases['base'] = ROOT.TCanvas('basecan', 'basecan', xsize, ysize)

        if doratio :
            self.curr_canvases['bottom'] = ROOT.TPad('bottompad', 'bottompad', 0.01, 0.01, 0.99, 0.32)
            self.curr_canvases['top'] = ROOT.TPad('toppad', 'toppad', 0.01, 0.35, 0.99, 0.99)
            self.curr_canvases['top'].SetTopMargin(0.08)
            self.curr_canvases['top'].SetBottomMargin(0.06)
            #self.curr_canvases['top'].SetRightMargin(0.05)
            #self.curr_canvases['top'].SetLeftMargin(0.11)
            self.curr_canvases['bottom'].SetTopMargin(0.05)
            self.curr_canvases['bottom'].SetBottomMargin(0.3)
            #self.curr_canvases['bottom'].SetRightMargin(0.05)
            #self.curr_canvases['bottom'].SetLeftMargin(0.11)
            self.curr_canvases['base'].cd()
            self.curr_canvases['bottom'].Draw()
            self.curr_canvases['top'].Draw()
        else :
            self.curr_canvases['top'] = self.curr_canvases['base']
            self.curr_canvases['top'].SetTopMargin(0.08)
            #self.curr_canvases['top'].SetBottomMargin(0.13)
            #self.curr_canvases['top'].SetLeftMargin(0.13)
            #self.curr_canvases['top'].SetTitle('')

        self.curr_canvases['top'].cd()
        if isinstance(topcan, ROOT.TCanvas ) :
            #topcan.SetTitle('')
            for prim in topcan.GetListOfPrimitives() :
                if isinstance(prim, ROOT.TH1F) :
                    if doratio : # canvas sizes differ for ratio, so title, label sizes are different
                        prim.GetYaxis().SetTitleSize(0.06)
                        prim.GetYaxis().SetTitleOffset(1.1)
                        prim.GetYaxis().SetLabelSize(0.06)
                        prim.GetXaxis().SetLabelSize(0.06)
                        prim.GetXaxis().SetTitleSize(0.06)
                    else :
                        prim.GetYaxis().SetTitleSize(0.05)
                        prim.GetYaxis().SetTitleOffset(1.1)
                        prim.GetYaxis().SetLabelSize(0.05)
                        prim.GetXaxis().SetLabelSize(0.05)
                        prim.GetXaxis().SetTitleSize(0.05)

            topcan.DrawClonePad()
            #self.curr_canvases['top'].GetPrimitive('title').SetTextColor(ROOT.kWhite)

        histymax = 0
        if isinstance(topcan, ROOT.THStack ) :
            histymax = topcan.GetMaximum()
        for name in datahists :
            if name in self.samples :
                max = self.samples[name].hist.GetMaximum()
                if max > histymax :
                    histymax = max

        if ymax is not None :
            histymax = ymax
        else :
            histymax *= 1.2
        if ymin is not None :
            histymin = ymin
        else :
            histymin = 0.1
        if isinstance(topcan, ROOT.THStack ) :
            topcan.SetMaximum(histymax)
            topcan.SetMinimum(histymin) #to avoid error when setting log scale
            topcan.Draw()
            if doratio : # canvas sizes differ for ratio, so title, label sizes are different
                topcan.GetHistogram().GetYaxis().SetTitleSize(0.06)
                topcan.GetHistogram().GetYaxis().SetTitleOffset(1.1)
                topcan.GetHistogram().GetYaxis().SetLabelSize(0.06)
                topcan.GetHistogram().GetXaxis().SetLabelSize(0.06)
                topcan.GetHistogram().GetXaxis().SetTitleSize(0.06)
            else :
                topcan.GetHistogram().GetYaxis().SetTitleSize(0.05)
                topcan.GetHistogram().GetYaxis().SetTitleOffset(1.1)
                topcan.GetHistogram().GetYaxis().SetLabelSize(0.05)
                topcan.GetHistogram().GetXaxis().SetLabelSize(0.05)
                topcan.GetHistogram().GetXaxis().SetTitleSize(0.05)

        if isinstance(topcan, ROOT.THStack ) :
            topcan.GetHistogram().GetYaxis().SetRangeUser(0, histymax)
        
        for name in datahists :
            if name in self.samples :
                self.samples[name].hist.Draw('PE same')
        for name in sighists : 
            if name in self.samples :
                self.samples[name].hist.Draw('HIST same')

        #if self.curr_legend is not None :
        #    if doratio :
        #        self.curr_legend.SetX2( self.curr_legend.GetX2()*1.00 )
        #        self.curr_legend.SetY2( self.curr_legend.GetY2()*1.05 )
        #        self.curr_legend.SetY1( self.curr_legend.GetY1()*0.95 )
            
        self.curr_legend.Draw()

        if not noAtlasLabel :
            atlaslabel = ROOT.TLatex()
            atlaslabel.SetNDC()
            atlaslabel.SetTextSize( 0.05 )
            atlaslabel.SetText(0.3, 0.85, '#it{ATLAS Internal}')
            atlaslabel.Draw()
            self.add_decoration(atlaslabel)

        if doratio :
            self.curr_canvases['bottom'].cd()
            for idx, (name, ratiosamp) in enumerate(self.curr_ratios.iteritems()) :
                drawopt = 'same'
                if idx == 0 :
                    drawopt = ''
                if ratiosamp.isSignal :
                    drawopt += 'HIST'

                ratiosamp.hist.GetYaxis().SetTitleSize(0.11)
                ratiosamp.hist.GetYaxis().SetTitleOffset(0.6)
                ratiosamp.hist.GetYaxis().SetLabelSize(0.12)
                ratiosamp.hist.GetXaxis().SetLabelSize(0.12)
                ratiosamp.hist.GetXaxis().SetTitleSize(0.12)
                ratiosamp.hist.GetXaxis().SetTitleOffset(1.0)
                ratiosamp.hist.SetStats(0)
                ratiosamp.hist.SetTitle('')
                ratiosamp.hist.GetYaxis().CenterTitle()
                ratiosamp.hist.GetYaxis().SetNdivisions(506, True)
                if rlabel is not None :
                    ratiosamp.hist.GetYaxis().SetTitle(rlabel)
                if rmin is not None and rmax is not None :
                    ratiosamp.hist.GetYaxis().SetRangeUser(rmin, rmax)

                ratiosamp.hist.Draw(drawopt)


            left_edge = self.curr_ratios.values()[0].hist.GetXaxis().GetXmin()
            right_edge = self.curr_ratios.values()[0].hist.GetXaxis().GetXmax()

            oneline = ROOT.TLine(left_edge, 1, right_edge, 1)
            oneline.SetLineStyle(3)
            oneline.SetLineWidth(2)
            oneline.SetLineColor(ROOT.kBlack)
            self.add_decoration(oneline)
            oneline.Draw()

        if xlabel is not None :
            if doratio :
                for ratiosamp in self.curr_ratios.values() :
                    ratiosamp.hist.GetXaxis().SetTitle(xlabel)
            else :
                if isinstance(topcan, ROOT.THStack ) :
                    topcan.GetHistogram().GetXaxis().SetTitle(xlabel)

                for samp in self.samples.values() :
                    if samp.hist :
                        samp.hist.GetXaxis().SetTitle(xlabel)

        if ylabel is not None :
            if isinstance(topcan, ROOT.THStack ) :
                topcan.GetHistogram().GetYaxis().SetTitle(ylabel)
            for samp in self.samples.values() :
                if samp.hist :
                    samp.hist.GetXaxis().SetTitle(ylabel)

        if logy :
            self.curr_canvases['top'].SetLogy()

    def DrawSameCanvas(self, normalize=False, doratio=False, xlabel=None, ylabel=None) :

        self.curr_canvases['same'] = ROOT.TCanvas('samecan', 'samecan')
        #self.curr_canvases['same'].SetBottomMargin(0.12)
        #self.curr_canvases['same'].SetLeftMargin(0.12)

        for idx, sample in enumerate(self.samples.values()) : 
            #sample.hist.GetYaxis().SetTitleSize(0.05)
            #sample.hist.GetYaxis().SetLabelSize(0.05)
            #sample.hist.GetXaxis().SetLabelSize(0.05)
            #sample.hist.GetXaxis().SetTitleSize(0.05)
            sample.hist.SetTitle('')
            if xlabel is not None :
                sample.hist.GetXaxis().SetTitle(xlabel)
            if ylabel is not None :
                sample.hist.GetYaxis().SetTitle(ylabel)
            if idx == 0 :
                if normalize :
                    sample.hist.DrawNormalized()
                else :
                    sample.hist.Draw()
            else :
                if normalize :
                    sample.hist.DrawNormalized('same')
                else :
                    sample.hist.Draw('same')

        if doratio :
            self.curr_canvases['ratio'] = ROOT.TCanvas('ratiocanvas', 'ratiocanvas')
            self.curr_ratios.values()[0].hist.Draw()

    def CompareSelections( self, varexp, selections, insamples, histpars=None, same=False, normalize=False, doratio=False, ratiosamp=0, ylabel=None, xlabel=None, rlabel=None, useModel=False, treeHist=None, treeSelection=None, noAtlasLabel=False, colors=[], legend_entries=[] ) :
        assert len(selections) == len(insamples), 'selections and samples must have same length'

        if len(colors) != len( selections ) :
            if colors :
                print 'Size of colors input does not match size of vars input!'

            colors = [ self.samples[samp].color for samp in insamples ]

        if not same :
            self.clear_all()

        if ylabel is None :
            bin_width = ( histpars[2] - histpars[1] )/histpars[0]
            ylabel = 'Events / %d GeV' %bin_width
            if normalize :
                ylabel = 'Normalized ' + ylabel

        if rlabel is None :
            rlabel = 'Data / MC'

        created_hists = self.MakeSameCanvas(insamples, varexp, selections, histpars=histpars, preserve_hists=True, useModel=useModel, treeHist=treeHist, treeSelection=treeSelection, normalize=normalize, xlabel=xlabel, ylabel=ylabel, doratio=doratio, colors=colors )
        if not created_hists :
            print 'No histograms were created'
            return

        hists_tmp = list(created_hists) # create a temporary list that will be modified
        numsample = hists_tmp[ratiosamp]
        hists_tmp.pop(ratiosamp)
        for idx, histname in enumerate(hists_tmp) :
            if idx == 0 :
                name = 'ratio'
            else :
                name = 'ratio' + str(idx)

            self.curr_ratios[name] = Sample( name, isData=False )
            self.curr_ratios[name].hist = self.samples[histname].hist.Clone('ratio')
            divide_scale = 1.0
            if normalize :
                self.curr_ratios[name].hist.Divide( self.curr_ratios[name].hist, self.samples[numsample].hist, 1.0/self.curr_ratios[name].hist.Integral(), 1.0/self.samples[numsample].hist.Integral() )
            else :
                self.curr_ratios[name].hist.Divide( self.curr_ratios[name].hist, self.samples[numsample].hist )

            if self.samples[histname].isSignal :
                self.curr_ratios[name].isSignal = True

        # make the legend
        # In placing the legend move the bottom down 0.05 for each entry
        step = len(created_hists)
        self.curr_legend = self.create_standard_legend(step, doratio)

        # check for an input legend_entries
        if not legend_entries : 
            legend_entries = list(created_hists)

        for idx, sampname in enumerate(created_hists) :
            drawopt = 'PE'
            if self.samples[sampname].isSignal :
                drawopt = 'L'
            legname = legend_entries[idx]
            self.curr_legend.AddEntry(self.samples[sampname].hist, legname,  drawopt)

            self.samples[sampname].hist.SetLineColor( colors[idx] )
            self.samples[sampname].hist.SetMarkerColor( colors[idx] )

        self.DrawCanvas(self.curr_canvases['same'], ylabel=ylabel, xlabel=xlabel, rlabel=rlabel, doratio=doratio, noAtlasLabel=noAtlasLabel)

    def Draw2D( self, varexp, selection, sample_name, histpars=None, drawopts='', xlabel=None, ylabel=None) :

        self.clear_hists()
        self.create_hist( self.samples[sample_name], varexp, selection, histpars)

        if xlabel is not None :
            self.samples[sample_name].hist.GetXaxis().SetTitle( xlabel )
        if ylabel is not None :
            self.samples[sample_name].hist.GetYaxis().SetTitle( ylabel )
            
        self.curr_canvases['base'] = ROOT.TCanvas('basecan', '')
        self.curr_canvases['base'].SetRightMargin(0.12)
        self.curr_canvases['base'].cd()

        self.samples[sample_name].hist.Draw(drawopts)

    def CompareVars( self, varexps, selection, sample_name, histpars=None, same=False, normalize=False, doratio=False, ylabel=None, xlabel=None, colors=[], labels=[] ) :

        if not isinstance( varexps, list ) : varexps = [varexps]

        if len(colors) != len( varexps ) :
            if colors :
                print 'Size of colors input does not match size of vars input!'

            colors = [ROOT.kBlack]*len(varexps)

        if len(labels) != len(varexps) :
            if labels :
                print 'Size of labels does not match size of vars input!'
            labels = varexps

        sample = self.samples[sample_name]
        created_hists = []
        for var in varexps :
            self.clear_hists()
            newsamp = copy.copy(sample)
            newsamp.hist = None
            newsamp.name = '%s_%s' %(sample.name, var)
            created_hists.append(newsamp.name)
            self.create_hist( newsamp, var, selection, histpars)
            self.curr_hists[newsamp.name] = newsamp.hist.Clone(var)

        self.curr_canvases['same'] = ROOT.TCanvas('same', '')
        for idx, name in enumerate( created_hists ) :
            self.curr_hists[name].SetMarkerColor( colors[idx] )
            self.curr_hists[name].SetLineColor( colors[idx] )

            if idx == 0 :
                if normalize :
                    self.curr_hists[name].DrawNormalized('hist')
                else :
                    self.curr_hists[name].Draw('hist')
            else :
                if normalize :
                    self.curr_hists[name].DrawNormalized('samehist')
                else :
                    self.curr_hists[name].Draw('samehist')

        self.DrawCanvas(self.curr_canvases['same'])

        # make the legend
        # In placing the legend move the bottom down 0.05 for each entry
        step = len(varexps)
        self.curr_legend = self.create_standard_legend(step, doratio)

        for var, lab in zip( varexps, labels ) :
            histname = '%s_%s' %(sample.name, var)
            self.curr_legend.AddEntry(self.curr_hists[histname], lab, 'L' )
            
        self.DrawCanvas(self.curr_canvases['same'], ylabel=ylabel, xlabel=xlabel, doratio=doratio)


    def MakeCutflowTable(self, var, cut_selection, labels, histpars, useModel=False, useTreeModel=False) :

        if not isinstance(cut_selection, list) :
            cut_selection = [cut_selection]
        if not isinstance(labels, list) :
            labels = [labels]

        if len(cut_selection) != len(labels) :
            print 'Number of labels much match number of cuts'
            return

        table_entries = {}
        cut_order = []
        
        for selection, label in zip(cut_selection, labels) :
            cut_order.append(label)
            table_entries[label] = {}

            self.clear_all()
            for name, chain in self.samples.iteritems() :

                histname = 'hist_%s' %(name)

                full_selection = selection
                print 'Drawing sample : %s' %name

                thishist = None
                if type( histpars ) is tuple :
                    thishist = ROOT.TH1F( histname, histname, 1, histpars[1], histpars[2] )
                    thishist.Sumw2()

                if useTreeModel and name in self.treemodels  :
                    print 'Tree model is disabled'
                #if useTreeModel and name in self.treemodels  :
                #    # Draw the histogram.  Use histpars as the bin limits if given
                #    self.treemodels[name].Draw(treeHist+ ' >> ' + histname, treeSelection, 'goff' )
                #else :
                #    # Draw the histogram.  Use histpars as the bin limits if given
                chain.Draw(var+ ' >> ' + histname, full_selection, 'goff' )

                # get the histogram
                if self.sample_conf[name]['isSignal'] :
                    self.curr_signals[name] = thishist.Clone()
                    #self.curr_signals[name] = ROOT.gPad.GetPrimitive(histname)
                else :
                    self.curr_hists[name] = thishist.Clone()
                    #self.curr_hists[name] = ROOT.gPad.GetPrimitive(histname)

            
            mcsum = 0.0
            mcerrsq = 0.0
            for name, hist in self.curr_hists.iteritems() :
                val = hist.GetBinContent(1)
                err = hist.GetBinError(1)
                table_entries[label][name] = (val, err)
                if name is not 'Data' :
                    mcsum += val
                    mcerrsq += err*err
            table_entries[label]['MC'] = (mcsum, math.sqrt(mcerrsq))
            dataval = table_entries[label]['Data'][0]
            dataerr = table_entries[label]['Data'][1]
            ratioval = dataval/mcsum
            ratioerr = dataval/mcsum * math.sqrt( ( dataerr/dataval )*( dataerr/dataval ) + ( mcerrsq/(mcsum*mcsum) ) )
            table_entries[label]['Data/MC'] = (ratioval, ratioerr)

        for name in cut_order :
            print table_entries[name]

        second_table = {}
        for cut, table in table_entries.iteritems() :
            second_table.setdefault(cut, {})

            for samp in ['Data','MC', 'Data/MC'] :
                second_table[cut][samp] = table_entries[cut].pop(samp)

        table_text_1 = self.LatexCutflowTable(table_entries, cut_order, self.stack_order)
        table_text_2 = self.LatexCutflowTable(second_table, cut_order, ['MC', 'Data', 'Data/MC'])

        self.MakeLatexDocument(tables=[table_text_1, table_text_2])


    def LatexCutflowTable(self, entries, roworder, colorder, options={}) :
        print roworder
        print entries.values()[0]

        table = []
        header = []
        header.append('Cut Flow')
        header+= colorder
        table.append(header)

        for rowname in roworder :
            entry = entries[rowname]
            cutline = []
            cutline.append(rowname)
            print 'Row %s has entry' %rowname
            print entry
            for sampname in colorder :
                data =  entry[sampname]
                if data[0] > 1000 :
                    cutline.append(r'%.2e $\pm$ %.2f'  %( data[0], data[1]) )
                elif data[0] < 1 :
                    cutline.append(r'%.3f $\pm$ %.3f'  %( data[0], data[1]) )
                else :
                    cutline.append(r'%.2f $\pm$ %.2f'  %( data[0], data[1]) )
            table.append(cutline)

        print 'TABLE'
        print table

        # loop over the inputs and collect length information
        column_width = []
        numcol = len(table[0]) # the length of any row (first here) is the column width
        for colnum in range(0, numcol) :
            widths = []
            for row in table :
                colentry = row[colnum]
                widths.append(len(colentry))
            column_width.append(max(widths))
            #column_width[table[0][colnum]] = max(widths)

        table_text = []
        table_text.append(r'\begin{table}')
        table_text.append(r'\scriptsize')

        ncutcol = len(colorder)
        table_text.append(r'\begin{tabular}{ | l | %s |}\hline' %( '|'.join([ ' c ' ]*ncutcol)))
        for row in table :
            text_entries = []
            print row
            for coln, ent in enumerate(row) :
                print column_width[coln]
            row_entry = ' %s ' %( ' & '.join([ ent.ljust(column_width[coln])  for coln, ent in enumerate(row) ] ))
            row_entry.rstrip('&&')
            row_entry += r' \\'
            table_text.append(row_entry)

        table_text[-1] += r' \hline'
        table_text.append('\end{tabular}\end{table}')

        print '\n'.join(table_text)
        return table_text

    def MakeLatexDocument(self, tables=[]) :
    
        doc_text = []
        doc_text.append(r'\documentclass[12pt]{article}')
        doc_text.append(r'\usepackage[top=3cm,bottom=2cm,left=1cm,right=1cm] {geometry}')
        doc_text.append(r'\begin{document}')
        doc_text.append(r'\begin{center}')
        for table_text in tables :
            doc_text += table_text
        doc_text.append(r'\end{center}')
        doc_text.append(r'\end{document}')

        print 'DOC'
        print '\n'.join(doc_text)
        tmpname = '/tmp/latex_table'
        tmpfile = open(tmpname+'.tex', 'w')
        tmpfile.write('\n'.join(doc_text))
        tmpfile.close()

        os.system(r'cd /tmp ; latex %s' %tmpname+'.tex')
        os.system(r'dvips %s -o %s' %(tmpname+'.dvi', tmpname+'.ps' ) )
        os.system(r'gv %s' %tmpname+'.ps')

    # ------------------------------------------------------------
    #   Do variable rebinning for a stack plot
    # ------------------------------------------------------------
    def make_variable_binning(self, stacklist,threshold=3):

        if not isinstance(stacklist, list) :
            stacklist = [stacklist]
    
        # sum stack list
        sum = stacklist[0].Clone('sum')
        sum.Reset()
        for h in stacklist:
            sum.Add(h)
    
        # make binning
        bins=[]
        axis=sum.GetXaxis()
        bins.append(axis.GetXmin())
        count=0
        for b in range(1, sum.GetNbinsX()+1):
            # this special case is to not extend the first 
            # filled bin to the edge of the histogram
            if sum.GetBinContent(b)>0 and count==0 and len(bins)==1:
                bins.append(axis.GetBinLowEdge(b))
            count+=sum.GetBinContent(b)
            if count>threshold:
                bins.append(axis.GetBinUpEdge(b))
                count=0
        if count!=0:
            bins.append(axis.GetXmax())
        print bins,count
        return bins
    
    # ------------------------------------------------------------
    #   Do variable rebinning for a stack plot
    # ------------------------------------------------------------
    def do_variable_rebinning(self, samp,bins):
        newhist=ROOT.TH1F(samp.hist.GetName()+"_rebin",
                          samp.hist.GetTitle()+";"+samp.hist.GetXaxis().GetTitle()+";"+samp.hist.GetYaxis().GetTitle(),
                          len(bins)-1,
                          array('d',bins))
        a=samp.hist.GetXaxis()
        newa=newhist.GetXaxis()
        for b in range(1, samp.hist.GetNbinsX()+1):
            newb=newa.FindBin(a.GetBinCenter(b))
            val=newhist.GetBinContent(newb)
            err=newhist.GetBinError(newb)
            ratio_bin_widths=newa.GetBinWidth(newb)/a.GetBinWidth(b)
            val=val+samp.hist.GetBinContent(b)/ratio_bin_widths
            err=math.sqrt(err*err+samp.hist.GetBinError(b)/ratio_bin_widths*samp.hist.GetBinError(b)/ratio_bin_widths)
            newhist.SetBinContent(newb,val)
            newhist.SetBinError(newb,err)
    
        return newhist

    # ----------------------------------------------------------------------------
    def create_standard_legend(self, nentries, doratio=False) :

        legend_limits = { 'x1' : 0.68, 'y1' : 0.82-0.06*nentries, 'x2' : 0.92, 'y2' : 0.82 }

        # modify for different canvas size
        if doratio :
            legend_limits['y1'] = legend_limits['y1']*0.95
            legend_limits['y2'] = legend_limits['y2']*1.05

        # grab stored legend limits
        if self.legendLimits :
            legend_limits = self.legendLimits

        leg = ROOT.TLegend(legend_limits['x1'], legend_limits['y1'],
                           legend_limits['x2'], legend_limits['y2'])
        leg.SetFillColor(ROOT.kWhite)
        leg.SetBorderSize(0)

        return leg
    
    # ----------------------------------------------------------------------------
    def store_current_legend_placement(self) :
    
        self.legendLimits = {}
    
        leg = self.curr_legend
        self.legendLimits['x1'] = leg.GetX1NDC()
        self.legendLimits['y1'] = leg.GetY1NDC() 
        self.legendLimits['x2'] = leg.GetX2NDC()
        self.legendLimits['y2'] = leg.GetY2NDC()

        print self.legendLimits
