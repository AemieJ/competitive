#include <iostream>

using namespace std;

string reverseString(string stringName) 
{   
    int size = stringName.length();
    for(int i=0 ; i < size/2; i++)
    {
        swap(stringName[i], stringName[size-i-1]);
    }
    return stringName;
}

string convertInttoString(int num)
{
    string remainder;
    while(num>0)
    {
        remainder += (num%10 + '0');
        num /= 10;
    }
    return reverseString(remainder);
}
int inRangeofAlpha(string input)
{
        for(int i=1 ; i<=26 ; i++)
        {
            if (input == convertInttoString(i))
                return 1;
        }
        return 0;
}

int countDecodings(string input , int size)
{
    int count[size+1];
    count[0] = 1;
    count[1] = 1;

    for(int i=2 ; i<=size ; i++)
    {
        count[i] = 0;
        if(input[i-1] > '0')
            count[i] = count[i-1];

        if(input[i-2]=='1' || input[i-2]=='2' && input[i-1] < '7')
            count[i] += count[i-2];

        if(input[i-1]=='0' && input[i-2]>'0')
        {
            string temp;
            temp = ((input[i-2]-'0')*10 + 0) + '0';
            if(inRangeofAlpha(temp))
                count[i] = count[i-1];
        }
    }
    return count[size];
    
}

int stringToInteger(string input)
{
    int size = input.length();
    int result=0;
    for(int i=0 ; i<size;i++)
        result += (result*10) + (input[i]-'0');
    return result;
}

int main()
{
    string input="-1";
    while(stringToInteger(input) != 0) 
    {
        getline(cin , input);
        if(stringToInteger(input) == 0)
            break;
        int size = input.length();
        int count = countDecodings(input , size);
        cout << count << endl;
    }
    return 0;
}