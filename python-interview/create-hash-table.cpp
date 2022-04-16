//
// Created by 成翔昊 on 2022/4/16.
//

#include <vector>
#include <list>
#include <iostream>

using namespace std;

class MyHashMap {
private:
    vector<list<pair<int, int>>> table;
    int bucketSize;
public:
    MyHashMap(int _bucketSize) {
        bucketSize = _bucketSize;
        table = vector<list<pair<int, int>>>(bucketSize, list<pair<int, int>>());
    }

    void put(int key, int value) {
        int hash = key % bucketSize;
        list<pair<int, int>> &bucketList = table[hash];
        for (auto iter = bucketList.begin(); iter != bucketList.end(); iter++) {
            if (iter->first==key) {
                iter->second=value;
                return;
            }
        }
        bucketList.push_back(make_pair(key, value));
    }

    int get(int key) {
        int hash = key % bucketSize;
        list<pair<int, int>> &bucketList = table[hash];
        for (auto iter = bucketList.begin(); iter != bucketList.end(); iter++) {
            if (iter->first==key) {
                return iter->second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int hash = key % bucketSize;
        list<pair<int, int>> &bucketList = table[hash];
        for (auto iter = bucketList.begin(); iter != bucketList.end(); iter++) {
            if (iter->first==key) {
                bucketList.erase(iter);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */