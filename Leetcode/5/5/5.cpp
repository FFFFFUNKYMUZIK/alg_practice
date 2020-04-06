#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#if 0

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxlen = 0;
        int tmplen;
        string ret;

        for (int i = 0; i < len; i++) {
            tmplen = 0;
            int j, k;

            j = i - 1;
            k = 0;
            while (j >= 0 && i+k <len) {
                if (s[j] == s[i + k]) tmplen += 2;
                else {
                   break;
                }
                j--;
                k++;
            }

            if (tmplen > maxlen) {
                maxlen = tmplen;
                ret = s.substr(j + 1, i + k - (j + 1));
            }
            
            j = i - 1;
            k = 1;
            tmplen = 1;
            while (j >= 0 && i + k < len) {
                if (s[j] == s[i + k]) tmplen += 2;
                else {
                    break;
                }
                j--;
                k++;
            }

            if (tmplen > maxlen) {
                maxlen = tmplen;
                ret = s.substr(j + 1, i + k - (j + 1));
            }
        }
        return ret;

    }
};

#else


#endif

int main()
{
    Solution sol;
    string ret;
    ret = sol.longestPalindrome(string("babad"));
    //ret = sol.longestPalindrome(string("cbbd"));
    //ret = sol.longestPalindrome(string("a"));
    //ret = sol.longestPalindrome(string("ccc"));
    //ret = sol.longestPalindrome(string("adfabcdcbadda"));

    return 0;
}

