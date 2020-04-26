#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;

    void backtrack(vector<int>& bucket, int cur, int left, int n) {
        if (left == 0) {
            ret.push_back(bucket);
            return;
        }

        for (int i = cur; i <= n + 1 - left; i++) {
            bucket.push_back(i);
            backtrack(bucket, i + 1, left - 1, n);
            bucket.pop_back();
        }
        
    }


    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>>().swap(ret);

        vector<int> bucket;

        backtrack(bucket, 1, k, n);

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> ret;

    ret = sol.combine(4,2);

    return 0;
}