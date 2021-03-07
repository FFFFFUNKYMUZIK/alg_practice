class Solution {
public:
    vector<int> countBits(int num) {
    	/* brute force : O(n * bits of int)) */
    	/* 0 1 | 2 3 | 4 5 6 7 | 8 9 10 11 12 13 14 15 | 16 17 ... */
    	/* 0 1 | 1 2 | 1 2 2 3 | 1 2  2  3  2  3  3  4 | 1  2 ... */
    	/* 2^n-1 2^n  2^n+1  ...  2^(n+1) */
    	/*     k   1    1+1 		 1+k  */

    	vector<int> ret(num+1, 0);
    	ret[0] = 0;
    	
    	int s = 1;
    	int pow2 = 1;

    	for (int i=1;i<=num;i++){
    		if (i==pow2){
    			ret[i] = 1;
    			pow2 *= 2;
    			s = 1;
    			continue;
    		}

    		ret[i] = ret[s++]+1;
    	}
    
    	return ret;
    }
};