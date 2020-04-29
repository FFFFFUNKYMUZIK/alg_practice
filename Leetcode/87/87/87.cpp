#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    bool isScramble_helper(const char* s1, const char * s2, int len) {

        if (len == 0) return true;
        if (len == 1 && *s1==*s2) return true;

        int cnt = 0;
        vector<int> cntbuf(255, 0);

        for (int i = 0; i < len - 1; i++) {
            if ((++cntbuf[s1[i]]) <= 0) cnt++;
            if ((--cntbuf[s2[i]]) >= 0) cnt++;
            if (cnt == i + 1) {
                if (isScramble_helper(s1, s2, cnt) && isScramble_helper(s1+cnt, s2+cnt, len-cnt)) {
                    return true;
                }
            }
        }

        cnt = 0;
        vector<int>(255, 0).swap(cntbuf);
        for (int i = 0; i < len - 1; i++) {
            if ((++cntbuf[s1[i]]) <= 0) cnt++;
            if ((--cntbuf[s2[len - i - 1]]) >= 0) cnt++;
            if (cnt == i + 1) {
                if (isScramble_helper(s1, s2 + len - cnt, cnt) && isScramble_helper(s1 + cnt, s2, len - cnt)) {
                    return true;
                }
            }
        }

        return false;

    }
    
    bool isScramble(string s1, string s2) {
        return isScramble_helper(s1.c_str(), s2.c_str(), s1.length());
    }
};

int main()
{
    Solution sol;
    bool ret;

    ret = sol.isScramble(string("great"), string("rgeat"));

    ret = sol.isScramble(string("abcde"), string("caebd"));

    ret = sol.isScramble(string("abb"), string("bba"));

    ret = sol.isScramble(string("abc"), string("bca"));

    return 0;
}

