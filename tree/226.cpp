//
// Created by 成翔昊 on 2022/7/4.
//

#include "treenode.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) return root;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);

        return root;
    }
};