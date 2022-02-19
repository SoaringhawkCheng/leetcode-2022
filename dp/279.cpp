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
            vector<int>::iterator iter = squareList.begin();
            while (iter != squareList.end() && *iter <= i) {
                minNum = min(minNum, dp[i - *iter] + 1);
                iter++;
            }
            dp[i] = minNum;
        }

        return dp[n];
    }

    void generateSquareList(vector<int> &squareList, int n) {
        int squareNum = 1;
        int diff = 1;
        while (squareNum <= n) {
            squareList.push_back(squareNum);
            diff = diff + 2;
        }
    }
};