/** ast.c **/
/**
 * ASTs are types of tokens that is already been made with this is done so that     
 **/
#include "tokens.c"

#define  typenames(value) _##value 
#define  typenames2d(value, value1) _##value##_##value1
#define  typenames3d(value, value1, value2) _##value##_##value1##_##value2
#define  typenames4d(value, value1, value2,value3) _##value##_##value1##_##value2##_##value3  
enum TYPES {
  // basic types 
  typenames(int),
  typenames(uint),
  typenames(char),
  typenames(string),
  typenames(bool),

  // unsigned types
  typenames2d(unsigned, char),
  typenames2d(unsigned, int),
  typenames2d(unsigned, uint),

  // long types 
  typenames2d(long, int),
  typenames2d(long,uint),
  // long long types 
  typenames3d(long, long, int),
  // long long unsigned types 
};



enum FIXED_SIZE {
  typenames(default),     // default will not be that hard for few things around 
  typenames2d(8,bits),    //  8 bits sized     
  typenames2d(16,bits),   //  16 bits sized 
  typenames2d(32,bits),   //  32 bits sized
  typenames2d(64,bits),   //  64 bits sized 
  typenames2d(128,bits),  //  128 bits sized  
  typenames2d(256,bits),  //  256 bits sized
};



union ast_t {
    struct declarations {
        int* qualifiers;
        enum TYPES type;
        enum FIXED_SIZE fixed;
        union ast_t* value;
        
    } delaration;


    struct literals {
        enum LITERALS type;
        void* value;
    } literals;


    struct fcall {
        char* name;
        union ast_t* args;
    } funcall;


    struct identifier {
        char* name;
    } identifier;

    struct expression {
        union ast_t* expressions;
    } expression;

};
