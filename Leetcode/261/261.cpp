#if 1
class Solution {
public:
	/*
	Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
	*/
	class UF{

public:
		UF(int n){
			p = vector<int>(n, 0);
			rank = vector<int>(n, 0);
			for (int i=0;i<n;i++){
				p[i] = i;
				rank[i] = 0;
			}
		}

		int	Find(int x){
			if (p[x] == x){
				return x;			
			}
			return p[x] = Find(p[x]);
		}

		bool Union(int x, int y){
			int px, py;
			px = Find(x);
			py = Find(y);

			if (px==py) return false;

			if (rank[px]<rank[py]){
				p[px] = py;
			}
			else{
				p[py] = px;

				if (rank[px]==rank[py])
					rank[px]++;
			}
			return true;
		}

private:
		vector<int> p;
		vector<int> rank;
	};

    bool validTree(int n, vector<vector<int>>& edges) {
      	
      	Solution::UF uf(n);
    	bool valid = true;
    	if (edges.size() < n - 1) return false;

  		for (auto i : edges){
  			if (!uf.Union(i[0],i[1])){
  				valid = false;
  				break;
  			}
  		}   	
  		return valid;
    }
};


#else

class Solution {
public:
	/*
	Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
	*/

	bool dfs(int n, int p, vector<vector<int>>& to,  vector<char>& visit, int& cnt){
		bool valid = true;
		visit[n] = 1;
		cnt++;

		for (auto i : to[n]){
			if (i==p) continue;
			if (visit[i] || !dfs(i, n, to, visit, cnt)){
				valid = false;
				break;
			}
		}
		return valid;
	}
	
    bool validTree(int n, vector<vector<int>>& edges) {
      	
    	if (edges.size() < n - 1) return false;

    	bool valid = false;
    	vector<vector<int>> to(n, vector<int>());
    	vector<char> visit(n, 0);

  		for (auto i : edges){
  			to[i[0]].push_back(i[1]);
  			to[i[1]].push_back(i[0]);
  		}

  		int cnt = 0;
  		valid = dfs(0, -1, to, visit, cnt);

  		return valid && (cnt==n);
    }
};


#endif