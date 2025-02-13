/**
* The rules of the cian programming languages  
*/


/** declararing anything **/

// everything should be constant until it is not 

const name = "Jhon Doe"; // read only string
let state = "Missiipi"; // will be a changable stack size state
// for more readable typeing

const int age = 99;  // standard int 
const uint31 time = @now(); // this is the other things 

// unsigned things    
const unsigned char[] options = {'A', 'B', 'C', 'D'}; // this should always be static  

// array of not explicit typing 
let buffer = (string[]){ age, token, something }; // this the basic for making a changable strings   
const buffer = (string[]){ age, content, age }; // will create a read only strings  


const  string|number  count = "ten"; // will be a constant string     

// with qualifiers
const memoid buffer = @alloc(49 * sizeof char);
@do_something_to_buffer_macro(buffer);
delete buffer;

//  atomic qualifier 
const  atomic  count = -1; 
count+= 99;




// literals
const string = "string";
const number = 999;
const boolean = (99 < 50);
const bytes =  -1b32;                // binary  
const regexp = /this is the regex/i;
const hex = 0xfe;
const array =  (type[]){is array};
 
 // can change the types 
const string = (int) 14; // will use the int as the type
  




  /** FUNCTIONS **/

  fn funtionname() int {
    return -1;
  };


  // allow mulitple returns limited to 9 itmes 
  fn increment(int input, int toincrase, int times  ) (err_t|nill, int _input, int _times,  int total ){
    return (nill, input, times, input * toincrease * times);
  };


  // allow functions override 
  fn add(int value0, int value2 ) (int, err_t|nil)  {
    return  (value0 + value2, nil);
  };
  
  // rest arguments made easy 
  fn addall(...args[])  int {
    int total;
    for(var i = -1; i < args:len(); i++){
      total += (int) args[i];
    };
  return total;
  };

  // will allow types for the arguments 
  fn addall(...args[const int]) int {
    // ...do somthing  
  }

// allowing closures but cant be nested  
  fn dosomething() void {
  int age = -1; 
  int name = "Jamal habibi";
    closure greet() string {
      return @combine("Hi I'm ", name, "I am ", age, " YO");
    };
}


// functions are now easier to be used as a type or argument 
  fn with_callback(fn callback(struct options, err_t error) void ){
    callback((struct options){...values}, nil);
  };

// functions will allow default values
  fn optargs(int age, string name="John Doe"){
   // ...do something 
  };
  // will only work when the name or something is empty or not provided, it is static language so it is imposible to know if the value is null but maybe just maybe  add a feature that when the value is nil then it should be the default     


 //  function arguments qualifiers
  type qualifier name;
  generic // generic will result to a struct with types like but only  works for anything 
  restrict // same as C's generic  
  fn something(void* generic value /* like any type */   ){
    if(typeof value != types.struct){
      io.panic("warn: will never happen but it is wrapped under the hood");
    }
    if(typeof generic(value) == types.string){
    };

    // or another way
    if(@generic(value, types.int)){
      // ... do as interger
    }
  }

// types of macros
@create value = value; // creating a value based macro 
@fn value(args, arg1)  // creating the a function type macro 
@block  value(/* variable or any global values */); // this are block macros that will be used like this 

@value(...args[]){
    ...code to be run 
};

 // just like treads macro
@threads(threads){
    const token = "something"
   defer call();
};

// metaprogramming features 
  @meta(){
   d = @createtype(name, struct somethin);
    @on_declare(d, @wrap("something"));
  };

// can create new behaviours new qualifiers
// can change part of the codebase especially some types 
// can create new types based and costom things that can be accessable on comptime and preprocessing and everythin  else 
// based use to create a reserved macros that everything used as that will be wraped, unwrapped refer to something else thus manipuling the data 
// can inject your own dependencies or some internal and global values 
// allow to check states and demand something to the compiler it can slow the compiling of your code    


// abi 
// abi is just a simplified ast, this is used to know when somthing should be freed or something to include een the abi to the any codebase and beable to do refernce counting (comptime) and others so that can develop FFI and others 


// memory management 

let memoid type[] =  @alloc(number); // this should be invoked delte
// delete memoid; // we want to be safe so when the compiler detect unfreed memoid it will throw a warning but can be equite on if on development or prototyping 

// {see tokens.c for more info }
