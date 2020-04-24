#include <iostream>

using namespace std;

class Solution {
public:

    bool isInteger(string s) {
        int n = s.length();
        if (n == 0) return false;

        bool sign = false;

        int i = 0;
        while (i < n) {
            switch (s[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
            case '+':
            case '-':
                if (sign) return false;
                sign = true;
                if (i + 1 == n) return false;
                break;
            case ' ':
                if (i == 0) return false;
                while (i < n && s[i] == ' ') i++;
                if (i != n) return false;
                break;
            default :
                return false;
                break;
            }
            i++;
        }
        return true;
    }


    bool isNumber(string s) {
        int n = s.length();
        if (n == 0) return false;

        int i = 0;
        bool digit = false;
        bool sign = false;
        bool point = false;

        while (s[i] == ' ') i++;
        if (i == n) return false;

        while (i < n) {
            switch (s[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                digit = true;
                break;
            case 'e':
                if (!digit) return false;
                return isInteger(s.substr(i + 1));
                break;
            case '+':
            case '-':
                if (sign || digit) return false;
                sign = true;
                break;
            case '.':
                if (point) return false;
                if (!digit && (s[i + 1] < '0' || s[i + 1]>'9')) return false;
                point = true;
                break;
            case ' ':
                while (i<n && s[i] == ' ') i++;
                if (i != n) return false;
                break;
            default :
                return false;
                break;
            }
            i++;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    bool ret;

    ret = sol.isNumber(string("0"));

    ret = sol.isNumber(string(" 0.1"));

    ret = sol.isNumber(string("abc"));

    ret = sol.isNumber(string("1 a"));
    
    ret = sol.isNumber(string("2e10"));

    ret = sol.isNumber(string(" -90e3   "));

    ret = sol.isNumber(string(" 1e"));

    ret = sol.isNumber(string("e3"));

    ret = sol.isNumber(string(" 6e-1"));

    ret = sol.isNumber(string(" 99e2.5"));

    ret = sol.isNumber(string("53.5e93"));

    ret = sol.isNumber(string(" --6"));

    ret = sol.isNumber(string("-+3"));

    ret = sol.isNumber(string("95a54e53"));


    return 0;
}
