//
// Created by 成翔昊 on 2022/5/10.
//

#include <string>
#include "../tree/treenode.h"

class Solution {
    vector<int> path;
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == NULL) return result;
        dfs(root);
        return result;
    }

private:
    void dfs(TreeNode *curr) {
        path.push_back(curr->val);

        if (isLeaf(curr)) {
            string pathStr = buildPathStr();
            if (!pathStr.empty()) result.push_back(pathStr);
        }

        if (curr->left != NULL) {
            dfs(curr->left);
        }
        if (curr->right != NULL) {
            dfs(curr->right);
        }

        path.pop_back();
    }

    bool isLeaf(TreeNode *pNode) {
        return pNode->left == NULL && pNode->right == NULL;
    }

    string buildPathStr() {
        string pathStr;
        for (int i = 0; i < path.size(); i++) {
            pathStr.append(to_string(path[i]));
            if (i < path.size() - 1) pathStr.append("->");
        }
        return pathStr;
    }
};