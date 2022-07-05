//
// Created by 成翔昊 on 2022/5/23.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children;
    int sum;

    TrieNode() : children(26), sum(0) {}
};

class MapSum {
private:
    TrieNode *root;
    unordered_map<string, int> valMap;
public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        int addition = val;
        if (valMap.count(key)) {
            addition -= valMap[key];
        }
        valMap[key] = val;

        TrieNode *curr = root;
        for (auto &ch: key) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
            curr->sum += addition;
        }
    }

    int sum(string prefix) {
        TrieNode *curr = root;
        for (auto &ch: prefix) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) return 0;
            curr = curr->children[index];
        }

        return curr->sum;
    }
};

int main() {
    MapSum mapSum;
    mapSum.insert("apple", 3);
    cout << mapSum.sum("ap") << endl;
    mapSum.insert("app", 2);
    cout << mapSum.sum("ap") << endl;
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */