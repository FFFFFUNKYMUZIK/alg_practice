class Solution {
public:

	using ll = long long;
#if 0
	/* O(N) */
    int consecutiveNumbersSum(int N) {
        ll sum;
        int i,j;
        int ret = 1;

        i=1; j=0;
        sum = 0;
        while(sum<N) sum+=(++j);

        while(i!=j){
        	if (sum>N) {
        		sum -= i;
        		i++;
        	}
        	else if (sum<N){
        		sum += (j+1);
        		sum -= i;
        		i++;
        		j++;
        	}
        	else{
        		ret++;
        		sum-=i;
        		i++;
        	}
        }

        return ret;
    }
#else
	/* O(log2(N)) */
    int consecutiveNumbersSum(int N) {

    	/* (a+b)*(b-a+1) = 2*N */
    	/* a+b > b-a+1 where a>1 */
    	/* x*y = 2*N (x > y) */
    	/* a = (x-y+1)/2 */
    	/* b = (x+y-1)/2 */
    	int ret = 0;
    	int x,y;

        for (int i=1;i*i<2*N;i++){
        	if (2*N % i == 0){
        		x = 2*N/i;
        		y = i;

        		if ((x-y) % 2 == 1)
					ret++;
        	}
        }
        return ret;
    }
#endif
};
