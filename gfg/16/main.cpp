#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int trapWater(int arr[], int n) {
    int total = 0;
    int leftArr[n], rightArr[n];
    leftArr[0] = arr[0];
    rightArr[n-1] = arr[n-1];

    for(int i = 1; i < n-1; ++i) {
        leftArr[i] = max(arr[i], leftArr[i-1]);
        rightArr[n-i-1] = max(arr[n-i-1], rightArr[n-i]);
    }

    for(int i = 1; i < n-1; ++i) {
        int minElm = min(leftArr[i], rightArr[i]);
        if (minElm > arr[i]) {
            total += (minElm - arr[i]);
        }
    }
    return total;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << trapWater(arr, n) << endl;
    }
    return 0;
}