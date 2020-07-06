class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> bucket;
            
        int cnt = 1;
        int trace = 0;
        for (int i=0;i<nums.size();i++){
            if (cnt>k+1){
                auto it = bucket.find(nums[trace]);
                bucket.erase(it);
                trace++;
                cnt--;
            }
                        
            auto it = bucket.insert(nums[i]);
            if (it!=bucket.begin() && (*it - *(prev(it))) <=t ) return true;    
            if (it!=prev(bucket.end()) && (*(next(it)) - *(it)) <=t ) return true;
                
            cnt++;
        }
        
        return false;
    }
};
