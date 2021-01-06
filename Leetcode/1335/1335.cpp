class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
		int n = jobDifficulty.size();

		if (d > n) return -1;

		/* DP(i,j) : minimum difficulty sum where last cut at ith number and j cuts remain */
		/* where n-i >= j and j<=d and i+j >= d */
		/* so d <= i+j <= n and j<=d */
		/* DP(i,j) = min(DP(d - j - 1 , j+1) + max(d-j-1 ~ i-1), DP(d - j + 1, j+1) + max(d-j+1~i-1), ... , DP(i-1, j+1) + max(i-1 ~ i-1)) */
		/* get DP(n, 0) */
		/* DP(0, d) = 0 */

		vector<int> pre(n - d + 1, 0);
		vector<int> cur(n - d + 1, 0);

		int rangemax = jobDifficulty[0];

		/* fill initial value in column where j = d-1 */
		for (int i=0;i<n-d+1;i++){
			if (jobDifficulty[i] > rangemax){
				rangemax = jobDifficulty[i];
			}

			pre[i] = rangemax;
		}

		int dpmin = 0;

        /* O(n*n*d) */
		for (int j = d-2;j>=0;j--){
			for (int i=0;i<n-d+1;i++){
				rangemax = jobDifficulty[d - j + (i - 1)];
				dpmin = rangemax + pre[i];
                
				for (int k=i;k>=0;k--){
					if (jobDifficulty[d - j + (k - 1)] > rangemax){
						rangemax = jobDifficulty[d - j + (k - 1)];
					}
					if (pre[k] + rangemax < dpmin){
						dpmin = pre[k] + rangemax;
					}
				}
				cur[i] = dpmin;				
			}

			pre.swap(cur);
		}

		return pre[n-d];
    }
};