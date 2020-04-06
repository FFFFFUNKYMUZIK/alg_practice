#include <iostream>
#include <string>

using namespace std;


#if 0

// basic wildcard implementation
class Solution {
public:
    bool isMatch(string s, string p) {
        int len = s.length();
        int plen = p.length();
        
        if (plen == 0){
            if (len > 0) return false;
            else return true;
        }
        if (len == 0) {
            int i = 0;
            while (i < plen) {
                if (p[i] != '*') return false;
                i++;
            }
            return true;
        }

        bool ret = false;
        
        if (s[0] == p[0] || p[0] == '.') return isMatch(s.substr(1), p.substr(1));
        if (p[0] == '*') {
            for (int i = 0; i <= len; i++) {
                if (ret = isMatch(s.substr(i), p.substr(1))) break;
            }
        }

        return ret;
    }
};

#elif 1

//'*' Matches zero or more of the PRECEDING ELEMENT
class Solution {
public:
    bool isMatch(string s, string p) {
        int len = s.length();
        int plen = p.length();

        if (plen == 0) {
            if (len > 0) return false;
            else return true;
        }
        if (len == 0) {
            int j = 0;
            while (j < plen) {
                if (j + 1 < plen && p[j + 1] == '*') {
                    j++;
                    while (j < plen && p[j] == '*') j++;
                }
                else break;
            }
            if (j == plen) return true;
            else return false;
        }

        int i = 0, j = 0;
        char pre = 0;
        while (i < len && j <plen) {
            if (j + 1 < plen && p[j + 1] == '*') {
                pre = p[j];
                j++;
                while (j < plen && p[j] == '*') j++;

                if (isMatch(s.substr(i), p.substr(j))) return true;

                while (i < len && (s[i] == pre || pre == '.')) {
                    if (isMatch(s.substr(i+1), p.substr(j))) return true;
                    i++;
                }
            }
            else if (s[i] == p[j] || p[j] == '.') {
                i++; j++;
            }
            else {
                break;
            }
        }

        if (i == len) {
            while (j < plen) {
                if (j + 1 < plen && p[j + 1] == '*') {
                    j++;
                    while (j < plen && p[j] == '*') j++;
                }
                else break;
            }
            if (j == plen) return true;
            else return false;
        }

        if (i == len && j == plen) return true;

        return false;
    }
};
#else

//reference solution
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (p[j - 1] == '*') {
                    // 1. means 0
                    if (j > 1 && dp[i][j - 2] == 1) {
                        dp[i][j] = 1;
                        continue;
                    }
                    // 2. means 1 or more
                    if (i > 0 && ((s[i - 1] == p[j - 2]) || p[j - 2] == '.')) {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                else if (p[j - 1] == '.') {
                    dp[i][j] = i > 0 ? dp[i - 1][j - 1] : 0;
                }
                else {
                    if (i == 0 || s[i - 1] != p[j - 1]) {
                        dp[i][j] = 0;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n] == 1;
    }
};
*/
#include <vector>



#endif

int main()
{
    Solution sol;
    
    bool ret;
    ret = sol.isMatch(string("aa"), string("aa"));
    ret = sol.isMatch(string("aa"), string("a"));
    ret = sol.isMatch(string("aa"), string("a*"));
    ret = sol.isMatch(string("ab"), string(".*"));
    ret = sol.isMatch(string("aab"), string("c*a*b"));
    ret = sol.isMatch(string("mississippi"), string("mis*is*p*."));
    ret = sol.isMatch(string("aaa"), string("ab*a"));
    ret = sol.isMatch(string("a"), string("ab*"));

    ret = sol.isMatch(string("ab"), string(".*c"));


    return 0;
}
