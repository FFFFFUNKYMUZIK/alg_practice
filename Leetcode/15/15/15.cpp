#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        unordered_map<int, int> um;

        int cur;
        int curcnt = 0;
        int idx = 0;
        vector<int> cand;
        
        while (idx<nums.size()) {
            cur = nums[idx++];
            curcnt = 1;
            while (idx < nums.size() && cur == nums[idx]) {
                curcnt++;
                idx++;
            }
            um[cur] = curcnt;
            cand.push_back(cur);
        }

        for (int i = 0; i < cand.size();i++) {
            cur = cand[i];
            if (cur > 0) break;
            if (cur == 0) {
                if (um[cur] >= 3) {
                    ret.push_back(vector<int>({ 0,0,0 }));
                }
            }
            else {
                if (um[cur] >= 2) {
                    if (um.find(-2 * cur) != um.end()) ret.push_back(vector<int>({ cur, cur, -2 * cur }));
                }
                if (um[cur] >= 1) {
                    for (int j = i + 1; j < cand.size(); j++) {
                        if (-cur - cand[j] < cand[j]) break;

                        um[cand[j]]--;
                        if (um.find(-cur - cand[j]) != um.end() && (um[-cur - cand[j]] > 0)) ret.push_back(vector<int>({ cur, cand[j], -cur - cand[j] }));
                        um[cand[j]]++;
                    }
                }
            }
        }

        return ret;
    }
};


int main()
{
    Solution sol;

    vector<vector<int>> ret;

    vector<int> in;
    
    in = vector<int>({-1, 0, 1, 2, -1, -4});
    ret = sol.threeSum(in);
    in = vector<int>({ 0, 0 });
    ret = sol.threeSum(in);
    in = vector<int>({ 1,1, -2 });
    ret = sol.threeSum(in);

    return 0;
}
