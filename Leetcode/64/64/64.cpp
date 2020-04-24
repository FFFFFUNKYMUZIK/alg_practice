#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        int idx = 0;
        while (idx++ < m) {
            dp[0] += grid[idx-1][0];
            for (int i = 1; i < n; i++) {
                dp[i] = min(dp[i-1], dp[i])+ grid[idx-1][i];
            }
        }

        return dp[n - 1];

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> in;
    int ret;


    in = vector<vector<int>>({ {1,3,1},{1,5,1},{4,2,1} });
    ret = sol.minPathSum(in);
    
    in = vector<vector<int>>({ {1,2,5},{3,2,1}});
    ret = sol.minPathSum(in);
    return 0;
}