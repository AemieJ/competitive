#include<bits/stdc++.h>

using namespace std;


void addStream(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    if (maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double findMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (maxHeap.size() == 0) return 0;
    if (maxHeap.size() > minHeap.size()) {
        return maxHeap.top();
    } else if(maxHeap.size() == minHeap.size()) {
        return ((double)(maxHeap.top() + minHeap.top())/2);
    }
}

int main() {
    int n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        addStream(val, maxHeap, minHeap);
        cout << floor(findMedian(maxHeap, minHeap)) << endl;
    }
    return 0;
}