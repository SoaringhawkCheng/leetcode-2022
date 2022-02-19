//
// Created by 成翔昊 on 2022/2/16.
//

#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n<=0) return 0;
        vector<int> dp = vector<int>(n+1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], j * dp[i-j]);
            }
        }

        return dp[dp.size()-1];
    }
};