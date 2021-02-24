class Solution {

#define DIVUP(m,n) ((m) + ((n)-1))/(n)

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    	int n = nums.size();

        int s = 1;
        int e = pow(10,6);
        int mid;

        while(s<e){
        	mid = (s + e)/2;

        	if ([&nums](int div){
	        		int sum = 0;
	        		for (int i=0;i<nums.size();i++){
	        			sum += DIVUP(nums[i],div);
	        		}
        			return sum;
        		}(mid) > threshold){
        		s = mid + 1;
        	}
        	else{
				e = mid;        		
        	}
        }

        return e;
    }
};