#include <iostream>
#include "Operator.h"

int main()
{
    Operator object1(23);
    Operator object2(32);
    Operator result;

    result = object1 + object2; //At this point , it calls the operator+ method which adds the number of the 
                                //two objects 
    
    std::cout << result.number << std::endl;
}