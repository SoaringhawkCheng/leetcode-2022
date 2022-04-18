//
// Created by 成翔昊 on 2022/4/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int currSum;
    vector<int> currList;
    vector<vector<int>> result;
public:
    Solution() : currSum(0) {}

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return result;
    }

private:
    void dfs(const vector<int> &candidates, int target, int currIndex) {
        if (currSum == target && !currList.empty()) {
            result.push_back(currList);
        }

        if (currSum >= target) {
            return;
        }

        for (int i = currIndex; i < candidates.size(); i++) {
            currList.push_back(candidates[i]);
            currSum += candidates[i];
            dfs(candidates, target, i);
            currSum -= candidates[i];
            currList.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> result = s.combinationSum(candidates, 7);
    for (auto row: result) {
        for (auto col: row) cout << col << " ";
        cout << endl;
    }
    return 0;
}