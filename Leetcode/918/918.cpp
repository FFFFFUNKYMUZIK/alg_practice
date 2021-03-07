class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
    	int n = A.size();
    	
    	int psum = 0;
    	int maxsum = A[0];
    	int sum = 0;
    	int rmax = A[n-1];

    	for (int i=0;i<n;i++){
    		psum += A[i];
    		sum += A[i];

    		maxsum = max(maxsum, psum);
    		psum = max(psum, 0);
    	}

    	psum = 0;
    	if (n<=2) return maxsum;

    	sum = sum - A[n-1] - A[n-2];
    	for (int i=n-1;i>1;i--){
    		psum += A[i];
    		rmax = max(rmax, psum);
    		maxsum = max(maxsum, sum + rmax);
    		sum -= A[i-2];
    	}


    	return maxsum;
    }
};