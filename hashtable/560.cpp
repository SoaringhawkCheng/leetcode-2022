//
// Created by 成翔昊 on 2022/11/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 前缀和
    int subarraySum(vector<int> &nums, int k) {
        if (nums.empty()) return k == 0;

        unordered_map<int, int> preSumMap;
        preSumMap[0] = 1; //前缀和为0的有1个
        int preSum = 0, count = 0;
        for (auto num: nums) {
            preSum+=num;
            if (preSumMap.find(preSum-k)!=preSumMap.end()) {
                count += preSumMap[preSum-k];
            }
            preSumMap[preSum]++;
        }
        return count;
    }
};