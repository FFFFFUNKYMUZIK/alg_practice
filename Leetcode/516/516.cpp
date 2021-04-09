class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	/* dp[i+1][j-1], dp[i][j-1], dp[i+1][j] */
    	/* i<=j, dp[i][i] = 1 */
    	/* dp[i][i+1] = s[i]==s[j];
     	/* dp[i][j] =  dp[i+1][j-1] + 2  if (s[i]==s[j])
     				   dp[i+1][j-1] + 1  else if (dp[i][j-1] > dp[i+1][j-1] || dp[i+1][j] > dp[i+1][j-1])
     				   dp[i+1][j-1]		 else
     	*/
    	/* 
    		i o
    		i i
    	*/
    	int n = s.length();

    	vector<vector<int>> dp(n, vector<int>(n, 0));

    	for (int i=n-1; i>=0;i--){
    		dp[i][i] = 1;
    		for (int j=i+1;j<n;j++){
    			if(s[i]==s[j]){
    				dp[i][j] = dp[i+1][j-1] + 2;
    			}
    			else {
    				dp[i][j] = max(max(dp[i+1][j-1], dp[i][j-1]), dp[i+1][j]);
    			}
    		}
    	}

    	return dp[0][n-1];

    }
};