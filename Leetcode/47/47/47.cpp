#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;

    void backtrack(vector<int>& nums, vector<int>& cand, vector<int>& candcnt, vector<int>& bucket) {
        if (bucket.size() == nums.size()) {
            ret.push_back(bucket);
            return;
        }

        for (int i = 0; i < cand.size() ; i++) {
            if (candcnt[i] > 0) {
                bucket.push_back(cand[i]);
                candcnt[i]--;
                backtrack(nums, cand, candcnt, bucket);
                bucket.pop_back();
                candcnt[i]++;
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() <= 1) return vector<vector<int>>(1, nums);

        sort(nums.begin(), nums.end());

        vector<int> cand;
        vector<int> candcnt;

        int i = 0;
        while (i < nums.size()) {
            int cnt = 1;
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
                cnt++;
            }
            cand.push_back(nums[i]);
            candcnt.push_back(cnt);
            i++;
        }

        vector<vector<int>>().swap(ret);
        vector<int> bucket;

        backtrack(nums, cand, candcnt, bucket);

        return ret;

    }
};

int main()
{
    Solution sol;

    vector<vector<int>> ret;
    vector<int> in;

    in = vector<int>({1,1,2});
    ret = sol.permuteUnique(in);
        
    return 0;
}