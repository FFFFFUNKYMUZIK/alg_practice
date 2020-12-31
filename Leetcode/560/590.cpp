class Solution {
public:
	/* O(N*k) with DP */
	/* O(N) with hash */
    int subarraySum(vector<int>& nums, int k) {

    	unordered_map<int, int> psum;

    	int n = nums.size();
    	int sum = 0;
    	int cnt = 0;
    	psum[sum] = 1;
    	for (int i=0;i<nums.size();i++){
    		sum += nums[i];
    		if (psum.find(sum - k) != psum.end()){
    			cnt += psum[sum-k];
    		}
    		psum[sum]++;
    	}

    	return cnt;
    }
};