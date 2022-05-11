//
// Created by 成翔昊 on 2022/5/10.
//

#include <vector>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> visited;
    int total, size;
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || n < k) return result;
        visited = vector<bool>(n + 1, false);
        total = n, size = k;
        dfs(1);
        return result;
    }

private:
    void dfs(int index) {
        if (path.size() == size) {
            result.push_back(path);
            return;
        }

        for (int i = index; i <= total; i++) {
            if (visited[i]) continue;
            path.push_back(i);
            visited[i] = true;
            dfs(i + 1);
            visited[i] = false;
            path.pop_back();
        }
    }
};