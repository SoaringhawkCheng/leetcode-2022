//
// Created by 成翔昊 on 2022/3/21.
//

#ifndef LEETCODE_2022_LIST_NODE_H
#define LEETCODE_2022_LIST_NODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode *next): val(val), next(next) {}
};

#endif //LEETCODE_2022_LIST_NODE_H
