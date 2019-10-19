#include <iostream>

using namespace std;

long long countTotalCards(long long int card)
{
    long long int count = 0;
    for(long long int i = 1 ; i <= card ; ++i)
        count += (i-1) + (2*i);
    
    return count%1000007;
}

int main()
{
    int test;
    long long int cards , totalCards;
    cin >> test;
    for(int _=0 ; _<test ; _++)
    {
        cin >> cards;
        totalCards = countTotalCards(cards);
        cout << totalCards << endl;
    }
    return 0;
}