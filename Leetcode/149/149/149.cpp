#include "stdafx.h"
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
		
	typedef struct line_t {
		int a, b, c;
	} line;

	int maxPoints(vector<vector<int>>& points) {

		unordered_map<




	}
};

int main()
{
	Solution sol;
	vector<vector<int>> in;
	int ret;

	in = vector<vector<int>>({ {1,1},{2,2},{3,3} });
	ret = sol.maxPoints(in);

	in = vector<vector<int>>({ { 1,1 },{ 3,2 },{ 5,3 }, {4,1}, {2,3}, {1,4} });
	ret = sol.maxPoints(in);

    return 0;
}

