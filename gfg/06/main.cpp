/*
Logic of super 
We have 2 arrays but we want to use 1 itself.
[1 4 5 6 7]
[2 5 6 7 8]
super = 9
1 * 9 + 2 = 11
4 * 9 + 5 = 41 ..and so on
newArr = [11 41 51 61 71]

To retrieve the values: 
11 / 9 = 2 
11 % 9 = 1
*/

#include<stdio.h>
#include<algorithm>
#include<vector> 
#include<bits/stdc++.h>

using namespace std;

void alternate(vector<long>& arr);
void printVector(vector<long> v);

long main() {
    long testCases; 
    cin >> testCases; 
    for (long i = 0; i < testCases; ++i) {
        long size; 
        vector<long> arr;
        cin >> size;
        for (long j = 0; j < size; ++j) {
            long elm;
            cin >> elm;
            arr.push_back(elm);            
        }
        alternate(arr);
        printVector(arr);
    }
    return 0;
}

void printVector(vector<long> v) {
    for (long i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void alternate(vector<long>& arr) {
    sort(arr.begin(), arr.end());
    long super = *(arr.end() - 1) + 1;
    cout << super << endl;
    long l = 0; 
    long r = arr.size() - 1;

    for (long i = 0; i < arr.size(); ++i) {
        if (i % 2) {
            arr[i] += (arr[l] % super) * super;
            ++l;
        } else {
            arr[i] += (arr[r] % super) * super;
            --r;
        }
    }

    for (long j = 0; j < arr.size(); ++j) {
        arr[j] /= super;
    }
}