//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;

        int size = coins.size();
        vector<int> dp(amount + 1);
        // 用完前一种金币，在用下一种
        for (int i = 0; i < size; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (coins[i] == j) dp[j] = 1; // 初始化为1，为0无法区分是没有金币组合，或者是组合金币个数是0，无法直接使用
                else if (dp[j - coins[i]] > 0) // 能由本币加上已有组合构成
                    dp[j] = min(dp[j] > 0 ? dp[j] : INT_MAX, dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] > 0 ? dp[amount] : -1;
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    Solution s;
    cout << s.coinChange(coins, 11) << endl;
}