//
// Created by 成翔昊 on 2022/7/21.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        // 除去左侧的L和右侧的R，计算中间的非S
        if (directions.empty()) {
            return 0;
        }

        int begin = 0, end = directions.size() - 1;
        while (begin <= end && directions[begin] == 'L') begin++;
        while (begin <= end && directions[end] == 'R' ) end--;

        int cnt = 0;
        for (int i = begin; i <= end; i++)
            if (directions[i]=='R' || directions[i]=='L') cnt++;

        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.countCollisions("R") << endl;
}