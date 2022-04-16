//
// Created by 成翔昊 on 2022/4/15.
//

#include "tree.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    TreeNode *pNode, *qNode;
    TreeNode *ancestor;
public:
    // 后序遍历，返回第一个节点
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        pNode = p, qNode = q, ancestor = NULL;
        postTraverse(root);
        return ancestor;
    }

private:
    pair<bool, bool> postTraverse(TreeNode *root) {
        if (root == NULL) {
            return make_pair(false, false);
        }

        pair<bool, bool> leftStatus = postTraverse(root->left);
        pair<bool, bool> rightStatus = postTraverse(root->right);

        pair<bool, bool> result;
        if (leftStatus.first || rightStatus.first || root == pNode) {
            result.first = true;
        }
        if (leftStatus.second || rightStatus.second || root == qNode) {
            result.second = true;
        }

        if (result.first && result.second && ancestor == NULL) {
            ancestor = root;
        }

        return result;
    }
};

int main() {
    vector<int> valList = {3, 5, 1, 6, 2, 0, 8, 7, 4};
    vector<TreeNode> nodeList;
    for (auto val: valList) {
        nodeList.push_back(TreeNode(val));
    }

    nodeList[0].left = &nodeList[1];
    nodeList[0].right = &nodeList[2];
    nodeList[1].left = &nodeList[3];
    nodeList[1].right = &nodeList[4];
    nodeList[2].left = &nodeList[5];
    nodeList[2].right = &nodeList[6];
    nodeList[4].left = &nodeList[7];
    nodeList[4].right = &nodeList[8];

    Solution s;
    cout << s.lowestCommonAncestor(&nodeList[0], &nodeList[3], &nodeList[8])->val << endl;
}