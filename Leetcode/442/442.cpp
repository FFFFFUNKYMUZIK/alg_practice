class Solution {
public:
	/* Could you do it without extra space and in O(n) runtime? */

    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ret;
        int n = nums.size();
        int i=0;

        while(i<n){
        	if (nums[i]==i + 1 || nums[i] == 0){
        		i++;
        	}
        	else{
        		if (nums[nums[i] - 1] == nums[i]){
        			nums[nums[i] - 1] = 0;
        			ret.push_back(nums[i]);
        		}
        		else if (nums[nums[i] - 1] == 0){
        			i++;
        		}
        		else{
        			int tmp = nums[i];
        			nums[i] = nums[tmp - 1];
        			nums[tmp - 1] = tmp;
        		}
        	}
        }

        return ret;
    }
};