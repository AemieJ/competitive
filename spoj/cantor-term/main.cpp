#include <iostream> 

using namespace std;

int getCantorNumerator(long long int value , long long int term)
{
    long long int index = term - (value*(value+1))/2;
    long long int numerator;
    if((value+1) %2 != 0)
         numerator = (value - index) + 2;
    if((value+1) %2 == 0)
        numerator = index;

    return numerator;
        
}

int getCantorTerm(long long int term)
{
    long long int number = 0;
    while(number >= -1)
    {
        if(term > (number*(number+1))/2 && term <= ((number+1)*(number+2))/2)
            break;
        ++number;
    }
    return number;
}

int main()
{
    int test;
    cin >> test;
    for(int _ = 0 ; _<test ; _++)
    {
        long long int term;
        cin >> term; 
        long long int value = getCantorTerm(term);
        long long int total = value + 2;
        long long int numerator = getCantorNumerator(value , term);

        cout << "TERM " << term << " IS " << numerator << "/" << (total-numerator) << endl;
    }

    return 0;
}