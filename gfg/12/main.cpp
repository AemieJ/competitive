/* IMPORTANT QUESTION */
// Program to find minimum number of platforms
// required on a railway station

#include <bits/stdc++.h>
using namespace std;

// Driver function to sort the vector elements
// by first element and after that second element
bool customsort(const pair<int,char> &a,const pair<int,char> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

//Position this line where user code will be pasted.
// Driver code

int findPlatform(int arr[], int dep[], int n)
{
    // Insert all the times (arr. and dep.)
    // in the vector of pairs.
    vector< pair<int,char> > order;
    for (int i = 0; i < n; i++) {

        // If its arrival then second value
        // of pair is 'a' else 'd'
        order.push_back(make_pair(arr[i], 'a'));
        order.push_back(make_pair(dep[i], 'd'));
    }

    // custom sort order vector, first by time than by
    // arrival or departure
    sort(order.begin(),order.end(),customsort);

    int result = 1;
    int plat_needed = 0;

    vector< pair<int,char> >::iterator it = order.begin();

    // Start iterating the multimap.
    for (; it != order.end(); it++) {
        // If its 'a' then add 1 to plat_needed
        // else minus 1 from plat_needed.
        if ((*it).second == 'a')
            plat_needed++;
        else
            plat_needed--;

        if (plat_needed>result)
            result = plat_needed;
    }
    return result;
}
//Position this line where user code will be pasted.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
           for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}