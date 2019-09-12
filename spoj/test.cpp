#include <iostream>
#include "util.h"
#include <string>
#include <sstream>
#include <bits/stdc++.h> 

using namespace std;

/*
    ISSUES WITH THE PROBLEM 
    1.DOESNT SOLVE CORRECTLY IF STARTING DIGIT IS 0 : SOLVED
    2.IN NUMBER LIKE 88888 IT PRINTED 88:88 INSTEAD OF 88988 (ONLY ODD) : SOLVED
    3.NEAREST PALINDROME OF SINGLE DIGIT LOGIC IS WRONG FOR 0-8 THE NEXT PALINDROME IS ITS NEXT NUMBER ITSELF : SOLVED
 */
int main()
{
    for(int _=0 ; _<2 ; _++)
    {
        string digit, nextPalindrome;
        getline(cin, digit);
        digit.erase(0, min(digit.find_first_not_of('0'), digit.size() - 1));
        int size = digit.length();

        if (size == 1 || size == 2)
            nextPalindrome = nextPalindromeBasic(digit, size);

        else if (size % 2 == 0)
            nextPalindrome = nextPalindromeEven(digit, size);

        else if (size % 2 != 0)
            nextPalindrome = nextPalindromeOdd(digit, size);

        cout << nextPalindrome << endl;
    }
    return 0;
}