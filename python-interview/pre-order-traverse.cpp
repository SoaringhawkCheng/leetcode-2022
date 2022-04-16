//
// Created by 成翔昊 on 2022/4/16.
//

#include "tree.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;

        stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            if (top==NULL) continue;

            result.push_back(top->val);
            stk.push(top->right);
            stk.push(top->left);
        }

        return result;
    }
};