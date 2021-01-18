class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size();

    	int poscnt = 0;
    	for (int i=0;i<n;i++){
    		if (nums[i]>0){
    			poscnt = n - i;
    			break;
    		}
    	}

    	int ret = 0;
    	if (poscnt == 0){
    		ret = nums[n-1]*nums[n-2]*nums[n-3];
    	}
    	else if (poscnt <= 2){
    		ret = nums[n-1]*nums[0]*nums[1];
    	}
    	else{
    		ret = max(nums[n-1]*nums[0]*nums[1], nums[n-1]*nums[n-2]*nums[n-3]);
    	}

        
        return ret;
    }
};