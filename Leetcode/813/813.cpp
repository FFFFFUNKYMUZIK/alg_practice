class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();

        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0));

        double sum = 0;
        for (int i=1;i<=n;i++){
        	sum += A[i-1];
        	dp[i][1] = sum/i;
        }

        /* dp(i,j) = max(dp(i-1, j-1) + A[i],
        				 dp(i-2, j-1) + (A[i] + A[i-1])/2,
        				 dp(i-3, j-1) + (A[i] + A[i-1] + A[i-2])/3, ...,
        				 dp(i-k, j-1) + (A[i] + ... + A[i-k+1])/k, ...,
        				 dp(j-1, j-1) + (A[i] + ... + A[j])/(i-j+1)); */

        double maxval;
        for (int j=2;j<=K;j++){
        	for (int i=j;i<=n;i++){
        		sum = 0;
        		maxval = 0;
        		for (int k=i-1;k>=j-1;k--){
        			sum += A[k];
        			maxval = max(maxval, dp[k][j-1] + sum/(i-k));
        		}
        		dp[i][j] = maxval;
        	}
        }

        return dp[n][K];
    }
};