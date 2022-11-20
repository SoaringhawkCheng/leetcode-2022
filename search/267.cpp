//
// Created by 成翔昊 on 2022/11/20.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
private:
    int size;
    char lastChar = '\0';
    unordered_map<char, int> charCntMap;
    vector<string> result;
public:
    vector<string> generatePalindromes(string s) {
        for (auto ch: s) charCntMap[ch]++;

        char midChar = '\0';
        for (auto charCnt: charCntMap) {
            if (charCnt.second % 2) {
                if (midChar != '\0') return result;
                midChar = charCnt.first;
                charCntMap[charCnt.first]--;
            }
        }

        string init = "";
        if (midChar != '\0') init.push_back(midChar);

        size = s.size();
        dfs(init);

        return result;
    }

private:
    void dfs(string path) {
        if (path.size() == size) {
            result.push_back(path);
            return;
        }

        for (auto charCnt: charCntMap) {
            if (charCnt.first == lastChar || charCnt.second == 0) continue;
            charCntMap[charCnt.first] -= 2;
            dfs(charCnt.first + path + charCnt.first);
            charCntMap[charCnt.first] += 2;
        }
    }
};

int main() {
    Solution s;
    for (auto res: s.generatePalindromes("aabb"))
        cout << res << endl;
}