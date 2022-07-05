//
// Created by 成翔昊 on 2022/6/30.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int row;
    int col;
    int val;

    bool operator<(const Node &lhs) const {
        return val > lhs.val;
    }

    Node() {}

    Node(int _row, int _col, int _val) : row(_row), col(_col), val(_val) {}
};

class Solution {
private:
    int row, col;
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        priority_queue<Node> heap;

        if (k <= 0 || matrix.empty() || matrix[0].empty()) return -1;

        row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            Node curr(i, 0, matrix[i][0]);
            heap.push(curr);
        }

        Node result;
        for (int i = 0; i < k; i++) {
            result = heap.top();
            heap.pop();
            if (result.col + 1 >= col) continue;

            Node next = Node(result.row, result.col + 1, matrix[result.row][result.col + 1]);
            heap.push(next);
        }

        return result.val;
    }
};

int main() {
    Solution s;
//    vector<vector<int>> matrix = {{1,  5,  9},
//                                  {10, 11, 13},
//                                  {12, 13, 15}};
    vector<vector<int>> matrix = {{-5}};
    cout << s.kthSmallest(matrix, 1) << endl;
}