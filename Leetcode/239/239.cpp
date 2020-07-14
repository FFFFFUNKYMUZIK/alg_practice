/*
Follow up:
Could you solve it in linear time?

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

using priority queue(max heap)-> O(NlogK)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n-k+1,0);
        
        deque<int> idxdeq;
        
        int i=0;
       
        for (;i<n;i++){
            while(!idxdeq.empty() && idxdeq.front() <= i-k ) idxdeq.pop_front();
            while(!idxdeq.empty() && nums[idxdeq.back()] <= nums[i] ) idxdeq.pop_back();
            idxdeq.push_back(i);
            if (i>=k-1) ret[i-k+1] = nums[idxdeq.front()];
        }
            
        return ret;
    }
};