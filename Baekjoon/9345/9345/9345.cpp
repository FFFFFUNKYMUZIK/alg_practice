#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


#define MAXVAL 100001
#define MINVAL 0

using namespace std;

typedef struct node_t {
    int minval;
    int maxval;
} node;

node init(vector<node>& tree, vector<int>& arr, int idx, int s, int e) {

    if (s == e) {
        tree[idx] = { arr[s], arr[s] };
    }
    else {
        int mid = (s + e) / 2;
        node ln = init(tree, arr, 2 * idx, s, mid);
        node rn = init(tree, arr, 2 * idx + 1, mid + 1, e);
        tree[idx] = { min(ln.minval, rn.minval), max(ln.maxval, rn.maxval) };
    }

    return tree[idx];
}

node update(vector<node>& tree, vector<int>& arr, int idx, int s, int e, int tar) {
    
    if (tar < s || e < tar) return tree[idx];

    int mid = (s + e) / 2;

    if (s == e) {
        tree[idx] = {arr[s], arr[s]};
    }
    else {
        node ln = update(tree, arr, 2 * idx, s, mid, tar);
        node rn = update(tree, arr, 2 * idx + 1, mid + 1, e, tar);
        tree[idx] = { min(ln.minval, rn.minval), max(ln.maxval, rn.maxval) };
    }

    return tree[idx];
}


void swap_element(vector<node>& tree, vector<int>& arr, int idx, int s, int e, int a, int b) {

    if (idx == 1) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    update(tree, arr, idx, s, e, a);
    update(tree, arr, idx, s, e, b);

}

bool get(vector<node> &tree, vector<int>& arr, int idx, int s, int e, int l, int r) {

    if (r<s || l>e) {
        return true;
    }
    else if (l <= s && e <= r) {
        return (tree[idx].minval >= l) && (tree[idx].maxval <= r);
    }

    int mid = (s + e) / 2;
    return get(tree, arr, 2 * idx, s, mid, l, r) && get(tree, arr, 2 * idx + 1, mid + 1, e, l, r);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, N, K;

    cin >> T;
    int idx = 0;
    
    
    while (idx < T) {

        cin >> N >> K;
        vector<int> arr(N, 0);
        for (int i = 0; i < N; i++) {
            arr[i] = i;
        }

        int h = ceil(log2(N)) + 1;
        vector<node> tree((1 << h) + 1, { MAXVAL, MINVAL });
        init(tree, arr, 1, 0, N - 1);

        int Q, A, B;
        int idx2 = 0;
        while (idx2 < K) {
            cin >> Q >> A >> B;
            if (Q == 0) swap_element(tree, arr, 1, 0, N - 1, A, B);
            else if (Q == 1) {
                if (get(tree, arr, 1, 0, N-1, A, B)) {
                    printf("YES\n");
                }
                else {
                    printf("NO\n");
                }
            }
            idx2++;
        }

        idx++;
    }
    
    return 0;
}

