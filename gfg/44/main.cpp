#include<bits/stdc++.h>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int diff = 0, deficiet = 0;
   int start = 0;
   for(int i = 0; i < n; ++i) {
       int amount = p[i].petrol;
       int dist = p[i].distance;
       diff += amount - dist;
       if (diff < 0) {
           start = i + 1;
           deficiet += diff;
           diff = 0;
       }
   }
   return (deficiet + diff >=0 ? start : -1);
}

int main() {
    return 0;
}