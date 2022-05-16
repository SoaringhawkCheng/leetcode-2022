//
// Created by 成翔昊 on 2022/5/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size(), size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));

        for (int i = 1; i <= size1; i++) dp[i][0] = i;
        for (int j = 1; j <= size2; j++) dp[0][j] = j;

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[size1][size2];
    }
};

int main() {
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
}