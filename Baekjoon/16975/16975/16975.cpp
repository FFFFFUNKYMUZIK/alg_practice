#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

void init(vector<ull> & tree, vector<ull> & arr, int s, int e, int idx) {

    if (s == e) {
        tree[idx] = arr[s];
    }
    else {
        int  mid = (s + e) / 2;
        init(tree, arr, s, mid, 2 * idx);
        init(tree, arr, mid+1, e, 2 * idx+1);
    }
}

void update(vector<ull>& tree, vector<ull>& arr, int s, int e, int idx, int i, int j, int k) {

    if (j<s || i>e) {
        return;
    }
    else if (i<=s && e<=j) {
        tree[idx] += k;
    }
    else {
        int mid = (s + e) / 2;
        update(tree, arr, s, mid, 2 * idx, i, j, k);
        update(tree, arr, mid+1, e, 2 * idx + 1, i, j, k);
    }
}

ull get(vector<ull>& tree, vector<ull>& arr, int s, int e, int idx, int x) {
    if (x<s || x>e) {
        return 0;
    }
    if (s == e) {
        return tree[idx];
    }
    int mid = (s + e) / 2;
    return (tree[idx] + get(tree, arr, s, mid, 2 * idx, x) + get(tree, arr, mid+1, e, 2 * idx+1, x));
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    vector<ull> arr(N, 0);
    
    int idx = 0;
    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    int h = ceil(log2(N)) + 1;
    vector<ull> tree((1 << h) + 1, 0);
    init(tree, arr, 0, N-1, 1);

    int M;
    cin >> M;
    idx = 0;

    int qtype, i, j, k, x;
    while (idx < M) {
        cin >> qtype;
        if (qtype == 1) {
            cin >> i >> j >> k;
            update(tree, arr, 0, N - 1, 1, i-1, j-1, k);
        }
        else if (qtype == 2) {
            cin >> x;
            printf("%lld\n", get(tree, arr, 0, N - 1, 1, x-1));
        }

        idx++;
    }


    return 0;
}
