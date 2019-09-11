#include <iostream> 
#include <bits/stdc++.h> 

using namespace std;

int totalHotness(int array1[] , int array2[] , int size)
{
    int sum = 0;
    for(int i=0 ; i < size ; i++)
    {
        sum += (array1[i]*array2[i]);
    }
    return sum;
}

int main() 
{
    int test;
    cin >> test;

    for(int _=0 ; _<test ; _++)
    {
        int numberOfParticipants, sum;
        cin >> numberOfParticipants;

        int maleParticipants[numberOfParticipants];
        int femaleParticipants[numberOfParticipants];

        for (int i = 0; i < numberOfParticipants; i++){ cin >> maleParticipants[i]; }
        for (int j = 0; j < numberOfParticipants; j++){ cin >> femaleParticipants[j]; }

        sort(maleParticipants , maleParticipants + numberOfParticipants);
        sort(femaleParticipants , femaleParticipants + numberOfParticipants);

        sum = totalHotness(maleParticipants, femaleParticipants, numberOfParticipants);
        cout << sum << endl;
    }

    return 0;
}