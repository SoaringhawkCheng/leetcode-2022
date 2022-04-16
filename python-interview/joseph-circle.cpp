//
// Created by 成翔昊 on 2022/4/13.
//

#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        if (m <= 0 || n <= 1) {
            return -1;
        }

        deque<int> queue;
        for (int i = 0; i < n; i++) {
            queue.push_back(i);
        }

        while (queue.size() > 1) {
            for (int count = 0; count < m - 1; count++) {
                int num = queue.front();
                queue.pop_front();
                queue.push_back(num);
            }
            queue.pop_front();
        }

        return queue.front();
    }
};

int main() {
    Solution s;
    cout << s.lastRemaining(5, 3) << endl;
    cout << s.lastRemaining(10, 17) << endl;
}