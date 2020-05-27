#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


//104ms, 12% sol

#if 0

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

//12ms ref. sol

#elif 1

#include <map>

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.empty()) return 0;
		if (points.size() == 1) return 1;
		if (points.size() == 2) return 2;
		map<double, int> memo_k;
		int res = 2;
		while (points.size() > 2) {
			int vertical_cnt = 1;
			int base_x = points[points.size() - 1][0];
			int base_y = points[points.size() - 1][1];
			memo_k.clear();
			int tempres = 0;
			int same_points = 0;
			for (int i = points.size() - 2; i >= 0; i--) {
				if (points[i][0] == base_x && points[i][1] != base_y) ++vertical_cnt;
				else if (points[i][0] == base_x && points[i][1] == base_y) {
					++same_points;
					points.erase(points.begin() + i);
				}
				else
					++memo_k[((double)(points[i][1] - base_y) / (points[i][0] - base_x))];
			}
			for (auto &i : memo_k)
				if (++i.second > tempres)
					tempres = i.second;
			tempres = (tempres > vertical_cnt ? tempres : vertical_cnt) + same_points;
			res = max(res, tempres);
			points.pop_back();
		}
		return res;
	}
};

#else

//8ms reference solution

using slopeType = long;
slopeType slopeMax = LONG_MAX;
bool debug = false;

struct upoints {
	int x;
	int y;
	int count;
};

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		int numPoints0 = points.size();
		if (numPoints0 == 0) {
			return 0;
		}
		upoints upts[numPoints0];

		int numPoints = 0;

		for (int i = 0; i < numPoints0; ++i) {
			bool dup = false;
			for (int j = 0; j < numPoints; ++j) {
				if (upts[j].x == points[i][0] && upts[j].y == points[i][1]) {
					++upts[j].count;
					dup = true;
					if (debug) cout << "Point " << upts[j].x << ":" << upts[j].y << " duplicates " << upts[j].count << " times." << endl;
					break;
				}
			}
			if (not dup) {
				upts[numPoints].x = points[i][0];
				upts[numPoints].y = points[i][1];
				upts[numPoints].count = 1;
				++numPoints;
			}
		}

		if (numPoints == 0) {
			return 0;
		}
		if (numPoints == 1) {
			return upts[0].count;
		}

		slopeType slopes[numPoints][numPoints];

		for (int i = 0; i < numPoints; ++i) {
			for (int j = 0; j < numPoints; ++j) {
				slopes[i][j] = slopeMax;
			}
		}

		int maxSCount = 0;

		for (int i = 0; i < numPoints - 1; ++i) {
			for (int j = i + 1; j < numPoints; ++j) {
				slopeType slope;
				if (slopes[i][j] == slopeMax) {
					slopeType dy = upts[j].y - upts[i].y;
					slopeType dx = upts[j].x - upts[i].x;
					if (dx == 0) {
						slope = slopeMax - 1;
					}
					else {
						slope = (dy*INT_MAX) / dx;
					}

					if (slope == slopeMax) {
						slope = slopeMax - 1;
					}
					slopes[i][j] = slope;
					slopes[j][i] = slope;
					if (debug) cout << "Slope between point indexes " << i << " and " << j << " " << slope << endl;
				}
				else {
					if (debug) cout << "Slope between point indexes (pre-calculated) " << i << " and " << j << " " << slope << endl;
					slope = slopes[i][j];
				}

				if (debug) cout << endl << "Summary for row:column " << i << ":" << j << endl << endl;
				int hits = upts[i].count + upts[j].count;
				for (int k = 0; k < j; ++k) {
					if (k == i) {
						continue;
					}

					if (slope == slopes[i][k] && (slope <= 0 || slope && (slope & 0x0fffffff || slopes[i][k] & 0x0fffffff))) {
						slopeType dy1 = upts[j].y - upts[k].y;
						slopeType dx1 = upts[j].x - upts[k].x;
						slopeType slope1;
						if (dx1 != 0) {
							slope1 = (dy1*INT_MAX) / dx1;
						}
						else {
							slope1 = slopeMax - 1;
						}
						if (slope != slope1) {
							if (debug) cout << "slope " << i << ":" << j << " and slope " << k << ":" << j << " do not match " << slope << " and " << slope1 << endl;
							continue;
						}
					}
					else {
						if (debug) cout << "Not checking slope " << slope << " with " << slopes[i][k] << endl;
						continue;
					}
					hits += upts[k].count;;
					slopes[j][k] = slope;
					slopes[k][j] = slope;
					if (debug) cout << "Matched slope between points " << i << ":" << j << " and " << i << ":" << k << " " << slope << endl;
				}
				if (debug) cout << endl << "Done summary for row:column " << i << ":" << j << " hits " << hits << endl << endl;
				if (hits > maxSCount) {
					maxSCount = hits;
				}
			}
			if (maxSCount > numPoints0 / 2) {
				return maxSCount;
			}
		}
		return maxSCount;
	}
};

#endif

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

