//
// Created by 成翔昊 on 2022/2/19.
//

#include "sort.h"

void QuickSort::sort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin >= end) {
        return;
    }

    auto pivot = partition(begin, end);
    sort(begin, pivot);
    sort(next(pivot), end);
}

void QuickSort::sortDesc(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin >= end) {
        return;
    }

    auto pivot = partitionDesc(begin, end);
    sort(begin, pivot);
    sort(next(pivot), end);
}

vector<int>::iterator QuickSort::partition(vector<int>::iterator begin, vector<int>::iterator end) {
    // 保证[pivot, index)区间没有比pivotNum大，最后将prev(index)和pivot互换
    auto pivot = begin, index = next(begin);
    for (auto iter = next(begin); iter != end; iter++) {
        if (*iter < *pivot) {
            iter_swap(index, iter);
            index++;
        }
    }
    iter_swap(pivot, prev(index));
    return prev(index);
}

vector<int>::iterator QuickSort::partitionDesc(vector<int>::iterator begin, vector<int>::iterator end) {
    // 保证[pivot, index)区间没有比pivotNum小，最后将prev(index)和pivot互换
    auto pivot = begin, index = next(begin);
    for (auto iter = next(begin); iter != end; iter++) {
        if (*iter > *pivot) {
            iter_swap(index, iter);
            index++;
        }
    }
    iter_swap(pivot, prev(index));
    return prev(index);
}