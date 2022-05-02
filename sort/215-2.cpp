//
// Created by 成翔昊 on 2022/5/2.
//

#include <vector>

using namespace std;

class Solution {
    typedef vector<int>::iterator Iter;
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (k <= 0 || nums.size() < k) return -1;

        auto begin = nums.begin(), end = nums.end();
        while (begin < end) {
            auto pivot = partition(begin, end);
            int diff = pivot - nums.begin() + 1 - k;
            if (diff == 0) {
                return *pivot;
            } else if (diff > 0) end = pivot;
            else begin = next(pivot);
        }

        return -1;
    }

private:
    Iter partition(Iter begin, Iter end) {
        // begin < end由调用方保证
        // index之前都是大于等于pivot的
        auto pivot = begin, index = next(begin);
        for (Iter iter = next(begin); iter < end; iter++) {
            if (*iter >= *pivot) {
                iter_swap(index, iter);
                index++;
            }
        }

        iter_swap(pivot, prev(index));
        return prev(index);
    }
};