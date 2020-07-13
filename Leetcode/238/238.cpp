asdf
/*
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 0);
        
        int pmul=1, rpmul = 1;
        
        for (int i=n-1;i>=0;i--){
            ret[i] = rpmul;
            rpmul*=nums[i];
        }
        
        for (int i=0;i<n;i++){
            ret[i] *= pmul;
            pmul*=nums[i];
        }
        
        return ret;
    }
};