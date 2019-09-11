#include <iostream>
#include "This.h"

using namespace std;

This::This(int num)
:randVar(num)
{
}

void This::displayVar()
{
    /*
        Both syntax explicity calls the object this to point to the argument randVar and display its content . 
        In this case they display the same context itself.
    */
    cout << this->randVar << endl;
    cout << (*this).randVar << endl;
}