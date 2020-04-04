#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MOD (1000000000+7)
#define NUM_ALPHABET 26

class Solution {

public:

    vector<int> pidx = vector<int>(NUM_ALPHABET, -1);
    vector<int> ppidx = vector<int>(NUM_ALPHABET, -1);


    int uniqueLetterString(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;

        vector<int> dp(s.length(), 0);

        dp[0] = 1;
        dp[1] = s[0] == s[1]? 2 : 4;

        pidx[s[0] - 'A'] = 0;
        if (s[0] == s[1]) {
            pidx[s[0] - 'A'] = 1;
            ppidx[s[0] - 'A'] = 0;
        }
        else {
            pidx[s[1] - 'A'] = 1;
        }

        for (int i = 2; i < s.length(); i++) {
            int cidx = s[i] - 'A';
            //dp[i] = (dp[i - 1] + (dp[i - 1] - dp[i - 2]) + (i-pidx[cidx]) - (pidx[cidx] - ppidx[cidx]))%MOD;
            dp[i] = (2*dp[i - 1] - dp[i - 2] + i - 2* pidx[cidx] + ppidx[cidx]) % MOD;
            ppidx[cidx] = pidx[cidx];
            pidx[cidx] = i;
        }

        return dp[s.length() - 1];
    }
};

int main()
{
    Solution sol;
    
    string test("ABA");

    printf("%d\n", sol.uniqueLetterString(test));

    return 0;
}