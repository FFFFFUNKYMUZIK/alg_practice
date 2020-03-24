#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> p;


int Find(int x) {
    if (x == p[x]) {
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

typedef struct node_t {
    double w;
    int u, v;

    bool operator<(const node_t & rhs) const{
        return w < rhs.w;
    }
} node;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    vector<pair<int,int>> coord(N+1, make_pair(0, 0));
    vector<node> edges(N * (N-1)/2, { 0,0,0 });
    p = vector<int> (N+1, 0);

    for (int i = 1; i <= N; i++) p[i] = i;
    
    int idx = 1;
    int x, y;
    while (idx <= N) {
        cin >> x >> y;
        coord[idx] = make_pair(x, y);
        idx++;
    }

    idx = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            edges[idx++] = {sqrt(pow(coord[i].first - coord[j].first, 2) + pow(coord[i].second - coord[j].second, 2)), i, j};
        }
    }
    
    sort(edges.begin(), edges.end());

    idx = 0;
    while(idx < M) {
        cin >> x >> y;
        Union(x, y);
        idx++;
    }

    double ret = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (Find(edges[i].u) != Find(edges[i].v)) {
            Union(edges[i].u, edges[i].v);
            ret += edges[i].w;
        }
    }

    printf("%.2lf\n", ret);

    return 0;
}
