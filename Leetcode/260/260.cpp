/*
Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
        EOR of vector results in a^b 
        how to figure out a, b from a^b?
        
        a^b != 0 (otherwise a==b)
        
        split vector into two part with respect to lowest set bit of a^b ( = (a^b) & -(a^b))
        
            first set : a, x, x, y, y, ...
            second set : b, z, z, w, w, ... 
         
         exclusive or of first set : a
         exclusive or of first set : b
        */
        
        vector<int> ret;
        int n = nums.size();
        
        if (n<2) return ret;
        
        int tot = 0;
        
        for (int i=0;i<n;i++){
            tot^=nums[i];
        }
        
        int lbit = tot & -tot;
        
        int a=0, b=0;
        
        for (int i=0;i<n;i++){
            if (nums[i]&lbit){
                a^=nums[i];
            }
            else{
                b^=nums[i];
            }
        }
        
        ret.push_back(a);
        ret.push_back(b);
        
        return ret;
    }
};