//
// Created by 成翔昊 on 2022/10/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    typedef vector<int>::iterator Iter;
public:
    int findKthLargest(vector<int> &nums, int k) {
        Iter begin = nums.begin(), end = nums.end();
        while (begin < end) {
            auto pivot = partition(begin, end);
            int diff = k - (pivot - nums.begin() + 1);
            if (diff == 0) return *pivot;
            if (diff > 0) begin = next(pivot);
            else end = pivot;
        }

        return -1;
    }

private:
    Iter partition(Iter begin, Iter end) {
        auto pivot = begin, index = next(begin);
        for (auto iter = index; iter != end; iter++) {
            if (*iter >= *pivot) {
                iter_swap(iter, index);
                index++;
            }
        }

        iter_swap(pivot, prev(index));
        return prev(index);
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    Solution s;
    cout << s.findKthLargest(nums, 2) << endl;
}