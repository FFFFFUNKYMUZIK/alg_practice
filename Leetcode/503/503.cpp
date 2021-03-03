class Solution {

	using el = struct {int idx;int val;};
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     	int n = nums.size();

     	stack<el> st;
     	vector<int> ret(n, -1);

     	for (int rep = 0; rep < 2; rep++){
	     	for (int i = 0;i<n;i++){
	   			while(!st.empty() && st.top().val < nums[i]){
	   				 el& cur = st.top();
	   				 ret[cur.idx] = nums[i];
	   				 st.pop();
	   			}
	   			st.push({i, nums[i]});
	     	}
     	}

     	return ret;
    }
};