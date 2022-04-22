//
// Created by 成翔昊 on 2022/4/3.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) {
            return 0;
        }

        vector<int> dp(s.size(), 0);
        int maxLen = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
                } else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') { // ')'
                    dp[i] = dp[i - 1] + ((i - 2 - dp[i - 1] >= 0) ? dp[i - 2 - dp[i - 1]] : 0) + 2;
                }

                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};

int main() {
    string s = ")(())(())(()";
    Solution solution;
    cout << solution.longestValidParentheses(s) << endl;
}