#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edges;
vector<int> order;
vector<bool> cutv;
int gorder = 1;

int dfs(int cur, int pre) {

    order[cur] = gorder++;
    int ch = 0;
    int ret = order[cur];


    int tmp;
    for (int i = 0; i < edges[cur].size(); i++) {
        int nxt = edges[cur][i];
        if (nxt == pre) continue;

        if (order[nxt] == 0) {
            ch++;
            tmp = dfs(nxt, cur);
            if (pre != -1 && tmp >= order[cur]) cutv[cur] = true;
        }
        else {
            tmp = order[nxt];
        }
        ret = min(ret, tmp);
    }

    if (pre == -1 && ch>1) {
        cutv[cur] = true;
    }

    return ret;
}


int main()
{
    int V, E;
    cin >> V >> E;


    edges = vector<vector<int>>(V + 1, vector<int>());

    int idx = 0;
    int f, t;
    while (idx<E) {
        cin >> f >> t;
        edges[f].push_back(t);
        edges[t].push_back(f);
        idx++;
    }


    order = vector<int>(V + 1, 0);
    cutv = vector<bool>(V + 1, false);

    for (int i = 1; i <= V; i++) {
        if (order[i] == 0) {
            dfs(i, -1);
        }
    }

    vector<int> res;
    for (int i = 1; i < cutv.size(); i++) {
        if (cutv[i]) {
            res.push_back(i);
        }
    }
    
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}
