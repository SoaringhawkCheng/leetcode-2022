//
// Created by 成翔昊 on 2022/11/20.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // costs[i][j] 第i个房子用第j种油漆的花费
    // dp[i][j] 表示刷到第i个房子，用第j种油漆的最少花费
    // dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + costs[i][j]
    int minCost(vector<vector<int>> &costs) {
        if (costs.empty()) return 0;

        int row = costs.size(), col = costs[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col));
        for (int i = 1; i <= row; i++) {
            for (int j = 0; j < col; j++) {
                dp[i][j] = costs[i - 1][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }

        return min(min(dp[row][0], dp[row][1]), dp[row][2]);
    }
};

int main() {
    vector<vector<int>> costs = {
            {17, 2,  17},
            {16, 16, 5},
            {14, 3,  19}};
    Solution s;
    cout << s.minCost(costs) << endl;
}