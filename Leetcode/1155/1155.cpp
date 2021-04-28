class Solution {

#define MOD (1000000007LL)
using ll = long long;

public:
    int numRollsToTarget(int d, int f, int target) {
    	if (d*f < target) return 0;

    	vector<ll> bucket(target + 1, 0);
    	for (int i=1;i<=f && i <= target;i++) bucket[i] = 1;

    	/* O(d*f*t) */
    	for (int i=0;i<d - 1;i++){
    		vector<ll> tmp(target + 1, 0);
    		for (int j=1;j<=target;j++){
    			for (int k=1;k <= f && j + k<=target;k++){
    				tmp[j+k] = (tmp[j+k] + bucket[j]) % MOD;
    			}
    		}
    		tmp.swap(bucket);
    	}
        return bucket[target];
    }
};