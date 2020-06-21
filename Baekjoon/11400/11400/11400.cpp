#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edges;
vector<vector<int>> cut;
vector<int> order;
int gorder = 1;

int dfs(int cur, int pre) {

    int ret = order[cur] = gorder++;

    int tmp;
    for (int i = 0; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        if (nxt == pre) continue;

        if (order[nxt] == 0) {
            tmp = dfs(nxt, cur);
            if (tmp > order[cur]) {
                cut.push_back(vector<int>({ min(cur, nxt), max(cur, nxt) }));
            }
        }
        else {
            tmp = order[nxt];
        }
        ret = min(tmp, ret);
    }

    return ret;
}

int main()
{

    int V, E;

    cin >> V >> E;

    edges = vector<vector<int>>(V+1, vector<int>());
    vector<vector<int>>().swap(cut);
    order = vector<int>(V + 1, 0);

    int idx = 0;
    int f, t;
    while (idx < E) {
        scanf("%d%d", &f, &t);
        edges[f].push_back(t);
        edges[t].push_back(f);
        idx++;
    }

    for (int i = 1; i <= V; i++) {
        if (order[i] == 0) {
            dfs(i, -1);
        }
    }

    cout << cut.size() << endl;

    sort(cut.begin(), cut.end());

    for (int i = 0; i < cut.size(); i++) {
        printf("%d %d\n", cut[i][0], cut[i][1]);
    }

    return 0;
}
