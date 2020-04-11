#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0; 
        int idx = 1;

        while (++i < n) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (idx != i)
                nums[idx] = nums[i];
            idx++;
        }

        return idx;
    }
};

int main()
{
    Solution sol;

    int ret;
    vector<int> in({0,0,1,1,1,2,2,3,3,4});

    ret = sol.removeDuplicates(in);

    in = vector<int>();
    ret = sol.removeDuplicates(in);

    in = vector<int>({ 1,2 });
    ret = sol.removeDuplicates(in);

    in = vector<int>({ 1,2, 3 });
    ret = sol.removeDuplicates(in);

    return 0;
}
