//
// Created by 成翔昊 on 2022/10/26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> primeList;
//    int index = 0;
//    int curr = 1;
public:
    string calcFactorialSum(int upper) {
        genPrimeList(upper);
        for (auto prime: primeList) cout << prime << ",";
        cout << endl;
        return calcFactorialSum(1, 0);
    }

private:
    string calcFactorialSum(int curr, int index) {
        if (index >= primeList.size()) return "0";

        string result = "1";
        while (curr <= primeList[index]) {
            result = multiply(result, to_string(curr));
            curr++;
        }

        return multiply(result, sum("1", calcFactorialSum(curr, index + 1)));
    }


    void genPrimeList(int upper) {

        vector<bool> isPrime(upper + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= upper; i++) {

            if (!isPrime[i]) continue;
            primeList.push_back(i);

            if (i * i > upper) continue;
            for (int j = i * i; j <= upper; j += i) isPrime[j] = false;
        }
    }

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
    cout << s.calcFactorialSum(100) << endl;
}