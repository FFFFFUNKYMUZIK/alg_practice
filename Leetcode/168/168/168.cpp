#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		char ref = 'A';
		string ret;
		char cchar;

		int cur;
		while (n) {
			cur = (n - 1) % 26;
			n = (n - 1 - cur) / 26;
			cchar = ref + cur;
			ret = string(&cchar, 1) + ret;
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	string ret;

	ret = sol.convertToTitle(1);

	ret = sol.convertToTitle(28);

	ret = sol.convertToTitle(701);

    return 0;
}

