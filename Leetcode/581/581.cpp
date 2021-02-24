class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int maxval = nums[0];
        int n = nums.size();
        int sidx = n + 1;
        int sidx_tmp;
        int eidx = n;

        for (int i=0;i<n;i++){
        	if (nums[i]>=maxval){
        		maxval = nums[i];
        		st.push(i);
        	}
        	else{
        		eidx = i;
        		sidx_tmp = n;
        		while(!st.empty() && nums[st.top()] > nums[i]){
        			sidx_tmp = st.top();
        			st.pop();
        		}
        		sidx = min(sidx, sidx_tmp);
        	}
		}

		return eidx - sidx + 1;
    }
};