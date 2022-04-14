//
// Created by 成翔昊 on 2022/4/12.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) return s;

        vector<vector<bool>> dp(size, vector<bool>(size, 0));
        int maxLen = 1;
        int begin = 0;

        for (int i = 0; i < size; i++) {
            dp[i][i] = true;
        }

        for (int len = 2; len <= size; len++) {
            for (int i = 0; i < size; i++) {
                int j = len + i - 1;
                if (j >= size) break;
                if (s[i] != s[j]) dp[i][j] = false;
                else if (j - i < 3) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("aa") << endl;
}