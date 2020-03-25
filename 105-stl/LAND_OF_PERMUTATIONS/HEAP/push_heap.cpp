#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
    vector<int>num{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    make_heap(begin(num), end(num));
    num.push_back(8.88);
    push_heap(begin(num), end(num));
    return 0;
}