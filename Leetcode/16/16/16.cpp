#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int sum;
        int nearest_sum = nums[0]+nums[1]+nums[2];
        int min_diff = abs(nearest_sum - target);

        for (int i = 0; i < nums.size() && 3*nums[i]<=target; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int k = nums.size() - 1;
            for (int j = i+1; j < nums.size() && j < k;) {
                sum = nums[i] + nums[j] + nums[k];
                
                if (abs(sum - target) < min_diff) {
                    nearest_sum = sum;
                    min_diff = abs(sum - target);
                }

                if (min_diff == 0) return target;

                if (target > sum) {
                    j++;
                    while (j < nums.size() && nums[j] == nums[j-1]) {
                        j++;
                    }
                }
                else {
                    k--;
                    while (k > j&& nums[k] == nums[k+1]) {
                        k--;
                    }
                }
            }
        }

        return nearest_sum;

    }
};

int main()
{
    Solution sol;

    int ret;

    vector<int> in; int tar;

    in = vector<int>({-1, 2, 1, -4});
    tar = 1;
    ret = sol.threeSumClosest(in ,tar);
    in = vector<int>({ 0, 2, 1, -3 });
    tar = 1;
    ret = sol.threeSumClosest(in, tar);

    in = vector<int>({ 6, -18, -20, -7, -15, 9, 18, 10, 1, -20, -17, -19, -3, -5, -19, 10, 6, -11, 1, -17, -15, 6, 17, -18, -3, 16, 19, -20, -3, -17, -15, -3, 12, 1, -9, 4, 1, 12, -2, 14, 4, -4, 19, -20, 6, 0, -19, 18, 14, 1, -15, -5, 14, 12, -4, 0, -10, 6, 6, -6, 20, -8, -6, 5, 0, 3, 10, 7, -2, 17, 20, 12, 19, -13, -1, 10, -1, 14, 0, 7, -3, 10, 14, 14, 11, 0, -4, -15, -8, 3, 2, -5, 9, 10, 16, -4, -3, -9, -8, -14, 10, 6, 2, -12, -7, -16, -6, 10 });
    tar = -52;
    ret = sol.threeSumClosest(in, tar);

    return 0;
}
