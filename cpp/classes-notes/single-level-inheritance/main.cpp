#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main() 
{
    Derived derivedObject;
    derivedObject.displayName();
    return 0;
}