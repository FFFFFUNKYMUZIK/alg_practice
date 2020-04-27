#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int nidx = 0;
        for (int i = 0; i < n; i++) {
            if (i < (n - 2) &&  nums[i] == nums[i + 2]) continue;
            nums[nidx++] = nums[i];
        }

        return nidx;
    }
};

int main()
{
    Solution sol;

    int ret;
    vector<int> in;

    in = vector<int>({1,1,1,2,2,3});
    ret = sol.removeDuplicates(in);

    in = vector<int>({ 0,0,1,1,1,1,2,3,3 });
    ret = sol.removeDuplicates(in);

    in = vector<int>({ 1 });
    ret = sol.removeDuplicates(in);

    return 0;
}
