#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        vector<int> numv, openv;
        string l("("), r(")");

        ret.push_back(l);
        numv.push_back(1);
        openv.push_back(1);

        for (int i = 1; i < 2*n; i++) {
            vector<string> buf;
            vector<int> numvbuf, openvbuf;
            
            for (int j = 0; j < ret.size(); j++) {
                int num = numv[j];
                int open = openv[j];
                string str = ret[j];
                
                if (num < n) {
                    buf.push_back(str+l);
                    numvbuf.push_back(num + 1);
                    openvbuf.push_back(open + 1);
                }
                if (open > 0) {
                    buf.push_back(str+r);
                    numvbuf.push_back(num);
                    openvbuf.push_back(open - 1);
                }
            }

            ret.swap(buf);
            numv.swap(numvbuf);
            openv.swap(openvbuf);
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<string> ret;
    ret = sol.generateParenthesis(1);
    ret = sol.generateParenthesis(3);
    ret = sol.generateParenthesis(2);
    ret = sol.generateParenthesis(4);


    return 0;
}
