#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxval = nums[0];
		int curmax = nums[0];
		int curmin = nums[0];


		int tmp;
		for (int i = 1; i < nums.size(); i++) {
			tmp = max(max(nums[i] * curmax, nums[i] * curmin), nums[i]);
			curmin = min(min(nums[i] * curmax, nums[i] * curmin), nums[i]);
			curmax = tmp;
			maxval = max(curmax, maxval);
		}
		
		return maxval;
	}
};


int main()
{
	Solution sol;
	int ret;

	vector<int> in = vector<int>({ 2,3,-2,4 });
	ret = sol.maxProduct(in);

	in = vector<int>({ 2,3,-2,4, -1 });
	ret = sol.maxProduct(in);

	in = vector<int>({ -2,0, -1 });
	ret = sol.maxProduct(in);

    return 0;
}

