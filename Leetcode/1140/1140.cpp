class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        /* dp(i,j) : max profit with piles[i:] and M=j */
        /* dp(i,j) = max(
        				 sum(piles[i:]) - dp(i+1, max(j, 1)),
						 sum(piles[i:]) - dp(i+2, max(j, 2)),
						 ...,
						 sum(piles[i:]) - dp(i+2*j, max(j, 2*j))
						 )
					= sum(piles[i:]) - min(dp(i+1,), ...) */
		/* dp(n, j) = 0 */
		/* dp(n-1, j) = piles[n-1] */
		/* answer : dp(0, 1); */
		/*			dp(1, 1) dp(2, 2) */


        int n = piles.size();
        vector<int> rpsum(n, 0);
        rpsum[n-1] = piles[n-1];
        for (int i=n - 2;i>=0;i--){
        	rpsum[i] = rpsum[i+1] + piles[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i=n-1;i>=0;i--){
        	for (int j=1;j<=i+1;j++){
        		int minval = INT_MAX;
        		for (int k=1;i+k<=n && k<=2*j;k++){
        			minval = min(minval, dp[i+k][max(j, k)]);
        		}
        		dp[i][j] = rpsum[i] - minval;
        	}
        }

        return dp[0][1];
    }
};