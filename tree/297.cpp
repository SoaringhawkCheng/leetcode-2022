//
// Created by 成翔昊 on 2022/7/7.
//

#include "treenode.h"


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string str = "";
        serialize(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        queue<string> nodes;
        string substr;
        for (auto &ch: data) {
            if (ch == ',') {
                nodes.push(substr);
                substr.clear();
            } else {
                substr.push_back(ch);
            }
        }
        if (!substr.empty()) {
            nodes.push(substr);
            substr.clear();
        }
        return deserialize(nodes);
    }

private:
    void serialize(TreeNode *root, string &str) {
        if (root == NULL) {
            str += "None,";
            return;
        }

        str += to_string(root->val) + ",";
        serialize(root->left, str);
        serialize(root->right, str);
    }

    TreeNode *deserialize(queue<string> &nodes) {
        if (nodes.front() == "None") {
            nodes.pop();
            return NULL;
        }

        TreeNode *root = new TreeNode(stoi(nodes.front()));
        nodes.pop();

        root->left = deserialize(nodes);
        root->right = deserialize(nodes);
        return root;
    }
};