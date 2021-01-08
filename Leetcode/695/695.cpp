class Solution {

	using vi = vector<int>;
	using vvi =  vector<vi>;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int explore(int x, int y, vvi& grid, vvi& visit, int& w, int& h){

		int nx, ny;
		int ret = 1;

		visit[x][y] = 1;

		for (int i=0;i<4;i++){
			nx = x+dx[i];
			ny = y+dy[i];

			if(nx<w && nx>=0 &&
				ny<h && ny>=0 &&
				visit[nx][ny] == 0 &&
				grid[nx][ny] == 1)
				ret += explore(nx,ny,grid,visit,w,h);
		}

		return ret;
	}

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {

    	int w = grid.size();
    	if (w==0) return 0;
    	int h = grid[0].size();
    	if (h==0) return 0;
        
        vvi visit(w, vi(h, 0));
        int area;
        int maxarea = 0;

        for (int i=0;i<w;i++){
        	for (int j=0;j<h;j++){
        		if (visit[i][j] == 1 || grid[i][j] == 0) continue;
        			area = explore(i, j, grid, visit, w, h);
        			if (area>maxarea) maxarea = area;
    		}
    	}

    	return maxarea;
    }
};