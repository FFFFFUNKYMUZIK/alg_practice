#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> chbuf(256, -1);
        int maxlen = 0;
        int tmplen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (chbuf[s[i]] + tmplen >= i) {
                tmplen = i - chbuf[s[i]];
            }
            else {
                tmplen++;
                if (maxlen < tmplen) maxlen = tmplen;
            }
            chbuf[s[i]] = i;
        }
        return maxlen;
    }
};

int main()
{

    Solution sol;
    sol.lengthOfLongestSubstring(string("abcabcbb"));

    return 0;
}
