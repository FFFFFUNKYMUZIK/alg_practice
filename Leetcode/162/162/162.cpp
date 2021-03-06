#include "stdafx.h"
#include <vector>

using namespace std;

/*
Follow up: Your solution should be in logarithmic complexity.
*/

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int s = 0;
		int n = nums.size();
		int e = n - 1;
		if (n == 1) return 0;

		while (s < e) {
			int mid = (s + e) / 2;

			if (nums[mid] < nums[mid + 1]) {
				s = mid + 1;
			}
			else {
				e = mid;
			}
		}

		return s;
	}
};

int main()
{
	Solution sol;
	vector<int> in;
	int ret;

	in = vector<int>({1,2,3,1});
	ret = sol.findPeakElement(in);


	in = vector<int>({ 1,2,1,3,5,6,4 });
	ret = sol.findPeakElement(in);

    return 0;
}

