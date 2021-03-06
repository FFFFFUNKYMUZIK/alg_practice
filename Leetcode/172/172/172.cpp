#include "stdafx.h"

/*
Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
	int trailingZeroes(int n) {
		int ret;

		int cnt = 0;
		long long cur = 2;
		long long N = n;

		cur = 5;
		while (cur<=N) {
			cnt += N / cur;
			cur *= 5;
		}

		return cnt;
	}
};


int main()
{
	Solution sol;
	int ret;

	ret = sol.trailingZeroes(3);

	ret = sol.trailingZeroes(5);

    return 0;
}

