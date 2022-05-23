//
// Created by 成翔昊 on 2022/3/22.
//

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int calc(string s) {
        if (s.empty()) return 0;
        s.push_back('+');
        int result = 0, prev = 0, index = 0, status = 1;
        while (index != s.size()) {
            if (s[index] == '-') {
                int num = stoi(s.substr(prev, index - prev));
                result = result + status * num;
                status = -1;
                prev = (++index);
            } else if (s[index] == '+') {
                int num = stoi(s.substr(prev, index - prev));
                result = result + status * num;
                status = 1;
                prev = (++index);
            } else index++;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.calc("20+10-5") << endl;
}

//int main() {
//    Solution s;
//    cout << s.multiple("12345678", "456789") << endl;
//}