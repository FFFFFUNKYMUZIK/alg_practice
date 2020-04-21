#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;

    void backtrack(vector<int>& cand, vector<int> candcnt, int s, vector<int>& bucket, int left) {

        if (left == 0) {
            ret.push_back(bucket);
        }

        for (int i = s; i < cand.size(); i++) {
            if (left >= cand[i]) {
                int cnt = 0;
                while (left >= cand[i] && candcnt[i] > 0) {
                    cnt++;
                    bucket.push_back(cand[i]);
                    left -= cand[i];
                    candcnt[i]--;
                    backtrack(cand, candcnt, i + 1, bucket, left);
                }
                left += cnt * cand[i];
                candcnt[i] += cnt;

                while (cnt > 0) {
                    bucket.pop_back();
                    cnt--;
                }
            }
            else {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>>().swap(ret);

        vector<int> bucket;

        sort(candidates.begin(), candidates.end());

        vector<int> cand;
        vector<int> candcnt;

        int i = 0;
        while (i < candidates.size()) {
            int cnt = 1;
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
                i++;
                cnt++;
            }
            cand.push_back(candidates[i]);
            candcnt.push_back(cnt);
            i++;
        }

        backtrack(cand, candcnt, 0, bucket, target);

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> ret;
    vector<int> in;
    int target;

    in = vector<int>({10,1,2,7,6,1,5});
    target = 8;
    ret = sol.combinationSum2(in, target);

    in = vector<int>({ 2,5,2,1,2 });
    target = 5;
    ret = sol.combinationSum2(in, target);
    
    return 0;
}

