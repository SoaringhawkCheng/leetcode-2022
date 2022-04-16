//
// Created by 成翔昊 on 2022/4/16.
//

#include "tree.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> result;

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i=0;i<size;i++) {
                TreeNode *front = q.front();
                q.pop();
                if (front==NULL) continue;
                level.push_back(front->val);
                q.push(front->left);
                q.push(front->right);
            }

            if (!level.empty()) {
                result.push_back(level);
            }
        }

        return result;
    }
};