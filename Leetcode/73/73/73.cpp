#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //constant space constraint
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;

        bool cr = false, cc = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                cc = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                cr = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (cc) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (cr) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> in;

    in = vector<vector<int>>({ {1,1,1}, {1,0,1}, {1,1,1} });
    sol.setZeroes(in);

    in = vector<vector<int>>({ {0,1,2,0}, {3,4,5,2}, {1,3,1,5} });
    sol.setZeroes(in);


    return 0;
}
