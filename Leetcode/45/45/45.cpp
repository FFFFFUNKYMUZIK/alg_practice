#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#if 0
//BFS
//TLE at last input
// [25000, 24999, 24888, ..., 1, ...] (size : 100000)
class Solution {
public:

    int jump(vector<int>& nums) {

        int n = nums.size();

        //bfs
        queue<pair<int, int>> q;
        vector<int> visit(n, 0);
        q.push(make_pair(0, 0));

        int ret = 0;
        while (!q.empty()) {
            int curidx = q.front().first;
            int jumps = q.front().second;
            q.pop();

            if (curidx == n - 1) {
                ret = jumps;
                break;
            }

            int i = curidx+nums[curidx] < n-1 ? curidx + nums[curidx] : n-1;
            while(i>curidx){
                if (visit[i] == 0) {
                    q.push(make_pair(i, jumps + 1));
                    visit[i] = 1;
                }
                i--;
            }
        }
        return ret;
    }
};

#else

//Time O(n), Space O(1)
class Solution {
public:

    int jump(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0;
        int cidx = 0;
        int nidx = 0;

        int i = 0;
        while (i<n){
            if (i > cidx) {
                cidx = nidx;
                jumps++;
            }
            if (nums[i] + i > nidx) nidx = nums[i] + i;
            if (nidx >= n - 1) {
                jumps++;
                break;
            }

            i++;
        }

        return jumps;

    }
};

#endif

int main()
{
    Solution sol;

    vector<int> in;
    int ret;

    in = vector<int>({ 2,3,1,1,4 });
    ret = sol.jump(in);
    
    in = vector<int>({ 2,3,1,1,4 });
    ret = sol.jump(in);

    in = vector<int>({ 0 });
    ret = sol.jump(in);

    return 0;
}

