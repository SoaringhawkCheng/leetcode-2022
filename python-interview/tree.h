//
// Created by 成翔昊 on 2022/4/11.
//

#ifndef LEETCODE_2022_TREE_H
#define LEETCODE_2022_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //LEETCODE_2022_TREE_H
