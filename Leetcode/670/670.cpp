class Solution {
public:
    int maximumSwap(int num) {

    	vector<int> digits;
    	int orig = num;

        while(orig>0){
        	digits.push_back(orig%10);
        	orig/=10;
        }

        int n = digits.size();
        int c;

        class el{
        public:
        	el(int i, int d) : idx(i), dig(d) {};
        	int idx;
        	int dig;
        };

        stack<el> st, stc;
        int j = n - 1;

        while(j>=0){
        	c = digits[j];
        	while(!st.empty() && st.top().dig <= c){
	        	st.pop();
        	}

        	st.push({j, c});
        	j--;
        }

        while (!st.empty()){
        	stc.push(st.top());
        	st.pop();
        }

        int i = n - 1;
        while (!stc.empty()){
        	if (i != stc.top().idx){
        		j = stc.top().idx;
        		break;
        	}
        	stc.pop();
        	i--;
        }

		int ret = num;
        if (!stc.empty()){
        	int tmp = digits[i];
        	digits[i] = digits[j];
        	digits[j] = tmp;

        	i = n-1;
        	ret = 0;
        	while(i>=0){
	        	ret *= 10;
        		ret = (ret + digits[i]);
        		i--;
        	}
        }

        return ret;
    }
};