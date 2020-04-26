#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;

    void backtrack(vector<int>& nums, vector<int>& bucket, int idx) {
        if (idx == nums.size()) {
            ret.push_back(bucket);
            return;
        }
        //include (idx)th element
        bucket.push_back(nums[idx]);
        backtrack(nums, bucket, idx + 1);
        bucket.pop_back();

        //do not include (idx)th element
        backtrack(nums, bucket, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>().swap(ret);
        vector<int> bucket;

        backtrack(nums, bucket, 0);

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ret;
    vector<int> in;

    in = vector<int>({1,2,3});
    ret = sol.subsets(in);

    return 0;
}
