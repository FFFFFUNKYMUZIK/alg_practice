class Solution {
public:
    bool isMonotonic(vector<int>& A) {
    	int state = 0;

    	for (int i=1;i<A.size();i++){
    		if (A[i]-A[i-1]>0){
    			if (state<0) return false;
    		}
    		else if (A[i]-A[i-1]<0){
    			if (state>0) return false;
    		}
    		if (state == 0) state = A[i]-A[i-1];
    	}
        
        return true;
    }
};