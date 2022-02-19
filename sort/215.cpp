//
// Created by 成翔昊 on 2022/2/19.
//

#include "sort.h"

class Solution {
public:
//    int findKthLargest(vector<int> &nums, int k) {
//        QuickSort::sort(nums.begin(), nums.end());
//        for (auto num: nums) {
//            cout << num << " ";
//        }
//        cout << endl;
//
//        reverse(nums.begin(), nums.end());
//        for (auto num: nums) {
//            cout << num << " ";
//        }
//        cout << endl;
//        if (k > nums.size()) return INT_MAX;
//        return nums[k - 1];
//    }
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.empty() || k > nums.size() || k <= 0) {
            return INT_MAX;
        }

        auto begin = nums.begin();
        auto end = nums.end();

        while (begin < end) {
            for (auto num: nums) {
                cout << num << " ";
            }
            cout << endl;

            auto pivot = QuickSort::partitionDesc(begin, end);
            if (pivot - nums.begin() > k - 1) {
                end = pivot;
            } else if (pivot - nums.begin() < k - 1) {
                begin = next(pivot);
            } else {
                return *pivot;
            }
        }

        return INT_MAX;
    }
};

//int main() {
//    vector<int> nums = {3, 2, 1, 5, 6, 4};
//    Solution s;
//    cout << s.findKthLargest(nums, 2) << endl;
//}