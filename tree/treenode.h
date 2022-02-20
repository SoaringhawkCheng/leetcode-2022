//
// Created by 成翔昊 on 2022/2/20.
//

#ifndef LEETCODE_2022_TREENODE_H
#define LEETCODE_2022_TREENODE_H

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_2022_TREENODE_H
