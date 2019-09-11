#include <iostream>
#include <math.h>

using namespace std;
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

