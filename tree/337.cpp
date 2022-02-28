//
// Created by 成翔昊 on 2022/2/27.
//

#include "treenode.h"

struct TreeNodeStatus {
    int selected;
    int notSelected;
};

class Solution {
public:
    int rob(TreeNode *root) {
        auto status = dfs(root);
        return max(status.selected, status.notSelected);
    }

private:
    TreeNodeStatus dfs(TreeNode *node) {
        if (!node) {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }
};