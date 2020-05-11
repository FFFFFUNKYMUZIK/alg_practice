#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0) return ret;
        if (numRows >= 1) ret.push_back(vector<int>(1, 1));
        if (numRows >= 2) ret.push_back(vector<int>(2, 1));

        for (int i = 3; i <= numRows; i++) {
            vector<int> layer(i,1);
            for (int j = 1; j < i - 1; j++) {
                layer[j] = ret[i - 2][j - 1] + ret[i - 2][j];
            }
            ret.push_back(layer);
        }

        return ret;
    }
};

int main()
{

    Solution sol;
    vector<vector<int>> ret;

    ret = sol.generate(5);


    return 0;
}
