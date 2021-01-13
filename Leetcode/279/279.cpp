class Solution {
public:
    int numSquares(int n) {
        int sq = sqrt(n);

        vector<int> dp(n + 1, 0);

        for (int i=1;i<=n;i++){
        	int j = 1;

        	int minval = i;

        	while(i-j*j>=0){
        		minval = min(minval, dp[i-j*j] + 1);
        		j++;
        	}
        	dp[i] = minval;
        }

        return dp[n];
    }
};