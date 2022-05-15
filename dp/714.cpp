//
// Created by 成翔昊 on 2022/5/14.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        if (prices.empty()) return 0;

        vector<int> buy(prices.size());
        vector<int> sell(prices.size());

        buy[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return sell[prices.size() - 1];
    }
};