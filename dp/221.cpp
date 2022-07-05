//
// Created by 成翔昊 on 2022/7/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // f[i][j] = {
    //      0                                           if i==0 or j==0 or matrix[i][j]
    //      min(f[i][j-1],f[i-1][j],f[i-1][j-1]) + 1    otherwise
    // }
    //
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i - 1][j - 1] == '0') continue;
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};

int main() {
    Solution s;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << s.maximalSquare(matrix) << endl;
}