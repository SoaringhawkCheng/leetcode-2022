//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        if (nums.empty()) {
            return target == 0;
        }

        int size = nums.size(), sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }

        if (target + sum < 0 || target - sum > 0) return false;

        vector<vector<int>> dp(size, vector<int>(2 * sum + 1));
        dp[0][sum - nums[0]] += 1;
        dp[0][sum + nums[0]] += 1;
        for (int i = 1; i < size; i++) {
            for (int j = nums[i]; j <= 2 * sum; j++)
                if (dp[i - 1][j - nums[i]]) dp[i][j] += dp[i - 1][j - nums[i]];

            for (int j = 2 * sum - nums[i]; j >= 0; j--)
                if (dp[i - 1][j + nums[i]]) dp[i][j] += dp[i - 1][j + nums[i]];
        }

        return dp[size - 1][sum + target];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    Solution s;
    cout << s.findTargetSumWays(nums, 3) << endl;
}
