#include <iostream>
#include <vector>

using namespace std;

/*
problem 153 doesn't allow duplicate element, otherwise problem 154 does.
Solution for 154 can beat prob.153.
following is for prob. 154.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        while (s < e) {
            int mid = (s + e) / 2;

            if (nums[s] < nums[mid]) {
                if (nums[s] < nums[e]) {
                    return nums[s];
                }
                else {
                    s = mid + 1;
                }
            }
            else if (nums[s] == nums[mid]) {
                if (nums[s] < nums[e]) {
                    return nums[s];
                }
                else if(nums[s]==nums[e]){
                    //worst case O(n)
                    s++;
                }
                else {
                    s = mid + 1;
                }
            }
            else {
                s++;
                e = mid;
            }

        }

        //should not reach if input array is valid
        return nums[s];

    }
};

int main()
{
    Solution sol;
    int ret;

    vector<int> in = vector<int>({3,4,5,1,2});
    ret = sol.findMin(in);

    in = vector<int>({ 4,5,6,7,0,1,2 });
    ret = sol.findMin(in);

    in = vector<int>({ 2,2,2,0,1 });
    ret = sol.findMin(in);

    return 0;
}