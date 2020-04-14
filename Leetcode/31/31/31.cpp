#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;

        int i = 0;
        for (i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) break;
        }

        sort(nums.begin() + i, nums.end());

        if (i > 0) {
            auto it_up = upper_bound(nums.begin() + i, nums.end(), nums[i - 1]);

            int tmp = nums[i - 1];
            nums[i - 1] = *it_up;
            *it_up = tmp;
        }
    }
};


int main()
{
    Solution sol;

    vector<int> in;

    in = vector<int>({ 1,2,3 });
    sol.nextPermutation(in);

    in = vector<int>({ 3,2,1 });
    sol.nextPermutation(in);

    in = vector<int>({ 1,1,5 });
    sol.nextPermutation(in);

    in = vector<int>({ 1,2,8,4,9,6,5,3 });
    sol.nextPermutation(in);

    in = vector<int>({ 1,2 });
    sol.nextPermutation(in);

    return 0;
}
