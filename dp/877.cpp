//
// Created by 成翔昊 on 2022/10/3.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // dp[i][j]表示当剩下的石子堆为下标i到下标j时，当前玩家执行最优策略的最大收益
    // dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
    // i==j 的情况，dp[i][j] = piles[i]
    bool stoneGame(vector<int> &piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        for (int index = 0; index < piles.size(); index++)
            dp[index][index] = piles[index];

        for (int step = 1; step < piles.size(); step++) {
            for (int index = 0; index < piles.size() - step; index++) {
                dp[index][index + step] = max(
                        piles[index] - dp[index + 1][index + step],
                        piles[index + step] - dp[index][index + step - 1]
                );
            }
        }

        return dp[0][piles.size() - 1] > 0;
    }
};