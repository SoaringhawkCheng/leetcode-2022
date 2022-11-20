//
// Created by 成翔昊 on 2022/11/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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
    unordered_set<char> charSet = {'0', '1', '8', '6', '9'};
    unordered_set<char> midCharSet = {'0', '1', '8'};

    int step;
    int size;
    bool isOdd;
    string path;
    vector<string> result;

public:
    vector<string> findStrobogrammatic(int n) {
        if (n <= 0) return result;

        isOdd = n % 2, size = n / 2;
        dfs();
        return result;
    }

private:
    void dfs() {
        if (step == 1 && path == "0") return;

        if (step == size) {
            genFullPath();
            return;
        }
        for (auto iter = charMap.begin(); iter != charMap.end(); iter++) {
            path.push_back(iter->first);
            step++;
            dfs();
            step--;
            path.pop_back();
        }
    }

    void genFullPath() {
        string reversePath;
        for (int i = 0; i < path.size(); i++) {
            reversePath.push_back(charMap[path[i]]);
        }
        reverse(reversePath.begin(), reversePath.end());

        if (!isOdd) {
            result.push_back(path + reversePath);
            return;
        }

        for (auto midChar: midCharSet) {
            result.push_back(path + midChar + reversePath);
        }
    }
};