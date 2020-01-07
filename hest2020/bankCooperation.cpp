#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h> 
using namespace std;

void findMaximumContainerSize(vector<int>relations[], vector<int>goldWeight) {
    int containerSize = 0;
    for(int i=1; i <= 8; ++i){
        int maxElement = *max_element(goldWeight.begin(), goldWeight.end());
        int maxElementIndex = max_element(goldWeight.begin(), goldWeight.end()) - goldWeight.begin();
        
        
        if(relations[i].size() == 0) 
            containerSize += goldWeight[i-1];
    }

}

int main() {
    int weight, company;
    int pair1, pair2;
	vector< int >goldWeight;
	string input;
    getline(cin, input);
    istringstream is(input);
    while(is>>weight) goldWeight.push_back(weight);
    cin >> company;
    vector< int >relations[9];
    for(int i=0; i < company; ++i) {
        cin >> pair1 >> pair2;
        relations[pair1].push_back(pair2);
        relations[pair2].push_back(pair1);
    }
    
    findMaximumContainerSize(relations, goldWeight);
    
	return 0;
}
