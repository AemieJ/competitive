#include <iostream>

using namespace std;

int main() 
{

    int test;
    cin >> test;
    long long int number , result;

    for(int _=0; _<test;  _++)
    {
        cin >> number;

        result = 192 + (number-1)*250;
        cout << result << endl;
    }
    return 0;
}