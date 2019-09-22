#include <iostream> 

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int _=0 ; _<test ; _++)
    {
        long long int thirdTerm, thirdLastTerm, sum , commonDifference;
        cin >> thirdTerm >> thirdLastTerm >> sum;

        long long int numberOfTerms = (2 * sum) / (thirdTerm + thirdLastTerm);
        if(numberOfTerms != 5)
            commonDifference = (thirdLastTerm - thirdTerm) / (numberOfTerms - 5);
        if(numberOfTerms == 5)
            commonDifference = 1;
        long long int firstTerm = thirdTerm - (2 * commonDifference);

        cout << numberOfTerms << endl;
        for (int i = 1; i <= numberOfTerms; ++i)
            cout << firstTerm + ((i - 1) * commonDifference) << " ";
        cout << endl;
    }
}