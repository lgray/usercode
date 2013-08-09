#ifndef ANALYSISBASE_H
#define ANALYSISBASE_H

#include <string>
#include <vector>
#include <getopt.h>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>

namespace CutType {

    enum Op {
        
        EQUAL_TO = 0,
        GREATER_THAN = 1,
        LESS_THAN = 2,
        GREATER_THAN_OR_EQUAL_TO = 3,
        LESS_THAN_OR_EQUAL_TO = 4,
        OTHER = 100
    
    };

    enum Type {

      BOOL = 0,
      INT  = 1,
      FLOAT = 2

    };
    
}

class Cut {

    public :

        Cut(CutType::Op in_op, CutType::Type in_type, 
             bool in_val_bool, int in_val_int, float in_val_float);

        void Print();
    public :

        CutType::Op   op;
        CutType::Type type;
        bool          val_bool;
        int           val_int;
        float         val_float;
      
};

class CutConfig {

    public :

        CutConfig(const std::string & conf);

        std::string GetName() const { return name; }
        const std::vector<Cut> & GetCuts() const { return cuts; }
        bool GetIsInverted() const { return is_inv; }

        void SetName( const std::string & in_name ) { name = in_name; }

        void SetCuts( const std::vector<Cut> & in_cuts) { cuts = in_cuts; }

        void SetIsInverted( bool in_is_inv ) { is_inv = in_is_inv; }

        CutType::Op attempt_logicalop_parse(const std::string & val, CutType::Type & type,
                                            int & cut_val_int, float &  cut_val_float);

        bool PassBool ( const std::string & cutname, const bool  val ) const ;
        bool PassInt  ( const std::string & cutname, const int   val ) const ;
        bool PassFloat( const std::string & cutname, const float val ) const ;

    public :

        std::string name;
        std::vector<Cut> cuts;
        bool is_inv;

};

class ModuleConfig {

    public :

        ModuleConfig(const std::string &in_name, const std::vector<CutConfig> & in_configs);

        bool PassBool ( const std::string & cutname, const bool  val ) const;
        bool PassInt  ( const std::string & cutname, const int   val ) const;
        bool PassFloat( const std::string & cutname, const float val ) const;

        std::string GetName() const {return name;}

        const CutConfig & GetCut( const std::string &name ) const ;
        bool HasCut( const std::string &name ) const;

        const std::vector<CutConfig> & GetAllCuts() const { return configs; }

    public :

        std::string name;
        std::vector<CutConfig> configs;

};

class AnaConfig {

    public :
       
        AnaConfig();

        void AddModule( const std::string &name, const std::vector<CutConfig> & in_confs );


        int size() const { return confs.size(); }

        const ModuleConfig getEntry( unsigned int i ) const ;
        const std::vector<ModuleConfig> getEntries() const;
    
    public :

        std::vector<ModuleConfig> confs;

};

struct FileEntry { 

    FileEntry() {}

    std::vector<std::string> files;
    std::vector< std::pair< std::string, std::pair< int, int > > > jobs;

};


struct CmdOptions {

    CmdOptions();

    std::string config_file;
    std::string treeName;
    std::string outputDir;
    std::string outputFile;
    std::string storagePath;
    std::vector< FileEntry > files;
    int nevt;
    bool transferToStorage;

};

CmdOptions ParseOptions(int, char**);

AnaConfig ParseConfig( const std::string & fname, CmdOptions & options );


std::vector<std::string> Tokenize(const std::string & input, const std::string &sep );


#endif
