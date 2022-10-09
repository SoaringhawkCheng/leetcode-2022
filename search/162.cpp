//
// Created by 成翔昊 on 2022/10/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.empty()) return -1;
        auto begin = nums.begin(), end = nums.end();
        while (begin < end) {
            // 0->1->end
            auto mid = begin + (end - begin) / 2;
            if (mid == begin) return mid - begin;
            if (*mid < *prev(mid)) {
                end = mid;
            } else {
                begin = mid;
            }
        }

        return -1;
    }
};