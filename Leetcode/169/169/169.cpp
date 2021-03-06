#include "stdafx.h"
#include <vector>
#include <unordered_map>

using namespace std;

#if 0
//56ms, 25%
//O(n)

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n = nums.size();
		int thr = n / 2;
		unordered_map<int, int> cnt;

		for (int i = 0; i < n; i++) {
			if (cnt.find(nums[i]) != cnt.end()) {
				cnt[nums[i]]++;
			}
			else {
				cnt[nums[i]] = 1;
			}
			if (cnt[nums[i]] > thr) return nums[i];
		}

		return 0;
	}
};

#else

//reference solution, brilliant solution, O(n)

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n = nums.size();
		int cnt = 0, cand = -1;
		int thr = n / 2;

		for (int i = 0; i < n; i++) {
			cand = (cnt == 0) ? nums[i] : cand;
			cnt += (cand == nums[i]) ? 1 : -1;
			if (cnt > thr) break;
		}

		return cand;
	}
};

#endif

int main()
{
	Solution sol;
	vector<int> in;
	int ret;

	in = vector<int>({3,2,3});
	ret = sol.majorityElement(in);

	in = vector<int>({ 2,2,1,1,1,2,2 });
	ret = sol.majorityElement(in);

    return 0;
}

