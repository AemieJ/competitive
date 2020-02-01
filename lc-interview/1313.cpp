/* ==== QUESTION ==== */

/*
Decompress Run-Length Encoded List (Easy)

We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [a, b] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are a elements with value b in the decompressed list.

Return the decompressed list.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4,4] is [2,4,4,4].
 

Constraints:

2 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>res;
        int length = nums.size();
        
        for (int i=0; i < length; ++i) {
            if (2*i < length &&  (2*i+1) < length) {
                int freq = 2*i,
                    val = 2*i + 1;
                for (int j=0; j < nums[freq]; ++j) {
                    res.push_back(nums[val]);
                }
            } else {
                break;
            }
        }
        
        return res;
    }
};
