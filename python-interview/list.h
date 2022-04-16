//
// Created by 成翔昊 on 2022/4/14.
//

#ifndef LEETCODE_2022_LIST_H
#define LEETCODE_2022_LIST_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(NULL) {}

    ListNode(int x) : val(x), next(nullptr) {}
};

#endif //LEETCODE_2022_LIST_H
