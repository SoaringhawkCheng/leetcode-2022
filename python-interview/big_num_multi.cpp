//
// Created by 成翔昊 on 2022/4/3.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string bigNumberMultiply(string lhs, string rhs) {
        if (lhs.empty() || rhs.empty() || !lhs.compare("0") || !rhs.compare("0")) {
            return "0";
        }

        vector<int> resList(lhs.size() + rhs.size() + 1, 0);

        int lsize = lhs.size();
        int rsize = rhs.size();
        for (int i = lsize - 1; i >= 0; i--) {
            int lnum = lhs[i] - '0';
            for (int j = rsize - 1; j >= 0; j--) {
                int rnum = rhs[j] - '0';
                int pos = (lsize - 1 - i) + (rsize - 1 - j);
                int sum = resList[pos] + lnum * rnum;
                resList[pos] = sum % 10;
                resList[pos + 1] += sum / 10;
            }
        }

        int index = resList.size() - 1;
        while (index > 0 && resList[index] == 0) index--;

        string resStr;
        for (; index >= 0; index--) {
            resStr.push_back('0' + resList[index]);
        }

        return resStr;
    }
};

int main() {
    Solution s;
    cout << s.bigNumberMultiply("123", "456") << endl;
    return 0;
}