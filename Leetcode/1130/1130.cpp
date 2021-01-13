class Solution {

#if 0
	typedef struct el_t{
		int val;
		int maxval;
	} el;

	using vvel = vector<vector<el>>;

	el getdp(int s, int e, vvel& dp, vector<int>& arr){
		if (dp[s][e].val != -1)
			return dp[s][e];

		el& res = dp[s][e];

		el left, right;

		int mintreeval = INT_MAX;
		int rangemax = arr[s];

		for (int i=s;i<e;i++){
			left = getdp(s, i, dp, arr);
			right = getdp(i+1, e, dp, arr);

			mintreeval = min(mintreeval, left.val + right.val + left.maxval * right.maxval);
			rangemax = max(rangemax, arr[i]);
		}

		rangemax = max(rangemax, arr[e]);

		res = {mintreeval, rangemax};

		return res;
	}

public:

    int mctFromLeafValues(vector<int>& arr) {
        /* if arr divide into 2 part(arr1, arr2) then the node value is max(arr1)*max(arr2) */
    	/* O(3^N) for brute force */
    	/* O(N^3) for DP */

    	int n = arr.size();

    	vvel dp(n, vector<el>(n, {-1, 0}));

    	for (int i=0; i<n;i++){
    		dp[i][i] = {0, arr[i]};
    	}

    	el res = getdp(0, n-1, dp, arr);

    	return res.val;
    }

    #else


/* reference : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space */
/* O(N) brilliant solution */
/*
	The problem can translated as following:
	Given an array A, choose two neighbors in the array a and b,
	we can remove the smaller one min(a,b) and the cost is a * b.
	What is the minimum cost to remove the whole array until only one left?
*/

public:

    int mctFromLeafValues(vector<int>& arr) {

    	int n = arr.size();
    	stack<int> st;
    	int cost = 0;

    	for (int i=0;i<n;i++){
    		int s = arr[i];
    		while(!st.empty() && st.top() <= s){
    			int p = st.top();
    			st.pop();
    			if (st.empty())
    				cost += s * p;
    			else
    				cost += (min(s, st.top())) * p;
    		}
    		st.push(s);
    	}

    	int p = 0;
    	while (!st.empty()){
    		cost += p*st.top();
    		p = st.top();
    		st.pop();
    	}

    	return cost;
    }
    #endif
};