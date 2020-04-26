#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length();
        int tlen = t.length();


        vector<int> spos(256, 0);
        vector<int> tpos(256, 0);

        int refcnt = 0;
        for (int i = 0; i < tlen; i++) {
            if (tpos[t[i]] == 0) refcnt++;
            tpos[t[i]]++;
        }

        int cnt = 0;
        int minlen = slen + 1;
        int minidx = 0;
        int i = 0, j = 0;

        while (j < slen) {
            if (++spos[s[j]] == tpos[s[j]]) cnt++;
            if (cnt < refcnt) {
                j++;
                continue;
            }
            
            while(i<=j){
                if (spos[s[i]] == tpos[s[i]]) {
                    if (j - i + 1 < minlen) {
                        minlen = j - i + 1;
                        minidx = i;
                    }
                    spos[s[i++]]--;
                    cnt--;

                    break;
                }
                spos[s[i++]]--;
            }
            j++;
        }

        if (minlen == slen + 1) return string("");

        return s.substr(minidx, minlen);
    }
};

int main()
{
    Solution sol;

    string ret;

    ret = sol.minWindow(string("ADOBECODEBANC"), string("ABC"));

    return 0;
}
