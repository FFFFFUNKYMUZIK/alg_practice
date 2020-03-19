#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

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
