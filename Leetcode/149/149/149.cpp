﻿#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:

	using line = vector<int>;

	using pt = vector<int>;

	int getGCD(unsigned int a, unsigned int b) {
		if (a == 0) return b;
		return getGCD(b % a, a);
	}

	int getLCM(unsigned int a, unsigned int b) {
		int c = a/ getGCD(a, b);
		return c * b;
	}

	struct VectorHasher {
		int operator()(const vector<int>& V) const {
			int hash = 0;
			for (int i = 0; i < V.size(); i++) {
				hash ^= V[i];
			}
			return hash;
		}
	};

	int maxPoints(vector<vector<int>>& points) {

		unordered_map<line, vector<pt>, VectorHasher> um;
		int n = points.size();
		if (n <= 2) return n;
		int ret = 0;
		unordered_map<vector<int>, int, VectorHasher> cnt;
		for (int i = 0; i < n; i++) {
			if (cnt.find(points[i]) != cnt.end()) {
				cnt[points[i]]++;
			}
			else {
				cnt[points[i]] = 1;
			}
		}

		vector<vector<int>> individual;
		for (auto it = cnt.begin(); it != cnt.end(); it++) {
			individual.push_back(it->first);
		}
		n = individual.size();

		for (int i = 1; i < n; i++) {
			unordered_set<line, VectorHasher> us;
			pt p = { individual[i][0], individual[i][1] };
			for (int j = 0; j < i; j++) {
				pt rp = { individual[j][0], individual[j][1] };
				int dx = p[0] - rp[0];
				int dy = p[1] - rp[1];
				int a, b, c;
				//a is forced to be positive to avoid making duplicated hash key among same linear equation
				//otherwise a==0, b is positive.
				if (dx == 0) {
					a = 1;
					b = 0;
					c = -p[0];
				}
				else if (dy == 0) {
					a = 0;
					b = 1;
					c = -p[1];
				}
				else {
					int lcm = getLCM(abs(dx), abs(dy));
					a = abs(lcm / dx);
					int sign = dx * (long long)dy < (long long)0 ? 1 : -1;
					b = abs(lcm / dy) * sign;
					c = -a * p[0] - b * p[1];
				}
				if ((us.find({ a,b,c }) == us.end())) {
					if (um.find({ a,b,c }) == um.end()) {
						um[{a, b, c}].push_back(rp);
					}

					um[{a, b, c}].push_back(p);
					us.insert({ a,b,c });
				}
			}
		}

		if (um.size() == 0) {
			return cnt.begin()->second;
		}

		else {
			for (auto it = um.begin(); it != um.end(); it++) {
				vector<pt>& vec = it->second;
				int sum = 0;
				for (int i = 0; i < vec.size(); i++) {
					sum += cnt[vec[i]];
				}
				ret = max(ret, sum);
			}
		}

		return ret;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> in;
	int ret;

	in = vector<vector<int>>({ {1,1},{2,2},{3,3} });
	ret = sol.maxPoints(in);

	in = vector<vector<int>>({ { 1,1 },{ 3,2 },{ 5,3 }, {4,1}, {2,3}, {1,4} });
	ret = sol.maxPoints(in);

	in = vector<vector<int>>({ { 1,1 },{ 1,1 },{ 2,3 } });
	ret = sol.maxPoints(in);

	in = vector<vector<int>>({ { 0,0 },{ 1,1 },{ 0,0 } });
	ret = sol.maxPoints(in);


	in = vector<vector<int>>({ { 0,0 },{ 1,65536 },{ 65536,0 } });
	ret = sol.maxPoints(in);

	return 0;
}

