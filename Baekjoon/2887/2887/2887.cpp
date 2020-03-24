#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

typedef struct edge_t {
    int u, v;
    ull w;

    edge_t(int u_, int v_, ull w_) : u(u_), v(v_), w(w_){}

    bool operator<(const edge_t& rhs) const {
        return w < rhs.w;
    }
} edge;

vector<edge> edges;

class coord {
public:
    ll c;
    int idx;

    coord(ll c_, int idx_) : c(c_), idx(idx_) {}

    bool operator<(const coord& rhs) const {
        return c < rhs.c;
    }

};

vector<int> p;

int Find(int x) {
    if (x == p[x]) return x;
    else return p[x] = Find(p[x]);
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

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    edges = vector<edge>(N + 1, {0,0,0});
    p = vector<int>(N+1, 0);
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }

    vector<coord> coordx(N + 1, coord(0, 0));
    vector<coord> coordy(N + 1, coord(0, 0));
    vector<coord> coordz(N + 1, coord(0, 0));

    int idx = 1;
    ll x, y, z;
    while (idx <= N) {
        cin >> x >> y >> z;
        coordx[idx] = coord(x, idx);
        coordy[idx] = coord(y, idx);
        coordz[idx] = coord(z, idx);
        idx++;
    }

    sort(coordx.begin() + 1, coordx.end());
    sort(coordy.begin() + 1, coordy.end());
    sort(coordz.begin() + 1, coordz.end());

    for (int i = 1; i < N; i++) {
        edges.push_back({ coordx[i].idx, coordx[i + 1].idx, (ull)abs(coordx[i + 1].c - coordx[i].c) });
        edges.push_back({ coordy[i].idx, coordy[i + 1].idx, (ull)abs(coordy[i + 1].c - coordy[i].c) });
        edges.push_back({ coordz[i].idx, coordz[i + 1].idx, (ull)abs(coordz[i + 1].c - coordz[i].c) });
    }

    sort(edges.begin(), edges.end());

    ull ret = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (Find(edges[i].u) != Find(edges[i].v)) {
            Union(edges[i].u, edges[i].v);
            ret += edges[i].w;
        }

    }

    printf("%lld\n", ret);

    return 0;
}