/*
Convert Integer to the Sum of Two No-Zero Integers (Easy)

Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.

Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
Example 2:

Input: n = 11
Output: [2,9]
Example 3:

Input: n = 10000
Output: [1,9999]
Example 4:

Input: n = 69
Output: [1,68]
Example 5:

Input: n = 1010
Output: [11,999]
 

Constraints:

2 <= n <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>result;
        int initial = 1;
        int finalVal = n-1;
        
        while(initial <= finalVal) {
            if (check(initial) && check(finalVal)) {
                result.push_back(initial);
                result.push_back(finalVal);
                return result;
            } else {
                ++initial;
                --finalVal;
            }
        }
        return {};
        
    }
private:
    int check(int num) {
        while (num > 0) {
            if (num % 10 == 0) 
                return 0;
            num = num/10;
        }
        return 1;
    }
    
};