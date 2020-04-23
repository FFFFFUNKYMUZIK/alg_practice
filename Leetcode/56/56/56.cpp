#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool sortvec(vector<int>& lhs, vector<int>& rhs) const{
        if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
        return lhs[0] < rhs[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ret;
        if (n <= 0) return ret;

        sort(intervals.begin(), intervals.end(), [this](vector<int>& lhs, vector<int>& rhs) {return sortvec(lhs, rhs); });

        vector<int> cur = intervals[0];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= cur[1]) cur[1] = max(cur[1], intervals[i][1]);
            else {
                ret.push_back(cur);
                cur = intervals[i];
            }
        }
        ret.push_back(cur);

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ret, in;

    in = vector<vector<int>>({ {1,3}, {2,6}, {8,10}, {15,18} });
    ret = sol.merge(in);

    in = vector<vector<int>>({ {1,4}, {4,5} });
    ret = sol.merge(in);

    in = vector<vector<int>>({ {1,4}, {0, 2},  {3,5} });
    ret = sol.merge(in);

    return 0;
}