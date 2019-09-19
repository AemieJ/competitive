#include <iostream>

using namespace std;

long getMaximumSet(long long int number)
{
    if(number < 12)
        return number;
    else 
    {
        if((number/2 + number/3 + number/4) > number)
            return getMaximumSet(number/2) +getMaximumSet(number/3)+getMaximumSet(number/4);
    }
    return number;
}

int main()
{
    //TO BE DONE LATER USING RECURSION 
    long long int number;
    while(cin >> number)
    {
        cout << getMaximumSet(number) << endl;
    }

    return 0;
}