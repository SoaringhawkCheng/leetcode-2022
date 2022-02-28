//
// Created by 成翔昊 on 2022/2/20.
//

#include "treenode.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (!stk.empty() || curr != NULL) {
            while (curr != NULL) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            result.push_back(curr->val);
            stk.pop();

            curr = curr->right;
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode *> stk;
        TreeNode *curr = root;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }

            TreeNode *top = stk.top();
            result.push_back(top->val);
            stk.pop();
            curr = curr->right;
        }
    }
};