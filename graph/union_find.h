//
// Created by 成翔昊 on 2022/4/28.
//

#ifndef LEETCODE_2022_UNION_FIND_H
#define LEETCODE_2022_UNION_FIND_H

#include<vector>

using namespace std;

class UnionFind {
private:
    vector<int> roots;
public:
    UnionFind(int size) {
        for (int i = 0; i < size; i++) roots.push_back(i);
    }

    int find(int index) {
        if (roots[index] == index) {
            return index;
        }
        return roots[index] = find(roots[index]);
    }

    bool isConnected(int lhs, int rhs) {
        return find(lhs) == find(rhs);
    }

    void makeUnion(int lhs, int rhs) {
        roots[find(rhs)] = find(lhs);
    }
};

#endif //LEETCODE_2022_UNION_FIND_H
