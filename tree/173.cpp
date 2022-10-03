//
// Created by 成翔昊 on 2022/10/3.
//

#include "treenode.h"

using namespace std;

class BSTIterator {
private:
    stack<TreeNode *> stk;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        if (!hasNext()) return -1;
        TreeNode *curr = stk.top();
        stk.pop();
        int res = curr->val;
        curr = curr->right;
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        return res;
    }

    bool hasNext() {
        return !stk.empty();
    }
};