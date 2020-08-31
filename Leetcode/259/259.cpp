/* Follow up: Could you solve it in O(n2) runtime? */

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        int n = nums.size();
        int cnt = 0;
        
        if (n<3) return cnt;
        
        //O(nlogn)
        std::sort(nums.begin(), nums.end());
        
        int i, j, k;
        
        
        //O(n^2)
        int first, sum;
        for (i=0;i<n-2;i++){
            first = nums[i];
            j = i+1;
            k = n-1;
            
            while(j<k){
                sum = first + nums[j] + nums[k];
                if (target > sum){
                    cnt+=(k-j);
                    j++;
                }
                else if (target <= sum){
                    k--;
                }
            }
        }
        
        return cnt;
    }
};