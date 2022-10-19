//
// Created by 成翔昊 on 2022/10/11.
//

#include "list_node.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode *node) {
        ListNode *prev = NULL;
        while (node->next != NULL) {
            prev = node;
            node->val = node->next->val;
            node = node->next;
        }
        prev->next = NULL;
    }
};