//
// Created by 成翔昊 on 2022/3/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void quickSort(vector<int> &nums) {
        quickSort(nums.begin(), nums.end());
    }

private:
    void quickSort(vector<int>::iterator begin, vector<int>::iterator end) {
        if (begin >= end) {
            return;
        }

        auto pivot = partition(begin, end);
        quickSort(begin, pivot);
        quickSort(next(pivot), end);
    }

    vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {
        // step1: pivot取第一个元素，index始终指向第一个不小于pivot的元素
        // step2: iter从next(pivot)开始迭代，当遇到比pivot小的数，将index和iter的值互换并自增
        // step3: iter迭代完成，将index和pivot互换
        int pivotNum = *begin;
        auto index = next(begin);
        for (auto iter = next(begin); iter != end; iter++) {
            if (*iter < pivotNum) {
                iter_swap(iter, index);
                index++;
            }
        }
        iter_swap(prev(index), begin);
        return prev(index);
    }
};

//int main() {
//    vector<int> nums = {1, 4, 2, 8, 5, 7};
//    Solution s;
//    s.quickSort(nums);
//    for (auto num: nums) {
//        cout << num << " ";
//    }
//    cout << endl;
//}