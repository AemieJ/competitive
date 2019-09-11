#include <iostream>

using namespace std;

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

int main() 
{
    int requiredMovement , numberOfPackets = 0 ;
    while(numberOfPackets != -1)
    {
        cin >> numberOfPackets;
        if (numberOfPackets == -1)
            break;
            
        int arrayOfCandies[numberOfPackets];
        for (int i = 0; i < numberOfPackets; i++){ cin >> arrayOfCandies[i]; }

        int sum = sumOfArray(arrayOfCandies, numberOfPackets);
        if (sum % numberOfPackets == 0)
        {
            int requiredNoOfCandies = sum / numberOfPackets;
            requiredMovement = findRequiredMovement(arrayOfCandies, numberOfPackets, requiredNoOfCandies);
            cout << requiredMovement << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}