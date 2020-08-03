class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        
        if (n==0) return 0;
        
        
        vector<int> dp(3, 0);
        
        for (int i=0;i<n;i++){
            vector<int> pdp(3, 0);
        
            pdp[0] = costs[i][0] + min(dp[1],dp[2]);
            pdp[1] = costs[i][1] + min(dp[0],dp[2]);
            pdp[2] = costs[i][2] + min(dp[0],dp[1]);
        
            dp = move(pdp);
        }
        
        return min(min(dp[0], dp[1]), dp[2]);
        
    }
};