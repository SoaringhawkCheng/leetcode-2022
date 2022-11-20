//
// Created by 成翔昊 on 2022/11/5.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;
        int index = 0;

        for (; index < intervals.size() && intervals[index][1] < newInterval[0]; index++)
            result.push_back(intervals[index]);

        int left = newInterval[0], right = newInterval[1];
        for (; index < intervals.size() && intervals[index][0] <= newInterval[1]; index++) {
            left = min(left, intervals[index][0]);
            right = max(right, intervals[index][1]);
        }
        result.push_back({left, right});

        for (; index < intervals.size(); index++) result.push_back(intervals[index]);

        return result;
    }
};