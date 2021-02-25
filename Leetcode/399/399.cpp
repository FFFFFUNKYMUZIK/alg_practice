class Solution {

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        vector<vector<double>> ratio(2*n, vector<double>(2*n, -1.0));
        unordered_map<string, int> idx;

        vector<vector<int>> graph(2*n, vector<int>());
        int varcnt = 0;

        for (int i=0;i<n;i++){
        	if (idx.find(equations[i][0]) == idx.end()){
        		idx[equations[i][0]] = varcnt++;
        	}
        	if (idx.find(equations[i][1]) == idx.end()){
        		idx[equations[i][1]] = varcnt++;
        	}
        	ratio[idx[equations[i][0]]][idx[equations[i][1]]] = values[i];
        	ratio[idx[equations[i][1]]][idx[equations[i][0]]] = 1/values[i];

        	graph[idx[equations[i][0]]].push_back(idx[equations[i][1]]);
        	graph[idx[equations[i][1]]].push_back(idx[equations[i][0]]);
        }



        for (int i=0;i<varcnt;i++){
        	vector<char> visit(varcnt, 0);
        	stack<pair<int, double>> st;
        	int s = i;
        	st.push(make_pair(i, 1.0));

        	while(!st.empty()){
        		auto cur = st.top();
        		st.pop();
        		visit[cur.first] = 1;
        		ratio[cur.first][s] = cur.second;
        		for (int j=0;j<graph[cur.first].size();j++){
        			if (visit[graph[cur.first][j]] == 0){
        				st.push(make_pair(graph[cur.first][j], cur.second * ratio[graph[cur.first][j]][cur.first]));
        			}
        		}
        	}
        }

        vector<double> ret(queries.size(), 0);
        for (int i=0;i<queries.size();i++){
        	if (idx.find(queries[i][0]) != idx.end() &&
        		idx.find(queries[i][1]) != idx.end()){
        		ret[i] = ratio[idx[queries[i][0]]][idx[queries[i][1]]];
    		}
    		else{
    			ret[i] = -1.0;
    		}
        }

        return ret;
    }
};