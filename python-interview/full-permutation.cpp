//
// Created by 成翔昊 on 2022/4/18.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> visited;
    vector<int> path;
    vector<vector<int>> results;
public:
    vector<vector<int>> permute(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            visited[i] = false;
        }

        dfs(nums);
        return results;
    }

    void dfs(const vector<int> &nums) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums);
                visited[i] = false;
                path.pop_back();

            }
        }
    }
};