//
// Created by 成翔昊 on 2022/2/17.
//

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        int size = nums.size(), maxSubSeq = 1;
        vector<int> dp(size, 1);
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxSubSeq = max(maxSubSeq, dp[i]);
                }
            }
        }

        return maxSubSeq;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << s.lengthOfLIS(nums) << endl;
}