//
// Created by 成翔昊 on 2022/3/21.
//

#include "list_node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *mergeTwoSortedList(ListNode *head1, ListNode *head2) {
        ListNode dummy(-1);
        ListNode *curr = &dummy;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if (head1 != NULL) {
            curr->next = head1;
        }

        if (head2 != NULL) {
            curr->next = head2;
        }

        return dummy.next;
    }
};