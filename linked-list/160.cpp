//
// Created by 成翔昊 on 2022/2/19.
//

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = 0, size2 = 0;
        ListNode *currA = headA;
        ListNode *currB = headB;

        while (currA!=NULL) {
            size1++;
            currA = currA->next;
        }
        while (currB!=NULL) {
            size2++;
            currB = currB->next;
        }

        if (size1 < size2) {
            return getIntersectionNode(headB, headA, size2 - size1);
        } else {
            return getIntersectionNode(headA, headB, size1 - size2);
        }
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB, int diff) {
        for (int i = 0; i < diff; i++) {
            headA = headA->next;
        }

        while (headA!=NULL && headB!=NULL && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

//int main() {
//    ListNode a1 = ListNode(0);
//    ListNode a2 = ListNode(0);
//    ListNode a3 = ListNode(0);
//    ListNode a4 = ListNode(0);
//    ListNode b1 = ListNode(0);
//    ListNode b2 = ListNode(0);
//    ListNode c1 = ListNode(0);
//    ListNode c2 = ListNode(0);
//    ListNode c3 = ListNode(0);
//
//    a1.next = &a2;
//    a2.next = &a3;
//    a3.next = &a4;
//    a4.next = &c1;
//
//    b1.next = &b2;
//    b2.next = &c1;
//
//    c1.next = &c2;
//    c2.next = &c3;
//
//    Solution s;
//    s.getIntersectionNode()
//}