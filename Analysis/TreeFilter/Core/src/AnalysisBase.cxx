#include "Core/AnalysisBase.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

AnaConfig::AnaConfig()
{
}

void AnaConfig::AddModule(  const std::string &in_name, const std::vector<CutConfig> & in_confs ) {

    confs.push_back( ModuleConfig( in_name, in_confs) );

}

ModuleConfig::ModuleConfig( const std::string &in_name, const std::vector<CutConfig> & in_configs ) :
    
    name( in_name ),
    configs( in_configs )
{
}

const ModuleConfig AnaConfig::getEntry( unsigned int i ) const {

    if( i > confs.size()-1 ) {
        std::cout << "AnaConfig::getEntry - ERROR : entry exceeds size" << std::endl;
        return ModuleConfig( "", std::vector<CutConfig>() );
    }

    return confs[i];
}

const std::vector<ModuleConfig> AnaConfig::getEntries() const {
  return confs;
}

Cut::Cut( CutType::Op in_op, CutType::Type in_type, 
               bool in_val_bool, int in_val_int, float in_val_float ) : 
    op( in_op ),
    type( in_type ),
    val_bool( in_val_bool ),
    val_int ( in_val_int ),
    val_float( in_val_float )
{
}

void Cut::Print() { 
    std::cout << "op = " << op << " type = " << type << " bool val = " << val_bool << " int val = " << val_int << " float val = " << val_float << std::endl;
}

CutConfig::CutConfig( const std::string &cut_str ) {

    // cut string should have the formant name [val]
    std::size_t posbeg = cut_str.find("[");
    std::size_t posend = cut_str.find("]");

    // throw an error if the formatting is incorrect
    if( posbeg == std::string::npos || posend == std::string::npos ) {

      std::cout << "CutConfig - ERROR : cut string should have the format name [val]"
                << "Instead got " << cut_str << std::endl;
      return;
    }

    // get the cut name values
    std::string name = cut_str.substr(0, posbeg);
    std::string val_str = cut_str.substr( posbeg+1, posend-posbeg-1 );

    bool should_invert = false;
    // if this cut should be inverted there is a ! in the string.
    // Remove ! from the name if it is there
    std::size_t posinv = name.find("!");
    if( posinv != std::string::npos ) {
        should_invert = true;
        name = name.substr(0, posinv);
    }

    // remove whitespace from the name
    boost::algorithm::trim(name);

    const std::vector<std::string> each_cut = Tokenize(val_str, ",");

    std::vector<Cut> conf_cut;

    BOOST_FOREACH( const std::string & val_orig, each_cut ) {
      
        // copy the value string and set it to lower case (mainly for True/False -> true/false )
        std::string val( val_orig );
        std::transform(val.begin(), val.end(), val.begin(), ::tolower);

        CutType::Op cut_op;
        CutType::Type cut_type;
        bool  cut_val_bool  = 0;
        int   cut_val_int   = 0;
        float cut_val_float = 0;

        // check if it is a boolean cut first
        if( val.find("true") != std::string::npos ) {
            cut_type = CutType::BOOL;
            cut_op   = CutType::EQUAL_TO;
            cut_val_bool = true;
        }
        else if( val.find("false") != std::string::npos ) {
            cut_type = CutType::BOOL;
            cut_op   = CutType::EQUAL_TO;
            cut_val_bool = false;
        }
        else {
            cut_op = attempt_logicalop_parse( val, cut_type, cut_val_int, cut_val_float );
        }
        Cut testcut(cut_op, cut_type, cut_val_bool, cut_val_int, cut_val_float);
        testcut.Print();
        conf_cut.push_back( testcut );
    }

    SetName( name );
    SetCuts( conf_cut );
    SetIsInverted( should_invert );

}

CutType::Op CutConfig::attempt_logicalop_parse( const std::string & val, CutType::Type & type,
                                                  int & cut_val_int, float &  cut_val_float )
{
    
    CutType::Op cut_op;

    // create a string that will have the operator removed
    std::string mod_val;

    std::size_t pos;
    if( (pos = val.find( "==" ) ) != std::string::npos ) {
        cut_op = CutType::EQUAL_TO;
        mod_val = val.substr( pos+2 );
    }
    else if( (pos = val.find( ">=" ) ) != std::string::npos ) {
        cut_op = CutType::GREATER_THAN_OR_EQUAL_TO;
        mod_val = val.substr( pos+2 );
    }
    else if( (pos = val.find( "<=" ) ) != std::string::npos ) {
        cut_op = CutType::LESS_THAN_OR_EQUAL_TO;
        mod_val = val.substr( pos+2 );
    }
    else if( (pos = val.find( ">" ) ) != std::string::npos ) {
        cut_op = CutType::GREATER_THAN;
        mod_val = val.substr( pos+1 );
    }
    else if( (pos = val.find( "<" ) ) != std::string::npos ) {
        cut_op = CutType::LESS_THAN;
        mod_val = val.substr( pos+1 );
    }
    else {
        cut_op = CutType::OTHER;
    }

    boost::algorithm::trim(mod_val);

    // now grab the value
    if( cut_op != CutType::OTHER ) {

        // Check for float by the presence of a decimal point. 
        // otherwise its an int
        // May need to fix this later
        
        if( mod_val.find(".") != std::string::npos ) {
            type = CutType::FLOAT;
            std::stringstream ss( mod_val );
            ss >> cut_val_float;
        }
        else {
            type = CutType::INT;
            std::stringstream ss( mod_val );
            ss >> cut_val_int;
            // Even if this is configured as an
            // int it can be compared to a float
            // so store it as a float too
            cut_val_float = cut_val_int;
        }
            
    }

    return cut_op;
}

bool CutConfig::PassFloat(const std::string &name, const float cutval ) const {

    bool pass = true;
    BOOST_FOREACH( const Cut & cut, GetCuts() ) {

        if( cut.type != CutType::FLOAT && cut.type != CutType::INT ) {
          std::cout << "CutConfig::PassFloat - ERROR : Float cut requested for cut " << name << " but cut was not configured as a float " << std::endl;
          pass = false;
          continue;
        }

        if( cut.op == CutType::GREATER_THAN_OR_EQUAL_TO ) {
          if( !(cutval >= cut.val_float) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN_OR_EQUAL_TO ) {
          if( !(cutval <= cut.val_float) ) pass = false;
        }
        if( cut.op == CutType::GREATER_THAN ) {
          if( !(cutval > cut.val_float) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN ) {
          if( !(cutval < cut.val_float) ) pass = false;
        }
        if( cut.op == CutType::EQUAL_TO ) {
          if( !(cutval == cut.val_float) ) pass = false;
          std::cout << "CutConfig::PassFloat - WARNING : EQUAL_TO operator used for float comparison for cut " << name << std::endl;
        }

    }

    if( GetIsInverted() ) {
      pass = !pass;
    }

    return pass;
}
        
bool CutConfig::PassInt(const std::string &name, const int cutval ) const {

    bool pass = true;
    BOOST_FOREACH( const Cut & cut, GetCuts() ) {

        if( cut.type != CutType::INT ) {
          std::cout << "CutConfig::PassInt - ERROR : Int cut requested for cut " << name << " but cut was not configured as an int" << std::endl;
          pass = false;
          continue;
        }

        if( cut.op == CutType::GREATER_THAN_OR_EQUAL_TO ) {
          if( !(cutval >= cut.val_int) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN_OR_EQUAL_TO ) {
          if( !(cutval <= cut.val_int) ) pass = false;
        }
        if( cut.op == CutType::GREATER_THAN ) {
          if( !(cutval > cut.val_int) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN ) {
          if( !(cutval < cut.val_int) ) pass = false;
        }
        if( cut.op == CutType::EQUAL_TO ) {
          if( !(cutval == cut.val_int) ) pass = false;
        }

    }

    if( GetIsInverted() ) {
      pass = !pass;
    }

    return pass;
}
        
bool CutConfig::PassBool(const std::string &name, const bool cutval ) const {

    bool pass = true;
    BOOST_FOREACH( const Cut & cut, GetCuts() ) {

        if( cut.type != CutType::BOOL ) {
          std::cout << "CutConfig::PassBool - ERROR : Boolean cut requested for cut " << name << " but cut was not configured as a bool " << std::endl;
          pass = false;
          continue;
        }

        if( cut.op == CutType::EQUAL_TO ) {
            if( !(cutval == cut.val_bool) ) pass = false;
        }

    }

    if( GetIsInverted() ) {
        pass = !pass;
    }

    return pass;
}
        

bool ModuleConfig::PassFloat( const std::string & cutname, const float cutval ) const
{

    if( HasCut( cutname ) ) {
        const CutConfig & cut_conf = GetCut( cutname );
        return cut_conf.PassFloat( cutname, cutval );
    }
    else {
        //if the cut doesn't exist then pass
        return true;
    }
      

}

bool ModuleConfig::PassInt( const std::string & cutname, const int cutval ) const
{

    if( HasCut( cutname ) ) {
        const CutConfig & cut_conf = GetCut( cutname );
        return cut_conf.PassInt( cutname, cutval );
    }
    else {
        //if the cut doesn't exist then pass
        return true;
    }

}

bool ModuleConfig::PassBool( const std::string & cutname, const bool cutval ) const
{

    if( HasCut( cutname ) ) {
        const CutConfig & cut_conf = GetCut( cutname );
        return cut_conf.PassBool( cutname, cutval );
    }
    else {
        //if the cut doesn't exist then pass
        return true;
    }

}

bool ModuleConfig::HasCut( const std::string &name ) const {

    bool found=false;
    BOOST_FOREACH( const CutConfig & cut_conf, configs ) {
        if( name == cut_conf.GetName() ) {
            found = true;
            break;
        }
    }

    return found;
}

const CutConfig & ModuleConfig::GetCut( const std::string & name ) const {

    BOOST_FOREACH( const CutConfig & cut_conf, configs ) {
        if( cut_conf.GetName() == name ) {
            return cut_conf;
        }
    }

    // This will throw an exception.  Its a bit hacked, but its the desired functionality
    return configs[configs.size()];

}

AnaConfig ParseConfig( const std::string & fname, CmdOptions & options ) {

    AnaConfig ana_config;

    std::ifstream file(fname.c_str());
    std::string line;
    if( file.is_open() ) {
        
        bool read_modules = false;
        while( getline(file, line) ) {

            if( read_modules ) {

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
                boost::algorithm::trim(module_name);
                std::string module_config = module_split[1];

                // Split the module config by ';' to separate cut entries
                std::vector<std::string> cut_split = Tokenize( module_config, ";" );

                BOOST_FOREACH( const std::string & cut, cut_split ) {
                    if( cut.find_first_not_of(' ') == std::string::npos ) continue; //check if cut is only whitespace 
                    module_cuts.push_back( CutConfig( cut ) );
                }

                ana_config.AddModule( module_name, module_cuts );
            }
            else {
                // reading header information
                std::vector<std::string> header_split = Tokenize( line, ":" );
                if( header_split.size() > 1  ) {
                    std::string header_key = header_split[0];
                    std::vector<std::string> remainder( header_split.begin()+1, header_split.end() );
                    std::string header_val = boost::algorithm::join(remainder, ":");
                    if( header_key.find("files") != std::string::npos ) {// read files
                        // this is a bit complicated
                        // first remove white space
                        boost::algorithm::trim(header_val);
                        // the string should begin with [ and end with ] 
                        std::vector<std::string> file_map_entries = Tokenize( header_val, ";");
                        BOOST_FOREACH( const std::string & file_map, file_map_entries ) {
                            // split again to separate the list of file names from the
                            // list of events
                            if( !(file_map[0] == '[' and file_map[file_map.size()-1] == ']' ) ) {
                                std::cout << "ERROR in reading files.  String should begin with [ and end with ]" << std::endl;
                                continue;
                            }
                            std::string file_map_mod = file_map.substr(1, file_map.size() - 2 );
                            
                            std::vector<std::string> file_map_split = Tokenize( file_map_mod, "][" );
                            if( !file_map_split.size() == 2 ) {
                                std::cout << "ERROR in reading files.  File entry should have a list of files and a list of events" << std::endl;
                                continue;
                            }
                            // entries are printed as python tuples separated by a comma
                            std::vector<std::string> job_list = Tokenize( file_map_split[1], "," );
                            std::vector< std::pair< std::string, std::pair< int, int > > > out_job_list;
                            int jobidx = -1;
                            BOOST_FOREACH( const std::string event_vals, job_list ) {
                                jobidx++;
                                // the entry is like 0:(0-500) 
                                std::vector<std::string> job_evtrange = Tokenize( event_vals, ":" );
                                std::string jobid = job_evtrange[0];
                                std::stringstream jobstr("");
                                jobstr << "Job_" << std::setw(4) << std::setfill('0') << jobidx;

                                std::string event_vals_mod = job_evtrange[1].substr( 1, job_evtrange[1].size() - 2 );
                                std::vector<std::string> vals = Tokenize( event_vals_mod, "-");
                                if( !vals.size() == 2 ) {
                                    std::cout << "ERROR in reading files.  Events entry should have a tuple of integers" << std::endl;
                                    continue;
                                }
                                boost::algorithm::trim(vals[0]);
                                boost::algorithm::trim(vals[1]);
                                std::stringstream minstr(vals[0]);
                                std::stringstream maxstr(vals[1]);
                                int minval;
                                int maxval;
                                minstr >> minval ;
                                maxstr >> maxval ;
                                std::pair<int, int> evt_range( minval, maxval );
                                out_job_list.push_back( std::make_pair( jobstr.str(), evt_range ) );
                            }
                            std::vector<std::string> files = Tokenize(file_map_split[0], ",");
                            FileEntry entry;
                            entry.files = files;
                            entry.jobs = out_job_list;
                            options.files.push_back( entry );
                        }
                    }
                    else if( header_key.find("treeName") != std::string::npos ) {
                        options.treeName = header_val;
                        boost::algorithm::trim(options.treeName);
                    }
                    else if( header_key.find("outputDir") != std::string::npos ) {
                        options.outputDir = header_val;
                        boost::algorithm::trim(options.outputDir);
                    }
                    else if( header_key.find("outputFile") != std::string::npos ) {
                        options.outputFile = header_val;
                        boost::algorithm::trim(options.outputFile);
                    }
                    else if( header_key.find("storagePath") != std::string::npos ) {
                        options.storagePath = header_val;
                        boost::algorithm::trim(options.storagePath);
                        options.transferToStorage = true;
                    }
                    else if( header_key.find("nevt") != std::string::npos ) {
                        std::stringstream ss(header_val);
                        ss >> options.nevt;
                    }
                }
            }

            // __Modules__ line indicates the beginning of modules

            if( line.find("__Modules__") != std::string::npos ) {
                read_modules = true;
            }
        }
    }
    return ana_config;
}


CmdOptions::CmdOptions() : nevt(-1), transferToStorage(false)
{
}

CmdOptions ParseOptions( int argc, char **argv ) 
{

    CmdOptions options;
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

std::vector<std::string> Tokenize(const std::string & text, const std::string &in_sep ) {

    std::vector<std::string> out_tokens;
    std::cout << "Got sep " << in_sep << " text " << text << std::endl;
    if( text == "" ) {
        std::cout << "Tokenize : WARNING - string to split is empty" << std::endl;
        return out_tokens;
    }

    boost::char_separator<char> sep(in_sep.c_str());
    boost::tokenizer< boost::char_separator<char> > tokens(text, sep);
    BOOST_FOREACH (const std::string& t, tokens) {
      std::cout << "TOken " << t << std::endl;
        out_tokens.push_back(t);
    }

    return out_tokens;
}
        
    
