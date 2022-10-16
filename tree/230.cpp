//
// Created by 成翔昊 on 2022/2/27.
//

#include "treenode.h"

class Solution {
private:
    unordered_map<TreeNode *, int> nodeNum;

public:
    int kthSmallest(TreeNode *root, int k) {
        countNodeNum(root);
        while (root != NULL) {
            int diff = nodeNum[root->left] + 1 - k;
            if (diff == 0) return root->val;
            else if (diff < 0) {
                root = root->right;
                k = -diff;
            } else
                root = root->left;
        }

        return -1;
    }

private:
    int countNodeNum(TreeNode *node) {
        if (node == NULL) return 0;
        nodeNum[node] = 1 + countNodeNum(node->left) + countNodeNum(node->right);
        return nodeNum[node];
    }
};

int main() {
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);
    TreeNode node4 = TreeNode(4);

//    node3.left = &node1;
//    node1.right = &node2;
//    node3.right = &node4;

    node1.right = &node2;

    Solution s;
    cout << s.kthSmallest(&node1, 2) << endl;
}