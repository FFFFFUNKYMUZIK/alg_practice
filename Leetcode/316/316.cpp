class Solution {

	#define ALP 26
public:
    string removeDuplicateLetters(string s) {
    	int n = s.length();
        stack<char> st;
        vector<int> b(ALP, 0);
        vector<int> v(ALP, 0);

        for (int i=0;i<n;i++){
        	b[s[i] - 'a']++;
        }

        string ret;
        for (int i=0;i<n;i++){
        	b[s[i] - 'a']--;
        	if (v[s[i] - 'a'] == 1) continue;

        	while(!st.empty() && st.top() > s[i] && b[st.top() - 'a'] > 0){
        		v[st.top() - 'a'] = 0;
        		st.pop();
        	}

        	st.push(s[i]);
        	v[s[i] - 'a'] = 1;        	
        }

        while(!st.empty()){
        	ret = st.top() + ret;
        	st.pop();
        }

        return ret;
    }
};