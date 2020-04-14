#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> ret({ -1, -1 });

        if (n == 0) {
            return ret;
        }

        int low = n, high = -1;
        
        int s = 0, e = n-1;
        while (s <= e) {
            int mid = (s + e) / 2;

            if (nums[mid] < target) {
                s = mid + 1;
            }
            else if (nums[mid] >= target) {
                e = mid - 1;
                low = mid;
            }
        }

        s = 0, e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;

            if (nums[mid] <= target) {
                s = mid + 1;
                high = mid;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
        }

        if (low <= high) {
            ret = vector<int>({ low, high });
        }

        return ret;

    }
};

int main()
{
    Solution sol;

    vector<int> in;
    int tar;
    vector<int> ret;
    
    in = vector<int>({5,7,7,8,8,10});
    tar = 8;
    ret = sol.searchRange(in, tar);

    in = vector<int>({ 5,7,7,8,8,10 });
    tar = 6;
    ret = sol.searchRange(in, tar);

    in = vector<int>({ 5,7,7,8,8,10 });
    tar = 3;
    ret = sol.searchRange(in, tar);

    in = vector<int>({ 5,7,7,8,8,10 });
    tar = 11;
    ret = sol.searchRange(in, tar);

    return 0;
}
