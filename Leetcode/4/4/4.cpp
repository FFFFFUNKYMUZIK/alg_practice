#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0

//accepted but too complex
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) {
            int tmp = m;
            m = n;
            n = tmp;

            vector<int> vtmp = nums1;
            nums1 = nums2;
            nums2 = vtmp;

        }

        if (n == 0) {
            nums2 = nums1;
            n = m;
        }
        int l, r;
        int half = (m + n + 1) / 2;
        bool odd = (m + n) % 2;

        int s = 0, e = m;
        int mid1;
        int mid2;
        double ret;
        bool find = false;

        while (s<=e) {
            mid1 = (s + e) / 2;
            mid2 = half - mid1;

            if (mid2 <= 0) {
                if (mid2 == 0 && nums1[mid1 - 1] <= nums2[0]) {
                    find = true;
                    if (mid1 == m) {
                        if (odd) {
                            ret = nums1[mid1 - 1];
                        }
                        else {
                            ret = (nums1[mid1 - 1] + nums2[0]) / 2.0;
                        }
                    }
                    else {
                        if (odd) {
                            ret = nums1[mid1 - 1];
                        }
                        else {
                            ret = (nums1[mid1 - 1] + min(nums1[mid1], nums2[0])) / 2.0;
                        }
                    }
                    break;
                }
                e = mid1 - 1;
                continue;
            }
            if (mid2 >= n) {
                if (mid2 == n && nums2[n - 1] <= nums1[mid1]) {
                    find = true;
                    if (mid1 == 0) {
                        if (odd) {
                            ret = nums2[n - 1];
                        }
                        else {
                            ret = (nums1[mid1] + nums2[n - 1]) / 2.0;
                        }
                    }
                    else {
                        if (odd) {
                            ret = max(nums1[mid1 - 1], nums2[n-1]);
                        }
                        else {
                            ret = (nums1[mid1] + max(nums1[mid1 - 1], nums2[n - 1])) / 2.0;
                        }
                    }
                    break;
                }
                s = mid1 + 1;
                continue;
            }


            if (nums1[mid1 - 1] <= nums2[mid2] &&
                nums2[mid2 - 1] <= nums1[mid1]) {
                find = true;
                if (odd) {
                    ret = max(nums1[mid1 - 1], nums2[mid2 - 1]);
                }
                else {
                    ret = (max(nums1[mid1 - 1], nums2[mid2 - 1]) + min(nums1[mid1], nums2[mid2])) / 2.0;
                }
                break;
            }
            else if (nums1[mid1-1] <= nums2[mid2]) {
                s = mid1 + 1;
            }
            else {
                e = mid1 - 1;
            }

        }

        return ret;
    }
};

#else

//reference from https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/554231/Simple-C%2B%2B-Solution-O(log(min(nums1-nums2)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int len1 = nums1.size();
        int len2 = nums2.size();

        int start = 0, end = len1;
        while (start <= end) {
            int partition1 = (start + end) / 2;
            int partition2 = (len1 + len2 + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT32_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == len1) ? INT32_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT32_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == len2) ? INT32_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((len1 + len2) % 2 == 0) {
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2) {
                end = partition1 - 1;
            }
            else {
                start = partition1 + 1;
            }
        }
        return 0.0;
    }

};

#endif

int main()
{
    Solution sol;

    int tvarr1[] = { 2};
    //int tvarr2[] = {};
    
    vector<int> tv1(tvarr1, tvarr1 + 1);
    //vector<int> tv2(tvarr2, tvarr2 + 2);
    vector<int> tv2;

    printf("%lf\n", sol.findMedianSortedArrays(tv1, tv2));

    return 0;
}