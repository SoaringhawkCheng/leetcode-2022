//
// Created by 成翔昊 on 2022/2/16.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }

        if (nums.size() == 2) {
            return 1;
        }

        vector<int> dp = vector<int>(nums.size(), 0);
        dp[1] = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = 1;
            }
        }

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += dp[i];
        }

        return result;
    }
};

//int main() {
//    Solution s = Solution();
//    vector<int> nums = {1, 2, 3, 4};
//    cout << s.numberOfArithmeticSlices(nums) << endl;
//}