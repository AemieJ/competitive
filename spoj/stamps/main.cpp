#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    int scenario;
    cin >> scenario;
    cin.ignore(256,'\n');

    for(int _=0 ; _<scenario ; _++)
    {
        int threshold, noOfFriends, stamp;
        cin >> threshold >> noOfFriends;
        vector<int> stamps;

        string s;
        cin.ignore(256, '\n');
        getline(cin, s);
        istringstream iss(s);
        for (std::string s; iss >> s;)
        {
            istringstream ss(s);
            ss >> stamp;
            stamps.push_back(stamp);
        }
        int totalStamps = 0, count = 0;
        sort(stamps.begin(), stamps.end(), greater<int>());
        for (int i = 0; i < noOfFriends; ++i)
        {
            totalStamps += stamps[i];
            ++count;
            if (totalStamps >= threshold)
                break;
        }

        cout << "Scenario #" << _+1 << ":" << endl;
        if (totalStamps >= threshold)
            cout << count << endl << endl;
        if (totalStamps < threshold)
            cout << "impossible" << endl << endl;
    }
    return 0;
}