//
// Created by 成翔昊 on 2022/4/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> subStrMap;
        vector<string> result;
        if (s.size() < 10) {
            return result;
        }

        for (int i = 0; i <= s.size() - 10; i++) {
            string subStr = s.substr(i, 10);
            if (subStrMap.find(subStr) == subStrMap.end()) {
                subStrMap[subStr] = 1;
            } else if (subStrMap[subStr] == 1) {
                result.push_back(subStr);
                subStrMap[subStr]++;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    for (auto subStr: result) {
        cout << subStr << endl;
    }
}