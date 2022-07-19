//
// Created by 成翔昊 on 2022/7/5.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int begin, end;

    Node(int begin, int end) : begin(begin), end(end) {}

    bool operator<(const Node &rhs) const { // priority_queue默认大顶堆
        return end > rhs.end;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int maxSize = 0;
        priority_queue<Node> q;

        for (int i = 0; i < intervals.size(); i++) {
            Node node(intervals[i][0], intervals[i][1]);

            while (!q.empty() && q.top().end <= node.begin) q.pop();
            q.push(node);
            maxSize = max(maxSize, (int) q.size());
        }

        return maxSize;
    }

private:
    static bool compare(vector<int> &lhs, vector<int> &rhs) {
        return lhs[0] < rhs[0];
    }
};

int main() {
    vector<vector<int>> intervals = {{0,  30},
                                     {5,  10},
                                     {15, 20}};
    Solution s;
    cout << s.minMeetingRooms(intervals) << endl;
}