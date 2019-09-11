#ifndef PEOPLE_H
#define PEOPLE_H


#include <string>
#include "Birthday.h"

using namespace std;

class People {
    public : 
        People(string name , Birthday bo);
        void printInfo();
    private : 
        string nameOfPerson;
        Birthday birthdayObject;

};

#endif