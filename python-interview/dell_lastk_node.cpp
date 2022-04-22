//
// Created by 成翔昊 on 2022/3/21.
//

#include "list_node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *dellLastKNode(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k < 1) {
            return head;
        }

        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k && fast != NULL; i++) {
            fast = fast->next;
        }

        if (fast == NULL) {
            return head->next;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};