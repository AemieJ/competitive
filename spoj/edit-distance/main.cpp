#include <iostream>
#include <string>

using namespace std;

int editDistance(string string1 , string string2 , int length1 , int length2)
{
    int dpMatrix[length1+1][length2+1];

    for(int i = 0; i <= length1 ; ++i)
    {
        for(int j = 0; j <= length2 ; ++j)
        {
            if (i == 0)
                dpMatrix[0][j] = j;
            else if (j == 0)
                dpMatrix[i][0] = i;
            
            else if(string1[i-1] == string2[j-1])
                dpMatrix[i][j] = dpMatrix[i-1][j-1];
            
            else 
                dpMatrix[i][j] = 1 + min(dpMatrix[i-1][j-1] ,min(dpMatrix[i-1][j] , dpMatrix[i][j-1]));
        }
    }
    return dpMatrix[length1][length2];
    
}

int main()
{
    int test , countMinimumOperations;
    string string1 , string2;
    cin >> test;
    cin.ignore(256,'\n');
    for(int _=0 ; _<test ; _++)
    {
        getline(cin , string1);
        getline(cin , string2);
        countMinimumOperations = editDistance(string1 , string2 , string1.length() , string2.length());
        cout << countMinimumOperations << endl;

    }
    return 0;
}