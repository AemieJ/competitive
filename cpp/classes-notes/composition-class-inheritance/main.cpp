#include <iostream> 
#include "Birthday.h" 
#include "People.h"

using namespace std;

int main() 
{
    Birthday birthdayObject(3 , 5 , 2000);
    People detailofPerson("Aemie" , birthdayObject);
    detailofPerson.printInfo();
    
    return 0;
}