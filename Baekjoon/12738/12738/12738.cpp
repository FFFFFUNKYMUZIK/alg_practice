#include <iostream>
#include <vector>
#define INFNEGMAX 0x80000000

using namespace std;

//bin search

int binsearch(vector<int>& buf, int val, int s, int e) {

    while (s < e) {
        int mid = (s+e) / 2;
        if (buf[mid] < val) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
    }

    return e;

}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);
    vector<int> buf(N + 1, INFNEGMAX);
    vector<int> bufidx(N + 1, 0);
    vector<int> preidx(N + 1, 0);
    
    int idx = 1;
    while (idx <= N) {
        cin >> arr[idx];
        idx++;
    }

    int maxlen = 0;
    int premaxidx = 0;

    for (int i = 1; i <= N; i++) {

        if (buf[maxlen] < arr[i]) {
            buf[++maxlen] = arr[i];
            bufidx[maxlen] = i;
            preidx[i] = bufidx[maxlen-1];
            premaxidx = i;
        }
        else {
            int idx = binsearch(buf, arr[i], 1, maxlen);
            bufidx[idx] = i;
            preidx[i] = bufidx[idx - 1];
            buf[idx] = arr[i];
            if (idx == maxlen) premaxidx = i;
        }

    }

    printf("%d\n", maxlen);

    vector<int> st;
    while (premaxidx > 0) {
        st.push_back(arr[premaxidx]);
        premaxidx = preidx[premaxidx];
    }

    for (auto it = st.rbegin(); it != st.rend(); it++) {
        printf("%d ", *it);
    }

    return 0;
}


//segment tree

/*
#include <cmath>
#include <algorithm>

typedef struct vpair_t {
    int val;
    int idx;

    bool operator<(const vpair_t& rhs) {
        if (val == rhs.val) {
            return idx > rhs.idx;
        }
        return val < rhs.val;
    }
} vpair;

void update(vector<int>& tree, int s, int e, int idx, int val, int i) {
    if (i < s || e < i)
        return;
    if (s == e) {
        tree[idx] = val;
        return;
    }
    int mid = (s + e) / 2;

    if (tree[idx] < val) tree[idx] = val;

    update(tree, s, mid, 2 * idx, val, i);
    update(tree, mid + 1, e, 2 * idx + 1, val, i);
}

int find(vector<int>& tree, int s, int e, int idx, int l, int r) {
    if (r < s || e < l) {
        return 0;
    }
    else if (l <= s && e <= r) {
        return tree[idx];
    }

    int mid = (s + e) / 2;
    return max(find(tree, s, mid, 2 * idx, l, r), find(tree, mid + 1, e, 2 * idx + 1, l, r));

}

int main()
{
    int N;
    cin >> N;

    vector<vpair> arr(N + 1, { 0, 0 });

    int h = ceil(log2(N)) + 1;

    vector<int> tree((1 << h) + 1, 0);

    int idx = 1;
    int val;
    while (idx <= N) {
        cin >> val;
        arr[idx] = { val, idx };
        idx++;
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        int part = find(tree, 1, N, 1, 1, arr[i].idx - 1);
        update(tree, 1, N, 1, part + 1, arr[i].idx);
    }

    printf("%d\n", tree[1]);

    return 0;
}
*/