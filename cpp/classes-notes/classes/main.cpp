#include <iostream>
#include "Practice.h"

using namespace std;

int main() 
{
    Practice practiceObject;
    const Practice *practicePointer = &practiceObject;

    practiceObject.printExpression();

    practicePointer->printConstantExpression();
}