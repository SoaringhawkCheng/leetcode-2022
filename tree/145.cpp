//
// Created by 成翔昊 on 2022/2/20.
//

#include "treenode.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();
            if (curr==NULL) continue;
            result.push_back(curr->val);
            stk.push(curr->left);
            stk.push(curr->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};