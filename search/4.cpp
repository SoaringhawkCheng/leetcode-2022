//
// Created by 成翔昊 on 2022/10/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    typedef vector<int>::iterator Iter;
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        cout << "haha: " << total % 2 << endl;
        if (total % 2)
            return find_kth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (total + 1) / 2);
        else
            return (find_kth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total / 2) +
                    find_kth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), total / 2 + 1)) / 2.0;
    }

private:
    int find_kth(Iter begin1, Iter end1, Iter begin2, Iter end2, int target) {
        if (end1 - begin1 > end2 - begin2) return find_kth(begin2, end2, begin1, end1, target);
        if (begin1 == end1) return *(begin2 + target - 1);
        if (target == 1) return min(*begin1, *begin2);

        int size1 = min(target / 2, int(end1 - begin1));
        int size2 = target - size1;

        Iter mid1 = begin1 + size1 - 1;
        Iter mid2 = begin2 + size2 - 1;
        if (*mid1 == *mid2) return *mid1;
        if (*mid1 < *mid2) return find_kth(next(mid1), end1, begin2, end2, size2);
        return find_kth(begin1, end1, next(mid2), end2, size1);
    }
};

int main() {
    vector<int> nums1 = {2, 2, 4, 4};
    vector<int> nums2 = {2, 2, 4, 4};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}