#include<bits/stdc++.h>

using namespace std;

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

struct val{
	int first;
	int second;
};

bool customSort (val a, val b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n) {
    sort(p, p + n, customSort);
    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if (p[i].first > p[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    return 0;
}