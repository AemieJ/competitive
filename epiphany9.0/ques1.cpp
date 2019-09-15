#include <iostream> 

using namespace std;

int equalize(long long int a, long long int b)
{
        for(int m=1; m<a; m++)
        {
            if(a%m == b)
                return 1;
        }
        return -1;
}

int main() 
{
    int test , possibility = -1;
    cin >> test;
    long long int a , b;

    for(int _=0 ; _<test ; _++)
    {
        cin >> a >> b;
        possibility = equalize(a,b);
        cout << possibility << endl;

    }
    return 0;
}