#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if (len == 0) return true;

        vector<int> cmap(256, -1);
        vector<int> comap(256, -1);

        for (int i = 0; i < len; i++) {
            if (cmap[s[i]] == -1) {
                if (comap[t[i]] != -1) return false;
                cmap[s[i]] = t[i];
                comap[t[i]] = 1;
            }
            else if (cmap[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;

    bool ret;

    ret = sol.isIsomorphic(string("egg"), string("add"));

    return 0;
}
