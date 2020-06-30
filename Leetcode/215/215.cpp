#if 0

//std sort O(NlogN)
//What's the point?
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        return nums[k-1];
    }
};

#elif 1

//min heap
//O(NlogK)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int> >pq;
        int i;
        for (i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(;i<nums.size();i++){
            if (pq.top()<nums[i]){
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};


#endif