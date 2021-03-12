class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ret;

        int n = firstList.size();
        int m = secondList.size();

        if (n==0 || m==0) return ret;

        int i=0, j=0;

        int s, e;
        while(i<n){
        	s = firstList[i][0];
        	e = firstList[i][1];

        	while(j<m && secondList[j][1] < s) j++;
        	if (j==m) break;

        	while(j<m){
        		if (secondList[j][1] <= e){
        			int ns = max(s, secondList[j][0]);
        			ret.push_back({ns, secondList[j][1]});
        			j++;
        		}
        		else{
        			if (secondList[j][0] <= e){
        				int ns = max(s, secondList[j][0]);
        				ret.push_back({ns, e});
        				break;
        			}
        			else{
        				break;
        			}
        		}
        	}
        	if (j==m) break;
        	i++;
        }

        return ret;
    }
};