#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std; 

int fibonnaciNaive(int num);
int fibonnaciMemoization(int num, vector<int> temp);
int fibonnaciBottomUp(int num);


int main() {
    int num = 30;
    vector<int> temp(num + 1, 0);
    cout << fibonnaciNaive(num) << endl;
    cout << fibonnaciMemoization(num, temp) << endl;
    cout << fibonnaciBottomUp(num) << endl;
    return 0;
}

// Rescursion Method ( least time efficient )
int fibonnaciNaive(int num) {
    int res;
    if (num == 1 or num == 2) res = 1;
    else {
        res = fibonnaciNaive(num - 1) + fibonnaciNaive(num - 2);
    }
    return res;
}

// Memoization Method
int fibonnaciMemoization(int num, vector<int> temp) {
    int res;
    if (temp[num] != 0) {
        return temp[num];
    } 
    if (num == 1 or num == 2) res = 1;
    else {
        res = fibonnaciMemoization(num - 1, temp) + fibonnaciMemoization(num - 2, temp);
        temp[num] = res;
    }
    return res;
}

// Bottom Up DP ( most time efficient )
int fibonnaciBottomUp(int num) {
    vector<int> temp(num + 1, 0); 
    temp[1] = 1;
    temp[2] = 1;
    for (int i = 3; i <= num; ++i) {
        temp[i] = temp[i-1] + temp[i-2];
    }
    return temp[num];
}