class Solution {

	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

public:

	int explore(int x, int y, int w, int h, vector<vector<int>>& grid, vector<vector<int>>& visit){

		int nx, ny;
		int ret = 0;
		if (grid[x][y]){
			ret = 4;
			visit[x][y] = 1;
			for (int i=0;i<4;i++){
				nx = x+dx[i];
				ny = y+dy[i];

				if (nx>=0 && nx<h &&
					ny>=0 && ny<w){

					if (grid[nx][ny] == 1){
						if (visit[nx][ny] == 0){
							ret += (explore(nx, ny, w, h, grid, visit) - 1);
						}
						else{
							ret -= 1;
						}
					}
				}
			}
		}

		return ret;
	}

    int islandPerimeter(vector<vector<int>>& grid) {

        int h = grid.size();
        int w = grid[0].size();
        int ret;

        vector<vector<int>> visit(h, vector<int>(w, 0));

        for (int i=0;i<h;i++){
        	for (int j=0;j<w;j++){
        		if ((ret = explore(i,j, w, h, grid, visit)) > 0)
        			return ret;
        	}
        }

        return 0;
    }
};