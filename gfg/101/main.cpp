/* HIGHLY IMPORTANT QUES */
#include<bits/stdc++.h>

using namespace std;

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

bool areaSort(tuple<int, int, int>& a, tuple<int, int, int> &b) {
    int areaA = get<0>(a) * get<1>(a);
    int areaB = get<0>(b) * get<1>(b);
    return (areaA > areaB);
}

int maxHeight(int h[],int w[],int l[],int n) {
    vector<tuple<int,int,int> > v;
    //Generate all rotation of boxes
    for(int i=0;i<n;i++){
        if(l[i] > w[i])
            v.push_back(make_tuple(l[i],w[i],h[i]));
        else
            v.push_back(make_tuple(w[i],l[i],h[i]));
        if(w[i] > h[i])
            v.push_back(make_tuple(w[i],h[i],l[i]));
        else
            v.push_back(make_tuple(h[i],w[i],l[i]));
        if(h[i] > l[i])
            v.push_back(make_tuple(h[i],l[i],w[i]));
        else
            v.push_back(make_tuple(l[i],h[i],w[i]));
    }

    sort(v.begin(), v.end(), areaSort);
    
    int size = v.size();
    int dp[size];
    for(int i = 0; i < size; ++i) {
        tuple<int, int, int> a = v[i];
        int height = get<2>(a);
        dp[i] = height;
    }

    for(int i = 1; i < size; ++i) {
        for(int j = 0; j < i; ++j) {
            int l1 = get<0>(v[i]);
            int l2 = get<0>(v[j]);

            int w1 = get<1>(v[i]);
            int w2 = get<1>(v[j]);

            int h1 = get<2>(v[i]);

            if (l1 < l2 && w1 < w2 && dp[i] < h1 + dp[j]) {
                dp[i] = h1 + dp[j];
            }

        }
    }
    
    return *max_element(dp ,dp + size);
}