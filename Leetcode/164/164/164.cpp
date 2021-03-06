#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

/*
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.
*/

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;

		//radix sort using bit
		vector<int> buf = nums;
		vector<int> tmp(n, 0);
		vector<int> right_tmp(n, 0);

		//O(32*n) = O(n)
		for (int i = 0; i < 31; i++) {
			int l = 0, r = 0;
			for (int j = 0; j < n; j++) {
				if (buf[j] & (1 << i)) {
					right_tmp[r++] = buf[j];
				}
				else {
					tmp[l++] = buf[j];
				}
			}
			r = 0;
			while (l < n) {
				tmp[l++] = right_tmp[r++];
			}
			buf.swap(tmp);
		}

		int maxdiff = 0;
		for (int i = 0; i < n-1; i++) {
			maxdiff = max(maxdiff, buf[i + 1] - buf[i]);
		}

		return maxdiff;
	}
};

int main()
{
	Solution sol;
	int ret;
	vector<int> in;

	in = vector<int>({ 3,6,9,1 });
	ret = sol.maximumGap(in);

	in = vector<int>({ 10 });
	ret = sol.maximumGap(in);


    return 0;
}

