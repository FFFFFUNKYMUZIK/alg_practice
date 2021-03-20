class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int maxlen = K;

        int i = 0;
        int zero = K;
    	for (int j=0;j<n;j++){
    		if (A[j] == 0){
    			if (zero) zero--;
    			else{
    				while(i<j && A[i]==1){
    					i++;
    				}
    				i++;
    			}
    		}
    		maxlen = max(maxlen, j - i + 1);
    	}

    	return maxlen;

    }
};