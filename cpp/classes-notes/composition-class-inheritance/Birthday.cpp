#include <iostream> 
#include "Birthday.h" 

using namespace std;

Birthday::Birthday(int day , int month , int year) 
{
    dayOfBirth = day;
    monthOfBirth = month;
    yearOfBirth = year;
}

void Birthday::printBirthday() 
{
    cout <<  dayOfBirth << "/" << monthOfBirth << "/" << yearOfBirth << endl;
}