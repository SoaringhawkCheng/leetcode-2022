//
// Created by 成翔昊 on 2022/11/20.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>> &costs) {
        if (costs.empty() || costs[0].empty()) return 0;

        int row = costs.size(), col = costs[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col));

        for (int i = 1; i <= row; i++) {
            for (int j = 0; j < col; j++) {
                int minimum = INT_MAX;
                for (int k = 1; k < col; k++) minimum = min(minimum, dp[i - 1][(j + k) % col]);
                dp[i][j] = costs[i - 1][j] + minimum;
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < col; i++) {
            result = min(result, dp[row][i]);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> costs = {
            {1, 3},
            {2, 4}
    };
    Solution s;
    cout << s.minCostII(costs) << endl;
}