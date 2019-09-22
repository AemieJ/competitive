#include <iostream>
#include <iomanip>
#define PI 3.14159

int main()
{
    double lengthOfFence = -1;
    while(lengthOfFence != 0)
    {
        std::cin >> lengthOfFence;
        if(lengthOfFence == 0)
            break;
        double maximumArea = (lengthOfFence*lengthOfFence)/(2*PI);
        std::cout << std::fixed << std::setprecision(2) << maximumArea << std::endl;
    }
    return 0;
}