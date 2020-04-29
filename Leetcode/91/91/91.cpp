#include <iostream>
#include <string>
#include <vector>

using namespace std;


//fibonacci w/ special case('1' & '2')
class Solution {
public:
    int numDecodings(string s) {

        int n = s.length();

        vector<int> noc(n+1, 0);
        noc[0] = noc[1] = 1;
        if (s[0] == '0') return 0;

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') noc[i] = noc[i - 1];

            if (s[i - 2] == '1') {
                noc[i] += noc[i - 2];
            }
            else if (s[i - 2] == '2' && s[i - 1] <= '6') {
                noc[i] += noc[i - 2];
            }
        }

        return noc[n];
    }
};



int main()
{
    Solution sol;

    int ret;

    ret = sol.numDecodings(string("12"));

    ret = sol.numDecodings(string("226"));

    return 0;
}
