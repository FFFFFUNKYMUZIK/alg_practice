#include <iostream>
#include <string>
#include <vector>

using namespace std;

#if 0

// recursion w/ memoization O(NM * N) = O(N^2M)
// 60ms elapse
// Memory O(NM)
class Solution {
public:

    string sbuf;
    string pbuf;
    vector<vector<int>> memo;

    int isMatch_sub(int si, int pi) {

        int& ret = memo[si][pi];
        if (ret != -1) return ret;

        if (si == sbuf.size() && pi == pbuf.size()) return (ret = 1);
        else if (pi == pbuf.size()) return (ret = 0);
                
        while (si < sbuf.size() && pi < pbuf.size()) {
            if (pbuf[pi] == sbuf[si] || pbuf[pi] == '?') {
                pi++; si++;
                continue;
            }
            else break;
        }

        if (pi == pbuf.size()) {
            return (ret = isMatch_sub(si, pi));
        }
        else if (pbuf[pi] == '*') {
            while (pi < pbuf.size() && pbuf[pi] == '*') pi++;
            while (si <= sbuf.size()) {
                if (ret = isMatch_sub(si, pi)) return ret;
                si++;
            }
        }

        return (ret = 0);

    }


    bool isMatch(string s, string p) {

        sbuf = s;
        pbuf = p;
        memo = vector<vector<int>> (s.size() + 1, vector<int>(p.size() + 1, -1));

        return isMatch_sub(0, 0);
    }
};

#elif 0

//maximize to utilize memo O(NM)
//no loop for each partial prob.
//52ms elapse
//Memory O(NM)

class Solution {
public:

    string sbuf;
    string pbuf;
    vector<vector<int>> memo;

    int isMatch_sub(int si, int pi) {

        int& ret = memo[si][pi];
        if (ret != -1) return ret;
        ret = 0;

        if (si == sbuf.size() && pi == pbuf.size()) return (ret = 1);
        else if (pi == pbuf.size()) return (ret = 0);

        if (si < sbuf.size() && pi < pbuf.size() &&
            (pbuf[pi] == sbuf[si] || pbuf[pi] == '?')) {
            return ret = isMatch_sub(si + 1, pi + 1);
        }

        if (pi == pbuf.size()) {
            return ret = isMatch_sub(si, pi);
        }
        else if (pbuf[pi] == '*') {
            return ret = isMatch_sub(si, pi + 1) || (si < sbuf.size() && isMatch_sub(si + 1, pi));
        }

        return ret;
    }


    bool isMatch(string s, string p) {

        sbuf = s;
        pbuf = p;
        memo = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));

        return isMatch_sub(0, 0);
    }
};

#else

//0ms reference solution
//constant extra space
//elapse 4ms
//time complexity O(NM)

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};


#endif


int main()
{
    Solution sol;

    string in1, in2;
    bool ret;

    in1 = string("aa");
    in2 = string("a");
    ret = sol.isMatch(in1, in2);

    in1 = string("aa");
    in2 = string("*");
    ret = sol.isMatch(in1, in2);
    
    in1 = string("cb");
    in2 = string("?a");
    ret = sol.isMatch(in1, in2);

    in1 = string("adceb");
    in2 = string("a*b");
    ret = sol.isMatch(in1, in2);

    in1 = string("acdcb");
    in2 = string("a*c?b");
    ret = sol.isMatch(in1, in2);

    in1 = string("accbcdbcd");
    in2 = string("a*bcd");
    ret = sol.isMatch(in1, in2);
    
    in1 = string("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba");
    in2 = string("a*******b");
    ret = sol.isMatch(in1, in2);

        
    in1 = string("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb");
    in2 = string("b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a");
    ret = sol.isMatch(in1, in2);
        

    return 0;
}
