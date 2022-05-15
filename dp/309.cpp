//
// Created by 成翔昊 on 2022/5/14.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int size = prices.size();

        vector<int> buy(size);
        vector<int> sell(size);
        vector<int> active(size);

        buy[0] = -prices[0];
        for (int i = 1; i < size; i++) {
            buy[i] = max(buy[i - 1], active[i - 1] - prices[i]);
            sell[i] = buy[i - 1] + prices[i];
            active[i] = max(active[i - 1], sell[i - 1]);
        }

        return max(sell[size - 1], active[size - 1]);
    }
};