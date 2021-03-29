class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /* sort the array and rearrange like [arr[n/2], arr[n/2+1], arr[n/2-1], ..., ), O(nlogn)*/
    	bool des = false;
    	int n = nums.size();
    	int pre = nums[0];

    	auto swap = [](int &a, int &b){
    		int tmp = a;
    		a = b;
    		b = tmp;
    	};

    	for (int i = 1;i < n;i++){
    		if (des){
    			if (pre < nums[i]){
    				swap(nums[i-1], nums[i]);
    			}
    		}
    		else{
    			if (pre > nums[i]){
    				swap(nums[i-1], nums[i]);
    			}
    		}
    		des = !des;
    		pre = nums[i];
    	}

    	return;
    }
};