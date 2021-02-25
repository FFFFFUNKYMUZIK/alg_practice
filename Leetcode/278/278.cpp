// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    	unsigned int s = 1, e = n;

    	while(s<e){
    		int mid = (s + e) / 2;

    		if (isBadVersion(mid)){
    			e = mid;
    		}
    		else{
    			s = mid + 1;
    		}
    	}
        
        return e;
    }
};