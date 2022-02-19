//
// Created by 成翔昊 on 2022/2/9.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }

        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }

    int rob(vector<int>& nums, int begin, int end) {
        int prev = 0, curr = 0;
        for (int i = begin; i < end; i++) {
            int tmp = curr;
            curr = max(prev + nums[i], curr);
            prev = tmp;
        }
        return curr;
    }
};