#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.length();
        int cnt = 0;
        int ret = 0;
        int i = 0;

        while (i < n) {
            while (i<n && s[i] != ' ') {
                cnt++; i++;
            }

            ret = cnt > 0 ? cnt : ret;
            cnt = 0;
            i++;
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    int ret;

    ret = sol.lengthOfLastWord(string("Hello World"));


    return 0;
}
