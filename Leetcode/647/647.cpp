class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int len = s.length();

        for (int i=0;i<len;i++){

        	int j = 0;
        	while(i-j >=0 && i+j < len){
        		if (s[i-j]==s[i+j]) cnt++;
        		else break;
        		j++;
        	}

        	j = 0;
        	while(i-j >=0 && i+j+1 < len){
        		if (s[i-j]==s[i+j+1]) cnt++;
        		else break;
        		j++;
        	}
        }

        return cnt;

    }
};