#include <iostream>

using namespace std;
string calcDivision(string number , int divisor)
{
    string quotient;
    int idx = 0;
    int temp = number[idx]-'0';
    while(temp < divisor)
        temp = temp*10 + (number[++idx]-'0');
    while(number.size() > idx)
    {
        quotient += temp/divisor + '0';
        temp = (temp%divisor)*10 + (number[++idx]-'0');
    }

    return quotient;
}

string calcDifference(string number1 , string number2) 
{
    //string difference = " ";
    int size = number2.length();
    int sizeGreater = number1.length();
    int borrow = 0;
    for(int i=0 ; i < size ; i++)
    {
        number1[i] = (((number1[i]-'0')-borrow)+'0');
        if((number1[i]-'0') >= (number2[i]-'0'))
        {
            number1[i] = ((number1[i]-'0') - (number2[i]-'0')) + '0';
            borrow = 0;
        }

        else if((number1[i]-'0') < (number2[i]-'0'))
        {
            number1[i] = (((number1[i]-'0')+10) - (number2[i]-'0') + '0');
            borrow=1;
        }
    }
    if(number1[size] != '0')
        number1[size] = (((number1[size]-'0')-borrow)+'0');
    else if(number1[size] == '0' && borrow==1)
    {
        int count = size;
        while(count < (sizeGreater-size) && number1[count] == '0')
        {
            number1[count] = (((number1[count]-'0')-borrow)+'0');
            number1[count] = (((number1[count]-'0')+10)+ '0');
            borrow=1;
            count++;
        }
        number1[sizeGreater-1] = (((number1[sizeGreater-1]-'0')-borrow)+'0');
    }
    return number1;

}

string reverseString(string stringName) 
{   
    int size = stringName.length();
    for(int i=0 ; i < size/2; i++)
    {
        swap(stringName[i], stringName[size-i-1]);
    }
    return stringName;
}

int main()
{
    for(int _=0 ; _ < 10 ; _++)
    {
        string noOfApples, difference;
        string actualDifference, actualResult1, actualResult2;

        getline(cin, noOfApples);
        getline(cin, difference);

        noOfApples = reverseString(noOfApples);
        difference = reverseString(difference);

        actualDifference = calcDifference(noOfApples, difference);
        actualDifference = reverseString(actualDifference);
        actualDifference.erase(0, min(actualDifference.find_first_not_of('0'), actualDifference.size() - 1)); //TO REMOVE ALL LEADING ZEROS IN ANY CASE

        actualResult2 = calcDivision(actualDifference, 2);
        //RESULT 1 IS COMING WRONG BUT DIFFERENCE ALGORITHM IS RIGHT BECAUSE RESULT2 COMES CORRECT
        actualResult1 = calcDifference(noOfApples, actualResult2);
        actualResult1 = reverseString(actualResult1);
        actualResult1.erase(0, min(actualResult1.find_first_not_of('0'), actualResult1.size() - 1)); //TO REMOVE ALL LEADING ZEROS IN ANY CASE
        
        cout << actualResult1 << endl;
        cout << actualResult2 << endl;
    }
    return 0;
}