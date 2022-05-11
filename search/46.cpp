//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> visited;
    int size;
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.empty()) return result;
        size = nums.size();
        visited = vector<bool>(nums.size(), false);
        dfs(nums);
        return result;
    }

private:
    void dfs(vector<int> &nums) {
        if (path.size()==size) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums);
            visited[i] = false;
            path.pop_back();
        }
    }
};