//
// Created by 成翔昊 on 2022/2/20.
//

#include "treenode.h"

class Solution {
public:
    int maxPath = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxPath;
    }

    int maxDepth(TreeNode* node) {
        if (node==NULL) return 0;
        int l = maxDepth(node->left);
        int r = maxDepth(node->right);
        maxPath = max(maxPath, l+r);
        return max(l,r) + 1;
    }
};