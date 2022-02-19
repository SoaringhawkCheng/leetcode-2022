//
// Created by 成翔昊 on 2022/2/19.
//

#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1);
        while(head!=NULL) {
            ListNode *tmp = dummy.next;
            dummy.next = head;
            head = head->next;
            dummy.next->next = tmp;
        }
        return dummy.next;
    }
};