class Solution {

	vector<int> p;

	void Union(int x, int y){
		int px, py;
		px = Find(x);
		py = Find(y);

		if (px!=py){
			p[px] = py;
		}
	}

	int Find(int x){
		if (p[x] == x){
			return x;
		} 
		
		return p[x] = Find(p[x]);
	}


public:
	/* Union Find : O(n*n*logn) */
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();

        vector<int>(n, 0).swap(p);
        for (int i=0;i<n;i++){
        	p[i] = i;
        }

        for (int i=0;i<n;i++){
       		for (int j=i+1;j<n;j++){
        		if (isConnected[i][j] && Find(i) != Find(j)){
        			Union(i, j);
      			}
      		}
        }

        int cnt = 0;
        for (int i=0;i<n;i++){
        	if (p[i] == i) cnt++;
        }
        return cnt;
    }

    /* let's do with dfs (O(N)) */
};