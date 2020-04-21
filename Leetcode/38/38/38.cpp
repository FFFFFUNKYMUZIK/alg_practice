#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        string ret = "1";

        for (int i = 0; i < n-1; i++) {
            string buf = ret;
            ret.clear();
            int j = 0;
            while (j < buf.length()) {
                int cnt = 1;
                while (j < (buf.length() - 1) && buf[j]==buf[j+1]) {
                    j++;
                    cnt++;
                }

                ret += to_string(cnt) + buf.substr(j,1);
                j++;
            }
        }
 
        return ret;
    }
};

int main()
{
    Solution sol;

    string ret;
    ret = sol.countAndSay(1);

    ret = sol.countAndSay(4);


    return 0;
}
