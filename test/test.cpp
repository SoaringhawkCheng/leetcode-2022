//
// Created by 成翔昊 on 2022/10/12.
//

# include "../tree/treenode.h"
#include <iostream>
#include <stack>
//#include <unordered_map>
//#include <vector>


using namespace std;


//
//
//                            __
//   ________    _____       ----
// n+1
// 先把n放中间，然后第放置n+1，接着又是把n挪过去
// cnt[n+1] = 2 * cnt[n] + 1
class Solution {
private:
    int total = 0;
    int n;
public:
    int count(int n) {
        if (n<=0) return 0;
        this->n = n;
        realCount(1);
    }

private:
    void realCount(int step) {
        if (step>n) return;
        total += step;
        count(step+1);
    }
};

int main() {

}