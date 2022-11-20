//
// Created by 成翔昊 on 2022/11/19.
//

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, char> charMap = {
            {'0', '0'},
            {'1', '1'},
            {'8', '8'},
            {'6', '9'},
            {'9', '6'},
    };
public:
    bool isStrobogrammatic(string num) {
        for (auto left = num.begin(), right = prev(num.end()); left <= right; left++, right--) {

            if (charMap[*left] != *right) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isStrobogrammatic("69") << endl;
}