//
// Created by 成翔昊 on 2022/4/28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> parents;
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++) {
            parents.push_back(i);
        }

        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            if (find(edge[0] - 1) == find(edge[1] - 1)) {
                return edge;
            }

            makeUnion(edge[0] - 1, edge[1] - 1);
        }

        return vector<int>();
    }

private:
    int find(int index) {
        if (parents[index] == index) return index;
        return parents[index] = find(parents[index]);
    }

    void makeUnion(int index1, int index2) {
        parents[find(index1)] = find(index2);
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2},
                                 {1, 3},
                                 {2, 3}};
    Solution s;
    auto edge = s.findRedundantConnection(edges);
    for (auto pt: edge) {
        cout << pt << " ";
    }
    cout << endl;
}