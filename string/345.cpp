//
// Created by 成翔昊 on 2022/5/2.
//

#include <iostream>

using namespace std;

class Solution {
private:
    string alpha = "aeiouAEIOU";
public:
    string reverseVowels(string s) {
        auto begin = s.begin(), end = prev(s.end());
        while (begin < end) {
            while (alpha.find(*begin) == string::npos && begin < s.end()) {
                begin++;
            }
            while (alpha.find(*end) == string::npos && end > s.begin()) {
                end--;
            }
            if (begin < end) {
                iter_swap(begin, end);
                begin++;
                end--;
            }
        }
        return s;
    }
};