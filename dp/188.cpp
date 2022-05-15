//
// Created by 成翔昊 on 2022/5/14.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        int size = prices.size();
        vector<vector<int>> buy(size, vector<int>(k + 1));
        vector<vector<int>> sell(size, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        for (int i = 1; i <= k; i++) buy[0][i] = sell[0][i] = INT_MIN / 2;

        for (int i = 1; i < size; i++) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }

        int maxProfit = 0;
        for (auto profit: sell[size - 1]) {
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};