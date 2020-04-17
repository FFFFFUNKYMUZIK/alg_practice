#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INT_MAX 987654321

using namespace std;

int main()
{
    int T, n, m ,t;
    int s, g, h;
    int a, b, d;
    int x;

    cin >> T;


    int idx = 0;
    while (idx < T) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        vector<int> dest, ret;
        vector<vector<pair<int, int>>> edges(n+1);


        int idx2 = 0;
        while (idx2 < m) {
            cin >> a >> b >> d;
            edges[a].push_back(make_pair(b, d));
            edges[b].push_back(make_pair(a, d));
            idx2++;
        }

        idx2 = 0;
        while (idx2 < t) {
            cin >> x;
            dest.push_back(x);
            idx2++;
        }

        vector<int> dist(n+1, INT_MAX);
        vector<int> throughs(n + 1, 0);
        dist[s] = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, s));

        pair<int, int> cur;
        int d, cn;

        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();

            d = cur.first;
            cn = cur.second;

            for (int i = 0; i < edges[cn].size(); i++) {
                pair<int, int> edge = edges[cn][i];
                int next = edge.first;
                int ndist = edge.second;
                int cthrough = (cn == g && next == h) || (cn == h && next == g);

                if (d == dist[cn] && (dist[cn] + ndist < dist[next])) {
                    dist[next] = dist[cn] + ndist;
                    throughs[next] = throughs[cn] | cthrough;
                    pq.push(make_pair(dist[next], next));
                }
                else if (d == dist[cn] && (dist[cn] + ndist == dist[next]) &&
                    (throughs[next]==false) && ((throughs[cn]|cthrough) == true)) {
                    throughs[next] = true;
                    pq.push(make_pair(dist[next], next));
                }
            }
        }

        for (int i = 0; i < dest.size(); i++) {
            if (throughs[dest[i]]) {
                ret.push_back(dest[i]);
            }
        }

        sort(ret.begin(), ret.end());

        for (int i = 0; i < ret.size(); i++) {
            printf("%d ", ret[i]);
        }
        printf("\n");

        idx++;
    }


    return 0;
}

