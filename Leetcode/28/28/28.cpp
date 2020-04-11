#include <iostream>
#include <string>
#include <vector>

using namespace std;

//kmp

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int m = needle.length();

        if (m == 0) return 0;
        vector<int> pi(m, 0);
        
        int acc = 0;
        for (int i = 1; i < m; i++) {
            while (acc > 0 && needle[i] != needle[acc]) {
                acc = pi[acc-1];
            }
            if (needle[i] == needle[acc]) {
                pi[i] = ++acc;
            }
        }

        acc = 0;
        int s = -1;
        for (int i = 0; i < n; i++) {
            while (acc > 0 && haystack[i]!=needle[acc]) {
                acc = pi[acc-1];
            }
            if (haystack[i] == needle[acc]) {
                ++acc;
            }
            if (acc == m) {
                s = i - (m-1);
                break;
            }
        }

        return s;
    }
};

int main()
{
    Solution sol;
    string in1, in2;
    int ret;

    ret = sol.strStr(in1, in2);

    in1 = string("e");
    in2 = string("");
    ret = sol.strStr(in1, in2);

    in1 = string("hello");
    in2 = string("ll");
    ret = sol.strStr(in1, in2);
    
    in1 = string("aaaaa");
    in2 = string("bba");
    ret = sol.strStr(in1, in2);
    
    in1 = string("mississippi");
    in2 = string("issip");
    ret = sol.strStr(in1, in2);


    return 0;
}