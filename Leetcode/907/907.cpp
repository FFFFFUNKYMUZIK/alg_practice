class Solution {

	#define MOD (1000000007LL)

public:
    int sumSubarrayMins(vector<int>& arr) {
    	int n = arr.size();

        using ll = long long;
        using el = struct {
        	int val;
        	int idx;
        };

        ll minsum = 0;
        stack<el> st;
        vector<int> dp(n + 1, 0);

        for (int i=0;i<n;i++){
        	while(!st.empty() && st.top().val >= arr[i]){
        		st.pop();
        	}

        	int idx = -1;
        	if (!st.empty()) idx = st.top().idx;

        	dp[i + 1] = ((i - idx) * arr[i] % MOD + dp[idx + 1]) % MOD;
        	minsum = (minsum + dp[i+1])%MOD;
        	st.push({arr[i], i});

        }

        return minsum;
    }
};