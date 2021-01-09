class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /* DP[i][j] = DP[i-1][j] + DP[i][j-c] */

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        sort(coins.begin(), coins.end());

        for (int i=0;i<coins.size();i++){
        	for (int j=coins[i];j<=amount;j++){
        		dp[j] += dp[j-coins[i]];
        	}
        }
        return dp[amount];
    }
};