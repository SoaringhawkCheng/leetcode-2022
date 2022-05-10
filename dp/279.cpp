//
// Created by 成翔昊 on 2022/2/17.
//

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> squareList = vector<int>();
        generateSquareList(squareList, n);

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int minNum = i;
            for (auto iter = squareList.begin(); iter != squareList.end(); iter++) {
                int rest = i - *iter;
                if (rest < 0) break;
                minNum = min(minNum, dp[rest] + 1);
            }
            dp[i] = minNum;
        }

        return dp[n];
    }

    void generateSquareList(vector<int> &squareList, int n) {
        int squareNum = 1;
        int diff = 3;
        while (squareNum <= n) {
            squareList.push_back(squareNum);
            squareNum += diff;
            diff += 2;
        }
    }
};