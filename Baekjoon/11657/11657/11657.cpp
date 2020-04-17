#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

typedef struct edge_t {
    int u, v, c;
} edge;

int main()
{
    int N, M;
    cin >> N >> M;
       
    vector<edge> edges;


    int A, B, C;
    int idx = 0;
    while (idx < M) {
        cin >> A >> B >> C;
        edges.push_back({ A,B,C });
        idx++;
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < edges.size(); j++) {
            edge& cur = edges[j];
            int u = cur.u;
            int v = cur.v;
            int c = cur.c;

            if (dist[u] != INF && dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
            }
        }
    }

    bool cycle = false;
    for (int j = 0; j < edges.size(); j++) {
        edge& cur = edges[j];
        int u = cur.u;
        int v = cur.v;
        int c = cur.c;

        if (dist[u] != INF && dist[u] + c < dist[v]) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        printf("-1\n");
    }
    else {
        for (int i = 2; i < dist.size(); i++) {
            if (dist[i] != INF) {
                printf("%d\n", dist[i]);
            }
            else {
                printf("-1\n");
            }
        }
    }

    return 0;
}
