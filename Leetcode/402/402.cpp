class Solution {
public:
    string removeKdigits(string num, int k) {
    	if (k==0) return num;
    	int n = num.length();
    	if (n==k) return string("0");

    	string ret;
    	stack<int> st;
    	int i = 0;

    	while(k>0 && i < n){
    		if (!st.empty() && num[st.top()] > num[i]){
    			st.pop();
    			k--;
    		}
    		else{
    			if (!st.empty() || num[i] != '0'){
    				st.push(i);
    			}
    			i++;
    		}
    	}

    	while(k>0){
    		st.pop();
    		k--;
    	}

    	while(i<n){
    		if (!st.empty() || num[i] != '0'){
   				st.push(i);
   			}
   			i++;
    	}

    	while(!st.empty()){
    		ret = num[st.top()] + ret;
    		st.pop();
    	}

        return ret == "" ? "0" : ret;
    }
};