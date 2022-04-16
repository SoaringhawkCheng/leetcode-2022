//
// Created by 成翔昊 on 2022/4/16.
//

#include "tree.h"
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (!stk.empty() || curr != NULL) {
            while (curr != NULL) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};