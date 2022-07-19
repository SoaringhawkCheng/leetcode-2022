//
// Created by 成翔昊 on 2022/2/17.
//
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] != '0');

        for (int i = 2; i <= size; i++) {
            int num1 = stoi(s.substr(i - 1, 1));

            if (num1 != 0) {
                dp[i] += dp[i - 1];
            }

            if (s[i - 2] == '0') continue;
            int num2 = stoi(s.substr(i - 2, 2));
            if (num2 <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[size];
    }
};

//int main() {
//    Solution s;
//    cout << s.numDecodings("2101") << endl;
//}