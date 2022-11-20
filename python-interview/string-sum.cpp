//
// Created by 成翔昊 on 2022/4/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string sum(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        int i = size1 - 1, j = size2 - 1, carryBit = 0;
        string result;

        while (i >= 0 || j >= 0 || carryBit) {
            int value1 = i >= 0 ? s1[i] - '0' : 0;
            int value2 = j >= 0 ? s2[j] - '0' : 0;

            int sumNum = value1 + value2 + carryBit;
            carryBit = sumNum / 10;

            result.push_back('0' + sumNum % 10);
            i--, j--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    cout << "haha" << endl;
    cout << "haha" << endl;
    Solution s;
    cout << s.sum("123", "45") << endl;
}