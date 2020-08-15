/*
Mathematical formula derivation: 
1( all a) 
n( 1b rest a)
n( 1c rest a)
n*(n-1) / 2 (2c rest a)
n*(n-1) (1b 1c rest a)
n*(n-1)*(n-2) / 2 (1b 2c rest a) 
total : (n*n*n + 3*n + 2) / 2
*/

#include<iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n; 
        int res = (n*n*n + 3*n + 2)/2;
        cout << res << endl;
    }
}