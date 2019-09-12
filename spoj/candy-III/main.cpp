#include <iostream>

using namespace std;
/* 
    MODULAR ADDITION FOR EVERY ITERATOR IS MUCH EFFICIENT THAN SUMMING THE TERMS.
*/
int main()
{
    long long int test;
    cin >> test;
    cout << endl;

    for(int _=0;_<test;_++)
    {
        long long int totalNumber, candy;
        long long int sum = 0;
        cin >> totalNumber;

        for (long long int _ = 0; _ < totalNumber; _++)
        {
            cin >> candy;
            sum += (candy%totalNumber);
        }

        if (sum % totalNumber == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        cout << endl;
    }
    return 0;
}