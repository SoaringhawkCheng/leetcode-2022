//
// Created by 成翔昊 on 2022/10/19.
//

#include <unordered_map>
#include <string>
#include <mutex>

using namespace std;

mutex mtx;

struct BlockNode {
    int val;
    string hash;
    string prevHash;
    int index;
    int state;
    unordered_map<string, string> payload;

    BlockNode() : val(0) {}

    BlockNode(int val, string) : val(val) {}

    BlockNode(int val, BlockNode *next) : val(val) {}
};

class BlockCache {
    unordered_map<string, string> keyValue;
};

class BlockChain {
private:
    BlockNode *root;
    unordered_map<string, BlockNode *> nodeMap;
    int capacity = 6;
    int state; //

public:
    BlockChain(BlockNode *root) {
        this->root = root;
        this->root->index = 1;
        this->nodeMap = unordered_map<string, BlockNode *>();
        this->nodeMap[root->hash] = root;
    }

    bool joinChain(BlockNode *node) {
        BlockNode *father = getFatherNode(node);
        if (father->index == capacity - 1) {
            if (mtx.try_lock()) {
                // 链路state置位
                //
                //
            }

        }
    }

private:
    BlockNode *getFatherNode(BlockNode *node) {
        // TODO: 基于某种随机算法或业务规则，不知道如何实现，返回root示意
        return root;
    }
};