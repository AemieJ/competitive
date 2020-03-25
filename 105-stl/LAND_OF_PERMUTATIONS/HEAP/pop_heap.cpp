#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
    vector<int>num{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    make_heap(begin(num), end(num));
    pop_heap(begin(num), end(num));
    num.pop_back();
    return 0;
}