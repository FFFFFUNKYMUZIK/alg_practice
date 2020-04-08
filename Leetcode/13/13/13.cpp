#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        vector<string> str({string("I"), string("IV"),string("V"),string("IX"),string("X"),string("XL"),string("L"),string("XC"),string("C"),string("CD"), string("D"), string("CM"), string("M") });
        vector<int> val({ 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 });
        unordered_map<string, int> um;

        for (int i = 0; i < val.size(); i++) {
            um[str[i]] = val[i];
        }

        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (um.find(s.substr(i, 2)) != um.end()) {
                ret += um[s.substr(i, 2)];
                i++;
            }
            else {
                ret += um[s.substr(i, 1)];
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    
    int ret;
        
    ret = sol.romanToInt(string("III"));
    ret = sol.romanToInt(string("IV"));
    ret = sol.romanToInt(string("IX"));
    ret = sol.romanToInt(string("LVIII"));
    ret = sol.romanToInt(string("MCMXCIV"));

    ret = sol.romanToInt(string("DCXXI"));


    return 0;
}
