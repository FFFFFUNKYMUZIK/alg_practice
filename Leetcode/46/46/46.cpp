#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;

    void backtrack(vector<int>& nums, vector<int>& visit, vector<int>& bucket) {
        if (bucket.size() == nums.size()) {
            ret.push_back(bucket);
            return;
        }

        for (int i = 0; i < visit.size(); i++) {
            if (visit[i] == 0) {
                bucket.push_back(nums[i]);
                visit[i] = 1;
                backtrack(nums, visit, bucket);
                bucket.pop_back();
                visit[i] = 0;
            }
             
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 1) return vector<vector<int>>(1, nums);

        vector<vector<int>>().swap(ret);
        vector<int> visit(nums.size(), 0);
        vector<int> bucket;

        backtrack(nums, visit, bucket);
        return ret;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> ret;
    vector<int> in;

    in = vector<int>({1,2,3});
    ret = sol.permute(in);

    return 0;
}
