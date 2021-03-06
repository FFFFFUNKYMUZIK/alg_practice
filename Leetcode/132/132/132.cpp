#include "stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#if 0
//use DP
//O(N^2) for creating DP table, use queue finding candidate for palindrome O(N^2)
//not good performance (172ms / 20%)
class Solution {
public:

	int minCut(string s) {
		int n = s.length();
		if (n == 0) return 0;

		vector<vector<bool>> isPal = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = n - 1; i >= 0; i--) {
			isPal[i][i] = true;
			if (i != 0) isPal[i][i - 1] = true;

			for (int j = i + 1; j < n; j++) {
				isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
			}
		}
		

		queue<int> q;
		q.push(0);
		int step = 0;
		vector<bool> visit(n + 1, false);

		while (!q.empty()) {
			queue<int> tmpq;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (cur == n) {
					return step-1;
				}
				
				if (!visit[cur]) {
					for (int i = cur; i < n; i++) {
						if (!visit[i+1] && isPal[cur][i]) {
							tmpq.push(i + 1);
						}
					}
				}

				visit[cur] = true;
			}

			step++;
			tmpq.swap(q);
		}
		
		return step-1;
	}
};

#elif 0

//use DP
//O(N^2) for creating DP table, also use DP finding candidate for palindrome O(N^2)
//not good performance (172ms / 20%), same as queue implementation

class Solution {
public:

	int minCut(string s) {
		int n = s.length();
		if (n == 0) return 0;

		vector<vector<bool>> isPal = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = n - 1; i >= 0; i--) {
			isPal[i][i] = true;
			if (i != 0) isPal[i][i - 1] = true;

			for (int j = i + 1; j < n; j++) {
				isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
			}
		}

		vector<int> cut(n, 0);
		cut[0] = 0;

		for (int i = 1; i < n; i++) {
			if (isPal[0][i]) {
				cut[i] = 0;
				continue;
			}
			
			cut[i] = cut[i - 1] + 1;
			for (int j = 1; j < i; j++) {
				if (isPal[j][i]) {
					cut[i] = min(cut[i], cut[j-1] + 1);
				}
			}
		}

		return cut[n-1];
	}
};

#else


//use DP
//O(N^2) for creating DP table(but fill elements by diagonal order, break if false occurs), also use DP finding candidate for palindrome O(N^2)
//24ms

class Solution {
public:

	int minCut(string s) {
		int n = s.length();
		if (n <= 1) return 0;

		vector<vector<int>> isPal(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--) {
			isPal[i][i] = 1;
			if (i != 0) isPal[i][i - 1] = 1;

			for (int j = i + 1, is = i; j < n && is >= 0; j++, is--) {
				if ((isPal[is][j] = (s[is] == s[j]))==0) break;
			}
		
			for (int j = i, is = i; j < n && is >= 0; j++, is--) {
				if ((isPal[is][j] = (s[is] == s[j]))==0) break;
			}
		}

		vector<int> cut(n, 0);
		cut[0] = 0;

		for (int i = 1; i < n; i++) {
			if (isPal[0][i]) {
				cut[i] = 0;
				continue;
			}

			cut[i] = cut[i - 1] + 1;
			for (int j = 1; j < i; j++) {
				if (isPal[j][i]) {
					cut[i] = min(cut[i], cut[j - 1] + 1);
				}
			}
		}

		return cut[n - 1];
	}
};


#endif

int main()
{

	Solution sol;
	int ret;

	ret = sol.minCut(string("aab"));

	ret = sol.minCut(string("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"));

	return 0;
}

