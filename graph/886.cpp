//
// Created by 成翔昊 on 2022/10/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> dislikeMap;
    vector<int> parent;
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        for (auto dislike: dislikes) {
            dislikeMap[dislike[0] - 1].push_back(dislike[1] - 1);
            dislikeMap[dislike[1] - 1].push_back(dislike[0] - 1);
        }

        for (int i = 0; i < n; i++) parent.push_back(i);

        for (int i = 0; i < n; i++) {
            for (int j: dislikeMap[i]) {
                parent[find(j)] = find(dislikeMap[i][0]);
                if (find(i) == find(j)) return false;
            }
        }

        return true;
    }

private:
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
};

int main() {
    int n = 4;
    vector<vector<int>> dislikes = {{1, 2},
                                    {1, 3},
                                    {2, 4}};
    Solution s;
    cout << s.possibleBipartition(n, dislikes) << endl;
}