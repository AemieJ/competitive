/*
 i/p : 1 3 4
 o/p : 4 12 
 explanation: { (1, 3), (2, 4), (2, 6), (4, 8), (4, 12)}
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void lastPair(long a, long b, long n, long start);

int main() {
    long t; 
    long a, b, n;
    long start;
    cin >> t; 
    for (int i = 0; i < t; ++i) { 
        cin >> a >> b >> n;
        if (n % 2) {
            start = 3;
        } else {
            start = 2;
        }
        lastPair(a, b, n, start);
    }
    return 0;
}

void lastPair(long a, long b, long n, long start) {
    vector<pair<long, long>> arr;
    arr.push_back(make_pair(a, b));
    arr.push_back(make_pair(b- a, b + a));

    long newA, newB;

    for (int i = start; i <= n; i += 2) {
        newA = arr[start - 2].first * 2;
        newB = arr[start - 2].second * 2;
        arr.at(start-2) = make_pair(newA, newB);
    }

    cout << arr[start - 2].first << " " << arr[start - 2].second << endl;
}