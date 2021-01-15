class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();

        vector<int> psum(n+1, 0);

        for (int i=0;i<n;i++){
        	psum[i+1] = psum[i] + A[i];
        }

        vector<int> Ll(n - L + 1), Ml(n - M + 1);
        vector<int> Lr(n - L + 1), Mr(n - M + 1);
        int maxval = 0;
        for (int i=L-1;i<n;i++){
        	maxval = max(maxval, psum[i + 1] - psum[i + 1 - L]);
        	Ll[i - L + 1] = maxval;
        }
        maxval =0;
        for (int i=L-1;i<n;i++){
        	maxval = max(maxval, psum[n - i + L - 1] - psum[n - i - 1]);
        	Lr[n - i - 1] = maxval;
        }
        maxval =0;
        for (int i=M-1;i<n;i++){
        	maxval = max(maxval, psum[i + 1] - psum[i + 1 - M]);
        	Ml[i - M + 1] = maxval;
        }
        maxval =0;
        for (int i=M-1;i<n;i++){
        	maxval = max(maxval, psum[n - i + M - 1] - psum[n - i - 1]);
        	Mr[n - i - 1] = maxval;
        }

        maxval = 0;
    	for (int i=0;i <= n - M - L;i++){
    		maxval = max(maxval, Ll[i] + Mr[i+L]);
    		maxval = max(maxval, Ml[i] + Lr[i+M]);
    	}
    	return maxval;
    }
};