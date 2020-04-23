#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    int ret;
    vector<int> col;
    vector<int> inc;
    vector<int> dec;

#define INCIDX(x, y, n) ((x)-(y) + (n)-1)
#define DECIDX(x, y, n) ((x)+(y)) 

    void backtrack(int i, int n, vector<string>& bucket) {
        if (i == n) {
            ret++;
            return;
        }

        string& row = bucket[i];
        for (int c = 0; c < row.length(); c++) {
            if (col[c] == 0 &&
                inc[INCIDX(i, c, n)] == 0 &&
                dec[DECIDX(i, c, n)] == 0) {

                col[c] = 1;
                inc[INCIDX(i, c, n)] = 1;
                dec[DECIDX(i, c, n)] = 1;
                row[c] = 'Q';

                backtrack(i + 1, n, bucket);

                col[c] = 0;
                inc[INCIDX(i, c, n)] = 0;
                dec[DECIDX(i, c, n)] = 0;
                row[c] = '.';
            }
        }
    };

    int totalNQueens(int n) {
        if (n == 0) return 0;

        string row;
        for (int i = 0; i < n; i++) row += ".";

        vector<string> bucket(n, row);

        ret = 0;
        col = vector<int>(n, 0);
        inc = vector<int>(2 * n - 1, 0);
        dec = vector<int>(2 * n - 1, 0);

        backtrack(0, n, bucket);

        return ret;
    }
};


int main()
{

    Solution sol;
    vector<vector<string>> ret;
    ret = sol.totalNQueens(4);

    return 0;
}
