class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

    	if (k==0) return 0;

        int n = s.length();

        int dcnt = 0;
        unordered_map<char, int> cnt;
        int maxlen = 0;

        int i = 0;
        for (int j=0;j<n;j++){
        	if (cnt.find(s[j]) == cnt.end() || cnt[s[j]] == 0) dcnt++;
        	cnt[s[j]]++;

        	if (dcnt <= k){
        		maxlen = max(maxlen, j-i+1);
        	}
        	else{
        		while(dcnt>k){
        			if (--cnt[s[i++]] == 0){
        				dcnt--;
        			}
        		}
        	}
        }
        return maxlen;
    }
};