//
// Created by 成翔昊 on 2022/4/16.
//

#include "tree.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> q;
        vector<double> result;

        if (root == NULL) {
            return result;
        }

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            double avg = 0.0;
            for (int i = 0; i < size; i++) {
                TreeNode *front = q.front();
                avg += front->val;
                if (front->left != NULL) q.push(front->left);
                if (front->right != NULL) q.push(front->right);
                q.pop();
            }

            if (size>0) {
                avg/=size;
                result.push_back(avg);
            }
        }

        return result;
    }
};