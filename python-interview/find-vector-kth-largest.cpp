//
// Created by 成翔昊 on 2022/4/19.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    typedef vector<int>::iterator Iterator;
public:
    int findKthLargest(vector<int> &nums, int k) {
        auto begin = nums.begin(), end = nums.end();
        while (begin < end) {
            auto pivot = partition(begin, end);
            int diff = pivot - nums.begin() + 1 - k;
            if (diff == 0) return *pivot;
            else if (diff > 0) {
                end = pivot;
            } else {
                begin = next(pivot);
            }
        }
        return -1;
    }

private:
    Iterator partition(Iterator begin, Iterator end) {
        auto pivot = begin;
        auto iter = next(begin), index = next(begin);
        for (; iter < end; iter++) {
            if (*iter > *pivot) {
                iter_swap(iter, index);
                index++;
            }
        }
        iter_swap(pivot, prev(index));
        return prev(index);
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(nums, 4) << endl;
}