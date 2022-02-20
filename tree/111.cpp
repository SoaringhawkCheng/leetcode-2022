//
// Created by 成翔昊 on 2022/2/20.
//

#include "treenode.h"

class Solution {
public:
//    int minDepth(TreeNode *root) {
//        if (root == NULL) return 0;
//        int leftDepth = minDepth(root->left);
//        int rightDepth = minDepth(root->right);
//        if (leftDepth == 0 || rightDepth == 0) return leftDepth + rightDepth + 1;
//        return min(minDepth(root->left), minDepth(root->right)) + 1;
//    }

    int minDepth(TreeNode *root) {
        int depth = 0;
        if (root==NULL) return depth;

        queue<TreeNode *> prevQ, nextQ;
        prevQ.push(root);

        while (!prevQ.empty()) {
            while (!prevQ.empty()) {
                TreeNode *curr = prevQ.front();
                prevQ.pop();
                if (curr->left == NULL && curr->right == NULL) return depth + 1;
                if (curr->left!=NULL) {
                    nextQ.push(curr->left);
                }
                if (curr->right!=NULL) {
                    nextQ.push(curr->right);
                }
            }

            depth = depth + 1;
            queue<TreeNode *> tmp = prevQ;
            prevQ = nextQ;
            nextQ = tmp;
        }

        return depth;
    }
};