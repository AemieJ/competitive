/* TWO SUM 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// ==== SOLUTION ==== O(N^2)//
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>pair;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    pair.push_back(i);
                    pair.push_back(j);
                    break;
                }
            }
        }
        return pair;
    }
};

// ==== BETTER APPROACH ==== O(N) // 
// Using Hash Table

class Solution {
public: 
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>pair;
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = find(nums.begin(), nums.end(), complement);
            if ( it != nums.end()) {
                pair.push_back(distance(nums.begin(), it));
            }
        }
    }
};