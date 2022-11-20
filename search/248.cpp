//
// Created by 成翔昊 on 2022/11/20.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<char, char> charPairMap = {
            {'0', '0'}, {'1', '1'}, {'8', '8'},
            {'6', '9'}, {'9', '6'}
    };
    vector<string> initialList = {"", "0", "1", "8"};
public:
    int strobogrammaticInRange(string low, string high) {
        queue<string> q;
        for (auto init: initialList) q.push(init);

        int total = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string str = q.front();
                q.pop();
                if (!compare(str, high)) continue;
                else if (compare(low, str) && (str.size() == 1 || str[0] != '0')) total++;

                for (auto pair: charPairMap) {
                    q.push(pair.first + str + pair.second);
                }
            }
        }
        return total;
    }

private:
    bool compare(string lhs, string rhs) { // <=
        if (lhs.size() == rhs.size()) return lhs <= rhs;
        else return lhs.size() < rhs.size();
    }
};

int main() {
    Solution s;
    cout << s.strobogrammaticInRange("0", "0") << endl;
}