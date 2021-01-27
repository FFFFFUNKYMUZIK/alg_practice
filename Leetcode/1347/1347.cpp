class Solution {
public:
    int minSteps(string s, string t) {
    	int slen = s.length();
    	int tlen = t.length();

    	vector<int> alp(26, 0);

    	for (int i=0;i<slen;i++){
			alp[s[i] - 'a']++;    		
    	}

    	for (int i=0;i<tlen;i++){
			alp[t[i] - 'a']--;    		
    	}
        
        int ret = 0;
        for (auto a : alp){
        	if (a<0) ret-=a;
        }

        return ret;
    }
};