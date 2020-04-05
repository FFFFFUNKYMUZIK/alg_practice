#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;

        unordered_map<int, int> bucket;

        for (int i = 0; i < nums.size(); i++) {
            if (bucket.find(nums[i]) != bucket.end()) {
                ret.push_back(bucket[nums[i]]);
                ret.push_back(i);
                break;
             }
            bucket[target - nums[i]] = i;
        }

        return ret;

    }
};

int main()
{
    Solution sol;


    return 0;
}
