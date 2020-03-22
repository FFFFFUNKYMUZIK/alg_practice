#include <iostream>
#include <vector>
#include <cmath>



using namespace std;

/*
long long init_tree(vector<long long> & tree, vector<long long> & arr, int start, int end, int node) {
    if (start == end) {
        //if it's leaf
        tree[node] = arr[start];
    }
    else {
        //calculate on lower level
        tree[node] = init_tree(tree, arr, start, (start+end)/2, 2*node) + init_tree(tree, arr, (start+end)/2+1, end, 2*node+1);
    }
    
    return tree[node];
}

long long sum_tree(vector<long long>& tree, vector<long long>& arr, int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        //not my business
        return 0;
    }
    else if (left <= start && end <= right) {
        //it's all mine
        return tree[node];
    }
    //calculate on lower level
    return sum_tree(tree, arr, start, (start+end)/2, 2*node, left, right) + sum_tree(tree, arr, (start+end)/2+1, end, 2*node+1, left, right);
}

void update_tree(vector<long long>& tree, vector<long long>& arr, int start, int end, int node, int tar, long long diff) {
    if (tar<start || tar>end) return;
    tree[node] += diff;
    if (start != end) { //if it's not leaf node
        update_tree(tree, arr, start, (start + end) / 2, 2 * node, tar, diff);
        update_tree(tree, arr, (start + end) / 2 + 1, end, 2 * node + 1, tar, diff);
    }
    else {
        //IMPORTANT!!
        arr[start] += diff;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int idx = 0;

    vector<long long> arr(N, 0);

    while (idx < N) {
        cin >> arr[idx];
        idx++;
    }

    int tree_height = ceil(log2(N));
    int tree_size = 1<<(tree_height + 1);

    vector<long long> tree(tree_size+1, 0);

    init_tree(tree, arr, 0, N - 1, 1);

    idx = 0;
    int  a, b;
    long long c;
    while (idx < M + K) {
        cin >> a >> b >> c;
        if (a == 1) update_tree(tree, arr, 0, N-1, 1, b-1, c-arr[b-1]);
        else if (a == 2) printf("%lld\n", sum_tree(tree, arr, 0, N-1, 1, b-1, c-1));
        idx++;
    }

    return 0;

}

*/

//do same thing with BIT

void update(vector<long long>& tree, int idx, long long diff) {

    while (idx < tree.size()) {
        tree[idx] += diff;
        idx += idx & -idx;
    }
}

long long sum(vector<long long>& tree, int l, int r) {
    
    long long lsum = 0, rsum = 0;
    
    l--;

    while (l > 0) {
        lsum += tree[l];
        l -= l & -l;
    }

    while (r > 0) {
        rsum += tree[r];
        r -= r & -r;
    }

    return rsum - lsum;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int idx = 1;

    vector<long long> arr(N+1, 0);
    vector<long long> tree(N + 1, 0);

    while (idx <= N) {
        cin >> arr[idx];
        update(tree, idx, arr[idx]);
        idx++;
    }

    idx = 0;
    int  a, b;
    long long c;
    while (idx < M + K) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(tree, b, c - arr[b]);
            arr[b] = c;
        }
        else if (a == 2) printf("%lld\n", sum(tree, b, c));
        idx++;
    }

    return 0;

}


