//
// Created by 成翔昊 on 2022/5/23.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Trie {
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string word) {
        Trie *curr = this;
        for (auto &ch: word) {
            int bucket = ch - 'a';
            curr = curr->children[bucket];
            if (curr == NULL) break;
        }
        return curr;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie *curr = this;
        for (auto &ch: word) {
            int bucket = ch - 'a';
            if (curr->children[bucket] == NULL)
                curr->children[bucket] = new Trie();

            curr = curr->children[bucket];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Trie *leaf = searchPrefix(word);
        return leaf != NULL && leaf->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *leaf = searchPrefix(prefix);
        return leaf != NULL;
    }
};

int main() {
    Trie t;
    t.insert("app");
    t.insert("apple");
    cout << t.search("apps") << endl;
    cout << t.search("app") << endl;
}