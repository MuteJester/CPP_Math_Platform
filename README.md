# Algebric Support Platform For CPP

A small library which allows the developer to work with algebric expression as variabels for easier and faster programing when the usage of math is needed

## Getting Started

Inorder to start working with the library simply download CPP_MP.h from the reposetoriy , include it in your project and you are ready to code! 



### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

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
creation of a function variable is done by declaering a new __Function__ object
the constractor of the function object recivces a string which reprisents the algebric
expression
__NOTE: the library is still under development ,there may be some expression that yet to be supported__

**Example : Function f1("5*x^2 + cos(2*x));

After the creation of the variable it may be used as pleased , at any time each __Function__ variable
contains the string formation of the algebric expression meaning it can be prented at any step
for example , calling on the class methood called 'Derive' will update the function variable to its
coressponding derivative 

Indeep instruction will be placed in the wiki tab of this reposetoriy 




## Authors

* **Thomas Konstantin** - (https://github.com/MuteJester)


