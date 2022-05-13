//
// Created by 成翔昊 on 2022/5/13.
//

#include <vector>
#include <iostream>

using namespace std;

// 对包含重复的序列进行全排列，返回不重复的排列
// 排列重复的本质是，两个相同值但是不同位置的数，会有各种组合
// 消除方式是相同的值，在排列中严格按从小大的位置排
// 即位置靠前的没有访问，位置靠后的不能被访问
class Solution {
private:
    vector<int> nums, path;
    vector<bool> visited;
    vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        visited.resize(nums.size());
        dfs();
        return result;
    }

private:
    void dfs() {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]))
                continue;

            path.push_back(nums[i]);
            visited[i] = true;
            dfs();
            visited[i] = false;
            path.pop_back();
        }
    }
};