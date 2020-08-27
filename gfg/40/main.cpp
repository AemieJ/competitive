#include<bits/stdc++.h>

using namespace std;

class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

int _stack :: getMin() {
    if (!s.empty()) {
        return minEle;
    } else {
        return -1;
    }
}
int _stack ::pop() {
    if (!s.empty()) {
        int val = s.top();
        s.pop();
        if (val < minEle) {
            minEle = 2*minEle - val;
            return ((val + minEle) / 2);
        }
        return val;
    } else {
        return -1;
    }
}   

void _stack::push(int x) {
    if (s.empty()) {
        minEle = x;
        s.push(x);
    } else {
        if (x < minEle) {
            s.push(2*x - minEle);
            minEle = x;
        } else {
           s.push(x); 
        }
    }
}

int main() {

    return 0;
}