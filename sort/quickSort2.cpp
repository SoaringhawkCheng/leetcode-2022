//
// Created by 成翔昊 on 2022/2/26.
//

#include "sort.h"

void QuickSort2::sort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end) {
        return;
    }

    auto pivot = partition(begin, end);
    sort(begin, pivot);
    sort(next(pivot), end);
}

void QuickSort2::sortDesc(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end) {
        return;
    }

    auto pivot = partitionDesc(begin, end);
    sort(begin, pivot);
    sort(next(pivot), end);
}

vector<int>::iterator QuickSort2::partition(vector<int>::iterator begin, vector<int>::iterator end) {
    // [begin, index) < pivot, [index, end) > pivot
    auto pivot = begin, index = next(begin);
    for (auto iter = next(begin); iter != end; iter++) {
        if (*iter <= *pivot) {
            iter_swap(iter, index);
            index++;
        }
    }
    iter_swap(pivot, prev(index));
    return prev(index);
}

vector<int>::iterator QuickSort2::partitionDesc(vector<int>::iterator begin, vector<int>::iterator end) {
    // [begin, index) < pivot, [index, end) > pivot
    auto pivot = begin, index = next(begin);
    for (auto iter = next(begin); iter != end; iter++) {
        if (*iter <= *pivot) {
            iter_swap(iter, index);
            index++;
        }
    }
    iter_swap(pivot, prev(index));
    return prev(index);
}

//int main() {
//    QuickSort2 qs = QuickSort2();
//    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
//    qs.sortDesc(nums.begin(), nums.end());
//    for (auto num: nums) {
//        cout << num << " ";
//    }
//    cout << endl;
//}