//
// Created by 成翔昊 on 2022/2/19.
//

#ifndef LEETCODE_2022_LIST_NODE_H
#define LEETCODE_2022_LIST_NODE_H

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //LEETCODE_2022_LIST_NODE_H
