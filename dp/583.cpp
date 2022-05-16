//
// Created by 成翔昊 on 2022/5/16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // 子序列
        int size1 = word1.size(), size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                } else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return size1 + size2 - 2 * dp[size1][size2];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("sea", "eat") << endl;
}