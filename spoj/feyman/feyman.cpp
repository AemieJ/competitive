#include <iostream>

using namespace std;

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

int main()
{
    int gridSize = -1; 

    while(gridSize != 0)
    {
        cin >> gridSize;
        if(gridSize ==0)
            break;
            
        cout << totalNumberofSquares(gridSize) << endl;
        
    }
    return 0;
}