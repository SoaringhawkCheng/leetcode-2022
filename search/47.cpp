//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<int, int> visited;
    unordered_map<int, int> countMap;
    vector<int> path;
    int size;
    vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        for (auto num: nums) countMap[num]++;
        size = nums.size();
        dfs();
        return result;
    }

private:
    void dfs() {
        if (path.size() == size) {
            result.push_back(path);
            return;
        }

        for (auto &count: countMap) {
            if (!path.empty() && path.back() == count.first) continue;

            vector<int> tmp;
            for (int i = 1; i <= count.second; i++) {
                tmp.push_back(count.first);
                path.insert(path.end(), tmp.begin(), tmp.end());
                count.second -= i;
                dfs();
                count.second += i;
                path.erase(path.end() - i, path.end());
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    Solution s;
    vector<vector<int>> result = s.permuteUnique(nums);
    for (auto res: result) {
        for (auto num: res) cout << num << " ";
        cout << endl;
    }
}