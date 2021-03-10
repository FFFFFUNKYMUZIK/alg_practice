class Solution {

#define MOD 1000000007LL

public:
    int waysToSplit(vector<int>& nums) {
        
        /* brute force : O(N^2) */
        /* consider A[0], ..., A[i] which Sum(0~i) <= Sum * 2/3 */
        /* divide into two partition so that Sum(0~j) <= Sum(j~i) */

    	int n = nums.size();

    	vector<int> vpsum(n+1, 0);
    	int psum = 0;

    	for (int i=0;i<n;i++){
    		psum += nums[i];
    		vpsum[i+1] = psum;
    	}

    	int cnt = 0;

    	for (int i=1;i<n && vpsum[i+1] <= (psum * 2)/3;i++){
    		int pos1 = upper_bound(vpsum.begin() + 1, vpsum.begin() + i + 1, (vpsum[i+1]/2)) - (vpsum.begin() + 1);
    		int pos2 = lower_bound(vpsum.begin() + 1, vpsum.begin() + i + 1, psum - vpsum[i+1]) - (vpsum.begin() + 1);
    		cnt = (cnt + pos1 - pos2) % MOD;
    	}

    	return cnt;
    }
};