#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(m, 0);

        dp[0] = 1;

        while (n-- > 0) {
            for (int i = 1; i < m; i++) {
                dp[i] += dp[i - 1];
            }
        }

        return dp[m - 1];

    }
};

int main()
{

    Solution sol;

    int ret;

    //It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
    ret = sol.uniquePaths(3, 2);

    ret = sol.uniquePaths(7, 3);


    return 0;
}
