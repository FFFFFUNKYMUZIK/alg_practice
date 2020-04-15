#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {


        int n = nums.size();
        if (n == 0) return 0;

        int s=0, e = n-1;
        int ret = n;

        while (s<=e) {
            int mid = (s + e) / 2;

            if (nums[mid] < target) {
                s = mid + 1;
            }
            else if (nums[mid]>target){
                ret = mid;
                e = mid - 1;
            }
            else {
                return mid;
            }
        }

        return ret;

    }
};

int main()
{
    Solution sol;

    vector<int> in;
    int tar;
    int ret;

    in = vector<int>({ 1,3,5,6 });


    tar = 5;
    ret = sol.searchInsert(in, tar);

    tar = 2;
    ret = sol.searchInsert(in, tar);

    tar = 7;
    ret = sol.searchInsert(in, tar);

    tar = 0;
    ret = sol.searchInsert(in, tar);

    return 0;
}
