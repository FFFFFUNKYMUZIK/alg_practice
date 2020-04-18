#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;




#if 0

typedef struct node_t {
    ll val, lazy;
} node;

//segment tree w/ lazy propagation

//O(logN) for initiation
//if update every element each time then O(NlogN)
ll init(vector<node>& tree, vector<ll>& arr, int s, int e, int node) {
    if (s == e) {
        tree[node] = { arr[s], 0 };
        return tree[node].val;
    }

    int mid = (s + e) / 2;
    tree[node].val = init(tree, arr, s, mid, 2 * node) + init(tree, arr, mid+1, e, 2*node + 1);

    return tree[node].val;
}

void update(vector<node>& tree, vector<ll>& arr, int s, int e, int node, int l, int r, ll diff) {
    
    if (tree[node].lazy != 0) {
        tree[node].val += (e - s + 1) * tree[node].lazy;
        if (s != e) {
            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if (r < s || e < l) {
        return;
    }
    else if (l <= s && e <= r) {
        tree[node].val += diff * (e - s + 1);
        if (s != e) {
            tree[2 * node].lazy += diff;
            tree[2 * node + 1].lazy += diff;
        }
        return;
    }

    int mid = (s + e) / 2;
    update(tree, arr, s, mid, 2 * node, l, r, diff);
    update(tree, arr, mid+1, e, 2 * node + 1, l, r, diff);

    tree[node].val = tree[2 * node].val + tree[2 * node + 1].val;
}

ll sum(vector<node>& tree, vector<ll>& arr, int s, int e, int node, int l, int r) {
    //same lazy prop. w/ update
    if (tree[node].lazy != 0) {
        tree[node].val += (e - s + 1) * tree[node].lazy;
        if (s != e) {
            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
    if (r < s || e < l) {
        return 0;
    }
    else if (l <= s && e <= r) {
        return tree[node].val;
    }

    int mid = (s + e) / 2;
    return sum(tree, arr, s, mid, 2 * node, l, r) + sum(tree, arr, mid + 1, e, 2 * node + 1, l, r);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    int idx = 1;

    vector<ll> arr(N+1, 0);
    int h = ceil(log2(N)) + 1;
    vector<node> tree((1 << h) + 1, { 0, 0 });

    while (idx <= N) {
        cin >> arr[idx];
        idx++;
    }

    init(tree, arr, 1, N, 1);


    idx = 0;
    int a, b, c;
    ll d;
    while (idx < M + K) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(tree, arr, 1, N, 1, b, c, d);
        }
        else if (a==2){
            cin >> b >> c;
            printf("%lld\n", sum(tree, arr, 1, N, 1, b, c));
        }
        idx++;
    }

    return 0;
}

#else

//fenwick tree (range update & range query O(logN)
//reference : https://www.acmicpc.net/blog/view/88

//O(NlogN) for initiation (update every single element)
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
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int idx = 1;

    vector<ll> tree_slope(N + 1, 0);
    vector<ll> tree_const(N + 1, 0);

    ll cur;
    while (idx <= N) {
        cin >> cur;
        update(tree_const, idx, cur);
        idx++;
    }

    idx = 0;
    int a, b, c;
    ll d;

#define LINEAR(m) (sum(tree_slope, m)*(m)+sum(tree_const, m))
    while (idx < M + K) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(tree_const, b, d*(1ll-b));
            update(tree_const, c+1, d*c);
            update(tree_slope, b, d);
            update(tree_slope, c+1, -d);
        }
        else if (a == 2) {
            cin >> b >> c;
            printf("%lld\n", LINEAR(c) - LINEAR(b-1));
        }
        idx++;
    }

#undef LINEAR
    return 0;
}

#endif