class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int maxd = 0;
        int d = 0;
        bool first = true;

        for (int i=0;i<seats.size();i++){
        	d++;
        	if (seats[i]){
        		if (!first){
        			maxd = max(d/2, maxd);
        		}
        		else{
        			maxd = max(d - 1, maxd);
        			first = false;
        		}
        		d = 0;
        	}
        }
        maxd = max(d, maxd);

        return maxd;
    }
};