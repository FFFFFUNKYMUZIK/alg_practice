#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n = nums.size();
        if (n == 0) return 0;

        int idx = 0;
        int i = 0;
        while (i < n) {
            if (nums[i] == val) {
                i++;
                continue;
            }

            nums[idx++] = nums[i++];
        }

        return idx;

    }
};

int main()
{
    Solution sol;
    int ret;
    vector<int> in;

    in = vector<int>({ 3,2,2,3 });
    ret = sol.removeElement(in, 3);

    in = vector<int>({ 0, 1, 2, 2, 3, 0, 4, 2 });
    ret = sol.removeElement(in, 2);

    return 0;
}
