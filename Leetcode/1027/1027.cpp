class Solution {
public:

	#define MAXSTEP 500
    int longestArithSeqLength(vector<int>& A) {
        int len = A.size();

        /* naive : O(N^3) */
        /* DP(i, s) = longest arithmetic subsequence in A[0...i] such that have step s and ends at A[i] */
        
        vector<vector<int>> dp(len, vector<int>(2 * MAXSTEP + 1, -1));

        int maxlen = 0;

        for (int i=0;i<len;i++){
        	for (int j=0;j<i;j++){

        		int d = A[i] - A[j] + 500;
        		if (dp[j][d] == -1){
        			dp[i][d] = 2;
        		}
        		else{
        			dp[i][d] = dp[j][d] + 1;
        		}

        		maxlen = max(maxlen, dp[i][d]);
        	}
        }

        return maxlen;
    }
};