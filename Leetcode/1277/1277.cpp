class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        /* dp[i][j] = how many square submatrix from matrix[0][0] ~ matrix[i][j] */
        /* dp[i+1][j+1] = (num of squares end at i+1,j+1) + dp[i][j+1] + dp[i+1][j] - dp[i][j] */

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));

        #define RS(v, i, j, s) (v[(i)][(j)] - v[(i)][(j)-(s)] - v[(i)-(s)][(j)] + v[(i)-(s)][(j)-(s)])
        for (int i=0;i<n;i++){
        	for (int j=0;j<m;j++){
        		sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (matrix[i][j] == 1);
        		int k;
        		for (k=1;k<=min(i,j) + 1 ;k++){
        			if (RS(sum, i+1, j+1, k) != k*k) break;
        		}
        		dp[i+1][j+1] = (k-1) + dp[i][j+1] + dp[i+1][j] - dp[i][j];
        	}
        }

        return dp[n][m];

    }
};