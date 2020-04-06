#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        
        int len = s.length();
        if (len <= numRows || numRows == 1) return s;

        string ret; ret.resize(len);
        vector<int> nextidx(2 * numRows - 2, 0);
        vector<int> nextptn(2 * numRows - 2, 0);

        nextptn[0] = 1;
        for (int i = 1; i < numRows - 1; i++) {
            nextidx[i] = 2 * numRows - 2 - i;
            nextidx[2 * numRows - 2 - i] = i;
            nextptn[2 * numRows - 2 - i] = 1;
        }
        nextidx[numRows - 1] = numRows - 1;
        nextptn[numRows - 1] = 1;

        int cnt = 0;
        int stride = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {
            int j = i;
            int start = 0;
            while (start + j < len) {
                ret[cnt++] = s[start+j];
                start += nextptn[j] * stride;
                j = nextidx[j];
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    string ret;
    ret = sol.convert(string("PAYPALISHIRING"),3);
    ret = sol.convert(string("PAYPALISHIRING"),4);

    return 0;
}
