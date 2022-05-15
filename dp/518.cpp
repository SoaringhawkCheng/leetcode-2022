//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        if (amount < 0) return 0;

        vector<int> dp(amount + 1);
        dp[0] = 1; // 楼梯初始数

        // 爬楼梯 2+5和5+2是一种组合，所以要保证2在5前面
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    cout << s.change(5, coins) << endl;
}