// 88.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

#if 0
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> buf(m + n, 0);
        int idx = 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) { buf[idx++] = nums1[i++]; }
            else { buf[idx++] = nums2[j++]; }
        }
        while (i < m) buf[idx++] = nums1[i++];
        while (j < n) buf[idx++] = nums2[j++];

        copy(buf.begin(), buf.end(), nums1.begin());
    }
};
#else
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (m == 0) {
            nums1.swap(nums2);
            return;
        }
        if (n == 0) return;

        vector<int> buf(m + n, 0);

        int idx = 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) buf[idx++] = nums1[i++];
            else buf[idx++] = nums2[j++];
        }
        while (i < m) buf[idx++] = nums1[i++];
        while (j < n) buf[idx++] = nums2[j++];

        nums1.swap(buf);
    }
};
#endif


int main()
{
    Solution sol;
    vector<int> nums1(1,0), nums2(1,1);

    sol.merge(nums1, 0, nums2, 1);

}
