//
// Created by 成翔昊 on 2022/4/19.
//

#include <vector>
//#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    typedef vector<int>::iterator Iterator;
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        if (total == 0) {
            return 0.0;
        }

        if (total % 2) {
            return findMedianSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total / 2 + 1);
        } else {
            return (findMedianSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total / 2) +
                    findMedianSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total / 2 + 1)
                   ) / 2.0;
        }
    }

private:
    double findMedianSortedArrays(Iterator begin1, Iterator end1, Iterator begin2, Iterator end2, int target) {
        if (end1 - begin1 > end2 - begin2) return findMedianSortedArrays(begin2, end2, begin1, end1, target);
        if (begin1 >= end1) return *(begin2 + target - 1);
        if (target == 1) return min(*begin1, *begin2);

        int leftNum = min((target) / 2, int(end1 - begin1));
        int rightNum = target - leftNum;

        if (*(begin1 + leftNum - 1) == *(begin2 + rightNum - 1)) {
            return *(begin1 + leftNum - 1);
        } else if (*(begin1 + leftNum - 1) < *(begin2 + rightNum - 1)) {
            return findMedianSortedArrays(begin1 + leftNum, end1, begin2, end2, target - leftNum);
        } else {
            return findMedianSortedArrays(begin1, end1, begin2 + rightNum, end2, target - rightNum);
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}