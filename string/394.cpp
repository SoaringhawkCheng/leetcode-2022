//
// Created by 成翔昊 on 2022/7/18.
//

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return parseString(s, index);
    }

private:
    string parseString(string s, int &index, int time = 1) {
        string result = "";

        if (index >= s.size() || s[index] == ']') {
            index++;
        } else if (isdigit(s[index])) {
            string digit = parseDigit(s, index);
            result += parseString(s, index, stoi(digit));
        } else if (isalpha(s[index])) {
            result += s[index++];
            result += parseString(s, index, time);
        } else if (s[index] == '[') {
            index++;
            string subStr = parseString(s, index, time);
            while (time--) result += subStr;
            result += parseString(s, index);
        }

        return result;
    }

    string parseDigit(string s, int &index) {
        string digit;
        while (index < s.size() && isdigit(s[index])) digit += s[index++];
        return digit;
    }
};

int main() {
    Solution s;

//    vector<pair<string, string>> cases = {{"3[a]2[bc]",     "aaabcbc"},
//                                          {"3[a2[c]]aa",    "accaccaccaa"},
//                                          {"2[abc]3[cd]ef", "abcabccdcdcdef"},
//                                          {"abc3[cd]xyz",   "abccdcdcdxyz"},
//                                          {"10[a]",         "aaaaaaaaaa"}};
//    for (auto c: cases) {
//        cout << (s.decodeString(c.first) == c.second) << " ";
//    }
//    cout << endl;

    string str = "3[a2[c]]aa";
    cout << s.decodeString(str) << endl;
}