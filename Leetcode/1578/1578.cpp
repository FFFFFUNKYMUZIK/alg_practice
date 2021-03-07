class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.length();

        char pre = ' ';
        int prelen = 0;
        s += ' ';
        cost.push_back(0);
        int mincost = 0;
        int local_maxcost = 0;
        int costsum = 0;

        for (int i=0;i<=n;i++){
        	if (s[i] != pre){
        		if (prelen > 1){
        			mincost += (costsum - local_maxcost);
        		}
        		pre = s[i];
        		prelen = 1;
        		local_maxcost = cost[i];
        		costsum = cost[i];
        	}
        	else{
        		prelen++;
        		costsum += cost[i];
        		local_maxcost = max(local_maxcost, cost[i]);
        	}
        }

        cost.pop_back();

        return mincost;

    }
};