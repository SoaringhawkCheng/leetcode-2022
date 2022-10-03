//
// Created by 成翔昊 on 2022/10/3.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int>> wordMap;
public:
    WordDistance(vector<string> &wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++)
            wordMap[wordsDict[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int minDis = INT_MAX;
        int index1 = 0, index2 = 0;
        vector<int> wordIdxList1 = wordMap[word1];
        vector<int> wordIdxList2 = wordMap[word2];
        while (index1 < wordIdxList1.size() && index2 < wordIdxList2.size()) {
            if (wordIdxList1[index1] < wordIdxList2[index2]) {
                minDis = min(minDis, wordIdxList2[index2] - wordIdxList1[index1]);
                index1++;
            } else if (wordIdxList1[index1] > wordIdxList2[index2]){
                minDis = min(minDis, wordIdxList1[index1] - wordIdxList2[index2]);
                index2++;
            } else return 0;
        }
        return minDis;
    }
};

int main() {
    vector<string> wordsDict = {"practice","makes","perfect","coding","makes"};
    WordDistance *wd = new WordDistance(wordsDict);
    cout << wd->shortest("coding", "practice") << endl;
    cout << wd->shortest("makes", "coding") << endl;
}