#include <iostream>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
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

int stringToInteger(string input)
{
    int result=0;
    for(int i=0 ;input[i] != '\0';i++)
        result += (result*10) + (input[i]-'0');
    return result;
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

int presenceofZero(string input)
{
    int countOfZero = 0;
    for(int i=0 ; i < input.length() ; i++)
    {
        if(input[i]=='0')
        {
            countOfZero++;
            break;
        }

    }
    return countOfZero;
}

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
        while(count <sizeGreater && number1[count] == '0')
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


int powerCalculation(int base , int exponent)
{
    int result = 1;
    for(int _=0; _< exponent ; _++)
    {
        result *= base;
    }
    return result;
}
int totalHotness(int array1[] , int array2[] , int size)
{
    int sum = 0;
    for(int i=0 ; i < size ; i++)
    {
        sum += (array1[i]*array2[i]);
    }
    return sum;
}

int sumOfArray(int array[] , int size) 
{
    int sum=0;
    for(int i=0 ; i< size ; i++) 
    {
        sum += array[i];
    }
    return sum;
}
int findRequiredMovement(int array[] , int size , int requiredIndex)
{
    int count = 0;
    for(int i=0 ; i<size ; i++)
    {
        array[i] = requiredIndex - array[i];
        if (array[i] >0)
            count += array[i];
    }
    if (sumOfArray(array , size) == 0)
        return count;
    
    return -1;
}

int checkAP(int number1 , int number2 , int number3)
{
    if (number2-number1 == number3-number2)
        return number3+(number2-number1);
    else 
        return 0;
}

int checkGP(float number1 , float number2 , float number3) 
{
    if( number2/number1 == number3/number2) 
        return number3*(number2/number1);
    else 
        return 0;
}

int totalNumberofSquares(int gridSize)
{
    int sum=0;
    while(gridSize > 0)
    {
        sum += (gridSize * gridSize);
        gridSize--;
    }
    return sum;
}

int getNumberfromCoordinate(int xCoordinate , int yCoordinate) 
{   
    
    if (yCoordinate <= xCoordinate && yCoordinate >= xCoordinate-2)
    {
        if (xCoordinate % 2 == 0 && yCoordinate % 2 ==0)
            return (xCoordinate + yCoordinate);

        if (xCoordinate % 2 != 0 && yCoordinate % 2 !=0)
            return (xCoordinate + yCoordinate-1);
        
        else 
            return -1;
    }
    else 
        return -1;
}

int factorialSmall(long int number)
{
    if(number >=1)
        return number*factorialSmall(number-1);
    else
        return 1;   
    
}

int calcTrailingZeros(int number) 
{ 
    int count = 0; 
    for (int i = 5; number / i >= 1; i *= 5) 
        count += number / i; 
    return count; 
} 

int reverse(int number)
{
    int reverseNumber = 0;
    while(number>0)
    {
        int modulus = number%10;
        reverseNumber = (reverseNumber*10) + modulus;

        number /= 10;
    }
    return reverseNumber;
}

bool isPrime(int number)
{
    if(number == 1)
        return 0;
    for (int j = 2; j <= sqrt(number); j++)
        if (number % j == 0)
            return 0;
    return 1;
}

