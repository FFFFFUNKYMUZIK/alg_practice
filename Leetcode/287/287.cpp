class Solution {
public:
	#if 0
    int findDuplicate(vector<int>& nums) {
    	/* hashmap O(N)/O(N)*/

    	int n = nums.size()-1;
    	vector<int> hash(n+1, 0);

    	for (int i=0;i<=n;i++){
    		if (hash[nums[i]])
    			return nums[i];

    		hash[nums[i]] = 1;
    	}

    	return -1;
    }

	#else
    int findDuplicate(vector<int>& nums) {
    	/* manipulate nums (space complexity O(1))*/

    	int n = nums.size()-1;

    	int i=1;
    	int tmp;
    	while(i<=n){
    		tmp = nums[i];
    		if (tmp != i){
    			if (nums[tmp] == nums[i])
    				return nums[i];
    			nums[i] = nums[tmp];
    			nums[tmp] = tmp;
    			continue;
    		}

    		i++;
    	}

    	return nums[0];
    }
    #endif
};