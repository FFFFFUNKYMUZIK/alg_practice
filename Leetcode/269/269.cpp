#define LOW_ALP 26

class Solution {
public:
    
    string alienOrder(vector<string>& words) {
    	
    	string ret;
    	int num = words.size();
    	if (num == 0) return ret;

    	vector<int> indegree(LOW_ALP, -1);
    	vector<vector<int>> edges(LOW_ALP, vector<int>(LOW_ALP, 0));

    	int alen, blen;
    	int cnt = 0;


    	/* init DAG */
		for (int i=0; i<num ;i++){
			alen = words[i].length();
			int j=0;

			while(j<alen){
				if (indegree[words[i][j] - 'a'] != 0){
					indegree[words[i][j] - 'a'] = 0;
					cnt++;
				}
				j++;
			}
		}

		/* make DAG */
    	for (int i=0; i<num - 1;i++){
    		alen = words[i].length();
    		blen = words[i+1].length();
    		int j=0;
    		while(j < alen && j < blen &&
    			words[i][j] == words[i + 1][j])
    			j++;

    		if (j == blen && j != alen) return ret;
    		
    		if (j!=alen){
    			if (edges[words[i][j] - 'a'][words[i + 1][j] - 'a'] == 0){
    				edges[words[i][j] - 'a'][words[i + 1][j] - 'a'] = 1;
   					indegree[words[i + 1][j] - 'a']++;
    			}
   			}
    	}

    	/* topological sort */
    	queue<int> q;
    	for (int i=0;i<indegree.size();i++){
    		if (indegree[i] == 0) q.push(i);
    	}
    	
    	int cur;
    	while(!q.empty()){
    		cur = q.front();
    		q.pop();
    		cnt--;
    		ret += (cur+'a');

    		for (int i=0;i<edges[cur].size();i++){
    			if (edges[cur][i]){
    				if (--indegree[i] == 0) q.push(i);
    			}
    		}
    	}
    	if (cnt != 0) return string();

    	return ret;
    }
};
