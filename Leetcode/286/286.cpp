class Solution {

#define INF 2147483647

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

	void dfs(vector<vector<int>>& rooms, int x, int y, int m, int n, int dist){
		rooms[x][y] = dist++;

		int nx, ny;
		for (int i=0;i<4;i++){
			nx = x+dx[i];
			ny = y+dy[i];

			if (nx>=0 && nx < m &&
				ny>=0 && ny < n &&
				rooms[nx][ny] > dist){
				dfs(rooms, nx, ny, m, n, dist);
			}
		}

	}


public:
    void wallsAndGates(vector<vector<int>>& rooms) {
    	int m = rooms.size();
    	int n = rooms[0].size();

    	for (int i=0;i<m;i++){
    		for (int j=0;j<n;j++){
    			if (rooms[i][j] == 0){
    				dfs(rooms, i, j, m, n, 0);
    			}
    		}	
    	}

		return;       
    }
};