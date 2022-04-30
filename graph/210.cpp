//
// Created by 成翔昊 on 2022/4/28.
//

#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<int> indegrees;
    vector<vector<int>> edges;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indegrees = vector<int>(numCourses, 0);
        edges = vector<vector<int>>(numCourses, vector<int>());

        queue<int> q;
        for (auto row: prerequisites) {
            indegrees[row[0]]++;
            edges[row[1]].push_back(row[0]);
        }

        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        int total = 0;
        while (!q.empty()) {
            int course = q.front();
            result.push_back(course);
            q.pop();
            total++;
            for (auto child: edges[course]) {
                indegrees[child]--;
                if (indegrees[child] == 0) q.push(child);
            }
        }

        return (total == numCourses)?result: vector<int>();
    }
};