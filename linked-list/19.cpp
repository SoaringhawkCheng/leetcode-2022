//
// Created by 成翔昊 on 2022/2/19.
//
#include "list_node.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast, *slow;
        fast = slow = &dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
            if (fast == NULL) return head;
        }

        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow->next!=NULL) {
            slow->next = slow->next->next;
        }

        return dummy.next;
    }
};