#include <iostream>

using namespace std;


int main() 
{
    float value = 1.00f;
    while(value != 0.00)
    {
        cin >> value;
        float start = 2.00f;
        float result = 0.00;
        if(value == 0.00)
            break;

        while(result < value)
        {
            result += (1/start);
            start++;
        }

        cout << start-2 << " card(s)" << endl;        
    }
    return 0;
}