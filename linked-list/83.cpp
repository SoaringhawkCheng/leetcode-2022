//
// Created by 成翔昊 on 2022/2/19.
//

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *curr = head;
        while (curr->next != NULL && curr->val == curr->next->val) curr=curr->next;
        head->next = deleteDuplicates(curr);
        return head;
    }
};