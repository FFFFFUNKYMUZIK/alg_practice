#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int main()
{
    int n, m;

    cin >> n>>m;

    vector<vector<pair<int,int>>> edges(n+1, vector<pair<int,int>>());


    int idx = 0;
    int u, v, c;
    while (idx < m) {
        cin >> u >> v >> c;
        edges[u].push_back(make_pair(v, c));
        idx++;
    }

    int s, e;
    cin >> s >> e;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
    pq.push(make_pair(s, 0));
    vector<int> cost(n + 1, INF);
    vector<int> p(n + 1, -1);

    cost[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().first;
        int cur_cost = pq.top().second;
        pq.pop();

        if (cur_cost == cost[cur]) {
            for (int i = 0; i < edges[cur].size(); i++) {
                pair<int, int>& edge = edges[cur][i];
                int next = edge.first;
                int c = edge.second;
                if (c + cur_cost < cost[next]) {
                    cost[next] = c + cur_cost;
                    p[next] = cur;
                    pq.push(make_pair(next, cost[next]));
                }
            }
        }
    }

    printf("%d\n", cost[e]);

    vector<int> st;
    int trace = e;
    int cnt = 1;
    while (trace != s) {
        st.push_back(trace);
        trace = p[trace];
        cnt++;
    }
    st.push_back(s);

    printf("%d\n", cnt);

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        printf("%d ", *it);
    }

    return 0;
}
