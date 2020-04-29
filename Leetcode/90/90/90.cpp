#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<vector<int>> ret;
    unordered_map<int, int> em;

    using mapit = unordered_map<int, int>::iterator;

    void backtrack(vector<int>& bucket, mapit it) {
        if (it == em.end()) {
            ret.push_back(bucket);
            return;
        }

        int size = bucket.size();
        int key = it->first;
        int cnt = it->second;
        it++;
        for (int i = 0; i <= cnt; i++) {
            backtrack(bucket, it);
            bucket.push_back(key);
        }
        bucket.resize(size);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>().swap(ret);
        vector<int> bucket;
        
        for (int i = 0; i < n; i++) em[nums[i]]++;

        backtrack(bucket, em.begin());
        
        return ret;
    }
};

int main()
{
    Solution sol;
    
    vector<vector<int>> ret;
    vector<int> in;

    in = vector<int>({1,2,2});
    ret = sol.subsetsWithDup(in);
       
    return 0;
}
