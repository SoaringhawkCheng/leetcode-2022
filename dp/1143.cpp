//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size(), size2 = text2.size();
        if (!size1 || !size2) return 0;

        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[size1][size2];
    }
};

int main() {
    Solution s;
    cout << s.longestCommonSubsequence("abc", "def") << endl;
}