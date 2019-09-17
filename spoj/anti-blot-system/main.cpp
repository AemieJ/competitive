#include <iostream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

int main() 
{
    int test;
    cin >> test;
    cin.ignore(256, '\n');
    string blank;
    for(int _= 0 ; _<test ; _++)
    {
        cout << endl;
        vector<string> result;
        string s;
        getline(cin , blank);
        getline(cin, s);
        istringstream iss(s);
        for (std::string s; iss >> s;)
            result.push_back(s);

        string number1 = result[0];
        string number2 = result[2];
        string answer = result[4];

        size_t found1 = number1.find("machula");
        size_t found2 = number2.find("machula");
        size_t found3 = answer.find("machula");

        int num1 , num2 , ans;
        istringstream s1(number1);
        s1 >> num1;
        istringstream s2(number2);
        s2 >> num2;
        istringstream s3(answer);
        s3 >> ans;

        if(found1 != string::npos)
            cout << ans-num2 << " + " << num2 << " = " << ans;
        if(found2 != string::npos)
            cout << num1 << " + " << ans-num1 << " = " << ans;
        if(found3 != string::npos)
            cout << num1 << " + " << num2 << " = " << num1+num2;


    }
    return 0;
}