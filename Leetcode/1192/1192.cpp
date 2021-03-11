class Solution {

	int order = 0;
	vector<vector<int>> ret;

	int dfs(int i, vector<int>& disc, vector<vector<int>>& edges, int par){
		disc[i] = ++order;
		int reach = disc[i];

		for (int j=0;j<edges[i].size();j++){
			int next = edges[i][j];
			if (next == par) continue;

			if (disc[next] == 0){
				int lowest = dfs(next, disc, edges, i);
				if (lowest>=disc[next]){
					ret.push_back({i, next});
				}
				reach = min(reach, lowest);
			}
			else
				reach = min(reach, disc[next]);
		}

		return reach;
	}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        /* graph articulation */

    	vector<int> disc(n, 0);
    	vector<vector<int>> edges(n, vector<int>());

    	for (int i=0;i<connections.size();i++){
    		edges[connections[i][0]].push_back(connections[i][1]);
    		edges[connections[i][1]].push_back(connections[i][0]);
    	}

/*
    	for (int i=0;i<n;i++){
    		if (disc[i] == 0){
    			dfs(i, disc, edges);	
    		}
    	}
*/
    	dfs(0, disc, edges, -1);

    	return ret;

    }
};