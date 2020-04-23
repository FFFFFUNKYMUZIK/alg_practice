#include <iostream>
#include <vector>

using namespace std;


// rotate 90 : (i,j) -> (j, n-i-1)
// (i,j) -> (j, n-i-1) -> (n-i-1, n-j-1) -> (n-j-1, i) -> (i, j)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int half1 = n / 2;
        int half2 = (n + 1) / 2;
              
        int tmp;
        int x, y;
        for (int i = 0; i < half1; i++) {
            for (int j = 0; j < half2; j++) {
                x = i;
                y = j;
                tmp = matrix[i][j];
                for (int k = 0; k < 4; k++) {
                    int z = x;
                    x = y;
                    y = n-z-1;

                    z = matrix[x][y];
                    matrix[x][y] = tmp;
                    tmp = z;
                }
            }
        }
    }
};

int main()
{

    Solution sol;
    vector<vector<int>> in;

    in = vector<vector<int>>({ {1,2,3},{4,5,6},{7,8,9} });
    sol.rotate(in);

    in = vector<vector<int>>({ {5,1,9, 11},{2,4,8,10},{13,3,6,7}, {15,14,12,16} });
    sol.rotate(in);

    return 0;
}