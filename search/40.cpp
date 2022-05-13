//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int sum, target;
    vector<int> candidates, path;
    vector<vector<int>> result;
    vector<bool> visited;
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates, this->target = target;
        sum = 0;
        visited.resize(candidates.size());
        dfs(0);
        return result;
    }

private:
    void dfs(int index) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        if (sum > target || index >= candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (visited[i] || (i > 0 && candidates[i - 1] == candidates[i] && !visited[i - 1])) continue;

            sum += candidates[i];
            path.push_back(candidates[i]);
            visited[i] = true;
            dfs(i + 1);
            visited[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    Solution s;
    s.combinationSum2(candidates, 8);
}
