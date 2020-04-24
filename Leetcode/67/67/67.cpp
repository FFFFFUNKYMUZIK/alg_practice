#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        string& lstr = a.length() < b.length() ? b : a;
        int ln = lstr.length();
        string& sstr = a.length() < b.length() ? a : b;
        int sn = sstr.length();

#define VAL(c) ((c)-'0')

        string ret(ln+1, '0');
        int i = 0;
        int round = 0;
        int sum = 0;
        for (; i < sn; i++) {
            sum = VAL(sstr[sn-i-1])+VAL(lstr[ln-i-1])+round;
            ret[ln - i] = sum % 2 + '0';
            round = sum / 2;
        }
        for (; i < ln; i++) {
            sum = VAL(lstr[ln-i-1]) + round;
            ret[ln - i] = sum % 2 + '0';
            round = sum / 2;
        }

        if (round == 0) ret = ret.substr(1);
        else ret[0] = '1';

        return ret;
    }
};


int main()
{
    Solution sol;

    string ret;

    ret = sol.addBinary(string("11"), string("1"));

    ret = sol.addBinary(string("1010"), string("1011"));

    return 0;
}
