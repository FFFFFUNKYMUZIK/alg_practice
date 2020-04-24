#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ret;

        if (intervals.size() == 0) return vector<vector<int>>(1, newInterval);

        if (newInterval[1] < intervals[0][0]) {
            ret.push_back(newInterval);
            ret.resize(intervals.size() + 1);
            copy(intervals.begin(), intervals.end(), ret.begin()+1);
            return ret;
        }
        if (newInterval[0] > intervals[intervals.size() - 1][1]) {
            ret = intervals;
            ret.push_back(newInterval);
            return ret;
        }

        bool ins = false;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int>& cur = intervals[i];
            if (!ins) {
                if (newInterval[0] <= cur[1] && newInterval[1] >= cur[0]) {
                    cur[0] = min(cur[0], newInterval[0]);
                    cur[1] = max(cur[1], newInterval[1]);
                    while (++i < intervals.size() && intervals[i][0] <= cur[1]) {
                        cur[1] = max(cur[1], intervals[i][1]);
                    }
                    i--;
                    ins = true;
                }
                else if (newInterval[1]<cur[0]) {
                    ret.push_back(newInterval);
                    ins = true;
                }
            }
            ret.push_back(cur);
            
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> intv;
    vector<int> nintv;
    vector<vector<int>> ret;

    intv = vector<vector<int>>({ {1,3},{6,9} });
    nintv = vector<int>({ 2,5 });
    ret = sol.insert(intv, nintv);

    intv = vector<vector<int>>({ {1,2},{3,5}, {6,7}, {8,10}, {12,16} });
    nintv = vector<int>({ 4,8 });
    ret = sol.insert(intv, nintv);

    intv = vector<vector<int>>({ {1,5} });
    nintv = vector<int>({ 0,0 });
    ret = sol.insert(intv, nintv);

    return 0;
}
