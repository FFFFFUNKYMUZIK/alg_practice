#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned long long ull_c;

#define MOD 1000000007ULL

using namespace std;

ull_c init_tree(vector<ull_c>& tree, vector<ull_c>& arr, int start, int end, int node) {
    if (start == end) {
        //if it's leaf
        tree[node] = arr[start] % MOD;
    }
    else {
        //calculate on lower level
        tree[node] = init_tree(tree, arr, start, (start + end) / 2, 2 * node) * init_tree(tree, arr, (start + end) / 2 + 1, end, 2 * node + 1) % MOD;
    }

    return tree[node];
}

ull_c mul_tree(vector<ull_c>& tree, vector<ull_c>& arr, int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        //not my business
        return 1;
    }
    else if (left <= start && end <= right) {
        //it's all mine
        return tree[node];
    }
    //calculate on lower level
    return mul_tree(tree, arr, start, (start + end) / 2, 2 * node, left, right) * mul_tree(tree, arr, (start + end) / 2 + 1, end, 2 * node + 1, left, right) % MOD;
}

ull_c update_tree(vector<ull_c>& tree, vector<ull_c>& arr, int start, int end, int node, int tar, ull_c val) {
    if (tar<start || tar>end) return tree[node];

    if (start != end) { //if it's not leaf node
        tree[node] = update_tree(tree, arr, start, (start + end) / 2, 2 * node, tar, val) * update_tree(tree, arr, (start + end) / 2 + 1, end, 2 * node + 1, tar, val) % MOD;
    }
    else {
        /*IMPORTANT!!*/
        arr[start] = val;
        tree[node] = val%MOD;
    }

    return tree[node];
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int idx = 0;

    vector<ull_c> arr(N, 0);

    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    int tree_height = ceil(log2(N));
    int tree_size = 1 << (tree_height + 1);

    vector<ull_c> tree(tree_size + 1, 0);

    init_tree(tree, arr, 0, N - 1, 1);

    idx = 0;
    int  a, b;
    ull_c c;
    while (idx < M + K) {
        cin >> a >> b >> c;
        if (a == 1) update_tree(tree, arr, 0, N - 1, 1, b - 1, c );
        else if (a == 2) printf("%lld\n", mul_tree(tree, arr, 0, N - 1, 1, b - 1, c - 1));
        idx++;
    }

    return 0;

}
