//
// Created by 成翔昊 on 2022/2/9.
//
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = curr;
            curr = max(prev + nums[i], curr);
            prev = tmp;
        }
        return curr;
    }
};