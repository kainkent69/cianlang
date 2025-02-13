/** tokens.c **/
#include <stdint.h>

char* keywords[] = {
  "const",      // constant value 
  "let",        // let  value 
  "nil",        //  null  value just to shorten the words 
  "sizeof",     //  a keyword for knowing the sizeof anything in bytes
  "typeof",     //  knowing the typeof something with different variants
  "export",     // making a declaration to be accessible outside the main file 
  "for",        // for looping for something   
  "if",         // for making conditional
  "iferr",      // just like an if but for catching error
  "else",       // else is somthing that is making for other things around
  "while",      // is a while loop 
  "do",         // is a do loop 
  "true",       // is a boolean literal 
  "false",      // is a false boolean literal 
  "delete",     // for deleting memory 
  "closure",    // for making an functions inside a function but but does not allow nesting
};


char* defualt_qualifier[] = {
  "memoid",     // a qualifier that says something is a memory based output
  "atomic",     // for making a atomic variables 
  "auto",       //  is a memory safe memoid that does not need manual memory allocation
  "regions",    // is a type of arena memory that uses single memory constant for other things,
  "fast",       // this qualifier is for making fast but more memory ussage   
  "temp",       // is a qualifier for mem and is temporary memory allocation and will be freed after use  
};

// NOTE: the rules of qualifer that they must folow the currect order atomic should not be memoid  and others 
// new qualifier will be done with metaprogramming  and there also other scopes and user defined qualifers should be userd first 
// there are qualiifer that does not need anything else 


/** 
 * // basic memoid usses 
 * memoid char[] buffer = @alloc(50);  //  needs freeing  error in strict safe mode or -ssm 
 * delete buffer; // disable memory warning 
 * 
 * // temporray use of memoid 
 * memoid temp char[] buffer = @alloc(50); // no need to free because after use will be freed
 * 
 * // fast memoid 
 *  momoid temp fast char[] buffer = @alloc(50);   
 *  
 * // let the compiler set memory slower more with overhead but secure 
 *  memoid auto char[] buffer = value; // do not need to alloc  
 * 
 * stack allocation will just be the same
 *  moemoid char[const] = @stackalloc(50); // will throw an erro if there is no memory available  
 *
 * const freeoriginal = true;
 * const paniconoverflow  = false; // will cause error 
 * const limit = 0; // means no limit  
 *
 * // changing memory
 *  char newbuffer = @alloc(buffer, newmeme, { optional values }, limit, freeoriginal, panic, fn onerror(error){} )
 *
 *  // regions will always be void** memoid
 *   void** memodid region = @alloc(@memory(20, "mib"));
 *
 *  NOTE: it support function overirde as long as types dont overlaps  
 * */


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
  "others",     // i dont know a lot yet so keep them going 
  "tuple",
};


/* macro names that no one can remake */
char* reserved_macro[]  = {
  "alloc",         // memory allocation 
  "tempalloc",
   "threads",
   "process",
};


/**
 * This reserved word will be changed and updated at compile time
 */
char* reserved_constants[] = {
  "__stack__",         // results the  stack trace of where it is called
  "__filename__",        // the file name of the where file is called
  "__dirname__",         // the current directory it is called 
  "__osname__",        // the os name linux apple and others 
  "__arctype__",       // the archeticture type 32bit or 64bit 
  "__osversion__",     // the version of os 
  "__cpu__",           // a string version name and type of it's cpu 
  "__location__"       // the location of the project 
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


