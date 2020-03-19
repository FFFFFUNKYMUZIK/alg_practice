#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

typedef struct plane_t{
    int v, c, d;

    bool operator<(const plane_t& right) const {
        return d > right.d;
    };
} plane;

int main()
{
    int T;
    cin >> T;
    int idx = 0;

    while (idx < T) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<plane>> planes(N+1, vector<plane>());

        int idx2 = 0;
        int u, v, c, d;
        while (idx2 < K) {
            cin >> u >> v >> c >> d;
            planes[u].push_back({ v,c,d });
            idx2++;
        }

        priority_queue<plane> pq;
        pq.push({ 1, 0, 0});
        vector<vector<int>> dist(N+1, vector<int>(M+1 , INF));
        dist[1][0] = 0;

        int shortest_d = -1;

        plane cur;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();

            if (cur.d == dist[cur.v][cur.c]) {

                if (cur.v == N) {
                    priority_queue<plane> empty;
                    pq.swap(empty);
                    shortest_d = cur.d;
                    break;
                }

                for (int i = 0; i < planes[cur.v].size(); i++) {
                    plane& edge = planes[cur.v][i];
                    if ((cur.c + edge.c <= M) && (cur.d + edge.d < dist[edge.v][cur.c + edge.c])) {
                        vector<int>& distvec = dist[edge.v];
                        int curd = cur.d + edge.d;
                        for (int i = cur.c + edge.c; i <= M;i++ ) {
                            if (curd < distvec[i]) distvec[i] = curd;
                            else break;
                        }
                        pq.push({edge.v, cur.c + edge.c, cur.d + edge.d });
                    }
                }
             }
        }

        if (shortest_d == -1) {
            cout << "Poor KCM" << '\n';
        }
        else {
            cout << shortest_d << '\n';
        }
        
        idx++;
    }
    
    return 0;
}
