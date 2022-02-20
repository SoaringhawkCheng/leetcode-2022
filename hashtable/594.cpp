//
// Created by 成翔昊 on 2022/2/20.
//

#include "hashtable.h"

class Solution {
public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> numCounts;
        for (int i = 0; i < nums.size(); i++) {
            if (numCounts.find(nums[i]) != numCounts.end()) {
                numCounts[nums[i]]++;
            } else {
                numCounts[nums[i]] = 1;
            }
        }

        int longest = 0;
        for (auto iter = numCounts.begin(); iter != numCounts.end(); iter++) {
            if (numCounts.find(iter->first + 1) != numCounts.end()) {
                longest = max(longest, numCounts[iter->first] + numCounts[iter->first + 1]);
            }
        }
    }
};