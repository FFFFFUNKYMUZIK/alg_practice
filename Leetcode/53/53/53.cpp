#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int ret = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            ret = max(ret, sum);
        }
        return ret;
    }
};




int main()
{

    Solution sol;
    vector<int> in;
    int ret;

    in = vector<int>({-2,1,-3,4,-1,2,1,-5,4});
    ret = sol.maxSubArray(in);

    return 0;
}
