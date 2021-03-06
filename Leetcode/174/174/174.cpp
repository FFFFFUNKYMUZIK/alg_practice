﻿#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	int calculateMinimumHP(vector<vector<int>>& dungeon) {

		int h = dungeon.size();
		int w = dungeon[0].size();

		vector<int> dp(w, 0);

		dp[w - 1] = min(dp[w - 1] + dungeon[h - 1][w - 1], 0);
		for (int j= w - 2; j >= 0; j--) {
			dp[j] = min(dp[j+1] + dungeon[h-1][j] , 0);
		}

		for (int i = h - 2; i >= 0; i--) {
			dp[w - 1] = min(dp[w - 1] + dungeon[i][w-1], 0);
			for (int j = w - 2; j >= 0; j--) {
				dp[j] = min(max(dp[j], dp[j + 1]) + dungeon[i][j], 0);
			}
		}

		return abs(dp[0]) + 1;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> in;
	int ret;

	in = vector<vector<int>>({ {-2,-3,3}, {-5,-10,1}, {10,30,-5} });
	ret = sol.calculateMinimumHP(in);

	in = vector<vector<int>>({ {-2, -3, 3, -13, 15, 28}, {-5,-10,1, -100, 22, -12}, {10,30,-5, -12, -1, -100}, {1, 2, 3, 5, 7, 2} });
	ret = sol.calculateMinimumHP(in);

	return 0;
}

