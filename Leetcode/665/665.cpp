class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return true;

        int pre = nums[0];
        int ppre = nums[1];
        int cap = 0;

        for (int i=1;i<n;i++){
        	if (nums[i]<pre){
        		if (++cap > 1){
        			return false;
        		}

        		if (nums[i] >= ppre){
        			pre = nums[i];
        		}
        	}
        	else{
        		ppre = pre;
        	  	pre = nums[i];
        	}
        }

        return true;
    }
};