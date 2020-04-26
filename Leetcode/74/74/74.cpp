#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        if (target<matrix[0][0] || target>matrix[m - 1][n - 1]) return false;


        int s=0, e=m;
        int row, col;

        //find row(O(logM))
        while (s + 1 < e) {
            int mid = (s + e) / 2;

            if (target < matrix[mid][0]) {
                e = mid;
            }
            else {
                s = mid;
            }
        }
        row = s;

        //find col(O(logN))
        s = 0, e = n;
        while (s + 1 < e) {
            int mid = (s + e) / 2;

            if (target < matrix[row][mid]) {
                e = mid;
            }
            else {
                s = mid;
            }
        }
        col = s;

        if (target == matrix[row][col]) return true;

        return false;
    }
};

int main()
{
    Solution sol;

    bool ret;

    vector<vector<int>> in;

    in = vector<vector<int>>({ {1,3,5,7},{10,11,16,20},{23,30,34,50} });
    ret = sol.searchMatrix(in, 3);

    in = vector<vector<int>>({ {1,3,5,7},{10,11,16,20},{23,30,34,50} });
    ret = sol.searchMatrix(in, 13);

    return 0;
}
