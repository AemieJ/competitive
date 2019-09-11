#include <iostream>
#include "Member.h"

using namespace std;


// If an object is of type constant or class , a member function is used in initialization
Member::Member(int reg , int constant) 
:regularVariable(reg) , constantVariable(constant)
{
    cout << "Constructor Invoked." << endl;
}

void Member::printValue()
{
    cout << "Regular Variable " << regularVariable << endl;
    cout << "Constant Variable " << constantVariable << endl;
}