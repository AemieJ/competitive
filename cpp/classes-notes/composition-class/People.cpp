#include <iostream>
#include <string>
#include "Birthday.h"
#include "People.h"

using namespace std;

People::People(string name , Birthday bo) 
: nameOfPerson(name) , birthdayObject(bo)
{  
}

void People::printInfo()
{
    cout << nameOfPerson << " is born on ";
    birthdayObject.printBirthday();
}