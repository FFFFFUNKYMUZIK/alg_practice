#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int s1len = s1.length(), s2len = s2.length(), s3len = s3.length();
        if (s1len + s2len != s3len)return false;
        if (s3.length() == 0) return true;

        vector<vector<bool>> dp(s1len + 1, vector<bool>(s2len + 1, false));

        dp[s1len][s2len] = true;

        int i = s1len - 1, j = s2len - 1;
        while (i >= 0) {
            if ((dp[i][s2len] = (s1[i] == s3[i + s2len])) == false) break;
            i--;
        }
        while (j >= 0) {
            if ((dp[s1len][j] = (s2[j] == s3[s1len + j])) == false) break;
            j--;
        }

        for (i = s1len - 1; i >= 0; i--) {
            for (j = s2len - 1; j >= 0; j--) {
                if ((s1[i] == s3[i + j] && dp[i + 1][j]) ||
                    (s2[j] == s3[i + j] && dp[i][j + 1])) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];

    }
};

int main()
{

    Solution sol;
    bool ret;

    ret = sol.isInterleave(string("aabcc"), string("dbbca"), string("aadbbcbcac"));

    ret = sol.isInterleave(string("aabcc"), string("dbbca"), string("aadbbbaccc"));
    
    return 0;
}
