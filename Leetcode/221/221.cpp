class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        if(m==0) return 0;
        
        vector<int> dp(m, 0);
        
        int maxside = 0;
        
        for (int i=0;i<n;i++){
            int tmp = dp[0];
            int tmp2;
            dp[0] = matrix[i][0] - '0';
            if (dp[0]>maxside) maxside = dp[0];
            for (int j=1;j<m;j++){
                
                if (matrix[i][j]=='1'){
                    tmp2 = min(tmp,dp[j-1]);
                    tmp = dp[j];
                    dp[j] = min(tmp2, dp[j]) + 1;
                    if (dp[j]>maxside) maxside = dp[j];
                }
                else{
                    dp[j] = 0;   
                }
            
            }
        }
        
        return maxside*maxside;
    }
};