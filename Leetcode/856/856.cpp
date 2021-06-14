class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        bool unit = false;

        stack<int> st;

        int i = 0;
        while(i < s.length()){
        	if (s[i] == '('){
        		st.push(score);
        		score = 0;
        		unit = true;
        	}
        	else{
        		if (unit){
        			score = 1;
        		}
        		else{
        			score *= 2;
        		}
        		
        		score += st.top();
        		st.pop();
        		unit = false;
        	}
        	i++;
        }

        return score;
    }
};