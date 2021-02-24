class Solution {

	#define DAY_PER_YEAR 365
	
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /* 1, 7, 30 days */

        int n = days.size();
        int cost = 0;
        vector<int> dp(DAY_PER_YEAR, 0);
        int j = n-1;
        if (days[j] == dp.size()){
        	cost = min(costs[0], min(costs[1], costs[2]));
        	dp[dp.size() - 1] = cost;
        	j--;
        }

        for (int i=dp.size() - 2;i>=0;i--){
        	if ((i+1) == days[j]){

        		cost = costs[0] + dp[i+1];
        		if (i + 7 < dp.size()){
        			cost = min(cost, costs[1] + dp[i+7]);
        		}
        		if (i + 30 < dp.size()){
        			cost = min(cost, costs[2] + dp[i+30]);
        		}

        		if (--j < 0)
        			break;
        		
        	}

        	dp[i] = cost;
        }

        return cost;
    }
};