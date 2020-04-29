#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1<<n, 0);
        
        for (int i = 0; i < n; i++) {
            int offset = 1 << i;
            for (int j = 0; j < offset; j++) {
                ret[offset + j] = ret[offset - j - 1] + offset;
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<int> ret;

    ret = sol.grayCode(2);

    ret = sol.grayCode(0);

    ret = sol.grayCode(15);


    ret = sol.grayCode(20);

    return 0;
}