class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        s+=" ";

        int i=0, j=0;
        char tmp;
        int cur;

        while(i<n){
        	while(s[j]!=' ') j++;
        	cur = j+1;
        	j--;

        	while(i<j){
        		tmp = s[i];
        		s[i] = s[j];
        		s[j] = tmp;
        		i++; j--;
        	}

        	i = cur;
        	j = cur;
        }

        s.resize(n);

        return s;
    }
};