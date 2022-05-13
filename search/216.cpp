//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int k, n, sum;
    vector<int> path;
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k, this->n = n, sum = 0;
        dfs(1);
        return result;
    }

private:
    void dfs(int index) {
        if (path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }

        for (int i = index; i <= 9; i++) {
            path.push_back(i);
            sum += i;
            dfs(i + 1);
            sum -= i;
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> result = s.combinationSum3(9, 45);
    for (auto res: result) {
        for (auto num: res) cout << num << " ";
        cout << endl;
    }
}