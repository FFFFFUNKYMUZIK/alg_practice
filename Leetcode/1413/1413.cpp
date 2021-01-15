class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minsum = 0;
        int psum = 0;
        for (auto n : nums){
        	psum += n;
        	minsum = min(minsum, psum);
        }
        return 1-minsum;
    }
};