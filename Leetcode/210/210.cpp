#include <iostream>



#if 0

//dfs
class Solution {
public:
    vector<vector<int>> edges;
    stack<int> st;
    vector<int> v;
    
    bool dfs(int s){
        if (v[s] == 0) return false;
        if (v[s] == 1) return true;
        
        v[s] = 0;
        for (int c = 0 ; c<edges[s].size();c++){
            if (!dfs(edges[s][c])) return false;
        }
        
        v[s] = 1;
        st.push(s);
        
        return true;
    }
       
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        if (numCourses == 0) return ret;

        edges = vector<vector<int>>(numCourses, vector<int>());
        v = vector<int>(numCourses, -1);
        stack<int>().swap(st);
                
        for (int i=0;i<prerequisites.size();i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i=0;i<numCourses;i++){
            if (!dfs(i)) return ret;
        }
        
        while (!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        
        return ret;
    }
};

#else

//bfs(queue)

class Solution {
public:
 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        if (numCourses == 0) return ret;

        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
      
        for (int i=0;i<prerequisites.size();i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for (int i=0;i<numCourses;i++){
            if (indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int cur = q.front();
            ret.push_back(cur);
            q.pop();
            
            for (int i=0;i<edges[cur].size();i++){
                int nxt = edges[cur][i];
                if (--indegree[nxt]==0) q.push(nxt);
                else if (indegree[nxt]<0){
                    break;  
                }
            }
        }
        
        if (ret.size()<numCourses) vector<int>().swap(ret);
        
        return ret;
    }
};

#endif
int main(){

return 0;
}