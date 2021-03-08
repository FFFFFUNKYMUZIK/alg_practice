class Solution {

public:
    vector<int> countSmaller(vector<int>& nums) {
    	int n = nums.size();
        vector<int> cnt(n, 0);
        vector<int> b(2 * 10000 + 2, 0);

        auto update = [](vector<int>& b, int c, int val)->void{
        	c += 10001;
        	while(c<20002){
        		b[c] += val;
        		c += (c&-c);
        	}
        };

        auto get = [](vector<int>& b, int c)->int{
        	c += 10001;
        	int sum = 0;
        	while(c>0){
        		sum += b[c];
        		c -= (c&-c);
        	}
        	return sum;
        };

        for (int i=n-1;i>=0;i--){
        	cnt[i] = get(b, nums[i]);
        	update(b, nums[i] + 1, 1);
        }

        return cnt;
    }
};