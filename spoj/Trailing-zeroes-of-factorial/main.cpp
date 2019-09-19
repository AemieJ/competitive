#include <iostream>

using namespace std;

int calcTrailingZeros(int number) 
{ 
    int count = 0; 
    for (int i = 5; number / i >= 1; i *= 5) 
        count += number / i; 
    return count; 
}

int main() 
{
    int test , integer;
    cin >> test;
    for(int _=0 ; _<test ; _++)
    {
        cin >> integer;
        cout << calcTrailingZeros(integer) << endl;
    }    
    return 0;
}