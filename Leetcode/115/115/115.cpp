#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    vector<vector<int>> dp;
    string ss, ts;

    int get(int i, int j) {
        int& ret = dp[i][j];

        if (ret != -1) return ret;

        ret = get(i + 1, j);
        if (ss[i] == ts[j]) {
            ret += get(i + 1, j + 1);
        }
        return ret;
    }
       
    int numDistinct(string s, string t) {

        int slen = s.length();
        int tlen = t.length();

        if (slen < tlen) return 0;
        if (tlen == 0) return 1;
        if (slen == 0) return 0;

        ss = s;
        ts = t;
        dp = vector<vector<int>>(slen, vector<int>(tlen, -1));

        int cnt = 0;
        for (int i = slen - 1; i >= 0; i--) {
            if (s[i] == t[tlen - 1]) cnt++;
            dp[i][tlen - 1] = cnt;
            if (tlen - (slen - i) - 1 >= 0) dp[i][tlen - (slen - i) - 1] = 0;
        }

        return get(0, 0);
    }
};

int main()
{
    Solution sol;
    int ret;

    ret = sol.numDistinct(string("rabbbit"), string("rabbit"));

    ret = sol.numDistinct(string("babgbag"), string("bag"));

    return 0;
}