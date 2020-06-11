#include <vector>
#include <stack>





class Solution {
	
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
	int n = grid.size();
	if (n==0) return ret;
	int m = grid[0].size();
	if (m==0) return ret;

	vector<char> visit(n*m, 0);

	for (int i=0;i<n;i++){
		int base = i*m;
		for (int j=0;j<m;j++){
			if (visit[base+j] || grid[i][j] == '0') continue;
		
			ret++;
			stack<pair<int,int>> st;
			st.push(make_pair(j,i));

			int x,y;
			while(!st.empty()){
				pair<int, int> cur = st.top();
				st.pop();
				x = cur.first;
				y = cur.second;

				int nx, ny; 			
				for (int d=0;d<4;d++){
					nx = x+dx[d];
					ny = y+dy[d];
					if ( nx>=0 && nx<m &&
						ny>=0 && ny<n &&
						visit[ny*m+nx]==0 &&
						grid[ny][nx]=='1'){
						visit[ny*m+nx]=1;
						st.push(make_pair(nx,ny));
					}
				}
			}
		}
	}


	return ret;
    }
};



int main(){
	return 0;
}
