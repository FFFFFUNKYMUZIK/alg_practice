#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {

        int len = str.length();
        int idx = 0;
        long long ret = 0;

        if (len == 0) return 0;

        int sign = 1;
        while (str[idx] == ' ' && idx < len) idx++;
        if (str[idx] == '-' || str[idx] == '+') {
            if (str[idx] == '-') sign = -1;
            idx++;
        }

        int digit = 0;
        while (idx < len) {
            if (str[idx] < '0' || str[idx] > '9') {
                break;
            }
            ret = ret * 10  + str[idx] - '0';
            ret += digit;
            
            if (ret > INT_MAX) {
                if (sign == 1) { return INT_MAX; }
                else { return INT_MIN; }
            }
            idx++;
        }
        
        return ret*sign;
    }
};


int main()
{
    Solution sol;

    int ret;

    ret = sol.myAtoi(string("42"));
    ret = sol.myAtoi(string("4193 with words"));
    ret = sol.myAtoi(string("    -42"));
    ret = sol.myAtoi(string("words and 987"));
    ret = sol.myAtoi(string("-91283472332"));

    return 0;
}
