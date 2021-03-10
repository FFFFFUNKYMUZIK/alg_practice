class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        /* hash : O(2^n) */
        /* brute force : O(n^3) */
        /* first two elements in fibnacci define exact distinct sequence */

#if 0
/* T.L.E */
    	using ll = long long;

    	int n= arr.size();
    	int maxseq = 0;

    	for (int i=0;i<n;i++){
    		for (int j=i+1;j<n;j++){
    			int maxlen = 2;
    			ll next = arr[i]+arr[j];
    			ll nnext = arr[j]+next;
    			ll tmp;
    			for (int k=j+1;k<n;k++){
    				if (arr[k] == next){
    					maxlen++;
    					tmp = next;
    					next = nnext;
    					nnext = tmp + next;
    				}
    			}

    			if (maxlen > 2){
    				maxseq = max(maxseq, maxlen);	
    			}
    		}
    	}

    	return maxseq;

#else

    	using ll = long long;

    	int n= arr.size();
    	int maxseq = 0;
    	unordered_set<int> bucket(arr.begin(), arr.end());

    	for (int i=0;i<n;i++){
    		for (int j=i+1;j<n;j++){
    			int maxlen = 2;
    			ll next = arr[i]+arr[j];
    			ll nnext = arr[j]+next;
    			ll tmp;
    			while(bucket.find(next) != bucket.end()){
   					maxlen++;
   					tmp = next;
   					next = nnext;
  					nnext = tmp + next;
    			}

    			if (maxlen > 2){
    				maxseq = max(maxseq, maxlen);	
    			}
    		}
    	}

    	return maxseq;

#endif

    }
};