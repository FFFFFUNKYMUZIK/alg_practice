#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> ret;

    void backtrack(vector<int>& candidates, int s, vector<int>& bucket, int left) {

        if (left == 0) {
            ret.push_back(bucket);
            return;
        }
        
        for (int i = s; i < candidates.size();i++) {
            if (left >= candidates[i]) {
                bucket.push_back(candidates[i]);
                backtrack(candidates, i, bucket, left - candidates[i]);
                bucket.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>().swap(ret);

        vector<int> bucket;
        backtrack(candidates, 0, bucket, target);

        return ret;
    }
};

int main()
{

    Solution sol;

    vector<int> in;
    vector<vector<int>> ret;
    int target;

    in = vector<int>({ 2,3,6,7 });
    target = 7;
    ret = sol.combinationSum(in, target);

    in = vector<int>({ 2,3,5});
    target = 8;
    ret = sol.combinationSum(in, target);


    return 0;
}