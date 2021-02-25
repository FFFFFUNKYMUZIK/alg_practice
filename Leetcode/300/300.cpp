class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> bucket(1,-pow(10,4) - 1);
        int cnt = 1;

        for (int i=0;i<n;i++){
        	if (nums[i] > bucket[cnt - 1]){
        		bucket.push_back(nums[i]);
        		cnt++;
        	}
        	else{
        		auto it = lower_bound(bucket.begin(), bucket.end(), nums[i]);
        		*it = nums[i];
        	}
        }

        return cnt - 1;
    }
};