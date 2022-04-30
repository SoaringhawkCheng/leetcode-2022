//
// Created by 成翔昊 on 2022/4/28.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> colorMap;
    bool conflict;
public:
    bool isBipartite(vector<vector<int>> &graph) {
        if (graph.size() < 2) {
            return true;
        }

        for (int index = 0; index < graph.size() && !conflict; index++) {
            if (colorMap.find(index) == colorMap.end()) {
                dfs(graph, index, true);
            }
        }

        return !conflict;
    }

    void dfs(const vector<vector<int>> &graph, int index, bool color) {
        if (colorMap.find(index) != colorMap.end()) {
            if (colorMap[index] != color) {
                conflict = true;
            }

            return;
        }

        colorMap[index] = color;
        vector<int> neighbours = graph[index];
        for (auto n: neighbours) {
            dfs(graph, n, !color);
            if (conflict) {
                return;
            }
        }
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