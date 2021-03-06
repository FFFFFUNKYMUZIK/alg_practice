#include "stdafx.h"
#include <vector>
#include <algorithm>


using namespace std;

/*
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

//reference solution
//O(NK), dp

class Solution {

public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (n <= 1 || k==0) return 0;
		
		if (k >= n / 2) {
			int sum = 0;
			for (int i = 1; i < n; i++) {
				if (prices[i] > prices[i - 1]) sum += (prices[i]-prices[i-1]);
			}
			return sum;
		}

		vector<vector<int>> dp(k + 1, vector<int>(n, 0));

		for (int i = 1; i <= k; i++) {
			int bmax = -prices[0];
			for (int j = 1; j < n; j++) {
				// select max element among two cases,
				// dp[i][j-1] : do not sell stock for prices[j]
				// bmax + prices[j] : sell stock for prices[j]
				dp[i][j] = max(dp[i][j - 1], bmax + prices[j]);

				// save max profit If I got 1 stock
				bmax = max(bmax, dp[i-1][j]-prices[j]);
			}
		}


		return dp[k][n-1];
	}
};

int main()
{
	Solution sol;
	int ret;
	vector<int> in;

	in = vector<int>({2,4,1});
	ret = sol.maxProfit(2, in);

	in = vector<int>({ 3,2,6,5,0,3 });
	ret = sol.maxProfit(2, in);

    return 0;
}

