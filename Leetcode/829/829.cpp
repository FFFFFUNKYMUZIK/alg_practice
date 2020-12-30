class Solution {
public:

	using ll = long long;

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
};