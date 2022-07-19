//
// Created by 成翔昊 on 2022/7/5.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.size() < 2) return true;

        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] > intervals[i][0]) return false;
        }
        return true;
    }

private:
    static bool compare(vector<int> &lhs, vector<int> &rhs) {
        return lhs[1] < rhs[1];
    }
};