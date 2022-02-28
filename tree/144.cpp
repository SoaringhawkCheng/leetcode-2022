//
// Created by 成翔昊 on 2022/2/20.
//

#include "treenode.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();

            if (curr==NULL){
                continue;
            }

            result.push_back(curr->val);
            stk.push(curr->right);
            stk.push(curr->left);
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root==NULL) {
            return result;
        }

        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *top = stk.top();
            result.push_back(top->val);
            stk.pop();
            if (top->right) stk.push(top->right);
            if (top->left) stk.push(top->left);
        }

        return result;
    }
};

//int main() {
//    TreeNode node1(1);
//    TreeNode node2(2);
//    TreeNode node3(3);
//    TreeNode node4(4);
//    node1.left = &node4;
//    node4.left = &node3;
//    node4.right = &node2;
//    Solution2 s;
//    for (auto num: s.preorderTraversal(&node1))
//        cout << num << " ";
//    cout << endl;
//}