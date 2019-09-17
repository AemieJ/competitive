#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


int findWinner(vector< int>team1 , vector< int >team2)
{
    while (!team1.empty() && !team2.empty())
    {
        if(team1.back() < team2.back())
            team1.pop_back();
        if(team1.back() >= team2.back())
            team2.pop_back();
    }

    if(team1.empty())
        return 0;
    return 1;
}

int main()
{
    int test;
    cin >> test;
    
    for(int _=0 ; _<test ; _++)
    {
        cout << endl;
        int teamNum1, teamNum2;
        cin >> teamNum1 >> teamNum2;
        vector<int> Godzilla;
        vector<int> MechaGodzilla;
        cin.ignore(256, '\n');

        string strength1, strength2;
        int strengthG, strengthM;

        getline(cin, strength1);
        istringstream iss(strength1);
        for (string strength1; iss >> strength1;)
        {
            istringstream ss(strength1);
            ss >> strengthG;
            Godzilla.push_back(strengthG);
        }

        getline(cin, strength2);
        istringstream iss1(strength2);
        for (string strength2; iss1 >> strength2;)
        {
            istringstream ss1(strength2);
            ss1 >> strengthM;
            MechaGodzilla.push_back(strengthM);
        }

        sort(Godzilla.begin(), Godzilla.end(), greater<int>());
        sort(MechaGodzilla.begin(), MechaGodzilla.end(), greater<int>());

        int output = findWinner(Godzilla, MechaGodzilla);
        if (output == 1)
            cout << "Godzilla" << endl;
        if (output == 0)
            cout << "MechaGodzilla" << endl;
        if (output != 1 && output != 0)
            cout << "uncertain" << endl;
    }

    return 0;
}