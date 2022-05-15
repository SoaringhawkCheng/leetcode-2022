//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int size = s.size();
        vector<bool> dp(size + 1);
        dp[0] = true;

        for (int i = 1; i <= size; i++) {
            for (auto &word: wordDict) {
                int len = word.length();
                if (i < len) continue;
                if (word == s.substr(i - len, len))
                    dp[i] = dp[i] | dp[i - len];
            }
        }

        return dp[size];
    }
};