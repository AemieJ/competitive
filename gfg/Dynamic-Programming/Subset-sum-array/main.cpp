/*
Asumption: array is sorted & consists of only positive integers
arr = [2, 4, 6, 10]
sum = 16
subsets = [{2, 4, 6}, {6, 10}] 
o/p = 2
*/

#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int subsetArrayRecursion(vector<int> arr, int total, int index);
int mainArrayInput(vector<int> arr, int total);

int subsetArrayMemoization(vector<int> arr, int total, int index, map<string, int> memory);
int mainArrayMemoization(vector<int> arr, int total);

int main() {
    vector<int> arr = {2, 4, 6, 10};
    int sum = 16;
    cout << mainArrayInput(arr, sum) << endl;
    cout << mainArrayMemoization(arr, sum) << endl;
    return 0;
}

// Recursive Method
int subsetArrayRecursion(vector<int> arr, int total, int index) {
    if (total == 0) return 1;
    else if (total < 0 || index < 0) return 0;
    else if (total < arr[index]) {
        return subsetArrayRecursion(arr, total, index - 1);
    }
    else {
        return subsetArrayRecursion(arr, total, index - 1) + subsetArrayRecursion(arr, total - arr[index], index - 1);
    }

}

int mainArrayInput(vector<int> arr, int total) {
    return subsetArrayRecursion(arr, total, arr.size() - 1);
}

// Memoization Method
int subsetArrayMemoization(vector<int> arr, int total, int index, map<string, int> memory) {
    string key = to_string(total) + " : " + to_string(index);
    int value;
    auto it = memory.find(key);
    if (it != memory.end()) return it->second;
    if (total == 0) return 1;
    else if (total < 0 || index < 0) return 0;
    else if (total < arr[index]) {
        return subsetArrayMemoization(arr, total, index - 1, memory);
    }
    else {
        value = subsetArrayMemoization(arr, total, index - 1, memory) + subsetArrayMemoization(arr, total - arr[index], index - 1, memory);
        memory.insert(pair<string, int>(key, value));
    }
    return value;
}   

int mainArrayMemoization(vector<int> arr, int total) {
    map<string, int> memory;
    return subsetArrayMemoization(arr, total, arr.size() - 1, memory);
}