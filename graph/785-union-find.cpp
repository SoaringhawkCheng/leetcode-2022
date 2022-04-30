//
// Created by 成翔昊 on 2022/4/28.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include "union_find.h"

using namespace std;

class Solution {
private:
    unordered_map<int, bool> colorMap;
    bool conflict;
public:
    bool isBipartite(vector<vector<int>> &graph) {
        UnionFind uf = UnionFind(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            vector<int> neighbours = graph[i];
            if (neighbours.empty()) continue;

            for (auto n:neighbours) {
                if (uf.isConnected(i,n)) {
                    return false;
                }

                uf.makeUnion(neighbours[0], n);
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{4},
                                 {},
                                 {4},
                                 {4},
                                 {0, 2, 3}};

    cout << s.isBipartite(graph) << endl;
}