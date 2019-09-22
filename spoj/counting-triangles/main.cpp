#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int _=0 ; _<test ; _++)
    {
        long long number;
        cin >> number;
        cout << ((number*(number+2)*(2*number+1))/8) << endl;
    }
    return 0;
}