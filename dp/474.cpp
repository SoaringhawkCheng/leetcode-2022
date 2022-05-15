//
// Created by 成翔昊 on 2022/5/15.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int zero;
    int one;
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        if (strs.empty() || m < 0 || n < 0) return 0;

        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));


        for (int i = 1; i <= size; i++) {
            countStr(strs[i-1]);
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zero && k >= one)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zero][k - one] + 1);
                }
            }
        }
        return dp[size][m][n];
    }

private:
    void countStr(string str) {
        zero = 0, one = 0;
        for (auto &ch: str) {
            if (ch == '0') zero++;
            if (ch == '1') one++;
        }
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    Solution s;
    cout << s.findMaxForm(strs, 5, 3) << endl;
}