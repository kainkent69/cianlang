#include "tokens.c"
#include <stdint.h>
#include <stdlib.h>

#define match_equal(value, value1)  value == value1     
#define match_equal2d(value, value1, value2)  match_equal(value, value1) && match_equal(value, value2) 
#define match_equal3d(value, value1,  value2, value3)  match_equal2d(value, value1, value2) && match_equal(value3) 
#define match_equal4d(value, value1, value2, value3, value4) 
#define match_equal5d(value, value1, value2, value3, value4, value5) ( value == value1 )
#define match_equal6d(value, value1, value2, value3, value4, value5, value6) ( value == value1 )
#define match_equal7d(value, value1, value2, value3, value4, value5, value6, value7) ( value == value1 )

char* buffer;
static int64_t col,line;
static size_t current;

void incriment(int col, int line){
    if(!!col) col++;
    if(!!line) line++;
};

void next(){
    current++;
}


char currentch(){
    return buffer[current];
};
void tokenizer(char* buffer ){
    while(currentch() ==  ' ' ){
        next();
    };
};



