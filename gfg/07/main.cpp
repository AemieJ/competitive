/*
Basic DP Problem. Find Subarray with maximum sum
i/p = [1, 2, 3, -2, 5]
o/p = 9  
*/


#include<algorithm>
#include<stdio.h>
#include<bits/stdc++.h>
#include<vector> 

using namespace std; 

int kanadeAlgo(vector<int> arr);

int main() {
    int testCases; 
    cin >> testCases; 
    for (int i = 0; i < testCases; ++i) {
        int size; 
        vector<int> arr;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            int elm;
            cin >> elm;
            arr.push_back(elm);            
        }
        cout << kanadeAlgo(arr) << endl;
    }
    return 0;
}

int kanadeAlgo(vector<int> arr) {
    int n = arr.size();
    int dp[n];
    dp[0] = arr.at(0);

    for (int i  = 0; i < n; ++i) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);    
    }

    return *max_element(dp, dp + n);
}