//
// Created by 成翔昊 on 2022/5/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> nums;
    int size, target, count;
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        dfs(0, 0);
        this->nums = nums, this->target = target;
        size = nums.size(), count = 0;
        dfs(0, 0);
        return count;
    }

private:
    void dfs(int index, int sum) {
        if (index == size) {
            if (sum == target) {
                count++;
            }
            return;
        }

        dfs(index + 1, sum + nums[index]);
        dfs(index + 1, sum - nums[index]);
    }
};