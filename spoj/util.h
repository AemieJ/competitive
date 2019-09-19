#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long getBFSMaxIndex(vector< long long>graph[] , int start , long long int vertices , long long int &index)
{
    queue<long long>bfs_queue;
    int counter[vertices+1];
    memset(counter , -1 , sizeof(counter));

    bfs_queue.push(start);
    counter[start] = 0;
    while(!bfs_queue.empty())
    {
        long long int temp = bfs_queue.front();
        bfs_queue.pop();
        for(int i=0 ; i < graph[temp].size() ; ++i)
        {
            long long int adjacent = graph[temp][i];
            if(counter[adjacent] == -1)
            {
                bfs_queue.push(adjacent);
                counter[adjacent] = counter[temp] + 1;
            }
        }
    }

    long long int maxDistance = 0;
    for(int i=1 ; i <= vertices ; ++i)
    {
        if(counter[i] > maxDistance)
        {
             maxDistance = counter[i];
             index = i;
        }
    }
    return maxDistance;

}

int getLongestPath(vector<long long>graph[] , int start , long long int vertices)
{

    long long int index=-1 , maxValue;
    maxValue = getBFSMaxIndex(graph , start , vertices , index); 
    start = index;   index = -1;
    maxValue = getBFSMaxIndex(graph , start  , vertices , index);

    return maxValue;
}


bool breathFirstSearch(vector< int >graph[] , long long int start , long long int vertices)
{
    bool visited[vertices+1] = {0};
    queue< int >listOfVertices;
    int counter = 0;
    listOfVertices.push(start);
    memset(visited,0,sizeof(visited));

    while(!listOfVertices.empty())
    {
        long long int element = listOfVertices.front();
        listOfVertices.pop();
        visited[element] = 1;
        
        for(int i= 0 ; i < graph[element].size() ; ++i)
        {
            int adjacent = graph[element][i];
            if(visited[adjacent])    
                return 0;
            else
                listOfVertices.push(adjacent);
            
        }
        ++counter;
    }
    if(counter != vertices)
        return 0;
    else 
        return 1;
}

long getMaximumSet(long long int number)
{
    if(number < 12)
        return number;
    else 
    {
        if((number/2 + number/3 + number/4) > number)
            return getMaximumSet(number/2) +getMaximumSet(number/3)+getMaximumSet(number/4);
    }
    return number;
}

int getCantorNumerator(long long int value , long long int term)
{
    long long int index = term - (value*(value+1))/2;
    long long int numerator;
    if((value+1) %2 != 0)
         numerator = (value - index) + 2;
    if((value+1) %2 == 0)
        numerator = index;

    return numerator;
        
}

int getCantorTerm(long long int term)
{
    long long int number = 0;
    while(number >= -1)
    {
        if(term > (number*(number+1))/2 && term <= ((number+1)*(number+2))/2)
            break;
        ++number;
    }
    return number;
}

void updateBIT(int BIT[] , long long int index , long long int size)
{
        while(index <= size)
        {
            BIT[index] += 1;
            index += (index) & (-index);
        }
}

int totalSum(int BIT[] ,  long long int index)
{
    int sum = 0;
    while(index > 0)
    {
        sum += BIT[index];
        index -= (index) & (-index);
    }   
    return sum;
}

vector< int > convert(vector< int>array , long long int size)
{
    vector< int >copy = array;
    sort(copy.begin() , copy.end());
    for(int i=0 ; i< size ; i++)
        array[i] = lower_bound(copy.begin() , copy.end() , array[i]) - copy.begin() + 1;
    
    return array;
}

int totalInversions(vector< int >array , long long int size)
{
    array = convert(array , size);
    int BIT[size+1];
    for(int i = 1;i < size ; ++i)
        BIT[i] = 0;
    int inverseCount = 0;
    for(int i=size-1 ; i>=0 ; --i)
    {
        inverseCount += totalSum(BIT , array[i]-1);
        updateBIT(BIT , array[i] , size);
    }
    return inverseCount;
}

int findWinner(vector< int>team1 , vector< int >team2)
{
    while (!team1.empty() && !team2.empty())
    {
        if(team1.back() < team2.back())
            team1.pop_back();
        if(team1.back() >= team2.back())
            team2.pop_back();
    }

    if(team1.empty())
        return 0;
    return 1;
}
int checkOrderPossible(vector< int >input , int size)
{
        vector< int >stack;
        int requiredValue = 1 , answer = 1;
        for(int i=0 ; i< input.size() ; i++)
        {
            while(!stack.empty() && stack.back() == requiredValue)
            {
                requiredValue++;
                stack.pop_back();
            }

            if (input[i] == requiredValue)
                requiredValue++;
            else if(!stack.empty() && stack.back() < input[i])
            {
                answer = 0;
                break;
            }
            else 
                stack.push_back(input[i]);
        }

        return answer;
        
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
int compare(string input1 , string input2) 
{
    if (input1 == input2) 
            return 0;
    if (input1 > input2) 
            return 1;
    return -1;
}

int isFeasible(long long int  array[] , long long int mid , long long int total , long long int expected)
{
    int taken=1;
    long long int  last = array[0] , difference;
    for(int i=1 ; i<total;i++)
    {
        if(array[i]-last >= mid)
        {
            taken++;
            last = array[i];
            if(taken==expected) 
                return 1;
        }
    }
    return 0;
}

long long int minDistance(long long int array[] , long long int total , long long int expected)
{
    long long int  low = array[0] , high = array[total-1];
    long long int  mid , res = -1;
    while(low < high)
    {
        mid = (low+high)/2;
        if (isFeasible(array , mid , total , expected))
        {
            res = max(res,mid);
            low = mid+1;
        }

        else   
            high = mid;
    }
    return res;

}

bool compareNumbers(string str1, string str2) 
{  
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
       return true; 
    if (n2 < n1) 
       return false; 
  
    for (int i=0; i<n1; i++) 
    { 
       if (str1[i] < str2[i]) 
          return true; 
       if (str1[i] > str2[i]) 
          return false; 
    } 
  
    return false; 
} 
   
void sortNumberStrings(string arr[], int n) 
{ 
   sort(arr, arr+n, compareNumbers); 
} 

int allElementsNine(string input , int size)
{
    for(int i=0 ; i<size ; i++)
    {
        if (input[i]!='9')
            return 0;
    }
    return 1;
}

string nextPalindromeOdd(string input , int size)
{
    string copy = input , duplicate;
    duplicate = reverseString(input);
    int center = size/2;
    for(int i=center+1 ; i < size ; i++)
        copy[i] = duplicate[i];
    if(copy <= input && allElementsNine(copy , size) == 0)
    {
        int count=0;
        while(copy[center-count] == '9' && (size/2-count) > 0) 
        {
            copy[center-count] = '0';
            if(count != 0)
                copy[center+count] = '0';
            count++;
        }
        if(copy[center-count] < '9')
        {
            copy[center-count] = (copy[center-count]-'0') + 1 + '0'; 
            if(count != 0)
                copy[center+count] = (copy[center+count]-'0') + 1 + '0';
        }
    }
    if (copy <= input && allElementsNine(copy, size) == 1)
    {
        for (int i = 1; i < size; i++)
            copy[i] = '0';
        copy[0] = '1';
        copy += "1";
    }
    return copy;
}

string nextPalindromeEven(string input , int size)
{

    string copy = input , duplicate;
    duplicate = reverseString(input);
    for(int i= size/2 ; i < size ; i++)
        copy[i] = duplicate[i];
    if(copy <= input && allElementsNine(copy , size)==0)
    {
        int count=1;
        while(copy[size/2-count] == '9' && (size/2-count) > 0) 
        {
            copy[size/2-count] = '0';
            copy[size/2+count-1] = '0';
            count++;
        }
        if(copy[size/2-count] < '9')
        {
            copy[size/2-count] = (copy[size/2-count]-'0') + 1 + '0'; 
            copy[size/2+count-1] = (copy[size/2+count-1]-'0') + 1 + '0';
        }
    } 

    if(copy <= input && allElementsNine(copy , size)==1)
    {
        for(int i=1 ; i < size ; i++)
            copy[i] = '0';
        copy[0] = '1';
        copy += "1";        
    }
    return copy;
}

string nextPalindromeBasic(string input , int size)
{
    string copy = input;
    if(size==1)
        if(copy=="9")
            copy="11";
        else
            copy[0] = (input[0]-'0') + 1 + '0';
    else
    {
        copy[1] = copy[0];
        if(copy <= input)
        {
            copy[1] = (copy[1]-'0') +1 + '0';
            copy[0] = (copy[0]-'0') +1 + '0';
        }
    }
    if(input == "99")
        copy = "101";
    return copy;
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

string calcAddition(string number1 , string number2)
{
    int size = number2.length();
    int sizeGreater = number1.length();
    int carry = 0;
    string result;
    for(int i=0 ; i<size ; i++)
    {
        result += (((number1[i]-'0')+(number2[i]-'0') + carry)%10) + '0';
        carry = (((number1[i]-'0')+(number2[i]-'0') + carry)/10);
    }

    for(int j=size ; j<sizeGreater ; j++)
    {
        result += (number1[j]-'0' + carry)%10 + '0';
        carry = (number1[j]-'0' + carry)/10;
    }

    result = reverseString(result);
    result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
    return result;
}

string calcDifference(string number1 , string number2) 
{
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
    string result = reverseString(number1);
    result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
    return result;

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

