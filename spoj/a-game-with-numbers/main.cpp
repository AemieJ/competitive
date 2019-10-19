#include <iostream>
#include <string>

using namespace std;

int main()
{
    string integer;
    getline(cin , integer);
    long long int length = integer.length();
    char character = integer[length-1];
    if (character == '0')   
        cout << 2 << endl;
    else 
    {
        cout << 1 << endl << character << endl;
    }

    return 0;
}