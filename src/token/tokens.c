#include <stdint.h>


char* keywords[] = {
  "const", // constant value 
  "let",   // let  value 
  "nil",   //  null  value just to shorten the words 
  "sizeof",
  "typeof",
  "export",
  "memoid",
  "auto",
  "for",
  "if",
  "iferr",
  "else", 
  "while",
  "do",
  "true",
  "false",
  "delete"
};


char* defualt_qualifier[] = {
  "memoid",
  "atomic",
  "auto"
};

char* default_types[] = {
  "string",    // a ascii array of characters but will automatically accept utf-8 
   "bool",     // formally going to be a acceptable types 
  "unsigned",  // the unsigned value of anything 
  "long",      // the long for int and uint even float
  "short",     // making a short int
  "char",      // the character type
  "int",       // the int typed
  "uint",      // the uint type
  "float",     // the floating point type 
  "double",    // the double type
  "namespace", // the namespace to avoid naming conflict
  "struct",    // the struct type
  "interface", // the interface type
  "cls",       // maybe if i decide to make it oop
  "tupple",    // it is the double or multiple possible type
  "union",     // the union is a type with same pointer but differnt kind
  "others",     // i dont know a lot yet
  "",
  ""
};


enum TOKEN_TYPES {
  KW,         // the keyword 
  IDTFR,      // identifier 
  MCR,        // macro
  MCR_N,      // macroname
  LTR,        // literals
  PTR,        // pointer 
  ADR,        // address 
  DPTR,       // derferencing 
  TYP,        // type 
  BRCT,       // bracket  
  BW,         // bitwise operation 
  INCR,       // inctement
  DCR,        // decrement 
  ASSGN,      // assignment 
  TERNRY,     // ternary operatior
};


char* reserved_macro[]  = {
  "alloc",         // memory allocation 
  "tempalloc",
   "threads",
   "process",
  "",
  "",
  "",
  "",
  "",
  ""
};

/**
 * This reserved word will be changed and updated at compile time
 */
char* reserved_constants[] = {
  "__stack__",         // results the  stack trace of where it is called
  "__filename",        // the file name of the where file is called
  "__dirname",         // the current directory it is called 
  "__osname__",        // the os name linux apple and others 
  "__arctype__",       // the archeticture type 32bit or 64bit 
  "__osversion__",     // the version of os 
  "__cpu__",           // a string version of it's cpu 
};




/** sub token types of the token literals */
enum LITERALS {
  STR,   // string literals 
  FLT,   // float literals 
  INT,   // interger literals
  BIN,   // binary literals 
  OCT,   // octa literals 
  REG,   // regex literals  
  BOL,   // boolean literals 
  TEMP   // the template string `${}` // inspiration from javascript
};



/** the increment types */
enum ICRIMENT {
  POST,
  PRE
};


typedef struct basetoken {
  uint64_t columns, line;
  char* value;
  enum TOKEN_TYPES type;
  int s_type;
} basetoken_t;


