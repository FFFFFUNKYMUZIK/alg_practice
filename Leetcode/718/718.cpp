class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
    	int alen = A.size();
    	int blen = B.size();

        vector<vector<int>> dp(alen, vector<int>(blen, 0));

        int ret = 0;

        for (int i=0;i<alen;i++){
        	dp[i][0] = (A[i] == B[0] ? 1 : 0);
        	ret = max(ret, dp[i][0]);
        }

        for (int j=0;j<blen;j++){
        	dp[0][j] = (A[0] == B[j] ? 1 : 0);
        	ret = max(ret, dp[0][j]);
        }

        for (int i = 1;i<alen;i++){
        	for (int j = 1; j<blen; j++){
        		dp[i][j] = (A[i] == B[j] ? dp[i-1][j-1] + 1 : 0);
        		ret = max(ret, dp[i][j]);
        	}
        }

    	return ret;
    }
};