#include <iostream>
#include "Practice.h"

using namespace std;

Practice::Practice() {
    cout << "CONSTRUCTOR INVOKED" << endl;
}

void Practice::printExpression() {
    cout << "This is a regular expression" << endl;
}

void Practice::printConstantExpression() const {
    cout << "This is a constant expression" << endl;
}
Practice::~Practice() {
    cout << "DECONSTRUCTOR INVOKED" << endl;
}