//
// Created by 成翔昊 on 2022/10/12.
//

#include "../linked-list/list_node.h"
#include <iostream>
//#include <stack>
//#include <unordered_map>
#include <vector>
#include <queue>
#include "../tree/treenode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelTraverse(TreeNode *root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                level.push_back(curr->val);
                q.pop();
            }
            result.push_back(level);
        }

        return result;
    }
};

int main() {
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node1 = TreeNode(1);
    TreeNode node1 = TreeNode(1);
}