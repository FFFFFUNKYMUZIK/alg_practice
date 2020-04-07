#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        string ret;
        vector<int> val({1,4, 5, 9, 10,40, 50, 90, 100, 400, 500,900, 1000});
        vector<string> ch({ string("I"), string("IV"), string("V"), string("IX"), string("X"), string("XL"), string("L"), string("XC"), string("C"), string("CD"), string("D"), string("CM"), string("M") });
        unordered_map<int, string> cm;

        for (int i = 0; i < val.size(); i++) {
            cm[val[i]] = ch[i];
        }

        int q;
        for (int i = val.size()-1; i >=0; i--) {
            q = num / val[i];
            for (int j = 0; j < q; j++) {
                ret+=cm[val[i]];
            }
            if ((num -= q * val[i]) == 0) break;
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    string ret;
    ret = sol.intToRoman(3);
    ret = sol.intToRoman(4);
    ret = sol.intToRoman(9);
    ret = sol.intToRoman(58);
    ret = sol.intToRoman(1994);

    return 0;
}