//
// Created by 成翔昊 on 2022/2/19.
//

#ifndef LEETCODE_2022_SORT_H
#define LEETCODE_2022_SORT_H

#include<iostream>
#include<vector>
#include<iterator>
#include<unordered_map>
using namespace std;

class QuickSort{
public:
    static void sort(vector<int>::iterator begin, vector<int>::iterator end);
    static void sortDesc(vector<int>::iterator begin, vector<int>::iterator end);
    static vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end);
    static vector<int>::iterator partitionDesc(vector<int>::iterator begin, vector<int>::iterator end);
};

#endif //LEETCODE_2022_SORT_H
