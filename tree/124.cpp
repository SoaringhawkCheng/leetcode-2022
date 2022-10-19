//
// Created by 成翔昊 on 2022/10/16.
//

#include "treenode.h"

class Solution {
private:
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode *root) {
        maxRootPath(root);
        return maxSum;
    }

private:
    int maxRootPath(TreeNode *root) {
        if (root == NULL) return 0;

        int left = max(maxRootPath(root->left), 0);
        int right = max(maxRootPath(root->right),0);

        // 以root为中间节点的路径和
        maxSum = max(root->val + left + right, maxSum);

        // 以root为根的最长路径
        int maxRootPath = root->val + max(left, right);
        return maxRootPath;
    }
};