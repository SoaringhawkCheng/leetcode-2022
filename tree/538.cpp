//
// Created by 成翔昊 on 2022/2/27.
//

#include "treenode.h"

class Solution {
public:
    TreeNode *convertBST(TreeNode *root) {
        travel(root);
        return root;
    }

private:
    int sum = 0;

    void travel(TreeNode *node) {
        if (!node) return;
        travel(node->right);
        sum += node->val;
        node->val = sum;
        travel(node->left);
    }
};