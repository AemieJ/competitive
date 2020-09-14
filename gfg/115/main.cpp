#include<bits/stdc++.h>

using namespace std;

int dp[105][105] = {};

int xorr(int arr[], int a, int n, int i){
    if(i == n) return a;
    
    // choose and not choose number
    if(dp[a][i] != -1) return dp[a][i];
    return dp[a][i] = max( xorr(arr, a^arr[i], n, i+1), xorr(arr, a, n, i+1) );
}

// Function to return maximum XOR subset in set[]
int maxSubarrayXOR(int A[], int n) {
    memset(dp, -1, sizeof(dp));
    return xorr(A, 0, n, 0);
}



int main() {
    return 0;
}