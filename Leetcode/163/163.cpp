class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();
        
        vector<string> ret;
        
        long long low = lower, up = upper;
        
        for (int i=0;i<n;i++){
            if (nums[i]>low){
                ret.push_back(to_string(low));
                if (low + 1<nums[i]){
                    ret.back()+="->"+to_string(nums[i]-1);
                }
                low = (long long)nums[i]+1;
            }
            else if (nums[i]==low){
                low++;
            }
        }        
        
        
        if (low<up){
            ret.push_back(to_string(low) + "->" + to_string(up));
        }
        else if (low==up){
            ret.push_back(to_string(low));
        }
                
        return ret;
    }
};