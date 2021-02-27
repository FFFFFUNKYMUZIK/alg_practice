class Solution {
public:
    int triangleNumber(vector<int>& nums) {

    	sort(nums.begin(), nums.end(), less<int>());

    	int n = nums.size();
    	int sum = 0;

    	for (int i=0;i<n-2;i++){
    		int shortest = nums[i];
    		for (int j=i+1, k=i+2;j<n-1;j++){
    			if (j==k) k++;
    			else if (j<k){
    				sum += (k - j - 1);
    			}

    			while (k<n && (shortest + nums[j] > nums[k])){
    				k++;
    				sum++;
    			}
    		}
    	}

    	return sum;
    }
};