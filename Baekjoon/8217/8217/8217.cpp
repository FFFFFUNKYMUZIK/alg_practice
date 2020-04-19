#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void update(vector<ll>& tree, int idx, ll diff) {

    while (idx < tree.size()) {
        tree[idx] += diff;
        idx += idx & -idx;
    }

}

ll sum(vector<ll>& tree, int idx) {

    ll ret = 0;
    while (idx) {
        ret += tree[idx];
        idx -= idx & -idx;
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;

    cin >> N >> M;

    vector<vector<int>> own(N + 1);
    vector<ll> tar(N + 1, 0);

    int idx = 1;
    int owner;
    while (idx <= M) {
        cin >> owner;
        own[owner].push_back(idx);
        idx++;
    }

    idx = 1;
    while (idx <= N) {
        cin >> tar[idx];
        idx++;
    }


    int Q;
    cin >> Q;

    vector<int> larr(Q, 0), rarr(Q, 0), aarr(Q, 0);
    idx = 0;
    while (idx < Q) {
        cin >> larr[idx] >> rarr[idx] >> aarr[idx];
        idx++;
    }

    vector<int> sarr(N, 0), earr(N, Q - 1);

    vector<int> ret(N, -1);


    //O(logQ*(QM+N)) TLE
    /*
    while (1) {

        vector<ll> acc(N + 1, 0);
        vector<vector<int>> qbin(Q);

        int mid;
        bool search = false;
        for (int i = 0; i < N;i++) {
            if (sarr[i] <= earr[i]) {
                mid = (sarr[i] + earr[i]) / 2;
                qbin[mid].push_back(i);
                search = true;
            }
        }

        if (!search) break;

        for (int i = 0; i < Q; i++) {
            int l, r, a;
            l = larr[i]; r = rarr[i]; a = aarr[i];
            if (l <= r) {
                for (int k = l; k <= r; k++) {
                    acc[owner[k]] += a;
                }
            }
            else {
                for (int k = l; k <= M; k++) {
                    acc[owner[k]] += a;
                }
                for (int k = 1; k <= r; k++) {
                    acc[owner[k]] += a;
                }
            }

            for (int j = 0; j < qbin[i].size(); j++) {
                int qn = qbin[i][j];
                if (acc[qn + 1] >= tar[qn + 1]) {
                    ret[qn] = i + 1;
                    earr[qn] = i - 1;
                }
                else {
                    sarr[qn] = i + 1;
                }
            }

        }


    }
    */


    //O(logQ*(QlogM + MlogM) = O((Q+M)logMlogQ)
    while (1) {

        vector<ll> acc(N + 1, 0);
        vector<vector<int>> qbin(Q);
        vector<ll> fenwick(M + 1, 0);

        int mid;
        bool search = false;
        for (int i = 0; i < N; i++) {
            if (sarr[i] <= earr[i]) {
                mid = (sarr[i] + earr[i]) / 2;
                qbin[mid].push_back(i);
                search = true;
            }
        }

        if (!search) break;

        for (int i = 0; i < Q; i++) {
            int l, r, a;
            l = larr[i]; r = rarr[i]; a = aarr[i];
            
            update(fenwick, l, a);
            update(fenwick, r + 1, -a);

            if (l > r)
                update(fenwick, 1, a);


            for (int j = 0; j < qbin[i].size(); j++) {
                int qn = qbin[i][j] + 1;

                for (int k = 0; k < own[qn].size(); k++) {
                    acc[qn] += sum(fenwick, own[qn][k]);
                    //without this break, overflow occurs
                    if (acc[qn] >= tar[qn]) break;
                }

                if (acc[qn] >= tar[qn]) {
                    ret[qn - 1] = i + 1;
                    earr[qn - 1] = i - 1;
                }
                else {
                    sarr[qn - 1] = i + 1;
                }
            }

        }


    }

    for (int i = 0; i < N; i++) {
        if (ret[i] == -1) printf("NIE\n");
        else printf("%d\n", ret[i]);
    }

    return 0;
}
