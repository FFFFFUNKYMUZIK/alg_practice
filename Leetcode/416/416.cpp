class Solution {

	#define MSUM 10000

public:
    bool canPartition(vector<int>& nums) {
    	/* backtrack, hash : O(2^n) */
    	/* max sum = 200 * 100 = 20000, max half sum = 10000 */
    	/* DP(i, k) = true if can find subsets from arr[0...i] such that sums up to k */
 		/* DP(i, k) = DP(i-1, k-arr[i]) || DP(i-1, k) */
 		/* DP(i, 0) = 1; */
 		
 		int n = nums.size();
 		int sum = 0;
    	vector<vector<int>> dp(n, vector<int>(MSUM + 1, 0));

    	dp[0][0] = 1;
    	dp[0][nums[0]] = 1;
    	for (int i=0;i<n;i++){
    		sum += nums[i];
    	}

    	if (sum&1) return false;
    	if (nums[0] == sum/2) return true;

    	for (int i=1;i<n;i++){
    		dp[i][0] = 1;
    		for (int j=1;j<=sum/2;j++){
    			if (j - nums[i] >= 0) dp[i][j] = dp[i-1][j - nums[i]];
    			dp[i][j] |= dp[i-1][j];
    		}
    		if (dp[i][sum/2]) return true;
    	}

    	return !!dp[n-1][sum/2];
    }
};