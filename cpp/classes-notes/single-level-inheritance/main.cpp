#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

/*
    ONLY PUBLIC AND PROTECTED VARIABLES OF THE BASE CLASS CAN BE INHERITED IN THE DERIVED CLASS AND NOT THE PRIVATE 
    VARIABLES.

    ALSO THE DERIVED CLASS CAN'T INHERIT THE  CONSTRUCTOR AND DECONSTRUCTOR OF THE PARENT OR THE BASE CLASS.
*/
int main() 
{
    Derived derivedObject;
    derivedObject.displayName();
    return 0;
}