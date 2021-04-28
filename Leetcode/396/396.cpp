class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        /* 0   1 2 3 ... n-3 n-2 n-1 */
        /* 1   2 3 ...   n-2 n-1 0 */
        /* 2   3 4 ...   n-1 0   1 */
        /* ... */
		/* k   k+1 k+2 ...   n-1 0 1 2 ... k-1  k */
		/* k+1 k+2   ... n-1 0   1 2 3 ... k    k+1 */
        /* ... */
        /* n-1 0 1 2 ... n-4 n-3 n-2 */

        long long sum = 0;
        long long Fsum = 0;
        vector<long long> psum(n, 0);

        for (int i=0;i<n;i++){
        	Fsum += (i * nums[i]);
        	sum += nums[i];
        	psum[i] = sum;
        }

        long long maxFsum = Fsum;
        for (int i=1;i<n;i++){
        	Fsum += (psum[n - i - 1] - nums[n-i] * (n-1) + (psum[n-1] - psum[n-i]));
        	maxFsum = max(Fsum, maxFsum);
        }

        return maxFsum;
    }
};