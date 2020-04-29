#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    vector<string> ret;
    string in;

    void backtrack(int n, int cur, int cnt, string& bucket) {
        if (cnt == 4) {
            if (cur == n) {
                ret.push_back(bucket.substr(1));
            }
            return;
        }

        string buf = bucket;
        if (in[cur] == '0') {
            bucket += ".0";
            backtrack(n, cur + 1, cnt+1, bucket);
            bucket = buf;
            return;
        }

        int unit;
        for (int i = cur, j = 1; i < n && i < cur + 3 ; i++, j++) {
            unit = stoi(in.substr(cur, j));
            if (unit > 255) break;
            buf = bucket;
            bucket += ("." + to_string(unit));
            backtrack(n, i + 1, cnt + 1, bucket);
            bucket = buf;
        }

    }


    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        in = s;

        vector<string>().swap(ret);
        string bucket;
        backtrack(n, 0, 0, bucket);

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> ret;

    ret = sol.restoreIpAddresses(string("25525511135"));

    ret = sol.restoreIpAddresses(string("255011135"));

    return 0;
}