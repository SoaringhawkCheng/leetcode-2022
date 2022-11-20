//
// Created by 成翔昊 on 2022/11/19.
//

#include <vector>

using namespace std;

class Solution {
    typedef vector<char>::iterator Iter;
public:
    void reverseWords(vector<char> &s) {
        if (s.empty()) return;

        reverseRange(s.begin(), s.end());
        s.push_back(' ');

        Iter lastIndex = s.begin();
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            if (*iter != ' ') continue;

            reverseRange(lastIndex, iter);
            lastIndex = next(iter);
        }
        s.pop_back();
        return;
    }

private:
    void reverseRange(Iter begin, Iter end) {
        while (begin < end) {
            iter_swap(begin, prev(end));
            begin++, end--;
        }
    }
};