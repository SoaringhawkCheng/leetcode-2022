//
// Created by 成翔昊 on 2022/4/11.
//

#include "tree.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        int depth = 0;
        if (root == NULL) return depth;

        queue<TreeNode *> prevQ, nextQ;
        prevQ.push(root);

        while (!prevQ.empty()) {
            while (!prevQ.empty()) {
                TreeNode *curr = prevQ.front();
                if (curr->left == NULL && curr->right == NULL) return depth + 1;

                if (curr->left!=NULL) {
                    nextQ.push(curr->left);
                }
                if (curr->right!=NULL) {
                    nextQ.push(curr->right);
                }
                prevQ.pop();
            }

            depth = depth + 1;
            queue<TreeNode *> tmp = prevQ;
            prevQ = nextQ;
            nextQ = tmp;
        }

        return depth;
    }
};