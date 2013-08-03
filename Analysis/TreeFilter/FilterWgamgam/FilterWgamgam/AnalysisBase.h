
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
      FLOAT = 2,
      OTHER = 100

    }
    
}

class Cut {

    public :

        Cut();

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

        void SetName( const std::string & in_name ) { name = in_name; }

        void SetCuts( const std::vector<Cut> & in_cuts) { cuts = in_cuts; }

        void SetIsInverted( bool in_is_inv ) { is_inv = in_is_inv; }

        bool PassBool ( const std::string & cutname, const bool  val );
        bool PassInt  ( const std::string & cutname, const int   val );
        bool PassFloat( const std::string & cutname, const float val );

    public :

        std::string name;
        std::vector<Cut> cuts;
        bool is_inv;

}

class ModuleConfig {

    public :
        ModuleConfig(const std::string &in_name, const std::vector<CutConfig> & in_configs);

    public :

      std::string name;
      std::vector<CutConfig> configs;

      bool PassBool ( const std::string & cutname, const bool  val );
      bool PassInt  ( const std::string & cutname, const int   val );
      bool PassFloat( const std::string & cutname, const float val );

}

class AnaConfig {

    public :
       
        AnaConfig();

        AddModule( const std::string &name, const CutConfigList & confs );

        CutConfig GetCut( const std::string &name ) const ;

        int size() { return confs.size(); }

        ModuleConfig getEntry( int i );
    
    public :

        std::vector<ModuleConfig> confs;

}
