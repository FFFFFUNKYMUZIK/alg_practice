class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int len = nums.size();
        if (len==0) return ret;
        
        long long s = nums[0];
        long long next = s + 1;
        int cnt = 0;
        ret.push_back(to_string(s));
        nums.push_back(0);
        
        for (int i=1;i<=len;i++){
            
            if (nums[i]>next || i==len){
                if (next != s+1){
                    ret[cnt]+="->" + to_string(next-1);
                }
                s=nums[i];
                next=s+1LL;
                ret.push_back(to_string(s));
                cnt++;
            }
            else{ //nums[i]==next
                next++;                
            }
        }
        
        ret.pop_back();
        
        return ret;
    }
};