//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<bool>> dp;
    vector<string> path;
    vector<vector<string>> result;
public:
    vector<vector<string>> partition(string s) {
        dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));

        for (int i = 0; i < s.size(); i++) dp[i][i] = true;
        for (int i = 0; i < s.size() - 1; i++) dp[i][i + 1] = s[i] == s[i + 1];

        for (int i = 2; i < s.size(); i++) {
            for (int j = 0; j < s.size() - i; j++) {
                dp[j][j + i] = dp[j + 1][j + i - 1] && s[j] == s[i + j];
            }
        }

        dfs(s, 0);
        return result;
    }

private:
    void dfs(string &s, int index) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (!dp[index][i]) {
                continue;
            }
            path.push_back(s.substr(index, i - index + 1));
            dfs(s, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<string>> result = s.partition("aab");
    for (auto path: result) {
        for (auto substr: path) cout << substr << " ";
        cout << endl;
    }
}