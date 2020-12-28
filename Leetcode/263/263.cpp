class Solution {
public:
    bool isUgly(int num) {
    	if (num<1) return false;
        
    	vector<int> div({2, 3, 5});

    	for (int i=0;i<div.size();i++){
    		int cur = div[i];
    		while (num%cur == 0)
    			num /= cur;
    	}
    	return num == 1;
    }
};