//
// Created by 成翔昊 on 2022/2/17.
//

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int size = nums.size();
        vector<int> dp(size + 1, 0);
        int result = 0;
        for (int i = 1; i <= size; i++) {
            dp[i] = 1;
            for (int j=1;j<i;j++){
                if (nums[j-1] < nums[i-1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

//int main() {
//    Solution s;
//    vector<int> nums = {0,1,0,3,2,3};
//    cout << s.lengthOfLIS(nums) << endl;
//}