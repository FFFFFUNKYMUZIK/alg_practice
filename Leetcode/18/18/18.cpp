#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>>();

        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        int cur_sum;
        int two_sum;
        for (int i = 0; i < (nums.size() - 3) && (4*nums[i]<=target);) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            for (int j = i + 1; j < nums.size();) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                cur_sum = nums[i]+nums[j];
                two_sum = target - cur_sum;
                for (int m = j + 1, n = nums.size()-1; m < n;) {
                    cur_sum = two_sum - (nums[m]+nums[n]);

                    if (cur_sum > 0) {
                        while (m < nums.size() -1 && nums[m] == nums[m + 1]) m++;
                        m++;
                    }
                    else if (cur_sum < 0) {
                        while (n > 0 && nums[n] == nums[n - 1]) n--;
                        n--;
                    }
                    else {
                        ret.push_back(vector<int>({nums[i], nums[j], nums[m], nums[n]}));
                        while (m < nums.size() - 1 && nums[m] == nums[m + 1]) m++;
                        while (n > 0 && nums[n] == nums[n - 1]) n--;
                        m++; n--;
                    }
                }

                j++;

            }

            i++;

        }

        return ret;

    }
};

int main()
{
    Solution sol;

    vector<int> in({ 1,0,-1,0,-2,2 });
    vector<vector<int>> ret;

    ret = sol.fourSum(in, 0);

    in = vector<int>({ 0,0, 0, 0 });
    ret = sol.fourSum(in, 0);

    in = vector<int>({ -1,0,1,2,-1,-4 });
    ret = sol.fourSum(in, -1);

    return 0;
}
