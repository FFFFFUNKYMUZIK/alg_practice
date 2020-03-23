#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;


//Prim O(V^2+E) = O(V^2)
/*
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> edges(V+1);

    int idx = 0;
    int u, v, c;
    while (idx < E) {
        cin >> u >> v >> c;
        edges[u].push_back(make_pair(v, c));
        edges[v].push_back(make_pair(u, c));
        idx++;
    }

//    vector<int> parent(V + 1, -1);
    vector<int> weight(V + 1, INF);
    vector<bool> visit(V + 1, false);
    vector<pair<int, int>> MST;

//    parent[1] = 1;
    weight[1] = 0;

    int ret = 0;
    
    for (int rep = 1; rep <= V; rep++) {

        int next = 0;
        for (int i = 1; i <= V; i++) {
            if (!visit[i] && (weight[i] < weight[next])) {
                next = i;
            }
        }
        if (next == 0) break;

        ret += weight[next];
        visit[next] = true;
        //if (parent[next] != next) MST.push_back(make_pair(parent[next], next));

        for (int i = 0; i < edges[next].size(); i++) {
            int v = edges[next][i].first;
            int c = edges[next][i].second;
            if (!visit[v] && weight[v] > c) {
                weight[v] = c;
                //parent[v] = next;
            }

        }
    }

    cout << ret << '\n';

    return 0;
}

*/

//Prim O(ElogE) = O(ElogV)

/*
#include <queue>
typedef pair<int, pair<int, int>> piii;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> edges(V + 1);

    int idx = 0;
    int u, v, c;
    while (idx < E) {
        cin >> u >> v >> c;
        edges[u].push_back(make_pair(v, c));
        edges[v].push_back(make_pair(u, c));
        idx++;
    }
    
    vector<bool> visit(V + 1, false);
    vector<pair<int, int>> MST;

    priority_queue<piii, vector<piii>, greater<piii>> pq;

    int ret = 0;
    pq.push(make_pair(0, make_pair(0, 1)));
       
    while (!pq.empty()) {
        int cur_w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;

        pq.pop();

        if (!visit[v]) {
            MST.push_back(make_pair(u, v));
            visit[v] = true;
            ret += cur_w;

            for (int i = 0; i < edges[v].size(); i++) {
                int nv = edges[v][i].first;
                int nw = edges[v][i].second;
                if (!visit[nv]) {
                    pq.push(make_pair(nw, make_pair(v, nv)));
                }
            }
        }
    }


    cout << ret << '\n';

    return 0;
}
*/


//Kruskal O(ElogE)(sort) = O(ElogV)

#include <algorithm>

typedef struct edge_t {
    int w;
    int u, v;

    edge_t() {}
    edge_t(int w_, int u_, int v_) :w(w_), u(u_), v(v_) {}

    bool operator< (const edge_t & rhs) const {
        return w < rhs.w;
    }

} edge;

vector<edge> edges;
vector<int> p;

int Find(int x) {

    if (p[x] == x) {
        return x;
    }
    else {
        return p[x] = Find(p[x]);
    }

}

void Union(int x, int y) {

    int px = Find(x);
    int py = Find(y);

    if (px != py) {
        p[px] = py;
    }
}


int main()
{
    int V, E;
    cin >> V >> E;
    
    p = vector<int>(V + 1, 0);
    
    for (int i = 1; i <= V; i++) {
        p[i] = i;
    }

    int idx = 0;
    int u, v, c;
    while (idx < E) {
        cin >> u >> v >> c;
        edges.push_back({c, u, v});
        idx++;
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, int>> MST;

    int ret = 0;

    edge cur;
    for (int i = 0; i < E; i++) {
        cur = edges[i];
        int x = cur.u;
        int y = cur.v;
        int w = cur.w;
        if (Find(x) != Find(y)) {
            Union(x, y);
            ret += w;
            MST.push_back({x, y});
        }
    }

    cout << ret << '\n';

    return 0;
}