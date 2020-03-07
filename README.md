# Algebraic Support Platform For CPP

A small library which allows the developer to work with an algebraic expression as variables, as well as Matrixes ,Macros,geometry,statistics and probability  for easier and faster programming when the usage of math is needed 

## Getting Started

To start working with the library simply download CPP_MP.h from the reposetoriy, include it in your project and you are ready to code! 


## Running the tests

To make sure the header works properly you can copy the following main and try to run it:

`#include "CPP_MP.h"`
`using namespace std;`


    int main() {
   
    Function x("cos(1*x) + 2*x"),y;
  
    x.Derive();
  
    cout << x;

    cout << endl << endl;
    system("pause");
    return 0;
    }


The program should print : -1*sin(X) + 2


### Usages/Instructions

The core of the library runs around a class called __Function__ ,
creation of a function variable is done by declaring a new __Function__ object
the constructor of the function object receives a string which represents the algebraic
expression
__NOTE: the library is still under development, there may be some expression that yet to be supported__

**Example : Function f1("5*x^2 + cos(2*x));

After the creation of the variable, it may be used as pleased, at any time each __Function__ variable
contains the string formation of the algebraic expression meaning it can be printed at any step, for example, calling on the class method called 'Derive' will update the function variable to its
corresponding derivative 

Indeep instruction will be placed in the wiki tab of this repository 




## Authors

* **Thomas Konstantin** - (https://github.com/MuteJester)


