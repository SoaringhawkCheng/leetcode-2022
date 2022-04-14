//
// Created by 成翔昊 on 2022/4/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string s1, string s2) {
        if (s1.empty() || s2.empty()) {
            return "0";
        }

        int size1 = s1.size();
        int size2 = s2.size();
        vector<int> resultList(size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; i--) {
            int num1 = s1[i] - '0';
            for (int j = size2 - 1; j >= 0; j--) {
                int index = size1 + size2 - i - j - 2;
                int num2 = s2[j] - '0';
                int sum = resultList[index] + num1 * num2;
                resultList[index] = sum % 10;
                resultList[index + 1] += sum / 10;
            }
        }

        string result;
        int index = resultList.size() - 1;
        while (index > 0 && resultList[index] == 0) index--;
        while (index >= 0) {
            result.push_back('0' + resultList[index]);
            index--;
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << s.multiply("123", "45") << endl;
}