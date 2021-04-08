/*
Follow up: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
    	int n = nums.size();

        int s = 0;
        int e = n-1;

        while(s<e){
        	int mid = (s+e)/2;

        	if (mid > 0 && nums[mid] == nums[mid - 1]){
        		if ((e - mid)%2){
        			s = mid + 1;
        		}
        		else{
        			e = mid - 2;
        		}
        	}
        	else if (mid < n-1 && nums[mid] == nums[mid + 1]){
        		if ((e - mid - 1)%2){
        			s = mid + 1;
        		}
        		else{
        			e = mid - 1;
        		}	
        	}
        	else{
        		return nums[mid];
        	}
        }
        return nums[s];
    }
};