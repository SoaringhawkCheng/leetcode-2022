//
// Created by 成翔昊 on 2022/7/19.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 对于开区间(left,right)，dp[left][right]表示戳破气球的最大收益，最后一个戳破的气球为mid
    // 那么dp[left][right] = max(val(left) * val(mid) * val(right) + dp[left][mid] + dp[mid][right]);
    // 边界条件left == right - 1，dp[left][right] == 0
    int maxCoins(vector<int> &nums) {
        vector<int> val = vector<int>(nums.size() + 2, 0);
        val[0] = val[nums.size() + 1] = 1;
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));

        for (int i = 0; i < nums.size(); i++) val[i + 1] = nums[i];
        for (int width = 2; width <= nums.size() + 2; width++) {
            for (int left = 0; left < nums.size() + 2 - width; left++) {
                for (int mid = left + 1; mid < left + width; mid++) {
                    dp[left][left + width] = max(dp[left][left + width], val[left] * val[mid] * val[left + width] + dp[left][mid] + dp[mid][left+width]);
                }
            }
        }

        return dp[0][nums.size() + 1];
    }
};

int main() {
    vector<int> nums = {3, 1, 5, 8};
    Solution s;
    cout << s.maxCoins(nums) << endl;
}