/* WRONG ANS */
#include<bits/stdc++.h>

using namespace std;

void pageFaults(vector<int>& arr, int n, int mem) {
    
    int currMem = 0; 
    int pageFault = 0; 
    for(int i = 0; i < n; ++i) {
        if (i == mem-1) 
            pageFault = mem;
            
        if (i >= mem && find(arr.begin(), arr.begin() + mem, arr[i]) == (arr.begin() + mem) && currMem < mem) {
            ++currMem;
            int idx = currMem - 1;
            ++pageFault;
            arr[idx] = arr[i];
        }
        
        if (currMem == mem) currMem = 0;
    }

    cout << pageFault << endl;
}

int main() {
    int t, n, mem;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cin >> mem;
        pageFaults(arr, n, mem);
    }
    return 0;
}