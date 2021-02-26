class Solution {

	using dup = struct {
		char c;
		int cnt;
	};


public:
    string removeDuplicates(string s, int k) {
        stack<dup> st;
        int len = s.length();
        int cnt;

        for (int i=0;i<len;i++){
        	if (!st.empty()){
        		if (st.top().c == s[i]){
        			cnt = st.top().cnt + 1;
        			st.pop();
        			if (cnt < k){
        				st.push({s[i], cnt});
        			}
        		}
        		else{
        			st.push({s[i], 1});
        		}
        	}
        	else{
        		st.push({s[i], 1});
        	}
        }

        string ret;
        while(!st.empty()){
        	ret = st.top().c + ret;
        	if (--st.top().cnt == 0){
        		st.pop();
        	}
        }

        return ret;
    }
};