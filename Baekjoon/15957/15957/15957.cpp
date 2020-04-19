#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;


#if 0
//TLE

typedef struct song_t {
    int singer;
    int subnodes;
    vector<int> ch;
    int parent;
} song;

typedef struct rdata_t {
    ll T, P, S;

    bool operator<(rdata_t& rhs) {
        return T < rhs.T;
    }
} rdata;

int main()
{
    int N, K;
    ll J;

    cin >> N >> K >> J;

    vector<song> songs(N + 1, { -1, 1, vector<int>(), 0 });
    vector<int> songs_per_signer(N + 1, 0);
    vector<int> singers;

    int idx = 2;
    int p;
    while (idx <= N) {
        cin >> p;
        songs[p].ch.push_back(idx);
        songs[idx].parent = p;
        int diff = songs[idx].subnodes;
        while (p > 0) {
            songs[p].subnodes += diff;
            p = songs[p].parent;
        }
        idx++;
    }

    idx = 1;
    int sid;
    while (idx <= N) {
        cin >> sid;
        songs[idx].singer = sid;
        if (songs_per_signer[sid] == 0) singers.push_back(sid);
        songs_per_signer[sid]++;
        idx++;
    }

    vector<rdata> darr(K, { 0,0,0 });

    idx = 0;
    ll T, P, S;
    while (idx < K) {
        cin >> T >> P >> S;
        darr[idx] = { T, P, S };
        idx++;
    }

    sort(darr.begin(), darr.end());

    int singercnt = singers.size();
    vector<int> sarr(singercnt, 0), earr(singercnt, K);

    vector<int> res(N + 1, -1);

    while (1) {

        bool search = false;
        vector<vector<int>> qbin(K);
        vector<double> singer_acc(N + 1, 0);

        int mid;
        for (int i = 0; i < singercnt; i++) {
            if (sarr[i] < earr[i]) {
                qbin[(sarr[i] + earr[i]) >> 1].push_back(i);
                search = true;
            }
        }

        if (!search) break;

        for (int i = 0; i < K; i++) {
            rdata cur = darr[i];

            queue<int> q;
            q.push(cur.P);
            int score_per_node = cur.S / songs[cur.P].subnodes;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                int singer = songs[cur].singer;
                singer_acc[singer] += score_per_node;

                for (int j = 0; j < songs[cur].ch.size(); j++) {
                    q.push(songs[cur].ch[j]);
                }
            }

            for (auto k : qbin[i]) {
                if (singer_acc[singers[k]] / (double)songs_per_signer[singers[k]] > J) {
                    res[singers[k]] = cur.T;
                    earr[k] = i;
                }
                else {
                    sarr[k] = i + 1;
                }
            }

        }

    }

    for (int i = 1; i < songs.size(); i++) {
        printf("%d\n", res[songs[i].singer]);
    }


    return 0;
}

#else

#include <unordered_map>

typedef struct song_t {
    vector<int> ch;
} song;


typedef struct rdata_t {
    ll T, P, S;

    bool operator<(rdata_t& rhs) {
        return T < rhs.T;
    }
} rdata;


//fenwick
void update(vector<ll>& tree, int idx, ll diff) {
    while (idx < tree.size()) {
        tree[idx] += diff;
        idx += idx & -idx;
    }
}

ll get(vector<ll>& tree, int idx) {
    ll sum = 0;
    while (idx) {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

// Flatten tree & get subtree range

int dfs(vector<pair<int, int>>& range, vector<song>& songs, int s, int song_idx) {
    range[song_idx].first = s;

    int nodenum = 1;

    for (int i = 0; i < songs[song_idx].ch.size(); i++) {
        nodenum += dfs(range, songs, s + nodenum, songs[song_idx].ch[i]);
    }

    range[song_idx].second = s + nodenum;

    return nodenum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int N, K;
    ll J;

    cin >> N >> K >> J;

    vector<pair<int, int>> range(N + 1, { 0,0 });
    vector<song> songs(N + 1);

    int idx = 2;
    int p;
    while (idx <= N) {
        cin >> p;
        songs[p].ch.push_back(idx);
        idx++;
    }

    dfs(range, songs, 1, 1);

    idx = 1;
    int sid;
    unordered_map<int, vector<int>> um_singer;
    vector<int> singer_keys;
    vector<int> singer_order;

    while (idx <= N) {
        cin >> sid;
        um_singer[sid].push_back(idx);
        singer_order.push_back(sid);
        idx++;
    }

    for (auto it = um_singer.begin(); it != um_singer.end(); it++) {
        singer_keys.push_back(it->first);
    }

    vector<rdata> darr(K, { 0,0,0 });

    idx = 0;
    ll T, P, S;
    while (idx < K) {
        cin >> T >> P >> S;
        darr[idx] = { T, P, S };
        idx++;
    }

    sort(darr.begin(), darr.end());

    int singer_cnt = um_singer.size();

    vector<int> sarr(singer_cnt, 0), earr(singer_cnt, K);

    unordered_map<int, int> res;

    while (1) {

        vector<ll> ftree(N + 1, 0);

        bool search = false;
        vector<vector<pair<int, int>>> binqry(K);
        vector<ll> acc_score(singer_cnt, 0);

        for (int i = 0; i < singer_cnt; i++) {
            if (sarr[i] < earr[i]) {
                binqry[(sarr[i] + earr[i]) >> 1].push_back(make_pair(i, singer_keys[i]));
                search = true;
            }
        }

        if (!search) break;

        for (int i = 0; i < K; i++) {
            rdata& cur = darr[i];

            pair<int, int>& crange = range[cur.P];

            ll score = cur.S / (crange.second - crange.first);

            update(ftree, crange.first, score);
            update(ftree, crange.second, -score);

            for (auto jp : binqry[i]) {
                int qidx = jp.first;
                int j = jp.second;
                ll& sum = acc_score[qidx];
                int num_songs = um_singer[j].size();
                for (int k = 0; k < num_songs; k++) {
                    sum += get(ftree, range[um_singer[j][k]].first);
                    if (sum / (double)num_songs > J) break;
                }

                if (sum / (double)num_songs > J) {
                    res[j] = cur.T;
                    earr[qidx] = i;
                }
                else {
                    sarr[qidx] = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < singer_order.size(); i++) {
        if (res.find(singer_order[i]) != res.end()) {
            printf("%d\n", res[singer_order[i]]);
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}


#endif