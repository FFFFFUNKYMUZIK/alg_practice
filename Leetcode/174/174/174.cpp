#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:

	vector<vector<int>> mindam;
	vector<vector<pair<int, int>>> dp;

	int calculateMinimumHP(vector<vector<int>>& dungeon) {

		int h = dungeon.size();

		mindam = 


	}
};

int main()
{
	Solution sol;
	vector<vector<int>> in;
	int ret;

	in = vector<vector<int>>({ {-2,-3,3}, {-5,-10,1}, {10,30,-5} });
	ret = sol.calculateMinimumHP(in);

    return 0;
}

