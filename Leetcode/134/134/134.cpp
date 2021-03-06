#include "stdafx.h"
#include <vector>

using namespace std;

#if 0

class Solution {
public:


	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		if (n == 0) return -1;

		vector<int> candidates(n,0);
		for (int i = 0; i < n; i++) {
			if (gas[i] >= cost[i]) {
				candidates[i] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			if (candidates[i] == 1) {
				int tank = gas[i]-cost[i];
				int cur = (i + 1) % n;
				while (tank >= 0 && cur != i) {
					tank += (gas[cur]-cost[cur]);
					cur++;
					if (cur == n) cur = 0;
				}
				if (tank >= 0 && cur == i) return cur;
				else {
					while (i < n - 1 && candidates[i + 1] == 1) i++;
				}
			}
		}

		return -1;

	}
};

#else

//reference solution (4ms)
//brilliant!
//find start index i which makes the biggest sum
//on later circle path(0 ~ i), if sum goes negative at some index then overall sum < 0 (because 0~i is consist of blocks which makes negative sums)
//therefore, (overall sum >= 0) <=> (no such index that makes (gas-cost) subsequent sum goes negative on range i~(n-1)~(i-1))
class Solution {
public:


	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		if (n == 0) return -1;

		int cur;
		int acc = 0;
		int overall = 0;
		int sidx = 0;
		for (int i = 0; i < n; i++) {
			cur = (gas[i] - cost[i]);
			acc += cur;
			overall += cur;
			if (acc < 0) {
				acc = 0;
				sidx = i + 1;
			}
		}
		
		return (overall<0)||(sidx==n) ? -1 : sidx;

	}
};


#endif

int main()
{
	Solution sol;
	vector<int> in1, in2;
	int ret;

	in1 = vector<int>({ 1,2,3,4,5 });
	in2 = vector<int>({ 3,4,5,1,2 });
	ret = sol.canCompleteCircuit(in1, in2);

	in1 = vector<int>({ 2,3,4 });
	in2 = vector<int>({ 3,4,3 });
	ret = sol.canCompleteCircuit(in1, in2);

    return 0;
}

