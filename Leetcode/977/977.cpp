class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
 		int n = nums.size();

 		int l = -1,r = n;

 		for (int i=0;i<nums.size();i++){
 			if (nums[i] < 0) l = i;
 			if (nums[i] > 0){
 				r = i;
 				break;
 			}
 		}

 		int zeros = r - l - 1;

 		vector<int> ret(n, 0);
 		int i = zeros;
 		int sqmax = max(nums[0]*nums[0], nums[n-1] * nums[n-1]);
 		
 		int lsq, rsq;
 		while(i<n){
 			lsq = rsq = sqmax;

 			if (l>=0) lsq = nums[l]*nums[l];
 			if (r<n) rsq = nums[r]*nums[r];

 			if (lsq<rsq){
 				ret[i] = lsq;
 				l--;
 			}
 			else{
				ret[i] = rsq;
 				r++;
 			}

 			i++;
 		}

 		return ret;
    }
};