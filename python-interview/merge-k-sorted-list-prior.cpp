//
// Created by 成翔昊 on 2022/4/14.
//

#include <iostream>
#include <queue>
#include "list.h"

using namespace std;

struct PriorityListNode {
    int val;
    ListNode *ptr;

    bool operator<(const PriorityListNode &rhs) const {
        return val > rhs.val;
    }
};

class Solution {
private:
    priority_queue<PriorityListNode> q;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (auto node: lists) {
            if (node != NULL) {
                q.push({node->val, node});
            }
        }
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            curr->next = top.ptr;
            curr = curr->next;
            if (top.ptr->next != NULL)
                q.push({top.ptr->next->val, top.ptr->next});
        }
        return dummy.next;
    }
};