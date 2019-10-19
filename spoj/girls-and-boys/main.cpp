#include <iostream>
#include "math.h"

using namespace std;

int main()
{
    int girls = 0 , boys = 0; 
    
    while(girls != -1 && boys != -1)
    {
        cin >> girls >> boys;
        if(girls == -1 && boys == -1)
            break;
        double maximum = max(girls , boys);
        double minimum = min(girls , boys);
        double ans = (maximum)/(minimum+1);
        cout << ceil(ans) << endl;
    }

    return 0;
}