//Pr. 1

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int len = cookie.size();
    vector<int> psum(len + 1, 0);
    
    for (int i=1;i<=len;i++){
        psum[i] = psum[i-1]+cookie[i-1];
    }
    
    int s,e;
    int part_max = 0;
    for (int m=1;m<len;m++){
        s = 0, e = len;
        int lsum, rsum;
        while(s<m && m<e){
            lsum = psum[m]-psum[s];
            rsum = psum[e]-psum[m];
            
            if (lsum<rsum){
                e--;
            }
            else if (lsum>rsum){
                s++;
            }
            else{
                part_max = max(part_max, lsum);
                break;
            }
        }
    }
    
    return part_max;
}





//Pr. 2

//TLE solution
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;

    vector<vector<int>> edge_reorder(n + 1, vector<int>());

    //O(E)
    for (int i = 0; i < edges.size(); i++) {
        edge_reorder[edges[i][0]].push_back(edges[i][1]);
        edge_reorder[edges[i][1]].push_back(edges[i][0]);
    }

    //O(V^2)
    for (int i = 1; i <= n; i++) {
        bool add = true;
        vector<int> visit(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            if (visit[j] == 0) {
                vector<int> cvisit(n + 1, 0);
                queue<pair<int,int>> q;
                q.push(make_pair(j, 0));
                bool cont = true;
                while (!q.empty() && cont) {
                    pair<int, int> curp = q.front();
                    int cur = curp.first;
                    int p = curp.second;
                    q.pop();

                    for (int e = 0; e < edge_reorder[cur].size(); e++) {
                        int dst = edge_reorder[cur][e];
                        if (dst == i || dst == p) continue;
                        if (cvisit[dst] == 1) {
                            cont = false;
                            break;
                        }

                        visit[dst] = cvisit[dst] = 1;
                        q.push(make_pair(dst, cur));
                    }
                }
                if (!cont) {
                    add = false;
                    break;
                }
            }
        }
        if (add) {
            answer += i;
        }

    }

    return answer;
}


// articulation!

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edge_reorder;
vector<int> order;
vector<int> part;
int gorder = 1;

int dfs(int cur, int pre){
    int ret = order[cur] = gorder++;
    
    int tmp;
    int ch = 0;
    for (int i=0;i<edge_reorder[cur].size();i++){
        int nxt = edge_reorder[cur][i];
        if (nxt==pre) continue;
        
        if (order[nxt] == 0){
            ch++;
            tmp = dfs(nxt, cur);
            if (pre != 0 && tmp>=order[cur]) part[cur]++;
        }
        else{
            tmp = order[nxt];
        }
        ret = min(ret, tmp);
    }
    
    //root node case
    if (pre==0 && ch>1){
        part[cur] = ch-1;
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> edges) {
    
    order = vector<int>(n+1, 0);
    part = vector<int>(n+1, 0);
    edge_reorder = vector<vector<int>>(n+1, vector<int>());
    
    int cnt = 0;
    for (int i=0;i<edges.size();i++){
        int f, t;
        f = edges[i][0];
        t = edges[i][1];
        edge_reorder[f].push_back(t);
        edge_reorder[t].push_back(f);
        cnt++;
    }
    
    //one connected graph, so no iteration
    //dfs spanning tree
    dfs(1, 0);
    
    int ret = 0;
    for (int i=1;i<=n;i++){
        if (cnt - edge_reorder[i].size() < n-1 - part[i] ){
            ret+=i;
        }
    }
    return ret;
}