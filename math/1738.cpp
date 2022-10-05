//
// Created by 成翔昊 on 2022/10/4.
//

#include<vector>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        int row = matrix.size(), col = matrix[0].size();
        if (k > row * col) return -1;
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        vector<int> results;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                dp[i][j] = dp[i - 1][j - 1] ^ dp[i - 1][j] ^ dp[i][j - 1] ^ matrix[i - 1][j - 1];
                results.push_back(dp[i][j]);
            }
        }

        sort(results.begin(), results.end(), greater<int>());
        return results[k - 1];
    }
};