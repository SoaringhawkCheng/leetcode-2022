//
// Created by 成翔昊 on 2022/10/13.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ssize = s.size(), tsize = t.size();
        if (abs(ssize - tsize) > 1) return false;
        if (ssize > tsize) return isOneEditDistance(t, s);
        for (int i = 0; i < ssize; i++) {
            if (s[i] != t[i]) {
                if (ssize == tsize) return s.substr(i + 1) == t.substr(i + 1);
                else return s.substr(i) == t.substr(i + 1);
            }
        }
        return ssize + 1 == tsize;
    }
};