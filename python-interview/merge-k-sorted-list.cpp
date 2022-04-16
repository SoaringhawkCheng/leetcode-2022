//
// Created by 成翔昊 on 2022/4/14.
//

#include <iostream>
#include <vector>
#include "list.h"

using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode *merge(vector<ListNode *> &lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return NULL;
        int mid = left + (right - left) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        ListNode dummy(-1), *curr = &dummy;
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        curr->next = (head1 == NULL) ? head2 : head1;
        return dummy.next;
    }
};