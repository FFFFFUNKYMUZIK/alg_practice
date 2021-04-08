class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

    	unordered_map<int, int> psum;
    	int n = nums.size();
    	int sum = 0;
    	psum[0] = -1;

    	for (int i=0;i<n;i++){
    		sum = (sum + nums[i]) % k;
    		if (psum.find(sum) != psum.end()){
    			if (psum[sum] != i-1){
    				return true;
    			}
    		}
    		else{
    			psum[sum] = i;
    		}
    	}
        
        return false;
    }
};