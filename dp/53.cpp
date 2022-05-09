//
// Created by 成翔昊 on 2022/5/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    // f(i) = max(f(i-1)+nums[i], nums[i])
    int maxSubArray(vector<int> &nums) {
        int maxSum = nums[0], preSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum = max(nums[i], preSum+nums[i]);
            maxSum = max(maxSum, preSum);
        }
        return maxSum;
    }
};