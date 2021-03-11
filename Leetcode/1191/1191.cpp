class Solution {

#define MOD 1000000007LL

public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

    	using ll = long long;

    	int n = arr.size();
    	ll psum = 0;
    	ll maxlpsum = 0;
    	ll maxrpsum = 0;
    	ll sum = 0;
    	ll maxsum = 0;

    	for (int i=0;i<n;i++){
    		sum += arr[i];
    		psum = psum+arr[i];
    		maxlpsum = max(maxlpsum, psum);
    		sum = max(sum, 0LL);
    		maxsum = max(maxsum, sum);
    	}

    	maxsum = max(maxsum, k * psum);

    	if (k==1) return maxsum;

    	psum = 0;
    	for (int i=n-1;i>=0;i--){
    		psum = psum + arr[i];
    		maxrpsum = max(maxrpsum, psum);
    	}

    	maxsum = max(maxsum, maxlpsum + maxrpsum + (k-2)*psum);
        maxsum = max(maxsum, maxlpsum + maxrpsum);

    	return maxsum % MOD;
    }
};