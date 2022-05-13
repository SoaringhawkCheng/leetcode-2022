//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    int sum, target;
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        sum = 0, this->target = target;
        dfs(candidates, 0);
        return result;
    }

private:
    void dfs(vector<int> &candidates, int index) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(path);
        }

        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};