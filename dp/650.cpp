//
// Created by 成翔昊 on 2022/5/16.
//

#include <vector>
#include <iostream>

using namespace std;

// (0,1,2)

class Solution {
public:
    int minSteps(int n) {
        if (n == 0) return 0;
        vector<int> dp(n + 1);

        for (int i = 2; i <= n; i++) {
            dp[i] = INT_MAX;
            for (int j = 1; j < i / 2 + 1; j++)
                if (i % j == 0) dp[i] = min(dp[i], dp[j] + i/j);
        }

        return dp[n];
    }
};