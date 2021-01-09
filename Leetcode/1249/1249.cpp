class Solution {
public:
    string minRemoveToMakeValid(string s) {
     
     	int len = s.length();
    	stack<int> l, r;

    	for (int i=0;i<len;i++){
    		switch(s[i]){
    			case '(' :
    				l.push(i);
    			break;

    			case ')' :
    				if (!l.empty()){
    					l.pop();
    				}
    				else{
    					r.push(i);
    				}
    			break;

    			default :
    			break;
    		}
    	}

    	int retsize = len - l.size() - r.size();
    	string ret;
    	ret.resize(retsize);
    	retsize--;

    	for (int i=len -1 ; i>=0 ; i--){
    		if (!l.empty() && l.top() == i)
    			l.pop();
    		else if (!r.empty() && r.top() == i)
    			r.pop();
    		else
    			ret[retsize--] = s[i];
    	}

    	return ret;
    }
};