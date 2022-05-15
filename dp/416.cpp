//
// Created by 成翔昊 on 2022/5/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() < 2) return false;

        int sum = 0;
        for (auto num: nums) sum += num;
        if (sum % 2 != 0) return false;

        // dp[i][j]表示下标在[0,i]区间的部分数字之和可以为j
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1));
        dp[0][0] = dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];

                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }

                if (nums[i] < j && dp[i - 1][j - nums[i]]) dp[i][j] = true;
            }
        }

        return dp[nums.size() - 1][sum / 2];
    }
};

int main() {
    vector<int> nums = {1, 5, 10, 6};
    Solution s;
    cout << s.canPartition(nums) << endl;
}