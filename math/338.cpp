//
// Created by 成翔昊 on 2022/7/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        int prevBits = 1, len = 1;
        vector<int> res;

        for (int i = 0; i <= n; i++) {
            if (i % 2) ++prevBits, ++len;
            else prevBits = len - prevBits;
            res.push_back(prevBits);
        }

        return res;
    }
};

int main() {
    Solution s;
    s.countBits(2);
}