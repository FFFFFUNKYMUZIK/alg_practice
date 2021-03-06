/*
Follow up: Can you find a logarithmic time complexity (i.e., O(log(n))) solution?
*/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();

        int s = 0, e = n-1;

        auto me_counter = [](vector<int>& nums, int idx){
        	return nums[idx] - nums[0] - idx;
        };

        while(s<e){
        	int mid = (s + e + 1)/2;

        	if (me_counter(nums, mid)<k){
        		s = mid;
        	}
        	else{
        		e = mid - 1;
        	}
        }

        return nums[0] + k + s;
    }
};

