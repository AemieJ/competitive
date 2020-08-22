#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n, k;
    scanf("%d\n", &t);
    while(t--) { 
        scanf("%d\n", &n);
        int arr[n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &k);
        sort(arr, arr+n);
        printf("%d", arr[k-1]);
        printf("\n");
    }
    return 0;
}