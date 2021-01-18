class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;

        int tmp;
        int i=0;
        while(i<n){
        	tmp = nums[i];
        	if (tmp == i + 1 || tmp == 0){
        		i++;
        		continue;
        	}

        	if (nums[tmp - 1] == tmp){
        		nums[i] = 0;
        		i++;
        		continue;
        	}

        	nums[i] = nums[tmp - 1];
        	nums[tmp - 1] = tmp;
        }

        for (int i=0;i<n;i++){
        	if (nums[i]==0) ret.push_back(i+1);
        }
        return ret;
    }
};