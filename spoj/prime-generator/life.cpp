#include <iostream>

using namespace std;

int main()
{
    int ans=0;
    while(ans != 42)
    {
        cin >> ans;
        if(ans==42)
            break;
        cout << ans << endl;
    }
    return 0;
}