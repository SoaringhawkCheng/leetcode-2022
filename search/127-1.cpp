//
// Created by 成翔昊 on 2022/5/10.
//

#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        queue<string> q;
        q.push(beginWord);

        unordered_map<string, bool> visited;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) return level;

                for (auto word: wordList) {
                    if (visited.find(word) == visited.end() && isNeighbour(curr, word)) {
                        q.push(word);
                        visited[word] = true;
                    }
                }
            }

        }

        return 0;
    }

private:
    bool isNeighbour(string lhs, string rhs) {
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

}