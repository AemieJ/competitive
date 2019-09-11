#include <iostream> 

using namespace std;

/*
    Friend keyword allows the access of private variable in functions that are not part of the class as well.
*/

class Friend { 
    public: 
        Friend() { variableSet = 0;}
    private:
        int variableSet;
    friend void accessClassinFunction(Friend& friendObject);
};

void accessClassinFunction(Friend& friendObject) 
{
    friendObject.variableSet = 23;
    cout << "Value access from random function " << friendObject.variableSet << endl;
}

int main()
{
    Friend object;
    accessClassinFunction(object);
    return 0;
}