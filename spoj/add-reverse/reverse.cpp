#include <iostream>

using namespace std;


int reverse(int number)
{
    int reverseNumber = 0;
    while(number>0)
    {
        int modulus = number%10;
        reverseNumber = (reverseNumber*10) + modulus;

        number /= 10;
    }
    return reverseNumber;
}

int main()
{
    int test , integer1 , integer2;

    cin >> test;
    for(int _= 0 ; _<test ; _++)
    {
        cin >> integer1; 
        cin >> integer2;
        integer1 = reverse(integer1);
        integer2 = reverse(integer2);
        cout << reverse(integer1 + integer2) << endl;
    }
}