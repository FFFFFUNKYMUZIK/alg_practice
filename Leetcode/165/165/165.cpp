#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {

		int n1 = version1.length();
		int n2 = version2.length();

		vector<int> ver1, ver2;
		int idx1 = 0, idx2 = 0;
		int cnt1, cnt2;
		
		while (idx1 < n1 || idx2 < n2) {
			cnt1 = 0;
			cnt2 = 0;
			while (idx1 + cnt1 < n1 && version1[idx1+cnt1] != '.') cnt1++;
			while (idx2 + cnt2 < n2 && version2[idx2+cnt2] != '.') cnt2++;

			if (cnt1 != 0) {
				ver1.push_back(stoi(version1.substr(idx1, cnt1)));
			}
			else {
				ver1.push_back(0);
			}

			if (cnt2 != 0) {
				ver2.push_back(stoi(version2.substr(idx2, cnt2)));
			}
			else {
				ver2.push_back(0);
			}


			if (ver1.back() > ver2.back()) return 1;
			else if (ver1.back() < ver2.back()) return -1;

			idx1 += (cnt1+1);
			idx2 += (cnt2+1);
		}

		return 0;
	}
};

int main()
{
	Solution sol;

	int ret;
	ret=sol.compareVersion(string("0.1"), string("1.1"));

	ret = sol.compareVersion(string("1.0.1"), string("1"));

	ret = sol.compareVersion(string("7.5.2.4"), string("7.5.3"));

	ret = sol.compareVersion(string("1.01"), string("1.001"));

	ret = sol.compareVersion(string("1.0"), string("1.0.0"));

    return 0;
}

