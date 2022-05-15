//
// Created by 成翔昊 on 2022/2/17.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        if (pairs.empty()) return 0;

        sort(pairs.begin(), pairs.end(), compare);

        int size = pairs.size(), maxSubSeq = 1;
        vector<int> dp(size, 1);
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxSubSeq = max(maxSubSeq, dp[i]);
                }
            }
        }
        return maxSubSeq;
    }

private:
    static bool compare(vector<int> lhs, vector<int> rhs) {
        return lhs[1] < rhs[1] || (lhs[1] == rhs[1] && lhs[0] < rhs[0]);
    }
};

int main() {
    Solution s;
    vector<vector<int>> pairs = {{3,  10},
                                 {3,  7},
                                 {7,  10},
                                 {7,  9},
                                 {-1, 7},
                                 {-9, 5},
                                 {2,  8}};
    cout << s.findLongestChain(pairs) << endl;
}