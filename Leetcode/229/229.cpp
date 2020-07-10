/*
Note: The algorithm should run in linear time and in O(1) space.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        
        int len = nums.size();
        if (len==0) return ret;
        
        int thr = len/3;
        
        int cand1=0, cand2=0;
        int cnt1=0, cnt2=0;
        
        for (int i=0;i<len;i++){
        
            if (cand1==nums[i]) cnt1++;
            else if (cand2==nums[i]) cnt2++;
            else {
                if (cnt1==0){
                    cand1=nums[i];
                    cnt1++;
                }
                else if (cnt2==0){
                    cand2=nums[i];
                    cnt2++;
                }
                else{
                    cnt1--;cnt2--;
                }
            }
        }
        
        vector<int> cand;
        if (cnt1>0) cand.push_back(cand1);
        if (cnt2>0) cand.push_back(cand2);
        vector<int> cnt(cand.size(),0);
        
        for (int i=0;i<len;i++){
            for (int j=0;j<cand.size();j++){
                if (nums[i]==cand[j]) cnt[j]++;
            }
        }
        
        for (int j=0;j<cand.size();j++){
            if (cnt[j]>thr) ret.push_back(cand[j]);
        }
        
        return ret;
    }
};