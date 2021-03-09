class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> veff(r, vector<int>(c, INT_MAX));

		using el = struct{
			int eff;
			int x, y;
		};

		using comp = struct {
			bool operator()(const el& lhs, const el& rhs){
				return lhs.eff > rhs.eff;
			}
		};

		priority_queue<el, vector<el>, comp> pq;

		pq.push({0, r-1, c-1});
		veff[r-1][c-1] = 0;

		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, -1, 0, 1};

		el cur;
		while(!pq.empty()){
			cur = pq.top();
			pq.pop();

			for (int i=0;i<4;i++){
				int nx = cur.x+dx[i];
				int ny = cur.y+dy[i];

				if (nx>=0 && nx<r &&
					ny>=0 && ny<c ){
					int neff = max(cur.eff, abs(heights[cur.x][cur.y] - heights[nx][ny]));

					if (neff < veff[nx][ny]){
						veff[nx][ny] = neff;
						pq.push({neff, nx, ny});
					}
				}
			}
		}

		return veff[0][0];
    }
};