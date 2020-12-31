
class Solution {
public:
	/* minimum O(N) to probe vector, naive method (sort : O(NlogN)) */
	/* Quickselect? */

	typedef struct point_t{
		int idx;
		double dist;
	} point;

	int Partition(vector<point>& points, int s, int e, int K){

		double p = points[s].dist;
		point tmp;
		int i = s+1, j=e;

		while(i<=j){
			while(i <= e && points[i].dist <= p ) i++;
			while(j > 0 && points[j].dist > p) j--;
			if (i<j){
				tmp = points[i];
				points[i] = points[j];
				points[j] = tmp;
			}
		}

		tmp = points[s];
		points[s] = points[j];
		points[j] = tmp;

		return j;
	}

	void Quickselect(vector<point>& points, int s, int e, int K){

		cout<<s<<" "<<e<<endl;

		int pos = Partition(points, s, e, K);

		int offset = pos - s + 1;

		if (offset<K){
			Quickselect(points, pos + 1, e, K-offset);
		}
		else if (offset>K){
			Quickselect(points, s, pos - 1, K);
		}
		else{
			return;
		}
	}

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<point> pts(points.size(), point({0, 0.0}));
        vector<vector<int>> ret(K, vector<int>{0, 0});

        int x,y;
        for (int i=0;i<points.size();i++){
        	x = points[i][0];
        	y = points[i][1];
        	pts[i] = {i, sqrt(x*x+y*y)};
        }

        Quickselect(pts, 0, pts.size() - 1, K);

        for (int i=0;i<K;i++){
        	ret[i] = points[pts[i].idx];
        }

        return ret;
    }
};