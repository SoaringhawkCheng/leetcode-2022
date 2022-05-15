//
// Created by 成翔昊 on 2022/5/15.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        if (pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), compare);

        int right = pairs[0][1], count = 1;
        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > right) {
                right = pairs[i][1];
                count++;
            }
        }

        return count;
    }

private:
    static bool compare(vector<int> lhs, vector<int> rhs) {
        return lhs[1] < rhs[1] || (lhs[1] == rhs[1] && lhs[0] < rhs[0]);
    }
};