#include "FilterWgamgam/RunAnalysis.h"
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>

int main(int argc, char **argv)
{

    CmdOptions options = ParseOptions( argc, argv );

    // Parse the text file and form the configuration object
    AnaConfig ana_config = ParseConfig( options.config_file );

    // loop over configured modules
    for( int i = 0; i < config.size() ; i++ ) {
        
        // apply the module
        ApplyModule( ana_config.getEntry(i) );
    }

}

void ApplyModule( const ModuleConfig & config ) {

    if( config.module == "FilterElec" ) {
        FilterElec( config );
    }

}

void FilterElec( const ModuleConfig & config ) {

    int nEleOut = 0;
    for( int idx = 0; idx < IN::nEle; ++idx ) {
        
        float elePt = IN::elePt[idx];
        //etc

        if( !config.PassFloat( "elePt", elePt ) ) continue;
         
        nEleOut++;
        OUT::elePt.push_back(elePt);
    }

    OUT::nEle = nEleOut;
}     

CmdOptions ParseOptions( int argc, char **argv ) 
{

    CmdOptions options;
    options.files.clear();
    const struct option longopts[] =
         {
         {"conf_file", required_argument,        0, 'c'},
         {0,0,0,0},
    };

    int iarg=0;

    //turn off getopt error message
    
    while(iarg != -1) {
      iarg = getopt_long(argc, argv, "c:", longopts, 0);
      switch (iarg) {
        case 'c' : 
          {
          options.config_file = optarg;
          break;
          }
      }
    }

    return options;
}

AnaConfig ParseConfig( const std::string & fname ) {

    AnaConfig ana_config;

    std::ifstream file(fname);
    std::string line;
    for( std::string line; getline( file, lilne ) ) {

        // information to be collected
        std::string module_name;
        std::vector<CutConfig> module_cuts;

        // Split by : character.  The 0th entry is the
        // module name
        std::vector<std::string> module_split = Tokenize( line, ":" );
        if( module_split.size() != 2 ) {
            std::cout << "ParseConfig - ERROR : config file entry does not contain a \":\" "
                      << "character.  Please check the config file" << std::endl;
            continue;
        }
        module_name = module_split[0];
        std::string module_config = module_split[1];

        // Split the module config by ';' to separate cut entries
        std::vector<std::string> cut_split = Tokenize( module_config, ";" );

        BOOST_FOREACH( const std::string & cut, cut_split ) {
            module_cuts.push_back( CutConfig( cut ) );
        }

        ana_config.AddModule( module_name, module_cuts );
    }

    return ana_config;
}
