#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();
        
        vector<string> ret(1, "");
        vector<int> alp_s({0, 3, 6, 9, 12, 15, 19, 22, 26});

        for (int i = 0; i < digits.length(); i++) {
            vector<string> newstr;
            int order = digits[i] - '2';
            char cs = 'a' + alp_s[order];
            int alphabet_num = alp_s[order + 1] - alp_s[order];
            for (int j = 0; j < ret.size(); j++) {
                for (int k = 0; k < alphabet_num; k++) {
                    newstr.push_back(ret[j] + string(1, cs+k));
                }
            }
            ret.swap(newstr);
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<string> ret;
    string in;
    
    in = string("23");
    ret = sol.letterCombinations(in);

    in = string("7");
    ret = sol.letterCombinations(in);

    return 0;
}