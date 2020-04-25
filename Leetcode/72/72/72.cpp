#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
DP(i, j) = DP(i - 1, j - 1)                                         (if a[i] == b[j])
         = 1 + min(DP(i - 1, j), DP(i, j - 1), DP(i - 1, j - 1))	(else a[i] != b[j])

A->B
xxxxxxxxxa
yyyyyb

if (delete a)
xxxxxxxxx
yyyyyb
DP(i - 1, j)

if (insert b)
xxxxxxxxxab
yyyyyb
DP(i, j - 1)

if (replace a to b)
xxxxxxxxxb
yyyyyb

DP(i - 1, j - 1)
*/

#if 0

class Solution {
public:

    vector<vector<int>> dp;
    string istr, jstr;

    int getdist(int i, int j) {
        int& ret = dp[i][j];
        if (ret != -1) return ret;

        if (istr[i - 1] == jstr[j - 1]) return ret = getdist(i - 1, j - 1);
        return ret = 1 + min(min(getdist(i-1, j), getdist(i, j-1)), getdist(i-1, j-1));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n == 0 || m == 0) return max(n, m);

        istr = word1; jstr = word2;

        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int i = 0; i <= m; i++) dp[0][i] = i;

        return  getdist(n, m);
    }
};

#else

//fill all dp element with loop for optimization

class Solution {
public:

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n == 0 || m == 0) return max(n, m);

        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int i = 0; i <= m; i++) dp[0][i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] != word2[j - 1]) dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
                else dp[i][j] = dp[i - 1][j - 1];
            }
        }

        return  dp[n][m];
    }
};

#endif

int main()
{
    Solution sol;

    int ret;
    ret = sol.minDistance(string("horse"), string("ros"));

    ret = sol.minDistance(string("intention"), string("execution"));

    ret = sol.minDistance(string("testcase"), string("lactase"));


    return 0;
}
