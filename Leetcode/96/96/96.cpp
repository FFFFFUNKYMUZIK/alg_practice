#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int count(int s, int e) {

        if (e < s) {
            return 1;
        }

        int& ret = dp[s][e];
        if (ret != 0) return ret;

        for (int i = s; i <= e; i++) {
            ret += (count(s, i - 1) * count(i+1, e));
        }

        return ret;
    }


    int numTrees(int n) {
        dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        return count(1, n);
    }
};

int main()
{
    Solution sol;
    int ret;

    ret = sol.numTrees(18);


    return 0;
}
