#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<int> cost(n, 0);
        cost[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {

            cost[i] = triangle[i][i] + cost[i-1];
            for (int j = i - 1; j > 0; j--) {
                cost[j] = min(cost[j - 1], cost[j]) + triangle[i][j];
            }
            cost[0] += triangle[i][0];
        }

        int minval = cost[0];

        for (int i = 1; i < n; i++) {
            if (minval > cost[i]) minval = cost[i];
        }

        return minval;
    }
};

int main()
{

    Solution sol;
    int ret;

    vector<vector<int>> in({ {2}, {3,4}, {6,5,7}, {4,1,8,3} });

    ret = sol.minimumTotal(in);

    return 0;
}
