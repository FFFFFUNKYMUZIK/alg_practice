#include <vector>

using namespace std;

/*

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

*/

#if 1
//dfs

class Solution {

	vector<int> v;
	vector<vector<int>> edges;

	bool dfs(int i){
		if (v[i]==1) return true;
		if (v[i]==0) return false;

		v[i]=0;
		for(int t=0;t<edges[i].size();t++){
			if (!dfs(edges[i][t])) return false;
		}
		v[i]=1;

		return true;
	}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        	if (numCourses<=1) return true;
		v = vector<int>(numCourses, -1);

		int num_edge = prerequisites.size();
		
		edges = vector<vector<int>> (numCourses);
		
		for (int i=0;i<num_edge;i++){
			edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}

	for ( int i=0;i<numCourses;i++){
		if (!dfs(i))return false;
	}

	return true;

    }
};

#else

#include <queue>

//bfs
//kahn's algorithm(using indegree)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        	if (numCourses<=1) return true;

		int num_edge = prerequisites.size();
		
		vector<vector<int>> edges(numCourses);
		vector<int> indegree(numCourses, 0);
		
		for (int i=0;i<num_edge;i++){
			edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
			indegree[prerequisites[i][1]]++;
		}

		queue<int> q;
		for (int i=0;i<numCourses;i++){
			if (indegree[i]==0) q.push(i);
		}
		
		int cnt=0;		
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			cnt++;

			for (int i=0;i<edges[cur].size();i++){
				int next = edges[cur][i];
				indegree[next]--;
				if( indegree[next]==0) q.push(next);
				else if(indegree[next]<0) return false;
			}
		}
			
	return (cnt==numCourses);
    }
};


#endif

int main(){
	Solution sol;

	return 0;
}
