//
// Created by 成翔昊 on 2022/9/28.
//

#include "treenode.h"

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (root == NULL) return root;
        return reverse(root);
    }

private:
    TreeNode *reverse(TreeNode *curr) {
        if (curr->left == NULL) return curr;

        TreeNode *newRoot = reverse(curr->left);

        curr->left->left = curr->right;
        curr->left->right = curr;
        curr->left = curr->right = NULL;
        return newRoot;
    }
};