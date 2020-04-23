#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) return ret;

        int n = matrix[0].size();
        
        int half = min(m, n) / 2;

        int i = 0, x, y;
        while (i < half) {
            x = y = i;
            for (; y < n - i - 1; y++)ret.push_back(matrix[x][y]);
            for (; x < m - i - 1; x++)ret.push_back(matrix[x][y]);
            for (; y > i; y--)ret.push_back(matrix[x][y]);
            for (; x > i; x--)ret.push_back(matrix[x][y]);
            i++;
        }
        if (min(m, n) % 2 == 1) {
            x = y = i;
            if (m < n) {
                for (; y < n - i; y++) ret.push_back(matrix[x][y]);
            }
            else {
                for (; x < m - i; x++) ret.push_back(matrix[x][y]);
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<int> ret;

    vector<vector<int>> in;

    in = vector<vector<int>>({ {1,2,3}, {4,5,6}, {7,8,9} });
    ret = sol.spiralOrder(in);

    in = vector<vector<int>>({ {1,2,3, 4}, {5,6, 7, 8}, {9, 10, 11, 12} });
    ret = sol.spiralOrder(in);

    in = vector<vector<int>>({ {6,9,7} });
    ret = sol.spiralOrder(in);


    return 0;
}