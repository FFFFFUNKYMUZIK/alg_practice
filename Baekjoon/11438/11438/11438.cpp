#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    int N;
    cin >> N;

    int logsize = (int)log2(N);
    vector<vector<int>> tb(N+1, vector<int>(logsize+1, 0));
    
    int idx = 1;
    int a, b;


    vector<pair<int, int>> pd(N + 1, make_pair(0, 0));
    pd[1] = make_pair(1, 0);

#if 1
    //bfs
    vector<vector<int>> edges(N+1, vector<int>());
    vector<int> visit(N + 1, 0);

    while (idx < N) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        idx++;
    }
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(1, 0));

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        visit[cur] = 1;
        q.pop();

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i];
            if (visit[next] == 0) {
                pd[next] = make_pair(cur, dist + 1);
                q.push(make_pair(edges[cur][i], dist + 1));
            }
        }
    }
    
#else
    
    /*


    while (idx<N) {
        cin >> a >> b;
        if (pd[a].first == 0) {
            pd[a] = make_pair(b, pd[b].second + 1);
        }
        if (pd[b].first == 0) {
            pd[b] = make_pair(a, pd[a].second + 1);
        }
        idx++;
    }
    */
#endif

    for (int i = 1; i <= N; i++) {
        //depth info
        tb[i][0] = pd[i].first;
    }

    for (int j = 1; j <= logsize; j++) {
        for (int i = 1; i <= N; i++) {
            tb[i][j] = tb[tb[i][j - 1]][j - 1];
        }
    }


    
    int M;
    cin >> M;
    idx = 0;
    while (idx < M) {
        cin >> a >> b;
        int ad = pd[a].second;
        int bd = pd[b].second;
        if (ad < bd) {
            int tmp = a;
            a = b;
            b = tmp;

            tmp = ad;
            ad = bd;
            bd = tmp;
        }

        int depthdiff = ad - bd;

        while (depthdiff>0) {
            int logdsize = (int)log2(depthdiff);
            a = tb[a][logdsize];
            ad -= (1<<logdsize);
            depthdiff = ad - bd;
        }

        if (a == b) printf("%d\n", a);
        else {
            for (int i = logsize; i >= 0; i--) {
                if (tb[a][i] != tb[b][i]) {
                    a = tb[a][i];
                    b = tb[b][i];
                }
            }

            printf("%d\n", tb[a][0]);
        }

        idx++;
    }

}