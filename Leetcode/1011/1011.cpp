class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        /* minimize maximum of subarray sums which are split into D parts from original array */
    	/* minimum : (sum + D - 1)/D */
    	/* maximum : sum? */

    	int sum = 0;
    	for (auto e : weights){
    		sum += e;
    	}

    	int s = (sum + D - 1)/D;
    	int e = sum;
    	auto ispossible = [](vector<int>& weights, int D, int cap){
    		int sum = 0;
    		int cnt = 1;
    		for (auto e : weights){
    			if (sum + e <= cap){
    				sum += e;
    			}
    			else{
    				if (e <= cap){
    					sum = e;
    					cnt++;	
    				}
    				else
    					return false;
    			}

    			if (cnt > D) return false;
    		}
    		return true;
    	};

    	while(s<e){

    		int mid = (s+e)/2;
    		if (ispossible(weights, D, mid)){
    			e = mid;
    		}
    		else{
    			s = mid + 1;
    		}
    	}


    	return e;
    }
};