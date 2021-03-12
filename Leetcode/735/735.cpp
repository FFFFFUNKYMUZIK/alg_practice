class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();

        stack<int> st;
        vector<int> ret;

        for (int i=0;i<n;i++){
        	if (asteroids[i]<0){
        		while (!st.empty() && st.top() < abs(asteroids[i])) st.pop();
        		if (st.empty()){
        			ret.push_back(asteroids[i]);
        		}
        		else if (st.top() == abs(asteroids[i])){
        			st.pop();
        		}
        	}
        	else{
        		st.push(asteroids[i]);
        	}
        }

        if (!st.empty()){
        	int remain = ret.size() + st.size();
        	ret.resize(remain);
        	int i = remain;
        	while(!st.empty()){
        		ret[--i] = st.top();
        		st.pop();
        	}
        }

        return ret;
    }
};