class Solution {

public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if (k>=n-1) return n;

        int i = 0, j = 0;

        unordered_map<char, int> cnt;

        int maxlen = 0;
        int len;
        int possible = 0;
        int maxcnt = 0;

        while(i<=j && j<n){
        	len = j - i + 1;
        	cnt[s[j]]++;

        	maxcnt = max(cnt[s[j]], maxcnt);
        	if (len - maxcnt > k){
        		cnt[s[i]]--;
        		i++;
        		cnt[s[j]]--;
        	}
        	else{
        		maxlen = max(maxlen, j - i + 1);
        		j++;
        	}
        }


        return maxlen;
    }
};