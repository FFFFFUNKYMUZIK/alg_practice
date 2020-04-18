#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
vector<int> num_node;

void Init(int nodes) {

    vector<int>(nodes + 1, 0).swap(p);
    for (int i = 1; i <= nodes; i++) {
        p[i] = i;
    }
    vector<int>(nodes + 1, 1).swap(num_node);
}

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    
    return p[x] = Find(p[x]);
}

int Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px != py) {
        p[px] = py;
        num_node[py] += num_node[px];
    }

    return num_node[py];
};

typedef struct edge_t {
    int u, v, c;

    bool operator<(const edge_t& r) {
        return c < r.c;
    }
} edge;


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<edge> edges(m);

    int idx = 0;
    int a, b, c;
    while (idx < m) {
        cin >> a >> b >> c;
        edges[idx] = {a,b,c};
        idx++;
    }

    sort(edges.begin(), edges.end());

    int q;
    cin >> q;

    idx = 0;
    vector<int> xarr(q, 0), yarr(q, 0);
    while (idx < q) {
        cin >> xarr[idx] >> yarr[idx];
        idx++;
    }

    vector<int> larr(q, 0), rarr(q, m-1);
    vector<pair<int, int>> ret(q, make_pair(-1 , -1));


    //(M+Q)logMlogN
    while (1) {

        bool search = false;

        vector<vector<int>> qbin(m);

        for (int i = 0; i < q; i++) {
            int mid;
            if (larr[i] <= rarr[i]) {
                mid = (larr[i] + rarr[i]) / 2;
                qbin[mid].push_back(i);
                search = true;
            }
        }

        if (!search) break;

        Init(n);


        //(MlogN (Union) + QlogN(Find) )
        for (int i = 0; i < m; i++) {
            edge& e = edges[i];

            int nodes = Union(e.u, e.v);

            for (int j = 0; j < qbin[i].size(); j++) {
                int qn = qbin[i][j];
                if (Find(xarr[qn]) == Find(yarr[qn])) {
                    ret[qn] = make_pair(e.c , nodes);
                    rarr[qn] = i - 1;
                }
                else {
                    larr[qn] = i + 1;
                }
            }
        }

    }

    for (int i = 0; i < q; i++) {
        if (ret[i].first != -1) {
            printf("%d %d\n", ret[i].first, ret[i].second);
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}
