//
// Created by 成翔昊 on 2022/3/21.
//

#include "list_node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCircle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return 0;
        }

        ListNode *fast = head, *slow = head;
        int len = 0;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            len++;
            // 相遇即有环，且步数是环长
            if (fast == slow) {
                return len;
            }
        }

        return 0;
    }
};