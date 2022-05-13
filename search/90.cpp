//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> nums, path;
    vector<bool> visited;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        visited.resize(nums.size());
        dfs(0);
        return result;
    }

private:
    void dfs(int index) {
        result.push_back(path);
        if (index == nums.size()) return;

        for (int i = index; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            path.push_back(nums[i]);
            visited[i] = true;
            dfs(i + 1);
            visited[i] = false;
            path.pop_back();
        }
    }
};