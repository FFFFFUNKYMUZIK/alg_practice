/* 
Follow up:
Could you solve it in O(nk) runtime?
*/

#define MAX (0x7FFFFFFF)

class Solution {
public:

    int minCostII(vector<vector<int>>& costs) {

    	int n = costs.size();
    	if (n==0) return 0;
    	int k = costs[0].size();
    	if (k==0) return 0;

        int minval = 0, nextminval = 0;
        int minidx = -1;

        int minval_pre = 0, nextminval_pre = 0;
		int minidx_pre = -1;

        for (int i=0;i<n;i++){
        	minval = nextminval = MAX;
        	for (int j=0;j<k;j++){
        		int cur;
        		if (j != minidx_pre){
        			cur = minval_pre + costs[i][j];
        		}
        		else{
        			cur = nextminval_pre + costs[i][j];
        		}

        		if (cur <= minval){
        			nextminval = minval;

        			minval = cur;
        			minidx = j;
        		}
        		else if(cur <= nextminval){
        			nextminval = cur;
        		}
        	}

        	minval_pre = minval;
        	nextminval_pre = nextminval;
        	minidx_pre = minidx;
        }

        return minval;

    }
};