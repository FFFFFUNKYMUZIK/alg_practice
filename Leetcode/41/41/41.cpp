#include <iostream>
#include <vector>

using namespace std;

#if 0

//time complexity O(n), space complexity O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        if (n == 0) return 1;

        vector<int> bucket(n + 1 , 0);

        for (int i = 0; i < n; i++) {
            if (0 < nums[i] && nums[i] <= n) {
                bucket[nums[i]] = 1;
            }
        }
        
        int ret;
        for (ret = 1; ret <= n; ret++) {
            if (bucket[ret] == 0) break;
        }
        return ret;
    }
};

#else

//time complexity O(n), space complexity O(1)
//0ms submission solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i + 1 || nums[i] <= 0 || nums[i] > nums.size())i++;
            else if (nums[i] != nums[nums[i] - 1]) swap(nums[nums[i] - 1], nums[i]);
            else i++;
        }
        i = 0;
        while (i < nums.size() && nums[i] == i + 1)i++;
        return i + 1;
    }
};

#endif


int main()
{
    Solution sol;
    
    int ret;
    vector<int> in;

    in = vector<int>({ 1,2,0 });
    ret = sol.firstMissingPositive(in);

    in = vector<int>({ 3,4,-1,1 });
    ret = sol.firstMissingPositive(in);

    in = vector<int>({ 7,8,9,11,12 });
    ret = sol.firstMissingPositive(in);

    return 0;
}
