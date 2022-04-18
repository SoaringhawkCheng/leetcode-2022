//
// Created by 成翔昊 on 2022/4/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<pair<int, int>> freq;
    int currSum;
    vector<int> currList;
    vector<vector<int>> result;
public:
    Solution() : currSum(0) {}

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (auto candidate: candidates) {
            if (freq.empty() || freq.back().first != candidate) {
                freq.push_back(make_pair(candidate, 1));
            } else {
                freq.back().second++;
            }
        }

        dfs(freq, target, 0);
        return result;
    }

private:
    void dfs(vector<pair<int, int>> freq, int target, int currIndex) {
        if (currSum == target && !currList.empty()) {
            result.push_back(currList);
        }

        if (currSum >= target) {
            return;
        }

        for (int i = currIndex; i < freq.size(); i++) {
            pair<int,int> &numFreq = freq[i];
            if (numFreq.second==0) continue;

            currList.push_back(freq[i].first);
            currSum += freq[i].first;
            numFreq.second--;
            dfs(freq, target, i);
            numFreq.second++;
            currSum -= freq[i].first;
            currList.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = s.combinationSum2(candidates, 8);
    for (auto row: result) {
        for (auto col: row) cout << col << " ";
        cout << endl;
    }
    return 0;
}