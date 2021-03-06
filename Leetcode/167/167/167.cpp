#include "stdafx.h"
#include <vector>
#include <unordered_map>

using namespace std;

/*
Note:

Your returned answers(both index1 and index2) are not zero - based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();

		vector<int> ret;
		
		unordered_map<int, int> hash_idx;

		for (int i = 0; i < n; i++) {
			if (hash_idx.find(numbers[i]) == hash_idx.end()) {
				hash_idx[target - numbers[i]] = i+1;
			}
			else {
				ret.push_back(hash_idx[numbers[i]]);
				ret.push_back(i + 1);
			}
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	vector<int> ret;

	vector<int> in;

	in = vector<int>({2,7,11,15});
	ret = sol.twoSum(in, 9);


    return 0;
}

