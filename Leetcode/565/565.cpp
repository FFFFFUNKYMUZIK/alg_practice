class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 0);
        int maxlen = 0;

        for (int i=0;i<n;i++){
        	int s = i;
        	int cnt = 0;
        	while(len[s] == 0){
        		len[s] = ++cnt;
        		s = nums[s];
        	}
        	maxlen = max(maxlen, len[i]);
        }

        return maxlen;
    }
};