#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int cidx=0;
        int nidx=0;
        for (int i = 0; i < n; i++) {
            nidx = max(nidx, i + nums[i]);
            if (nidx >= n - 1) return true;
            if (i == cidx) {
                if (nidx == cidx) return false;
                cidx = nidx;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> in;
    bool ret;

    in = vector<int>({2,3,1,1,4});
    ret = sol.canJump(in);

    in = vector<int>({ 3,2,1,0,4 });
    ret = sol.canJump(in);
    
    return 0;
}
