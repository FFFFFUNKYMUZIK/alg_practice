class Solution {

	using ll = long long;
	using dphash = vector<unordered_map<ll, ll>>;

	dphash dp;
	int getdp(int i, ll val, vector<int>& nums, dphash &dp){
		if (i<0) return 0;
		if (dp[i].find(val) != dp[i].end()){
			return dp[i][val];
		}
		
		dp[i][val] = getdp(i-1, val - nums[i], nums, dp) +
					getdp(i-1, val + nums[i], nums, dp); 

		return dp[i][val];
	} 

public:

    int findTargetSumWays(vector<int>& nums, int S) {
    	int n = nums.size();
        dphash(n, unordered_map<ll,ll>()).swap(dp);

        dp[0][nums[0]]++;
	    dp[0][-nums[0]]++;

	    return getdp(n-1, S, nums, dp);
    }
};