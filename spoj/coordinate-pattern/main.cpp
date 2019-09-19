#include <iostream> 

using namespace std;
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

int main() 
{
    int test , xCoordinate , yCoordinate;
    cin >> test;

    for(int _=0 ; _<test ; _++)
    {
        cin >> xCoordinate >> yCoordinate;
        if(getNumberfromCoordinate(xCoordinate , yCoordinate) == -1)
            cout << "No Number" << endl;
        else 
           cout << getNumberfromCoordinate(xCoordinate , yCoordinate) << endl; 
    }
}