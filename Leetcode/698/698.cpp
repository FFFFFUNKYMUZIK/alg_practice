class Solution {
public:

	bool partition(vector<int>& nums, vector<int>& visit, int div, int part, int k, int from){
		if (div == part){
			k--;
			part = 0;
			from = 0;
		}
		if (k==1) return true;

		for (int i=from;i<nums.size();i++){
			if (visit[i] || div < part + nums[i]) continue;

			visit[i] = 1;
			if (partition(nums, visit, div, part+nums[i], k, i+1))
				return true;
			visit[i] = 0;

			if (part==0) break;
		}

		return false;
	}

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();

        int sum = 0;
        for (int i=0;i<n;i++){
        	sum += nums[i];
        }

        if (sum % k != 0) return false;
        int div = sum/k;

        vector<int> visit(n, 0);

        return partition(nums, visit, div, 0, k, 0);
    }
};