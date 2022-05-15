//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        if (target < 0) return 0;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] > i || dp[i] > INT_MAX - dp[i - nums[j]]) continue;
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    cout << s.combinationSum4(nums, 4) << endl;
}