//
// Created by 成翔昊 on 2022/2/27.
//

#include "list_node.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> stk1 = buildStack(l1);
        stack<int> stk2 = buildStack(l2);

        ListNode dummy(-1);
        int carryBit = 0;
        while (!stk1.empty() || !stk2.empty() || carryBit) {
            int top1 = 0, top2 = 0;

            if (!stk1.empty()) {
                top1 = stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                top2 = stk2.top();
                stk2.pop();
            }

            ListNode *p = new ListNode((top1 + top2 + carryBit) % 10);
            carryBit = (top1 + top2 + carryBit) / 10;

            p->next = dummy.next;
            dummy.next = p;
        }

        return dummy.next;
    }

private:
    stack<int> buildStack(ListNode *l) {
        stack<int> stk;
        while (l!=NULL) {
            stk.push(l->val);
            l = l->next;
        }
        return stk;
    }
};

//int main() {
//    vector<int> nums1 = {7, 2, 4, 3};
//    vector<int> nums2 = {5, 6, 4};
//    ListNode dummy1(-1);
//    ListNode dummy2(-1);
//    for (auto num: nums1) {
//        ListNode *p = new ListNode(num);
//        p->next = dummy1.next;
//        dummy1.next = p;
//    }
//    for (auto num: nums2) {
//        ListNode *p = new ListNode(num);
//        p->next = dummy2.next;
//        dummy2.next = p;
//    }
//    Solution s;
//    s.addTwoNumbers(dummy1.next, dummy2.next);
//}