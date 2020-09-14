#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int i = 0, arr[10];
        while (n > 0) {
            arr[i++] = n%2;
            n /= 2;
        }
        
        arr[i] = 0;
        int sum = 0;
        for(int j = 0; j < i; j += 2) {
            int x = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = x;
            sum += arr[j]*pow(2, j);
            sum += arr[j+1]*pow(2, j+1);
        }
        cout << sum << endl;
    }
    return 0;
}