class Solution {

	using ll = long long;
public:
    string decodeString(string s) {
        string ret;

        stack<ll> irepeat;
        stack<string> srepeat;
        int len = s.length();
        ll num = 0;
        string part;

        for (int i=0;i<len;i++){
        	auto cur = s[i];

        	if (cur >= '0' && cur <= '9'){
        		num = num * 10 + (cur - '0');
        	}
        	else if (cur >= 'a' && cur <= 'z'){
        		ret += cur;
        	}
        	else{
        		if (cur=='['){
        			srepeat.push(ret);
        			irepeat.push(num);
        			ret = "";
        			num = 0;
        		}
        		else if (cur==']'){
        			int rep = irepeat.top();
        			irepeat.pop();
        			part = "";
        			for (int r = 0;r<rep;r++){
        				part += ret;
        			}

        			ret = srepeat.top();
        			srepeat.pop(); 
        			ret += part;
        		}
        	}
        }

        return ret;
    }
};