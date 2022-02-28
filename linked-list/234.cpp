//
// Created by 成翔昊 on 2022/2/27.
//

#include "list_node.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode *fast = head, *slow = head;
        while (slow->next!=NULL && slow->next->next != NULL)
            fast = fast->next, slow = slow->next->next;
        ListNode dummy(-1);
        ListNode *curr = fast->next;
        fast->next = NULL;

        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = tmp;
        }

        ListNode *head2 = dummy.next;
        while (head != NULL && head2 != NULL) {
            if (head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};