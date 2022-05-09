//
// Created by 成翔昊 on 2022/5/4.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // 最优的解的首个区间，不存在右边界比这个区间的小的，否则就会有更优解
    // 划掉这个区间，剩下来的也可以用这个方式找最优解，一直找左边界大于right的右边界最小的区间，并更新right
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), this->compare);

        int right = intervals[0][1], count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= right) {
                ++count;
                right = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }

private:
    static bool compare(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 2},
                                     {2, 3},
                                     {3, 4},
                                     {1, 3}};
    Solution s;
    cout << s.eraseOverlapIntervals(intervals) << endl;
}