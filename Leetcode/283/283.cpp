class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int buc = 0;
        for (int i=0;i<nums.size();i++){
        	if (nums[i] != 0){
        		nums[buc] = nums[i];
        		if (i != buc) nums[i] = 0;
        		buc++;
        	}
        }
        return;
    }
};