#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int n = s.length();
		int ret = 0;

		int i = n - 1;
		char cur;
		int mul = 1;
		const char *pcur = s.c_str()+(n-1);
		while (i >= 0) {
			cur = *(pcur--);

			ret += ((cur - 'A') + 1)*mul;
			i--;
			if (i>=0)mul *= 26;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	int ret;

	ret = sol.titleToNumber(string("A"));

	ret = sol.titleToNumber(string("AB"));

	ret = sol.titleToNumber(string("ZY"));


    return 0;
}

