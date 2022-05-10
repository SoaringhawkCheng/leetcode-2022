//
// Created by 成翔昊 on 2022/5/10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares = genSquares(n);
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(n);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (auto s: squares) {
                    int next = curr - s;
                    if (next == 0) {
                        return level;
                    }

                    if (next < 0) break;
                    if (!visited[next]) {
                        visited[next]=true;
                        q.push(next);
                    }

                }
            }
        }
        return -1;
    }

private:
    vector<int> genSquares(int n) {
        vector<int> squares;
        int square = 1;
        int diff = 3;
        while (square <= n) {
            squares.push_back(square);
            square += diff;
            diff += 2;
        }
        return squares;
    }
};