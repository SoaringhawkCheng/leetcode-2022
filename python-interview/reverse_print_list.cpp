//
// Created by 成翔昊 on 2022/3/21.
//

#include "list_node.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
    vector<int> reversePrintListNode(ListNode *head) {
        vector<int> reverseList;
        while(head!=NULL) {
            reverseList.push_back(head->val);
            head=head->next;
        }

        reverse(reverseList.begin(), reverseList.end());
        return reverseList;
    }
};