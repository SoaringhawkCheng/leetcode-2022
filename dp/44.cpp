//
// Created by 成翔昊 on 2022/7/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
        dp[0][0] = true;

        for (int level = 1; level <= p.size(); level++) {
            dp[level][0] = (p[level - 1] == '*' && dp[level - 1][0]);

            for (int index = 1; index <= s.size(); index++) {
                if (p[level - 1] == '*') {
                    for (int i = index; i >= 0; i--) {
                        if (dp[level - 1][i]) {
                            dp[level][index] = true;
                            break;
                        }
                    }
                } else if (p[level - 1] == '?') {
                    dp[level][index] = dp[level - 1][index - 1];
                } else {
                    dp[level][index] = dp[level - 1][index - 1] && p[level - 1] == s[index - 1];
                }
            }
        }

        return dp[p.size()][s.size()];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("adceb", "*a*b") << endl;
}