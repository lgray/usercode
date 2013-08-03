#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <sstream>

AnaConfig::AnaConfig()
{
}

AnaConfig::AddModule(  const std::string &in_name, const std::vector<CutConfig> & in_confs ) {

    confs.push_back( ModuleConfig( in_name, in_confs) ) );

}

ModuleConfig::ModuleConfig( const std::string &in_name, const std::vector<CutConfig> & in_configs ) :
    
    name( in_name ),
    configs( in_configs )
{
}

ModuleConfig AnaConfig::getEntry( int i ) {

    if( i > confs.size()-1 ) {
        std::cout << "AnaConfig::getEntry - ERROR : entry exceeds size" << std::endl;
        return ModuleConfig( "", std::vector<CutConfig>() );
    }

    return confs[i];
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

void CutConfig::CutConfig( const std::string &cut_str ) {

    // cut string should have the formant name [val]
    std::size_t posbeg = cut_str.find("[");
    std::size_t posend = cut_str.find("]");

    // throw an error if the formatting is incorrect
    if( posbeg == std::string::npos || posend == std::string::npos ) {
      std::cout << "CutConfig - ERROR : cut string should have the format name [val]"
                << std::endl;
      return;
    }

    // get the cut name values
    std::string name = cut_str.substr(0, posbeg);
    std::string val_str = cut_str.substr( posbeg+1, posend-posbeg );

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
            cut_op   = CutType::EQUAL_TO
            cut_val_bool = true;
        }
        else if( val.find("false") != std::string::npos ) {
            cut_type = CutType::BOOL;
            cut_op   = CutType::EQUAL_TO
            cut_val_bool = false;
        }
        else {
            cut_op = attempt_logicalop_parse( val, cut_type, cut_val_int, cut_val_float );
        }

        conf_cut.push_back( Cut(cut_op, cut_type, cut_val_bool, cut_val_int, cut_val_float) );
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

    if( pos = val.find( "==" ); pos != std::string::npos ) {
        cut_op = CutType::Equal;
        mod_val = val.substr( pos+2 );
    }
    else if( pos = val.find( ">=" ); pos != std::string::npos ) {
        cut_op = CutType::GREATER_THAN_OR_EQUAL_TO;
        mod_val = val.substr( pos+2 );
    }
    else if( pos = val.find( "<=" ); pos != std::string::npos ) {
        cut_op = CutType::LESS_THAN_OR_EQUAL_TO;
        mod_val = val.substr( pos+2 );
    }
    else if( pos = val.find( ">" ); pos != std::string::npos ) {
        cut_op = CutType::GREATER_THAN;
        mod_val = val.substr( pos+1 );
    }
    else if( pos = val.find( "<" ); pos != std::string::npos ) {
        cut_op = CutType::LESS_THAN;
        mod_val = val.substr( pos+1 );
    }
    else {
        cut_op = CutType::OTHER;
    }

    // now grab the value
    if( cut_op != CutType::OTHER ) {

        std::stringstream ss( mod_val );
        int test_int;
        float test_float;

        ss >> test_int;
        if( !ss.fail ) {
            cut_val_int = test_int;
        }

        ss >> test_float;
        if( !ss.fail ) {
            cut_val_float = test_float;
        }
    }

    return cut_op;
}

bool CutConfig::PassFloat(const std::string &name, const float cutval ) {

    bool pass = true;
    BOOST_FOREACH( const Cut & cut, GetCuts() ) {

        if( cut.type != CutType::FLOAT ) {
          std::cout << "CutConfig::PassFloat - ERROR : Float cut requested for cut " << name << " but cut was not configured as a float " << std::endl;
          pass = false;
          continue;
        }

        if( cut.op == CutType::GREATER_THAN_OR_EQUAL_TO ) {
          if( !(cutval >= cut.float_val) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN_OR_EQUAL_TO ) {
          if( !(cutval <= cut.float_val) ) pass = false;
        }
        if( cut.op == CutType::GREATER_THAN ) {
          if( !(cutval > cut.float_val) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN ) {
          if( !(cutval < cut.float_val) ) pass = false;
        }
        if( cut.op == CutType::EQUAL_TO ) {
          if( !(cutval == cut.float_val) ) pass = false;
          std::cout << "CutConfig::PassFloat - WARNING : EQUAL_TO operator used for float comparison for cut " << name << std::endl;
        }

    }

    if( GetIsInverted() ) {
      pass = !pass;
    }

    return pass;
}
        
bool CutConfig::PassInt(const std::string &name, const int cutval ) {

    bool pass = true;
    BOOST_FOREACH( const Cut & cut, GetCuts() ) {

        if( cut.type != CutType::INT ) {
          std::cout << "CutConfig::PassInt - ERROR : Int cut requested for cut " << name << " but cut was not configured as an int" << std::endl;
          pass = false;
          continue;
        }

        if( cut.op == CutType::GREATER_THAN_OR_EQUAL_TO ) {
          if( !(cutval >= cut.int_val) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN_OR_EQUAL_TO ) {
          if( !(cutval <= cut.int_val) ) pass = false;
        }
        if( cut.op == CutType::GREATER_THAN ) {
          if( !(cutval > cut.int_val) ) pass = false;
        }
        if( cut.op == CutType::LESS_THAN ) {
          if( !(cutval < cut.int_val) ) pass = false;
        }
        if( cut.op == CutType::EQUAL_TO ) {
          if( !(cutval == cut.int_val) ) pass = false;
        }

    }

    if( GetIsInverted() ) {
      pass = !pass;
    }

    return pass;
}
        
bool CutConfig::PassBool(const std::string &name, const bool cutval ) {

    bool pass = true;
    BOOST_FOREACH( const Cut & cut, GetCuts() ) {

        if( cut.type != CutType::BOOL ) {
          std::cout << "CutConfig::PassBool - ERROR : Boolean cut requested for cut " << name << " but cut was not configured as a bool " << std::endl;
          pass = false;
          continue;
        }

        if( cut.op == CutType::EQUAL_TO ) {
            if( !(cutval == cut.bool_val) ) pass = false;
        }

    }

    if( GetIsInverted() ) {
        pass = !pass;
    }

    return pass;
}
        

bool ModuleConfig::PassFloat( const std::string & cutname, const float cutval ) const
{

    CutConfig & cut_conf = GetCut( cutname );

    return cut_conf.PassFloat( cutname, cutval );

}

bool ModuleConfig::PassInt( const std::string & cutname, const int cutval ) const
{

    CutConfig & cut_conf = GetCut( cutname );

    return cut_conf.PassInt( cutname, cutval );

}

bool ModuleConfig::PassBool( const std::string & cutname, const bool cutval ) const
{

    CutConfig & cut_conf = GetCut( cutname );

    return cut_conf.PassBool( cutname, cutval );

}

CutConfig AnaConfig::GetCut( const std::string & name ) const {
  
    CutConfig config;
    BOOST_FOREACH( const CutConfig & cut_conf, GetAllCuts() ) {
        if( cut_conf.GetName() == name ) {
            config = cut_conf;
            break;
        }
    }

    return config;
}




