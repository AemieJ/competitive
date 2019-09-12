#include <iostream> 
#include "Operator.h"

using namespace std;

Operator::Operator()
{}

Operator::Operator(int digit)
{
    number = digit;
}

Operator Operator::operator+(Operator object) 
{
    Operator newObject;
    newObject.number = number + object.number;
    return newObject.number;
}