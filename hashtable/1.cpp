//
// Created by 成翔昊 on 2022/2/20.
//

#include "hashtable.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> numIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (numIndex.find(target - nums[i]) != numIndex.end()) {
                return {numIndex[target - nums[i]], i};
            } else {
                numIndex[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};