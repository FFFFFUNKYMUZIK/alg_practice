class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    	/* dp[i] = max(dp[i-1] + arr[i], dp[i-2] + 2*max(arr[i], arr[i-1], ...) */

        long long sum;

        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i=0;i<n;i++){
        	int rmsum = 0;
        	int rmax = 0;
        	for (int j=i;j>=0 && i-j+1 <= k;j--){
        		rmax = max(rmax, arr[j]);
        		rmsum = max(rmsum, dp[j] + rmax * (i-j+1));
        	}
        	dp[i+1] = rmsum;
        }

        return dp[n];
    }
};