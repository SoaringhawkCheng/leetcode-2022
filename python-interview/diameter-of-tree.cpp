//
// Created by 成翔昊 on 2022/4/12.
//

#include "tree.h"
#include <iostream>

using namespace std;

class Solution {
private:
    int diameter;
public:
    Solution() : diameter(0) {}

    // 一个节点的最大直径，是左右深度组成的路径，与左右子树的直径三者的最大值
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return diameter;
    }

    int dfs(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};