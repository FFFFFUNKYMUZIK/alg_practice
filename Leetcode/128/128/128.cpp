#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Your algorithm should run in O(n) complexity.
*/

#if 0

//not O(N)...
class Solution {
public:
    unordered_map<int, int> p;

    int find_(int x) {
        if (p.find(x) == p.end()) return x;
        if (p[x] == x) return x;

        return p[x] = find_(p[x]);
    }
       
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;

        unordered_map<int, int>().swap(p);

        for (int i = 0; i < N; i++) {
            p[nums[i]] = nums[i] - 1;
        }

        //not O(N)...
        int maxlen = 0;
        for (int i = 0; i < N; i++) {
            maxlen = max(maxlen, nums[i] - find_(nums[i]));
        }

        return maxlen;
    }
};

#elif 1


class Solution {
public:
    unordered_map<int, int> p;

    int find_(int x) {
        if (p.find(x) == p.end()) return x;
        if (p[x] == x) return x;

        return p[x] = find_(p[x]);
    }

    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;

        unordered_map<int, int>().swap(p);

        for (int i = 0; i < N; i++) {
            p[nums[i]] = nums[i] - 1;
        }

        int maxlen = 0;
        for (int i = 0; i < N; i++) {
            if (p.find(nums[i] + 1) != p.end()) continue;
            maxlen = max(maxlen, nums[i] - find_(nums[i]));
        }

        return maxlen;
    }
};

#else

#include <unordered_set>
//reference solution, 4ms
//O(2*N*hash) = O(N), but...

class Solution {
    
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        for (int num : nums)
            nums_set.insert(num);
        int max_count = 0;
        for (int num : nums_set)
        {
            if (nums_set.find(num - 1) != nums_set.end()) continue;
            int current_num = num;
            int current_count = 1;
            while (nums_set.find(current_num + 1) != nums_set.end())
            {
                current_count++;
                current_num++;
            }
            max_count = std::max(current_count, max_count);
        }
        return max_count;
    }
};


#endif


int main()
{

    Solution sol;
    vector<int> in;

    in = vector<int>({100,4,200,1,3,2});
    int ret = sol.longestConsecutive(in);

    return 0;
}
