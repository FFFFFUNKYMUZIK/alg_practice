class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();
        if (n==0) return 0;

    	sort(points.begin(), points.end(), [](const vector<int>& lhs, const vector<int>& rhs)
    											{return lhs[1] < rhs[1];});
    	int cnt = 1;
    	int end = points[0][1];
    	for (int i=1;i<n;i++){
    		if (points[i][0]>end){
    			cnt++;
    			end = points[i][1];
    		}
    	}

    	return cnt;
    }
};