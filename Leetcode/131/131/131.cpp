#include "stdafx.h"

#include <string>
#include <vector>
#include <list>

using namespace std;

#if 0

//not optimal
//duplicate calculation of palindrome
//example:	"aa" "a" "aaaaaaaaa"
//			"a" "aa" "aaaaaaaaa"
//					^ calculate palindrome position several times for same string
//T.C. of calculating palindrome position for each string : O(N^2) 
//T.C. of worst case bactrack : O(2^(N-1))

class Solution {
public:

	vector<vector<string>> ret;
	string gs;
	
	void backtrack(int s, int n, vector<string>& bucket) {
		if (s == n) {
			ret.push_back(bucket);
			return;
		}

		list<int> pos;
		list<int> tmp;
		for (int i = s; i < n; i++) tmp.push_back(i);
		int step = 0;
		while (!tmp.empty()) {
			for (auto it = tmp.begin(); it != tmp.end();) {
				if (s + step >= *it - step) {
					pos.push_back(*it);
					it = tmp.erase(it);
					continue;
				}

				if (gs[s + step] != gs[*it - step]) {
					it = tmp.erase(it);
				}
				else {
					it++;
				}
			}
			step++;
		}

		for (auto it = pos.begin(); it != pos.end(); it++) {
			bucket.push_back(gs.substr(s, *it - s +  1));
			backtrack(*it + 1, n, bucket);
			bucket.pop_back();
		}

	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>>().swap(ret);
		gs = s;
		vector<string> bucket;
		if (s.empty()) return ret;
			
		backtrack(0, s.length(), bucket);

		return ret;
	}
};

#else

//use DP
//O(N^2) for creating DP table, finding candidate for palindrome O(N)

class Solution {
public:

	vector<vector<string>> ret;
	vector<vector<bool>> isPal;
	string gs;

	void backtrack(int s, int n, vector<string>& bucket) {
		if (s == n) {
			ret.push_back(bucket);
			return;
		}

		for (int i = s; i < n; i++) {
			if (isPal[s][i]) {
				bucket.push_back(gs.substr(s,i-s+1));
				backtrack(i + 1, n, bucket);
				bucket.pop_back();
			}
		}

	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>>().swap(ret);
		int n = s.length();
		if (n==0) return ret;
		gs = s;
		
		isPal = vector<vector<bool>>(n, vector<bool>(n,false));
		for (int i = n - 1; i >= 0; i--) {
			isPal[i][i] = true;
			if (i != 0) isPal[i][i - 1] = true;

			for (int j = i + 1; j < n; j++) {
				isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
			}
		}

		vector<string> bucket;
		backtrack(0, n, bucket);

		return ret;
	}
};

#endif

int main()
{

	Solution sol;
	vector<vector<string>> ret;

	ret = sol.partition(string("aab"));

    return 0;
}

