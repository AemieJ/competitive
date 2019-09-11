#include <iostream>
#include <string>
using namespace std;

int main()
{
    int columnSize = -1 , rowSize;
    string sentence;

    while(columnSize != 0)
    {
        cin >> columnSize;
        if(columnSize ==0)
            break;

        char subString[columnSize];

        cin.ignore(256, '\n');
        getline(cin, sentence);
        rowSize = sentence.length() / columnSize;

        for (int i = columnSize; i < sentence.length(); i += (columnSize * 2))
        {
            sentence.copy(subString, columnSize, i);
            for (int j = 0; j < columnSize; j++)
            {
                sentence[j + i] = subString[(columnSize - j) - 1];
            }
        }

        for (int a = 0; a < columnSize; a++)
        {
            for (int b = a; b < sentence.length(); b += columnSize)
            {
                cout << sentence[b];
            }
        }
        cout << endl;
    }
    return 0;
}