//
// Created by 成翔昊 on 2022/5/2.
//

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        // left表示第一个不是0的下标，right表示第一个不是2的下标
        auto left = nums.begin(), right = prev(nums.end());

        for (auto iter = nums.begin(); iter <= right;) {
            if (*iter == 0) {
                iter_swap(iter, left);
                left++;
                iter = left;
            } else if (*iter == 2) {
                iter_swap(iter, right);
                right--;
            } else {
                iter++;
            }
        }
    }
};