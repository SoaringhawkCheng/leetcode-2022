//
// Created by 成翔昊 on 2022/5/10.
//

#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        wordList.push_back(beginWord);
        unordered_map<int, vector<int>> graph;
        buildGraph(wordList, graph);

        queue<int> q;
        q.push(wordList.size() - 1);
        vector<bool> visited(wordList.size(), false);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                visited[curr] = true;

                if (wordList[curr] == endWord) return level;

                for (auto next: graph[curr]) {
                    if (!visited[next]) {
                        q.push(next);
                    }
                }
            }

        }

        return 0;
    }

private:
    void buildGraph(vector<string> &wordList, unordered_map<int, vector<int>> &graph) {
        int size = wordList.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (isConnect(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }

    bool isConnect(string lhs, string rhs) {
        if (lhs.size() != rhs.size()) return false;
        int count = 0;
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) count++;
            if (count > 1) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;
}