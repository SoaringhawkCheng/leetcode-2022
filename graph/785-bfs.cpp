//
// Created by 成翔昊 on 2022/4/28.
//

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> colorMap;
    queue<int> level;
    bool conflict;
public:
    bool isBipartite(vector<vector<int>> &graph) {
        if (graph.size() < 2) {
            return true;
        }

        for (int index = 0; index < graph.size() && !conflict; index++) {
            if (colorMap.find(index) == colorMap.end()) {
                bfs(graph, index, true);
            }
        }

        return !conflict;
    }

    void bfs(const vector<vector<int>> &graph, int index, bool color) {
        level.push(index);
        while (!level.empty()) {
            int size = level.size();
            for (int i = 0; i < size; i++) {
                int front = level.front();
                level.pop();
                if (colorMap.find(front) != colorMap.end()) {
                    if (colorMap[front] != color) {
                        conflict = true;
                        return;
                    }
                    continue;
                }

                colorMap[front] = color;
                vector<int> neighbours = graph[front];
                for (auto n: neighbours) {
                    if (colorMap.find(n) == colorMap.end()) {
                        level.push(n);
                    }
                }
            }
            color = !color;
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