#if 0

class Solution {
public:
    int minSteps(int n) {
        /* cur / clip */
        /* clip = cur   copy */
        /* cur += clip  paste */
    	/* cur = 1 initially */

    	/* per step */
    	/* copy -> paste */
    	/* paste -> paste or copy */

    	/* dp(1,0) = 0 */
    	/* dp(1,1) = 1 */
    	/* copy : go to diagonal */

    	if (n==1) return 0;

    	vector<vector<int>> dp (n+1, vector<int>(n+1, n));
    	dp[1][1] = 1;
    	int minstep = n;

    	for (int j=1;j<=n/2;j++){
    		int fstep = dp[j][j];
    		for (int i = j+j;i<=n/2;i+=j){
    			dp[i][j] = ++fstep;
    			dp[i][i] = min(dp[i][i], fstep + 1);
    		}
    		if ((n-j) % j == 0){
    			minstep = min(minstep, dp[j][j] + (n-j)/j);
    		}
    	}

    	return minstep;
    }
};

#elif 0

class Solution {
public:
    int minSteps(int n) {
        
    	/* copy(denominator) -> paste -> paste -> ... -> paste */
    	/* copy(denom of denom) -> paste -> ... -> paste */
    	/* prime? : minimum step = prime; */
    	/* n = p * q then minimum step = p + q */
    	/* n = p * q * r then min step = (p + q) + r */
    	/* n = p1 * p2 * ... * pn then minstep = p1+p2+...+pn */

    	int minstep = 0;

    	vector<int> v(n + 1, 0);

    	for (int i=2;i*i<=n;i++){
    		if (v[i] == 0){
    			for (int j=i*i;j<=n;j+=i){
    				v[j] = 1;
    			}
    		}
    	}
    	for (int i=2;i<=n;i++){
    		while (n % i == 0){
    			n /= i;
    			minstep+=i;
    		}
    	}

    	return minstep;
    }
};
#else


class Solution {
public:
    int minSteps(int n) {
        
    	/* copy(denominator) -> paste -> paste -> ... -> paste */
    	/* copy(denom of denom) -> paste -> ... -> paste */
    	/* prime? : minimum step = prime; */
    	/* n = p * q then minimum step = p + q */
    	/* n = p * q * r then min step = (p + q) + r */
    	/* n = p1 * p2 * ... * pn then minstep = p1+p2+...+pn */

    	int minstep = 0;

    	int i = 2;
    	while (n > 1){
    		while(n%i == 0){
    			n /= i;
    			minstep += i;
    		}
    		i++;
    	}


    	return minstep;
    }
};

#endif