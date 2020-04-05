#include <iostream>
#include <vector>

using namespace std;

#if 1

class Solution {
public:

    int getMaxRepetitions(string s1, int n1, string s2, int n2) {

        int s1len = s1.length();
        int s2len = s2.length();
        
        vector<int> nextpos(s2len, 0);
        vector<int> cnt(s2len, 0);

        for (int i = 0; i < s2len; i++) {
            int sidx = i;
            for (int j = 0; j < s1len; j++) {
                if (s1[j] == s2[sidx]) {
                    sidx++;
                    if (sidx == s2len) {
                        sidx = 0;
                        cnt[i] += 1;
                    }
                }
            }
            nextpos[i] = sidx;
            if (cnt[i] == 0 && sidx == i) return 0;
        }

        int s2cnt = 0;
        int sidx = 0;
        while (n1 > 0) {
            s2cnt += cnt[sidx];
            sidx = nextpos[sidx];
            n1--;
        }

        return s2cnt/n2;
    }
};

#else


#endif

int main()
{
    Solution sol;

    string a("baba"), b("baab");

    printf("%d\n", sol.getMaxRepetitions(a, 11, b, 1));

    return 0;
}
