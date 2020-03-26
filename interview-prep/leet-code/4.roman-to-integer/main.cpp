/* ROMAN TO INTEGER 
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int>romans;
        romans['I']= 1;
        romans['V']= 5;
        romans['X']= 10;
        romans['L']= 50;
        romans['C']= 100;
        romans['D']= 500;
        romans['M']= 1000;
        
        map<string, int>exceptions;
        exceptions["IV"] = 4;
        exceptions["IX"] = 9;
        exceptions["XL"] = 40;
        exceptions["XC"] = 90;
        exceptions["CD"] = 400;
        exceptions["CM"] = 900;
        
        int sum = 0;
        string newString;
        for (int i = 0; i < s.length(); ++i) {
            auto it = romans.find(s[i+1]);
            if (s[i+1] != '\0') {
                newString = string(1, s[i]) + s[i+1];
            }
            auto itr = romans.find(s[i]);
            auto itr2 = exceptions.find(newString);
            if (itr2 != exceptions.end() && it != romans.end() && itr != romans.end()) {
                sum += (itr2->second);
                sum -= (it->second);
            } else {
                sum += (itr->second);
            }
        }
        return sum;      
    }
};