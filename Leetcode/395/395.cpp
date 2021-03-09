class Solution {
public:

	int subfunc(string s, int k, vector<int>& cnt){

		int n = s.length();

    	if (n==0 || n<k) return 0;

		vector<int> accum(26, 0);

    	int chars = 0;
    	int full = 0;
    	int maxlen = 0;

    	for (int i=0;i<n;i++){

			accum[s[i]-'a']++;
    		cnt[s[i]-'a']--;

    		if (accum[s[i]-'a'] == 1){
    			chars++;

    			if (cnt[s[i]-'a'] < k - 1){
    				maxlen = max(maxlen, subfunc(s.substr(0, i), k, accum));
    				maxlen = max(maxlen, subfunc(s.substr(i+1), k, cnt));
    				break;
    			}
    		}
    		
    		if (accum[s[i]-'a'] == k){
    			full++;
    		}

    		if (chars==full){
    			maxlen = max(maxlen, i+1);
    		}
    	}

    	return maxlen;
	}


    int longestSubstring(string s, int k) {
        
    	int n = s.length();

    	if (n==0 || n<k) return 0;

    	vector<int> cnt(26, 0);
    	
    	for (int i=0;i<n;i++){
    		++cnt[s[i]-'a'];
    	}

    	return subfunc(s, k, cnt);
    }
};