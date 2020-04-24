#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n,0));

        int i = 0, x, y;
        int digit = 1;
        int half = n / 2;
        while (i < half) {
            x = y = i;
            for (; y < n - i - 1; y++) ret[x][y] = digit++;
            for (; x < n - i - 1; x++) ret[x][y] = digit++;
            for (; y > i; y--) ret[x][y] = digit++;
            for (; x > i; x--) ret[x][y] = digit++;
            i++;
        }
        if (n % 2 == 1) {
            ret[half][half] = digit;
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> ret;

    ret = sol.generateMatrix(1);

    ret = sol.generateMatrix(3);

    ret = sol.generateMatrix(4);


    return 0;
}
