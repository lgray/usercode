
import core

def main() :

    options = core.ParseArgs()

    runmod = RunModule()
    ana_config = core.ConfigureAnalysis( runmod, options )

    ana_config.Run( runmod, options )

    print '^_^ Finished ^_^'


class RunModule : 

    def __init__(self) :
        pass

    def Run(self, module_configs, options, minevt, maxevt ) :

        if maxevt == 0 :
            #maxevt = self.in_tree.GetEntries()
            maxevt = 1000

        print 'Will analyze %d events between %d and %d' %( maxevt-minevt, minevt, maxevt )
        n_saved_evt = 0

        for tidx in xrange( minevt, maxevt ) :

            #if tidx % 1000 == 0 : 
            print 'Processed %d entries' %tidx

            self.in_tree.GetEntry(tidx)

            core.copy_event( self ) # implement this

            save_event = True
            for conf in module_configs :
                save_event &= self.apply_module( conf )

            save_event = True
            
            if save_event :
                self.out_tree.Fill()
                n_saved_evt += 1


    def apply_module(self, config ) :

        keep_evt = True

        if hasattr(self, config.name ) :
            func = getattr(self, config.name )
            keep_evt &= func( config )
        else :
            print 'Cannot find function with name %s' %config.name

        return keep_evt

    def FilterEvent( self, config ) :

        pass_event = True

        nEle = self.in_tree.nEle

        if not config.pass_cut( 'cut_nLep', nEle ) : pass_event = False

        return pass_event

main()
