//
// Created by 成翔昊 on 2022/5/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), compare);
        if (points.empty()) {
            return 0;
        }

        int right = points[0][1], count = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] >= right) {
                count++;
                right = points[i][1];
            }
        }

        return count;
    }

private:
    static bool compare(const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[1] < rhs[1];
    }
};