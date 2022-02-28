//
// Created by 成翔昊 on 2022/2/27.
//

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    int result;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val = 0) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        dfs(root);
        return maxPath;
    }

private:
    int maxPath = 0;

    int dfs(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = root->left != NULL && root->val == root->left->val ? left + 1 : 0;
        int rightPath = root->right != NULL && root->val == root->right->val ? right + 1 : 0;

        maxPath = max(maxPath, leftPath + rightPath);
        int path = max(leftPath, rightPath);
        root->result = path;
        return path;
    }
};

//int main() {
//    //          1
//    //      4       5
//    //    4   4       5
//    vector<int> nums = {1, 4, 5, 4, 4, 5};
//    vector<TreeNode> nodes;
//    for (auto num: nums) {
//        nodes.push_back(TreeNode(num));
//    }
//    nodes[0].left=&nodes[1];
//    nodes[0].right=&nodes[2];
//    nodes[1].left=&nodes[3];
//    nodes[1].right=&nodes[4];
//    nodes[2].right=&nodes[5];
//
//    Solution s;
//    cout << s.longestUnivaluePath(&nodes[0]);
//    cout << endl;
//}

