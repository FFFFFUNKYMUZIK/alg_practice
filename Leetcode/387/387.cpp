class Solution {
public:
    int firstUniqChar(string s) {
        int ret = -1;

        vector<int> occurance(26, -1);

        for (int i=0;i<s.length();i++){
        	if (occurance[s[i] - 'a'] == -1){
        		occurance[s[i] - 'a'] = i;
        	}
        	else{
        		occurance[s[i] - 'a'] = s.length();	
        	}
        }

        int minret = s.length();
        for (int i=0;i<26;i++){
        	if (occurance[i] != -1 && occurance[i] < minret){
        		minret = occurance[i];
        	}
        }

        return minret == s.length() ? -1 : minret;
    }
};