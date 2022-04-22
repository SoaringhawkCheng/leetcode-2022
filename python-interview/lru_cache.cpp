//
// Created by 成翔昊 on 2022/4/3.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct CacheNode {
    string key;
    int value;
    CacheNode *prev;
    CacheNode *next;
    CacheNode(string _key, int _val) : key(_key), value(_val), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    unordered_map<string, CacheNode *> nodeTable;
    CacheNode *head;
    CacheNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : size(0), capacity(_capacity) {
        head = new CacheNode("", -1);
        tail = new CacheNode("", -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(string key) {
        if (nodeTable.find(key) == nodeTable.end()) {
            return -1;
        }

        CacheNode *node = nodeTable[key];
        removeNode(node);
        addToHead(node);
        return node->value;
    }

    void put(string key, int value) {
        if (nodeTable.find(key) == nodeTable.end()) {
            CacheNode *node = new CacheNode(key, value);
            nodeTable[key] = node;
            addToHead(node);
            ++size;

            if (size > capacity) {
                removeTail();
            }

        } else {
            CacheNode *node = nodeTable[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
        }
    }

    void print() {
        CacheNode *node = head->next;
        while (node != tail) {
            cout << node->key << ":" << node->value << ",";
            node = node->next;
        }
        cout << endl;
    }

private:
    void addToHead(CacheNode *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(CacheNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    CacheNode *removeTail() {
        if (tail->prev == head) {
            return NULL;
        }

        CacheNode *node = tail->prev;
        removeNode(node);
        nodeTable.erase(node->key);
        --size;
        return node;
    }
};

int main() {
    LRUCache cache(3);
    cache.put("a", 1);
    cache.print();
    cache.put("b", 1);
    cache.print();
    cache.put("c", 1);
    cache.print();
    cache.put("d", 1);
    cache.print();
    cache.put("c", 2);
    cache.print();
    cache.put("b", 2);
    cache.print();
    cout << "d=" << cache.get("d") << endl;
    cache.print();
    cout << "c=" << cache.get("c") << endl;
    cache.print();
}