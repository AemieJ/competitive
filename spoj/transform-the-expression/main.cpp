#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string> 

using namespace std;

int priority(char operation)
{
    if(operation == '^')    
        return 3;
    if(operation == '*' || operation == '/')
        return 2;
    if(operation == '+' || operation == '-')
        return 1;
}

vector< char > infixToPostfix(string expression , int size)
{
    vector< char >postfix;
    vector< char >operators;
    for(int i = 0; i<size ; ++i)
    {
        if(isalpha(expression[i]))
            postfix.push_back(expression[i]);
        
        if(expression[i] == '(')
            operators.push_back(expression[i]);
        
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||  expression[i] == '/' || expression[i] == '^')
        {
            while(operators.back() != '(' && (priority(operators.back()) >= priority(expression[i])))
            {
                postfix.push_back(operators.back());
                operators.pop_back();
            }
            operators.push_back(expression[i]);
        }

        if(expression[i] == ')')
        {
            while(operators.back() != '(')
            {
                postfix.push_back(operators.back());
                operators.pop_back();
            }
            operators.pop_back();
        }

    }
    return postfix;
}

int main()
{
    int test;
    cin >> test;
    cin.ignore(256,'\n');
    for(int _=0 ; _<test ; _++)
    {
        string expression;
        getline(cin , expression);
        vector< char >postfix;
        postfix = infixToPostfix(expression , expression.length());
        for(int i = 0 ; i< postfix.size() ; ++i)
            cout << postfix[i];
        cout << endl;
        
    }
    return 0;
}