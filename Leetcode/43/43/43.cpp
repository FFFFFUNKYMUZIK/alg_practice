#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        int n1 = num1.length();
        int n2 = num2.length();

        if (n1 == 0 || n2 == 0) return string("");

        vector<int> round(n1 + n2, 0);

        string ret;
        int c1, c2, mul;
        for (int i = 0; i < num1.length(); i++) {
            for (int j = 0; j < num2.length() ; j++) {
                c1 = num1[i] - '0';
                c2 = num2[j] - '0';
                if (c1 == 0 || c2 == 0) continue;
                mul = c1 * c2;
                round[i + j] += mul / 10;
                round[i + j + 1] += mul % 10;
            }
        }

        
        for (int i = round.size() - 1; i >= 0; i--) {
            if (i > 0) round[i-1] += round[i] / 10;
            ret = to_string((round[i]%10)) + ret;
        }

        int i = 0;
        while (i < ret.size()-1 && ret[i] == '0') {
            i++;
        }

        return ret.substr(i);
    }
};

int main()
{
    Solution sol;

    string ret;
    string in1, in2;
    
    in1 = "2"; in2 = "3";
    ret = sol.multiply(in1, in2);

    in1 = "123"; in2 = "456";
    ret = sol.multiply(in1, in2);

    in1 = "0"; in2 = "0";
    ret = sol.multiply(in1, in2);

    return 0;
}
