//
// Created by 成翔昊 on 2022/11/20.
//

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> charCntMap;
        for (auto ch: s) charCntMap[ch]++;

        bool existOdd = false;
        for (auto charCnt: charCntMap) {
            if (charCnt.second % 2) {
                if (existOdd) return false;
                existOdd = true;
            }
        }

        return true;
    }
};