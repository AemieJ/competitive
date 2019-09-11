#include <iostream> 
#include <math.h>

using namespace std;

int main()
{
    int gridNumber , count =0;
    cin >> gridNumber; 

    for(int length=1 ; length <= sqrt(gridNumber) ; length++)
    {
        for(int height=length; height*length <= gridNumber ; height++)
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}