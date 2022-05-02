//
// Created by 成翔昊 on 2022/5/2.
//

#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        for (auto begin = s.begin(), end = prev(s.end()); begin < end; begin++, end--) {
            if (*begin != *end) {
                return isPalindrome(begin, prev(end)) || isPalindrome(next(begin), end);
            }
        }
        return true;
    }

private:
    bool isPalindrome(string::iterator begin, string::iterator end) {
        while (begin < end) {
            if (*begin != *end) {
                return false;
            }
            begin++, end--;
        }
        return true;
    }
};