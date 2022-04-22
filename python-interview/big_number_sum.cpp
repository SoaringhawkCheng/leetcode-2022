//
// Created by 成翔昊 on 2022/3/21.
//

#include "list_node.h"
#include <iostream>

using namespace std;

class Solution {
    ListNode *bigNumberSum(ListNode *head1, ListNode *head2) {
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        int carryBit = 0;
        while (head1 || head2 || carryBit) {
            int value1 = head1 == NULL ? 0 : head1->val;
            int value2 = head2 == NULL ? 0 : head2->val;

            int sumNum = value1 + value2 + carryBit;
            carryBit = carryBit/10;

            curr->next = new ListNode(sumNum % 10);
            curr = curr->next;
        }

        return dummy.next;
    }
};