#include <unordered_map>

class Solution {
public:
    bool canPermutePalindrome(string s) {
    	int len = s.length();
    	if (len <= 1) return true;

        unordered_map<int, int> hash;
        int oddcnt = 0;

        for (int i=0;i<len;i++){
        	if ((++hash[s[i]]) % 2 == 0) oddcnt--;
        	else oddcnt++;
        }

        return oddcnt <= 1;
    }
};