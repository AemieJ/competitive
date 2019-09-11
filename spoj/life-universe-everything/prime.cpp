#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int number)
{
    if(number == 1)
        return 0;
    for (int j = 2; j <= sqrt(number); j++)
        if (number % j == 0)
            return 0;
    return 1;
}

void primeGenerator(int integer1 , int integer2)
{
    for (int i=integer1; i <= integer2 ; i++)
    {
        if(isPrime(i))
            cout << i << endl;
    }
}

int main()
{
    int test , integer1 , integer2;
    cin >> test;

    for(int i=0; i < test ; i++)
    {
        cin >> integer1;
        cin >> integer2;
        primeGenerator(integer1 , integer2);
    }
    return 0;
}