//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }

private:
    void dfs(vector<int>& nums, int index) {
        result.push_back(path);
        if (index == nums.size()) return;

        for (int i=index; i<nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
};